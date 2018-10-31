#ifndef CppClasses_H
#define CppClasses_H

#include <iostream>

class Base
{

  public:
    Base(){};
    ~Base(){};
    virtual void virtualFunction() {std::cout << "In Base virtual Function" << std::endl;};
    void publicFunction(std::string str) {std::cout << "In Base public Function: " << str << std::endl;};

    private:
    virtual void virtualPrivateFunction() {std::cout << "In Base virtual private Function" << std::endl;};
    std::string privateString;

};

class Derived
{

  public:
    Derived(){};
    ~Derived(){};
    void virtualFunction() {std::cout << "In Derived virtual Function " << std::endl; this->virtualPrivateFunction();};
    void DerpublicFunction(std::string str) {std::cout << "In derived public Function: " << str << std::endl;};

    private:
    void virtualPrivateFunction() {std::cout << "In Derived virtual private Function" << std::endl;};
};

#endif // CppClasses_H