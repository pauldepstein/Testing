#ifndef RESPONDENT_H_INCLUDED
#define RESPONDENT_H_INCLUDED
#include "Employee.h"
#include <string>
#include <iostream>
#include <cstdlib>
class Respondent : public Employee
{
protected:
    void setFree() // Handle 50% of calls.
    {
        if(rand() % 2)
            free = true;
    }

public:
    void handle(const std::string& message)
    {
        setFree();
        if(free)
        std::cout << std::endl << message + " handled by respondent." << std::endl;
        else
          Employee::handle(message); // pass along chain of command.
    }

};


#endif // RESPONDENT_H_INCLUDED
