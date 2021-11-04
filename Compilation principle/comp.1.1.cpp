//设计并实现一个包含预处理功能的词法分析程序，加深对编译原理中词法分析过程的理解


#include <cstring>
#include"iostream"

using namespace std;


//存放处理后的字符串
char tempstr[255] = {};
//空格标志
bool temp = false;
//临时数组
char word[255] = {};
//keyword关键字
string Keyword[26] = {//
        "main", "if", "then", "while", "do",
        "static", "default", "do", "int",
        "double", "struct", "break", "else",
        "long", "switch", "case", "typedef",
        "char", "return", "const", "float",
        "short", "continue", "for", "void",
        "sizeof"};


int Keyword_num[26] = {1, 2, 3, 4, 5, 6, 39, 40, 7, 8, 9, 10, 11,
                       12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
//部分运算符，定界符等
char Symbol[9] = {'+', '-', '*', '/', '=', ';', '(', ')', '#'};
//对应的种码值
int Symbol_num[9] = {27, 28, 29, 30, 38, 41, 42, 43, 0};


//判断是否为字母
bool IsChar(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}


//判断是否为数字
bool IsDigit(char ch) {
    if (ch >= '0' && ch <= '9')
        return true;
    return false;
}


//判断是否为定界符等
int IsSymbol(char ch) {
    for (int i = 0; i < 9; i++) {
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
void Space(char a[]) {
    int j = 0;
    memset(word, 0, 255);//需要清空，不然可能残留上次的字符串
    temp = false;
    for (int i = 0; i < 255; i++) {
        if (a[i] != ' ' && a[i] != '\t') {//空格符
            word[j++] = a[i];
            temp = false;
        } else {
            if (!temp && a[i] != '\t') {
                word[j++] = a[i];
                temp = true;
            }
        }
    }
}


//处理"//"注释
void prePro() {
    int j = 0;
    memset(tempstr, 0, 255);
    for (int i = 0; i){
            if (word[i]=='/'&&word[i+1]=='/')
            {

                while (i{
                        i++;
                }
            }


            else {

                tempstr[j++] = word[i];
            }
    }
}


int main() {
    char instr[255] = {}; //接收输入字符串
    bool flag = false; //多行注释标志,false为未处于注释区域
    string Token;//存放字符串
    char *str = NULL;//存放每行的字符串
    char delims[] = " ";//分割标志
    //freopen("test.cpp","r",stdin);
    //freopen("result.txt","w",stdout); //此行注释后，控制台输出，
    //否则文本输出
    while ((gets(instr)) != NULL) {

        Space(instr);
        prePro();


        str = strtok(tempstr, delims);//分割字符串


        while (str != NULL) {

            //头文件，宏定义
            if (*(str) == '#') {

                printf("#\n");
                break;
            }


            for (int i = 0; i{
                    if (*(str+i)=='/')
                    {

                        if (*(str + i + 1) == '*') {

                            flag = true;
                            break;
                        }
                    }
                    //注释处理: */,注释区域结束
                    if (*(str+i)=='*'&&flag)
                    {

                        if (*(str + i + 1) == '/') {

                            flag = false;
                            i++;
                            break;
                        }
                    }
                    //标识符，关键词
                    if (IsChar(*(str+i))&&(!flag))
                    {

//                    printf("进入标识符判断\n");
                        while (IsChar(*(str + i)) || IsDigit(*(str + i))
                               || *(str + i) == '_') {

                            Token += *(str + i);
                            i++;
                        }


                        if (IsKeyword(Token) != 25) {

                            printf("%s---->%d\n", Token.c_str(),
                                   Keyword_num[IsKeyword(Token)]);
                        } else printf("%s---->25\n", Token.c_str());


                        Token = "";
//                printf("退出标识符判断\n");
                    }
                    if (IsDigit(*(str+i))&&(!flag))
                    {

//                        printf("进入数字判断\n");
                        while (IsDigit(*(str + i))) {

                            Token += *(str + i);
                            i++;
                        }
                        printf("%s------>26\n", Token.c_str());
                        Token = "";
                    }


                    //<,<=,<>
                    if (*(str+i)=='<'&&(!flag))
                    {

                        if (*(str + i) == '=') {
                            printf("<=------>35\n");
                            i++;
                        }
                        if (*(str + i) == '>') {
                            printf("<>------>34\n");
                            i++;
                        } else printf("<------>33\n");
                    }
                    //>,>=
                    else if (*(str+i)=='>'&&(!flag))
                    {

                        if (*(str + i + 1) == '=') { printf(">------>37\n"); }
                        else printf(">-------36\n");
                    }
                    //:,:=
                    else if (*(str+i)==':'&&(!flag))
                    {

                        if (*(str + i + 1) == '=') { printf(":=------->32\n"); }
                        else printf(":-------->31\n");
                    }
                    //余下定界符等
                    else if (IsSymbol(*(str+i))!=-1&&(!flag))
                    {

                        printf("%c------->%d\n", *(str + i),
                               Symbol_num[IsSymbol(*(str + i))]);
                    }
            }
                    str = strtok(NULL, delims);
        }
    }


    return 0;
}
