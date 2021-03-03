#include "Mesh.h"

Mesh::Mesh(const char* filepath)
{

	std::cout << "Loading mesh OBJ from: " << filepath << '\n';

	std::ifstream inFile{ filepath };
    std::string line;

    // If we couldn't open the output file stream for reading
    if (!inFile)
    {
        // Print an error and exit
        std::cerr << "Uh oh, OBJ file could not be opened for reading!" << std::endl;

    }

    // While there's still stuff left to read
    while (std::getline(inFile, line))
    {
        std::string type;
        int index;
        std::istringstream in(line);
        in >> type;

        if (type == "v")
        {
            Vertex temp;
            in >> temp.Position.x >> temp.Position.y >> temp.Position.z;
            vertices.push_back(temp);
            verticesCount++;
        }

        if (type == "f")
        {
            while (in >> index) {
                indices.push_back(index-1);
                indicesCount++;
            }
        }

    }
}

Mesh::~Mesh()
{
}
