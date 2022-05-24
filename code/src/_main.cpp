#include "Game.h"

Game* game = NULL;

int main() {
  const char* windowName = "Engine Tester";
  int windowWidth = 1024;
  int windowHeight = 600;
  bool fullscreen = false;

  game = new Game();
  game->initEngine(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                   windowWidth, windowHeight, fullscreen);
  game->initGame();
  game->run();

  printf("Bye, have a good time!\n");
  return 0;
}
