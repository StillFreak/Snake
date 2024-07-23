#include <chrono>
#include <thread>
#include <iostream>
#include <random>
#include <vector>
#include <ctime>

#pragma once
class Player
{
private:
	

public:
	int i_place = 5, j_place = 5, k = 0, spd = 800;
	bool game = true;
	int apple_place[2];
	std::vector <std::vector <int>> body;

	Player(std::vector <std::vector <int>> body = { {5, 5}, {6, 5} }) {
		this->body = body;
	}

	void LvlUp() {			//Поднятие уровня змейки (увеличение ее размера)
		spd -= 25;
		body.push_back({ body[body.size() - 1][0], body[body.size() - 1][1] });
	}

	void Apple_Spawn() {			//Случайный спавн яблока
		srand(time(0));
		int x = rand() % (9 - 0 + 1);
		int y = rand() % (9 - 0 + 1);
		apple_place[0] = x;
		apple_place[1] = y;

	}

	void Moving() {				//Передвижение змейки
		while (game)
		{
			if (i_place == 10 || j_place == 10 || i_place == -1 || j_place == -1) {
				break;
				game = false;
			}			
			if (k == 1) {
				i_place--;
				for (int i = body.size() - 1; i > 0; --i) {
					for (int j = 0; j < 2; ++j) {
						if (body[i][0] == i_place && body[i][1] == j_place) {
							game = false;
						}
						body[i][j] = body[i - 1][j];
					}
				}
				body[0] = { i_place, j_place };
				std::this_thread::sleep_for(std::chrono::milliseconds(spd));
			}
			else if (k == 2) {
				i_place++;
				for (int i = body.size() - 1; i > 0; --i) {
					for (int j = 0; j < 2; ++j) {
						if (body[i][0] == i_place && body[i][1] == j_place) {
							game = false;
						}
						body[i][j] = body[i - 1][j];
					}
				}
				body[0] = { i_place, j_place };
				std::this_thread::sleep_for(std::chrono::milliseconds(spd));
			}
			else if (k == 3){
				j_place--;
				for (int i = body.size() - 1; i > 0; --i) {
					for (int j = 0; j < 2; ++j) {
						if (body[i][0] == i_place && body[i][1] == j_place) {
							game = false;
						}
						body[i][j] = body[i - 1][j];
					}
				}
				body[0] = { i_place, j_place };
				std::this_thread::sleep_for(std::chrono::milliseconds(spd));				
			}
			else if (k == 4) {
				j_place++;
				for (int i = body.size() - 1; i > 0; --i) {
					for (int j = 0; j < 2; ++j) {
						if (body[i][0] == i_place && body[i][1] == j_place) {
							game = false;
						}
						body[i][j] = body[i - 1][j];
					}
				}
				body[0] = { i_place, j_place };
				std::this_thread::sleep_for(std::chrono::milliseconds(spd));
			}			
		}
	}
};

