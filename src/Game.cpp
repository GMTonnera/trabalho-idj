#include <string>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <ctime>
#include <iostream>
#include "Game.h"
#include "State.h"
#include "Resources.h"

Game* Game::instance = nullptr;


Game& Game::GetInstance() {
	// Verificar se existe uma inst�ncia de jogo
	if (instance != nullptr) {
		// Se sim, retornar essa inst�ncia
		return *instance;
	}
	else {
		// Se n�o, criar uma nova
		instance = new Game("Gustavo M. Tonnera (211055272)", 1024, 600);
	}
}

Game::Game(std::string title, int width, int height) {
	// Verificar se j� existe uma inst�ncia de Game
	srand(time(NULL));

	if (instance == nullptr) {
		// Se n�o, criar uma
		instance = this;

		// Incializar o SDL
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
		
		// Incializar o SDL_Image
		IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);

		// Inicializar o SDL_Mixer
		Mix_Init(MIX_INIT_OGG | MIX_INIT_WAVPACK);
		Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
		Mix_AllocateChannels(32);
		
		// Criar uma nova janela
		window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
		
		// Criar um novo renderizador
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		
		// Criar um novo estado
		state = new State();
	}
}

Game::~Game() {
	// Deletar estado
	delete state;

	// Encerrar SDL_Mixer
	Mix_CloseAudio();
	Mix_Quit();
	
	// Encerrar SDL_Image
	IMG_Quit();
	
	// Destruir Renderizador
	SDL_DestroyRenderer(renderer);
	
	// Destruir Janela
	SDL_DestroyWindow(window);
	
	// Encerrar SDL
	SDL_Quit();
}

State& Game::GetState() {
	return *state;
}

SDL_Renderer* Game::GetRenderer() {
	return renderer;
}

void Game::Run() {
	while (!state->QuitRequested()) {
		state->Update(0.0);
		state->Render();
		SDL_RenderPresent(renderer);
		SDL_Delay(33);
	}

	Resources::ClearImages();
	Resources::ClearMusics();
	Resources::ClearSounds();
}