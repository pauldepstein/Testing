#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
// Base class for all employees.
#include <string>
#include <stdexcept>
#include <iostream>
#include <cstdlib>

class Employee
{
    Employee* next;
    int id; // Identifying the nature of the employee.

    protected:
    bool free; // true if employee is free to handle the call.

public:
    Employee() : free(true)
    {
        next = 0;
    }

    // Total number of employees = 50.
    static const int NUM_EMPLOYEES = 50;

    Employee(int Index) : id(Index), free(true)
    {
        if(Index >= NUM_EMPLOYEES)
            throw std::domain_error("Not enough employees.");

        if(id < NUM_EMPLOYEES - 1)
        {
            next = new Employee(id+1);
            next -> id = id + 1;
        }

        else
            next = 0;
    }

    /*void setNext(Employee* employee)
    {
        next = employee;
    }*/

    /*void add(Employee* employee) // Recursive method.
    {
        if(next)
           next -> add(employee);
        else
            next = employee;
    }*/

    // Delegating to the next employee
    virtual void handle(const std::string& message)
    {
        setFree();
        if(free)
        {
            std::cout << "Employee " << id << std::endl;
            std::cout << message << std::endl;
        }
        else
            next->handle(message);
    }

    virtual ~Employee()
    {
        delete next;
    }


protected:
    // Determining if employee is available.
    // Must be available if no other employees are in the queue
    virtual void setFree()
    {
        if ( !next)
        {
            free = true;
        }
    }



};


#endif // EMPLOYEE_H_INCLUDED
