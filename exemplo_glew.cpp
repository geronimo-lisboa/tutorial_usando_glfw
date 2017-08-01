#include <GL/glew.h>
#include <Windows.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "janela.h"

using namespace std;

shared_ptr<Janela> janela = nullptr;

int main(int argc, char** argv)
{
	try
	{
		janela = make_shared<Janela>(300, 300,
		[](){
		},
		[](){
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