#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 30;// Высота карты (в плитках 64*64 пикселя)
const int WIDTH_MAP = 30;// Ширина карты (в плитках 64*64 пикселя)
const int LAYERS = 2;// Количество слоев карты
// Базовая карта уровня (тестовая)
static sf::String TileMap[LAYERS][HEIGHT_MAP] = {
	{
		"gggggggggggggggggggggggggggggg",
		"ggggggggggwwgggggggggggggggggg",
		"gggggggggwwwwggggggggggggggggg",
		"ggggggggwwwwwwgggggggggggggggg",
		"ggggggggwwwwwwgggggggggggggggg",
		"gggggggggwwwwggggggggggggggggg",
		"ggggggggggwwgggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg",
		"gggggggggggggggggggggggggggggg"
	},
	{
		"                              ",
		"    tC   y       b            ",
		"    CC                 b      ",
		"    b b         tCtC          ",
		"      y         CCCC   tC     ",
		"    b          b       CC     ",
		"     b                  b     ",
		"           y   y   b          ",
		"         b                    ",
		"   b            tC     b      ",
		"        b       CC b          ",
		"     tC      tC               ",
		"     CC      CC       tC      ",
		"    b  y     b  y     CC      ",
		"                    tC    y   ",
		"     tC    b        CC b      ",
		"     CC            y     b    ",
		"    b        tC               ",
		"       b     CC b     b       ",
		"    y                         ",
		"           b         b        ",
		"    tC                        ",
		"    CC         tC       tC    ",
		"  b     y      CC   b   CC    ",
		"    tC                        ",
		"    CC        b               ",
		"   b     b               tC   ",
		"   b               tC    CC   ",
		"             y     CC   b     ",
		"                              "
	}
};