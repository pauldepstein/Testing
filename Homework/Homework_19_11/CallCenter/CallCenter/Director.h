#ifndef DIRECTOR_H_INCLUDED
#define DIRECTOR_H_INCLUDED
#include "Employee.h"
#include <string>
#include <iostream>
#include <stdexcept>

class Director : public Employee
{
protected:
    void setFree() // Handle all remaining calls.
    {
            free = true;
    }

public:
    void handle(const std::string& message)
    {
        setFree();
        if(free)
        std::cout << std::endl << message + " director." << std::endl;
        else
            throw std::domain_error("Messages should not be left unhandled.");
    }

};



#endif // DIRECTOR_H_INCLUDED
