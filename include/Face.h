#pragma once
#include "Component.h"

class Face : public Component{

	private:
		int hitpoints;

	public:
		Face(GameObject& associated);

		~Face();

		void Damage(int damage);

		void Update(float dt);

		void Render();

		bool Is(std::string type);
};