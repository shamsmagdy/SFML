//#include<sfml/graphics.hpp>
//#include<iostream>
//#include<sfml/audio.hpp>
//#include <fstream>
//using namespace std;
//using namespace sf;
//
//struct ball
//{
//    sprite colors[18];             //sruct for balls
//}ball1, ball2, ball3, ball4;
//
//sprite clrs[24];
//
//int count = 0;
//int main()
//{
//    renderwindow window(videomode(1000, 800), "bubble shooter");
//    window.setframeratelimit(30);
//
//    int animator = 0;
//    int counter;
//
//    //textures
//
//    texture redd, yelow, cyann, orangee, backk, cannon_sheet, cannon_base;
//    redd.loadfromfile("red.png");
//    yelow.loadfromfile("yellow.png");
//    cyann.loadfromfile("ball6.png");
//    orangee.loadfromfile("orange.png");
//    backk.loadfromfile("background.jpg");
//    cannon_base.loadfromfile("cannon base.png");
//    cannon_sheet.loadfromfile("cannon spritesheet.png");
//
//    /*file opnening*/
//    fstream myfile;                                                           /*file opening*/
//    myfile.open("hscore.txt", ios::out);
//
//    //sprites
//
//    sprite backs, base, cannon_sprite;
//    backs.settexture(backk);
//    backs.setscale(1.8, 1);
//    base.settexture(cannon_base);
//    base.setorigin(123, 74);
//    base.setposition(500, 750);
//    cannon_sprite.settexture(cannon_sheet);
//    cannon_sprite.setposition(423, 580);
//    cannon_sprite.settexturerect(intrect(animator * 104, 0, 104, 144));
//
//    //filling array of cannon balls with sprites
//
//    for (int i = 0; i < 20; i += 4)
//    {
//        clrs[i].settexture(redd);
//        clrs[i].setscale(0, 0);
//        clrs[i].setposition(497, 740);
//        clrs[i].setorigin(65, 55);
//    }
//
//    for (int i = 1; i < 21; i += 4)
//    {
//        clrs[i].settexture(yelow);
//        clrs[i].setscale(0, 0);
//        clrs[i].setposition(497, 740);
//        clrs[i].setorigin(65, 55);
//    }
//
//    for (int i = 2; i < 22; i += 4)
//    {
//        clrs[i].settexture(cyann);
//        clrs[i].setscale(0, 0);
//        clrs[i].setposition(497, 740);
//        clrs[i].setorigin(58, 58);
//    }
//
//    for (int i = 3; i < 23; i += 4)
//    {
//        clrs[i].settexture(orangee);
//        clrs[i].setscale(0, 0);
//        clrs[i].setposition(497, 740);
//        clrs[i].setorigin(58, 53);
//    }
//
//
//    texture background, bubble, start, animal, menu, monkey, monkey2, senjap, poma, bubb, buuu, highh, hscore;
//    texture blueball, redball, yellowball, orangeball, backimage, kass, level, animation, ground, pointer, bname;
//    background.loadfromfile("back1.jpg");
//    bubble.loadfromfile("bubblee.png");
//    start.loadfromfile("bstart.png");
//    animal.loadfromfile("animals.png");
//    menu.loadfromfile("menuu.png");
//    monkey.loadfromfile("monkey.png");              //loading images
//    monkey2.loadfromfile("monkey2.png");
//    senjap.loadfromfile("senjapc.png");
//    poma.loadfromfile("boma.png");
//    bubb.loadfromfile("bubb.png");
//    buuu.loadfromfile("buuu.png");
//    blueball.loadfromfile("ball6.png");
//    redball.loadfromfile("redball.png");
//    yellowball.loadfromfile("yellowball.png");
//    orangeball.loadfromfile("orangeball.png");
//    backimage.loadfromfile("backk.jpeg");
//    highh.loadfromfile("high.jpg");
//    kass.loadfromfile("kaas.png");
//    animation.loadfromfile("anim.png");
//    ground.loadfromfile("groundd.jpg");
//    pointer.loadfromfile("pointerr.png");
//    bname.loadfromfile("board.png");
//
//    sprite back, bub, st, ani, men, mon, mon2, sen, pom, bu[3], buu, b, hig, kas, animat, grou, point, bnam;
//    back.settexture(background);
//    back.setscale(1.8, 1);
//    bub.settexture(bubble);
//    bub.setscale(0.8, 0.8);
//    bub.setposition(270, 90);
//    st.settexture(start);
//    st.setposition(390, 410);
//    st.setscale(0.7, 0.7);
//    ani.settexture(animal);
//    ani.setposition(370, 460);
//    ani.setscale(0.7, 0.7);
//    men.settexture(menu);
//    men.setposition(280, 150);
//    men.setscale(1, 1);
//    mon.settexture(monkey);
//    mon.setposition(700, 70);
//    mon.setscale(0.6, 0.6);
//    mon2.settexture(monkey2);
//    mon2.setposition(60, 10);
//    mon2.setscale(0.4, 0.4);
//    sen.settexture(senjap);
//    sen.setposition(130, 590);
//    sen.setscale(0.3, 0.3);
//    sen.setrotation(-30);
//    pom.settexture(poma);
//    pom.setposition(688, 27);
//    pom.setscale(0.3, 0.3);
//    for (int i = 0; i < 3; i++)
//    {
//        bu[i].settexture(bubb);         //loop for repeat this image 
//        bu[i].setscale(0.9, 0.9);
//    }
//    bu[0].setposition(550, 250);
//    bu[1].setposition(250, 100);
//    bu[2].setposition(220, 350);
//    buu.settexture(buuu);
//    buu.setposition(610, 480);
//    buu.setscale(0.6, 0.6);
//    buu.setrotation(-25);
//    b.settexture(backimage);
//    b.setscale(1.8, 1);
//    hig.settexture(highh);
//    hig.setposition(300, 240);
//    hig.setscale(1.6, 1.6);
//    kas.settexture(kass);
//    kas.setposition(310, 570);
//    kas.setscale(0.9, 0.9);
//    animat.settexture(animation);
//    animat.setposition(50, 600);
//    animat.setscale(1, 1);
//    grou.settexture(ground);
//    grou.setposition(0, 735);
//    grou.setscale(7, 1);
//    point.settexture(pointer);
//    point.setposition(100, 100);
//    point.setscale(0.3, 0.3);
//    bnam.settexture(bname);
//    bnam.setposition(340, 280);
//    bnam.setscale(0.6, 0.6);
//    int scoree = 0;
//    font font, ffont, fffont;
//    font.loadfromfile("font.ttf");
//    ffont.loadfromfile("hhhh.ttf");
//    fffont.loadfromfile("foont.ttf");
//    int maxscore = 0;
//    text sstart, play, exit, high, hs, backh, leve, score, text, next, hello, name,scorepage, highscore;
//    highscore.setfont(font);
//    scorepage.setfont(font);
//    sstart.setfont(font);
//    sstart.setstring("start");
//    sstart.setposition(420, 405);
//    sstart.setfillcolor(color(90, 60, 80, 255));
//    sstart.setcharactersize(65);
//    scorepage.setstring("best score :\n" + to_string(maxscore));
//    scorepage.setcharactersize(60);
//    scorepage.setposition(360, 230);
//    scorepage.setfillcolor(color(0, 100, 40, 255));
//   
//    play.setfont(font);
//    play.setstring("play");
//    play.setposition(460, 165);
//    play.setcharactersize(80);
//    exit.setstring("back");
//    exit.setfont(font);
//    exit.setposition(475, 410);
//    exit.setcharactersize(85);
//    high.setstring("high score");
//    high.setfont(font);
//    high.setposition(310, 310);
//    high.setcharactersize(47);
//    hs.setfont(ffont);
//    hs.setstring("high score");
//    hs.setposition(280, 130);
//    hs.setfillcolor(color(210, 110, 60, 255));
//    hs.setcharactersize(75);
//    backh.setstring("back");
//    backh.setfont(font);
//    backh.setposition(610, 670);
//    backh.setcharactersize(85);
//    leve.setfont(ffont);
//    leve.setstring("level: 1");
//    leve.setposition(15, 0);
//    leve.setcharactersize(50);
//    leve.setfillcolor(color::white);
//    score.setfont(ffont);
//    score.setstring("score :"+to_string(scoree));
//    score.setposition(750, 0);
//    score.setfillcolor(color::white);
//    score.setcharactersize(50);
//
//    //enter user name
//
//    string input_text;
//
//    text.setfont(fffont);
//    text.setposition(400, 380);
//    text.setcharactersize(50);
//    text.setfillcolor(color(0, 0, 0, 255));
//    hello.setfont(ffont);
//    hello.setstring("hello!");
//    hello.setposition(370, 110);
//    hello.setfillcolor(color(210, 110, 60, 255));
//    hello.setcharactersize(70);
//    name.setfont(ffont);
//    name.setfont(ffont);
//    name.setstring("please,enter your name");
//    name.setposition(250, 220);
//    name.setfillcolor(color(210, 110, 60, 255));
//    name.setcharactersize(42);
//    next.setfont(font);
//    next.setstring("next");
//    next.setposition(400, 470);
//    next.setfillcolor(color(210, 110, 60, 255));
//    next.setcharactersize(110);
//
//    //sound
//    soundbuffer buff;
//    buff.loadfromfile("soundclick (1).wav");
//    sound sound;
//    sound.setbuffer(buff);
//    music music;
//    music.openfromfile("game music.wav");
//    music.play();
//    music.setloop(true);
//
//    texture red, yellow, blue, orange;
//    red.loadfromfile("redball.png");
//    yellow.loadfromfile("yellowball.png");
//    blue.loadfromfile("blueball.png");
//    orange.loadfromfile("orangeball.png");
//
//
//    int count = 0;
//    int col = 0;
//    //triangle shape
//    sprite arr[20][25];
//
//    for (int row = 0; row < 8; row++)
//    {
//        if (row == 0)
//        {
//            for (int col = 0; col < 24; col++)
//            {
//                arr[row][col].settexture(red);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 55);
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
//                arr[row][col].settexture(yellow);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 105);
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
//                arr[row][col].settexture(orange);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 153);
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
//                arr[row][col].settexture(blue);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 205);
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
//                arr[row][col].settexture(red);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 260);
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
//                arr[row][col].settexture(yellow);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 308);
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
//                arr[row][col].settexture(orange);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 355);
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
//                arr[row][col].settexture(blue);
//                arr[row][col].setscale(0.5, 0.5);
//                arr[row][col].setposition(50 * col, 407);
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
//    counter = 0;
//    
//    while (window.isopen())
//    {
//        event event;
//        while (window.pollevent(event))
//        {
//            if (event.type == event::closed)
//                window.close();
//
//            if (keyboard::iskeypressed(keyboard::right)&&count==2)
//            {
//                scoree += 10;
//
//                score.setstring("score :" + to_string(scoree));
//                if (scoree > maxscore)
//                {
//                    maxscore = scoree;
//                    myfile.open("hscore.txt");
//                }
//
//                myfile << maxscore;
//                myfile.close();
//                scorepage.setstring("best score :\n" + to_string(maxscore));
//
//
//            }
//
//            if (event.keypressed)
//            {
//                point.setposition(mouse::getposition(window).x, mouse::getposition(window).y);
//
//                if (point.getglobalbounds().intersects(sstart.getglobalbounds()))
//                {
//                    sstart.setfillcolor(color(0, 0, 0, 255));
//                }
//                else
//                    sstart.setfillcolor(color(90, 60, 80, 255));
//
//
//                if (point.getglobalbounds().intersects(play.getglobalbounds()))
//                {
//                    play.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    play.setfillcolor(color(100, 100, 50, 255));
//
//                if (point.getglobalbounds().intersects(high.getglobalbounds()))
//                {
//                    high.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    high.setfillcolor(color(100, 100, 50, 255));
//                if (point.getglobalbounds().intersects(exit.getglobalbounds()))
//                {
//                    exit.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    exit.setfillcolor(color(100, 100, 50, 255));
//                if (point.getglobalbounds().intersects(next.getglobalbounds()))
//                {
//                    next.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    next.setfillcolor(color(100, 100, 50, 255));
//
//                if (point.getglobalbounds().intersects(backh.getglobalbounds()))
//                {
//                    backh.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    backh.setfillcolor(color(90, 60, 80, 255));
//
//            }
//            //move between padges
//            if (mouse::isbuttonpressed(mouse::left))
//            {
//                if (count == 0)
//                {
//                    if (point.getglobalbounds().intersects(sstart.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 1;
//                    }
//                    break;
//                }
//
//                if (count == 1)
//                {
//                    if (point.getglobalbounds().intersects(play.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 4;
//                    }
//
//                    if (point.getglobalbounds().intersects(high.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 3;
//                    }
//
//                    if (point.getglobalbounds().intersects(exit.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 0;
//                    }
//                    break;
//
//                }
//                if (count == 3)
//                {
//                    if (point.getglobalbounds().intersects(backh.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 1;
//                    }
//                }
//                if (count == 4)
//                {
//                    if (point.getglobalbounds().intersects(next.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 2;
//                    }
//
//                    break;
//                }
//
//            }
//            // move between badges
//            if (mouse::isbuttonpressed(mouse::left))
//            {
//                vector2i mouseposition = mouse::getposition(window);     //to show pos on consol
//                cout << mouseposition.x << " " << mouseposition.y;
//            }
//            //enter player name
//            if (event.type == event::textentered)
//            {
//                if (isprint(event.text.unicode))
//                    input_text += event.text.unicode;
//            }
//
//
//
//        }
//        text.setstring(input_text);
//
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
//            window.draw(pom);                 //second page
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
//            window.draw(backs);
//            window.draw(grou);
//            window.draw(clrs[counter]);
//            //window.draw(cannon_sprite);
//            window.draw(leve);
//            window.draw(score);
//            window.draw(animat);
//
//            //drawing certain ball
//
//            for (int i = 23; i >= 0; i--)
//                window.draw(clrs[i]);
//
//            if (counter < 24)
//                counter++;
//
//            //draw triangle shape
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
//            window.draw(backh);
//            window.draw(point);
//            window.draw(scorepage);
//
//        }
//        if (count == 4)             //name page
//        {
//            window.draw(back);
//            window.draw(mon);
//            window.draw(mon2);
//            window.draw(sen);
//            window.draw(pom);
//            window.draw(hello);
//            window.draw(name);
//            window.draw(bnam);
//            window.draw(text);
//            window.draw(next);
//            window.draw(point);
//
//        }
//
//
//        window.display();
//    }
//    return 0;
//
//}