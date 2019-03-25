// M06_UF1_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"

#include <iostream>
#include <fstream>
#include <string>


std::string* textures;


int loadTextures(std::ifstream& file, int num_texture)
{
	std::string word;
	
	textures = new std::string[num_texture + 1];
	textures[0] = "none";

	int counter = 1;
	
	while (counter == num_texture + 1)
	{
		std::getline(file, word, ';');
		std::getline(file, word, ';');
		textures[counter] = word;
		std::cout << word << '\n';

		std::getline(file, word, ';');

		counter++;
	}
	return 0;
}

std::string levels;

int loadLevels(std::ifstream& file, int num_level)
{
	//interpretar los bloques de los dos niveles implementados
	std::string word;

	//levels = new std:string[num_level + 1];
}


int main(int argc, char* argv[])
{

	std::ifstream game_setup("../M06_UF1_01/game.csv");

	if (!game_setup.is_open)
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string word;
	std::string title;
	std::string level;
	int levels_n = 0;
	int textures_n = 0;

	while (game_setup.good())
	{
		std::getline(game_setup, word, ';');

		if (word.compare("TEXTURES") == 0)
		{
			std::getline(game_setup, word, ';');
			textures_n = std::stoi(word);
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
			std::getline(game_setup, level, ';');
			std::getline(game_setup, word, '\n');

			loadLevels(game_setup, levels_n);

		}
	}

	game_setup.close();

	/*std::ofstream archivo;

	archivo.open("datos.csv");

	archivo << "a;b;c;\n";
	archivo << "d;e;f;\n";
	archivo << "1;2;3.456;\n";
	archivo.close();

	return 0;

	std::ifstream ip("../M06_UF1_01/Personas.csv");

	if (!ip.is_open())
	{
		std::cout << "ERROR: Error al abrir el archivo" << '\n';
		return 1;
	}

	std::string nombre;
	std::string apellido;
	std::string edad;
	std::string peso;

	int edadi;
	float pesof;

	while (ip.good())
	{
		std::getline(ip, nombre, ';');
		std::getline(ip, apellido, ';');
		std::getline(ip, edad, ';');
		std::getline(ip, peso, '\n');

		edadi = std::stoi(edad);
		pesof = std::stoi(peso);

		std::cout << "Nombre: " << nombre << " " << apellido << '\n';
		std::cout << "Edad: " << edad << '\n';
		std::cout << "Peso: " << peso << '\n';
		std::cout << "============================" << '\n';

		
	}

	ip.close();*/
}


