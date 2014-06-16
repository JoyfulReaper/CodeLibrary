/*
 c p*pLua: luaStackItem.hpp
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
 * @file luaStackItem.hpp
 * @author Kyle Givler
 */

#ifndef _LUA_STACK_ITEM_H_
#define _LUA_STACK_ITEM_H_

#include <lua.hpp>
#include <string>
#include <cassert>
#include <typeinfo>

namespace cppLua
{
  class luaStackItem
  {
  public:
    luaStackItem(lua_State *lua, int stackPos) : lua(lua), stackPos(stackPos)
    {
      assert(lua);
    }
    
    int getTypeId() const {return lua_type(lua, stackPos);}
    bool isNil() const {return lua_isnil(lua, stackPos);}
    
    template <typename T>
    T getAs()
    {
      if(typeid(T) == typeid(int))
      {
	return lua_tonumber(lua, stackPos);
      }
    }
    
  private:
    lua_State *lua;
    int stackPos;
  };
}

#endif