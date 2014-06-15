#include "luaStackResult.hpp"
#include "luaExcept.hpp"

namespace cppLua
{
  int luaStackResult::getStackPos(int index) const
  {
    int x = 0;
    if (index > 0 && index <= numRetVal)
    {
      return x ? prevStackTop + 1 : prevStackTop + index;
    }
    
    if(index < 0 && index >= -numRetVal)
    {
      return x ? prevStackTop + 1 : prevStackTop + numRetVal + 1 + index;
    }
    return x;
  }
}