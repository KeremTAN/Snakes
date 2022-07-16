#pragma once

#include "Cell.hpp"

class Snake : DrawableShapes {
public:
	Snake();
	void addQueue();
	void move();
	void setDirection(CellDirection newDirection);
	void draw(Window& window) override;

private:
	std::vector<Cell> m_cells;

};