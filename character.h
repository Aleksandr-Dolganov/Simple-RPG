#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Character
{
private:
	float Currentframe;// Текущий кадр анимации
	
	Vector2f m_Position;// Координаты персонажа
	Sprite m_Sprite;// Спрайт персонажа
	Texture m_Texture;// Текстуры персонажа
	// Переменные отслеживающие нажатия клавиш w, a, s, d.
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;

	float m_Speed;// Скорость персонажа
public:
	Character();// Конструктор
	int Health;
	Sprite getSprite();// Функция передачи спрайта персонажа в основной класс (engine)
	Vector2f getPos();// Функция передачи координат персонажа в основной класс (engine)
	// Функции движения
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// Функции остановки движения
	void stopLeft();
	void stopRight();
	void stopDown();
	void stopUp();

	void setY(float);// Установка координаты Y для персонажа
	void setX(float);// Установка координаты X для персонажа
	void setSpeed(float);// Установка скорости персонажа

	int dx();// Функция отслеживания куда двигался игрок по X (при >0 - вправо, при <0 - влево)
	int dy();// Функция отслеживания куда двигался игрок по Y (при >0 - вверх, при <0 - вниз)
	void updateCh(float elapsedTime);// Функция обновления персонажа (изменение кадров анимации и позиции персонажа)
	void randPos();
};