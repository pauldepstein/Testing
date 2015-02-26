#ifndef CALL_H_INCLUDED
#define CALL_H_INCLUDED
#include <string>
// File to represent a call which can only be handled by people of a certain rank (priority).
class Call
{
    public:
    Call(int priority, std::string message = "\nHandling Message\n")
    {
        _priority = priority;
        _message = message;
    }

    void dispatchCall() const;
    int getPriority() const {return _priority;}
    std::string getMessage() const {return _message;}

    private:
    int _priority;
    std::string _message;

};

#endif // CALL_H_INCLUDED
