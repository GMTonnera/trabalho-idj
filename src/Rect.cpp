#include "Rect.h"

Rect::Rect() {
	this->h = 0;
	this->w = 0;
	this->x = 0;
	this->y = 0;
}

Rect::Rect(float x, float y, float w, float h) {
	this->h = h;
	this->w = w;
	this->x = x;
	this->y = y;
}

Rect Rect::operator+(Vec2 v) {
	return Rect(this->x + v.x, this->y + y, this->w, this->h);
}

Vec2 Rect::GetCenter() {
	return Vec2((this->x + this->w) / 2, (this->y + this->h) / 2);
}

float Rect::GetDistanceRect(Rect r) {
	return this->GetCenter().GetDistance(r.GetCenter());
}

bool Rect::IsInside(Vec2 v) {
	if ((v.x <= this->x + this->w) and (v.x >= this->x) and (v.y <= this->y + this->h) and (v.y >= this->y)) {
		return true;
	}
	return false;
}