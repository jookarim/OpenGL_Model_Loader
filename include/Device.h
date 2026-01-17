#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace engine::gl
{
	class Device
	{
	private:
		void createDevice(GLFWwindow* window);

		GLFWwindow* m_window = nullptr;

	public:
		explicit Device(GLFWwindow* window);
		~Device() noexcept = default;

		Device(const Device&) = delete;
		Device& operator=(const Device&) = delete;

		void makeCurrent() const;
		void swapBuffers() const;
	};
}
