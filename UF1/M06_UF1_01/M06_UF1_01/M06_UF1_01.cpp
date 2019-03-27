// M06_UF1_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>
#include <fstream>
#include <string>


std::string* textures;
std::string* levels;


int loadTextures(std::ifstream& file, int num_texture)
{
	std::string word;
	
	textures = new std::string[num_texture + 1];
	textures[0] = "none";

	int counter = 1;
	
	while (counter != num_texture + 1)
	{
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << std::endl;

		std::getline(file, word, '\n');

		counter++;
	}

	return 0;
}



int loadLevels(std::ifstream& file, int num_level)
{
	//interpretar los bloques de los dos niveles implementados
	std::string palabra;
	int n_filas;
	int n_columnas;

	levels = new std::string[num_level + 1];
	levels[0] = "none";

	int counter = 1;

	while(counter != num_level + 1) {
		std::getline(file, palabra, ';');
		std::getline(file, palabra, ';');
		std::getline(file, palabra, ';');
		levels[counter] = palabra;
		std::cout << "Nombre del nivel: ";
		std::cout << palabra;

		std::getline(file, palabra, ';');
		n_columnas = std::stoi(palabra);
		std::cout << "Numero de columnas: ";
		std::cout << palabra;

		std::getline(file, palabra, ';');
		n_filas = std::stoi(palabra);
		std::cout << "Numero de filas: ";
		std::cout << palabra << std::endl;
		
		std::getline(file, palabra, ';');
		std::getline(file, palabra, '\n');

		std::getline(file, palabra, ';');

		if (palabra.compare("BACKGROUND") == 0)
		{
			std::cout << palabra << std::endl;
			std::getline(file, palabra, '\n');
			for (int i = 0; i < 8; i++)
			{
				std::getline(file, palabra, '\n');
				std::cout << palabra << std::endl;
				i;
			}
		}
		std::getline(file, palabra, ';');
		if (palabra.compare("COLLISIONS") == 0)
		{
			std::cout << palabra << std::endl;
			std::getline(file, palabra, '\n');
			for (int i = 0; i < 8; i++)
			{
				std::getline(file, palabra, '\n');
				std::cout << palabra << std::endl;
				i;
			}
		}
		std::getline(file, palabra, ';');
		if (palabra.compare("FOREGROUND") == 0)
		{
			std::cout << palabra << std::endl;
			std::getline(file, palabra, '\n');
			for (int i = 0; i < 8; i++)
			{
				std::getline(file, palabra, '\n');
				std::cout << palabra << std::endl;
				i;
			}
		}

		counter++;
	}

	return 0;
}




int main(int argc, char* argv[])
{

	std::ifstream game_setup("../M06_UF1_01/game.csv");

	if (!game_setup.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	std::string title;
	//std::string level;
	
	int levels_n = 0;
	int textures_n = 0;

	while (game_setup.good())
	{
		std::getline(game_setup, word, ';');

		if (word.compare("TEXTURES") == 0)
		{
			std::getline(game_setup, word, ';');
			textures_n = std::stoi(word);
			std::cout << "Numero de texturas: ";
			std::cout << word << std::endl;
			std::getline(game_setup, word, '\n');
			

			loadTextures(game_setup, textures_n);
			
		}
		else if (word.compare("TITLE") == 0)
		{
			std::getline(game_setup, title, ';');
			std::getline(game_setup, word, '\n');

			std::cout << title << std::endl;
		}
		else if (word.compare("LEVELS") == 0)
		{
			std::getline(game_setup, word, ';');
			levels_n = std::stoi(word);
			std::cout << "Numero de niveles: ";
			std::cout << word << std::endl;
			std::getline(game_setup, word, '\n');
			
			
			loadLevels(game_setup, levels_n);

		}
	}

	game_setup.close();

	
}


