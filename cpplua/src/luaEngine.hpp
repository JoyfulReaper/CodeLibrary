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
* @file luaEngine.hpp
* @author Kyle Givler
*/

#ifndef _LUA_ENGINE_H_
#define _LUA_ENGINE_H_

#include "luaStackResult.hpp"
#include "luaExcept.hpp"
#include <lua.hpp>
#include <iostream>
#include <string>

namespace cppLua
{
  class luaEngine
  {
  public:
    luaEngine();
    ~luaEngine();
    
    void doString(std::string);
    
    template <class T> T getGlobal(T name);
    
    void stackDump();
    
  private:
    lua_State *lua;

  };

}
#endif