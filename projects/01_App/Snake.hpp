#pragma once

#include "Cell.hpp"
#include "Window.hpp"

class Snake : DrawableShapes {
public:
	Snake(Window* win);
	void set(const float& cellSize, 
			 const float& windowWidth,
			 const float& windowHeight);
	void addQueue();
	void move();
	void setDirection(CellDirection newDirection);
	void draw(Window& window) override;
	bool isInWindow();
	bool isEatItself();

private:
	void				checkEating();
	void				freshEating();
	Cell				m_eating;
	std::vector<Cell>	m_cells;
	float				m_distance;
	CellDirection		m_Direction;
	float				m_cellSize;
	float				m_windowWidth;
	float				m_windowHeight;
	int					m_score;
	Window*				m_ptrWindow;

};