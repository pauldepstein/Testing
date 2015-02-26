/***** Note -- could be done more simply with library operations.
and lists -- for example, list has a push_front member
****************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;
// A stack structure for elements of type T for example integers.

template <class T> class Stack_
{
protected:
    vector<T> StackedElements;

// Remove from the StackedElements and return it.
public:
    T pop()
    {
        if(StackedElements.empty())
            throw domain_error("No elements present");

        int finalIndex = StackedElements.size()-1;
        T popped = StackedElements[finalIndex];
        StackedElements.erase(StackedElements.begin()+finalIndex);
        return popped;
    }

    // Add an element
    void push(T t)
    {
       StackedElements.push_back(t);
    }

    Stack_(vector<T> elements):StackedElements(elements)
    {

    }


    void display()const
    {   cout << endl << endl;
        cout << "Displaying Stack" << endl;
        for(int i = 0; i < StackedElements.size(); i++)
            cout << "Element in position " << i << " is " << StackedElements[i] << endl;
    }

    vector<T> getElements() {return StackedElements;}

};

template <class T> class DerivedStack : public Stack_<T>
{
    T minVal;

public:
    T getMinVal(){return minVal; }
    DerivedStack(vector<T> stacked):Stack_<T>(stacked)
    {
        std::sort(stacked.begin(), stacked.end());
        //minVal is least element if any exist else the default
        minVal =  !stacked.empty()?stacked[0]:T();
    }
};

template <class T> class SetOfStacks
{
    // small stacks collected in a larger stack
    Stack_<Stack_<T> > stacks;
    int capacity; // capacity of each substack.
    vector <T> stackedElements; // Elements to be distributed among the stacks.
    void EliminateEmpty() // Eliminating final stack if empty.
    {
       if(!stacks.getElements().empty())
       {
           if(stacks.getElements()[stacks.getElements().size()-1].getElements().empty())
              stacks.getElements().pop();
       }
    }

public:
    T pop()
    {
        EliminateEmpty();

        if(stacks.getElements().empty())
            throw domain_error("No elements present");

        T popped = stacks.getElements()[stacks.getElements().size()-1].pop();
        EliminateEmpty();
        return popped;
    }

    // Add an element
    void push(T t)
    {
       if(stacks.empty() || stacks[stacks.getElements.size() -1].size() >= capacity)
       {
           // Not sure if there's an easier way to get a vector with
           // a single element -- might be more concise syntax particularly
           // with C++-11.
           vector<T> singleElement;
           singleElement.push_back(t);
           Stack_<T> newStack = Stack_<T>(singleElement);
           stacks.push(newStack);

       }
    }

    // Create all stacks in the constructor
    SetOfStacks(vector<T>allElements, int stackCapacity): stackedElements(allElements), capacity(stackCapacity)
    {

        vector<T> emptyVec;
        Stack_<T> initialStack = Stack_<T>(emptyVec);
        vector<Stack_<T> > emptySetOfStacks;
        emptySetOfStacks.push_back(initialStack);
        stacks = Stack_<Stack_<T> > (emptySetOfStacks);
        for(int i = 0; i<stackedElements.size(); i++)
            if(stacks.getElements()[stacks.getElements().size()-1].getElements().size() < capacity)
            stacks.getElements()[stacks.getElements().size()-1].push(stackedElements[i]);
            else
            {
                initialStack.push(stackedElements[i]);
                stacks.push(initialStack);
            }

    }

    void display() const
    {
        for(int i = 0; i<(stacks.getElements()).size(); i++)
        {
            cout << endl << "Displaying info on stack " << i << endl;
            stacks.getElements()[i].display();
            cout << endl;
        }
    }



};

template <class T> class Queue_
{
    vector<T> QueuedElements;

// Remove from the QueuedElements and return it.
public:
    T dequeue()
    {
        if(QueuedElements.empty())
            throw domain_error("No elements present");

        T popped = QueuedElements[0];
        QueuedElements.erase(QueuedElements.begin());
        return popped;
    }

    // Add an element to the front of the gueue.
    void queue(T t)
    {
       vector<T> queuedElements;
       queuedElements.push_back(t);

       for(int i = 0; i < QueuedElements.size(); i++)
          queuedElements.push_back(QueuedElements[i]);

        QueuedElements = queuedElements;

    }

    void display()const
    {   cout << endl << endl;

        cout << "Displaying Queue" << endl;
        for(int i = 0; i < QueuedElements.size(); i++)
            cout << "Element in position " << i << " is " << QueuedElements[i] << endl;
    }
    Queue_(vector<T> elements):QueuedElements(elements)
    {

    }

};

int main()
{
    // Create a stack and a queue
    vector<int> QueueVec;
    vector<int> StackVec;
    for(int i = 0; i < 10; i++)
        StackVec.push_back(i * 5);

    Stack_<int> stack = Stack_<int>(StackVec);
    Queue_<int> queue_ = Queue_<int>(StackVec);

    stack.display();
    queue_.display();

    // Test pop operations.
    int popped = stack.pop();
    int dequeued = queue_.dequeue();

    cout << "popped from stack = " << popped << endl;
    cout << "popped from queue = " << dequeued << endl << endl;

    stack.display();
    queue_.display();

    // Now push -100 and display again.
    const int testVal = -100;
    stack.push(testVal);
    queue_.queue(testVal);

    stack.display();
    queue_.display();

    // Add -5000 to the top of the stack
    // display and check that this is the new minimum of the derived stack.
    stack.push(-5000);
    stack.display();

    DerivedStack<int> minStack = DerivedStack<int>(stack.getElements());
    cout << endl << endl << "new minimum value should be -5000 and is " << minStack.getMinVal();

    cout << endl << "Now testing set of stacks " << endl;

    vector<int> testVec;

    for(int i = 0; i < 51; i++)
        testVec.push_back(i);

    SetOfStacks<int> testSet = SetOfStacks<int>(testVec, 5);
    testSet.display();

    // Now test popping
    popped = testSet.pop();

    cout << endl << "Popped value = " << popped;
    cout << endl;

    cout << "Now showing results of popping." << endl;
    testSet.display();


    return 0;
}
