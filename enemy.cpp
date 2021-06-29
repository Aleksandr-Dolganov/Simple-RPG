#pragma once
#include "enemy.h"
#include <ctime>
#include "map.h"

Enemy::Enemy() {
	srand(time(0));
	CurrentEframe = 0;
	Health = 20;
	e_Texture.loadFromFile("Textures/Enemy/bat_texture.png");
	e_Sprite.setTexture(e_Texture);
	e_Sprite.setScale(4, 4);
	e_Sprite.setTextureRect(IntRect(0, 24, 16, 24));

	e_Position = Vector2f(0, 0);
}
Sprite Enemy::getSprite()
{
	return e_Sprite;
}
void Enemy::updateEn(float elapsedTime)
{
	e_Sprite.setPosition(e_Position);
	CurrentEframe += 0.009 * elapsedTime;
	if (CurrentEframe > 5) CurrentEframe -= 5;
	e_Sprite.setTextureRect(IntRect(16 * int(CurrentEframe), 24, 16, 24));

}

void Enemy::randPos() {
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
	e_Position = Vector2f(x * 64, y * 64);
}