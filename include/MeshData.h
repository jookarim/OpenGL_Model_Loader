#include <vector>
#include <glm/glm.hpp>

namespace engine::assets
{
	struct Vertex
	{
		glm::vec3 position{};
		glm::vec2 texCoord{};
		glm::vec3 normal{};
	};

	struct MeshData
	{
		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;
	};
}