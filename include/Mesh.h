#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "MeshData.h"

namespace engine::gfx
{	
	class Mesh
	{
	private:
		void createMesh(const engine::assets::MeshData& meshData);

		gl::VertexArray m_vertexArray;
		gl::VertexBuffer m_vertexBuffer;
		gl::IndexBuffer m_indexBuffer;
	public:
		Mesh(const assets::MeshData& meshData);
		~Mesh() noexcept = default;

		void draw() const;
	};
}