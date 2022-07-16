#include "Cell.hpp"
#include"Window.hpp"

Cell::Cell()
{
	m_shape.setFillColor(sf::Color::Red);
	m_shape.setOutlineColor(sf::Color::Blue);
	m_shape.setOutlineThickness(1);
	setSize(30);
	setVelocity(0.5);
	setDirection(CellDirection::Right);
}

Cell Cell::createCell()
{
	sf::Vector2f newPosition = m_position;
	switch (m_direction)
	{
	case CellDirection::Right:
		newPosition.x -= m_size;
		break;
	case CellDirection::Left:
		newPosition.x += m_size;
		break;
	case CellDirection::Up:
		newPosition.y += m_size;
		break;
	case CellDirection::Down:
		newPosition.y -= m_size;
		break;
	default:
		break;
	}
	Cell newCell;
	newCell.setPosition(newPosition);
	newCell.setDirection(m_direction);
	return newCell;
}

void Cell::draw(Window& win)
{
	m_shape.setPosition(m_position);
	win.draw(m_shape);
}

void Cell::setPosition(const sf::Vector2f& newPosition)
{
	m_position = newPosition;
}

void Cell::setDirection(const CellDirection& direction)
{
	m_direction = direction;
}

CellDirection Cell::getDirection()
{
	return m_direction;
}

float Cell::getSize()
{
	return m_size;
}

void Cell::setSize(const float& size)
{
	m_size = size;
	m_shape.setSize(sf::Vector2f(m_size, m_size));
}

float Cell::getVelocity()
{
	return m_velocity;
}

void Cell::setVelocity(const float& velocity)
{
	m_velocity = velocity;
}

void Cell::moveCell()
{
	switch (m_direction)
	{
	case CellDirection::Right:
		m_position.x += m_velocity;
		break;
	case CellDirection::Left:
		m_position.x -= m_velocity;
		break;
	case CellDirection::Up:
		m_position.y -= m_velocity;
		break;
	case CellDirection::Down:
		m_position.y += m_velocity;
		break;
	default:
		break;
	}
}
