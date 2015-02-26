#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

// Base class for displaying cats and dogs.
class Animal
{
    public:
        Animal();
        Animal(double);
        virtual ~Animal();
       // unsigned int GetCounter() { return m_Counter; }
        //void SetCounter(unsigned int val) { m_Counter = val; }
        void SetAge (double age) {m_Age = age;}
        double GetAge()const{return m_Age;}
        std::string stringID; // Identifier of animal type -- for example dog or cat
        virtual void display() const {std::cout << "Either cat or dog.";}
    protected:
        double m_Age; // age of animal

    private:
        //unsigned int m_Counter;

};

#endif // ANIMAL_H
