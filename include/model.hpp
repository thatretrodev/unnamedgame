#include <vector>

#ifndef MODEL_HPP
#define MODEL_HPP

struct ModelVertex {
	float x;
	float y;
	float z;
};

struct ModelFace {
	int vertex1, vertex2, vertex3;
};

class Model {
	public:
		std::vector<ModelVertex> vertices;
		std::vector<ModelFace> faces;
		Model(char* filename);
};

#endif