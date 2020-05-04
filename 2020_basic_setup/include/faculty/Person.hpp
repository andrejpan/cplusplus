#pragma once

#include <string>

class Person
{

protected:
  std::string firstName;
  std::string lastName;
  int age;

public:
  Person(const std::string &fName, const std::string &lName);

  Person(const std::string &fName, const std::string &lName, const int &age);

  // If there is at least virtual function, there should be virtual destructor as well.
  virtual ~Person();

  void SetFirstName(const std::string &fName);
  std::string GetFirstName();

  void SetLastName(const std::string &lName);
  std::string GetLastName();

  void SetAge(const int &age);
  int GetAge();

  virtual void display() const;
};
