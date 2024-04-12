#pragma once
#include <SDL.h>
#include <string>
#include "Component.h"
#include "GameObject.h"

class Sprite : public Component{
	private:
		SDL_Texture* texture;
		int width;
		int height;
		SDL_Rect clipRect;

	public:
		Sprite();

		Sprite(GameObject& go);

		Sprite(std::string file, GameObject& go);

		~Sprite();

		void Open(std::string file);

		void SetClip(int x, int y, int w, int h);

		void Render();

		int GetWidth();

		int GetHeight();

		bool IsOpen();
		
		void Update(float dt);

		bool Is(std::string type);
};