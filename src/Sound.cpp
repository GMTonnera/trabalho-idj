#include <iostream>
#include <SDL.h>
#include "Sound.h"
#include "Resources.h"

Sound::Sound(GameObject& associated) : Component{ associated } {
	chunk = nullptr;
	channel = NULL;
	state = 0;
	playing = false;
}

Sound::Sound(std::string file, GameObject& associated) : Component{ associated } {
	channel = NULL;
	state = 0;
	playing = false;
	Open(file);
}

void Sound::Play(int times) {
	state = 1;
	channel = Mix_PlayChannel(-1, chunk, times - 1);
}

void Sound::Stop() {
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
	}
}

void Sound::Open(std::string file) {
	chunk = Resources::GetSound(file);  
	if (chunk == nullptr) {
		std::cout << SDL_GetError() << "\n";
		exit(1);
	}
	
}

Sound::~Sound() {
	if (chunk != nullptr) {
		Mix_HaltChannel(channel);
		Mix_FreeChunk(chunk);
	}
}

bool Sound::Is(std::string type) {
	if (type == "sound") {
		return true;
	}
	return false;
}

bool Sound::IsOpen() {
	if (chunk != nullptr) {
		return true;
	}
	return false;
}

void Sound::Update(float dt){
	playing = Mix_Playing(channel);

	if (state == 1 and !playing) {
		state == 2;
		associated.RequestDelete();
	}
}

void Sound::Render(){}

int Sound::GetState() {
	return this->state;
}

