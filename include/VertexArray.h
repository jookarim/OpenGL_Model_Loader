#include <GL/glew.h>
#include <cstdint>
#include <cstddef>

namespace engine::gl
{
	class VertexBuffer;
	class IndexBuffer;

	class VertexArray
	{
	private:
		uint32_t m_id = 0;

		void createVertexArray();
		void destroyVertexArray() noexcept;
	public:
		VertexArray();
		~VertexArray() noexcept;

		void linkVertexArrayToVertexBuffer(const VertexBuffer& vertexBuffer, uint32_t vertexBufferBinding, intptr_t offset, uint32_t stride) const;
		void linkVertexArrayToIndexBuffer(const IndexBuffer& indexBuffer) const;

		VertexArray(const VertexArray&) = delete;
		VertexArray& operator=(const VertexArray&) = delete;

		VertexArray(VertexArray&& other) noexcept;
		VertexArray& operator=(VertexArray&& other) noexcept;

		void linkAttrib(uint32_t attribIndex, uint32_t size, uint32_t type, bool normalized, uint32_t relativeOffset) const noexcept;
		
		void bind() const;

		uint32_t getID() const { return m_id; }
	};
}

