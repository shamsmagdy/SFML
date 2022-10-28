#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


using namespace std;
using namespace sf;

struct ball
{
	Sprite colors[20][25];
}upper_balls;

Sprite clrs[48];
void set_pos_ball(int counter, Sprite clrs[], RenderWindow& window)
{
	clrs[counter].setScale(0.5, 0.5);
	Vector2f ball_move(Mouse::getPosition(window).x - clrs[counter].getPosition().x, Mouse::getPosition(window).y - clrs[counter].getPosition().y);
	clrs[counter].move(ball_move * (1.f / 10.f));
}


int main()
{
	//window setup

	RenderWindow window(VideoMode(1000, 800), "Bubble Shooter");
	window.setFramerateLimit(30);

	//variable declaration

	int animator = 0;
	int counter = 0;
	bool check = false;
	//bool right = false, left = false, middle = false;

	//textures

	Texture redd, yelow, cyann, orangee, back, cannon_sheet, cannon_base;
	redd.loadFromFile("redball.png");
	yelow.loadFromFile("yellowball.png");
	cyann.loadFromFile("blueball.png");
	orangee.loadFromFile("orangeball.png");
	back.loadFromFile("background.jpeg");
	cannon_base.loadFromFile("cannon base.png");
	cannon_sheet.loadFromFile("Cannon spritesheet.png");

	//sprites

	Sprite backs, base, cannon_sprite;
	backs.setTexture(back);

	base.setTexture(cannon_base);
	base.setOrigin(123, 74);
	base.setPosition(500, 750);
	cannon_sprite.setTexture(cannon_sheet);
	cannon_sprite.setPosition(423, 580);
	cannon_sprite.setTextureRect(IntRect(animator * 104, 0, 104, 144));

	//filling array of cannon balls with sprites

	for (int i = 0; i < 20; i += 4)
	{
		clrs[i].setTexture(redd);
		clrs[i].setScale(0.5, 0.5);
		clrs[i].setPosition(497, 740);
		clrs[i].setOrigin(65, 55);
	}

	for (int i = 1; i < 21; i += 4)
	{
		clrs[i].setTexture(yelow);
		clrs[i].setScale(0.5, 0.5);
		clrs[i].setPosition(497, 740);
		clrs[i].setOrigin(65, 55);
	}

	for (int i = 2; i < 22; i += 4)
	{
		clrs[i].setTexture(cyann);
		clrs[i].setScale(0.5, 0.5);
		clrs[i].setPosition(497, 740);
		clrs[i].setOrigin(58, 58);
	}

	for (int i = 3; i < 23; i += 4)
	{
		clrs[i].setTexture(orangee);
		clrs[i].setScale(0.5, 0.5);
		clrs[i].setPosition(497, 740);
		clrs[i].setOrigin(58, 53);
	}

	//filling upper balls

	for (int row = 0; row < 8; row++)
	{
		if (row == 0)
		{
			for (int col = 0; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(redd);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 55);
				if (col == 16)
				{
					break;

				}
			}
		}
		if (row == 1)
		{
			for (int col = 3; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(yelow);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 105);
				if (col == 15)
				{
					break;

				}
			}
		}

		if (row == 2)
		{
			for (int col = 4; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(orangee);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 153);
				if (col == 14)
				{
					break;

				}
			}
		}

		if (row == 3)
		{
			for (int col = 5; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(cyann);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 205);
				if (col == 13)
				{
					break;

				}
			}
		}

		if (row == 4)
		{
			for (int col = 6; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(redd);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 260);
				if (col == 12)
				{
					break;

				}
			}
		}

		if (row == 5)
		{
			for (int col = 7; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(yelow);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 308);
				if (col == 11)
				{
					break;

				}
			}
		}

		if (row == 6)
		{
			for (int col = 8; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(orangee);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 355);
				if (col == 10)
				{
					break;

				}
			}
		}

		if (row == 7)
		{
			for (int col = 9; col < 24; col++)
			{
				upper_balls.colors[row][col].setTexture(cyann);
				upper_balls.colors[row][col].setScale(0.5, 0.5);
				upper_balls.colors[row][col].setPosition(50 * col, 407);
				if (col == 9)
				{
					break;

				}
			}
		}


	}    //end forloop

	//Game loop

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}


		static bool click, collided;

		if (event.type == Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left && click == false)
			{
				click = true;

				set_pos_ball(counter, clrs, window);

				for (int row = 0; row < 8; row++)
				{

					for (int col = 0; col < 24; col++)
					{

						if (clrs[counter].getGlobalBounds().intersects(upper_balls.colors[row][col].getGlobalBounds()))

						{
							if (clrs[counter].getTexture() == &cyann)
							{
								upper_balls.colors[row][col].setScale(0, 0);

								clrs[counter].setScale(0, 0);

								counter++;
							}

							else if (clrs[counter].getTexture() == &redd)
							{
								upper_balls.colors[row][col].setScale(0, 0);

								clrs[counter].setScale(0, 0);

								counter++;
							}

							else if (clrs[counter].getTexture() == &yelow)
							{
								upper_balls.colors[row][col].setScale(0, 0);

								clrs[counter].setScale(0, 0);

								counter++;
							}

							else if (clrs[counter].getTexture() == &orangee)
							{
								upper_balls.colors[row][col].setScale(0, 0);

								clrs[counter].setScale(0, 0);

								counter++;
							}
						}
					}
				}

			}
		}



		if (event.type == Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == Mouse::Left)
			{
				click = false;


			}
		}


		window.clear();

		window.draw(backs);

		//window.draw(clrs[counter]);

		window.draw(cannon_sprite);

		//drawing certain ball

		window.draw(base);

		for (int i = 23; i >= 0; i--)
			window.draw(clrs[i]);

		// drawing upper balls

		for (int row = 0; row < 8; row++)
		{
			for (int col = 2; col < 17; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 1; row < 8; row++)
		{
			for (int col = 3; col < 15; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 2; row < 8; row++)
		{
			for (int col = 4; col < 14; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 3; row < 8; row++)
		{
			for (int col = 5; col < 13; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 4; row < 8; row++)
		{
			for (int col = 6; col < 12; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 5; row < 8; row++)
		{
			for (int col = 7; col < 11; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		for (int row = 6; row < 8; row++)
		{
			for (int col = 8; col < 10; col++)
			{
				window.draw(upper_balls.colors[row][col]);
			}
		}

		window.display();

	}
	return 0;
}