#include "TileMap.h"
#include <fstream>

TileMap::TileMap(GameObject& assossiated, std::string file, TileSet* tileSet) : Component(assossiated){
	this->Load(file);
	this->tileSet = tileSet;
}

void TileMap::Load(std::string file) {
	std::ifstream mapFile(file);
	std::string line;
	int p;

	getline(mapFile, line);
	
	// Largura do mapa
	p = line.find(',');
	this->mapWidth = stoi(line.substr(0, p));
	line.erase(0, p + 1);

	// Altura do mapa
	p = line.find(',');
	this->mapHeight = stoi(line.substr(0, p));
	line.erase(0, p + 1);

	// Profundidade do mapa
	p = line.find(',');
	this->mapDepth = stoi(line.substr(0, p));
	line.erase(0, p + 1);
	
	while (getline(mapFile, line)) {
		while ((p = line.find(',')) != std::string::npos) {
			this->tileMatrix.push_back(stoi(line.substr(0, p))-1);
			line.erase(0, p + 1);
		}
	}
}

void TileMap::SetTileSet(TileSet* tileSet) {
	this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z) {
	return this->tileMatrix[x + y*this->mapWidth + z*this->mapWidth*this->mapHeight];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
	for (int i = layer * (mapWidth * mapHeight - 1); i <= (layer + 1) * (mapWidth * mapHeight - 1); i++) {
		this->tileSet->RenderTile(this->tileMatrix[i], i % mapWidth, i / mapHeight);
	}
}

void TileMap::Render() {
	for (int i = 0; i < this->mapDepth; i++) {
		this->RenderLayer(i, 0, 0);
	}
}

int TileMap::GetWidth() {
	return this->mapWidth;
}

int TileMap::GetHeight() {

	return this->mapHeight;
}

int TileMap::GetDepth() {
	return this->mapDepth;
}

bool TileMap::Is(std::string type) {
	if (type == "tilemap") {
		return true;
	}
	return false;
}

void TileMap::Update(float dt) {

}