#include"Snake.hpp"

Snake::Snake(Window* win)
{
	m_ptrWindow = win;
	m_distance = 0.0f;
	m_score = 0;
	m_Direction = CellDirection::Right;
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
	m_cells[0].setColor(sf::Color::Magenta);
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
	if (!isInWindow())
		return;
	if (isEatItself())
		return;

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
		m_cells[0].setDirection(m_Direction);
		m_distance = 0.0f;
	}
}

void Snake::setDirection(CellDirection newDirection)
{
	if (newDirection == CellDirection::Right && m_cells[0].getDirection() == CellDirection::Left)
		return;
	if (newDirection == CellDirection::Left && m_cells[0].getDirection() == CellDirection::Right)
		return;
	if (newDirection == CellDirection::Up && m_cells[0].getDirection() == CellDirection::Down)
		return;
	if (newDirection == CellDirection::Down && m_cells[0].getDirection() == CellDirection::Up)
		return;
	m_Direction = newDirection;
}

void Snake::draw(Window& window)
{
	m_eating.draw(window);
	for (auto& cell : m_cells)
		cell.draw(window);

}

bool Snake::isInWindow()
{
	if (m_cells[0].getPosition().x < 0 ||
		m_cells[0].getPosition().x + m_cellSize > m_windowWidth ||
		m_cells[0].getPosition().y < 0 ||
		m_cells[0].getPosition().y + m_cellSize > m_windowHeight)
		return false;
	
	return true;
}

bool Snake::isEatItself()
{
	for (int i=2; i<m_cells.size(); i++)
		if (m_cells[0].getPosition() == m_cells[i].getPosition())
			return true;
	return false;
}

void Snake::checkEating()
{
	if (m_cells[0].getPosition() == m_eating.getPosition())
	{
		addQueue();
		freshEating();
		m_score += 5;
		m_ptrWindow->setTitle(m_score);
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
