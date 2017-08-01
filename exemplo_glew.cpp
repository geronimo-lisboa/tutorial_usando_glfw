#include <GL/glew.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <stdlib.h>

using namespace std;
const int screenWidth = 400;
const int screenHeight = 400;
GLFWwindow *window;
bool isInitialized;
int main(int argc, char** argv)
{
	try
	{
		//Seta o callback de erros da GLFW
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
		window = glfwCreateWindow(screenWidth, screenHeight, "BOA NOITE", NULL, NULL);//A criação da janela é aqui
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
		isInitialized = false;

		while (!glfwWindowShouldClose(window))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			//O callback de inicialização
			isInitialized = true;
			//O callback de render
			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glfwDestroyWindow(window);
		glfwTerminate();

		exit(EXIT_SUCCESS);
	}
	catch (std::exception &ex)
	{
		std::cout << "Erro : " << ex.what() << endl;
		std::cout << "Pressione qqer tecla para continuar...";
		getchar();
		exit(EXIT_FAILURE);
	}

}