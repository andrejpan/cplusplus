#include "Student.hpp"
#include <iostream>
#include <utility>//TODO what is with libraries and flags??

Student::Student(const std::string &first_Name, const std::string &last_Name, const int &age, std::string course) : Person(first_Name, last_Name, age), course(std::move(course))
{}

Student::~Student()
{
  std::cout << "Destructor with student " << this->firstName << " has been activated." << std::endl;
}

void Student::display() const
{
  // Call base-class version of display()
  Person::display();
  // Display student related info.
  std::cout << "Enrolled into course " << this->course << std::endl;
}
