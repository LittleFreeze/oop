
#include "json.hpp"

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

int
main(int argc, char* argv[])
{
  std::ifstream filein ("test2.txt");
  std::cout << "Enter Input" << std::endl;
  std::istreambuf_iterator<char> first(filein);
  std::istreambuf_iterator<char> last;
  std::string s(first, last);

  std::list <json::Value*> mylist;
  std::cout << "Parsing" << std::endl;
  json::Value* val = json::parse(s,&mylist);
  std::cout << "Parsing Complete" << std::endl;

  // std::cout << size(val) << ' ' << height(val) << '\n';
  //std::cout << *val << '\n';

}
