#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include<fstream>
#include<string>
using namespace std;
using namespace sf;
struct shoot
{
	Sprite shooting_ball[48];
	int column_number0 = 16;
	int column_number1 = 15;
	int column_number2 = 14;
	int column_number3 = 13;
	int column_number4 = 12;
	int column_number5 = 11;
	int column_number6 = 10;
	int column_number7 = 9;
}ball;
struct player
{
	string player_name;
	int high_score = 0;
	int player_score = 0;
};
int count = 0;
void set_pos_ball(int counter, Sprite clrs[], RenderWindow& window)
{
	clrs[counter].setScale(0.5, 0.5);
	Vector2f ball_move(Mouse::getPosition(window).x - clrs[counter].getPosition().x,
		Mouse::getPosition(window).y - clrs[counter].getPosition().y);
	clrs[counter].move(ball_move * (1.f / 10.f));
}
void Filling_cannon_balls(Texture& redd, Texture& cyann, Texture& yelow, Texture& orangee)
{
	for (int i = 0; i < 20; i += 4)
	{
		ball.shooting_ball[i].setTexture(redd);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
	}
	for (int i = 1; i < 21; i += 4)
	{
		ball.shooting_ball[i].setTexture(yelow);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(65, 55);
	}
	for (int i = 2; i < 22; i += 4)
	{
		ball.shooting_ball[i].setTexture(cyann);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 58);
	}
	for (int i = 3; i < 23; i += 4)
	{
		ball.shooting_ball[i].setTexture(orangee);
		ball.shooting_ball[i].setScale(0.5, 0.5);
		ball.shooting_ball[i].setPosition(497, 740);
		ball.shooting_ball[i].setOrigin(58, 53);
	}
}
int draw = 0;
string names[100];
string scoreeeee[100];

