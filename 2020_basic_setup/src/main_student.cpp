#include "Student.hpp"

#include <iostream>
#include <memory>

int main()
{

  std::unique_ptr<Person> p = std::make_unique<Student>("Janez", "Novak", 19, "sudoscience");
  p->display();

  return EXIT_SUCCESS;
}
