#include <iostream>
#include <vector>
#include <conio.h>
#include <thread>
#include <chrono>
#include "Player.h"


Player snake;

void key_detect() {             //Функция определения нажатой клавиши
	while (snake.game)
	{
		if (snake.i_place == 10 || snake.j_place == 10) {
			break;
		}
		char key = _getch();
		if (key == 0x48) {
			snake.k = 1;
		}
		else if (key == 0x50) {
			snake.k = 2;
		}
		else if (key == 0x4B) {
			snake.k = 3;
		}
		else if (key == 0x4D) {
			snake.k = 4;
		}
	}
}

void Map_Draw() {							//Отрисовка карты
	std::vector <std::vector <char>> map(10, std::vector <char>(10, '.'));
	snake.Apple_Spawn();
	
	while (snake.game) {		
		if (snake.i_place == 10 || snake.j_place == 10) {
			break;
		}
		std::vector <std::vector <char>> map(10, std::vector <char>(10, '.'));
		map[snake.apple_place[0]][snake.apple_place[1]] = '0';
		if (snake.i_place == 10 || snake.j_place == 10) {
			snake.game = false;
		}

		for (int i = 0; i < snake.body.size() - 1; ++i) {
			map[snake.body[i][0]][snake.body[i][1]] = '8';
		}
		

		if (map[snake.i_place][snake.j_place] == map[snake.apple_place[0]][snake.apple_place[1]]) {
			snake.LvlUp();
			snake.Apple_Spawn();
			map[snake.apple_place[0]][snake.apple_place[1]] = '0';
		}


		for (size_t i = 0; i < 10; ++i) {
			for (size_t j = 0; j < 10; ++j) {
				std::cout << map[i][j] << ' ';
			}
			std::cout << '\n';
		}
		std::this_thread::sleep_for(std::chrono::milliseconds (snake.spd));
		system("cls");
		
	}
}

int main() {
	std::thread thr(key_detect);                //Создание отдельных потоков для функций
	std::thread draw(Map_Draw);

	snake.Moving();

	thr.detach();
	draw.detach();

	std::cout << "Game over";
	return 0;
}