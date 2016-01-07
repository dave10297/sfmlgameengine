#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <tuple>
#include <list>

#include "helperfunctions.h"

class ScreenOutput
{
public:
  ScreenOutput(std::string TextFontFileName, sf::RenderWindow* WindowRef);
  ~ScreenOutput();
  void Write(std::string OutputData);
  void Clear();
  void Draw();

  void SetScreenCursorPosition(sf::Vector2f NewScreenCursorPosition);
  void SetOutputFontSizePixels(const unsigned int NewOutputFontSizePixels);
  void SetOutputLineHeightPadding(const float NewOutputLineHeightPadding);
  sf::Vector2f GetScreenCursorPosition() const;
  unsigned int GetOutputFontSizePixels() const;
  float GetLineHeightPadding() const;

private:
  std::string OutputFontFileName;
  sf::Text OutputTextObject;
  sf::Font TextFontObject;
  std::list<std::string> OutputContentList;
  sf::RenderWindow* WindowObjectRef;

  sf::Vector2f ScreenCursorPosition;
  unsigned int OutputFontSizePixels;
  float OutputLineHeightPadding;
};
