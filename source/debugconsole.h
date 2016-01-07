#pragma once 

#include <iostream>
#include <windows.h>

#include <SFML/System.hpp>

// A Wrapper for window specific functions that conflict with other functions named the same.
namespace WindowsFunctions
{
  void WinSleep(sf::Time SleepDuration);
}

class WindowsDebugConsole
{
public:
  WindowsDebugConsole();
  ~WindowsDebugConsole();
  void ClearScreen();
  void Sleep(sf::Time SleepDuration);
private:
  HANDLE HandleStdOutput;
};
