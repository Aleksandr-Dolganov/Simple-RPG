#pragma once
#include <SFML\Graphics.hpp>
// Камера
static sf::View Cam;
// Функция управления камерой (слежение за игроком)
inline void moveCam(float x, float y) {
	float x1 = x, y1 = y;

	if (x1 < 224) x1 = 224;
	if (y1 < 240) y1 = 240;
	if (x1 > 1632) x1 = 1632;
	if (y1 > 1648) y1 = 1648;

	Cam.setCenter(x1 + 32, y1 + 16);
}