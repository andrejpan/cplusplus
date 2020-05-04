#pragma once
#include "Person.hpp"

class Student : public Person
{
private:
  std::string course;

public:
  Student(const std::string &first_Name, const std::string &last_Name, const int &age, std::string course);

  virtual ~Student();

  virtual void display() const;
};
