//#include<SFML/Graphics.hpp>
//#include<iostream>
//#include<SFML/Audio.hpp>
//
//using namespace std;
//using namespace sf;
//void main()
//{
//
//	RenderWindow window(VideoMode(1000, 800), "bubble shooter");
//	Texture red, yellow, blue, orange;
//	red.loadFromFile("redball.png");
//	yellow.loadFromFile("yellowball.png");
//	blue.loadFromFile("blueball.png");
//	orange.loadFromFile("orangeball.png");
//
//
//
//	int score = 0;
//	int col = 0;
//	Sprite arr[20][25];
//	for (int row = 0; row < 8; row++)
//	{
//		if (row == 0)
//		{
//			for (int col = 0; col < 24; col++)
//			{
//				arr[row][col].setTexture(red);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 55);
//				if (col == 16)
//				{
//					break;
//
//				}
//			}
//		}
//		if (row == 1)
//		{
//			for (int col = 3; col < 24; col++)
//			{
//				arr[row][col].setTexture(yellow);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 105);
//				if (col == 15)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 2)
//		{
//			for (int col = 4; col < 24; col++)
//			{
//				arr[row][col].setTexture(orange);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 153);
//				if (col == 14)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 3)
//		{
//			for (int col = 5; col < 24; col++)
//			{
//				arr[row][col].setTexture(blue);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 205);
//				if (col == 13)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 4)
//		{
//			for (int col = 6; col < 24; col++)
//			{
//				arr[row][col].setTexture(red);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 260);
//				if (col == 12)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 5)
//		{
//			for (int col = 7; col < 24; col++)
//			{
//				arr[row][col].setTexture(yellow);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 308);
//				if (col == 11)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 6)
//		{
//			for (int col = 8; col < 24; col++)
//			{
//				arr[row][col].setTexture(orange);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 355);
//				if (col == 10)
//				{
//					break;
//
//				}
//			}
//		}
//
//		if (row == 7)
//		{
//			for (int col = 9; col < 24; col++)
//			{
//				arr[row][col].setTexture(blue);
//				arr[row][col].setScale(0.5, 0.5);
//				arr[row][col].setPosition(50 * col, 407);
//				if (col == 9)
//				{
//					break;
//
//				}
//			}
//		}
//
//
//	}    //end forloop
//
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//
//		}
//
//	
//
//		for (int row = 0; row < 8; row++)
//		{
//			for (int col = 2; col < 17; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 1; row < 8; row++)
//		{
//			for (int col = 3; col < 15; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 2; row < 8; row++)
//		{
//			for (int col = 4; col < 14; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 3; row < 8; row++)
//		{
//			for (int col = 5; col < 13; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 4; row < 8; row++)
//		{
//			for (int col = 6; col < 12; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 5; row < 8; row++)
//		{
//			for (int col = 7; col < 11; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		for (int row = 6; row < 8; row++)
//		{
//			for (int col = 8; col < 10; col++)
//			{
//				window.draw(arr[row][col]);
//			}
//		}
//
//		window.display();
//	}
//
//}