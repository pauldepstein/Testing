#include <iostream>
#include <vector>
#include <boost/scoped_ptr.hpp>

using namespace std;

int main()
{

    cout << "Hello world!" << endl;
   int my_array[5] = {1, 2, 3, 4, 5};
   for(int& x: my_array)
     x*=2;

   for(auto& x: my_array)
     x*=2;

    return 0;
}
