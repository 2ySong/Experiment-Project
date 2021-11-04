#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char prog1[20000] = {' '};
char prog2[20000] = {' '};
int p, q, syn, m = 0;
char token[100];
char *rwtab[46] = {"#", "main", "if", "then", "while", "do", "static", "int",
                   "double", "struct", "break", "else", "long", "switch", "case", "typedef",
                   "char", "return", "const", "float", "short", "continue", "for", "void",
                   "sizeof", "ID", "NUM", "+", "-", "*", "/", ":", ":=", "<", "<>", "<=", ">",
                   ">=", "=", "default", ";", "(", ")", "{", "}"};


void Empty(char prog1[]) {
    for (int i = 0; i < 20000; i++)
        prog1[i] = ' ';
}

int isLetter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A') && ch <= 'Z')
        return 1;
    else
        return 0;
}

int isNum(char ch) {
    if (ch >= '0' && ch <= '9')
        return 1;
    else
        return 0;
}

void dealEmpty(char prog1[], char prog2[]) {
    p = q = 0;
    char ch = prog1[p++];
    while (ch != '$') {
        if (ch == ' ') {
            do {
                ch = prog1[p++];
            } while (ch == ' ');
            prog2[q++] = ' ';
        }
        prog2[q++] = ch;
        ch = prog1[p++];
    }
    //prog2[q]='\n';
    prog2[q] = '$';
}


void dealNote(char prog1[], char prog2[]) {
    p = q = 0;
    int i = 0;
    int node = 0;
    m = 0;
    char ch = prog1[p++];
    while (ch != '$') {
        if (ch == '/' && node == 0) {
            m++;
            i = 1;
            ch = prog1[p++];
            if (ch == '/') {
                m++;
                do {
                    ch = prog1[p++];
                    m++;
                    if (ch == '$' && node == 0) {
                        p = p - 1;
                        node = 0;
                        ch = prog1[p];
                        break;
                    }
                } while (ch != '\n' || ch != '$');
            } else if (ch == '*') {
                m++;
                do {
                    m++;
                    ch = prog1[p++];
                    if (prog1[p] == '$' && node == 0) {
                        p = p - m;
                        node = 10;
                        ch = '0';
                        break;
                    }
                } while (ch != '*' && prog1[p] != '/' || ch != '$');
                //prog2[q++] = ' ';
                //p++;
                if (node == 11) {
                    p++;
                }
                if (node == 10) {
                    ch = prog1[p];
                }
                prog2[q++] = ch;
                p++;
            } else if (node != 10) {
                p = p - 2;
                ch = prog1[p++];
            }
        }
        if (i == 1)
            ch = prog1[p];
        prog2[q++] = ch;
        ch = prog1[p++];
    }
    prog2[q] = '$';
}

void dealLine(char prog1[], char prog2[]) {
    p = q = 0;
    char ch = prog1[p++];
    while (ch != '$' && q < 19999 && p < 19999) {
        if (ch == '\n') {
            do {
                ch = prog1[p++];
            } while (ch == '\n');
        }
        prog2[q++] = ch;
        ch = prog1[p++];
    }
    prog2[q] = '$';
}

void YCL() {
    dealEmpty(prog1, prog2);
    dealNote(prog2, prog1);
    dealLine(prog1, prog2);
}

void scanner() {
    for (int i = 0; i < 100; i++)
        token[i] = ' ';
    char ch = prog2[p++];
    while (ch == ' ') {
        ch = prog2[p];
        p++;
    }
    if (isLetter(ch)) {
        m = 0;
        while (isLetter(ch) || isNum(ch)) {
            token[m++] = ch;
            ch = prog2[p++];
        }
        token[m++] = '\0';
        p--;
        syn = 25;
        for (int i = 0; i < 45; i++) {
            if (strcmp(token, rwtab[i]) == 0) {
                syn = i;
                break;
            }
        }
    } else if (isNum(ch)) {
        m = 0;
        while (isNum(ch)) {
            token[m++] = ch;
            ch = prog2[p++];
        }
        syn = 26;
        if (isLetter(ch)) {
            while (1) {
                if (!isLetter(ch) && !isNum(ch)) {
                    break;
                }
                token[m++] = ch;
                ch = prog2[p++];
            }
            syn = -1;
        }
        token[m++] = '\0';
        p--;
    } else
        switch (ch) {
            case '<':
                m = 0;
                token[m++] = ch;
                ch = prog2[p++];
                if (ch == '>') {
                    syn = 34;
                    token[m++] = ch;
                } else if (ch == '=') {
                    syn = 35;
                    token[m++] = ch;
                } else {
                    syn = 33;
                    p--;
                }
                token[m++] = '\0';
                break;
            case '>':
                m = 0;
                token[m++] = ch;
                ch = prog2[p++];
                if (ch == '=') {
                    syn = 37;
                    token[m++] = ch;
                } else {
                    syn = 36;
                    p--;
                }
                token[m++] = '\0';
                break;
            case ':':
                m = 0;
                token[m++] = ch;
                ch = prog2[p++];
                if (ch == '=') {
                    syn = 32;
                    token[m++] = ch;
                } else {
                    syn = 31;
                    p--;
                }
                token[m++] = '\0';
                break;
            case '+':
                syn = 27;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '-':
                syn = 28;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '*':
                syn = 29;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '/':
                syn = 30;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '=':
                syn = 38;
                token[0] = ch;
                token[1] = '\0';
                break;
            case ';':
                syn = 41;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '(':
                syn = 42;
                token[0] = ch;
                token[1] = '\0';
                break;
            case ')':
                syn = 43;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '#':
                syn = 0;
                token[0] = ch;
                token[1] = '\0';
                break;
            case '$':
                syn = -2;
                token[0] = ch;
                token[1] = '\0';
                break;
            default:
                syn = -1;
                token[0] = ch;
                token[1] = '\0';
                break;
        }
}

char *dectobin(char *token) {
    int sum = 0;
    int y, x = 1;
    int length = 0;
    int i;
    int n = 0;
    for (i = 0; token[i] >= 48 && token[i] < 57; i++) {
        n = n * 10 + (token[i] - 48);
    }
    while (n != 0) {
        y = n % 2;
        sum += x * y;
        x *= 10;
        n /= 2;
        length++;
    }
    for (i = length - 1; i >= 0; i--) {
        token[i] = (sum % 10) + 48;
        sum /= 10;
    }
    token[length] = '\0';
    return token;
}

int main() {
    p = 0;
    char ch;
    printf("Input:\n");
    do {
        ch = getchar();
        prog1[p++] = ch;
    } while (ch != '$');
    prog1[p] = '$';
    YCL();
    p = 0;
    do {
        scanner();
        if (syn == 25)
            printf("(%d , %s)\n", syn, token);
        else if (syn == 26)
            printf("(%d , %s)\n", syn, dectobin(token));
        else if (syn == -1)
            printf("(error , %s)\n", token);
        else
            printf("(%d , %s)\n", syn, token);
    } while (syn != -2);
//    system("pause");
    return 0;
}