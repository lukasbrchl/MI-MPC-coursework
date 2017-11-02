#include <iostream>
#include "String.h"
int main()
{

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
}