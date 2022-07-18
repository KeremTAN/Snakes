#pragma once

#include<SFML/Graphics.hpp>
#include"FunctionTypes.hpp"

class Window {
public:
	Window();
	void createWindow(const unsigned int& width,
		const unsigned int& height,
		const sf::String& title);
	void draw(sf::Drawable& shape);
	void processEvent();
	bool isOpen();
	void clearScreen();
	void showShape();
	void addKeyPressFunc(KeyboardFunction newFunction);
	void addKeyReleaseFunc(KeyboardFunction newFunction);
	void addMouseMoveFunc(MouseMove newFunction);
	void addMouseClickedFunc(MouseClick newFunction);
	void setTitle(const int& score);
private:
	KeyboardFunctionList m_keyPressFuncList;
	KeyboardFunctionList m_keyReleaseFuncList;
	MouseMoveFuncList m_mouseMoveFuncList;
	MouseClickFuncList m_mouseClickFuncList;
	sf::RenderWindow window;
};