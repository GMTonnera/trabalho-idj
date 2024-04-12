#pragma once
#include <string>
#include <GameObject.h>

class Component {
	protected:
		GameObject& associated;

	public:
		Component();

		Component(GameObject& go);

		virtual ~Component();

		virtual void Update(float dt) = 0;

		virtual void Render() = 0;

		virtual bool Is(std::string type) = 0;
};