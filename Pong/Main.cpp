#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>

bool m_leftPressed = false, m_rightPressed = false, m_upPressed = false, m_downPressed = false;
bool m_mouseLeftPressed = false, m_mouseRightPressed = false, m_mouseMiddlePressed = false;
bool m_leftReleased = false, m_rightReleased = false, m_upReleased = false, m_downReleased = false;
bool m_mouseLeftReleased = false, m_mouseRightReleased = false, m_mouseMiddleReleased = false;

sf::Event bhanuEvent;
sf::Font m_bhanuFont;
sf::Music m_bhanuMusic;
sf::RectangleShape m_bhanuRect(sf::Vector2f(800, 600));
sf::RenderWindow m_bhanuWindow(sf::VideoMode(800, 600), "SFML Works!!");
sf::Sound m_bhanuSound;
sf::SoundBuffer m_bhanuSoundBuff;
sf::Sprite m_bhanuEarthSp, m_bhanuSpaceSp;
sf::Text m_bhanuText;
sf::Texture m_bhanuEarthTex , m_bhanuSpaceTex;

void BhanuGame()
{
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
}

void BhanuEvents()
{
	while(m_bhanuWindow.pollEvent(bhanuEvent)) //Event of user clicked on 'X' to close the window
	{
		if(bhanuEvent.type == sf::Event::Closed) m_bhanuWindow.close();


		if(bhanuEvent.type == sf::Event::KeyPressed)
		{
			if(bhanuEvent.key.code == sf::Keyboard::Left)
			{
				m_leftPressed = true;
			}

			if(bhanuEvent.key.code == sf::Keyboard::Right)
			{
				m_rightPressed = true;
			}

			if(bhanuEvent.key.code == sf::Keyboard::Up)
			{
				m_upPressed = true;
			}

			if(bhanuEvent.key.code == sf::Keyboard::Down)
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

			if(bhanuEvent.key.code == sf::Keyboard::Right)
			{
				m_rightReleased = true;
			}

			if(bhanuEvent.key.code == sf::Keyboard::Up)
			{
				m_upReleased = true;
			}

			if(bhanuEvent.key.code == sf::Keyboard::Down)
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

			if(bhanuEvent.mouseButton.button == sf::Mouse::Right)
			{
				m_mouseRightPressed = true;
			}

			if(bhanuEvent.mouseButton.button == sf::Mouse::Middle)
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

			if(bhanuEvent.mouseButton.button == sf::Mouse::Right)
			{
				m_mouseRightReleased = true;
			}

			if(bhanuEvent.mouseButton.button == sf::Mouse::Middle)
			{
				m_mouseMiddleReleased = true;
			}
		}
	}
}

void BhanuSounds()
{
	if(m_bhanuMusic.openFromFile("Data/Sounds/DarkKnight.ogg") == false)
	{
		std::cout << "Sir Bhanu, unable to load Music, please check the path carefully" << std::endl;
	}
	else
	{
		m_bhanuMusic.play();
	}
}

void BhanuSprites()
{
	if(m_bhanuEarthTex.loadFromFile("Data/Sprites/Earth.png") == false)
	{
		std::cout << "Sir Bhanu, unable to load sprite, please check the path carefully" << std::endl;
	}
	else
	{
		m_bhanuEarthSp.setTexture(m_bhanuEarthTex);
		m_bhanuEarthSp.setOrigin(0 , 0);
		m_bhanuEarthSp.setPosition(250 , 150);
		m_bhanuEarthSp.setScale(0.5f , 0.5f);
	}

	if(m_bhanuSpaceTex.loadFromFile("Data/Sprites/Space.png") == false)
	{
		std::cout << "Sir Bhanu, unable to load sprite, please check the path carefully" << std::endl;
	}
	else
	{
		m_bhanuSpaceSp.setTexture(m_bhanuSpaceTex);
	}
}

void BhanuWindow()
{
	if(m_bhanuFont.loadFromFile("Data/impact.ttf") == false)
	{
		std::cout << "Sir Bhanu, unable to load font, please check the path carefully" << std::endl;
	}
	else
	{
		m_bhanuText.setFont(m_bhanuFont);
		m_bhanuText.setPosition(250 , 100);
	}
	
	m_bhanuText.setString("Bhanu owns this");
	m_bhanuWindow.setVerticalSyncEnabled(true);
	m_bhanuWindow.setFramerateLimit(60);
}

int main()
{
	std::cout << "Game Started" << std::endl;

	BhanuSounds(); //Sounds should stay outside Game Loop
	BhanuWindow();
	
	while(m_bhanuWindow.isOpen()) //Game Loop
	{
		BhanuEvents();
		BhanuGame();
		BhanuSprites();

		m_bhanuWindow.clear();

		//Drawing
		m_bhanuWindow.draw(m_bhanuSpaceSp); //This will be drawn first so it's background
		m_bhanuWindow.draw(m_bhanuEarthSp);
		m_bhanuWindow.draw(m_bhanuText);

		m_bhanuWindow.display();
	}

	return 0;
}