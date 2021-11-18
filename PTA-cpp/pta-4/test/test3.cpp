#include <iostream>

using namespace std;
int i = 20;

void add() {
    static int i;
    cout << "i=" << i << endl;
}

int main() {
    i = i + 10;
    cout << "i=" << i << endl;
    int i = 5;
    i += 30;
    cout << "i=" << i << endl;
    add();

//    return 0;
}
