#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <ctime>
#include <sstream>
#include <iostream>
#include "character.h"
#include "view.h"
#include "enemy.h"
#include "map.h"
using namespace sf;

struct Interface {
	Sprite Health;
	Sprite HealthCur;
	Texture Texture;
	Sprite Background;
	sf::Texture Widgets;
};

// ����� ������ ����
class Engine
{
private:
	Font font;// ����� ��� ������
	Text HealthText;// ����������� ���-�� ��������
	Text GameTimeOver;// ����������� ������� ���� �� ���� ���������
	Text CloseWindow;// ��������� �������� ����
	Text CloseWindow2;// ��������� �������� ����
	Text GAMEOVER;// ��������� ���� ���������
	// ������� ��������� ������
	void initTexts();
	// ������� ��������� ������� �������� ����
	void initMMTexts(Text&, Text&, Text&);
	// ������
	Music GameMusic;
	Music MainMenuMusic;

	RenderWindow m_Window;// ��������� ����
	float CurrentWframe;// ������� ���� �������� ����
	float zoomSpeed;// �������� ����

	Sprite m_map;// ������ �����
	Sprite m_mapW;// ������ ���� (� ���������)
	Texture m_mapTexture;// �������� �����
	Texture m_mapWTexture;// �������� ���� (� ���������)

	Interface interface;

	Character m_Character;// ��������� ���������
	Enemy e_Enemy;// ��������� �����

	// ������� ������������ ������� ������ ����������
	void input(float);
	// ������� ��� ���������� ���������
	void update(float);
	// ������� ��������� ����� (�� ����� view.h)
	void drawMap(float);
	// ������� ������������ �����
	void randomMap();
	// ������� ���������� �� ���
	void battle();
	// ���������� ���������� � ��� 
	// (����� ��� 0,5 ������ ������������ ����� ��������� �����)
	int ready;

	bool restart;// ���������� ��� �������� ����
	// ����� ���������
	void GameOver(int&);
	// ������ ����
	void GameGoing(int&, Clock, Clock, Clock);
	// ������� ����
	void GameMainMenu();
public:
	// �����������
	Engine();
	// ����������
	~Engine();

	// ������� ������� ����
	void start();
};