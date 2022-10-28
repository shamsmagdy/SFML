//#include<sfml/graphics.hpp>
//#include<iostream>
//#include<sfml/audio.hpp>
//#include<fstream>
//#include<string>
//
//using namespace std;
//using namespace sf;
//
//void inputfromfile(player gameplayer)
//{
//    ifstream input;
//    input.open("file3.txt");
//    while (input >> gameplayer.player_name >> gameplayer.high_score) {
//        if (gameplayer.player_score > gameplayer.high_score)
//        {
//            gameplayer.high_score = gameplayer.player_score;
//        }
//
//    }
//
//    input.close();
//}
//void savetofile(player gameplayer)
//{
//    ofstream output;
//    output.open("file3.txt", ios::app);
//
//    output << gameplayer.player_name << "\t";
//    output << gameplayer.high_score << endl;
//
//    output.close();
//
//}
//struct shoot
//{
//    sprite shooting_ball[48];
//    int column_number0 = 16;
//    int column_number1 = 15;
//    int column_number2 = 14;
//    int column_number3 = 13;
//    int column_number4 = 12;
//    int column_number5 = 11;
//    int column_number6 = 10;
//    int column_number7 = 9;
//}ball;
//struct player
//{
//    string player_name;
//    int high_score = 0;
//    int player_score = 0;
//};
//
//int count = 0;
//
//void set_pos_ball(int counter, sprite clrs[], renderwindow& window)
//{
//    clrs[counter].setscale(0.5, 0.5);
//    vector2f ball_move(mouse::getposition(window).x - clrs[counter].getposition().x, mouse::getposition(window).y - clrs[counter].getposition().y);
//    clrs[counter].move(ball_move * (1.f / 10.f));
//}
//
//void filling_cannon_balls(texture& redd, texture& cyann, texture& yelow, texture& orangee)
//{
//    for (int i = 0; i < 20; i += 4)
//    {
//        ball.shooting_ball[i].settexture(redd);
//        ball.shooting_ball[i].setscale(0.5, 0.5);
//        ball.shooting_ball[i].setposition(497, 740);
//        ball.shooting_ball[i].setorigin(65, 55);
//    }
//    for (int i = 1; i < 21; i += 4)
//    {
//        ball.shooting_ball[i].settexture(yelow);
//        ball.shooting_ball[i].setscale(0.5, 0.5);
//        ball.shooting_ball[i].setposition(497, 740);
//        ball.shooting_ball[i].setorigin(65, 55);
//    }
//    for (int i = 2; i < 22; i += 4)
//    {
//        ball.shooting_ball[i].settexture(cyann);
//        ball.shooting_ball[i].setscale(0.5, 0.5);
//        ball.shooting_ball[i].setposition(497, 740);
//        ball.shooting_ball[i].setorigin(58, 58);
//    }
//    for (int i = 3; i < 23; i += 4)
//    {
//        ball.shooting_ball[i].settexture(orangee);
//        ball.shooting_ball[i].setscale(0.5, 0.5);
//        ball.shooting_ball[i].setposition(497, 740);
//        ball.shooting_ball[i].setorigin(58, 53);
//    }
//}
//
//
//
//int main()
//{
//    renderwindow window(videomode(1000, 800), "bubble shooter");
//    window.setframeratelimit(30);
//
//    //variable declaration
//    int animator = 0, counter = 0,/* score = 0,*/ col = 0;
//    bool check = false;
//    bool collided = false;
//    static bool click;
//    player gameplayer;
//    int playindex = 0;
//    int scoreint = 0, maxscore = 0;
//
//
//
//    int scorecounter = 0;
//
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
//    cannon_sheet.loadfromfile("cannon spritesheet.png");
//    //sprites
//
//    sprite backs, base, cannon_sprite, upper_ball_colors[10][25];
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
//    filling_cannon_balls(redd, cyann, yelow, orangee);
//
//
//
//    texture background, bubble, start, animal, menu, monkey, monkey2, senjap, poma, bubb, buuu, highh, hscore, howplay;
//    texture blueball, redball, yellowball, orangeball, backimage, kass, level, animation, ground, pointer, bname, bhow, congrats, winscore;
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
//    pointer.loadfromfile("ppointer.png");
//    bname.loadfromfile("board.png");
//    howplay.loadfromfile("howplay.png");
//    bhow.loadfromfile("howboard.png");
//    congrats.loadfromfile("congratulations.png");
//    winscore.loadfromfile("board.png");
//
//    sprite back, bub, st, ani, men, mon, mon2, sen, pom, bu[3], buu, b, hig, kas, animat, grou, point, bnam, howp, bhoow, congrt, winscor;
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
//    howp.settexture(howplay);
//    howp.setposition(300, 530);
//    howp.setscale(1, 1);
//    bhoow.settexture(bhow);
//    bhoow.setposition(250, 200);
//    bhoow.setscale(1.5, 1.5);
//    congrt.settexture(congrats);
//    congrt.setposition(230, 20);
//    congrt.setscale(1, 1);
//    winscor.settexture(winscore);
//    winscor.setposition(345, 280);
//    winscor.setscale(0.6, 0.4);
//
//
//    font font, ffont, fffont;
//    font.loadfromfile("font.ttf");
//    ffont.loadfromfile("hhhh.ttf");
//    fffont.loadfromfile("foont.ttf");
//
//
//    text sstart, play, exit, high, hs, backh, leve, score, text, next, hello, name, how, howback, cong, scoree, winhigh;
//    text scorepage;
//    text winssssscore;
//    //nameeee.setfont(ffont);
//
//
//    for (int x = 0; x < 15; x++)
//    {
//
//        if (gameplayer.high_score > maxscore)
//        {
//            maxscore = gameplayer.high_score;
//            //nameeee.setstring(gameplayer[x].player_name);
//
//        }
//    }
//
//    //nameeee.setposition(350, 400);
//    //nameeee.setcharactersize(40);
//    //nameeee.setfillcolor(color::green);
//
//
//
//    sstart.setfont(font);
//    sstart.setstring("start");
//    sstart.setposition(420, 405);
//    sstart.setfillcolor(color(90, 60, 80, 255));
//    sstart.setcharactersize(65);
//    play.setfont(font);
//    play.setstring("play");
//    play.setposition(460, 165);
//    play.setcharactersize(80);
//    exit.setstring("back");
//    exit.setfont(font);
//    exit.setposition(330, 540);
//    exit.setcharactersize(85);
//    how.setfont(font);
//    how.setposition(450, 433);
//    how.setstring("how to play");
//    how.setcharactersize(43);
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
//    score.setstring("score :");
//    score.setposition(750, 0);
//    score.setfillcolor(color::white);
//    score.setcharactersize(50);
//    howback.setfont(font);
//    howback.setstring("back");
//    howback.setcharactersize(100);
//    howback.setposition(460, 670);
//    scoree.setfont(ffont);
//    scoree.setcharactersize(50);
//    scoree.setposition(650, 0);
//    winhigh.setfont(font);
//    winhigh.setstring("highscore");
//    winhigh.setcharactersize(80);
//    winhigh.setposition(380, 400);
//    winhigh.setfillcolor(color(90, 60, 80, 255));
//
//    string input_text;
//
//    //enter user name
//    text.setfont(fffont);
//    text.setposition(395, 380);
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
//    text timer;
//    int timee = 0;
//    timer.setstring("time : 00: " + to_string(timee));
//    timer.setfont(font);
//    timer.setcharactersize(50);
//    timer.setfillcolor(color::white);
//    timer.setposition(280, 5);
//    text max_text;
//
//
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
//    int count = 0;
//
//
//    //triangle shape
//    for (int row = 0; row < 8; row++)
//    {
//        if (row == 0)
//        {
//            for (int col = 2; col < 17; col++)
//            {
//                upper_ball_colors[row][col].settexture(redd);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 55);
//
//            }
//        }
//        if (row == 1)
//        {
//            for (int col = 3; col < 16; col++)
//            {
//                upper_ball_colors[row][col].settexture(yelow);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 105);
//
//            }
//        }
//        if (row == 2)
//        {
//            for (int col = 4; col < 15; col++)
//            {
//                upper_ball_colors[row][col].settexture(orangee);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 153);
//
//            }
//        }
//        if (row == 3)
//        {
//            for (int col = 5; col < 14; col++)
//            {
//                upper_ball_colors[row][col].settexture(cyann);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 205);
//
//            }
//        }
//        if (row == 4)
//        {
//            for (int col = 6; col < 13; col++)
//            {
//                upper_ball_colors[row][col].settexture(redd);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 260);
//
//            }
//        }
//        if (row == 5)
//        {
//            for (int col = 7; col < 12; col++)
//            {
//                upper_ball_colors[row][col].settexture(yelow);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 308);
//
//            }
//        }
//        if (row == 6)
//        {
//            for (int col = 8; col < 11; col++)
//            {
//                upper_ball_colors[row][col].settexture(orangee);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 355);
//
//            }
//        }
//        if (row == 7)
//        {
//            for (int col = 9; col < 10; col++)
//            {
//                upper_ball_colors[row][col].settexture(cyann);
//                upper_ball_colors[row][col].setscale(0.5, 0.5);
//                upper_ball_colors[row][col].setposition(50 * col, 407);
//
//
//            }
//        }
//    }    //end of loop
//
//    counter = 0;
//
//    int time;
//    clock clock;
//    time = 60;
//    bool screencollision = false;
//    timee = 0;
//
//    inputfromfile(gameplayer);
//
//    while (window.isopen())
//    {
//        event event;
//        while (window.pollevent(event))
//        {
//            if (event.type == event::closed)
//                window.close();
//
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
//
//                if (point.getglobalbounds().intersects(how.getglobalbounds()))
//                {
//                    how.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    how.setfillcolor(color(100, 100, 50, 255));
//
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
//                if (point.getglobalbounds().intersects(howback.getglobalbounds()))
//                {
//                    howback.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    howback.setfillcolor(color(90, 60, 80, 255));
//
//                if (point.getglobalbounds().intersects(winhigh.getglobalbounds()))
//                {
//                    winhigh.setfillcolor(color(0, 0, 0, 255));
//
//                }
//                else
//                    winhigh.setfillcolor(color(90, 60, 80, 255));
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
//                    if (point.getglobalbounds().intersects(how.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 5;
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
//                if (count == 5)
//                {
//                    if (point.getglobalbounds().intersects(howback.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 1;
//                    }
//                }
//                if (count == 6)
//                {
//                    if (point.getglobalbounds().intersects(winhigh.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 3;
//                    }
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
//                if (count == 4)
//                {
//                    if (isprint(event.text.unicode) && input_text.size() < 7)
//                        input_text += event.text.unicode;
//
//                }
//            }
//            text.setstring(input_text);
//            for (int i = 0;i < 15;i++)
//            {
//                if (input_text == gameplayer.player_name)
//                {
//                    playindex = i;
//                    break;
//                }
//                else
//                {
//                    gameplayer.player_name = input_text;
//                    playindex = i;
//                    break;
//                }
//
//
//            }
//
//            if (input_text.size() == 0)
//            {
//
//                if (mouse::isbuttonpressed(mouse::left))
//                {
//                    if (point.getglobalbounds().intersects(next.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 4;
//                    }
//
//                }
//            }
//            else  if ((input_text.size() < 8))
//            {
//                if (mouse::isbuttonpressed(mouse::left))
//                {
//                    if (point.getglobalbounds().intersects(next.getglobalbounds()))
//                    {
//                        sound.play();
//                        count = 2;
//                    }
//
//                }
//            }
//
//            timee = time - clock.getelapsedtime().asseconds();
//
//            timer.setstring("time : 00: " + to_string(timee));
//
//
//            //move function of the ball
//            if (event.type == event::mousebuttonpressed)
//            {
//                if (event.mousebutton.button == sf::mouse::left)
//                {
//                    click = true;
//
//                }
//            }
//
//            if (event.type == event::mousebuttonreleased)
//            {
//                if (event.mousebutton.button == mouse::left)
//                {
//                    click = false;
//
//                }
//            }
//
//            if (click)
//            {
//                set_pos_ball(counter, ball.shooting_ball, window);
//            }
//
//
//            //collision of ball with the upper balls
//
//            for (int i = 0; i < 25; i++)
//            {
//                if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[0][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &redd && upper_ball_colors[0][i].gettexture() == &redd)
//                    {
//                        for (int r = 0; r < 10; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                                collided = true;
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 0; r < 1; r++)
//                        {
//                            for (int c = 2; c < 17; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//                       /* if (gameplayer.high_score < scoreint)
//                        {
//                            gameplayer.high_score = scoreint;
//                        }*/
//
//                        // gameplayer[playindex].high_score += scoreint;
//
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &redd && upper_ball_colors[0][i].gettexture() != &redd)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number0++;
//                        upper_ball_colors[0][ball.column_number0].settexture(redd);
//                        upper_ball_colors[0][ball.column_number0].setscale(0.5, 0.5);
//                        upper_ball_colors[0][ball.column_number0].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[0][ball.column_number0].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number0++;
//                        if (ball.shooting_ball[counter].gettexture() == &yelow)
//                            upper_ball_colors[0][ball.column_number0].settexture(yelow);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[0][ball.column_number0].settexture(cyann);
//                        else
//                            upper_ball_colors[0][ball.column_number0].settexture(orangee);
//                        upper_ball_colors[0][ball.column_number0].setscale(0.5, 0.5);
//                        upper_ball_colors[0][ball.column_number0].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[0][ball.column_number0].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[1][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &yelow && upper_ball_colors[1][i].gettexture() == &yelow)
//                    {
//                        for (int r = 1; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                        for (int r = 1; r < 2; r++)
//                        {
//
//                            for (int c = 3; c < 16; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//                        // if (gameplayer.high_score < scoreint)
//                        // {
//                          //   gameplayer.high_score = scoreint;
//                        // }
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//
//                        //gameplayer[playindex].high_score += scoreint;
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &yelow && upper_ball_colors[1][i].gettexture() != &yelow)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number1++;
//                        upper_ball_colors[1][ball.column_number1].settexture(yelow);
//                        upper_ball_colors[1][ball.column_number1].setscale(0.5, 0.5);
//                        upper_ball_colors[1][ball.column_number1].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[1][ball.column_number1].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number1++;
//                        if (ball.shooting_ball[counter].gettexture() == &redd)
//                            upper_ball_colors[1][ball.column_number1].settexture(redd);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[1][ball.column_number1].settexture(cyann);
//                        else
//                            upper_ball_colors[1][ball.column_number1].settexture(orangee);
//                        upper_ball_colors[1][ball.column_number1].setscale(0.5, 0.5);
//                        upper_ball_colors[1][ball.column_number1].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[1][ball.column_number1].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                        scorecounter = 0;
//
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[2][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &orangee && upper_ball_colors[2][i].gettexture() == &orangee)
//                    {
//                        for (int r = 2; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 2; r < 3; r++)
//                        {
//                            for (int c = 4; c < 15; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//                        /*if (gameplayer.high_score < scoreint)
//                        {
//                            gameplayer.high_score = scoreint;
//                        }*/
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &orangee && upper_ball_colors[2][i].gettexture() != &orangee)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number2++;
//                        upper_ball_colors[2][ball.column_number2].settexture(orangee);
//                        upper_ball_colors[2][ball.column_number2].setscale(0.5, 0.5);
//                        upper_ball_colors[2][ball.column_number2].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[2][ball.column_number2].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number2++;
//                        if (ball.shooting_ball[counter].gettexture() == &yelow)
//                            upper_ball_colors[2][ball.column_number2].settexture(yelow);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[2][ball.column_number2].settexture(cyann);
//                        else
//                            upper_ball_colors[2][ball.column_number2].settexture(redd);
//                        upper_ball_colors[2][ball.column_number2].setscale(0.5, 0.5);
//                        upper_ball_colors[2][ball.column_number2].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[2][ball.column_number2].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[3][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &cyann && upper_ball_colors[3][i].gettexture() == &cyann)
//                    {
//                        for (int r = 3; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 3; r < 4; r++)
//                        {
//                            for (int c = 5; c < 14; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//                        scoreint = scoreint + scorecounter * 10;
//                        scoree.setstring("score :" + to_string(scoreint));
//                        /*if (gameplayer.high_score < scoreint)
//                        {
//                            gameplayer.high_score = scoreint;
//                        }*/
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//                        //gameplayer[playindex].high_score += scoreint;
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &cyann && upper_ball_colors[3][i].gettexture() != &cyann)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number3++;
//                        upper_ball_colors[3][ball.column_number3].settexture(cyann);
//                        upper_ball_colors[3][ball.column_number3].setscale(0.5, 0.5);
//                        upper_ball_colors[3][ball.column_number3].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[3][ball.column_number3].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number3++;
//                        if (ball.shooting_ball[counter].gettexture() == &yelow)
//                            upper_ball_colors[3][ball.column_number3].settexture(yelow);
//                        else if (ball.shooting_ball[counter].gettexture() == &redd)
//                            upper_ball_colors[3][ball.column_number3].settexture(redd);
//                        else
//                            upper_ball_colors[3][ball.column_number3].settexture(orangee);
//                        upper_ball_colors[3][ball.column_number3].setscale(0.5, 0.5);
//                        upper_ball_colors[3][ball.column_number3].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[3][ball.column_number3].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[4][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &redd && upper_ball_colors[4][i].gettexture() == &redd)
//                    {
//                        for (int r = 4; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 4; r < 5; r++)
//                        {
//                            for (int c = 6; c < 13; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//
//                        /* if (gameplayer.high_score < scoreint)
//                         {
//                             gameplayer.high_score = scoreint;
//                         }*/
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//                        // gameplayer[playindex].high_score += scoreint;
//
//
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &redd && upper_ball_colors[4][i].gettexture() != &redd)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number4++;
//                        upper_ball_colors[4][ball.column_number4].settexture(redd);
//                        upper_ball_colors[4][ball.column_number4].setscale(0.5, 0.5);
//                        upper_ball_colors[4][ball.column_number4].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[4][ball.column_number4].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number4++;
//                        if (ball.shooting_ball[counter].gettexture() == &yelow)
//                            upper_ball_colors[4][ball.column_number4].settexture(yelow);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[4][ball.column_number4].settexture(cyann);
//                        else
//                            upper_ball_colors[4][ball.column_number4].settexture(orangee);
//                        upper_ball_colors[4][ball.column_number4].setscale(0.5, 0.5);
//                        upper_ball_colors[4][ball.column_number4].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[4][ball.column_number4].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[5][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &yelow && upper_ball_colors[5][i].gettexture() == &yelow)
//                    {
//                        for (int r = 5; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 5; r < 6; r++)
//                        {
//                            for (int c = 7; c < 12; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//
//                        /*if (gameplayer.high_score < scoreint)
//                        {
//                            gameplayer.high_score = scoreint;
//                        }*/
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//                        // gameplayer[playindex].high_score += scoreint;
//
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &yelow && upper_ball_colors[5][i].gettexture() != &yelow)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number0++;
//                        upper_ball_colors[5][ball.column_number5].settexture(yelow);
//                        upper_ball_colors[5][ball.column_number5].setscale(0.5, 0.5);
//                        upper_ball_colors[5][ball.column_number5].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[5][ball.column_number5].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number5++;
//                        if (ball.shooting_ball[counter].gettexture() == &redd)
//                            upper_ball_colors[5][ball.column_number5].settexture(redd);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[5][ball.column_number5].settexture(cyann);
//                        else
//                            upper_ball_colors[5][ball.column_number5].settexture(orangee);
//                        upper_ball_colors[5][ball.column_number5].setscale(0.5, 0.5);
//                        upper_ball_colors[5][ball.column_number5].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[5][ball.column_number5].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[6][i].getglobalbounds()))
//                {
//                    if (ball.shooting_ball[counter].gettexture() == &orangee && upper_ball_colors[6][i].gettexture() == &orangee)
//                    {
//                        for (int r = 6; r < 8; r++)
//                        {
//                            for (int c = 0; c < 25; c++)
//                            {
//                                upper_ball_colors[r][c].setscale(0, 0);
//                            }
//                        }
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//
//                        scorecounter = 0;
//                        for (int r = 6; r < 7; r++)
//                        {
//                            for (int c = 8; c < 11; c++)
//                            {
//                                scorecounter++;
//                            }
//                        }
//
//                        scoreint = scoreint + (scorecounter * 10);
//                        scoree.setstring("score :" + to_string(scoreint));
//
//                        /* if (gameplayer.high_score < scoreint)
//                         {
//                             gameplayer.high_score = scoreint;
//                         }*/
//                        if (scoreint > maxscore)
//                        {
//                            maxscore = scoreint;
//                        }
//
//
//                        //gameplayer[playindex].high_score += scoreint;
//                    }
//                    else if (ball.shooting_ball[counter].gettexture() == &orangee && upper_ball_colors[6][i].gettexture() != &orangee)
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number6++;
//                        upper_ball_colors[6][ball.column_number6].settexture(orangee);
//                        upper_ball_colors[6][ball.column_number6].setscale(0.5, 0.5);
//                        upper_ball_colors[6][ball.column_number6].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[6][ball.column_number6].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                    else
//                    {
//                        ball.shooting_ball[counter].move(0, 0);
//                        ball.column_number6++;
//                        if (ball.shooting_ball[counter].gettexture() == &yelow)
//                            upper_ball_colors[6][ball.column_number6].settexture(yelow);
//                        else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                            upper_ball_colors[6][ball.column_number6].settexture(cyann);
//                        else
//                            upper_ball_colors[6][ball.column_number6].settexture(redd);
//                        upper_ball_colors[6][ball.column_number6].setscale(0.5, 0.5);
//                        upper_ball_colors[6][ball.column_number6].setposition(ball.shooting_ball[counter].getposition());
//                        upper_ball_colors[6][ball.column_number6].setorigin(ball.shooting_ball[counter].getorigin());
//                        ball.shooting_ball[counter].setscale(0, 0);
//                        counter++;
//                    }
//                }
//                else if (ball.shooting_ball[counter].getglobalbounds().intersects(upper_ball_colors[7][i].getglobalbounds()))
//                {
//                    ball.shooting_ball[counter].move(0, 0);
//                    ball.column_number7++;
//                    if (ball.shooting_ball[counter].gettexture() == &yelow)
//                        upper_ball_colors[7][ball.column_number7].settexture(yelow);
//                    else if (ball.shooting_ball[counter].gettexture() == &cyann)
//                        upper_ball_colors[7][ball.column_number7].settexture(cyann);
//                    else if (ball.shooting_ball[counter].gettexture() == &redd)
//                        upper_ball_colors[7][ball.column_number7].settexture(redd);
//                    else
//                        upper_ball_colors[7][ball.column_number7].settexture(orangee);
//                    upper_ball_colors[7][ball.column_number7].setscale(0.5, 0.5);
//                    upper_ball_colors[7][ball.column_number7].setposition(ball.shooting_ball[counter].getposition());
//                    upper_ball_colors[7][ball.column_number7].setorigin(ball.shooting_ball[counter].getorigin());
//                    ball.shooting_ball[counter].setscale(0, 0);
//                    counter++;
//                }
//            }
//
//        }
//
//
//
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
//            ////wiiin
//            //window.draw(congrt);
//            //window.draw(winscor);
//            //window.draw(ani);
//        }
//
//        if (count == 1)
//        {
//            window.draw(back);
//            window.draw(men);
//            window.draw(howp);
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
//            window.draw(how);
//            window.draw(point);
//
//        }
//        if (count == 2)                         //play page
//        {
//            window.draw(backs);
//            window.draw(grou);
//            window.draw(ball.shooting_ball[counter]);
//            window.draw(cannon_sprite);
//            window.draw(leve);
//            //  window.draw(score);
//            window.draw(animat);
//            window.draw(timer);
//            window.draw(scoree);
//
//
//            for (int row = 0; row < 8; row++)
//            {
//                for (int col = 2; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 16)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//
//                            continue;
//                    }
//                }
//            }
//
//            for (int row = 1; row < 8; row++)
//            {
//                for (int col = 3; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 15)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int row = 2; row < 8; row++)
//            {
//                for (int col = 4; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 14)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int row = 3; row < 8; row++)
//            {
//                for (int col = 5; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 13)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int row = 4; row < 8; row++)
//            {
//                for (int col = 6; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 12)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int row = 5; row < 8; row++)
//            {
//                for (int col = 7; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 11)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int row = 6; row < 8; row++)
//            {
//                for (int col = 8; col < 25; col++)
//                {
//                    window.draw(upper_ball_colors[row][col]);
//                    if (col > 10)
//                    {
//                        if (upper_ball_colors[row][col].getscale().x > 0 && upper_ball_colors[row][col].getscale().y > 0)
//                        {
//                            window.draw(upper_ball_colors[row][col]);
//                        }
//                        else
//                            continue;
//                    }
//                }
//            }
//            for (int i = 23; i >= 0; i--)
//                window.draw(ball.shooting_ball[i]);
//            for (int row = 0; row < 20; row++)
//            {
//                for (int col = 0; col < 25; col++)
//                {
//                    if (timee > 0 && collided)
//                    {
//                        //win window
//                        count = 6;
//
//
//                    }
//
//                    if (timee <= 0 && !(collided))
//                    {
//                        cout << "lose" << endl;
//                        timer.setstring("time : 00:00 ");
//                    }
//
//                }
//            }
//
//
//            winssssscore.setfont(ffont);
//            winssssscore.setstring("your score :" + to_string(scoreint));
//            winssssscore.setposition(400, 350);
//            winssssscore.setfillcolor(color::black);
//
//            max_text.setfont(ffont);
//            max_text.setstring("highscore :" + to_string(maxscore));
//            max_text.setposition(400, 400);
//            max_text.setfillcolor(color::black);
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
//            window.draw(max_text);
//
//            //window.draw(nameeee);
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
//        if (count == 5)     //how to play
//        {
//            window.draw(back);
//            window.draw(mon);
//            window.draw(mon2);
//            window.draw(sen);
//            window.draw(pom);
//
//            window.draw(bhoow);
//            window.draw(howback);
//            window.draw(point);
//        }
//        if (count == 6)
//        {
//            window.draw(back);
//            window.draw(mon);
//            window.draw(mon2);
//            window.draw(sen);
//            window.draw(pom);
//            window.draw(congrt);
//            window.draw(winscor);
//            window.draw(ani);
//            window.draw(winhigh);
//            window.draw(point);
//            scoree.setstring("score :" + to_string(scoreint));
//            window.draw(winssssscore);
//        }
//        window.display();
//    }
//    savetofile(gameplayer);
//    return 0;
//
//}
