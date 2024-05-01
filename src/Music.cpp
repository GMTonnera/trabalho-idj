#include "Music.h"
#include "Resources.h"
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
		
	}
}

void Music::Stop(int ms) {
	Mix_FadeOutMusic(ms);
}

void Music::Open(std::string file) {
	this->music = Resources::GetMusic(file);
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

