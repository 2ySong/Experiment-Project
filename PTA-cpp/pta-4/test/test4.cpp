#include <iostream>

using namespace std;

int main() {
    int a = 5, b = 3;
    int c = (a < b) ? (a++) : (++b);
    printf("%d,%d,%d",a, b, c);
//    return 0;
}
