#pragma once
#include <SDL_mixer.h>
#include "Component.h"


class Sound : public Component {
	private:
		Mix_Chunk* chunk;
		int channel;
		int state;
		bool playing;

	public:
		Sound(GameObject& associated);

		Sound(std::string file, GameObject& associated);

		~Sound();

		void Play(int times = 1);

		void Stop();

		void Open(std::string file);

		bool IsOpen();

		void Update(float dt);

		void Render();

		bool Is(std::string type);

		int GetState();
};