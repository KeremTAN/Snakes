#include"Snake.hpp"

Snake::Snake()
{
	m_distance = 0.0f;
	m_newDirection = CellDirection::Right;
}

void Snake::set(const float& cellSize,
				const float& windowWidth,
				const float& windowHeight)
{
	m_cellSize = cellSize;
	m_windowWidth = windowWidth;
	m_windowHeight = windowHeight;
	freshEating();
	addQueue();
	addQueue();
	addQueue();
	addQueue();
}

void Snake::addQueue()
{
	Cell newCell;
	if (!m_cells.empty())
	{
		newCell = m_cells.back().createCell();
	}
	newCell.setSize(m_cellSize);
	m_cells.push_back(newCell);
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
		checkEating();
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
	m_eating.draw(window);
	for (auto& cell : m_cells)
		cell.draw(window);

}

void Snake::checkEating()
{
	if (m_cells[0].getPosition() == m_eating.getPosition())
	{
		addQueue();
		freshEating();
		bool isCorrespond;
		do
		{
			isCorrespond = false;
			for (auto& cell : m_cells) {
				if (cell.getPosition() == m_eating.getPosition())
				{
					freshEating();
					isCorrespond = true;
					break;
				}
			}

		} while (isCorrespond);
	}
}

void Snake::freshEating()
{
	int colC = m_windowWidth / m_cellSize;
	int rowC = m_windowHeight / m_cellSize;
	float x = (rand() % colC) * m_cellSize;
	float y = (rand() % rowC) * m_cellSize;
	m_eating.setPosition(sf::Vector2f(x,y));
	m_eating.setSize(m_cellSize);
	m_eating.setColor(sf::Color::White);
}
