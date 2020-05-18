#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

bool comparison(string x, string y)
{
  return stoi(x + y) > stoi(y + x);
}

string largest_number(vector<string> a)
{
  std::stringstream ret;

  while (!a.empty())
  {
    string max_Dig = "0";
    int max_Pos = 0;

    for (size_t i = 0; i < a.size(); i++)
    {
      if (comparison(a.at(i), max_Dig))
      {
        max_Dig = a.at(i);
        max_Pos = i;
      }
    }
    ret << max_Dig;
    a.erase(a.begin() + max_Pos);
  }

  string result;
  ret >> result;
  return result;
}

int main()
{
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
