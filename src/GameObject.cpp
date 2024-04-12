#include "GameObject.h"
#include "Component.h"
#include <iostream>

GameObject::GameObject() {
	isDead = false;
}

GameObject::~GameObject() {
	/*for (int i = components.size() - 1; i >= 0; i--) {
		delete components[i].get();
	}*/
	this->components.clear();
}

void GameObject::Update(float dt) {
	for (int i = 0; i < this->components.size(); i++) {
		components[i]->Update(dt);
	}
}


void GameObject::Render() {
	for (int i = 0; i < this->components.size(); i++) {
		this->components[i]->Render();
	}
}

bool GameObject::IsDead() {
	return this->isDead;
}

void GameObject::RequestDelete() {
	this->isDead = true;
}

void GameObject::AddComponent(Component* cpt) {
	this->components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt) {
	for (int i = 0; i < this->components.size(); i++) {
		if (this->components[i].get() == cpt) {
			components.erase(this->components.begin()+i);
			break;
		}
	}
}

Component* GameObject::GetComponent(std::string type) {
	for (int i = 0; i < this->components.size(); i++) {
		if (this->components[i]->Is(type)) {
			return this->components[i].get();
		}
	}
	return nullptr;
}