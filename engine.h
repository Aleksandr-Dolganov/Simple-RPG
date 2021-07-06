#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <ctime>
#include <sstream>
#include <iostream>
#include "character.h"
#include "view.h"
#include "enemy.h"
#include "map.h"
using namespace sf;

struct Interface {
	Sprite Health;
	Sprite HealthCur;
	Texture Texture;
	Sprite Background;
	sf::Texture Widgets;
};

// Класс Движка игры
class Engine
{
private:
	Font font;// Шрифт для текста
	Text HealthText;// Отображение кол-ва здоровья
	Text GameTimeOver;// Отображение времени игры на окне проигрыша
	Text CloseWindow;// Подсказка закрытия игры
	Text CloseWindow2;// Подсказка рестарта игры
	Text GAMEOVER;// Заголовок окна проигрыша
	// Функция настройки тектов
	void initTexts();
	// Функция настройки текстов главного меню
	void initMMTexts(Text&, Text&, Text&);
	// Музыка
	Music GameMusic;
	Music MainMenuMusic;

	RenderWindow m_Window;// Экземпляр окна
	float CurrentWframe;// Текущий кадр анимации воды
	float zoomSpeed;// Скорость зума

	Sprite m_map;// Спрайт карты
	Sprite m_mapW;// Спрайт воды (с анимацией)
	Texture m_mapTexture;// Текстуры карты
	Texture m_mapWTexture;// Текстуры воды (с анимацией)

	Interface interface;

	Character m_Character;// Экземпляр персонажа
	Enemy e_Enemy;// Экземпляр врага

	// Функция отслеживания нажатия клавиш управления
	void input(float);
	// Функция для обновления персонажа
	void update(float);
	// Функция отрисовки карты (из файла view.h)
	void drawMap(float);
	// Функция рандомизации карты
	void randomMap();
	// Функция отвечающая за бой
	void battle();
	// Переменная готовности к бою 
	// (нужна для 0,5 секунд неуязвимости после получения урона)
	int ready;

	bool restart;// Переменная для рестарта игры
	// Экран проигрыша
	void GameOver(int&);
	// Работа игры
	void GameGoing(int&, Clock, Clock, Clock);
	// Главное меню
	void GameMainMenu();
public:
	// Конструктор
	Engine();
	// Деструктор
	~Engine();

	// Функция запуска игры
	void start();
};