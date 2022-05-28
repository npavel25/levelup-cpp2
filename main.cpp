#include <iostream>
#include "cowstring.h"

int main()
{
    cow::String object;
    cow::String object1("abc");
    cow::String object2(object1);

    std::cout << object1.c_str() << std::endl;
    std::cout << object2.c_str() << std::endl;

    cow::String obj3(object);
    std::cout << "Obj3 size: " << obj3.size() << std::endl;

    cow::String object4(std::move(object1));
    std::cout << object4.c_str() << std::endl;

    cow::String obj5("To be ");
    std::cout << obj5.append("or not to be").c_str() << std::endl;

}
