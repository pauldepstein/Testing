#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED
#include "Employee.h"
#include <string>
#include <iostream>
#include <cstdlib>
class Manager : public Employee
{
protected:
    void setFree() // Handle 2/3 of remaining calls.
    {
        if(rand() % 3)
            free = true;
    }

public:
    void handle(const std::string& message)
    {
        setFree();
        if(free)
        std::cout << std::endl << message + " handled by manager." << std::endl;
        else
        Employee::handle(message);
    }

};


#endif // MANAGER_H_INCLUDED
