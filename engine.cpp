#pragma once
#include "engine.h"

Engine::Engine()
{
	// Рандомим карту и положение персонажа/врага
	srand(time(0));
	randomMap();
	m_Character.randPos();
	e_Enemy.randPos();
	// Начальный кадр анимации воды
	CurrentWframe = 0;
	// Разрешение окна 512*512
	Vector2f resolution;
	resolution.x = 512;
	resolution.y = 512;
	// Создаем окно с параметрами
	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Simple 2D Rpg Project by Sam W.");
	// Начальная скорость зума
	zoomSpeed = 1;
	// Центр карты на позиции игрока
	Cam.setCenter(m_Character.getPos().x + 32, m_Character.getPos().y + 16);
	// Загружаем текстуры карты в спрайт 
	// (и увеличиваем размер до 64*64 (текстуры 32*32))
	Image m_mapImage;
	m_mapImage.loadFromFile("Textures/Background/bgTileset.png");
	m_mapImage.createMaskFromColor(Color::White, 0);
	m_mapTexture.loadFromImage(m_mapImage);
	m_map.setTexture(m_mapTexture);
	m_map.setScale(2, 2);
	// Загружаем текстуры воды в спрайт 
	// (и увеличиваем размер до 64*64 (текстуры 32*32))
	Image m_mapWImage;
	m_mapWImage.loadFromFile("Textures/Background/bgWTileset.png");
	m_mapWImage.createMaskFromColor(Color::White, 0);
	m_mapWTexture.loadFromImage(m_mapWImage);
	m_mapW.setTexture(m_mapWTexture);
	m_mapW.setScale(2, 2);
	Image InterfaceTexture, Widgets;
	InterfaceTexture.loadFromFile("Textures/Interface/icons.png");
	Widgets.loadFromFile("Textures/Interface/widgets.png");
	InterfaceTexture.createMaskFromColor(Color::White, 0);
	Widgets.createMaskFromColor(Color::White, 0);
	interface.Texture.loadFromImage(InterfaceTexture);
	interface.Widgets.loadFromImage(Widgets);
	interface.Background.setTexture(interface.Widgets);
	interface.Background.setTextureRect(IntRect(0, 66, 200, 19));
	interface.Background.setScale(0.98, 3);
	interface.Health.setTexture(interface.Texture);
	interface.Health.setTextureRect(IntRect(0, 84, 182, 5));
	interface.Health.setScale(1, 3);
	interface.HealthCur.setTexture(interface.Texture);
	interface.HealthCur.setScale(1, 3);
	// Готовность к бою
	ready = 1;
	// Рестарт запрещен
	restart = false;
	// Инициализация текстов
	initTexts();
	// Загрузка файла музыки
	GameMusic.openFromFile("Media/Music/Wynncraft - Triumphant Citadel.ogg");
	GameMusic.setLoop(true);
	GameMusic.setVolume(50);
	MainMenuMusic.openFromFile("Media/Music/Wynncraft - Understated Pride.ogg");
	MainMenuMusic.setLoop(true);
	MainMenuMusic.setVolume(50);
}
Engine::~Engine() {
	std::cout << std::endl << std::endl
		<< "\t\tGame Closed" << std::endl << std::endl;
}

void Engine::initTexts() {
	font.loadFromFile("Textures/Fonts/Kingthings Petrock.ttf");
	HealthText.setFont(font);
	GameTimeOver.setFont(font);
	CloseWindow.setFont(font);
	CloseWindow2.setFont(font);
	HealthText.setCharacterSize(30);
	GameTimeOver.setCharacterSize(70);
	CloseWindow.setCharacterSize(75);
	CloseWindow2.setCharacterSize(75);
	HealthText.setFillColor(Color::Red);
	GameTimeOver.setFillColor(Color::White);
	CloseWindow.setFillColor(Color::White);
	CloseWindow.setString("Press \"Space\" to close game.");
	CloseWindow2.setFillColor(Color::White);
	CloseWindow2.setString("Press \"R\" to restart game.");
	GAMEOVER.setFont(font);
	GAMEOVER.setCharacterSize(100);
	GAMEOVER.setFillColor(Color::White);
	GAMEOVER.setString("You died");
	GAMEOVER.setPosition(310, 0);
}
void Engine::initMMTexts(Text& GameName, Text& Author, Text& PressSpace) {
	GameName.setFont(font);
	GameName.setFillColor(Color::White);
	GameName.setCharacterSize(100);
	GameName.setString("Simple RPG");
	GameName.setPosition(300, 0);
	Author.setFont(font);
	Author.setFillColor(Color::White);
	Author.setCharacterSize(70);
	Author.setString("By Sam Wilde");
	Author.setPosition(400, 100);
	PressSpace.setFont(font);
	PressSpace.setFillColor(Color::White);
	PressSpace.setCharacterSize(70);
	PressSpace.setString("Press \"Space\" to start game.");
	PressSpace.setPosition(120, 900);
}

