//第二版--词法分析程序
#include<stdio.h>
#include<String.h>
int main() {
    FILE *p;
    int falg = 0, len, i = 0, j = 0;//
    char *rwtab[27] = {" ", "main", "if", "then", "while", "do",
                       "static", "int", "double", "struct", "break", "else", "long",
                       "switch", "case", "typedef", "char", "return", "const", "float",
                       "short", "continue", "for", "void", "sizeof", "default", "do"};//26个

    char str[1000], str1[1000], c;
    int syn, num;
    char token[200];

    if ((p = fopen("E:\\Love me\\Compilation principle\\test1.txt", "rt")) == NULL) {
        printf("无法打开");
        return 0;
    }

    //fgets(str,1000,p);
    while ((c = getc(p)) != EOF) {
        str[i++] = c;
    }
    fclose(p);
    if ((p = fopen("E:\\Love me\\Compilation principle\\test2.txt", "w")) == NULL) {
        printf("无法打开");
        return 0;
    }
    str[i] = '\0';
    //printf("%s\n",str);
    for (i = 0; str[i] != '\0';) {
        j = 0;
        num = -1;
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_') {
            while ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
                   (str[i] >= '0' && str[i] <= '9') || str[i] == '_') {
                token[j++] = str[i++];
            }
            token[j] = '\0';
            for (int k = 1; k < 27; k++) {
                if (strcmp(rwtab[k], token) == 0)
                    break;
                if (k < 25)
                    syn = k;
                else if (k == 25)
                    syn = 39;
                else if (k == 26)
                    syn = 40;
                else syn = 25;
            }//关键字和标示符处理
            if ((str[i] >= '0' && str[i] <= '9') && ((str[i + 1] >= 'a' && str[i + 1] <= 'z') ||
                                                     (str[i + 1] >= 'A' && str[i + 1] <= 'Z') || str[i + 1] == '_' ||
                                                     (str[i + 1] >= '0' && str[i + 1] <= '9'))) {
                syn = -3;
                while ((str[i] >= 'a' && str[i] <= 'z') ||
                       (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_' || (str[i] >= '0' && str[i] <= '9')) {
                    token[j++] = str[i++];
                }
                i--;
            } else if (str[i] >= '0' && str[i] <= '9') {
                num = 0;
                while (str[i] >= '0' && str[i] <= '9') {
                    num = num * 10 + str[i++] - '0';
                }
                syn = 26;
            }//数字在此处处理
            else {//printf("%c********************************\n",str[i]);
                if (str[i] == ':' && str[i + 1] == '=') {
                    syn = 32;
                    token[j++] = str[i];
                    token[j++] = str[i++];
                } else if (str[i] == '<' && str[i + 1] == '>') {
                    syn = 34;
                    token[j++] = str[i];
                    token[j++] = str[i++];
                } else if (str[i] == '<' && str[i + 1] == '=') {
                    syn = 35;
                    token[j++] = str[i];
                    token[j++] = str[i++];
                } else if (str[i] == '>' && str[i + 1] == '=') {
                    syn = 36;
                    token[j++] = str[i];
                    token[j++] = str[i++];
                } else if (str[i] == ' ') {
                    i++;
                    syn = -2;
                }
                else {
                    switch (str[i]) {
                        case '+':
                            syn = 27;
                            break;
                        case '-':
                            syn = 28;
                            break;
                        case '*':
                            syn = 29;
                            break;
                        case '/':
                            syn = 30;
                            break;
                        case ':':
                            syn = 31;
                            break;
                        case '<':
                            syn = 33;
                            break;
                        case '>':
                            syn = 36;
                            break;
                        case ';':
                            syn = 41;
                            break;
                        case ')':
                            syn = 43;
                            break;
                        case '(':
                            syn = 42;
                            break;
                        case '#':
                            syn = 0;
                            break;
                        case '=':
                            syn = 38;
                            break;
                        default:
                            syn = -1;
                            break;
                    }
                    //printf("%c********************************\n",str[i]);
                    token[j++] = str[i++];
                }
            }
            token[j] = '\0';
            if (num != -1) {
                printf("%d %d\n", num, syn);
                fprintf(p, "%d %d\n", num, syn);
                char A[100];
                int i = 0;
                while (num) {
                    A[i++] = num % 2;
                    num = num / 2;
                }

                for (i--; i >= 0; i--) {
                    printf("%c ", A[i] + '0');
                    fprintf(p, "%c ", A[i] + '0');
                }
                printf(" %d\n", syn);
                fprintf(p, "%d\n", syn);
            } else if (syn != -1 && syn != -2 && syn != -3) {
                printf("%s %d\n", token, syn);
                fprintf(p, "%s %d\n", token, syn);
            } else if (syn == -1) {
                printf("%s error\n", token);
                fprintf(p, "%s error\n", token);
            } else if (syn == -3) {
                printf("%s error ID\n", token);
                fprintf(p, "%s error ID\n", token);
            }
        }
        fclose(p);
        return 0;
    }
}