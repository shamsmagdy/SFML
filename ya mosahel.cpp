//#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <iostream>
//#include<fstream>
//
//using namespace std;
//using namespace sf;
//
//struct shoot
//{
//	Sprite shooting_ball[48];
//	int column_number0 = 16;
//	int column_number1 = 15;
//	int column_number2 = 14;
//	int column_number3 = 13;
//	int column_number4 = 12;
//	int column_number5 = 11;
//	int column_number6 = 10;
//	int column_number7 = 9;
//}ball;
//
//int count = 0;
//
//
//void set_pos_ball(int counter, Sprite clrs[], RenderWindow& window)
//{
//	clrs[counter].setScale(0.5, 0.5);
//	Vector2f ball_move(Mouse::getPosition(window).x - clrs[counter].getPosition().x, Mouse::getPosition(window).y - clrs[counter].getPosition().y);
//	clrs[counter].move(ball_move * (1.f / 10.f));
//}
//
//int main()
//{
//	//window setup
//	RenderWindow window(VideoMode(1000, 800), "Bubble Shooter");
//	window.setFramerateLimit(30);
//
//	bool scorecollision = false;
//
//	//  SCORE code  //
//	// file opnening //
//	fstream myfile;
//	myfile.open("hscore.txt", ios::out);
//
//	int maxscore = 0, scoreint = 0;
//	Text scoree, scorepage;
//
//	Font scorefont;
//	scorefont.loadFromFile("ffont.ttf");
//
//	scoree.setFont(scorefont);
//	scoree.setString("score :");
//	scoree.setPosition(30, 0);
//	scoree.setFillColor(Color::White);
//	scoree.setCharacterSize(50);
//
//
//	//variable declaration
//	int animator = 0, counter = 0, score = 0, col = 0, scale0 = 0, remaingballs = 0, scorecounter = 0;
//	bool check = false;
//	static bool click;
//
//	//textures
//	Texture redd, yelow, cyann, orangee, back, cannon_sheet, cannon_base, ground;
//	redd.loadFromFile("red.png");
//	yelow.loadFromFile("yellow.png");
//	cyann.loadFromFile("blue.png");
//	orangee.loadFromFile("orange.png");
//	back.loadFromFile("backk.jpeg");
//	cannon_base.loadFromFile("cannon base.png");
//	cannon_sheet.loadFromFile("Cannon spritesheet.png");
//	ground.loadFromFile("ground.jpeg");
//
//	//sprites
//	Sprite backs, base, cannon_sprite, upper_ball_colors[10][25], ground_sprite;
//	backs.setTexture(back);
//	backs.setScale(1.8, 1);
//	base.setTexture(cannon_base);
//	base.setOrigin(123, 74);
//	base.setPosition(500, 750);
//	cannon_sprite.setTexture(cannon_sheet);
//	cannon_sprite.setPosition(423, 580);
//	cannon_sprite.setTextureRect(IntRect(animator * 104, 0, 104, 144));
//	ground_sprite.setTexture(ground);
//	ground_sprite.setScale(2.5, 1);
//	ground_sprite.setPosition(0, 735);
//
//	//filling array of cannon balls with sprites
//	for (int i = 0; i < 20; i += 4)
//	{
//		ball.shooting_ball[i].setTexture(redd);
//		ball.shooting_ball[i].setScale(0.5, 0.5);
//		ball.shooting_ball[i].setPosition(497, 740);
//		ball.shooting_ball[i].setOrigin(65, 55);
//	}
//	for (int i = 1; i < 21; i += 4)
//	{
//		ball.shooting_ball[i].setTexture(yelow);
//		ball.shooting_ball[i].setScale(0.5, 0.5);
//		ball.shooting_ball[i].setPosition(497, 740);
//		ball.shooting_ball[i].setOrigin(65, 55);
//	}
//	for (int i = 2; i < 22; i += 4)
//	{
//		ball.shooting_ball[i].setTexture(cyann);
//		ball.shooting_ball[i].setScale(0.5, 0.5);
//		ball.shooting_ball[i].setPosition(497, 740);
//		ball.shooting_ball[i].setOrigin(58, 58);
//	}
//	for (int i = 3; i < 23; i += 4)
//	{
//		ball.shooting_ball[i].setTexture(orangee);
//		ball.shooting_ball[i].setScale(0.5, 0.5);
//		ball.shooting_ball[i].setPosition(497, 740);
//		ball.shooting_ball[i].setOrigin(58, 53);
//	}
//
//	//settings of upper balls
//	for (int row = 0; row < 8; row++)
//	{
//		if (row == 0)
//		{
//			for (int col = 2; col < 17; col++)
//			{
//				upper_ball_colors[row][col].setTexture(redd);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 55);
//				//if (col == 16)
//					//break;
//
//			}
//		}
//		if (row == 1)
//		{
//			for (int col = 3; col < 16; col++)
//			{
//				upper_ball_colors[row][col].setTexture(yelow);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 105);
//				//if (col == 15)
//					//break;
//			}
//		}
//		if (row == 2)
//		{
//			for (int col = 4; col < 15; col++)
//			{
//				upper_ball_colors[row][col].setTexture(orangee);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 153);
//				//if (col == 14)
//					//break;
//			}
//		}
//		if (row == 3)
//		{
//			for (int col = 5; col < 14; col++)
//			{
//				upper_ball_colors[row][col].setTexture(cyann);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 205);
//				//if (col == 13)
//					//break;
//			}
//		}
//		if (row == 4)
//		{
//			for (int col = 6; col < 13; col++)
//			{
//				upper_ball_colors[row][col].setTexture(redd);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 260);
//				//if (col == 12)
//					//break;
//			}
//		}
//		if (row == 5)
//		{
//			for (int col = 7; col < 12; col++)
//			{
//				upper_ball_colors[row][col].setTexture(yelow);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 308);
//				//if (col == 11)
//					//break;
//			}
//		}
//		if (row == 6)
//		{
//			for (int col = 8; col < 11; col++)
//			{
//				upper_ball_colors[row][col].setTexture(orangee);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 355);
//				//if (col == 10)
//					//break;
//			}
//		}
//		if (row == 7)
//		{
//			for (int col = 9; col < 10; col++)
//			{
//				upper_ball_colors[row][col].setTexture(cyann);
//				upper_ball_colors[row][col].setScale(0.5, 0.5);
//				upper_ball_colors[row][col].setPosition(50 * col, 407);
//				//if (col == 9)
//					//break;
//
//			}
//		}
//	}//end of loop
//
//	//Game loop
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//		}
//
//		//move function of the ball
//		if (event.type == Event::MouseButtonPressed)
//		{
//			if (event.mouseButton.button == Mouse::Left)
//			{
//				click = true;
//			}
//		}
//		if (event.type == Event::MouseButtonReleased)
//		{
//			if (event.mouseButton.button == Mouse::Left)
//			{
//				click = false;
//				set_pos_ball(counter, ball.shooting_ball, window);
//			}
//		}
//
//		//Collision of ball with the upper balls
//		for (int i = 0; i < 25; i++)
//		{
//			if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[0][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() == &redd)
//				{
//					for (int r = 0; r < 10; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//					scorecounter = 0;
//					for (int r = 0; r < 1; r++)
//					{
//						for (int c = 2; c < 17; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() != &redd)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number0++;
//					upper_ball_colors[0][ball.column_number0].setTexture(redd);
//					upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
//					upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number0++;
//					if (ball.shooting_ball[counter].getTexture() == &yelow)
//						upper_ball_colors[0][ball.column_number0].setTexture(yelow);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[0][ball.column_number0].setTexture(cyann);
//					else
//						upper_ball_colors[0][ball.column_number0].setTexture(orangee);
//					upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
//					upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//			}
//
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[1][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() == &yelow)
//				{
//					for (int r = 1; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//					scorecounter = 0;
//					for (int r = 1; r < 2; r++)
//					{
//
//						for (int c = 3; c < 16; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() != &yelow)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number1++;
//					upper_ball_colors[1][ball.column_number1].setTexture(yelow);
//					upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
//					upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number1++;
//					if (ball.shooting_ball[counter].getTexture() == &redd)
//						upper_ball_colors[1][ball.column_number1].setTexture(redd);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[1][ball.column_number1].setTexture(cyann);
//					else
//						upper_ball_colors[1][ball.column_number1].setTexture(orangee);
//					upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
//					upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//
//				}
//
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[2][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() == &orangee)
//				{
//
//					for (int r = 2; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//					scorecounter = 0;
//					for (int r = 2; r < 3; r++)
//					{
//						for (int c = 4; c < 15; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() != &orangee)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number2++;
//					upper_ball_colors[2][ball.column_number2].setTexture(orangee);
//					upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
//					upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number2++;
//					if (ball.shooting_ball[counter].getTexture() == &yelow)
//						upper_ball_colors[2][ball.column_number2].setTexture(yelow);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[2][ball.column_number2].setTexture(cyann);
//					else
//						upper_ball_colors[2][ball.column_number2].setTexture(redd);
//					upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
//					upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[3][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() == &cyann)
//				{
//					for (int r = 3; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//
//					scorecounter = 0;
//					for (int r = 3; r < 4; r++)
//					{
//						for (int c = 5; c < 14; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + scorecounter * 10;
//					scoree.setString("score :" + to_string(scoreint));
//					counter++;
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() != &cyann)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number3++;
//					upper_ball_colors[3][ball.column_number3].setTexture(cyann);
//					upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
//					upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number3++;
//					if (ball.shooting_ball[counter].getTexture() == &yelow)
//						upper_ball_colors[3][ball.column_number3].setTexture(yelow);
//					else if (ball.shooting_ball[counter].getTexture() == &redd)
//						upper_ball_colors[3][ball.column_number3].setTexture(redd);
//					else
//						upper_ball_colors[3][ball.column_number3].setTexture(orangee);
//					upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
//					upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[4][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() == &redd)
//				{
//					for (int r = 4; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//					scorecounter = 0;
//					for (int r = 4; r < 5; r++)
//					{
//						for (int c = 6; c < 13; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() != &redd)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number4++;
//					upper_ball_colors[4][ball.column_number4].setTexture(redd);
//					upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
//					upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number4++;
//					if (ball.shooting_ball[counter].getTexture() == &yelow)
//						upper_ball_colors[4][ball.column_number4].setTexture(yelow);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[4][ball.column_number4].setTexture(cyann);
//					else
//						upper_ball_colors[4][ball.column_number4].setTexture(orangee);
//					upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
//					upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[5][i].getGlobalBounds()))
//			{
//				if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() == &yelow)
//				{
//					for (int r = 5; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//					scorecounter = 0;
//					for (int r = 5; r < 6; r++)
//					{
//						for (int c = 7; c < 12; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() != &yelow)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number5++;
//					upper_ball_colors[5][ball.column_number5].setTexture(yelow);
//					upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
//					upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number5++;
//					if (ball.shooting_ball[counter].getTexture() == &redd)
//						upper_ball_colors[5][ball.column_number5].setTexture(redd);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[5][ball.column_number5].setTexture(cyann);
//					else
//						upper_ball_colors[5][ball.column_number5].setTexture(orangee);
//					upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
//					upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//				}
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[6][i].getGlobalBounds()))
//			{
//
//				if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() == &orangee)
//				{
//					for (int r = 6; r < 8; r++)
//					{
//						for (int c = 0; c < 25; c++)
//						{
//							upper_ball_colors[r][c].setScale(0, 0);
//
//						}
//					}
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//
//					scorecounter = 0;
//					for (int r = 6; r < 7; r++)
//					{
//						for (int c = 8; c < 11; c++)
//						{
//							scorecounter++;
//						}
//					}
//
//					scoreint = scoreint + (scorecounter * 10);
//					scoree.setString("score :" + to_string(scoreint));
//
//				}
//				else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() != &orangee)
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number6++;
//					upper_ball_colors[6][ball.column_number6].setTexture(orangee);
//					upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
//					upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//				else
//				{
//					ball.shooting_ball[counter].move(0, 0);
//					ball.column_number6++;
//					if (ball.shooting_ball[counter].getTexture() == &yelow)
//						upper_ball_colors[6][ball.column_number6].setTexture(yelow);
//					else if (ball.shooting_ball[counter].getTexture() == &cyann)
//						upper_ball_colors[6][ball.column_number6].setTexture(cyann);
//					else
//						upper_ball_colors[6][ball.column_number6].setTexture(redd);
//					upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
//					upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
//					upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
//					ball.shooting_ball[counter].setScale(0, 0);
//					counter++;
//				}
//			}
//			else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[7][i].getGlobalBounds()))
//			{
//				ball.shooting_ball[counter].move(0, 0);
//				ball.column_number7++;
//				if (ball.shooting_ball[counter].getTexture() == &yelow)
//					upper_ball_colors[7][ball.column_number7].setTexture(yelow);
//				else if (ball.shooting_ball[counter].getTexture() == &cyann)
//					upper_ball_colors[7][ball.column_number7].setTexture(cyann);
//				else if (ball.shooting_ball[counter].getTexture() == &redd)
//					upper_ball_colors[7][ball.column_number7].setTexture(redd);
//				else
//					upper_ball_colors[7][ball.column_number7].setTexture(orangee);
//				upper_ball_colors[7][ball.column_number7].setScale(0.5, 0.5);
//				upper_ball_colors[7][ball.column_number7].setPosition(ball.shooting_ball[counter].getPosition());
//				upper_ball_colors[7][ball.column_number7].setOrigin(ball.shooting_ball[counter].getOrigin());
//				ball.shooting_ball[counter].setScale(0, 0);
//				counter++;
//			}
//		}
//
//
//		window.clear();
//
//		//drawing of the game
//		window.draw(backs);
//		window.draw(ground_sprite);
//		window.draw(ball.shooting_ball[counter]);
//		window.draw(cannon_sprite);
//		window.draw(base);
//		for (int row = 0; row < 1; row++)
//		{
//			for (int col = 2; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 16)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 1; row < 2; row++)
//		{
//			for (int col = 3; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 15)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 2; row < 3; row++)
//		{
//			for (int col = 4; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 14)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 3; row < 4; row++)
//		{
//			for (int col = 5; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 13)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 4; row < 5; row++)
//		{
//			for (int col = 6; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 12)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 5; row < 6; row++)
//		{
//			for (int col = 7; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 11)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//		for (int row = 6; row < 7; row++)
//		{
//			for (int col = 8; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 10)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//
//		for (int row = 7; row < 8; row++)
//		{
//			for (int col = 9; col < 25; col++)
//			{
//				window.draw(upper_ball_colors[row][col]);
//				if (col > 10)
//				{
//					if (upper_ball_colors[row][col].getScale().x > 0 && upper_ball_colors[row][col].getScale().y > 0)
//					{
//						window.draw(upper_ball_colors[row][col]);
//					}
//					else
//						continue;
//				}
//			}
//		}
//
//
//		for (int i = 23; i >= 0; i--)
//			window.draw(ball.shooting_ball[i]);
//
//
//
//
//		window.draw(scoree);
//		window.display();
//	}
//	return 0;
//
//}