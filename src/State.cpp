#include "State.h"
#include "Sound.h"
#include "Face.h"
#include "GameObject.h"
#include <SDL.h>
#include <iostream>

State::State() : music(Music("recursos/audio/stageState.ogg")){
	this->quitRequested = false;
	
	GameObject* go = new GameObject();

	Sprite* spt = new Sprite("recursos/img/ocean.jpg", *go);

	go->AddComponent(spt);

	objectArray.emplace_back(go);

	GameObject* go2 = new GameObject();
	go2->box.x = 0;
	go2->box.y = 0;

	TileSet ts = TileSet(64, 64, "recursos/img/tileset.png");
	TileMap* tm = new TileMap(*go, "recursos/map/tileMap.txt", &ts);

	go2->AddComponent(tm);






	this->music.Play();

}

State::~State() {
	this->objectArray.clear();
}

void State::LoadAssets() {

}

void State::Update(float dt) {
	Input();
	for (int i = 0; i < objectArray.size(); i++) {
		this->objectArray[i]->Update(dt);
	}

	if (SDL_QuitRequested()) {
		this->music.Stop(0);
	}

	for (int i = objectArray.size()-1; i >= 0; i--) {
		if (objectArray[i]->IsDead()) {
			if (objectArray[i]->GetComponent("sound") == nullptr) {
				this->objectArray.erase(objectArray.begin() + i);
				GameObject* go = new GameObject();
				go->AddComponent(new Sound("recursos/audio/boom.wav", *go));
				Sound* cptSound = dynamic_cast<Sound*>(go->GetComponent("sound"));
				cptSound->Play();
				objectArray.emplace_back(go);
			}
			else {
				if (dynamic_cast<Sound*>(objectArray[i]->GetComponent("sound"))->GetState() == 2) {

					this->objectArray.erase(objectArray.begin() + i);
				}
			}
		}	
	}
}

void State::Render() {
	for (int i = 0; i < objectArray.size(); i++) {
		objectArray[i]->Render();
	}
}

bool State::QuitRequested() {
	return this->quitRequested;
}

void State::Input() {
	SDL_Event event;
	int mouseX, mouseY;

	// Obtenha as coordenadas do mouse
	SDL_GetMouseState(&mouseX, &mouseY);

	// SDL_PollEvent retorna 1 se encontrar eventos, zero caso contr�rio
	while (SDL_PollEvent(&event)) {

		// Se o evento for quit, setar a flag para termina��o
		if (event.type == SDL_QUIT) {
			this->quitRequested = true;
		}

		// Se o evento for clique...
		if (event.type == SDL_MOUSEBUTTONDOWN) {

			// Percorrer de tr�s pra frente pra sempre clicar no objeto mais de cima
			for (int i = this->objectArray.size() - 1; i >= 0; --i) {
				// Obtem o ponteiro e casta pra Face.
				GameObject* go = (GameObject*)objectArray[i].get();
				// Nota: Desencapsular o ponteiro � algo que devemos evitar ao m�ximo.
				// O prop�sito do unique_ptr � manter apenas uma c�pia daquele ponteiro,
				// ao usar get(), violamos esse princ�pio e estamos menos seguros.
				// Esse c�digo, assim como a classe Face, � provis�rio. Futuramente, para
				// chamar fun��es de GameObjects, use objectArray[i]->fun��o() direto.

				if (go->box.IsInside({ (float)mouseX, (float)mouseY })) {
					Face* face = (Face*)go->GetComponent("face");
					if (nullptr != face) {
						// Aplica dano
						face->Damage(std::rand() % 10 + 10);
						// Sai do loop (s� queremos acertar um)
						break;
					}
				}
			}
		}
		if (event.type == SDL_KEYDOWN) {
			// Se a tecla for ESC, setar a flag de quit
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				quitRequested = true;
			}
			// Se n�o, crie um objeto
			else {
				//Vec2 objPos = Vec2(200, 0).rotate(-PI + PI * (rand() % 1001) / 500.0) + Vec2(mouseX, mouseY);
				Vec2 objPos = Vec2(200, 0).Rotate(rand() * 2 * 3.1415) + Vec2(mouseX, mouseY);
				AddObject((int)objPos.x, (int)objPos.y);
			}
		}
	}
}

void State::AddObject(int x, int y) {
	
GameObject* go = new GameObject();
	go->AddComponent(new Sprite("recursos/img/penguinface.png", *go));

	go->box.x = x - (go->box.w / 2);
	go->box.y = y - (go->box.h / 2);

	go->AddComponent(new Face(*go));
	
	this->objectArray.emplace_back(go);
}