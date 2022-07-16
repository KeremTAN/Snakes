#pragma once
#include"DrawableShapes.hpp"

class Grid : DrawableShapes {
public:
	Grid();
	void set(const float& length, const float& space);
	virtual void draw(Window& window) override;
private:
	float				m_space;
	float				m_length;
	float				m_countingLine;
	sf::RectangleShape	m_horizontalLine;
	sf::RectangleShape	m_verticalLine;
};
