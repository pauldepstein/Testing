#ifndef ANIMALDATA_H_INCLUDED
#define ANIMALDATA_H_INCLUDED

// A class containing data for animals.
#include "Animal.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

class AnimalData{

public:

AnimalData() {CreateData();}
void display(int) const;
void display() const;

void push(Animal* animal)
{
    Animals.push_back(animal);
    AnimalSort();
}

Animal popAny()
{
   Animal oldest = *Animals[Animals.size()-1];
   Animals.erase(Animals.begin() + Animals.size()-1);

   return oldest;
}

Animal popCat()
{
    for (std::vector<Animal*>::iterator i = --Animals.end(); i > Animals.begin(); i--)
        if(((*i)->stringID == "cat") || ((*--i)->stringID == "cat"))
               {
                   Animal oldest = **i;
                   Animals.erase(i);
                   return oldest;
               }

        throw std::domain_error("No cat remains");
}

Animal popDog()
{
    for (std::vector<Animal*>::iterator i = --Animals.end(); i > Animals.begin(); i--)
        if(((*i)->stringID == "dog") || ((*--i)->stringID == "dog"))
               {
                   Animal oldest = **i;
                   Animals.erase(i);
                   return oldest;
               }

        throw std::domain_error("No dog remains");
}


~AnimalData()
{
    Animals.erase(remove_if(Animals.begin(), Animals.end(), deleted));
}

private:
void CreateData();
std::vector<Animal*> Animals;

void AnimalSort()
{
    std::sort(Animals.begin(), Animals.end(), compare);
}


// Comparing on age
static bool compare(const Animal* animal1, const Animal* animal2)
{
   return animal1->GetAge() < animal2->GetAge();
}

static bool deleted(Animal* animal)
    {
        delete animal;
        return true;
    }

};

#endif // ANIMALDATA_H_INCLUDED
