#include <exception>
#include <iostream>
#include <string>


class luaExcept: public exception
{
private:
  std::string msg;
public:
  luaExcept(std::string input) : msg(input) {}
  const char* what() 
  {
    msg = "LuaException: " + msg;
    return msg.c_str();
  }
};