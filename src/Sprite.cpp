#include <string>
#include <SDL_Image.h>
#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

Sprite::Sprite() : Component() {
	this->texture = nullptr;
	this->width = NULL;
	this->height = NULL;
	this->clipRect = {};
}

Sprite::Sprite(GameObject& associated) : Component(associated) {
	this->texture = nullptr;
	this->width = NULL;
	this->height = NULL;
	this->clipRect = {};
}

Sprite::Sprite(std::string file, GameObject& associated) : Component(associated) {
	texture = nullptr;
	Open(file);
	associated.box.w = width;
	this->associated.box.h = height;
}

Sprite::~Sprite() {
}

void Sprite::Open(std::string file) {
	if (texture != nullptr) {

	}
	texture = Resources::GetImage(file);
	
	SDL_GetError();

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render(int x, int y) {
	SDL_Rect dstrect;
	dstrect.x = x;
	dstrect.y = y;
	dstrect.w = clipRect.w;
	dstrect.h = clipRect.h;

	SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}


void Sprite::Render() {
	Render(associated.box.x, associated.box.y);
}

int Sprite::GetWidth() {
	return width;
}

int Sprite::GetHeight() {
	return height;
}

bool Sprite::IsOpen() {
	if (texture == nullptr) {
		return false;
	}
	else {
		return true;
	}
}

void Sprite::Update(float dt) {

}

bool Sprite::Is(std::string type) {
	if (type == "sprite") {
		return true;
	}

	return false;
}