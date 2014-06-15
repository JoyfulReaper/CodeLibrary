#ifndef _LUA_EXCEPT_H_
#define _LUA_EXCEPT_H_

#include <exception>
#include <iostream>
#include <string>

class luaExcept : public std::exception
{
public:
  luaExcept(std::string error)
  {
    msg = error;
  }
  
  const char* what()
  {
    msg = "LuaExcept: " + msg;
    return (msg.c_str());
  }
private:
  std::string msg;
};

#endif