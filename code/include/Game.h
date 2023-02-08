#ifndef GAME
#define GAME

#include "Engine.h"

/**
 * This is just a template "game", a tester for the engine project. This is how
 * a game should be made to use the engine I'm creating.
 * @author Pedro Nogueira
 */
class Game : public Engine {
 public:
  /**
   * Initializes the game in specific, like its states and flags.
   */
  void initGame() override;
  /**
   * Runs the game in specific. Put your states logic here, and don't forget to
   * clean in the end.
   */
  void run() override;
};

#endif  // GAME
