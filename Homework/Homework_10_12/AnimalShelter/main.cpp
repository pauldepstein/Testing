#include <iostream>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "AnimalData.h"

using namespace std;

int main()
{
    AnimalData animals;
    animals.push(new Cat(10000));
    animals.display();
    animals.push(new Dog(-2));
    animals.display();
    //animals.display(5);
    animals.popAny();//->display();
    //animals.popAny();
    cout << endl;
    animals.display();
    animals.display(50000);
    animals.popAny();
    animals.display(100);
    animals.popDog();
    animals.display(100);
    animals.popCat();
    animals.display(100);
    animals.popCat();
    animals.popCat();
    animals.popCat();
    animals.display(100);
    return 0;
}
