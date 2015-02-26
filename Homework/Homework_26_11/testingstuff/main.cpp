/* A program to test various sorting method as follows:
 1) The std::sort already-implemented version.
 2) Bubble sort.
 3) Insertion sort.
 4) Merge sort.
 5) Quick sort.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <memory>

using namespace std;

vector<int> CreateVector(int length)
// Create a random vector of a specified length.

{
    vector<int> vec;
    for(int i = 0; i < length; i++)
        vec.push_back(rand());

}

class SortTechniques{

public:
// Displays and times if it is the inital sort.
// Otherwise, just sorts.
SortTechniques(vector<int> vec, string sortName, bool initial = false):m_vec(vec), m_sortName(sortName), m_initial(initial)
{
    initial ? display(TimeSort()):Sort();
}

vector<int> getVec()
{
    return m_vec;
}

virtual void Sort() = 0;

// Sort functions have a vector<int>& as input and void output
// This is a function to time such sort functions.
// Also check that the sort has been done correctly.
// Returns sort time in milliseconds

double TimeSort( )
{
    clock_t beginTime = clock();
    Sort();
    clock_t endTime = clock();
    cout << endl << " The length of the vec is " << m_vec.size() << endl;
    CheckSorted();
    return  ((double)(endTime - beginTime))/(CLOCKS_PER_SEC/1000);
}

void display(double milliseconds)
{
    cout << endl << "The time taken for the " << m_sortName << " sort is " << milliseconds << " milliseconds." << endl;
}

virtual ~SortTechniques()
{

}

protected:
vector<int> m_vec;
string m_sortName;
bool m_initial;

bool CheckSorted()
{
   cout << endl << "checkLength"<< m_vec.size() << endl;
   for(int i = 1; i < m_vec.size(); i++)
       if(m_vec[i] < m_vec[i-1])
       {
           cout << endl << "Error -- vector not sorted!" << endl;
           return false;
       }

   return true;

}

};

class StandardSort : public SortTechniques
{
public:
    StandardSort(vector<int> vec, bool initial = false):SortTechniques(vec, "library", initial)
    {

    }

    void Sort()
    {
        sort(m_vec.begin(), m_vec.end());
    }

};

class InsertionSort : public SortTechniques{

public:
    InsertionSort(vector<int> vec, bool initial = false):SortTechniques(vec, "insertion", initial)
    {

    }
// Insertion Sort
// Swap until we get the smallest element, then
// swap until we get the second smallest etc.
    void Sort()
    {
        const int vecSize = m_vec.size();
        int tmp;

        for(int i = 0; i < vecSize; i++)
        {
            for(int j = i + 1; j < vecSize; j++)
               if(m_vec[i] > m_vec[j])
               {
                  // Swap elements in wrong order
                  tmp = m_vec[j];
                  m_vec[j] = m_vec[i];
                  m_vec[i] = tmp;

              }
         }
    }

};

class BubbleSort : public SortTechniques{

public:
BubbleSort(vector<int> vec, bool initial = false):SortTechniques(vec, "bubble", initial)
    {

    }
// This is the most natural way to sort if we were sorting by
// hand.  Keep swapping consecutive pairs.
// If we've gone through the list with no swaps then the list must
// be already sorted.

    void Sort()
    {
        if(m_vec.empty())
        return;
        const int vecSize = m_vec.size();
        int tmp;

       int i = 0;
       bool swapDone = false; // swap has been performed if true

   while(1)
   {
       int tmp;

       if( i == vecSize - 1)
       {
            if(!swapDone) // Reaching end of vec without doing swap means already sorted.
               return;

            i = 0; // else restart from the beginning
            swapDone = false;
       }

       if(m_vec[i] > m_vec[i+1]) // Swap needed
       {
              tmp = m_vec[i];
              m_vec[i] = m_vec[i+1];
              m_vec[i+1] = tmp;
              swapDone = true;
       }
       i++;
      }
    }

};

class MergeSort : public SortTechniques{

public:
MergeSort(vector<int> vec, bool initial = false):SortTechniques(vec, "merge", initial)
    {

    }


    void Sort()
    {
        const int vecSize = m_vec.size();
        const int mid = vecSize/2;

        if(vecSize <= 1)
        return;

    // Recursion in general case
    // Partition the vector into two vectors half the size
    vector<int> lowerHalf;
    copy(m_vec.begin(), m_vec.begin() + mid, back_inserter(lowerHalf));

    m_vec.erase(m_vec.begin(), m_vec.begin() + mid);

    // Now call MergeSort recursively
    MergeSort lower = MergeSort(lowerHalf);

    // Merge the two halves of the original vector.
    m_vec = Merge(lowerHalf, m_vec);
    }

private:
// Merging two already sorted vectors
vector<int> Merge(vector<int>& v, vector<int>& w)
{
    vector <int> results;
    const int vSize = v.size();
    const int wSize = w.size();

    int i = 0;
    int j = 0;

    while(i < vSize && j < wSize)
        if(v[i] < w[j])
             results.push_back(v[i++]);

        else
            results.push_back(w[j++]);



    while(i < vSize) // This means the elements of the second vector are all in place.
            results.push_back(v[i++]);

    while(j < wSize) // Likewise the first vector elements are in place
        results.push_back(w[j++]);

    return results;

}

};

class QuickSort : public SortTechniques{

public:
QuickSort(vector<int> vec, bool initial = false):SortTechniques(vec, "quick", initial)
    {

    }

    void Sort()
    {
        const int vecSize = m_vec.size();
        if(vecSize <= 1)
        return;

    // Partition into two smaller vectors around a pivot.
    int pivot = m_vec[0];

    int index = Partition(pivot);

    vector<int> upperHalf;
    for(int i = index; i < m_vec.size(); i++)
        upperHalf.push_back(m_vec[i]);

    m_vec.erase(m_vec.begin()+index, m_vec.end());

    // Now recursively quicksort the two smaller vectors and concatenate
    QuickSort upper = QuickSort(upperHalf);
    QuickSort lower = QuickSort(m_vec);

    copy(upperHalf.begin(), upperHalf.end(), back_inserter(m_vec));
    }

private:
// Finding the index such that everything left of the index is less
// than or equal to the pivot and everything to the right of the index is greater
// than or equal to the pivot.
int Partition(int pivot)
{
    if (m_vec.empty())
        return -1;

    const int vecSize = m_vec.size();

    int i = 0;
    int j = vecSize - 1;

    while(1)
    {
       while(i < vecSize && m_vec[i] < pivot)
          i++;

       while (j >= 0 && m_vec[j] >= pivot)
          j--;

       // Return i but take care with endpoint cases.
          if(i >= j)
          {
              if(i == 0)
                 return 1;

              if(i == vecSize)
                  return vecSize - 1;

              return i;
          }

        // swap the i and j components otherwise while incrementing and
        // decrementing iterators.
        int tmp = m_vec[i];
        m_vec[i] = m_vec[j];
        m_vec[j] = tmp;

    }
}


};


int main()
{
    // Sort through ten thousand random positive integers.
    const int sortLength = 10000;
    // create vector
    vector<int> vec = CreateVector(sortLength);

    // Create one copy for use on each sort.
    vector<int> libraryCopy = vec;
    vector<int> bubbleCopy = vec;
    vector<int> insertionCopy = vec;
    vector<int> mergeCopy = vec;
    vector<int> quickCopy = vec;

    // Display sort results
    shared_ptr<SortTechniques> library = make_shared<StandardSort>(libraryCopy, true);
    StandardSort standard = *library;

    shared_ptr<SortTechniques> bubble = make_shared<BubbleSort>(bubbleCopy, true);
    BubbleSort bub = *bubble;

    shared_ptr<SortTechniques> insertion = make_shared<InsertionSort>(insertionCopy, true);
    InsertionSort ins = *insertion;

    shared_ptr<SortTechniques> merging = make_shared<MergeSort>(mergeCopy, true);
    MergeSort merg = *merging;

    shared_ptr<SortTechniques> quicksort = make_shared<QuickSort>(quickCopy, true);
    QuickSort quick = *quicksort;

    return 0;
}
