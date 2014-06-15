#include <iostream>
#include <exception>
#include <lua.hpp>

#include "luaEngine.hpp"

using namespace cppLua;
using namespace std;

int main(void)
{
  luaEngine l;
  try {
    luaStackResult res = l.doString("print(\"HELLO\") return 1");
    cout << "number of items returned: " << res.getNumItems() << "\n"; 
    luaStackItem I = res.getItem();
    int type = I.getTypeId();
    if (type == LUA_TNUMBER)
      cout << "Number\n";
  } catch (std::exception &e)
  {
    cout << e.what();
  }
  
  lua_State *L = l.getLuaState();
  lua_pushstring(L, "fsdf");
  lua_pushnumber(L, 66);
  l.stackDump();
  
  return 0;
}