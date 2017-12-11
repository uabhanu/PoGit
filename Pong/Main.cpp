#include <SFML\Graphics.hpp>

int main()
{
	sf::RenderWindow bhanuWindow(sf::VideoMode(800 , 600) , "SFML Works!!");
	
	while (bhanuWindow.isOpen())
	{
		sf::Event bhanuEvent;

		while (bhanuWindow.pollEvent(bhanuEvent))
		{

		}

		bhanuWindow.clear();
		bhanuWindow.display();
	}

	return 0;
}