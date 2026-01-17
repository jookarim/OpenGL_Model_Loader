#include "VertexBuffer.h"

namespace gl
{
	void VertexBuffer::createVertexBuffer(size_t size, const void* data)
	{
		glCreateBuffers(1, &m_id);
		glNamedBufferStorage(m_id, size, data, GL_DYNAMIC_STORAGE_BIT);
	}

	void VertexBuffer::destroyVertexBuffer() noexcept
	{
		if (m_id != 0)
		{
			glDeleteBuffers(1, &m_id);
			m_id = 0;
		}
	}

	VertexBuffer::~VertexBuffer() noexcept
	{
		destroyVertexBuffer();
	}

	VertexBuffer::VertexBuffer(size_t size, const void* data)
	{
		createVertexBuffer(size, data);
	}

	VertexBuffer::VertexBuffer(size_t size)
	{
		glCreateBuffers(1, &m_id);
		glNamedBufferStorage(m_id, size, nullptr, GL_DYNAMIC_STORAGE_BIT);
	}

	void VertexBuffer::updateVertexBuffer(size_t offset, size_t size, const void* data)
	{
		glNamedBufferSubData(m_id, offset, size, data);
	}

	VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept
	{
		m_id = other.m_id;
		other.m_id = 0;
	}
	
	VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept
	{
		if (this == &other) return *this;
		destroyVertexBuffer();

		m_id = other.m_id;
		other.m_id = 0;

		return *this;
	}
}