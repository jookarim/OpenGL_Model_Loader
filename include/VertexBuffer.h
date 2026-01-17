#include <GL/glew.h>
#include <cstdint>
#include <cstddef>

namespace gl
{
    class VertexBuffer
    {
    private:
        uint32_t m_id = 0;

        void createVertexBuffer(size_t size, const void* data);
        void destroyVertexBuffer() noexcept;

    public:
        VertexBuffer(size_t size, const void* data);
        explicit VertexBuffer(size_t size); 

        ~VertexBuffer() noexcept;

        void updateVertexBuffer(size_t offset, size_t size, const void* data);

        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;

        VertexBuffer(VertexBuffer&& other) noexcept;
        VertexBuffer& operator=(VertexBuffer&& other) noexcept;

        uint32_t getID() const { return m_id; }
    };
}
