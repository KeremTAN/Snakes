#pragma once
#include "DrawableShapes.hpp"

enum class CellDirection {
	Up,
	Down,
	Left,
	Right
};

class Cell : DrawableShapes
{
public:
	Cell();

	Cell			createCell();
	void			draw(Window& win) override;
	void			setPosition(const sf::Vector2f& newPosition);	// ?
	void			setDirection(const CellDirection& direction);
	CellDirection	getDirection();
	float			getSize();
	void			setSize(const float& size);
	float			getVelocity();
	void			setVelocity(const float& velocity);
	void			moveCell();
private:
	CellDirection m_direction;
	sf::RectangleShape m_shape;
	float m_size;
	float m_velocity;
};