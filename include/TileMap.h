#pragma once
#include "TileSet.h"

class TileMap : public Component {
	private:
		std::vector<int> tileMatrix;
		TileSet* tileSet;
		int mapWidth, mapHeight, mapDepth;

	public:
		TileMap(GameObject& assossiated, std::string file, TileSet* tileSet);

		void Load(std::string file);

		void SetTileSet(TileSet* tileSet);

		int& At(int x, int y, int z = 0);

		void Render();

		void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

		int GetWidth();

		int GetHeight();

		int GetDepth();

		bool Is(std::string type);

		void Update(float dt);
};