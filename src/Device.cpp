#include "Device.h"

#include <stdexcept>
#include <iostream>

namespace gl
{
	Device::Device(GLFWwindow* window)
	{
		createDevice(window);
	}

	void Device::createDevice(GLFWwindow* window)
	{
		if (!window)
			throw std::runtime_error("gl::Device: GLFWwindow is null");

		m_window = window;

		glfwMakeContextCurrent(m_window);

		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
			throw std::runtime_error("Failed to initialize GLEW");
	}

	void Device::makeCurrent() const
	{
		glfwMakeContextCurrent(m_window);
	}

	void Device::swapBuffers() const
	{
		glfwSwapBuffers(m_window);
	}
}
