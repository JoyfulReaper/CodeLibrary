/*
    GreedyWrap: greedyWrap.cxx
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
 * @file GreedyWrap.cxx
 * @author Kyle Givler
 * 
 * Greedy word wrapping class
 */

#include "greedyWrap.hpp"

// TODO: Probably need to strip tabs (/t) maybe others

static const size_t SPACE_WIDTH = 1;

std::string GreedyWrap::lineWrap(std::stringstream &ss)
{
  size_t lineWidth = getLineWidth();
  int spaceLeft = lineWidth;
  
  std::string output;
  std::string word;
  while(getWord(ss, word))
  {
    if( (word.length() + SPACE_WIDTH) > spaceLeft)
    {
      output += "\n";
      output += word;
      output += " ";
      spaceLeft = (lineWidth - word.length());
    } else {
      spaceLeft -= (word.length() + SPACE_WIDTH);
      output += word;
      output += " ";
    }
  }
  
  return output;
}

std::string GreedyWrap::lineWrap(std::string string)
{
  std::stringstream ss;
  ss.str(string);
  return lineWrap(ss);
}

bool GreedyWrap::getWord(std::stringstream &ss, std::string &outWord) const
{
  std::string word = "";
  while( ss.good() )
  {
    char letter;
    letter = ss.get();
    
    if (letter == ' ' || !ss.good())
    {
      outWord = word;
      return true;
    }
    
    word += letter;
  }
  return false;
}