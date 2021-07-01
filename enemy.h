#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include "map.h"
using namespace sf;

class Enemy
{
private:
	float CurrentEframe;// Текущий кадр анимации врага
	Vector2f e_Position;// Позиция врага
	Sprite e_Sprite;// Спрайт врага
	Texture e_Texture;// Текстура врага
	int Health;// Здоровье врага
public:
	// Конструктор
	Enemy();
	// Деструктор
	~Enemy();
	// Передача спрайта врага в главную функцию
	Sprite getSprite();
	// Обновление врага
	void updateEn(float);
	// Рандомизирование позиции врага
	void randPos();
};