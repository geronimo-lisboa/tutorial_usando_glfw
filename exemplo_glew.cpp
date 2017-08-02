#include <GL/glew.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "janela.h"
#include "shader.h"

using namespace std;



int main(int argc, char** argv)
{
	shared_ptr<Janela> janela = nullptr;
	shared_ptr<Shader> shader = nullptr;
	try
	{
		janela = make_shared<Janela>(300, 300,
		[&shader](){
			shader = make_shared<Shader>("C:\\programacao\\tutorial_usando_glfw\\vertexShader.glsl",
				"C:\\programacao\\tutorial_usando_glfw\\fragmentShader.glsl");
		},

		[&shader](){
			
		});
		janela->Render();
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