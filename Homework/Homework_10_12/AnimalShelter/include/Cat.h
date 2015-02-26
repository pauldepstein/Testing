#ifndef CAT_H
#define CAT_H

#include <Animal.h>

class Cat : public Animal
{
    public:
        Cat(double);
        virtual ~Cat();
        void display() const ;
        //unsigned int GetCounter() { return m_Counter; }
        //void SetCounter(unsigned int val) { m_Counter = val; }
    protected:

    private:
        //unsigned int m_Counter;
};

#endif // CAT_H
