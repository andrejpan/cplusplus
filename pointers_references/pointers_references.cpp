#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl;

/*void Increment(int value)
{
    // this will just increment value locally
    value++;
}*/

void Increment(int *value)
{
  // dereference pointer and increment value
  (*value)++;
}

void IncrementReference(int &value)
{
  // reference
  value++;
}


int main()
{

  // variable on the stack
  auto var = 5;
  LOG(var);

  // not a valid pointer
  void *ptr0 = nullptr;

  int *ptr2 = &var;

  // User should not do this
  //double *ptr3 = (double *)&var;

  // dereferencing
  *ptr2 = 10;
  LOG(var);

  // TODO find out why this does not work...
  int ptr3 = 11;
  LOG(var);

  // variable on the heap
  char *buffer = new char[8];
  memset(buffer, 0, 8);
  delete[] buffer;

  // references
  int &ref1 = var;//alias for var
  ref1 = 2;
  LOG(var);

  Increment(&var);
  LOG(var);

  IncrementReference(var);
  LOG(var);

  // reference can be assigned just to one value and can not be changed to another
  return 0;
}