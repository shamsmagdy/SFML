#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include<fstream>
#include<string>
using namespace std;
using namespace sf;


struct shoot_Level1
{                              //NADA RANEEM
	Sprite shooting_ball[24];
	int column_number0 = 16;
	int column_number1 = 15;
	int column_number2 = 14;
	int column_number3 = 13;
	int column_number4 = 12;
	int column_number5 = 11;
	int column_number6 = 10;
	int column_number7 = 9;

}ball;

struct shoot_Level2
{
	Sprite shooting_balls[25];
	int row1 = 16;
	int row2 = 16;
	int row3 = 16;
	int row4 = 16;
	int row5 = 16;
}balls;

struct shoot_level3
{
	Sprite shooting_ball[24];
	int row1 = 10;
	int row2 = 11;
	int row3 = 12;
	int row4 = 13;
	int row5 = 14;
	int row6 = 13;
	int row7 = 12;
	int row8 = 11;
	int row9 = 10;
}ballss;

struct player
{                           //DANA
	string player_name;
	int high_score = 0;
	int player_score = 0;
};

int count = 0;

//LEVEL 1 FUN

void set_pos_ball(int counter, Sprite clrs[], RenderWindow& window, Event& event, bool level1)     //RANEEM
{
	if (level1)
		clrs[counter].setScale(0.5, 0.5);
	else
		clrs[counter].setScale(0.6, 0.6);
	Vector2f ball_move(Mouse::getPosition(window).x - clrs[counter].getPosition().x, Mouse::getPosition(window).y - clrs[counter].getPosition().y);
	clrs[counter].move(ball_move * (1.f / 10.f));
}

void Filling_cannon_balls_Level1(Texture& redd, Texture& cyann, Texture& yelow, Texture& orangee)    //RANEEM
{
	for (int i = 0; i < 20; i += 4)
	{
		ball.shooting_ball[i].setTexture(redd);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
		//ball.shooting_ball[i].move(velocity);

	}
	for (int i = 1; i < 21; i += 4)
	{
		ball.shooting_ball[i].setTexture(yelow);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
		//ball.shooting_ball[i].move(velocity);
	}
	for (int i = 2; i < 22; i += 4)
	{
		ball.shooting_ball[i].setTexture(cyann);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 58);
		//ball.shooting_ball[i].move(velocity);
	}
	for (int i = 3; i < 23; i += 4)
	{
		ball.shooting_ball[i].setTexture(orangee);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 53);
		//	ball.shooting_ball[i].move(velocity);
	}
}

void Filling_upper_balls_Level1(Texture& redd, Texture& cyann, Texture& yelow, Texture& orangee, Sprite upper_ball_colors[10][25])
{
	//TRIANGLE SHAPE                     //SHAMS
	for (int row = 0; row < 8; row++)
	{
		if (row == 0)
		{
			for (int col = 2; col < 17; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -407);
			}
		}
		if (row == 1)
		{
			for (int col = 3; col < 16; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -355);
			}
		}
		if (row == 2)
		{
			for (int col = 4; col < 15; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -308);
			}
		}
		if (row == 3)
		{
			for (int col = 5; col < 14; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -260);
			}
		}
		if (row == 4)
		{
			for (int col = 6; col < 13; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -205);
			}
		}
		if (row == 5)
		{
			for (int col = 7; col < 12; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -153);
			}
		}
		if (row == 6)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -105);
			}
		}
		if (row == 7)
		{
			for (int col = 9; col < 10; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, -55);
			}
		}
	}
	//end of loop
}

bool Animation_of_upper_balls_Level1(RenderWindow& window, Sprite upper_ball_colors[10][25])
{
	for (int row = 0; row < 8; row++)
	{

		if (row == 0)
		{
			for (int col = 2; col < 17; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 55)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 55);
				}
			}
		}
		else if (row == 1)
		{
			for (int col = 3; col < 16; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 105)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 105);
				}
			}
		}
		else if (row == 2)
		{
			for (int col = 4; col < 15; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 153)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 153);
				}
			}
		}
		else if (row == 3)
		{
			for (int col = 5; col < 14; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 205)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 205);
				}
			}
		}
		else if (row == 4)
		{
			for (int col = 6; col < 13; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 260)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 260);
				}
			}
		}
		else if (row == 5)
		{
			for (int col = 7; col < 12; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 308)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 308);
				}
			}
		}
		else if (row == 6)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_colors[row][col].move(0, 10);
				if (upper_ball_colors[row][col].getPosition().y >= 355)
				{
					upper_ball_colors[row][col].move(0, 0);
					upper_ball_colors[row][col].setPosition(50 * col, 355);
				}
			}
		}
		else if (row == 7)
		{
			upper_ball_colors[row][9].move(0, 10);
			if (upper_ball_colors[row][9].getPosition().y >= 407)
			{
				upper_ball_colors[row][9].move(0, 0);
				upper_ball_colors[row][9].setPosition(50 * 9, 407);
			}

		}

	}

	return true;
}

