#pragma once
#include <glm/common.hpp>
#include "GLFW/glfw3.h"
#include "RaycastResult.h"

class VertexHandler {

public:
	virtual glm::vec3 process(int meta, GLfloat x, GLfloat, GLfloat z, glm::vec3 worldPos, FACE face) = 0;
	virtual glm::vec2 processTex(GLfloat u, GLfloat v, FACE face) {
		return glm::vec2(u, v);
	}
protected:

	const glm::vec3 moveIn(GLfloat x, GLfloat y, GLfloat z, FACE face, GLfloat factor) {
		if (face == XPOS)
			x -= factor;
		else if (face == XNEG)
			x += factor;
		else if (face == ZPOS)
			z -= factor;
		else if (face == ZNEG)
			z += factor;
		return glm::vec3(x, y, z);
	}

	const glm::vec3 rotate90(GLfloat x, GLfloat y, GLfloat z, GLfloat v0 = 0.0f, GLfloat v1 = 1.0f) {
		if (x == v0 && z == v0)
			return glm::vec3(v0, y, v1);
		if (x == v0 && z == v1)
			return glm::vec3(v1, y, v1);
		if (x == v1 && z == v1)
			return glm::vec3(v1, y, v0);
		if (x == v1 && z == v0)
			return glm::vec3(v0, y, v0);
		return glm::vec3(x, y, z);
	};

	const glm::vec3 rotate180(GLfloat x, GLfloat y, GLfloat z, GLfloat v0 = 0.0f, GLfloat v1 = 1.0f) {
		if (x == v0 && z == v0)
			return glm::vec3(v1, y, v1);
		if (x == v0 && z == v1)
			return glm::vec3(v0, y, v1);
		if (x == v1 && z == v1)
			return glm::vec3(v0, y, v0);
		if (x == v1 && z == v0)
			return glm::vec3(v1, y, v0);
		return glm::vec3(x, y, z);
	};

	const glm::vec3 rotate270(GLfloat x, GLfloat y, GLfloat z, GLfloat v0 = 0.0f, GLfloat v1 = 1.0f) {
		if (x == v0 && z == v0)
			return glm::vec3(v1, y, v0);
		if (x == v1 && z == v0)
			return glm::vec3(v1, y, v1);
		if (x == v1 && z == v1)
			return glm::vec3(v0, y, v1);
		if (x == v0 && z == v1)
			return glm::vec3(v0, y, v0);
		return glm::vec3(x, y, z);
	};

};