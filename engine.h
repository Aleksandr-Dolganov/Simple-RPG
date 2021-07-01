#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include <sstream>
#include "character.h"
#include "view.h"
#include "enemy.h"
#include "map.h"
using namespace sf;

class Engine
{
private:
	Font font;
	Text HealthText;
	Text GameTimeOver;
	Text CloseWindow;
	Text CloseWindow2;
	Text GAMEOVER;

	RenderWindow m_Window;// Окно

	float CurrentWframe;// Текущий кадр анимации воды

	float zoomSpeed;// Скорость зума

	Sprite m_map;// Спрайт карты
	Sprite m_mapW;// Спрайт воды (с анимацией)
	Texture m_mapTexture;// Текстуры карты
	Texture m_mapWTexture;// Текстуры воды (с анимацией)

	Character m_Character;// Экземпляр персонажа

	Enemy e_Enemy;

	void input(float);// Функция отслеживания нажатия клавиш управления

	void update(float);// Функция для обновления персонажа

	void drawMap(float);// Функция отрисовки карты (из файла view.h)
	void randomMap();// Функция рандомизации карты

	void battle();
	int ready;

	bool restart;

	void GameOver(int&);
	void GameGoing(int&, Clock, Clock, Clock);
	void GameMainMenu();

public:
	Engine();// Конструктор

	void start();// Функция запуска игры
};