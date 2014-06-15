/*
    cppLua: luaStackResult.hpp
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
* @file luaStackResult.hpp
* @author Kyle Givler
*/

#ifndef _LUA_STACK_RESULT_H_
#define _LUA_STACK_RESULT_H_

#include <lua.hpp>
#include <string>
#include <cassert>

#include "luaStackItem.hpp"

namespace cppLua
{
  class luaStackResult
  {
  public:
    luaStackResult(lua_State *lua, int prevStackTop) : prevStackTop(prevStackTop), numRetVal(lua_gettop(lua) - prevStackTop), lua(lua)
    {
	assert(lua);
	assert(numRetVal >= 0);
    }
    
    ~luaStackResult()
    {
      assert(lua_gettop(lua) == prevStackTop + numRetVal);
      lua_settop(lua, prevStackTop);
    }
    
    void operator=(const luaStackResult &rhs) = delete;
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /**
     * @return Number of items in result
     */
    size_t getNumItems() const { return numRetVal; }
    
    /**
     * @param index Index of items
     * @return item at given index
     */
    luaStackItem getItem(int index = 1) const;
    int getStackPos(int index) const;
    
    
  private:
    int prevStackTop;
    int numRetVal;
    lua_State *lua;
  };
}
#endif