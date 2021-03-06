#include <cstring>
#include <iostream>

// Move Semantics in C++
// https://www.youtube.com/watch?v=ehMg6zvXuMY
// std::move and the Move Assignment Operator in C++
// https://www.youtube.com/watch?v=OWNeCTd7yQE
class MyString {
public:
  // default constructor
  MyString() : m_Data(nullptr), m_Size(0) {}
  // contructor
  MyString(const char *string) {
    m_Size = strlen(string);
    m_Data = new char[m_Size];
    memcpy(m_Data, string, m_Size);
    std::cout << "MyString() created" << std::endl;
  }
  // copy constructor
  MyString(const MyString &other) {
    // performing deep copy
    m_Size = other.m_Size;
    m_Data = new char[m_Size];
    memcpy(m_Data, other.m_Data, m_Size);
    std::cout << "MyString() created via copy constructor" << std::endl;
  }
  // move constructor for rvalue
  MyString(MyString &&other) noexcept {
    // performing "shalow" copy
    m_Size = other.m_Size;
    m_Data = other.m_Data; // assign the pointer instead of copying
    std::cout << "MyString() created via move constructor" << std::endl;

    other.m_Size = 0;
    other.m_Data = nullptr;
  }
  // move assignment operator should be included when move constructor is implemented
  MyString &operator=(MyString &&other) noexcept {
    std::cout << "Move assignment operator was called" << std::endl;
    if (this != &other) {
      delete[] m_Data;

      // performing "shalow" copy
      m_Size = other.m_Size;
      m_Data = other.m_Data; // assign the pointer instead of copying

      other.m_Size = 0;
      other.m_Data = nullptr;
    }
    return *this;
  }
  // destructor
  ~MyString() {
    if (m_Data != nullptr) {
      delete[] m_Data;
    }
    std::cout << "~MyString()" << std::endl;
  }
  void print() {
    for (uint32_t i = 0; i < m_Size; ++i) {
      printf("%c", m_Data[i]);
    }
    printf("\n");
  }

private:
  char *m_Data = nullptr;
  uint32_t m_Size = 0;
};

class Entity {
public:
  Entity(const MyString &name) : m_Name(name) {
    std::cout << "Entity() via copy constructor" << std::endl;
  }

  Entity(MyString &&name)
      : // m_Name(name) { // this calls copy contructor
        m_Name((MyString &&) name) { // m_Name(std::move(name))
    std::cout << "Entity() via move constructor" << std::endl;
  }
  ~Entity() { std::cout << "~Entity()" << std::endl; }

  void printName() { m_Name.print(); }

private:
  MyString m_Name;
};

int main() {
  Entity entity("Andrej");
  // Entity entity(MyString("Andrej"));
  entity.printName();

  MyString myString = "Hello";
  // MyString destString(std::move(myString));
  // std::move converts existing variable into temporary
  MyString destString = std::move(myString);
  myString.print(); // empty string
  destString.print();

  // move assignment operator
  MyString apple = "Apple";
  destString = std::move(apple);
  apple.print();
  destString.print();
}
