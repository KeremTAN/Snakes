#include"Grid.hpp"
#include"Window.hpp"
Grid::Grid()
{
	set(100, 10);
	m_horizontalLine.setFillColor(sf::Color::Green);
	m_verticalLine.setFillColor(sf::Color::Green);
}

void Grid::set(const float& length, const float& space)
{
	m_length = length;
	m_space = space;
	m_countingLine = length / space;

	m_horizontalLine.setSize(sf::Vector2f(m_length, 1.0f));
	m_verticalLine.setSize(sf::Vector2f(1.0f, m_length));

}

void Grid::draw(Window& window)
{
	sf::Vector2f position;
	for (int i = 0; i < m_countingLine; i++)
	{
		position.x = 0.0f;
		position.y = i * m_space;
		m_horizontalLine.setPosition(position);
		window.draw(m_horizontalLine);
		//vertical lines draw
		position.x = i * m_space;
		position.y = 0.0f;
		m_verticalLine.setPosition(position);
		window.draw(m_verticalLine);
	}
}

