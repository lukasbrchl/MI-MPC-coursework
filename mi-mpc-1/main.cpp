#include <iostream>
#include <cstddef>
#include "String.cpp"


class String;

using namespace std;

int main() {
    cout << String("0") << endl;
    cout << String("01") << endl;
    cout << String("012") << endl;
    cout << String("0123") << endl;
    cout << String("01234") << endl;
    cout << String("012345") << endl;
    cout << String("0123456") << endl;
    cout << String("01234567") << endl;
    cout << String("01234568") << endl;
    cout << String("012345689") << endl;
    cout << String("01234568910") << endl;
    return 0;
}