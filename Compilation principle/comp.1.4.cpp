
//导入程序所需头文件
#include "iostream"
#include <cstdio>
#include <cstring>
//调用命名空间std内定义的所有标识符
using namespace std;
//定义词法单元长度大小为12
char token[12];
//定义文件指针fin
FILE *fin;
//词法单元中的字符下标
int token_index = 0;
//读取子程序的行数
int row = 1;
//标记子程序的开头，如果是开头为0，不是为1
int start_flag = 0;
//词法单元中的字符
char ch;
//关键字
const char keyWord[13][20] = {"main", "if", "else", "do", "while", "for", "switch", "case", "int", "double", "float",
                              "long", "void"};

//初始化词法单元
void init_token() {
    int i;
    for (i = 0; i < 12; i++) {
        token[i] = NULL;
    }
}

//判断词法单元所属类型（程序核心部分）
int judge_token() {
    //初始化词法单元
    init_token();
    //判读是不是子程序的开头，如果是的话，第一次需要主动进行一次读取
    if (start_flag == 0) {
        ch = getc(fin);
    }
    start_flag = 1;
    //判读当前读取到的字符是不是空格，水平制表符或换行符如果是则跳过，继续读取下一位字符
    while (ch == ' ' || ch == '\t' || ch == '\n') {
        if (ch == '\n') {
            row++;
        }
        ch = getc(fin);
    }
    //词法单元中字符的下标重置为0
    token_index = 0;
    //下列情况可能为标识符或者变量名
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            token[token_index++] = ch;
            ch = getc(fin);
        }
        token[token_index++] = '\0';
        for (int i = 0; i < 13; i++) {
            //使用strcmp()方法，让当前词法单元与已知关键字比较
            if (strcmp(token, keyWord[i]) == 0) {
                //打印关键字对应的类型码
                return i + 3;
            }
        }
        //如果没有找到对应的关键字，则为标识符
        return 2;
    }
        //为数字
    else if (ch >= '0' && ch <= '9') {
        while ((ch >= '0' && ch <= '9') || ch == '.') {
            token[token_index++] = ch;
            ch = getc(fin);
        }
        return 1;
    }
        //否则为界符或者运算符
    else {
        token[token_index++] = ch;
        switch (ch) {
            case '(':
                ch = getc(fin);
                return 16;
            case ')':
                ch = getc(fin);
                return 17;
            case '{':
                ch = getc(fin);
                return 33;
            case '}':
                ch = getc(fin);
                return 34;
            case '+':
                ch = getc(fin);
                if (ch == '+') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 29;
                } else {
                    return 18;
                }
            case '-':
                ch = getc(fin);
                if (ch == '-') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 30;
                } else {
                    return 19;
                }
            case '*':
                //判读是不是注释的结尾
                ch = getc(fin);
                if (ch == '/') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 32;
                } else {
                    return 20;
                }
            case '/':
                //判读是不是注释的开头
                ch = getc(fin);
                if (ch == '*') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 31;
                } else {
                    return 21;
                }
            case '=':
                ch = getc(fin);
                if (ch == '=') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 23;
                } else {
                    return 22;
                }
            case '>':
                ch = getc(fin);
                if (ch == '=') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 24;
                } else {
                    return 23;
                }
            case '<':
                ch = getc(fin);
                if (ch == '=') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 26;
                } else {
                    return 25;
                }
            case ';':
                ch = getc(fin);
                return 27;
            case '"':
                ch = getc(fin);
                return 28;
            case '!':
                ch = getc(fin);
                if (ch == '=') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 37;
                } else {
                    return 36;
                }
            case '#':
                ch = getc(fin);
                return 0;
            case ',':
                ch = getc(fin);
                return 35;
                //EOF，文件结束标志，如果当前ch为EOF,说明子程序已读完
            case EOF:
                return -1;
                //若以上情况均未出现，则当前所读取的词法单元错误
            default:
                ch = getc(fin);
                return -10;
        }
    }
}

//打印编译子程序的所有词法单元的类型，若有错误，打印出错的行数
void getWord() {
    //声明变量result，记录词法单元所属类型
    int result;
    /*  若当前读取的字符不为文件结束符EOF，则继续读取
        实现了简单的恢复方法，重新扫描*/
    cout << "编号" << "\t" << "单元" << "\t" << "类型" << endl;
    //词法单元的编号
    int token_number = 1;
    while (result != -1) {
        result = judge_token();
        switch (result) {
            case -10:
                cout << "第 " << row << " 行出现错误." << endl;
                break;
            default:
                cout << token_number << "\t" << token << "\t" << result << endl;
                break;
        }
        token_number++;
    }
}

int main() {
    //以只读方式打开编译文件，compiler.txt
    fin = fopen("E:\\Love me\\Compilation principle\\compiler.txt", "r");
    //打印编译子程序的所有词法单元的类型
    getWord();
    return 0;
}
