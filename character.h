#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "map.h"
using namespace sf;

class Character
{
private:
	Vector2f m_Position;// Координаты персонажа
	Texture m_Texture;// Текстуры персонажа
	float m_Speed;// Скорость персонажа
	void collision();// Коллизия (столкновения с картой)
public:
	Character();// Конструктор
	~Character();// Деструктор
	float dx, dy;// Скорость персонажа по осям
	float Currentframe;// Текущий кадр анимации
	int dir;// Направление персонажа
	int BeforeBattleDir;
	int Health;// Здоровье персонажа
	Sprite m_Sprite;// Спрайт персонажа

	Vector2f getPos();// Функция передачи координат персонажа в основной класс (engine)
	Vector2f BeforeBattlePos;
	void setPos(float x, float y);// Установка координат для персонажа
	void setSpeed(float);// Установка скорости персонажа

	void updateCh(float elapsedTime, bool DebugOffCollision);// Функция обновления персонажа (изменение кадров анимации и позиции персонажа)
	void randPos();// Случайная позиция персонажа
};