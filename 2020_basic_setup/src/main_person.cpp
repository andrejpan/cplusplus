#include "Person.hpp"

#include <iostream>


int main()
{
  Person p("Gerry", "Wick");

  //std::cout << p.GetFirstName() << std::endl;
  p.SetAge(34);

  p.display();

  // this line will not work because firstName is private
  //p.firstName = "Gerry";

  return EXIT_SUCCESS;
}
