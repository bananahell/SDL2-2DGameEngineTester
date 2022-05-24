#include "MainState.h"

#include "Engine.h"

using namespace std;

MainState::MainState() : background(Sprite()), themeMusic(Music()) {}
MainState::~MainState() {}

void MainState::initState() {
  string oceanImgName = "../assets/img/ocean.jpg";
  string mainStateThemeName = "../assets/music/stageState.ogg";
  this->background.open(oceanImgName);
  this->themeMusic.open(mainStateThemeName);
  this->themeMusic.play(PLAY_FOREVER);
  this->isRunning = true;
}

void MainState::update() {}

void MainState::render() {
  this->background.render(0, 0);
}
