#pragma once
#include <GL/glew.h>
#include <cstdint>
#include <cstddef>

namespace gl
{
    class IndexBuffer
    {
    private:
        uint32_t m_id = 0;
        uint32_t m_count = 0;
        GLenum   m_type = GL_UNSIGNED_INT;

        void createIndexBuffer(size_t size, const void* data);
        void destroyIndexBuffer() noexcept;

    public:
        IndexBuffer(uint32_t count, GLenum type, const void* data);
        ~IndexBuffer() noexcept;

        IndexBuffer(const IndexBuffer&) = delete;
        IndexBuffer& operator=(const IndexBuffer&) = delete;

        IndexBuffer(IndexBuffer&& other) noexcept;
        IndexBuffer& operator=(IndexBuffer&& other) noexcept;

        uint32_t getID()    const { return m_id; }
        uint32_t getCount() const { return m_count; }
        GLenum   getType()  const { return m_type; }
    };
}
