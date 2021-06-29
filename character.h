#pragma once
#include <SFML\Graphics.hpp>
#include "map.h"
using namespace sf;

class Character
{
private:
	Vector2f m_Position;// Координаты персонажа
	
	Texture m_Texture;// Текстуры персонажа
	// Переменные отслеживающие нажатия клавиш w, a, s, d.
	

	float m_Speed;// Скорость персонажа
public:
	float dx, dy;
	float Currentframe;// Текущий кадр анимации
	Sprite m_Sprite;// Спрайт персонажа
	Character();// Конструктор
	int dir;
	int Health;
	Sprite getSprite();// Функция передачи спрайта персонажа в основной класс (engine)
	Vector2f getPos();// Функция передачи координат персонажа в основной класс (engine)

	void setY(float);// Установка координаты Y для персонажа
	void setX(float);// Установка координаты X для персонажа
	void setSpeed(float);// Установка скорости персонажа

	void updateCh(float elapsedTime);// Функция обновления персонажа (изменение кадров анимации и позиции персонажа)
	void randPos();
	void collision();
};