void inputfromfile()
{
	int max_two_22;
	ifstream input;
	input.open("file3.txt");
	char ch; 

	while (1) {
			input >> ch;
			if ('a' <=  ch && ch <= 'z') {
				names[draw] += ch;
			} 
		    if ('0' <= ch && ch <= '9') {
				scoreeeee[draw] += ch;
			}
			if (ch == ',') {
				draw++;
			}
			if (input.eof())
				break;
			cout << ch;
	}
		input.close();
}
void savetofile(player gameplayer, int& a)
{
	ofstream output;
	output.open("file3.txt", ios::app);
	output << gameplayer.high_score << "\t";
	output << gameplayer.player_name <<"," << endl;
	output.close();
}
int main()
{
	int a = 0;
	RenderWindow window(VideoMode(1000, 800), "bubble shooter");
	window.setFramerateLimit(30);
	//variable declaration
	int animator = 0, counter = 0,/* score = 0,*/ col = 0;
	bool check = false;
	bool collided = false;
	static bool click;
	player gameplayer;
	int playindex = 0;
	//int scoreint = 0, maxscore = 0;
	int scorecounter = 0;
	//textures
	Texture redd, yelow, cyann, orangee, backk, cannon_sheet, cannon_base;
	redd.loadFromFile("red.png");
	yelow.loadFromFile("yellow.png");
	cyann.loadFromFile("ball6.png");
	orangee.loadFromFile("orange.png");
	backk.loadFromFile("background.jpg");
	cannon_base.loadFromFile("cannon base.png");
	cannon_sheet.loadFromFile("Cannon spritesheet.png");
	cannon_sheet.loadFromFile("Cannon spritesheet.png");
	//sprites
	Sprite backs, base, cannon_sprite, upper_ball_colors[10][25];
	backs.setTexture(backk);
	backs.setScale(1.8, 1);
	base.setTexture(cannon_base);
	base.setOrigin(123, 74);
	base.setPosition(500, 750);
	cannon_sprite.setTexture(cannon_sheet);
	cannon_sprite.setPosition(423, 580);
	cannon_sprite.setTextureRect(IntRect(animator * 104, 0, 104, 144));
	//filling array of cannon balls with sprites
	Filling_cannon_balls(redd, cyann, yelow, orangee);
	Texture background, bubble, start, animal, menu, monkey, monkey2, senjap, poma, bubb, buuu,
		highh, hscore, howplay;
	Texture blueball, redball, yellowball, orangeball, backimage, kass, level, animation, ground,
		pointer,
		bname, bhow, congrats, winscore;
	background.loadFromFile("back1.jpg");
	bubble.loadFromFile("bubblee.png");
	start.loadFromFile("bstart.png");
	animal.loadFromFile("animals.png");
	menu.loadFromFile("menuu.png");
	monkey.loadFromFile("monkey.png"); //loading images
	monkey2.loadFromFile("monkey2.png");
	senjap.loadFromFile("senjapc.png");
	poma.loadFromFile("boma.png");
	bubb.loadFromFile("bubb.png");
	buuu.loadFromFile("buuu.png");
	blueball.loadFromFile("ball6.png");
	redball.loadFromFile("redball.png");
	yellowball.loadFromFile("yellowball.png");
	orangeball.loadFromFile("orangeball.png");
	backimage.loadFromFile("backk.jpeg");
	highh.loadFromFile("high.jpg");
	kass.loadFromFile("kaas.png");
	animation.loadFromFile("anim.png");
	ground.loadFromFile("groundd.jpg");
	pointer.loadFromFile("ppointer.png");
	bname.loadFromFile("board.png");
	howplay.loadFromFile("howplay.png");
	bhow.loadFromFile("howboard.png");
	congrats.loadFromFile("congratulations.png");
	winscore.loadFromFile("board.png");
	Sprite back, bub, st, ani, men, mon, mon2, sen, pom, bu[3], buu, b, hig, kas, animat, grou, point,
		bnam, howp, bhoow, congrt, winscor;
	back.setTexture(background);
	back.setScale(1.8, 1);
	bub.setTexture(bubble);
	bub.setScale(0.8, 0.8);
	bub.setPosition(270, 90);
	st.setTexture(start);
	st.setPosition(390, 410);
	st.setScale(0.7, 0.7);
	ani.setTexture(animal);
	ani.setPosition(370, 460);
	ani.setScale(0.7, 0.7);
	men.setTexture(menu);
	men.setPosition(280, 150);
	men.setScale(1, 1);
	mon.setTexture(monkey);
	mon.setPosition(700, 70);
	mon.setScale(0.6, 0.6);
	mon2.setTexture(monkey2);
	mon2.setPosition(60, 10);
	mon2.setScale(0.4, 0.4);
	sen.setTexture(senjap);
	sen.setPosition(130, 590);
	sen.setScale(0.3, 0.3);
	sen.setRotation(-30);
	pom.setTexture(poma);
	pom.setPosition(688, 27);
	pom.setScale(0.3, 0.3);
	for (int i = 0; i < 3; i++)
	{
		bu[i].setTexture(bubb); //loop for repeat this image 
		bu[i].setScale(0.9, 0.9);
	}
	bu[0].setPosition(550, 250);
	bu[1].setPosition(250, 100);
	bu[2].setPosition(220, 350);
	buu.setTexture(buuu);
	buu.setPosition(610, 480);
	buu.setScale(0.6, 0.6);
	buu.setRotation(-25);
	b.setTexture(backimage);
	b.setScale(1.8, 1);
	hig.setTexture(highh);
	hig.setPosition(300, 240);
	hig.setScale(1.6, 1.6);
	kas.setTexture(kass);
	kas.setPosition(310, 570);
	kas.setScale(0.9, 0.9);
	animat.setTexture(animation);
	animat.setPosition(50, 600);
	animat.setScale(1, 1);
	grou.setTexture(ground);
	grou.setPosition(0, 735);
	grou.setScale(7, 1);
	point.setTexture(pointer);
	point.setPosition(100, 100);
	point.setScale(0.3, 0.3);
	bnam.setTexture(bname);
	bnam.setPosition(340, 280);
	bnam.setScale(0.6, 0.6);
	howp.setTexture(howplay);
	howp.setPosition(300, 530);
	howp.setScale(1, 1);
	bhoow.setTexture(bhow);
	bhoow.setPosition(250, 200);
	bhoow.setScale(1.5, 1.5);
	congrt.setTexture(congrats);
	congrt.setPosition(230, 20);
	congrt.setScale(1, 1);
	winscor.setTexture(winscore);
	winscor.setPosition(345, 280);
	winscor.setScale(0.6, 0.4);
	Font font, ffont, fffont;
	font.loadFromFile("font.ttf");
	ffont.loadFromFile("hhhh.ttf");
	fffont.loadFromFile("foont.ttf");
	Text sstart, play, exit, high, hs, backh, leve, score, text, next, hello,
		name, how, howback, cong, scoree, winhigh;
	Text scorepage;
	Text winssssscore;
	Text score_max;
	Text aa1 , aa2 , aa3 , aa4 ,aa5;
	aa1.setFont(ffont);
	aa1.setPosition(100, 00);
	aa1.setFillColor((Color::Green));
	aa1.setString("sxd");

	aa2.setFont(ffont);
	aa2.setPosition(200, 200);
	aa2.setFillColor((Color::Green));
	aa3.setFont(ffont);
	aa3.setPosition(300, 300);
	aa5.setFont(ffont);
	aa5.setPosition(500, 500);
	aa5.setFillColor((Color::Green));
	aa3.setFillColor((Color::Green));
	aa4.setFont(ffont);
	aa4.setPosition(400, 400);
	aa4.setFillColor((Color::Green));
	


	//nameeee.setFont(ffont);
	for (int x = 0; x < 15; x++)
	{
		if (gameplayer.high_score > gameplayer.high_score)
		{
			gameplayer.high_score = gameplayer.high_score;
			//nameeee.setString(gameplayer[x].player_name);
		}
	}
	//nameeee.setPosition(350, 400);
	//nameeee.setCharacterSize(40);
	//nameeee.setFillColor(Color::Green);
	sstart.setFont(font);
	sstart.setString("START");
	sstart.setPosition(420, 405);
	sstart.setFillColor(Color(90, 60, 80, 255));
	sstart.setCharacterSize(65);
	play.setFont(font);
	play.setString("Play");
	play.setPosition(460, 165);
	play.setCharacterSize(80);
	exit.setString("Back");
	exit.setFont(font);
	exit.setPosition(330, 540);
	exit.setCharacterSize(85);
	how.setFont(font);
	how.setPosition(450, 433);
	how.setString("how to play");
	how.setCharacterSize(43);
	high.setString("High Score");
	high.setFont(font);
	high.setPosition(310, 310);
	high.setCharacterSize(47);
	hs.setFont(ffont);
	hs.setString("HIGH SCORE");
	hs.setPosition(280, 130);
	hs.setFillColor(Color(210, 110, 60, 255));
	hs.setCharacterSize(75);
	backh.setString("Back");
	backh.setFont(font);
	backh.setPosition(610, 670);
	backh.setCharacterSize(85);
	leve.setFont(ffont);
	leve.setString("level: 1");
	leve.setPosition(15, 0);
	leve.setCharacterSize(50);
	leve.setFillColor(Color::White);
	score.setFont(ffont);
	score.setString("Score :");
	score.setPosition(750, 0);
	score.setFillColor(Color::White);
	score.setCharacterSize(50);
	howback.setFont(font);
	howback.setString("Back");
	howback.setCharacterSize(100);
	howback.setPosition(460, 670);
	scoree.setFont(ffont);
	scoree.setCharacterSize(50);
	scoree.setPosition(650, 0);
	winhigh.setFont(font);
	winhigh.setString("highscore");
	winhigh.setCharacterSize(80);
	winhigh.setPosition(380, 400);
	winhigh.setFillColor(Color(90, 60, 80, 255));
	string input_text;
	//enter user name
	text.setFont(fffont);
	text.setPosition(395, 380);
	text.setCharacterSize(50);
	text.setFillColor(Color(0, 0, 0, 255));
	hello.setFont(ffont);
	hello.setString("Hello!");
	hello.setPosition(370, 110);
	hello.setFillColor(Color(210, 110, 60, 255));
	hello.setCharacterSize(70);
	name.setFont(ffont);
	name.setFont(ffont);
	name.setString("Please,Enter your name");
	name.setPosition(250, 220);
	name.setFillColor(Color(210, 110, 60, 255));
	name.setCharacterSize(42);
	next.setFont(font);
	next.setString("Next");
	next.setPosition(400, 470);
	next.setFillColor(Color(210, 110, 60, 255));
	next.setCharacterSize(110);
	Text timer;
	int timee = 0;
	timer.setString("Time : 00: " + to_string(timee));
	timer.setFont(font);
	timer.setCharacterSize(50);
	timer.setFillColor(Color::White);
	timer.setPosition(280, 5);
	//SOUND
	SoundBuffer buff;
	buff.loadFromFile("soundclick (1).wav");
	Sound sound;
	sound.setBuffer(buff);
	Music music;
	music.openFromFile("game music.wav");
	music.play();
	music.setLoop(true);
	Texture red, yellow, blue, orange;
	red.loadFromFile("redball.png");
	yellow.loadFromFile("yellowball.png");
	blue.loadFromFile("blueball.png");
	orange.loadFromFile("orangeball.png");
	int count = 0;
	//TRIANGLE SHAPE
	for (int row = 0; row < 8; row++)
	{
		if (row == 0)
		{
			for (int col = 2; col < 17; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 55);
			}
		}
		if (row == 1)
		{
			for (int col = 3; col < 16; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 105);
			}
		}
		if (row == 2)
		{
			for (int col = 4; col < 15; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 153);
			}
		}
		if (row == 3)
		{
			for (int col = 5; col < 14; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 205);
			}
		}
		if (row == 4)
		{
			for (int col = 6; col < 13; col++)
			{
				upper_ball_colors[row][col].setTexture(redd);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 260);
			}
		}
		if (row == 5)
		{
			for (int col = 7; col < 12; col++)
			{
				upper_ball_colors[row][col].setTexture(yelow);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 308);
			}
		}
		if (row == 6)
		{
			for (int col = 8; col < 11; col++)
			{
				upper_ball_colors[row][col].setTexture(orangee);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 355);
			}
		}
		if (row == 7)
		{
			for (int col = 9; col < 10; col++)
			{
				upper_ball_colors[row][col].setTexture(cyann);
				upper_ball_colors[row][col].setScale(0.5, 0.5);
				upper_ball_colors[row][col].setPosition(50 * col, 407);
			}
		}
	} //end of loop
	counter = 0;
	int time;
	Clock clock;
	time = 60;
	bool screenCollision = false;
	timee = 0;

	inputfromfile();
	aa1.setString(names[0] + "   " + scoreeeee[0]);
	aa2.setString(names[1] + "   " + scoreeeee[1]);

	aa3.setString(names[2] + "   " + scoreeeee[2]);

	aa4.setString(names[3] + "   " + scoreeeee[3]);

	aa5.setString(names[4] + "   " + scoreeeee[4]);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.KeyPressed)
			{
				point.setPosition(Mouse::getPosition(window).x,
					Mouse::getPosition(window).y);
				if (point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
				{
					sstart.setFillColor(Color(0, 0, 0, 255));
				}
				else
					sstart.setFillColor(Color(90, 60, 80, 255));
				if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
				{
					play.setFillColor(Color(0, 0, 0, 255));
				}
				else
					play.setFillColor(Color(100, 100, 50, 255));
				if (point.getGlobalBounds().intersects(high.getGlobalBounds()))
				{
					high.setFillColor(Color(0, 0, 0, 255));
				}
				else
					high.setFillColor(Color(100, 100, 50, 255));
				if (point.getGlobalBounds().intersects(how.getGlobalBounds()))
				{
					how.setFillColor(Color(0, 0, 0, 255));
				}
				else
					how.setFillColor(Color(100, 100, 50, 255));
				if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
				{
					exit.setFillColor(Color(0, 0, 0, 255));
				}
				else
					exit.setFillColor(Color(100, 100, 50, 255));
				if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
				{
					next.setFillColor(Color(0, 0, 0, 255));
				}
				else
					next.setFillColor(Color(100, 100, 50, 255));
				if (point.getGlobalBounds().intersects(backh.getGlobalBounds()))
				{
					backh.setFillColor(Color(0, 0, 0, 255));
				}
				else
					backh.setFillColor(Color(90, 60, 80, 255));
				if (point.getGlobalBounds().intersects(howback.getGlobalBounds()))
				{
					howback.setFillColor(Color(0, 0, 0, 255));
				}
				else
					howback.setFillColor(Color(90, 60, 80, 255));
				if (point.getGlobalBounds().intersects(winhigh.getGlobalBounds()))
				{
					winhigh.setFillColor(Color(0, 0, 0, 255));
				}
				else
					winhigh.setFillColor(Color(90, 60, 80, 255));
			}
			//move between padges
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (count == 0)
				{
					if
						(point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
					break;
				}
				if (count == 1)
				{
					if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
					{
						sound.play();
						count = 4;
					}
					if (point.getGlobalBounds().intersects(high.getGlobalBounds()))
					{
						sound.play();
						count = 3;
					}
					if (point.getGlobalBounds().intersects(how.getGlobalBounds()))
					{
						sound.play();
						count = 5;
					}
					if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
					{
						sound.play();
						count = 0;
					}
					break;
				}
				if (count == 3)
				{
					if
						(point.getGlobalBounds().intersects(backh.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
				}
				if (count == 5)
				{
					if
						(point.getGlobalBounds().intersects(howback.getGlobalBounds()))
					{
						sound.play();
						count = 1;
					}
				}
				if (count == 6)
				{
					if
						(point.getGlobalBounds().intersects(winhigh.getGlobalBounds()))
					{
						sound.play();
						count = 3;
					}
					break;
				}
			}
			// MOVE BETWEEN BADGES
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mouseposition = Mouse::getPosition(window); //to show pos on consol
					cout << mouseposition.x << " " << mouseposition.y;
			}
			//enter player name
			if (event.type == Event::TextEntered)
			{
				if (count == 4)
				{
					if (isprint(event.text.unicode) && input_text.size() < 7)
						input_text += event.text.unicode;
				}
			}
			text.setString(input_text);
			for (int i = 0;i < 15;i++)
			{
				if (input_text == gameplayer.player_name)
				{
					playindex = i;
					break;
				}
				else
				{
					gameplayer.player_name = input_text;
					playindex = i;
					break;
				}
			}
			if (input_text.size() == 0)
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
					{
						sound.play();
						count = 4;
					}
				}
			}
			else if ((input_text.size() < 8))
			{
				if (Mouse::isButtonPressed(Mouse::Left))
				{
					if (point.getGlobalBounds().intersects(next.getGlobalBounds()))
					{
						sound.play();
						count = 2;
					}
				}
			}
			timee = time - clock.getElapsedTime().asSeconds();
			timer.setString("Time : 00: " + to_string(timee));
			//move function of the ball
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					click = true;
				}
			}
			if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					click = false;
				}
			}
			if (click)
			{
				set_pos_ball(counter, ball.shooting_ball, window);
			}
			//Collision of ball with the upper balls
			for (int i = 0; i < 25; i++)
			{
				if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[0][i].getGlobalBounds()))
				{
					if (ball.shooting_ball[counter].getTexture() == &redd &&upper_ball_colors[0][i].getTexture()== &redd)
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
						gameplayer.player_score = gameplayer.player_score + (scorecounter * 10);
						scoree.setString("score :" + to_string(gameplayer.player_score));
						if (gameplayer.high_score < gameplayer.player_score)
						{
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;
							
						}
						// gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &redd &&
						upper_ball_colors[0][i].getTexture() != &redd)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number0++;
						upper_ball_colors[0][ball.column_number0].setTexture(redd);
						upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
						upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number0++;
						if (ball.shooting_ball[counter].getTexture() == &yelow)
							upper_ball_colors[0][ball.column_number0].setTexture(yelow);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[0][ball.column_number0].setTexture(cyann);
						else
							upper_ball_colors[0][ball.column_number0].setTexture(orangee);
						upper_ball_colors[0][ball.column_number0].setScale(0.5, 0.5);
						upper_ball_colors[0][ball.column_number0].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[0][ball.column_number0].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[1][i].getGlobalBounds()))
				{
					if (ball.shooting_ball[counter].getTexture() == &yelow &&
						upper_ball_colors[1][i].getTexture() == &yelow)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
						//gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &yelow &&
						upper_ball_colors[1][i].getTexture() != &yelow)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number1++;
						upper_ball_colors[1][ball.column_number1].setTexture(yelow);
						upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
						upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number1++;
						if (ball.shooting_ball[counter].getTexture() == &redd)
							upper_ball_colors[1][ball.column_number1].setTexture(redd);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[1][ball.column_number1].setTexture(cyann);
						else
							upper_ball_colors[1][ball.column_number1].setTexture(orangee);
						upper_ball_colors[1][ball.column_number1].setScale(0.5, 0.5);
						upper_ball_colors[1][ball.column_number1].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[1][ball.column_number1].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
						scorecounter = 0;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[2][i].getGlobalBounds()))
						
				{
					if (ball.shooting_ball[counter].getTexture() == &orangee &&
						upper_ball_colors[2][i].getTexture() == &orangee)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
					}
					else if (ball.shooting_ball[counter].getTexture() == &orangee
						&&
						upper_ball_colors[2][i].getTexture() != &orangee)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number2++;
						upper_ball_colors[2][ball.column_number2].setTexture(orangee);
						upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
						upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number2++;
						if (ball.shooting_ball[counter].getTexture() == &yelow)
							upper_ball_colors[2][ball.column_number2].setTexture(yelow);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[2][ball.column_number2].setTexture(cyann);
						else
							upper_ball_colors[2][ball.column_number2].setTexture(redd);
						upper_ball_colors[2][ball.column_number2].setScale(0.5, 0.5);
						upper_ball_colors[2][ball.column_number2].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[2][ball.column_number2].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[3][i].getGlobalBounds()))
						
				{
					if (ball.shooting_ball[counter].getTexture() == &cyann &&
						upper_ball_colors[3][i].getTexture() == &cyann)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
						//gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &cyann &&
						upper_ball_colors[3][i].getTexture() != &cyann)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number3++;
						upper_ball_colors[3][ball.column_number3].setTexture(cyann);
						upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
						upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number3++;
						if (ball.shooting_ball[counter].getTexture() == &yelow)
							upper_ball_colors[3][ball.column_number3].setTexture(yelow);
						else if (ball.shooting_ball[counter].getTexture() ==
							&redd)
							upper_ball_colors[3][ball.column_number3].setTexture(redd);
						else
							upper_ball_colors[3][ball.column_number3].setTexture(orangee);
						upper_ball_colors[3][ball.column_number3].setScale(0.5, 0.5);
						upper_ball_colors[3][ball.column_number3].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[3][ball.column_number3].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[4][i].getGlobalBounds()))
						
				{
					if (ball.shooting_ball[counter].getTexture() == &redd &&
						upper_ball_colors[4][i].getTexture()
						== &redd)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
						// gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &redd &&
						upper_ball_colors[4][i].getTexture() != &redd)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number4++;
						upper_ball_colors[4][ball.column_number4].setTexture(redd);
						upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
						upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number4++;
						if (ball.shooting_ball[counter].getTexture() == &yelow)
							upper_ball_colors[4][ball.column_number4].setTexture(yelow);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[4][ball.column_number4].setTexture(cyann);
						else
							upper_ball_colors[4][ball.column_number4].setTexture(orangee);
						upper_ball_colors[4][ball.column_number4].setScale(0.5, 0.5);
						upper_ball_colors[4][ball.column_number4].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[4][ball.column_number4].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[5][i].getGlobalBounds()))
						
				{
					if (ball.shooting_ball[counter].getTexture() == &yelow &&
						upper_ball_colors[5][i].getTexture() == &yelow)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
						// gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &yelow &&
						upper_ball_colors[5][i].getTexture() != &yelow)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number0++;
						upper_ball_colors[5][ball.column_number5].setTexture(yelow);
						upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
						upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number5++;
						if (ball.shooting_ball[counter].getTexture() == &redd)
							upper_ball_colors[5][ball.column_number5].setTexture(redd);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[5][ball.column_number5].setTexture(cyann);
						else
							upper_ball_colors[5][ball.column_number5].setTexture(orangee);
						upper_ball_colors[5][ball.column_number5].setScale(0.5, 0.5);
						upper_ball_colors[5][ball.column_number5].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[5][ball.column_number5].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[6][i].getGlobalBounds()))
						
				{
					if (ball.shooting_ball[counter].getTexture() == &orangee &&
						upper_ball_colors[6][i].getTexture() == &orangee)
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
							a = gameplayer.high_score;
							gameplayer.high_score = gameplayer.player_score;

						}
						//gameplayer[playindex].high_score += scoreint;
					}
					else if (ball.shooting_ball[counter].getTexture() == &orangee
						&&
						upper_ball_colors[6][i].getTexture() != &orangee)
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number6++;
						upper_ball_colors[6][ball.column_number6].setTexture(orangee);
						upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
						upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
					else
					{
						ball.shooting_ball[counter].move(0, 0);
						ball.column_number6++;
						if (ball.shooting_ball[counter].getTexture() == &yelow)
							upper_ball_colors[6][ball.column_number6].setTexture(yelow);
						else if (ball.shooting_ball[counter].getTexture() ==
							&cyann)
							upper_ball_colors[6][ball.column_number6].setTexture(cyann);
						else
							upper_ball_colors[6][ball.column_number6].setTexture(redd);
						upper_ball_colors[6][ball.column_number6].setScale(0.5, 0.5);
						upper_ball_colors[6][ball.column_number6].setPosition(ball.shooting_ball[counter].getPosition(
						));
						upper_ball_colors[6][ball.column_number6].setOrigin(ball.shooting_ball[counter].getOrigin());
						ball.shooting_ball[counter].setScale(0, 0);
						counter++;
					}
				}
				else if
					(ball.shooting_ball[counter].getGlobalBounds().intersects(upper_ball_colors[7][i].getGlobalBounds()))
						
				{
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
					upper_ball_colors[7][ball.column_number7].setPosition(ball.shooting_ball[counter].getPosition(
					));
					upper_ball_colors[7][ball.column_number7].setOrigin(ball.shooting_ball[counter].getOrigin());
					ball.shooting_ball[counter].setScale(0, 0);
					counter++;
				}
			}
		}
		score_max.setFont(font);
		score_max.setPosition(400, 400);
		score_max.setFillColor(Color::White);
		score_max.setString("HighScore::" + to_string(gameplayer.high_score));
		window.clear();
		if (count == 0)
		{
			window.draw(back); //first page
			window.draw(bub);
			window.draw(st);
			window.draw(sstart);
			window.draw(ani);
			window.draw(point);
			////WIIIN
			//window.draw(congrt);
			//window.draw(winscor);
			//window.draw(ani);
		}
		if (count == 1)
		{
			window.draw(back);
			window.draw(men);
			window.draw(howp);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom); //second page
			window.draw(bu[0]);
			window.draw(bu[1]);
			window.draw(bu[2]);
			window.draw(play);
			window.draw(exit);
			window.draw(high);
			window.draw(how);
			window.draw(point);
		}
		if (count == 2) //play page
		{
			window.draw(backs);
			window.draw(grou);
			window.draw(ball.shooting_ball[counter]);
			window.draw(cannon_sprite);
			window.draw(leve);
			// window.draw(score);
			window.draw(animat);
			window.draw(timer);
			window.draw(scoree);
			for (int row = 0; row < 8; row++)
			{
				for (int col = 2; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 16)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
						> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 1; row < 8; row++)
			{
				for (int col = 3; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 15)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
							> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 2; row < 8; row++)
			{
				for (int col = 4; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 14)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
						> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 3; row < 8; row++)
			{
				for (int col = 5; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 13)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
							> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 4; row < 8; row++)
			{
				for (int col = 6; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 12)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
						> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 5; row < 8; row++)
			{
				for (int col = 7; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 11)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
						> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int row = 6; row < 8; row++)
			{
				for (int col = 8; col < 25; col++)
				{
					window.draw(upper_ball_colors[row][col]);
					if (col > 10)
					{
						if (upper_ball_colors[row][col].getScale().x > 0 &&
							upper_ball_colors[row][col].getScale().y
							> 0)
						{
							window.draw(upper_ball_colors[row][col]);
						}
						else
							continue;
					}
				}
			}
			for (int i = 23; i >= 0; i--)
				window.draw(ball.shooting_ball[i]);
			for (int row = 0; row < 20; row++)
			{
				for (int col = 0; col < 25; col++)
				{
					if (timee > 0 && collided)
					{
						//win window
						count = 6;
					}
					if (timee <= 0 && !(collided))
					{
						cout << "lose" << endl;
						timer.setString("Time : 00:00 ");
					}
				}
			}
			winssssscore.setFont(ffont);
			winssssscore.setString("your score :" + to_string(gameplayer.player_score));
			winssssscore.setPosition(400, 350);
			winssssscore.setFillColor(Color::Black);
			/*aa.setFont(ffont);
			aa.setString("your score :" + to_string(gameplayer.player_score));
			aa.setPosition(400, 350);
			aa.setFillColor(Color::Black);*/
		}
		if (count == 3)
		{
		

			
			//aa2.setString(names[1]);

			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom); //highscore
			window.draw(hig);
			window.draw(hs);
			window.draw(kas);
			window.draw(backh);
			window.draw(point);
			window.draw(aa1);
			window.draw(aa2);
			window.draw(aa3);
			window.draw(aa4);
			window.draw(aa5);
		}
		if (count == 4) //Name page
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(hello);
			window.draw(name);
			window.draw(bnam);
			window.draw(text);
			window.draw(next);
			window.draw(point);
		}
		if (count == 5) //how to play
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(bhoow);
			window.draw(howback);
			window.draw(point);
		}
		if (count == 6)
		{
			window.draw(back);
			window.draw(mon);
			window.draw(mon2);
			window.draw(sen);
			window.draw(pom);
			window.draw(congrt);
			window.draw(winscor);
			window.draw(ani);
			window.draw(winhigh);
			window.draw(point);
			scoree.setString("score :" + to_string(gameplayer.player_score));
			window.draw(winssssscore);
		}
		window.display();
	}
	savetofile(gameplayer,a);
	return 0;
}