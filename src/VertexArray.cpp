#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace engine::gl
{
	void VertexArray::createVertexArray()
	{
		glCreateVertexArrays(1, &m_id);
	}

	void VertexArray::destroyVertexArray() noexcept
	{
		if (m_id != 0)
		{
			glDeleteVertexArrays(1, &m_id);
			m_id = 0;
		}
	}

	VertexArray::VertexArray()
	{
		createVertexArray();
	}

	VertexArray::~VertexArray() noexcept
	{
		destroyVertexArray();
	}

	void VertexArray::linkVertexArrayToVertexBuffer(const VertexBuffer& vertexBuffer, uint32_t vertexBufferBinding, intptr_t offset, uint32_t stride) const
	{
		glVertexArrayVertexBuffer(m_id, vertexBufferBinding, vertexBuffer.getID(), offset, stride);
	}

	void VertexArray::linkVertexArrayToIndexBuffer(const IndexBuffer& indexBuffer) const
	{
		glVertexArrayElementBuffer(m_id, indexBuffer.getID());
	}

	VertexArray::VertexArray(VertexArray&& other) noexcept
	{
		m_id = other.m_id;
		other.m_id = 0;
	}

	VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
	{
		if (this == &other) return *this;

		destroyVertexArray();

		m_id = other.m_id;

		other.m_id = 0;

		return *this;
	}

	void VertexArray::linkAttrib(uint32_t attribIndex, uint32_t size, uint32_t type, bool normalized, uint32_t relativeOffset) const noexcept
	{
		glEnableVertexArrayAttrib(m_id, attribIndex);
		glVertexArrayAttribBinding(m_id, attribIndex, 0);
		glVertexArrayAttribFormat(m_id, attribIndex, size, type, normalized, relativeOffset);
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_id);
	}
}
