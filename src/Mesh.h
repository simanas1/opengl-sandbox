#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include <glm/glm.hpp>

class Mesh {
public:
	Mesh(const char* filepath);
	~Mesh();

	struct Vertex {
		glm::vec3 Position;
	};

	int indicesCount{ 0 };
	int verticesCount{ 0 };

	std::vector<Vertex> vertices;

	std::vector<int> indices;
};