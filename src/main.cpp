#include <iostream>
#include "Window.h"

int main()
{
	engine::Window window(1270, 720, "Window");

	while (!window.shouldClose())
	{
		window.clear(1.f, 1.f, 0.f, 1.f);

		window.swapBuffers();
		window.pollEvents();
	}
}