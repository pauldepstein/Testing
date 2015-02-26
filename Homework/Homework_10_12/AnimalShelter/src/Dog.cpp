#include "Dog.h"
#include <iostream>

using namespace std;

Dog::Dog(double age):Animal(age)
{
   stringID = "dog";
}

void Dog::display() const
{
    cout << "I am a dog of age : " << m_Age;
}

Dog::~Dog()
{
    //dtor
}
