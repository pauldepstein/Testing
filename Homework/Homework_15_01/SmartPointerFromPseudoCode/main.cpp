#include <iostream>

using namespace std;

template <class T> class SmartPointer{
/* Smart pointer class needs pointer to object and reference count.  These may be pointers,
rather than the actual object or reference count value, since the goal of a smart pointer is
that the reference count is tracked across multiple smart pointers to one object */

public:
T* obj;
unsigned ref_count;

SmartPointer(T val)
// Set the value of T* obj here, and set the reference counter to 1
{
    obj = new T(val);
    ref_count = 1;
}

SmartPointer(SmartPointer<T> &smrtPtr){
	/*Create a new smart pointer that points to an existing object. Need to set obj and reference count
	to pointer to smrtPtr's obj and reference count. Then, because we created a new reference to obj, increment reference count*/
	obj = smrtPtr.obj;
	ref_count = ++smrtPtr.ref_count;
}

/*Destroy a reference to the object. Decrement reference count. If reference count is 0, then free the memory created
	by the integer and destroy the object*/
~SmartPointer(){
    if(--ref_count == 0)
    {
        if(obj)
           delete *obj;

        delete obj;
    }



    }

SmartPointer<T>& operator = (SmartPointer<T>& smrtPtr)
/* Overload equal operator, so that when you set one smart pointer equal to another
the old smart pointer has its reference counter decremented and the new smart pointer
has its reference count incremented */
{
    if(this != &smrtPtr)
    {
        if(--ref_count == 0)
        {
            if(obj)
              delete *obj;

            delete obj;

            smrtPtr.ref_count ++;
        }

    }
}


};

int main()
{
    // Testing code should be written here.
    return 0;
}
