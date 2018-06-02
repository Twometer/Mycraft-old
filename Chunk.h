#pragma once
#include <vector>
#include "Section.h"
#include "ChunkExtracted.h"
class Section;
class Chunk
{
private:
	Section * * sections;
public:
	int x;
	int z;
	unsigned char getBlock(int x, int y, int z);
	void setBlock(int x, int y, int z, unsigned char id, bool updateSection);
	void buildVertexData();
	void uploadVertexData();
	void render(bool transparencyPass);
	void destroy();
	void initialize(ChunkExtracted* data);
	Chunk(int x, int z);
	~Chunk();
};

