#pragma once
#include <SFML\Graphics.hpp>

const int HEIGHT_MAP = 30;// ������ ����� (� ������� 64*64 �������)
const int WIDTH_MAP = 30;// ������ ����� (� ������� 64*64 �������)
const int LAYERS = 2;// ���������� ����� �����
// ������� ����� ������ (��������)
extern sf::String TileMap[LAYERS][HEIGHT_MAP];