void Engine::start()
{
	// Таймеры
	Clock clock, cooldown, GameTime;
	int GameTimeInSec = 0;
	restart = false;
	// Запускаем главное меню
	GameMainMenu();
	// Начальный зум камеры
	Cam.setSize(512, 512);
	// Работа игры
	GameGoing(GameTimeInSec, GameTime, clock, cooldown);
	// Окно проигрыша
	GameOver(GameTimeInSec);
	// Закрытие окна
	m_Window.close();
	// Если мы нажали restart, то запускаем новый движок
	if (restart) Engine().start(); restart = false;
}

void Engine::input(float elapsedTime)
{
	// Выход из игры если нажат "Escape"
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Character.Health = -5;
		GAMEOVER.setString("Game closed");
		GAMEOVER.setPosition(256, 0);
	}
	// Тестовый телепорт в середину клетки
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		int x = (m_Character.getPos().x + 32) / 64, y = (m_Character.getPos().y + 32) / 64;
		m_Character.setX(x * 64);
		m_Character.setY(y * 64);
	}
	// Ускорение зума
	if (Keyboard::isKeyPressed(Keyboard::LShift)) {
		zoomSpeed = 5;
	}
	else {
		zoomSpeed = 1;
	}
	// Движение на WASD
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		if (m_Character.getPos().x > 0) {
			m_Character.dir = 1;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) {
				m_Character.setSpeed((float)0.4);
			}
			else {
				m_Character.setSpeed((float)0.2);
			}
			m_Character.Currentframe += 0.005 * elapsedTime;
			if (m_Character.Currentframe > 3) m_Character.Currentframe -= 3;
			m_Character.m_Sprite.setTextureRect(IntRect(32 * int(m_Character.Currentframe), 32, 32, 32));
			moveCam(m_Character.getPos().x, m_Character.getPos().y);
		}
	}
	else if (m_Character.dx < 0) {
		m_Character.m_Sprite.setTextureRect(IntRect(32, 32, 32, 32));
	}
	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		if (m_Character.getPos().x < 1920 - 64) {
			m_Character.dir = 0;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) {
				m_Character.setSpeed((float)0.4);
				zoomSpeed = 5;
			}
			else {
				m_Character.setSpeed((float)0.2);
				zoomSpeed = 1;
			}
			m_Character.Currentframe += 0.005 * elapsedTime;
			if (m_Character.Currentframe > 3) m_Character.Currentframe -= 3;
			m_Character.m_Sprite.setTextureRect(IntRect(32 * int(m_Character.Currentframe), 64, 32, 32));
			moveCam(m_Character.getPos().x, m_Character.getPos().y);
		}
	}
	else if (m_Character.dx > 0) {
		m_Character.m_Sprite.setTextureRect(IntRect(32, 64, 32, 32));
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (m_Character.getPos().y > 0) {
			m_Character.dir = 3;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) {
				m_Character.setSpeed((float)0.4);
				zoomSpeed = 5;
			}
			else {
				m_Character.setSpeed((float)0.2);
				zoomSpeed = 1;
			}
			m_Character.Currentframe += 0.005 * elapsedTime;
			if (m_Character.Currentframe > 3) m_Character.Currentframe -= 3;
			m_Character.m_Sprite.setTextureRect(IntRect(32 * int(m_Character.Currentframe), 96, 32, 32));
			moveCam(m_Character.getPos().x, m_Character.getPos().y);
		}
	}
	else if (m_Character.dy < 0) {
		m_Character.m_Sprite.setTextureRect(IntRect(32, 96, 32, 32));
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		if (m_Character.getPos().y < 1920 - 64) {
			m_Character.dir = 2;
			if (Keyboard::isKeyPressed(Keyboard::LShift)) {
				m_Character.setSpeed((float)0.4);
				zoomSpeed = 5;
			}
			else {
				m_Character.setSpeed((float)0.2);
				zoomSpeed = 1;
			}
			m_Character.Currentframe += 0.005 * elapsedTime;
			if (m_Character.Currentframe > 3) m_Character.Currentframe -= 3;
			m_Character.m_Sprite.setTextureRect(IntRect(32 * int(m_Character.Currentframe), 0, 32, 32));
			moveCam(m_Character.getPos().x, m_Character.getPos().y);
		}
	}
	else if (m_Character.dy > 0) {
		m_Character.m_Sprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
	// Рандомизация карты по нажатию F2
	if (Keyboard::isKeyPressed(Keyboard::F2)) {
		randomMap();
		m_Character.randPos();
		e_Enemy.randPos();
		Cam.setCenter(m_Character.getPos());
		sleep(sf::seconds(0.5));
	}
	// Управление зумом (тестово)
	if (Keyboard::isKeyPressed(Keyboard::Subtract))
	{
		Cam.setSize(Cam.getSize().x + zoomSpeed, Cam.getSize().y + zoomSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Add))
	{
		Cam.setSize(Cam.getSize().x - zoomSpeed, Cam.getSize().y - zoomSpeed);
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		Cam.setSize(512, 512);
	}
}
void Engine::update(float dtAsSeconds)
{
	// Обновление персонажа и врага
	m_Character.updateCh(dtAsSeconds);
	e_Enemy.updateEn(dtAsSeconds);
}
void Engine::drawMap(float elapsedTime)
{
	// Очистка окна
	m_Window.clear();
	// Отрисовка тайлов из карты в view.h
	for (int l = 0; l < LAYERS; l++) {
		m_map.setPosition(0, 0);
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (TileMap[l][i][j] == 'g') {
					m_map.setTextureRect(IntRect(0, 0, 32, 32));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}

				if (TileMap[l][i][j] == 'w') {
					CurrentWframe += 0.00001 * elapsedTime;
					if (CurrentWframe > 3) CurrentWframe -= 3;
					m_mapW.setTextureRect(IntRect(192 + 256 * int(CurrentWframe), 992, 32, 32));
					m_mapW.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_mapW);
				}

				if (TileMap[l][i][j] == 't') {
					m_map.setTextureRect(IntRect(0, 32, 64, 64));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}

				if (TileMap[l][i][j] == 'b') {
					m_map.setTextureRect(IntRect(0, 160, 32, 32));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}

				if (TileMap[l][i][j] == 'l') {
					m_map.setTextureRect(IntRect(192, 160, 64, 32));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}

				if (TileMap[l][i][j] == 'L') {
					m_map.setTextureRect(IntRect(224, 224, 32, 64));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}

				if (TileMap[l][i][j] == 'y') {
					m_map.setTextureRect(IntRect(224, 192, 32, 32));
					m_map.setPosition((float)j * 64, (float)i * 64);
					m_Window.draw(m_map);
				}
			}
		}
	}
	// Отрисовка персонажа и врага
	m_Window.draw(e_Enemy.getSprite());
	m_Window.draw(m_Character.m_Sprite);
	// Слежение камеры за игроком
	m_Window.setView(Cam);
	// Отрисовка здоровья в левом нижнем углу экрана
	std::ostringstream PlayerHealth;
	PlayerHealth << m_Character.Health;
	HealthText.setString(PlayerHealth.str()+ " / 20");
	if(m_Character.Health >=10 ){
		HealthText.setPosition(Cam.getCenter().x - 200, Cam.getCenter().y + 200); 
	}
	else {
		HealthText.setPosition(Cam.getCenter().x - 190, Cam.getCenter().y + 200);
	}
	interface.Background.setPosition(Cam.getCenter().x - 256,
		Cam.getCenter().y + 200);
	m_Window.draw(interface.Background);
	m_Window.draw(HealthText);
	interface.Health.setPosition(Cam.getCenter().x - 250,
		Cam.getCenter().y + 235);
	interface.HealthCur.setPosition(Cam.getCenter().x - 250,
		Cam.getCenter().y + 235);
	int tmp1;
	tmp1 = 182.0 * (m_Character.Health / 20.0);
	interface.HealthCur.setTextureRect(IntRect(0, 79, 
		tmp1, 5));
	m_Window.draw(interface.Health);
	m_Window.draw(interface.HealthCur);
	// Отрисовка всего этого в окне
	m_Window.display();
}
void Engine::randomMap() {
	int tmp;
	// Очистка карты
	for (int l = 0; l < LAYERS; l++) {
		for (int i = 0; i < HEIGHT_MAP; i++) {
			for (int j = 0; j < WIDTH_MAP; j++) {
				TileMap[l][i][j] = ' ';
			}
		}
	}
	// Заполнение первого слоя (земля/вода)
	for (int i = 0; i < HEIGHT_MAP; i++) {
		for (int j = 0; j < WIDTH_MAP; j++) {
			tmp = rand() % 100;
			if (tmp >= 0 and tmp <= 75) TileMap[0][i][j] = 'g';
			if (tmp > 75 and tmp <= 100) TileMap[0][i][j] = 'w';
		}
	}
	// Заполнение второго слоя деревьями, кустами, бревнами, цветами
	for (int i = 1; i < HEIGHT_MAP - 1; i++) {
		for (int j = 1; j < WIDTH_MAP - 1; j++) {
			tmp = rand() % 100;
			if (tmp > 65 and tmp <= 70
				and TileMap[1][i][j] == ' '
				and TileMap[0][i][j] != 'w'
				and TileMap[0][i + 1][j] != 'w'
				and TileMap[0][i + 1][j + 1] != 'w'
				and TileMap[0][i][j + 1] != 'w') {
				TileMap[1][i][j] = 't';
				TileMap[1][i + 1][j] = 'C';
				TileMap[1][i + 1][j + 1] = 'C';
				TileMap[1][i][j + 1] = 'C';
			}
			if (tmp > 70 and tmp <= 75
				and TileMap[1][i][j] == ' '
				and TileMap[1][i - 1][j] == ' '
				and TileMap[1][i][j - 1] == ' '
				and TileMap[1][i - 1][j - 1] == ' '
				and TileMap[1][i + 1][j] == ' '
				and TileMap[1][i][j + 1] == ' '
				and TileMap[1][i + 1][j + 1] == ' '
				and TileMap[1][i - 1][j + 1] == ' '
				and TileMap[1][i + 1][j - 1] == ' '
				and TileMap[0][i][j] != 'w'
				and TileMap[0][i + 1][j] != 'w'
				and TileMap[0][i + 1][j + 1] != 'w'
				and TileMap[0][i][j + 1] != 'w') TileMap[1][i][j] = 'b';
			if (tmp > 75 and tmp <= 80
				and TileMap[1][i][j] == ' '
				and TileMap[1][i - 1][j] == ' '
				and TileMap[1][i][j - 1] == ' '
				and TileMap[1][i - 1][j - 1] == ' '
				and TileMap[1][i + 1][j] == ' '
				and TileMap[1][i][j + 1] == ' '
				and TileMap[1][i + 1][j + 1] == ' '
				and TileMap[1][i - 1][j + 1] == ' '
				and TileMap[1][i + 1][j - 1] == ' '
				and TileMap[0][i][j] != 'w'
				and TileMap[0][i + 1][j] != 'w'
				and TileMap[0][i + 1][j + 1] != 'w'
				and TileMap[0][i][j + 1] != 'w') {
				TileMap[1][i][j] = 'l';
				TileMap[1][i][j + 1] = 'C';
			}
			if (tmp > 80 and tmp <= 85
				and TileMap[1][i][j] == ' '
				and TileMap[1][i - 1][j] == ' '
				and TileMap[1][i][j - 1] == ' '
				and TileMap[1][i - 1][j - 1] == ' '
				and TileMap[1][i + 1][j] == ' '
				and TileMap[1][i][j + 1] == ' '
				and TileMap[1][i + 1][j + 1] == ' '
				and TileMap[1][i - 1][j + 1] == ' '
				and TileMap[1][i + 1][j - 1] == ' '
				and TileMap[0][i][j] != 'w'
				and TileMap[0][i + 1][j] != 'w'
				and TileMap[0][i + 1][j + 1] != 'w'
				and TileMap[0][i][j + 1] != 'w') {
				TileMap[1][i][j] = 'L';
				TileMap[1][i + 1][j] = 'C';
			}
			if (tmp > 85 and tmp <= 100
				and TileMap[1][i][j] == ' '
				and TileMap[1][i - 1][j] == ' '
				and TileMap[1][i][j - 1] == ' '
				and TileMap[1][i - 1][j - 1] == ' '
				and TileMap[1][i + 1][j] == ' '
				and TileMap[1][i][j + 1] == ' '
				and TileMap[1][i + 1][j + 1] == ' '
				and TileMap[1][i - 1][j + 1] == ' '
				and TileMap[1][i + 1][j - 1] == ' '
				and TileMap[0][i][j] != 'w'
				and TileMap[0][i + 1][j] != 'w'
				and TileMap[0][i + 1][j + 1] != 'w'
				and TileMap[0][i][j + 1] != 'w') TileMap[1][i][j] = 'y';
		}
	}
}
void Engine::battle() {
	FloatRect Ch = m_Character.m_Sprite.getGlobalBounds(),
		En = e_Enemy.getSprite().getGlobalBounds();
	// Если игрок пересекается с врагом отнимать хп
	if (Ch.intersects(En) and ready) {
		m_Character.Health -= 1;
		ready = 0;
	}
}

