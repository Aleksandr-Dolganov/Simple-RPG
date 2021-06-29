#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;

class Character
{
private:
	float Currentframe;// ������� ���� ��������
	
	Vector2f m_Position;// ���������� ���������
	Sprite m_Sprite;// ������ ���������
	Texture m_Texture;// �������� ���������
	// ���������� ������������� ������� ������ w, a, s, d.
	bool m_LeftPressed;
	bool m_RightPressed;
	bool m_UpPressed;
	bool m_DownPressed;

	float m_Speed;// �������� ���������
public:
	Character();// �����������
	int Health;
	Sprite getSprite();// ������� �������� ������� ��������� � �������� ����� (engine)
	Vector2f getPos();// ������� �������� ��������� ��������� � �������� ����� (engine)
	// ������� ��������
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	// ������� ��������� ��������
	void stopLeft();
	void stopRight();
	void stopDown();
	void stopUp();

	void setY(float);// ��������� ���������� Y ��� ���������
	void setX(float);// ��������� ���������� X ��� ���������
	void setSpeed(float);// ��������� �������� ���������

	int dx();// ������� ������������ ���� �������� ����� �� X (��� >0 - ������, ��� <0 - �����)
	int dy();// ������� ������������ ���� �������� ����� �� Y (��� >0 - �����, ��� <0 - ����)
	void updateCh(float elapsedTime);// ������� ���������� ��������� (��������� ������ �������� � ������� ���������)
	void randPos();
};