#include "Mesh.h"

namespace engine::gfx
{
	void Mesh::createMesh(const engine::assets::MeshData& meshData) 
	{
		m_vertexArray.linkVertexArrayToVertexBuffer(m_vertexBuffer, 0, 0, sizeof(engine::assets::Vertex));
		m_vertexArray.linkVertexArrayToIndexBuffer(m_indexBuffer);

		m_vertexArray.linkAttrib(0, 3, GL_FLOAT, GL_FALSE, 0);
		m_vertexArray.linkAttrib(1, 2, GL_FLOAT, GL_FALSE, offsetof(engine::assets::Vertex, texCoord));
		m_vertexArray.linkAttrib(2, 3, GL_FLOAT, GL_FALSE, offsetof(engine::assets::Vertex, normal));
	}

	Mesh::Mesh(const engine::assets::MeshData& meshData) : m_vertexBuffer(meshData.vertices.size() * sizeof(engine::assets::Vertex), meshData.vertices.data()),
															m_indexBuffer(meshData.indices.size(), GL_UNSIGNED_INT, meshData.indices.data())
	{
		createMesh(meshData);
	}

	void Mesh::draw() const
	{
		m_vertexArray.bind();
		glDrawElements(GL_TRIANGLES, m_indexBuffer.getCount(), GL_UNSIGNED_INT, nullptr);
	}
}