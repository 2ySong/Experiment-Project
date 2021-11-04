#include<iostream>
#include<string>
#include <list>

using namespace std;

int main() {
    int n;
    string s, name;
    cin >> n;
    list<string> l;
    while (n--) {
        cin >> s;
        if (s == "in") {
            cin >> name;
            l.push_back(name);//入栈
        } else if (s == "out") {
            l.pop_front();//出栈
        } else if (s == "q") {
            if (l.empty()) {//判断是否为空
                cout << "NULL" << endl;
            } else {
                cout << l.front() << endl;//输出第一个人的名字
            }
        }
    }

    return 0;
}

