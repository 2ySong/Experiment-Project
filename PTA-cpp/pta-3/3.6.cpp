//
// Created by szy on 2021/11/1.
//

#include"bits/stdc"


using namespace std;

stack<char> st;

bool isMarch(string str) {
    int len = str.size();
    if (len % 2) return false;
    for (int i = 0; i < str.size(); i++) {
        switch (str[i]) {
            case '(':
            case '[':
            case '{':
                st.push(str[i]);
                break;
            case ')':
                if (!st.empty() && st.top() == '(') st.pop();
                else return false;
                break;
            case ']':
                if (!st.empty() && st.top() == '[') st.pop();
                else return false;
                break;
            case '}':
                if (!st.empty() && st.top() == '{') st.pop();
                else return false;
                break;
        }
    }
    return true;
}

int main() {
    int T;
    string str;
    cin >> T;
    cout << endl;
    while (T--) {
        cin >> str;
        cout << ((isMarch(str)) ? "Yes" : "No") << endl;
    }
    return 0;
}
