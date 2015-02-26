#include "Animal.h"
#include "AnimalData.h"
#include "Dog.h"
#include "Cat.h"
#include <iostream>
#include <vector>

using namespace std;

void AnimalData::CreateData()
{
    // Create dogs and cats in alternating order.
    const int numData = 100;
    for(int i = 0; i < numData; i++)
      {Animal* animal;

        if(i%2 == 0)
            animal = new Dog(i);

        else
            animal = new Cat(i);

        Animals.push_back(animal);
      }

}

// Displaying the first n entries if available
void AnimalData::display(int n)const
{
   int numDisplay = n;
   if(numDisplay > Animals.size())
        numDisplay = Animals.size();

   vector<Animal*>::const_iterator i = Animals.begin();
   int count = 0;

   while(count < numDisplay)
   {
       cout << endl;
       (*i++)->display();
       count++;
   }
}

// Displaying only the last animal
void AnimalData::display()const
{
    Animals[Animals.size()-1]->display();
}


