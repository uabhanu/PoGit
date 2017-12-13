#include <iostream>
#include <SFML\Graphics.hpp>

int main()
{
	bool m_leftPressed = false , m_rightPressed = false , m_upPressed = false , m_downPressed = false;
	bool m_mouseLeftPressed = false , m_mouseRightPressed = false , m_mouseMiddlePressed = false;
	bool m_leftReleased = false, m_rightReleased = false, m_upReleased = false, m_downReleased = false;
	bool m_mouseLeftReleased = false, m_mouseRightReleased = false, m_mouseMiddleReleased = false;

	sf::RenderWindow bhanuWindow(sf::VideoMode(800 , 600) , "SFML Works!!");
	bhanuWindow.setVerticalSyncEnabled(true);
	bhanuWindow.setFramerateLimit(60);
	
	while(bhanuWindow.isOpen())
	{
		//Events Processing
		sf::Event bhanuEvent;

		while(bhanuWindow.pollEvent(bhanuEvent)) //Event of user clicked on 'X' to close the window
		{
			if(bhanuEvent.type == sf::Event::Closed) bhanuWindow.close();
			

			if(bhanuEvent.type == sf::Event::KeyPressed)
			{
				if(bhanuEvent.key.code == sf::Keyboard::Left)
				{
					m_leftPressed = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Right)
				{
					m_rightPressed = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Up)
				{
					m_upPressed = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Down)
				{
					m_downPressed = true;
				}
			}

			if(bhanuEvent.type == sf::Event::KeyReleased)
			{
				if(bhanuEvent.key.code == sf::Keyboard::Left)
				{
					m_leftReleased = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Right)
				{
					m_rightReleased = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Up)
				{
					m_upReleased = true;
				}

				if (bhanuEvent.key.code == sf::Keyboard::Down)
				{
					m_downReleased = true;
				}
			}

			if(bhanuEvent.type == sf::Event::MouseButtonPressed)
			{
				if(bhanuEvent.mouseButton.button == sf::Mouse::Left)
				{
					m_mouseLeftPressed = true;
				}

				if (bhanuEvent.mouseButton.button == sf::Mouse::Right)
				{
					m_mouseRightPressed = true;
				}

				if (bhanuEvent.mouseButton.button == sf::Mouse::Middle)
				{
					m_mouseMiddlePressed = true;
				}
			}

			if(bhanuEvent.type == sf::Event::MouseButtonReleased)
			{
				if(bhanuEvent.mouseButton.button == sf::Mouse::Left)
				{
					m_mouseLeftReleased = true;
				}

				if (bhanuEvent.mouseButton.button == sf::Mouse::Right)
				{
					m_mouseRightReleased = true;
				}

				if (bhanuEvent.mouseButton.button == sf::Mouse::Middle)
				{
					m_mouseMiddleReleased = true;
				}
			}
		}

		//Game Logic
		if(m_leftPressed)
		{
			std::cout << "Left Key Pressed" << std::endl;
			m_leftPressed = false;
		}

		if(m_leftReleased)
		{
			std::cout << "Left Key Released" << std::endl;
			m_leftReleased = false;
		}

		bhanuWindow.clear();
		bhanuWindow.display();
	}

	return 0;
}