#include "janela.h"
#include <sstream>

Janela::Janela(int width, int height, std::function<void()> _init, std::function<void()> _render)
{
	this->isInicializado = false;
	this->initCallback = _init;
	this->renderCallback = _render;
	glfwSetErrorCallback([](int error, const char* description) {
		std::stringstream ss;
		ss << "Erro: " << error << " : " << description;
		throw std::exception(ss.str().c_str());
	});
	//Se falhou em iniciar, morre
	if (!glfwInit()) { throw std::exception("Falha no glfwInit(). Tem algo MUITO errado acontecendo"); }
	//OpenGL 3.2
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	window = glfwCreateWindow(width, height, "BOA NOITE", NULL, NULL);//A criação da janela é aqui
	if (!window)//Se falhou em criar a janela, morre.
	{
		glfwTerminate();
		throw std::exception("Não foi possivel criar a janela");
	}

	glfwMakeContextCurrent(window);
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* A fonte de erro mais comum é tentar iniciar a glew sem ter um contexto opengl funcionando,
		sem ter a tela ativa.*/
		std::stringstream ss;
		ss << "Erro de glew: " << glewGetErrorString(err);
		throw std::exception(ss.str().c_str());
	}
	//O makeCurrent() da glfw
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}
Janela::~Janela()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
void Janela::Render()
{
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		if (!isInicializado)
		{
			initCallback();
			isInicializado = true;
		}
		else
		{
			renderCallback();
		}
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}