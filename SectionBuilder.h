#pragma once
#include <vector>
#include "GLFW/glfw3.h"
#include "Section.h"
#include "VboBuilder.h"
class SectionBuilder
{
private:
	Section* chunk;
	
	int absX;
	int absY;
	int absZ;
	int x;
	int y;
	int z;
	int xo, yo, zo;
	unsigned char getBlock(unsigned char, int x, int y, int z);
public:
	GLfloat * vertices;
	int verticesAlloc;

	GLfloat * colors;
	int colorsAlloc;

	GLfloat * textureCoords;
	int textureCoordsAlloc;
	VboBuilder * regularBuilder;
	void drawDisplacedVertices(const GLfloat* textures, const GLfloat* vertices, int x, int y, int z, int tX, int tY, GLfloat color);
	void build(int xoff, int yoff, int zoff);
	SectionBuilder(Section* chunk);
	~SectionBuilder();
};

