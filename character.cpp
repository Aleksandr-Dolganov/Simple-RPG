#pragma once
#include "character.h"
#include "map.h"

Character::Character()
{
	Currentframe = 0;
	Health = 20;
	m_Speed = 0.2;
	// «адаем текстуры дл€ спрайта персонажа
	m_Texture.loadFromFile("Textures/Character/male-1.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(2, 2); // ”величение размера спрайта в 2 раза (теперь 64*64 п.)
	m_Sprite.setTextureRect(IntRect(32, 0, 32, 32));
	// Ќачальные координаты персонажа
	m_Position = Vector2f(0, 0);

	m_DownPressed = false;
	m_UpPressed = false;
	m_RightPressed = false;
	m_LeftPressed = false;
}

Sprite Character::getSprite()
{
	return m_Sprite;
}
Vector2f Character::getPos() {
	return m_Position;
}

void Character::moveLeft()
{
	m_LeftPressed = true;
}
void Character::moveRight()
{
	m_RightPressed = true;
}
void Character::moveUp()
{
	m_UpPressed = true;
}
void Character::moveDown()
{
	m_DownPressed = true;
}

void Character::stopLeft()
{
	m_LeftPressed = false;
	m_Sprite.setTextureRect(IntRect(32, 32, 32, 32));
}
void Character::stopRight()
{
	m_RightPressed = false;
	m_Sprite.setTextureRect(IntRect(32, 64, 32, 32));
}
void Character::stopDown()
{
	m_DownPressed = false;
	m_Sprite.setTextureRect(IntRect(32, 0, 32, 32));
}
void Character::stopUp()
{
	m_UpPressed = false;
	m_Sprite.setTextureRect(IntRect(32, 96, 32, 32));
}

void Character::setX(float x) {
	m_Position.x = x;
}
void Character::setY(float y) {
	m_Position.y = y;
}
void Character::setSpeed(float speed) {
	m_Speed = speed;
}

int Character::dx() {
	if (m_RightPressed) return 1;
	else if (m_LeftPressed) return -1;
	else return 0;
}
int Character::dy() {
	if (m_UpPressed) return 1;
	else if (m_DownPressed) return -1;
	else return 0;
}
void Character::updateCh(float elapsedTime)
{
	if (m_RightPressed)
	{
		Currentframe += 0.005 * elapsedTime;
		if (Currentframe > 3) Currentframe -= 3;
		m_Sprite.setTextureRect(IntRect(32 * int(Currentframe), 64, 32, 32));
		m_Position.x += m_Speed * elapsedTime;
	}
	else if (m_LeftPressed)
	{
		Currentframe += 0.005 * elapsedTime;
		if (Currentframe > 3) Currentframe -= 3;
		m_Sprite.setTextureRect(IntRect(32 * int(Currentframe), 32, 32, 32));
		m_Position.x -= m_Speed * elapsedTime;
	}
	else if (m_UpPressed)
	{
		Currentframe += 0.005 * elapsedTime;
		if (Currentframe > 3) Currentframe -= 3;
		m_Sprite.setTextureRect(IntRect(32 * int(Currentframe), 96, 32, 32));
		m_Position.y -= m_Speed * elapsedTime;
	}
	else if (m_DownPressed)
	{
		Currentframe += 0.005 * elapsedTime;
		if (Currentframe > 3) Currentframe -= 3;
		m_Sprite.setTextureRect(IntRect(32 * int(Currentframe), 0, 32, 32));
		m_Position.y += m_Speed * elapsedTime;
	}

	m_Sprite.setPosition(m_Position);
}

void Character::randPos() {
	int x = (rand() % 30), y = (rand() % 30);
	while (TileMap[0][y][x] == 'w'
		or TileMap[1][y][x] == 'C'
		or TileMap[1][y][x] == 't'
		or TileMap[1][y][x] == 'b'
		or TileMap[1][y][x] == 'l'
		or TileMap[1][y][x] == 'L') {
		x = (rand() % 30);
		y = (rand() % 30);
	}
	m_Position = Vector2f(x * 64, y * 64);
}