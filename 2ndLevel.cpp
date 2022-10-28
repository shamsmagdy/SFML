//#include<SFML/Graphics.hpp>
//#include<iostream>
//#include<SFML/Audio.hpp>
//#include <fstream>
//using namespace std;
//using namespace sf;
//
//void main()
//{
//	RenderWindow window2(VideoMode(1000, 800), "bubble shooter2");
//	Texture purple, black, green, DarkBlue;
//
//	purple.loadFromFile("ball 10.png");
//	black.loadFromFile("ball 4.png");                                             /*TEXTURES*/
//	green.loadFromFile("ball 7.png");
//	DarkBlue.loadFromFile("ball 2.png");
//
//	Sprite arr2[6][8];
//	for (int row = 0;row < 6;row++)
//	{
//		if(row==0)
//		{
//			for (int col = 0;col < 4;col++)
//			{
//				arr2[row][col].setTexture(purple);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 100);
//			}
//			for (int col = 4;col < 8;col++)
//			{
//				arr2[row][col].setTexture(black);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 100);
//			}
//		}
//		
//		if (row == 1)
//		{
//			for (int col = 0;col < 4;col++)
//			{
//				arr2[row][col].setTexture(green);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 200);
//			}
//
//			for (int col = 4;col < 8;col++)
//			{
//				arr2[row][col].setTexture(DarkBlue);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 200);
//			}
//		}
//
//		if (row == 2)
//		{
//			for (int col = 0;col < 4;col++)
//			{
//				arr2[row][col].setTexture(purple);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 300);
//			}
//
//			for (int col = 4;col < 8;col++)
//			{
//				arr2[row][col].setTexture(black);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 300);
//			}
//		}
//
//		if (row == 3)
//		{
//			for (int col = 0;col < 4;col++)
//			{
//				arr2[row][col].setTexture(green);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 400);
//			}
//
//			for (int col = 4;col < 8;col++)
//			{
//				arr2[row][col].setTexture(DarkBlue);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 400);
//			}
//		}
//
//		if (row == 4)
//		{
//			for (int col = 0;col < 4;col++)
//			{
//				arr2[row][col].setTexture(purple);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 500);
//			}
//
//			for (int col = 4;col < 8;col++)
//			{
//				arr2[row][col].setTexture(black);
//				arr2[row][col].setScale(0.5, 0.5);
//				arr2[row][col].setPosition(col * 55, 500);
//			}
//		}
//		while (window2.isOpen())
//		{
//			Event event;
//			while (window2.pollEvent(event));
//			{
//				if (event.type == Event::Closed)
//					window2.close();
//
//			}
//
//			for (int row = 0;row < 6;row++)
//			{
//				for (int col = 0;col < 8;col++)
//				{
//					window2.draw(arr2[row][col]);
//				}
//			}
//			
//			window2.display();
//
//
//
//
//
//
//		}
//
//
//
//	}
//
//
//
//
//}