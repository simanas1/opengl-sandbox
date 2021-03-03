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
        std::string faces;
        
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
            unsigned int polygonIndices{0};
            while (in >> faces)
            {
                polygonIndices++;
                std::stringstream facesStream(faces);
                std::string face;
                int faceCount{ 0 };
                while (std::getline(facesStream, face, '/'))
                {
                    faceCount++;
                    //TODO: what to do with quadrilaterals?
                    if (face != "" && polygonIndices < 4)
                    {
                        switch (faceCount)
                        {
                        case 1:
                            indices.push_back(std::stoi(face)-1);
                            indicesCount++;
                            break;
                        //TODO: other faces for textures and normals
                        }
                    }
                }
            }
        }
    }
}

Mesh::~Mesh()
{
}
