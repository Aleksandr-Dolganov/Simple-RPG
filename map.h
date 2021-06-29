#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 30;// ������ ����� (� ������� 64*64 �������)
const int WIDTH_MAP = 30;// ������ ����� (� ������� 64*64 �������)
const int LAYERS = 2;// ���������� ����� �����
// ������� ����� ������ (��������)
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