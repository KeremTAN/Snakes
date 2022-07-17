#pragma once

#include "Cell.hpp"

class Snake : DrawableShapes {
public:
	Snake();
	void set(const float& cellSize, 
			 const float& windowWidth,
			 const float& windowHeight);
	void addQueue();
	void move();
	void setDirection(CellDirection newDirection);
	void draw(Window& window) override;

private:
	void				checkEating();
	void				freshEating();
	Cell				m_eating;
	std::vector<Cell>	m_cells;
	float				m_distance;
	CellDirection		m_newDirection;
	float				m_cellSize;
	float				m_windowWidth;
	float				m_windowHeight;

};