#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cerrno>


inline bool isInteger(const string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

   char * p;
   strtol(s.c_str(), &p, 10);

   return (*p == 0);
}

string interpret(vector<string> tokens){


}
