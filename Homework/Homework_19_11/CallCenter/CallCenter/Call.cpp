/*#include "Respondent.h"
#include "Manager.h"
#include "Director.h"*/
#include "Call.h"
#include "Employee.h"
#include <string>

using namespace std;

void Call::dispatchCall() const
{

   // Start with a member of the appropriate rank to ensure that
   // message is handled by employee of correct seniority.
   // A call of rank n can be handled by an employee of rank n, n+1 etc.

   Employee employee(_priority);
   //Create a class for the call and specify who should be able to accept it based on rank of message


   // class for call propagated through the linked list
   // call class.  Have rank as a member variable.
   employee.handle(_message);

}
