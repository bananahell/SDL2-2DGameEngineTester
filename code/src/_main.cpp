#include <iostream>

#include "Game.h"

using namespace std;

Game* game = NULL;

int main() {
  const char* windowName = "Engine Tester";
  int windowWidth = 1024;
  int windowHeight = 600;
  bool fullscreen = false;

  cout << endl;
  game = new Game();
  game->initEngine(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                   windowWidth, windowHeight, fullscreen);
  game->initGame();
  game->run();

  cout << "Bye, have a good time!" << endl;
  cout << endl;
  return 0;
}
