#include <iostream>
#include "greedyWrap.hpp"

int main (void)
{
  std::stringstream ss;
  std::string test = "test string";
  
  ss << "\tTEST THIS is just a test! YOU can ignore this test! THIS IS JUST A BUNCH OF SHIT NOW SO IGNORE THIS SHIT OK? ksdhfa lsdkjfh laskdjhflk asdhkjfdh bavxcvn  akdlhgakdsjhgk lsjdhflkjsdha lfkjhdsakg. hkdls j;lkfhr luesafkhdkgh lakjsdhfdkjlsgfkjasfdh gkjsda ;lklhglkjdsfh gkj;dh fsklajhgj kldgajlk dhlkjghkj hsdf;gj al;ksdjglkfdsjf la;sjdlgk hjh fslkd;ajf;lkjdgkl aj;sdlkgj ;lkdsajgl;kj kjds; falgh kkjdhsdkjgfds ggfa. This is less shitty, i just need to think of words to write to test this shitty algoritm with. This wasn't too hard to write, so I don't know why all of the implementations that I found online suck so damn hard! one more word.";
  //ss << "For the debugger!";
  
  GreedyWrap wrap;
  std::cout << wrap.lineWrap(ss);
  
  
  return 0;
}