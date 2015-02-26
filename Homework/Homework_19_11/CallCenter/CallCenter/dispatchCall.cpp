/*#include "Respondent.h"
#include "Manager.h"
#include "Director.h"*/
#include "Call.h"
#include "Employee.h"
#include <string>

using namespace std;

void dispatchCall()
{
   Employee employee(0);
   //Create a class for the call and specify who should be able to accept it based on rank of message
   const string message = "\nHandling message\n";

   // class for call propagated through the linked list
   // call class.  Have rank as a member variable.
   employee.handle(message);
   /*Respondent respondent;
   Manager manager;
   Director director;

   respondent.add(&manager);
   manager.add(&director);
   respondent.handle(message);*/
}
