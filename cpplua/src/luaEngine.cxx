/*
    cppLua: luaEngine.hpp
    Copyright (C) 2014 Kyle Givler

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program. If not, see <http://www.gnu.org/licenses/>.

*/

/**
* @file luaEngine.cxx
* @author Kyle Givler
*/

#include "luaEngine.hpp"

namespace cppLua
{
  luaEngine::luaEngine() : lua(luaL_newstate())
  {
   if(lua == NULL)
    throw luaExcept("Unable to allocate memory");
    
   luaL_openlibs(lua);
  }

  luaEngine::~luaEngine()
  {
    lua_close(lua);
  }
  
  luaStackResult luaEngine::doString(std::string script)
  {
    int stackTop = lua_gettop(lua);
    assert(lua_checkstack(lua, 1));
    const int err = luaL_loadstring(lua, script.c_str());
    if (err != LUA_OK)
      throw luaExcept("Syntax error in script");
    
    const int errCall = lua_pcall(lua, 0, LUA_MULTRET, 0);
    if (errCall != LUA_OK)
    {
      throw luaExcept(lua_tostring(lua, -1));
      // FIXME: should we pop here?
    }
    
    return luaStackResult(lua, stackTop);
  }
  
  void luaEngine::stackDump()
  {
    size_t top = lua_gettop(lua); //index of top of stack
    for(size_t i = 1; i <= top; i++)
    {
      int type = lua_type(lua, i);
      switch (type)
      {
        case LUA_TSTRING:
        {
          std::cout << lua_tostring(lua, i) << std::endl;
          break;
        }
        case LUA_TBOOLEAN:
        {
          std::cout << (lua_toboolean(lua, i) ? "true" : "false") << std::endl;
          break;
        }
        case LUA_TNUMBER: 
        {
          std::cout << lua_tonumber(lua, i) << std::endl;
          break;
        }
        default:
        {
          std::cout << lua_typename(lua, i) << std::endl;
        }
      }
    }
  }
  
  
  
}