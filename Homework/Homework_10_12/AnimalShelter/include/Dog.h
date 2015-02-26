#ifndef DOG_H
#define DOG_H

#include <Animal.h>


class Dog : public Animal
{
    public:
        Dog(double);
        virtual ~Dog();
        void display() const ;
        //unsigned int GetCounter() { return m_Counter; }
        //void SetCounter(unsigned int val) { m_Counter = val; }
    protected:

    private:
        //unsigned int m_Counter;
};

#endif // DOG_H
