#include <array>
#include <iostream>
#include <memory>

// https://www.youtube.com/watch?v=UOB7-B2MfwA
// https://www.internalpointers.com/post/beginner-s-look-smart-pointers-modern-c

// When a smart pointer goes out of scope, its destructor gets triggered and the memory cleanup is
// performed. This technique is called Resource Acquisition Is Initialization (RAII):
class Entity {
 public:
  Entity() { std::cout << "Entity created." << std::endl; }
  ~Entity() { std::cout << "Entity was destroyed." << std::endl; }

  void Foo() { std::cout << "Foo was called." << std::endl; }

  // Unique pointer needs to be passed as reference.
  void Bar(const std::unique_ptr<int[]>& p) {
    std::cout << "Bar was called." << std::endl;
    std::cout << "p[0]:" << p[0] << std::endl;
  }
};

struct Player0 {
  std::shared_ptr<Player0> companion;
  ~Player0() { std::cout << "~Player0()\n"; }
};

struct Player1 {
  std::weak_ptr<Player1> companion;
  ~Player1() { std::cout << "~Player1()\n"; }
};

int main() {
  // A std::unique_ptr owns of the object it points to and no other smart pointers can point to it.
  {
    // basic usage, not exception safe
    std::unique_ptr<Entity> entity0(new Entity());
    entity0->Foo();

    // preferred way because of exception safety
    std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
    entity1->Foo();

    // unique pointers can not be copied
    // std::unique_ptr entity2 = entity0; //error

    std::unique_ptr<int> p1 = std::make_unique<int>();
    std::unique_ptr<int[]> p2 = std::make_unique<int[]>(50);
    p2[0] = 25;
    entity1->Bar(p2);
  }
  // entity pointers will be automatically destroyed here

  {
    std::shared_ptr<Entity> entity2;
    {
      // share pointers count reference counting and when is 0, poiter gets deleted
      std::shared_ptr<Entity> entity0 = std::make_shared<Entity>();
      // less efficient because of two different memory allocations
      std::shared_ptr<Entity> entity1(new Entity());
      entity2 = entity0;
    }
    // entity0 and entity1 are destroyed here

    std::shared_ptr<std::array<int, 10>> p1(new std::array<int, 10>());
    std::shared_ptr<std::array<int, 2>> p2(new std::array<int, 2>{{5, 4}});

    std::shared_ptr<int> ptr = std::make_shared<int>(100);
    // ptr.use_count() == 1
    std::shared_ptr<int> ptr_copy = ptr;  // Make a copy: with shared_ptr we can!
    // ptr.use_count() == 2
    // ptr_copy.use_count() == 2, it's the same underlying data after all
  }  // `ptr` and `ptr_copy` go out of scope here. No more references to the
  // original data (i.e. use_count() == 0), so it is automatically cleaned up.

  // entity 2 also dies here

  {
    // You can only create a std::weak_ptr out of a std::shared_ptr or another std::weak_ptr.
    std::weak_ptr<Entity> entity1;
    {
      std::shared_ptr<Entity> entity0 = std::make_shared<Entity>();
      entity1 = entity0;
    }
    // Entity class is destroyed

    std::weak_ptr<int> p_weak1;
    {
      std::shared_ptr<int> p_shared = std::make_shared<int>(100);
      p_weak1 = p_shared;
      std::weak_ptr<int> p_weak2(p_weak1);
    }
    if (p_weak1.expired())
      std::cout << "Shared already expired." << std::endl;
    else
      std::cout << "Shared pointer is still active." << std::endl;
  }

  // circular reference with share pointers
  {
    std::shared_ptr<Player0> jasmine = std::make_shared<Player0>();
    std::shared_ptr<Player0> albert = std::make_shared<Player0>();

    jasmine->companion = albert;  // (1)
    albert->companion = jasmine;  // (2)
    // memory leak, destructor is no called
  }

  // breaking the circular reference with weak_pointer
  {
    // circular reference with share pointers
    std::shared_ptr<Player1> jasmine = std::make_shared<Player1>();
    std::shared_ptr<Player1> albert = std::make_shared<Player1>();

    jasmine->companion = albert;  // (1)
    albert->companion = jasmine;  // (2)
    // memory leak, destructor is no called
  }
  return 0;
}
