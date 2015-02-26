#include <iostream> 
#include <cstring> 
#include <boost/shared_array.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

template <typename T>
boost::ptr_vector<T> create(T t)
{
  boost::ptr_vector<T> v; 
  v.push_back(new T(t));  

  return v;
}

template <typename T>
void display(boost::ptr_vector<T>& v)
{
	std::cout << std::endl;

	for(int i = 0; i < v.size(); i++)
		if(v[i])
			std::cout << *(v[i]);

	std::cout << std::endl;
}

boost::shared_array<char> get(const char *s) 
{ 
  int size = std::strlen(s); 
  boost::shared_array<char> text(new char[size+1]); 
  for(int i = 0; i < size; i++)
	  text[i] = s[i];

  // null character
  text[size] = '\0';

  return text; 
} 


void print(boost::shared_array<char>text) 
{
   int i = 0;
   if(text)
	  while(text[i])
		  std::cout<<text[i++];

   std::cout<<std::endl;
	   
}


int main(int argc, char *argv[]) 
{ 
  if (argc < 2) 
  { 
    std::cerr << argv[0] << " <data>" << std::endl; 

    return 1; 
  } 

  auto text = get(argv[1]); 
  print(text); 

  // Below needed to pause screen.
  // Also feed result into second exercise.
  int x;
  std::cin >> x;

  auto vec = create<int>(x);
  display<int> (vec);

 // display<int>(create<int>(x));

  
  return 0;
} 

