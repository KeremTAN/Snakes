#pragma once
#include"Window.hpp"
#include "Grid.hpp"
#include "Snake.hpp"

class Application {
public:
	Application();
	void built(const int& width, const int& height);
	void start(int fps);
private:
	void createFrame();
	void draw();
	void stageUpdate();
	void keyPressed(sf::Keyboard::Key key);
	void keyReleased(sf::Keyboard::Key key);
	void mouseMoved(sf::Event::MouseMoveEvent e);
	void mouseClicked(sf::Event::MouseButtonEvent e);


	Window		m_window;
	Snake		m_snake = Snake(&m_window);
	//Grid		m_grid;
	sf::Clock	m_clock;
	sf::Time	m_timeOfFrame;
	sf::Time	m_passingTime;
};