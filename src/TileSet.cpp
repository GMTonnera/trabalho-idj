#include "TileSet.h"

#include <cstdlib>

GameObject* go = new GameObject();

TileSet::TileSet(int tileWidth, int tileHeight, std::string file) : tileSet(Sprite(file, *go)) {
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
	this->columns = this->tileSet.GetWidth() / tileWidth;
	this->rows = this->tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y) {
	if (index >= 0 and index <= (this->columns * this->rows) - 1) {
		int xClip = index % this->columns * this->tileWidth;
		int yClip = index / this->rows * this->tileHeight;
		tileSet.SetClip(xClip, yClip, this->tileWidth, this->tileHeight);
		tileSet.Render(round(x), round(y));
	}
}

int TileSet::GetTileWidth() {
	return this->tileWidth;
}

int TileSet::GetTileHeight() {
	return this->tileHeight;
}