#ifndef MAINSTATE
#define MAINSTATE

#include <SDL2/SDL.h>

#include "State.h"

/**
 * One of the game's testing level. This is how the state class should be
 * inherited to make a game using this engine.
 * @author Pedro Nogueira
 */
class MainState : public State {
 public:
  Sprite background;  // Background sprite of the ice
  Music themeMusic;   // That cool theme song from idj

  /**
   * Default constructor, just starts the background image and song.
   */
  MainState();
  /**
   * Default destructor.
   */
  ~MainState();
  /**
   * Initializes the state in specific, like sprites and sounds.
   */
  void initState() override;
  /**
   * Main game logic of this specific state.
   */
  void update() override;
  /**
   * Handles what is shown in the screen.
   * @param renderer Engine's renderer, passed all the way up from the game.
   */
  void render() override;
};

#endif  // MAINSTATE
