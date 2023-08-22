#include "MainState.h"

#include "Engine.h"

using namespace std;

MainState::MainState() : themeMusic(Music()) {
  GameObject* background = new GameObject();
  background->box.posX = 0;
  background->box.posY = 0;
  background->addComponent(new Sprite(*background, "../assets/img/ocean.jpg"));
  State::objectVector.emplace_back(background);

  State::quitRequested = false;
}

MainState::~MainState() {}

void MainState::initState() {
  string mainStateThemeName = "../assets/music/stageState.ogg";
  this->themeMusic.open(mainStateThemeName);
  this->themeMusic.play(PLAY_FOREVER);
  this->quitRequested = false;
}

void MainState::update() {}

void MainState::render() {
  for (unsigned i = 0; i < State::objectVector.size(); i++) {
    State::objectVector.at(i).get()->render();
  }
}
