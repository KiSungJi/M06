// M06_UF1_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>
#include <fstream>
#include <string>

std::string word;
std::string* textures;
std::string* levels;
int levels_n = 0;
int textures_n = 0;

struct level {

	std::string title;
	int number;
	int width;
	int height;
	int** background;
	std::string** collisions;
	int** foreground;
};


int loadTextures(std::ifstream& file, int num_texture)
{
	
	
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

level* niveles;

int loadBackground(std::ifstream& file, int level_num, int width, int height)
{
	std::getline(file, word, '\n');
	int value = -1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::getline(file, word, ';');
			value = std::stoi(word);
			
			niveles[level_num].background[i][j] = value;

			std::cout << value;
		}
		std::cout << '\n';

		std::getline(file, word, '\n');
		
	}
	std::getline(file, word, '\n');
	return 0;
}

int loadForeground(std::ifstream& file, int level_num, int width, int height)
{

	int value = -1;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::getline(file, word, ';');
			value = std::stoi(word);

			niveles[level_num].foreground[i][j] = value;

			std::cout << value;
		}
		std::cout << '\n';

		std::getline(file, word, '\n');
	}
	return 0;
}

int loadCollisions(std::ifstream& file, int level_num, int width, int height)
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			std::getline(file, word, ';');
			niveles[level_num].collisions[i][j] = word;

			std::cout << word;
		}
		std::cout << '\n';

		std::getline(file, word, '\n');
	}
	return 0;
}


int loadLevels(std::ifstream& file, int num_level)
{
	niveles = new level[num_level + 1];
	niveles[0].title = "none";

			
	
	std::cout << word << std::endl;
	//std::getline(file, word, ';');

	for (int i = 0; i < num_level; i++)
	{
		std::getline(file, word, ';');
		if (word.compare("LEVEL") != 0)
		return 1;
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		std::cout << "Nombre del nivel: ";
		std::cout << word;

		std::getline(file, word, ';');
		niveles[i].height = std::stoi(word);
		std::cout << "Numero de columnas: ";
		std::cout << word;
		
		std::getline(file, word, ';');
		niveles[i].width = std::stoi(word);
		std::cout << "Numero de filas: ";
		std::cout << word << std::endl;
		
		std::getline(file, word, ';');
		std::getline(file, word, '\n');

		std::getline(file, word, ';');



		niveles[i].background = new int*[niveles[i].height];
		niveles[i].collisions = new std::string*[niveles[i].height];
		niveles[i].foreground = new int*[niveles[i].height];


		for (int j = 0; j < niveles[i].width; j++)
		{
			niveles[i].background[j] = new int[niveles[i].width];
			niveles[i].collisions[j] = new std::string[niveles[i].width];
			niveles[i].foreground[j] = new int[niveles[i].width];
		}

		for (int k = 0; k < 3; k++)
		{
			//std::getline(file, word, ';');
			std::string block = word;
			//std::getline(file, word, '\n');

			std::cout << block << '\n';

			if (word.compare("BACKGROUND") == 0)
			{
				loadBackground(file, i, niveles[i].height, niveles[i].width);
			}
			else if (word.compare("COLLISIONS") == 0)
			{
				loadCollisions(file, i, niveles[i].height, niveles[i].width);
			}
			else if (word.compare("FOREGROUND") == 0)
			{
				loadForeground(file, i, niveles[i].height, niveles[i].width);
			}
		}

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

	std::string title;
	
	

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


