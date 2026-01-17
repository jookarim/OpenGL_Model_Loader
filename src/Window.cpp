#include "Window.h"
#include "Device.h"
#include <stdexcept>

namespace engine
{
    Window::Window(int width, int height, const char* title)
    {
        createWindow(width, height, title);
        m_device = std::make_unique<gl::Device>(m_window);
        
        m_device->makeCurrent();
    }

    Window::~Window() noexcept
    {
        destroyWindow();
    }

    void Window::createWindow(int width, int height, const char* title)
    {
        if (!glfwInit())
            throw std::runtime_error("GLFW init failed");

        m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!m_window)
        {
            glfwTerminate();
            throw std::runtime_error("Window creation failed");
        }
    }

    void Window::destroyWindow() noexcept
    {
        m_device.reset();

        if (m_window)
        {
            glfwDestroyWindow(m_window);
            m_window = nullptr;
        }

        glfwTerminate();
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(m_window);
    }

    void Window::pollEvents()
    {
        glfwPollEvents();
    }

    void Window::clear(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::swapBuffers() const
    {
        m_device->swapBuffers();
    }
}
