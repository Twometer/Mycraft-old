#include "Block.h"



Block::Block(char id, TEXTURE topTex, TEXTURE sideTex, TEXTURE bottomTex, RendererType rendererType)
{
	this->id = id;
	this->topTex = topTex;
	this->sideTex = sideTex;
	this->bottomTex = bottomTex;
	this->rendererType = rendererType;
}


Block::~Block()
{
}
