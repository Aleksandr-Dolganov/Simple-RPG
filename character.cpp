#pragma once
#include "character.h"

Character::Character()
{
	// ????????? ???? ????????
	Currentframe = 0;
	// ????????? ????????
	Health = 20;
	// ????????? ????????
	m_Speed = 0;
	// ???????? ???????? ????????? (????? ?????????? ?? 64*64)
	m_Texture.loadFromFile("Textures/Character/male-1.png");
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(2, 2);
	m_Sprite.setTextureRect(IntRect(32, 0, 32, 32));
	// ????????? ??????????
	m_Position = Vector2f(0, 0);
	// ????????? ??????????? ? ???????? ?? ????
	dir = dx = dy = 0;
	BeforeBattlePos.x, BeforeBattlePos.y = 0;
}
Character::~Character() {
	std::cout << std::endl << std::endl
		<< "\t\tCharacter Destroyed" << std::endl << std::endl;
}

Vector2f Character::getPos() {
	return m_Position;
}
void Character::setPos(float x, float y) {
	m_Position.x = x;
	m_Position.y = y;
}
void Character::randPos() {
	int x = (rand() % 30), y = (rand() % 30);
	// ???????? ?? ?? ??? ???????? ?? ???????? ? ????? ? ????????? (?????? ? ?.?.)
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

void Character::setSpeed(float speed) {
	m_Speed = speed;
}
void Character::updateCh(float elapsedTime, bool DebugOffCollision)
{
	// ???????? ?????????
	switch (dir)
	{
	case 0: dx = m_Speed; dy = 0; break;// ???????? ??????
	case 1: dx = -m_Speed; dy = 0; break;// ???????? ?????
	case 2: dx = 0; dy = m_Speed; break;// ???????? ????
	case 3: dx = 0; dy = -m_Speed; break;// ???????? ?????
	}
	// ??????????? ????????? ?? ????? ??????????
	m_Position.x += dx * elapsedTime;
	m_Position.y += dy * elapsedTime;
	m_Speed = 0;
	m_Sprite.setPosition(m_Position);
	// ???????? ????????
	if (!DebugOffCollision) collision();
}

void Character::collision() {
	for (int i = (m_Position.y + 8) / 64; i < (m_Position.y + 56) / 64; i++) {
		for (int j = (m_Position.x + 8) / 64; j < (m_Position.x + 56) / 64; j++)
		{
			if (i >= 0 and j >= 0 and i < 30 and j < 30) {
				if (TileMap[0][i][j] == 'w'
					or TileMap[1][i][j] == 'C'
					or TileMap[1][i][j] == 't'
					or TileMap[1][i][j] == 'l'
					or TileMap[1][i][j] == 'L'
					or TileMap[1][i][j] == 'b')
				{
					if (dy > 0)
					{
						m_Position.y = i * 64 - 56;
					}
					if (dy < 0)
					{
						m_Position.y = i * 64 + 56;
					}
					if (dx > 0)
					{
						m_Position.x = j * 64 - 56;
					}
					if (dx < 0)
					{
						m_Position.x = j * 64 + 56;
					}
				}
			}
		}
	}
}