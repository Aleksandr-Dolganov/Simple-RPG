#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 30;// Высота карты (в плитках 64*64 пикселя)
const int WIDTH_MAP = 30;// Ширина карты (в плитках 64*64 пикселя)
const int LAYERS = 2;// Количество слоев карты
// Базовая карта уровня (тестовая)
extern sf::String TileMap[LAYERS][HEIGHT_MAP];