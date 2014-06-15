#include <iostream>
#include "luaEngine.hpp"

//using namespace cppLua;

int main(void)
{
  cppLua::luaEngine l;
  l.stackDump();
  
  return 0;
}