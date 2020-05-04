
#include "Person.hpp"
#include <iostream>


Person::Person(const std::string &fName, const std::string &lName)
{
  firstName = fName;
  lastName = lName;
  age = 0;
}

//TODO more efficient constructor
Person::Person(const std::string &fName, const std::string &lName, const int &age)
{
  firstName = fName;
  lastName = lName;

  this->age = age;
}


Person::~Person()
{
  std::cout << "Destructor with person " << firstName << " has been activated." << std::endl;
}

void Person::SetFirstName(const std::string &fName)
{
  this->firstName = fName;
}

std::string Person::GetFirstName()
{
  return this->firstName;
}

void Person::SetLastName(const std::string &lName)
{
  this->lastName = lName;
}

std::string Person::GetLastName()
{
  return this->lastName;
}

void Person::SetAge(const int &age)
{
  if (age > 0) {
    this->age = age;
  } else {
    std::cout << "Please enter a valid age" << std::endl;
  }
}

int Person::GetAge()
{
  return this->age;
}

void Person::display() const
{
  std::cout << firstName << " " << lastName << ", age of " << age << std::endl;
}
