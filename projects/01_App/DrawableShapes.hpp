#pragma once
#include<SFML/Graphics.hpp>
//#include "Window.hpp"

class Window;
class DrawableShapes {
public:
	DrawableShapes();
	virtual void draw(Window& window) = 0;
	sf::Vector2f getPosition();
protected: //kalýtým için protected yapýyoruz.
	sf::Vector2f	m_position;
	bool			m_isDrawable;
};
