#include "IndexBuffer.h"

namespace gl
{
    static size_t indexTypeSize(GLenum type)
    {
        switch (type)
        {
        case GL_UNSIGNED_BYTE:  return 1;
        case GL_UNSIGNED_SHORT: return 2;
        case GL_UNSIGNED_INT:   return 4;
        default: return 0;
        }
    }

    void IndexBuffer::createIndexBuffer(size_t size, const void* data)
    {
        glCreateBuffers(1, &m_id);
        glNamedBufferStorage(m_id, size, data, 0);
    }

    void IndexBuffer::destroyIndexBuffer() noexcept
    {
        if (m_id != 0)
        {
            glDeleteBuffers(1, &m_id);
            m_id = 0;
        }
    }

    IndexBuffer::IndexBuffer(uint32_t count, GLenum type, const void* data)
        : m_count(count), m_type(type)
    {
        size_t size = count * indexTypeSize(type);
        createIndexBuffer(size, data);
    }

    IndexBuffer::~IndexBuffer() noexcept
    {
        destroyIndexBuffer();
    }

    IndexBuffer::IndexBuffer(IndexBuffer&& other) noexcept
        : m_id(other.m_id),
        m_count(other.m_count),
        m_type(other.m_type)
    {
        other.m_id = 0;
        other.m_count = 0;
    }

    IndexBuffer& IndexBuffer::operator=(IndexBuffer&& other) noexcept
    {
        if (this != &other)
        {
            destroyIndexBuffer();
            m_id = other.m_id;
            m_count = other.m_count;
            m_type = other.m_type;

            other.m_id = 0;
            other.m_count = 0;
        }
        return *this;
    }
}
