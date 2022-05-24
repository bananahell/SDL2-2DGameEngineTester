#include "Game.h"

#include "MainState.h"

void Game::initGame() {
  this->state = new MainState();
}

void Game::run() {
  this->state->initState();
  this->state->stateLoop();
  this->clean();
}
