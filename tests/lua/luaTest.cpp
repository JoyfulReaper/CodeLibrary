#include <iostream>
#include <cstdlib>
#include <lua.hpp>

int testFunction(lua_State *l);

int main()
{
  std::cout << "Lua Test Program\n";
  
  // Test running a simple lua script
  std::cout << "Running hello.lua: \n\n";
  lua_State *L = luaL_newstate();
  if(L == NULL)
  {
    std::cout << "Failed to allocate memory\n";
    exit(EXIT_FAILURE);
  }
  
  luaL_openlibs(L);
  if (luaL_dofile(L, "hello.lua"))
  {
    std::cout << "Error running script\n";
    exit(EXIT_FAILURE);
  }
  lua_close(L);
  
  ///////////////////////////////////////////////////////////
  
  // Test calling a C++ function from Lua
  std::cout << "\nTesting calling C++ function from Lua:\n\n";
  L = luaL_newstate();
  if(L == NULL)
  {
    std::cout << "Failed to allocate memory\n";
    exit(EXIT_FAILURE);
  }
  luaL_openlibs(L);
  
  lua_pushcfunction(L, testFunction);
  lua_setglobal(L, "testFunction");
  
  int status = luaL_loadfile(L, "call_c_func.lua");
  if(status != LUA_OK)
  {
    std::cout << "status != LUA_OK\n";
    lua_close(L);
    exit(EXIT_FAILURE);
  }
  
  int result = lua_pcall(L, 0, LUA_MULTRET, 0);
  
  lua_close(L);
  return 0;
}

int testFunction(lua_State *l)
{
  int argc = lua_gettop(l); // Number of arguments
  
  // print input arguments
  std::cout << "Input arguments: " << argc << std::endl;
  
  for(int i=0; i<argc; i++)
  {
      std::cout << "input argument #" << argc-i << ": "
                << lua_tostring(l, lua_gettop(l)) << std::endl;
      lua_pop(l, 1);
  }

  lua_pushnumber(l, 12);
  
  return 1;
}