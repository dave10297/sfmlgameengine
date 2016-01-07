#include "screenoutput.h"

ScreenOutput::ScreenOutput(std::string TextFontFileName, sf::RenderWindow* WindowRef)
{
  ScreenCursorPosition = sf::Vector2f(0.0f, 0.0f);
  OutputFontSizePixels = HelperFunctions::PointsToPixels(20);
  OutputLineHeightPadding = 2.0f;

  TextFontObject.loadFromFile(TextFontFileName);
  OutputTextObject.setColor(sf::Color::White);
  OutputTextObject.setFont(TextFontObject);
  OutputTextObject.setPosition(ScreenCursorPosition);
  OutputTextObject.setCharacterSize(OutputFontSizePixels);

  WindowObjectRef = WindowRef;
}
ScreenOutput::~ScreenOutput()
{
  WindowObjectRef = 0;
  delete WindowObjectRef;
}
void ScreenOutput::Write(std::string OutputData)
{
  OutputContentList.push_back(OutputData);
}
void ScreenOutput::Clear()
{
  if (!OutputContentList.empty())
    OutputContentList.clear();
}
void ScreenOutput::Draw()
{
  if (!OutputContentList.empty())
  {
  }
}
void ScreenOutput::SetScreenCursorPosition(sf::Vector2f NewScreenCursorPosition)
{
  if (NewScreenCursorPosition.x < 0.0f)
    NewScreenCursorPosition.x = 0.0f;
  if (NewScreenCursorPosition.y < 0.0f)
    NewScreenCursorPosition.y = 0.0f;

  ScreenCursorPosition = NewScreenCursorPosition;
}
void ScreenOutput::SetOutputFontSizePixels(const unsigned int NewOutputFontSizePixels)
{
  OutputFontSizePixels = NewOutputFontSizePixels;
}
void ScreenOutput::SetOutputLineHeightPadding(const float NewOutputLineHeightPadding)
{
  OutputLineHeightPadding = NewOutputLineHeightPadding;
}
sf::Vector2f ScreenOutput::GetScreenCursorPosition() const
{
  return ScreenCursorPosition;
}
unsigned int ScreenOutput::GetOutputFontSizePixels() const
{
  return OutputFontSizePixels;
}
float ScreenOutput::GetLineHeightPadding() const
{
  return OutputLineHeightPadding;
}
