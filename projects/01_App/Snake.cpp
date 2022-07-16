#include"Snake.hpp"

Snake::Snake()
{
	addQueue();
	addQueue();
	addQueue();
	addQueue();
}

void Snake::addQueue()
{
	if (!m_cells.empty())
	{
		Cell newCell = m_cells.back().createCell();
		m_cells.push_back(newCell);
	}
	else
	{
		m_cells.push_back(Cell());
	}
}

void Snake::move()
{
	for (auto& cell : m_cells)
		cell.moveCell();
}

void Snake::setDirection(CellDirection newDirection)
{
}

void Snake::draw(Window& window)
{
	for (auto& cell : m_cells)
		cell.draw(window);

}
