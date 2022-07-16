#include "DrawableShapes.hpp"

DrawableShapes::DrawableShapes()
{
	m_isDrawable = true;
}

sf::Vector2f DrawableShapes::getPosition()
{
	return m_position;
}