void Collision_Level1(RenderWindow& window, Texture& redd, Texture& yelow, Texture& cyann, Texture& orangee, int& scorecounter, Text& scoree, bool& collided, int& counter, player& gameplayer, Sprite upper_ball_colors[10][25], Sound& bubblesound)
{
	for (int i = 0; i < 25; i++)
	{
		if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[0][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() == &redd)
			{
				for (int r = 0; r < 10; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
						collided = true;
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 0; r < 1; r++)
				{
					for (int c = 2; c < 17; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);  //DANA
				scoree.setString("score :" + to_string(gameplayer.player_score));

				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[0][i].getTexture() != &redd)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				upper_ball_colors[0][ball.column_number0].setTexture(redd);
				upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
				upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[0][ball.column_number0].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[0][ball.column_number0].setTexture(cyann);
				else
					upper_ball_colors[0][ball.column_number0].setTexture(orangee);
				upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
				upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[1][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() == &yelow)
			{
				for (int r = 1; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				for (int r = 1; r < 2; r++)
				{
					for (int c = 3; c < 16; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[1][i].getTexture() != &yelow)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number1++;
				upper_ball_colors[1][ball.column_number1].setTexture(yelow);
				upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
				upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number1++;
				if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[1][ball.column_number1].setTexture(redd);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[1][ball.column_number1].setTexture(cyann);
				else
					upper_ball_colors[1][ball.column_number1].setTexture(orangee);
				upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
				upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[2][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() == &orangee)
			{
				for (int r = 2; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 2; r < 3; r++)
				{
					for (int c = 4; c < 15; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[2][i].getTexture() != &orangee)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number2++;
				upper_ball_colors[2][ball.column_number2].setTexture(orangee);
				upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
				upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number2++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[2][ball.column_number2].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[2][ball.column_number2].setTexture(cyann);
				else
					upper_ball_colors[2][ball.column_number2].setTexture(redd);
				upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
				upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[3][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() == &cyann)
			{
				for (int r = 3; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 3; r < 4; r++)
				{
					for (int c = 5; c < 14; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &cyann && upper_ball_colors[3][i].getTexture() != &cyann)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number3++;
				upper_ball_colors[3][ball.column_number3].setTexture(cyann);
				upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
				upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number3++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[3][ball.column_number3].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[3][ball.column_number3].setTexture(redd);
				else
					upper_ball_colors[3][ball.column_number3].setTexture(orangee);
				upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
				upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[4][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() == &redd)
			{
				for (int r = 4; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 4; r < 5; r++)
				{
					for (int c = 6; c < 13; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &redd && upper_ball_colors[4][i].getTexture() != &redd)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number4++;
				upper_ball_colors[4][ball.column_number4].setTexture(redd);
				upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
				upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number4++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[4][ball.column_number4].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[4][ball.column_number4].setTexture(cyann);
				else
					upper_ball_colors[4][ball.column_number4].setTexture(orangee);
				upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
				upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[5][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() == &yelow)
			{
				for (int r = 5; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;
				for (int r = 5; r < 6; r++)
				{
					for (int c = 7; c < 12; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{
					gameplayer.high_score = gameplayer.player_score;
				}

			}
			else if (ball.shooting_ball[counter].getTexture() == &yelow && upper_ball_colors[5][i].getTexture() != &yelow)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number0++;
				upper_ball_colors[5][ball.column_number5].setTexture(yelow);
				upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
				upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number5++;
				if (ball.shooting_ball[counter].getTexture() == &redd)
					upper_ball_colors[5][ball.column_number5].setTexture(redd);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[5][ball.column_number5].setTexture(cyann);
				else
					upper_ball_colors[5][ball.column_number5].setTexture(orangee);
				upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
				upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[6][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() == &orangee)
			{
				for (int r = 6; r < 8; r++)
				{
					for (int c = 0; c < 25; c++)
					{
						upper_ball_colors[r][c].setScale(0, 0);
					}
				}
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
				scorecounter = 0;

				for (int r = 6; r < 7; r++)
				{
					for (int c = 8; c < 11; c++)
					{
						scorecounter++;
					}
				}
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("score :" + to_string(gameplayer.player_score));
				if (gameplayer.high_score < gameplayer.player_score)
				{

					gameplayer.high_score = gameplayer.player_score;

				}
			}
			else if (ball.shooting_ball[counter].getTexture() == &orangee && upper_ball_colors[6][i].getTexture() != &orangee)
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number6++;
				upper_ball_colors[6][ball.column_number6].setTexture(orangee);
				upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
				upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				bubblesound.play();
				ball.shooting_ball[counter].move(0, 0);
				ball.column_number6++;
				if (ball.shooting_ball[counter].getTexture() == &yelow)
					upper_ball_colors[6][ball.column_number6].setTexture(yelow);
				else if (ball.shooting_ball[counter].getTexture() == &cyann)
					upper_ball_colors[6][ball.column_number6].setTexture(cyann);
				else
					upper_ball_colors[6][ball.column_number6].setTexture(redd);
				upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
				upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition());
				upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
				ball.shooting_ball[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[7][i].getGlobalBounds()))
		{
			bubblesound.play();
			ball.shooting_ball[counter].move(0, 0);
			ball.column_number7++;
			if (ball.shooting_ball[counter].getTexture() == &yelow)
				upper_ball_colors[7][ball.column_number7].setTexture(yelow);
			else if (ball.shooting_ball[counter].getTexture() == &cyann)
				upper_ball_colors[7][ball.column_number7].setTexture(cyann);
			else if (ball.shooting_ball[counter].getTexture() == &redd)
				upper_ball_colors[7][ball.column_number7].setTexture(redd);
			else
				upper_ball_colors[7][ball.column_number7].setTexture(orangee);
			upper_ball_colors[7][ball.column_number7].setScale(0.5, 0.5);
			upper_ball_colors[7][ball.column_number7].setPosition(ball.shooting_ball[counter].getPosition());
			upper_ball_colors[7][ball.column_number7].setOrigin(ball.shooting_ball[counter].getOrigin());
			ball.shooting_ball[counter].setScale(0, 0);
			counter++;
		}
	}
}


//LEVEL 2222 FUN 

void Filling_cannon_balls_level2(Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange)
{
	for (int i = 0; i < 21; i += 5)
	{
		balls.shooting_balls[i].setTexture(mint);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(65, 55);
	}
	for (int i = 1; i < 22; i += 5)
	{
		balls.shooting_balls[i].setTexture(cyan);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(65, 55);
	}
	for (int i = 2; i < 23; i += 5)
	{
		balls.shooting_balls[i].setTexture(light_green);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 58);
	}
	for (int i = 3; i < 24; i += 5)
	{
		balls.shooting_balls[i].setTexture(orange);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 53);
	}
	for (int i = 4; i < 25; i += 5)
	{
		balls.shooting_balls[i].setTexture(yellow);
		balls.shooting_balls[i].setScale(0.6, 0.6);
		balls.shooting_balls[i].setPosition(497, 740);
		balls.shooting_balls[i].setOrigin(58, 53);
	}
}

void Filling_upper_balls_level2(Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange, Sprite upper_ball_level2[7][30])
{
	for (int row = 2; row < 7; row++)
	{
		if (row == 2)
		{
			for (int col = 1; col < 10; col++)
			{
				upper_ball_level2[row][col].setTexture(mint);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 70);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 10; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(yellow);
				upper_ball_level2[row][col].setPosition(55 * -col, 70);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 3)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].setTexture(light_green);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 125);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 4; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(orange);
				upper_ball_level2[row][col].setPosition(55 * -col, 125);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 4)
		{
			for (int col = 1; col < 8; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 178);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(mint);
				upper_ball_level2[row][col].setPosition(55 * -col, 179);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 5)
		{
			for (int col = 1; col < 15; col++)
			{
				upper_ball_level2[row][col].setTexture(yellow);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 232);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 15; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * -col, 232);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
		if (row == 6)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].setTexture(orange);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 4; col < 8; col++)
			{
				upper_ball_level2[row][col].setTexture(cyan);
				upper_ball_level2[row][col].setPosition(55 * col + 1000, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].setTexture(light_green);
				upper_ball_level2[row][col].setPosition(55 * -col, 285);
				upper_ball_level2[row][col].setScale(0.6, 0.6);
			}
		}
	}
}

bool Animation_level2(RenderWindow& window, Sprite upper_ball_level2[7][30])
{
	for (int row = 2; row < 7; row++)
	{
		if (row == 2)
		{
			for (int col = 1; col < 10; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 70);
				}
			}
			for (int col = 10; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 70);
				}
			}
		}
		else if (row == 3)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 125);
				}
			}
			for (int col = 4; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 125);
				}
			}
		}
		else if (row == 4)
		{
			for (int col = 1; col < 8; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 178);
				}
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 179);
				}
			}
		}
		else if (row == 5)
		{
			for (int col = 1; col < 15; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 232);
				}
			}
			for (int col = 15; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 232);
				}
			}
		}
		else if (row == 6)
		{
			for (int col = 1; col < 4; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
			for (int col = 4; col < 8; col++)
			{
				upper_ball_level2[row][col].move(-15, 0);
				if (upper_ball_level2[row][col].getPosition().x <= (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
			for (int col = 8; col < 17; col++)
			{
				upper_ball_level2[row][col].move(15, 0);
				if (upper_ball_level2[row][col].getPosition().x > (55 * col))
				{
					upper_ball_level2[row][col].move(0, 0);
					upper_ball_level2[row][col].setPosition(55 * col, 285);
				}
			}
		}
	}
	return true;
}

void Collision_level2(RenderWindow& window, Texture& mint, Texture& cyan, Texture& light_green, Texture& yellow, Texture& orange, Sprite upper_ball_level2[7][30], int& counter, Sound& bubblesound, int& scorecounter, player& gameplayer, Text& scoree, bool& collided)
{
	for (int i = 0; i < 30; i++)
	{
		if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[2][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[2][i].getTexture() == &mint)
			{
				scorecounter = 0;
				for (int r = 2; r < 7; r++)
				{
					for (int c = 1; c < 10; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
						collided = true;
					}
				}
				for (int r = 2; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 495)
						{
							upper_ball_level2[r][c].setScale(0, 0);
							collided = true;
						}
					}
				}

				for (int i = 0; i < 9; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;

				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[2][i].getTexture() == &yellow)
			{
				scorecounter = 0;
				for (int r = 2; r < 7; r++)
				{
					for (int c = 10; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 2; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 495)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 7; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[2][i].getTexture() != &mint)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				upper_ball_level2[2][balls.row1].setTexture(mint);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[2][i].getTexture() != &yellow)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				upper_ball_level2[2][balls.row1].setTexture(yellow);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row1++;
				if (balls.shooting_balls[counter].getTexture() == &cyan)
					upper_ball_level2[2][balls.row1].setTexture(cyan);
				else if (balls.shooting_balls[counter].getTexture() == &orange)
					upper_ball_level2[2][balls.row1].setTexture(orange);
				else
					upper_ball_level2[2][balls.row1].setTexture(light_green);
				upper_ball_level2[2][balls.row1].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[2][balls.row1].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[2][balls.row1].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[3][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[3][i].getTexture() == &light_green)
			{
				scorecounter = 0;
				for (int r = 3; r < 7; r++)
				{
					for (int c = 1; c < 4; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 3; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 165)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 3; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[3][i].getTexture() == &orange)
			{
				scorecounter = 0;
				for (int r = 3; r < 7; r++)
				{
					for (int c = 4; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 3; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 165)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 14; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[3][i].getTexture() != &light_green)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				upper_ball_level2[3][balls.row2].setTexture(light_green);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[3][i].getTexture() != &orange)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				upper_ball_level2[3][balls.row2].setTexture(orange);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row2++;
				if (balls.shooting_balls[counter].getTexture() == &cyan)
					upper_ball_level2[3][balls.row2].setTexture(cyan);
				else if (balls.shooting_balls[counter].getTexture() == &mint)
					upper_ball_level2[3][balls.row2].setTexture(mint);
				else
					upper_ball_level2[3][balls.row2].setTexture(yellow);
				upper_ball_level2[3][balls.row2].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[3][balls.row2].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[3][balls.row2].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[4][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[4][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int r = 4; r < 7; r++)
				{
					for (int c = 1; c < 8; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);

					}
				}
				for (int r = 4; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 385)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 8; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));
			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[4][i].getTexture() == &mint)
			{
				scorecounter = 0;
				for (int r = 4; r < 7; r++)
				{
					for (int c = 8; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 4; r < 7; r++)
				{
					for (int c = 17; c < 25; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 385)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 10; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[4][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				upper_ball_level2[4][balls.row3].setTexture(cyan);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &mint && upper_ball_level2[4][i].getTexture() != &mint)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				upper_ball_level2[4][balls.row3].setTexture(mint);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row3++;
				if (balls.shooting_balls[counter].getTexture() == &orange)
					upper_ball_level2[4][balls.row3].setTexture(orange);
				else if (balls.shooting_balls[counter].getTexture() == &yellow)
					upper_ball_level2[4][balls.row3].setTexture(yellow);
				else
					upper_ball_level2[4][balls.row3].setTexture(light_green);
				upper_ball_level2[4][balls.row3].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[4][balls.row3].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[4][balls.row3].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[5][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[5][i].getTexture() == &yellow)
			{
				scorecounter = 0;
				for (int r = 5; r < 7; r++)
				{
					for (int c = 1; c < 15; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 5; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x <= 770)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 14; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[5][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int r = 5; r < 7; r++)
				{
					for (int c = 15; c < 17; c++)
					{
						upper_ball_level2[r][c].setScale(0, 0);
					}
				}
				for (int r = 5; r < 7; r++)
				{
					for (int c = 17; c < 30; c++)
					{
						if (upper_ball_level2[r][c].getPosition().x > 770)
						{
							upper_ball_level2[r][c].setScale(0, 0);
						}
					}
				}
				for (int i = 0; i < 2; i++)
					scorecounter++;
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &yellow && upper_ball_level2[5][i].getTexture() != &yellow)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				upper_ball_level2[5][balls.row4].setTexture(yellow);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[5][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				upper_ball_level2[5][balls.row4].setTexture(cyan);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row4++;
				if (balls.shooting_balls[counter].getTexture() == &light_green)
					upper_ball_level2[5][balls.row4].setTexture(light_green);
				else if (balls.shooting_balls[counter].getTexture() == &mint)
					upper_ball_level2[5][balls.row4].setTexture(mint);
				else
					upper_ball_level2[5][balls.row4].setTexture(orange);
				upper_ball_level2[5][balls.row4].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[5][balls.row4].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[5][balls.row4].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
		}
		else if (balls.shooting_balls[counter].getGlobalBounds().intersects(upper_ball_level2[6][i].getGlobalBounds()))
		{
			bubblesound.play();
			if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[6][i].getTexture() == &orange)
			{
				scorecounter = 0;
				for (int c = 1; c < 4; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x <= 165)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[6][i].getTexture() == &cyan)
			{
				scorecounter = 0;
				for (int c = 4; c < 8; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x > 165 && upper_ball_level2[6][c].getPosition().x <= 385)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &light_green && upper_ball_level2[6][i].getTexture() == &light_green)
			{
				scorecounter = 0;
				for (int c = 8; c < 17; c++)
				{
					upper_ball_level2[6][c].setScale(0, 0);
					scorecounter++;
				}
				for (int c = 17; c < 30; c++)
				{
					if (upper_ball_level2[6][c].getPosition().x > 385)
					{
						upper_ball_level2[6][c].setScale(0, 0);
					}
				}
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
				gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
				scoree.setString("Score :" + to_string(gameplayer.player_score));

			}
			else if (balls.shooting_balls[counter].getTexture() == &orange && upper_ball_level2[6][i].getTexture() != &orange)
			{
				balls.shooting_balls[counter].move(0, 0);
				balls.row5++;
				upper_ball_level2[6][balls.row5].setTexture(orange);
				upper_ball_level2[6][balls.row5].setScale(balls.shooting_balls[counter].getScale());
				upper_ball_level2[6][balls.row5].setPosition(balls.shooting_balls[counter].getPosition());
				upper_ball_level2[6][balls.row5].setOrigin(balls.shooting_balls[counter].getOrigin());
				balls.shooting_balls[counter].setScale(0, 0);
				counter++;
			}
			else if (balls.shooting_balls[counter].getTexture() == &cyan && upper_ball_level2[6][i].getTexture() != &cyan)
			{
				balls.shooting_balls[counter].move(0, 0);
			}
		}
	}
}