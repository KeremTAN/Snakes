#include"Application.hpp"
#include<iostream>
#include"DrawableShapes.hpp"
#include "Grid.hpp"
#include "Snake.hpp"

Grid grid;
Snake snake;

Application::Application()
{
}

void Application::built(const int& width, const int& height)
{
	m_window.createWindow(width, height);
	grid.set(width, 20);
	m_window.addMouseMoveFunc(
		std::bind(&Application::mouseMoved, this, std::placeholders::_1)
	);
	// ??
	m_window.addMouseClickedFunc(
		std::bind(&Application::mouseClicked, this, std::placeholders::_1)
	);
	//--

	m_window.addKeyPressFunc(
		std::bind(&Application::keyPressed, this, std::placeholders::_1)
	);
	m_window.addKeyReleaseFunc(
		std::bind(&Application::keyReleased, this, std::placeholders::_1)
	);
}

void Application::start(const int& fps)
{
	float tmpFps = 1.0f / fps;
	m_timeOfFrame = sf::seconds(tmpFps);

	m_passingTime = m_clock.restart();
	while (m_window.isOpen())
	{
		m_window.processEvent();
		m_passingTime += m_clock.getElapsedTime();
		if (m_passingTime >= m_timeOfFrame)
		{
			createFrame();
			m_passingTime = m_passingTime - m_timeOfFrame;
			m_clock.restart();
		}
		else {
			sf::sleep(m_passingTime - m_timeOfFrame);
		}
	}
}

void Application::createFrame()
{
	stageUpdate();
	draw();
}

void Application::draw()
{
	m_window.clearScreen();
	grid.draw(m_window);
	snake.draw(m_window);
	m_window.showShape();
}

void Application::stageUpdate()
{
	snake.move();
}

void Application::keyPressed(sf::Keyboard::Key key)
{
	/*
	if (key == sf::Keyboard::Left)
		;
	if (key == sf::Keyboard::Right)
		;
	if (key == sf::Keyboard::Up)
		;
	if (key == sf::Keyboard::Down)
		;
		*/
}

void Application::keyReleased(sf::Keyboard::Key key)
{
}

void Application::mouseMoved(sf::Event::MouseMoveEvent e)
{
}

void Application::mouseClicked(sf::Event::MouseButtonEvent e)
{
}