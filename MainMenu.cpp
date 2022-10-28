//# include <iostream>
//# include <ctime>
//# include <cstdlib>
//# include <SFML/Graphics.hpp>
//# include <SFML/Audio.hpp>
//#include <fstream>
//#include <string>
//using namespace sf;
//using namespace std;
//
//
//#define maxmainmenu  3
//
//using namespace std;
//using namespace sf;
//struct ball
//{
//    Sprite colors[18];             //sruct for balls
//}ball1, ball2, ball3, ball4;
//
//Sprite clrs[24];
//
//int count = 0;
//int main()
//{
//
//    RenderWindow window(VideoMode(1000, 800), "bubble shooter");
//    window.setFramerateLimit(30);
//    //variable declaration
//
//    int animator = 0;
//    int counter;
//    //bool right = false, left = false, middle = false;
//    //textures
//    int maxscore = 0;
//    Font highhh;
//    highhh.loadFromFile("Montague.ttf");
//    Text HighScore,scorepage;
//    HighScore.setFont(highhh);
//    scorepage.setFont(highhh);
//    scorepage.setFillColor(Color::White);
//    int scoree = 0;
//    HighScore.setString("score :" + to_string(scoree));
//    HighScore.setPosition(0, 0);
//    HighScore.setFillColor(Color::White);
//    HighScore.setCharacterSize(50);
//    scorepage.setString("best score :\n" + to_string(maxscore));
//    scorepage.setCharacterSize(40);
//    scorepage.setPosition(400, 400);
//    scoree += 10;
//    fstream myfile;                                                           /*FILE OPENING*/
//    myfile.open("Hscore.txt", ios::out);
//
//  
//
//    Texture redd, yelow, cyann, orangee, backk, cannon_sheet, cannon_base;
//    redd.loadFromFile("redball.png");
//    yelow.loadFromFile("yellowball.png");
//    cyann.loadFromFile("blueball.png");
//    orangee.loadFromFile("orangeball.png");
//    backk.loadFromFile("background.jpeg");
//    cannon_base.loadFromFile("cannon base.png");
//    cannon_sheet.loadFromFile("Cannon spritesheet.png");
//
//    //sprites
//
//    Sprite backs, base, cannon_sprite;
//    backs.setTexture(backk);
//    base.setTexture(cannon_base);
//    base.setOrigin(123, 74);
//    base.setPosition(500, 750);
//    cannon_sprite.setTexture(cannon_sheet);
//    cannon_sprite.setPosition(423, 580);
//    cannon_sprite.setTextureRect(IntRect(animator * 104, 0, 104, 144));
//
//    //filling array of cannon balls with sprites
//
//    for (int i = 0; i < 20; i += 4)
//    {
//        clrs[i].setTexture(redd);
//        clrs[i].setScale(0, 0);
//        clrs[i].setPosition(497, 740);
//        clrs[i].setOrigin(65, 55);
//    }
//
//    for (int i = 1; i < 21; i += 4)
//    {
//        clrs[i].setTexture(yelow);
//        clrs[i].setScale(0, 0);
//        clrs[i].setPosition(497, 740);
//        clrs[i].setOrigin(65, 55);
//    }
//
//    for (int i = 2; i < 22; i += 4)
//    {
//        clrs[i].setTexture(cyann);
//        clrs[i].setScale(0, 0);
//        clrs[i].setPosition(497, 740);
//        clrs[i].setOrigin(58, 58);
//    }
//
//    for (int i = 3; i < 23; i += 4)
//    {
//        clrs[i].setTexture(orangee);
//        clrs[i].setScale(0, 0);
//        clrs[i].setPosition(497, 740);
//        clrs[i].setOrigin(58, 53);
//    }
//
//    /*int num = 2;
//    int range = 24;
//    vector<int> rand_vector;
//    for (int i = 0; i < range; i++)
//    {
//        rand_vector.push_back(i);
//    }*/
//
//    Texture background, bubble, start, animal, menu, monkey, monkey2, senjap, poma, bubb, buuu, highh, hscore;
//    Texture blueball, redball, yellowball, orangeball, backimage, kass, level, animation, ground, pointer;
//    background.loadFromFile("back1.jpg");
//    bubble.loadFromFile("bubblee.png");
//    start.loadFromFile("bstart.png");
//    animal.loadFromFile("animals.png");
//    menu.loadFromFile("menuu.png");
//    monkey.loadFromFile("monkey.png");              //loading images
//    monkey2.loadFromFile("monkey2.png");
//    senjap.loadFromFile("senjapc.png");
//    poma.loadFromFile("boma.png");
//    bubb.loadFromFile("bubb.png");
//    buuu.loadFromFile("buuu.png");
//    blueball.loadFromFile("blueball.png");
//    redball.loadFromFile("redball.png");
//    yellowball.loadFromFile("yellowball.png");
//    orangeball.loadFromFile("orangeball.png");
//    backimage.loadFromFile("backk.jpeg");
//    highh.loadFromFile("high.jpg");
//    kass.loadFromFile("kaas.png");
//    level.loadFromFile("levels.png");
//    animation.loadFromFile("anim.png");
//    ground.loadFromFile("groundd.jpg");
//    pointer.loadFromFile("mouse.png");
//
//    Sprite back, bub, st, ani, men, mon, mon2, sen, pom, bu[3], buu, b, hig, kas, lev, animat, grou, point;
//    back.setTexture(background);
//    back.setScale(1.8, 1);
//    bub.setTexture(bubble);
//    bub.setScale(0.8, 0.8);
//    bub.setPosition(270, 90);
//    st.setTexture(start);
//    st.setPosition(390, 410);
//    st.setScale(0.7, 0.7);
//    ani.setTexture(animal);
//    ani.setPosition(370, 460);
//    ani.setScale(0.7, 0.7);
//    men.setTexture(menu);
//    men.setPosition(280, 150);
//    men.setScale(1, 1);
//    mon.setTexture(monkey);
//    mon.setPosition(700, 70);
//    mon.setScale(0.6, 0.6);
//    mon2.setTexture(monkey2);
//    mon2.setPosition(60, 10);
//    mon2.setScale(0.4, 0.4);
//    sen.setTexture(senjap);
//    sen.setPosition(130, 590);
//    sen.setScale(0.3, 0.3);
//    sen.setRotation(-30);
//    pom.setTexture(poma);
//    pom.setPosition(688, 27);
//    pom.setScale(0.3, 0.3);
//    for (int i = 0; i < 3; i++)
//    {
//        bu[i].setTexture(bubb);         //loop for repeat this image 
//        bu[i].setScale(0.9, 0.9);
//    }
//    bu[0].setPosition(550, 250);
//    bu[1].setPosition(250, 100);
//    bu[2].setPosition(220, 350);
//    buu.setTexture(buuu);
//    buu.setPosition(610, 480);
//    buu.setScale(0.6, 0.6);
//    buu.setRotation(-25);
//    b.setTexture(backimage);
//    b.setScale(1.8, 1);
//    hig.setTexture(highh);
//    hig.setPosition(300, 240);
//    hig.setScale(1.6, 1.6);
//    kas.setTexture(kass);
//    kas.setPosition(310, 570);
//    kas.setScale(0.9, 0.9);
//    lev.setTexture(level);
//    lev.setPosition(0, 0);
//    lev.setScale(0.6, 0.6);
//    animat.setTexture(animation);
//    animat.setPosition(50, 600);
//    animat.setScale(1, 1);
//    grou.setTexture(ground);
//    grou.setPosition(0, 735);
//    grou.setScale(7, 1);
//    point.setTexture(pointer);
//    point.setPosition(100, 100);
//    point.setScale(0.3, 0.3);
//
//    Font font, ffont;
//    font.loadFromFile("font.ttf");
//    ffont.loadFromFile("hhhh.ttf");
//
//    Text sstart, play, exit, high, hs, leve, score;
//    sstart.setFont(font);
//    sstart.setString("START");
//    sstart.setPosition(420, 405);
//    sstart.setFillColor(Color(90, 60, 80, 255));
//    sstart.setCharacterSize(65);
//    play.setFont(font);
//    play.setString("Play");
//    play.setPosition(460, 165);
//    play.setCharacterSize(80);
//    play.setFillColor(Color(100, 100, 50, 255));
//    exit.setString("Back");
//    exit.setFont(font);
//    exit.setPosition(475, 410);
//    exit.setFillColor(Color(100, 100, 50, 255));
//    exit.setCharacterSize(85);
//    high.setString("High Score");
//    high.setFont(font);
//    high.setPosition(310, 310);
//    high.setFillColor(Color(100, 100, 50, 255));
//    high.setCharacterSize(47);
//    hs.setFont(ffont);
//    hs.setString("HIGH SCORE");
//    hs.setPosition(280, 130);
//    hs.setFillColor(Color(210, 110, 60, 255));
//    hs.setCharacterSize(75);
//    leve.setFont(ffont);
//    leve.setString("level: 1");
//    leve.setPosition(15, 0);
//    leve.setCharacterSize(50);
//    leve.setFillColor(Color(255, 255, 255, 255));
//    score.setFont(ffont);
//    score.setString("Score :");
//    score.setPosition(750, 0);
//    score.setFillColor(Color::White);
//    score.setCharacterSize(50);
//
//
//
//
//    SoundBuffer buff;
//    buff.loadFromFile("soundclick (1).wav");
//    Sound sound;
//    sound.setBuffer(buff);
//    Music music;
//    music.openFromFile("game music.wav");
//    music.play();
//    music.setLoop(true);
//
//    int count = 0;
//
//
//
//
//    Texture red, yellow, blue, orange;
//    red.loadFromFile("redball.png");
//    yellow.loadFromFile("yellowball.png");
//    blue.loadFromFile("blueball.png");
//    orange.loadFromFile("orangeball.png");
//
//
//    /* int scoree = 0;*/
//    int col = 0;
//
//    Sprite arr[20][25];
//
//    for (int row = 0; row < 8; row++)
//    {
//        if (row == 0)
//        {
//            for (int col = 0; col < 24; col++)
//            {
//                arr[row][col].setTexture(red);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 55);
//                if (col == 16)
//                {
//                    break;
//
//                }
//            }
//        }
//        if (row == 1)
//        {
//            for (int col = 3; col < 24; col++)
//            {
//                arr[row][col].setTexture(yellow);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 105);
//                if (col == 15)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 2)
//        {
//            for (int col = 4; col < 24; col++)
//            {
//                arr[row][col].setTexture(orange);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 153);
//                if (col == 14)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 3)
//        {
//            for (int col = 5; col < 24; col++)
//            {
//                arr[row][col].setTexture(blue);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 205);
//                if (col == 13)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 4)
//        {
//            for (int col = 6; col < 24; col++)
//            {
//                arr[row][col].setTexture(red);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 260);
//                if (col == 12)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 5)
//        {
//            for (int col = 7; col < 24; col++)
//            {
//                arr[row][col].setTexture(yellow);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 308);
//                if (col == 11)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 6)
//        {
//            for (int col = 8; col < 24; col++)
//            {
//                arr[row][col].setTexture(orange);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 355);
//                if (col == 10)
//                {
//                    break;
//
//                }
//            }
//        }
//
//        if (row == 7)
//        {
//            for (int col = 9; col < 24; col++)
//            {
//                arr[row][col].setTexture(blue);
//                arr[row][col].setScale(0.5, 0.5);
//                arr[row][col].setPosition(50 * col, 407);
//                if (col == 9)
//                {
//                    break;
//
//                }
//            }
//        }
//
//
//    }
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//            if (Keyboard::isKeyPressed(Keyboard::Right))
//            {
//                scoree += 10;
//
//                HighScore.setString("score :" + to_string(scoree));
//                if (scoree > maxscore)
//                {
//                    maxscore = scoree;
//                    myfile.open("Hscore.txt");
//                }
//
//                myfile << maxscore;
//                myfile.close();
//                scorepage.setString("best score :\n" + to_string(maxscore));
//
//
//            }
//            counter = 0;
//
//            //bool click;
//
//
//
//            if (event.KeyPressed)
//            {
//                point.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
//
//                if (point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
//                {
//                    sstart.setFillColor(Color(0, 0, 0, 255));
//                }
//                else
//                    sstart.setFillColor(Color(90, 60, 80, 255));
//
//
//                if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
//                {
//                    play.setFillColor(Color(0, 0, 0, 255));
//
//                }
//                else
//                    play.setFillColor(Color(100, 100, 50, 255));
//
//                if (point.getGlobalBounds().intersects(high.getGlobalBounds()))
//                {
//                    high.setFillColor(Color(0, 0, 0, 255));
//
//                }
//                else
//                    high.setFillColor(Color(100, 100, 50, 255));
//                if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
//                {
//                    exit.setFillColor(Color(0, 0, 0, 255));
//
//                }
//                else
//                    exit.setFillColor(Color(100, 100, 50, 255));
//
//            }
//
//            if (Mouse::isButtonPressed(Mouse::Left))
//            {
//                if (count == 0)
//                {
//                    if (point.getGlobalBounds().intersects(sstart.getGlobalBounds()))
//                    {
//                        sound.play();
//                        count = 1;
//                    }
//                    break;
//                }
//
//                if (count == 1)
//                {
//                    if (point.getGlobalBounds().intersects(play.getGlobalBounds()))
//                    {
//                        sound.play();
//                        count = 2;
//                    }
//
//
//                    if (point.getGlobalBounds().intersects(high.getGlobalBounds()))
//                    {
//                        sound.play();
//                        count = 3;
//                    }
//
//                    if (point.getGlobalBounds().intersects(exit.getGlobalBounds()))
//                    {
//                        sound.play();
//                        count = 0;
//                    }
//
//
//                }
//
//
//
//
//            }
//            // MOVE BETWEEN BADGES
//            if (Mouse::isButtonPressed(Mouse::Left))
//            {
//                Vector2i mouseposition = Mouse::getPosition(window);     //to show pos on consol
//                cout << mouseposition.x << " " << mouseposition.y;
//            }
//
//        }
//        window.clear();
//
//        if (count == 0)
//        {
//            window.draw(back);             //first page
//            window.draw(bub);
//            window.draw(st);
//            window.draw(sstart);
//            window.draw(ani);
//            window.draw(point);
//        }
//        if (count == 1)
//        {
//            window.draw(back);
//            window.draw(men);
//            window.draw(mon);
//            window.draw(mon2);
//            window.draw(sen);
//            window.draw(pom);                       //second page
//            window.draw(bu[0]);
//            window.draw(bu[1]);
//            window.draw(bu[2]);
//            window.draw(play);
//            window.draw(exit);
//            window.draw(high);
//            window.draw(point);
//
//        }
//        if (count == 2)                         //play page
//        {
//           
//            
//            window.draw(backs);
//            window.draw(grou);
//            window.draw(clrs[counter]);
//            //  window.draw(cannon_sprite);
//            window.draw(lev);
//            window.draw(leve);
//            window.draw(score);
//            window.draw(animat);
//            window.draw(HighScore);
//            //drawing certain ball
//
//          //  window.draw(base);
//
//            for (int i = 23; i >= 0; i--)
//                window.draw(clrs[i]);
//
//            if (counter < 24)
//                counter++;
//            for (int row = 0; row < 8; row++)
//            {
//                for (int col = 2; col < 17; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 1; row < 8; row++)
//            {
//                for (int col = 3; col < 15; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 2; row < 8; row++)
//            {
//                for (int col = 4; col < 14; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 3; row < 8; row++)
//            {
//                for (int col = 5; col < 13; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 4; row < 8; row++)
//            {
//                for (int col = 6; col < 12; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 5; row < 8; row++)
//            {
//                for (int col = 7; col < 11; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//            for (int row = 6; row < 8; row++)
//            {
//                for (int col = 8; col < 10; col++)
//                {
//                    window.draw(arr[row][col]);
//                }
//            }
//
//
//        }
//        if (count == 3)
//        {
//            window.draw(back);
//            window.draw(mon);
//            window.draw(mon2);
//            window.draw(sen);
//            window.draw(pom);             //highscore
//            window.draw(hig);
//            window.draw(hs);
//            window.draw(kas);
//            scorepage.setString("best score :\n" + to_string(maxscore));
//            
//            window.draw(scorepage);
//           
//
//
//        }
//
//        window.display();
//    }
//    return 0;
//
//}