#include "Music.h"
#include <iostream>

Music::Music() {
	music = nullptr;
}

Music::Music(std::string file) {
	Open(file);
}

void Music::Play(int times) {
	if (music != nullptr) {
		Mix_PlayMusic(music, times);
	}
}

void Music::Stop(int ms) {
	Mix_FadeOutMusic(ms);
}

void Music::Open(std::string file) {
	music = Mix_LoadMUS(file.c_str());
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

