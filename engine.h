#pragma once
#include <SFML\Graphics.hpp>
#include <ctime>
#include <sstream>
#include "character.h"
#include "view.h"
#include "enemy.h"
#include "map.h"
using namespace sf;

class Engine
{
private:
	Font font;
	Text HealthText;

	RenderWindow m_Window;// ����

	float CurrentWframe;// ������� ���� �������� ����

	float zoomSpeed;// �������� ����

	Sprite m_map;// ������ �����
	Sprite m_mapW;// ������ ���� (� ���������)
	Texture m_mapTexture;// �������� �����
	Texture m_mapWTexture;// �������� ���� (� ���������)

	Character m_Character;// ��������� ���������

	Enemy e_Enemy;

	void input(float);// ������� ������������ ������� ������ ����������

	void update(float);// ������� ��� ���������� ���������

	void drawMap(float);// ������� ��������� ����� (�� ����� view.h)
	void randomMap();// ������� ������������ �����

	void battle();
	int ready;
public:
	Engine();// �����������

	void start();// ������� ������� ����
};