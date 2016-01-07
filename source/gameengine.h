#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <windows.h>

#include "ScreenOutput.h"

#ifdef SFML_GAMEDEV_DEBUG
  #include "DebugConsole.h"
#endif

namespace sf
{
  void Sleep(sf::Time SleepDuration);
}

class GameEngine
{
public:
  GameEngine(std::string GameTitle);
  ~GameEngine();
  void Initialize();
  void Update();
  void Draw();
  void DeInitialize();
  void Run();

private:
  sf::RenderWindow GameWindow;
  ScreenOutput GameScreenOutput;
  sf::Event GameWindowEvent;
  sf::Clock GameClock;

  bool IsRunning;

  #ifdef SFML_GAMEDEV_DEBUG
    WindowsDebugConsole DebugConsole;
  #endif
};
