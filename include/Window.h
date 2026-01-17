#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <memory>

namespace engine
{
	namespace gl { class Device; }

	class Window
	{
	private:
		void createWindow(int width, int height, const char* title);
		void destroyWindow() noexcept;	
		GLFWwindow* m_window = nullptr;
		std::unique_ptr<gl::Device> m_device;
	public:
		Window(int width, int height, const char* title);
		~Window() noexcept;

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&&) = delete;

		void swapBuffers() const;

		bool shouldClose() const;
		void pollEvents();
		void clear(float r, float g, float b, float a);
	};
}