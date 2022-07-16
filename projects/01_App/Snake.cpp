#include"Snake.hpp"

Snake::Snake()
{
	m_distance = 0.0f;
	m_newDirection = CellDirection::Right;
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
	{
		cell.moveCell();
	}
	m_distance += m_cells[0].getVelocity();
	if (m_distance == m_cells[0].getSize())
	{
		for (int i = m_cells.size() - 1; i > 0; i--)
		{
			m_cells[i].setDirection(m_cells[i - 1].getDirection());
		}
		m_cells[0].setDirection(m_newDirection);
		m_distance = 0.0f;
	}
}

void Snake::setDirection(CellDirection newDirection)
{
	m_newDirection = newDirection;
}

void Snake::draw(Window& window)
{
	for (auto& cell : m_cells)
		cell.draw(window);

}
