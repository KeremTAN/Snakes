#pragma once
#include<SFML/Window/Event.hpp>
#include<functional>
#include<vector>

typedef std::function<void(sf::Keyboard::Key)> KeyboardFunction;

typedef std::vector<KeyboardFunction> KeyboardFunctionList;

typedef std::function<void(sf::Event::MouseMoveEvent)> MouseMove;

typedef std::vector<MouseMove> MouseMoveFuncList;

typedef std::function<void(sf::Event::MouseButtonEvent)> MouseClick;

typedef std::vector<MouseClick> MouseClickFuncList;