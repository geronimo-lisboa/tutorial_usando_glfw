#pragma once
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <functional>

class Janela
{
private:
	std::function<void()> initCallback;
	std::function<void()> renderCallback;
	GLFWwindow *window;
	bool isInicializado;
public:
	Janela(int width, int height, std::function<void()> _init, std::function<void()> _render);
	~Janela();
	void Render();
};