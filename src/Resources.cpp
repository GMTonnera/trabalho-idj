#include "Resources.h"
#include "Game.h"
#include <SDL_Image.h>
#include <iostream>


std::unordered_map<std::string, SDL_Texture*> Resources::imageTable = {};
std::unordered_map<std::string, Mix_Music*> Resources::musicTable = {};
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable = {};


SDL_Texture* Resources::GetImage(std::string file) {
	if (imageTable.find(file) != imageTable.end()) {
		return imageTable[file];
	}

	imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());

	return imageTable[file];
}
void Resources::ClearImages() {
	for (auto it = imageTable.begin(); it != imageTable.end(); it++) {
		SDL_DestroyTexture(std::get<1>(*it));
	}

	imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file) {
	if (musicTable.find(file) != musicTable.end()) {
		return musicTable[file];
	}

	musicTable[file] = Mix_LoadMUS(file.c_str());

	return musicTable[file];
}

void Resources::ClearMusics() {
	/*for (auto &it : musicTable) {
		delete it.second;
	}*/

	musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file) {
	if (soundTable.find(file) != soundTable.end()) {
		return soundTable[file];
	}

	soundTable[file] = Mix_LoadWAV(file.c_str());

	return soundTable[file];
}

void Resources::ClearSounds() {
	/*for (auto it : soundTable) {
		delete it.second;
	}*/

	soundTable.clear();
}