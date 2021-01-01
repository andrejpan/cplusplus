#include <string>
#include <iostream>
#include <variant>
#include <vector>

// https://www.bfilipek.com/2018/06/variant.html

struct SampleVisitor
{
  void operator()(int i) const { std::cout << "int: " << i << "\n"; }
  void operator()(float f) const { std::cout << "float: " << f << "\n"; }
  void operator()(const std::string &s) const { std::cout << "string: " << s << "\n"; }
};

int main()
{
  std::variant<int, float, std::string> intFloatString;
  static_assert(std::variant_size_v<decltype(intFloatString)> == 3);

  // default initialized to the first alternative, should be 0
  std::visit(SampleVisitor{}, intFloatString);

  // index will show the currently used 'type'
  std::cout << "index = " << intFloatString.index() << std::endl;
  intFloatString = 100.0f;
  std::visit(SampleVisitor{}, intFloatString);
  std::cout << "index = " << intFloatString.index() << std::endl;
  intFloatString = std::string("hello super world");
  std::visit(SampleVisitor{}, intFloatString);
  std::cout << "index = " << intFloatString.index() << std::endl;

  // try with get_if and init-if
  if (const auto intPtr(std::get_if<int>(&intFloatString)); intPtr)
    std::cout << "int: " << *intPtr << "\n";
  else if (const auto floatPtr(std::get_if<float>(&intFloatString)); floatPtr)
    std::cout << "float: " << *floatPtr << "\n";
  else if (const auto stringPtr = std::get_if<std::string>(&intFloatString))
    std::cout << "string: " << *stringPtr << "\n";

  // try with holds_alternative
  if (std::holds_alternative<int>(intFloatString))
    std::cout << "the variant holds an int!\n";
  else if (std::holds_alternative<float>(intFloatString))
    std::cout << "the variant holds a float\n";
  else if (std::holds_alternative<std::string>(intFloatString))
    std::cout << "the variant holds a string\n";

  // Type Safety - the variant doesn’t allow to get a value of the type that’s not active
  try {
    auto f = std::get<float>(intFloatString);
    std::cout << "float! " << f << "\n";
  } catch (std::bad_variant_access &) {
    std::cout << "our variant doesn't hold float at this moment...\n";
  }

  // The variant class calls destructors and constructors of non-trivial types, so in the example, the string object is
  // cleaned up before we switch to new variants.
  intFloatString = 10;
  std::visit(SampleVisitor{}, intFloatString);
  intFloatString = 10.0f;
  std::visit(SampleVisitor{}, intFloatString);

  // pass a value initialization
  std::variant<int, float, std::string> intFloatString1{ 10.5f };
  std::cout << "index = " << intFloatString1.index() << ", value: " << std::get<float>(intFloatString1) << "\n";

  // in_place for complex types
  std::variant<std::vector<int>, std::string> vecStr{ std::in_place_index<0>, { 0, 1, 2, 3 } };
  std::cout << "index = " << vecStr.index() << ", vector size: " << std::get<std::vector<int>>(vecStr).size() << "\n";

  // copy-initialize from other variant:
  std::variant<int, float, std::string> intFloatString2{ intFloatString };
  std::cout << "index = " << intFloatString2.index() << ", value: " << std::get<float>(intFloatString2) << "\n";

  intFloatString.emplace<2>(std::string("Hello"));// we're now string again
  // std::get returns a reference, so you can change the value:
  std::get<std::string>(intFloatString) += std::string(" World");
  std::cout << "index = " << intFloatString.index() << ", value: " << std::get<std::string>(intFloatString) << "\n";
  intFloatString = 10.1f;
  if (auto pFloat = std::get_if<float>(&intFloatString); pFloat) *pFloat *= 2.0f;
  std::cout << "index = " << intFloatString.index() << ", value: " << std::get<float>(intFloatString) << "\n";
}
