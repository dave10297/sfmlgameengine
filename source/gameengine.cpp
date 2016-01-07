#include "gameengine.h"

void sf::Sleep(sf::Time SleepDuration)
{
  sf::sleep(SleepDuration);
}
GameEngine::GameEngine(std::string GameTitle)
  : GameWindow(sf::VideoMode(800, 600), GameTitle, sf::Style::Close),
    GameScreenOutput("ff7.ttf", &GameWindow)
{
}
GameEngine::~GameEngine()
{
}

void GameEngine::Initialize()
{
  // Configure GameEngine subsystems
  #ifdef SFML_GAMEDEV_DEBUG
    SetConsoleTitle("SFML GameDev - Console");
  #endif
  IsRunning = true;
}
void GameEngine::Update()
{
  GameScreenOutput.Clear();
  #ifdef SFML_GAMEDEV_DEBUG
    DebugConsole.ClearScreen();
  #endif

  // Update all GameEngine subsystems
  while (GameWindow.pollEvent(GameWindowEvent))
  {
    // User pressed the 'X' button on the window titlebar
    switch (GameWindowEvent.type)
    {
      case sf::Event::Closed:
      {
        IsRunning = false;
      }break;

      // User pressed a key on the keyboard
      case sf::Event::KeyPressed:
      {
        switch(GameWindowEvent.key.code)
        {
          case sf::Keyboard::Escape:
          {
            IsRunning = false;
          }break;
        }
      }break;
    }
  }

  sf::Time MillisecondsToSleep = sf::milliseconds(1000 / 60 - GameClock.getElapsedTime().asMilliseconds());

  GameScreenOutput.Write("MillisecondsToSleep: ");
  GameScreenOutput.Write(std::to_string(MillisecondsToSleep.asMilliseconds()) + '\n');
  GameScreenOutput.Write("This is a string\n");
  GameScreenOutput.Write("This\nIs\nA\nNewline");
  GameScreenOutput.Write("\n");

  sf::Sleep(MillisecondsToSleep);

  GameClock.restart();
}
void GameEngine::Draw()
{
  // Draw all content to the screen
  GameWindow.clear(sf::Color::Black);
    GameScreenOutput.Draw();
  GameWindow.display();
}
void GameEngine::DeInitialize()
{
  // Shutdown all game engine systems
  GameWindow.close();
}
void GameEngine::Run()
{
  Initialize();
  while (IsRunning)
  {
    Update();
    Draw();
  }
  DeInitialize();
}