void Engine::GameOver(int& GameTimeInSec) {
	MainMenuMusic.play();
	while (!Keyboard::isKeyPressed(Keyboard::Space) and !restart) {
		m_Window.clear(Color(237, 144, 121, 255));
		m_Window.setView(View());
		std::ostringstream GameTimeStr;
		GameTimeStr << GameTimeInSec;
		GameTimeOver.setString("Time in game: " + GameTimeStr.str() + " seconds");
		GameTimeOver.setPosition(160, 512);
		m_Window.draw(GameTimeOver);
		CloseWindow.setPosition(120, 900);
		CloseWindow2.setPosition(120, 800);
		m_Window.draw(CloseWindow);
		m_Window.draw(CloseWindow2);
		m_Window.draw(GAMEOVER);
		m_Window.display();
		if (Keyboard::isKeyPressed(Keyboard::R)) restart = true;
	}
	MainMenuMusic.stop();
}
void Engine::GameGoing(int& GameTimeInSec, Clock GameTime,
	Clock clock, Clock cooldown) {
	GameMusic.play();
	while (m_Window.isOpen() and m_Character.Health > 0)
	{
		GameTimeInSec = GameTime.getElapsedTime().asSeconds();
		float time = (float)clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		if (!ready) {
			if (cooldown.getElapsedTime().asSeconds() >= 0.5) {
				ready = 1;
				cooldown.restart();
			}
		}
		else cooldown.restart();

		input(time);
		update(time);
		battle();
		drawMap(time);
	}
	GameMusic.stop();
}
void Engine::GameMainMenu() {
	MainMenuMusic.play();
	bool start = false;
	Text GameName, Author, PressSpace;
	initMMTexts(GameName, Author, PressSpace);
	while (!start) {
		m_Window.clear(Color(237, 144, 121, 255));
		m_Window.setView(View());
		m_Window.draw(GameName);
		m_Window.draw(Author);
		m_Window.draw(PressSpace);
		m_Window.display();
		if (Keyboard::isKeyPressed(Keyboard::Space)) start = true;
	}
	MainMenuMusic.stop();
}