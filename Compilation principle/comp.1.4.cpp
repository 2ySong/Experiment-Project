
//�����������ͷ�ļ�
#include "iostream"
#include <cstdio>
#include <cstring>
//���������ռ�std�ڶ�������б�ʶ��
using namespace std;
//����ʷ���Ԫ���ȴ�СΪ12
char token[12];
//�����ļ�ָ��fin
FILE *fin;
//�ʷ���Ԫ�е��ַ��±�
int token_index = 0;
//��ȡ�ӳ��������
int row = 1;
//����ӳ���Ŀ�ͷ������ǿ�ͷΪ0������Ϊ1
int start_flag = 0;
//�ʷ���Ԫ�е��ַ�
char ch;
//�ؼ���
const char keyWord[13][20] = {"main", "if", "else", "do", "while", "for", "switch", "case", "int", "double", "float",
                              "long", "void"};

//��ʼ���ʷ���Ԫ
void init_token() {
    int i;
    for (i = 0; i < 12; i++) {
        token[i] = NULL;
    }
}

//�жϴʷ���Ԫ�������ͣ�������Ĳ��֣�
int judge_token() {
    //��ʼ���ʷ���Ԫ
    init_token();
    //�ж��ǲ����ӳ���Ŀ�ͷ������ǵĻ�����һ����Ҫ��������һ�ζ�ȡ
    if (start_flag == 0) {
        ch = getc(fin);
    }
    start_flag = 1;
    //�ж���ǰ��ȡ�����ַ��ǲ��ǿո�ˮƽ�Ʊ�����з��������������������ȡ��һλ�ַ�
    while (ch == ' ' || ch == '\t' || ch == '\n') {
        if (ch == '\n') {
            row++;
        }
        ch = getc(fin);
    }
    //�ʷ���Ԫ���ַ����±�����Ϊ0
    token_index = 0;
    //�����������Ϊ��ʶ�����߱�����
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        while ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            token[token_index++] = ch;
            ch = getc(fin);
        }
        token[token_index++] = '\0';
        for (int i = 0; i < 13; i++) {
            //ʹ��strcmp()�������õ�ǰ�ʷ���Ԫ����֪�ؼ��ֱȽ�
            if (strcmp(token, keyWord[i]) == 0) {
                //��ӡ�ؼ��ֶ�Ӧ��������
                return i + 3;
            }
        }
        //���û���ҵ���Ӧ�Ĺؼ��֣���Ϊ��ʶ��
        return 2;
    }
        //Ϊ����
    else if (ch >= '0' && ch <= '9') {
        while ((ch >= '0' && ch <= '9') || ch == '.') {
            token[token_index++] = ch;
            ch = getc(fin);
        }
        return 1;
    }
        //����Ϊ������������
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
                //�ж��ǲ���ע�͵Ľ�β
                ch = getc(fin);
                if (ch == '/') {
                    token[token_index++] = ch;
                    ch = getc(fin);
                    return 32;
                } else {
                    return 20;
                }
            case '/':
                //�ж��ǲ���ע�͵Ŀ�ͷ
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
                //EOF���ļ�������־�������ǰchΪEOF,˵���ӳ����Ѷ���
            case EOF:
                return -1;
                //�����������δ���֣���ǰ����ȡ�Ĵʷ���Ԫ����
            default:
                ch = getc(fin);
                return -10;
        }
    }
}

//��ӡ�����ӳ�������дʷ���Ԫ�����ͣ����д��󣬴�ӡ���������
void getWord() {
    //��������result����¼�ʷ���Ԫ��������
    int result;
    /*  ����ǰ��ȡ���ַ���Ϊ�ļ�������EOF���������ȡ
        ʵ���˼򵥵Ļָ�����������ɨ��*/
    cout << "���" << "\t" << "��Ԫ" << "\t" << "����" << endl;
    //�ʷ���Ԫ�ı��
    int token_number = 1;
    while (result != -1) {
        result = judge_token();
        switch (result) {
            case -10:
                cout << "�� " << row << " �г��ִ���." << endl;
                break;
            default:
                cout << token_number << "\t" << token << "\t" << result << endl;
                break;
        }
        token_number++;
    }
}

int main() {
    //��ֻ����ʽ�򿪱����ļ���compiler.txt
    fin = fopen("E:\\Love me\\Compilation principle\\compiler.txt", "r");
    //��ӡ�����ӳ�������дʷ���Ԫ������
    getWord();
    return 0;
}
