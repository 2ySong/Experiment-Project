//
//
// Created by szy on 2021/10/25.
// 第四版--第三版改进，用括号表示

#include <cstring>
#include "windows.h"
#include"iostream"

using namespace std;
//存放处理后的字符串
char tempStr[255] = {};
//空格标志
bool temp = false;
//临时数组
char word[255] = {};
string Keyword[26] = {
        "main", "if", "then", "while", "do",
        "static", "default", "do", "int", "double",
        "struct", "break", "else", "long", "switch",
        "case", "typedef", "char", "return", "const",
        "float", "short", "continue", "for", "void",
        "sizeof"};//关键字
//关键字对应的种别码
int Keyword_num[26] = {1, 2, 3, 4, 5, 6, 39, 40, 7, 8, 9, 10, 11,
                       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
//部分运算符，定界符等
char Symbol[12] = {'+', '-', '*', '/', ':', '<', '>', '=', ';', '(', ')', '#'};
//对应的种码值
int Symbol_num[12] = {27, 28, 29, 30, 31, 33, 36, 38, 41, 42, 43, 0};

//判断是否为字母
bool IsLetter(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

//判断是否为数字
bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9' || ch == '.')
        return true;
    return false;
}

//判断是否为运算符、定界符等
int IsSymbol(char ch) {
    for (int i = 0; i < 12; i++) {
        if (ch == Symbol[i])
            return i;
    }
    return -1;
}

//判断是否为关键字
int IsKeyword(string str) {
    for (int i = 0; i < 26; i++) {
        if (str == Keyword[i]) {
            return i;
        }
    }
    //不是关键字即为ID
    return 25;
}


//空格处理
void Space(char space[]) {
    int j = 0;
    memset(word, 0, 255);//需要清空，不然可能残留上次的字符串
    temp = false;//默认非空格
    for (int i = 0; i < 255; i++) {
        if (space[i] != ' ' && space[i] != '\n') {//空格符
            word[j++] = space[i];
            temp = false;
        } else {//  空格情况
            if (!temp && space[i] != '\n') {
                word[j++] = space[i];
                temp = true;
            }
        }
    }
}

//处理"//"注释
void prePro() {
    int j = 0;
    memset(tempStr, 0, 255);//清空
    for (int i = 0; i < 255; i++) {
        if (word[i] == '/' && word[i + 1] == '/') {
            while (i < 255) {
                i++;
            }
        } else {
            tempStr[j++] = word[i];
        }
    }
}

//函数声明
int deal();

int main() {
    deal();
    char instr[255] = {}; //接收输入字符串
    bool flag = false; //多行注释标志,false为未处于注释区域
    string Token;//存放字符串
    char *str = NULL;//存放每行的字符串
    char delims[] = " ";//分割标志
//    int f = 1;
    freopen("E:\\Love me\\Compilation principle\\test1.txt", "r", stdin);
    freopen("E:\\Love me\\Compilation principle\\result.txt", "w", stdout); //此行注释后，控制台输出，
    //否则文本输出
//    printf("单词符号\t种别码\n");
    while ((gets(instr)) != NULL) {
        Space(instr);
        prePro();
        str = strtok(tempStr, delims);//分割字符串
        while (str != NULL) {
            //头文件，宏定义
            if (*(str) == '#') {
                printf("(# , 0)\n");
                break;
            }
            for (int i = 0; i < 2; i++) {
                if (*(str + i) == '/') {
                    if (*(str + i + 1) == '*') {
                        int g = 2;
                        if (*(str + i + 2) == '/') {
                            if (*(str + i + 3) == '*') {
                                printf("error:Multi-line comment format wrong!! The following characters are no longer recognized");
//                                f = -1;
                                return 0;
//                                flag = true;
                            } else {
                                flag = true;
                                break;
                            }
                        }//多行注释
                        else {
                            flag = true;
                            break;
                        }
                    }
                }
                //注释处理: */,注释区域结束
                if (*(str + i) == '*' && flag) {
                    if (*(str + i + 1) == '/') {
                        flag = false;
                        i++;
                        break;
                    }
                }

                //标识符，关键词
                if (IsLetter(*(str + i)) && (!flag)) {
                    while (IsLetter(*(str + i)) || IsDigit(*(str + i)) || *(str + i) == '_') {
                        Token += *(str + i);
                        i++;
                    }

                    if (IsKeyword(Token) != 25) {
                        printf("(%s , %d)\n", Token.c_str(), Keyword_num[IsKeyword(Token)]);
                    } else printf("(%s , 25)\n", Token.c_str());
                    Token = "";
//                printf("退出标识符判断\n");
                }
                if (IsDigit(*(str + i)) && (!flag)) {
//                        printf("进入数字判断\n");
                    while (IsDigit(*(str + i))) {
                        Token += *(str + i);
                        i++;
                    }
                    printf("(%s , 26)\n", Token.c_str());
                    Token = "";
                }

                //<,<=,<>
                if (*(str + i) == '<' && (!flag)) {
                    if (*(str + i) == '=') {
                        printf("(<= , 35)\n");
                        i++;
                    }
                    if (*(str + i) == '>') {
                        printf("(<> , 34)\n");
                        i++;
                    } else printf("(< , 33)\n");
                }
                    //>,>=
                else if (*(str + i) == '>' && (!flag)) {

                    if (*(str + i + 1) == '=') { printf("(>= , 37)\n"); }
                    else printf("(> , 36)\n");
                }
                    //:,:=
                else if (*(str + i) == ':' && (!flag)) {

                    if (*(str + i + 1) == '=') { printf("(:= , 32)\n"); }
                    else printf("(: , 31)\n");
                }
                    //余下定界符等
                else if (IsSymbol(*(str + i)) != -1 && (!flag)) {

                    printf("(%c , %d)\n", *(str + i),
                           Symbol_num[IsSymbol(*(str + i))]);
                }
            }
            str = strtok(NULL, delims);
        }
    }
    return 0;
}

int deal() {
    FILE *p;
    int falg = 0, len, i = 0, j = 0;//
    char str[1000], str1[1000], c;
    if ((p = fopen("E:\\Love me\\Compilation principle\\test.txt", "rt")) == NULL) {
        printf("Unable to open");
        return 0;
    } else {
        //fgets(str,1000,p);
        while ((c = getc(p)) != EOF) {
            str[i++] = c;
        }
        fclose(p);
        str[i] = '\0';
        for (i = 0; i < strlen(str); i++) {
            if (str[i] == '/' && str[i + 1] == '/') {
                while (str[i++] != '\n') {}
            }//单行注释
            else if (str[i] == '/' && str[i + 1] == '*') {
                if (str[i + 2] == '/' && str[i + 3] == '*') {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                            FOREGROUND_INTENSITY | FOREGROUND_RED);//设置红色
//                    cout << "红色testCOLOR（设置的颜色为红色）" << endl;
                    cout << "error: Multi-line comment format wrong!! The following characters are no longer recognized"
                         << endl;
                    return 0;
                }
                while (!(str[i] == '*' && str[i + 1] == '/')) { i++; }
                i += 2;
            }//多行注释
            else if (str[i] == ' ' && str[i + 1] == ' ') {
                while (str[i] == ' ') { i++; }
                i--;
                if (str1[j - 1] != ' ')
                    str1[j++] = ' ';
            }//多个空格，去除空格
            else if (str[i] == '\n') {
                if (str1[j - 1] != ' ')
                    str1[j++] = ' ';
            }//换行处理，
            else if (str[i] == 9) {
                while (str[i] == 9) {
                    i++;
                }
                if (str1[j - 1] != ' ')
                    str1[j++] = ' ';
                i--;
            }//tab键处理
            else str1[j++] = str[i];//其他字符处理
        }
        str1[j] = '\0';

        if ((p = fopen("E:\\Love me\\Compilation principle\\test1.txt", "w")) == NULL) {
            printf("can not find it!");
            return 0;
        } else {
            if (fputs(str1, p) != 0) {
                printf("Storage failed!");
            } else printf("Storage successful!");
        }
        fclose(p);
    }
    return 0;
}