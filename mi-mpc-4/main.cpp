#include <iostream>
#include "String.cpp"
#include "Lambda.cpp"


int main() {

    String s1;
    String s2("Hello world");
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    s1 = s2;
    std::cout << s1 << std::endl;
    String s3(s1);
    std::cout << s3 << std::endl;
    String s4("Short");
    s4.swap(s3);
    std::cout << s3 << std::endl;
    std::cout << s4 << std::endl;
    String s5 = std::move(s4);
    String s6 (std::move(s3));
    std::cout << s4 << std::endl;
    std::cout << s5 << std::endl;
    std::cout << s3 << std::endl;
    std::cout << s6 << std::endl;


    int a = 0, b = 1, c = 2;
    auto lambda = Lambda(a, b);
    lambda(c);
    std::cout << std::endl << a << std::endl; // prints out "3"

    return 0;
}