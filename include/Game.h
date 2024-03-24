#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <string>
#include "State.h"

class Game {
	private:
		
		static Game* instance;
		SDL_Window* window;
		SDL_Renderer* renderer;
		State* state;

		Game(std::string title, int width, int height);
	
	public:
		~Game();

		void Run();

		SDL_Renderer* GetRenderer();

		State& GetState();

		static Game& GetInstance();



};