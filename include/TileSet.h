#pragma once
#include "Sprite.h"

class TileSet {
	private:
		Sprite tileSet;
		int rows, columns, tileWidth, tileHeight;

	public:
		TileSet(int tileWidth, int tileHeight, std::string file);

		void RenderTile(unsigned index, float x, float y);

		int GetTileWidth();

		int GetTileHeight();
};