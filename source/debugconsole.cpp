#include "debugconsole.h"

void WindowsFunctions::WinSleep(sf::Time SleepDuration)
{
  Sleep(std::stoi(std::to_string(SleepDuration.asMilliseconds())));
}

WindowsDebugConsole::WindowsDebugConsole()
{
  HandleStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}
WindowsDebugConsole::~WindowsDebugConsole()
{

}
void WindowsDebugConsole::ClearScreen()
{
  // This isnt really clearing the screen but setting the Consoles cursor to a 'home' position then redrawing
  // THIS COULD CAUSE ARTIFACTING WHEN CERTAIN STRINGS CHANGE AND ARE REDRAWN OVER STRINGS THAT WERE LONGER, PART OF THE LONGER STRING WILL REMAIN ON THE CONSOLE
  COORD ConsoleCursorPosition;
  ConsoleCursorPosition.X = 0;
  ConsoleCursorPosition.Y = 0;

  SetConsoleCursorPosition(HandleStdOutput, ConsoleCursorPosition);
}
void WindowsDebugConsole::Sleep(sf::Time SleepDuration)
{
  WindowsFunctions::WinSleep(SleepDuration);
}
