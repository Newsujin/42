#include <iostream>
#include <sstream>

int main(void) {
    std::stringstream stream;
    std::string str = "123 123.456";
    int i;
    double d;
    stream.str(str);
    stream >> i >> d;
    std::cout << "int : " << i << ", double : " << d << std::endl;
}