#include <iostream>

// void printValue(int value){}

// lvalue reference - only accepts lvalues
void printValue(int &value) { std::cout << "lvalue reference" << std::endl; }

// const lvalue reference - accept both
void printValue(const int &value) {
  std::cout << "const lvalue reference" << std::endl;
}

// lvalue reference
void printName0(std::string &name) {
  std::cout << "[lvalue] " << name << std::endl;
}

// const lvalue reference
void printName1(const std::string &name) {
  std::cout << "[const lvalue] " << name << std::endl;
}

// temporary - rvalue reference
void printName2(std::string &&name) {
  std::cout << "[rvalue] " << name << std::endl;
}

int main() {
  int i = 10;
  printValue(i);  // lvalue
  printValue(10); // rvalue - temporary value

  std::string name = "Andrej ";
  std::string surname = "Pan";
  std::string fullName = name + surname;

  printName0(fullName);
  // printName0(name + surname); temporary
  // initial value of reference to non-const must be an lvalue

  printName1(fullName);
  printName1(name + surname);

  // printName2(fullName);
  // an rvalue reference cannot be bound to an lvalue
  printName2(name + surname);
}
