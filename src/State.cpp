#include "State.h"
#include <SDL.h>
#include <iostream>

State::State() {
	quitRequested = false;
	bg = *(new Sprite("recursos/img/ocean.jpg"));
	music = *(new Music("recursos/audio/stageState.ogg"));
	music.Play();

}

void State::LoadAssets() {

}

void State::Update(float dt) {
	if (SDL_QuitRequested()) {
		quitRequested = true;
		music.Stop(0);
	}
}

void State::Render() {
	bg.Render(0, 0);
}

bool State::QuitRequested() {
	return quitRequested;
}

