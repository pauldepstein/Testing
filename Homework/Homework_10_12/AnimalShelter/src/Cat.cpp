#include "Cat.h"
#include <iostream>
#include <string>

using namespace std;

Cat::Cat(double age):Animal(age)
{
   stringID = "cat";
}


void Cat::display()const
{
    cout << "I am a cat of age : " << m_Age;
}


Cat::~Cat()
{
    //dtor
}
