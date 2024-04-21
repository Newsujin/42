#include <iostream>

class ConstExample {
    public:
        void print() const {std::cout << "const" << std::endl;};
        void print() {std::cout << "normal" << std::endl;};
};

int main()
{
    ConstExample object1;
    const ConstExample object2;
    object1.print();
    object2.print();
    return 0;
}
