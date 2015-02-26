// File for string handling operations
#include "stringHandling.h"
#include <sstream>
#include <algorithm>
#include <cctype>
#include <string>
using std::string;
using std::stringstream;

string removeSpaces(string& str)
{
  str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
  return str;
}

// Although there are library functions to translate int to strings,
// they don't appear to be completely standard.

string intToString(int n)
{
    stringstream convert;
    convert << n;
    string s = convert.str();
    return(convert.str());
}
