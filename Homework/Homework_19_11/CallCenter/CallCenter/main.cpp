#include <iostream>
#include "Call.h"

using namespace std;

// Implementing dispatchCall // Should only be handled by employees of rank > 5.
int main()
{
    for(int i = 5; i < 50; i++)
        { // Results as expected.  50% of the time Call(i) is handled by
          // someone of rank i.
            Call call = Call(i);
            call.dispatchCall();
        }

        int x;

        cin >> x;
}
