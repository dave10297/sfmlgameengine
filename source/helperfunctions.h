#pragma once

#include <string>
#include <iostream>
#include <tuple>
#include <list>

namespace HelperFunctions
{
  // Converts screen sizes from points to pixels
  unsigned int PointsToPixels(const unsigned int Points);
  // Searches a string for a specific character and the occurances of that character found
  std::tuple<bool, int> SearchString(std::string SearchString, char SearchCharacter);
  std::list<std::string> SplitString(std::string InitialString, char SplitPoint);
}
