#include "Music.h"
#include <iostream>

Music::Music() {
	music = nullptr;
}

Music::Music(std::string file) {
	Open(file);
}

void Music::Play(int times) {
	if (this->music != nullptr) {
		Mix_PlayMusic(this->music, times);
		
		// std::cout << SDL_GetError() << "\n";
	}
}

void Music::Stop(int ms) {
	Mix_FadeOutMusic(ms);
}

void Music::Open(std::string file) {
	this->music = Mix_LoadMUS(file.c_str());
	std::cout << SDL_GetError() << "\n";
}

bool Music::IsOpen() {
	if (music == nullptr) {
		return false;
	}
	return true;
}

Music::~Music() {
	Stop();
	Mix_FreeMusic(music);
}

