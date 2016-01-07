#include "helperfunctions.h"

unsigned int HelperFunctions::PointsToPixels(const unsigned int Points)
{
  return (Points * 1.33);
}
std::tuple<bool, int> HelperFunctions::SearchString(std::string SearchString, char SearchCharacter)
{
  int CharacterOccurances = 0;
  bool CharacterFound = false;
  for (int StringIterator = 0; StringIterator < SearchString.length(); ++StringIterator)
  {
    if (SearchString[StringIterator] == SearchCharacter)
    {
      CharacterFound = true;
      CharacterOccurances++;
    }
  }

  return (std::make_tuple(CharacterFound, CharacterOccurances));
}
std::list<std::string> HelperFunctions::SplitString(std::string InitialString, char SplitPoint)
{
  std::list<std::string> StringList;
  std::string NewString = "";

  for (int StringIterator = 0; StringIterator < InitialString.length(); StringIterator++)
  {
    if (InitialString[StringIterator] == SplitPoint)
    {
      StringList.push_back(NewString);
      NewString = "";
      continue;
    }

    NewString += InitialString[StringIterator];
  }

  if (NewString != "")
    StringList.push_back(NewString);

  /*#ifdef SFML_GAMEDEV_DEBUG
    std::cout << "Returning Vector: " << std::endl;
    std::vector<std::string>::size_type VectorIterator;
    for (VectorIterator = 0; VectorIterator != StringVector.size(); VectorIterator++)
      std::cout << StringVector[VectorIterator] << std::endl;
  #endif*/
  return (StringList);
}
