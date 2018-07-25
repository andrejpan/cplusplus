#include <iostream>
#include <memory>

// mostly code from this tutorial
// https://www.youtube.com/watch?v=UOB7-B2MfwA
class Entity
{
public:
    Entity()
    {
        std::cout << "Created entity" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Destroyed entity" << std::endl;
    }

    void Foo()
    {

    }
};

int main() {

    {
        std::unique_ptr<Entity> entity0(new Entity());
        entity0->Foo();
        // prefered way because of exception safety
        std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();
        entity1->Foo();
        // entity pointers will be automatically destroyed here

        // unique pointers can not be copied
        //std::unique_ptr entity2 = entity0; -> error
    }

    {

        std::shared_ptr<Entity> entity2;
        {
            // share pointers count reference counting and when is 0, poiter gets deleted
            std::shared_ptr<Entity> entity0 = std::make_shared<Entity>();
            // less efficient because of two different memory allocations
            std::shared_ptr<Entity> entity1(new Entity());
            entity2 = entity0;
        }
        // entity0 and entity1 dies here
    }
    // entity 2 dies here

    {
        // this does not increase reference count
        std::weak_ptr<Entity> entity1;
        {
            std::shared_ptr<Entity> entity0 = std::make_shared<Entity>();
            entity1 = entity0;
        }
        // Entity class is already destroyed
    }

    std::cin.get();
    return 0;
}