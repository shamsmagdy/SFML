#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

using namespace sf;
int main()
{
    /*WINDOW AND EVENT*/

    RenderWindow window(VideoMode(1000, 700), " game 1");
    Event eve;

    /*TEXTURES*/

    Texture skyImage;
    Texture spritesheet_texture;
    Texture coinImage;
    Texture groundImage;

    /*LOADING IMAGES*/

    (skyImage.loadFromFile("sky2.jpg"));
    (spritesheet_texture.loadFromFile("mario_spritesheet.png"));
    coinImage.loadFromFile("coins.png");
    groundImage.loadFromFile("mario.ground.png");

    /*SPRITES*/

    Sprite Sky;
    Sprite spriTesheet;
    Sprite coin;
    Sprite arr[10];
    Sprite spGround;

    /*SETTING SPRITES*/

    Sky.setTexture(skyImage);
    spriTesheet.setTexture(spritesheet_texture);
    coin.setTexture(coinImage);
    
    spGround.setTexture(groundImage);


        /*SHAPE AND POSITION*/

    spritesheet_texture.setSmooth(true);
    coinImage.setSmooth(true);
    Sky.setScale(10, 5);
    int mario_scale = 3;
    spriTesheet.setScale(mario_scale, mario_scale);
    spriTesheet.setPosition(0, 455);
    coin.setPosition(100, 490);
    RectangleShape ground(Vector2f(2000,100));
    ground.setPosition(0, 1000);
    spGround.setTexture(groundImage);
    spGround.setScale(2, 1.5);
    spGround.setTextureRect(IntRect(0, 0, 2000, 100));
    spGround.setPosition(1,550);
    groundImage.setSmooth(true);


    /*ANIMATION*/

    spriTesheet.setTextureRect(IntRect(0, 0, 16, 32));
    coin.setTextureRect(IntRect(0, 0, 36, 32));
    int animation_indicator = 0;
    int coin_animation_idicator=0;
    Clock clock, animation_clock;
    float DletaTime = 0;

    /*COLLISIONS*/

    bool isCoinVisible = true;

    /*TEXT*/
    Font font;
    font.loadFromFile("orange juice 2.0.ttf");
    Text text;
    text.setFont(font);
    int score=0;
    text.setString("Score: " +to_string(score));
    text.setFillColor(Color::Black);
    text.setPosition(10, 260);
    text.setCharacterSize(48);

    
    /*VIEW*/

    View camera(FloatRect(0, 0, 1000, 700));
    camera.setCenter(spriTesheet.getPosition());
    window.setView(camera);

    
   
   

    /*LOOPS*/

    while (window.isOpen())
    {
        /*EVENT POLLING*/

        while (window.pollEvent(eve))
        {

            if (eve.type == sf::Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Left)) {
                //Left key is pressed : move our character
                camera.move(-5.f, 0.f);
                spriTesheet.move(-5.f, 0.f);
                text.move(-5.f, 0.f);
                
                if (animation_clock.getElapsedTime().asSeconds() > 0.1)
                {
                    animation_indicator++;
                    spriTesheet.setScale(-mario_scale, mario_scale);
                    animation_clock.restart();
                }
            }
            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                // left key is pressed: move our character
                camera.move(5.f, 0.f);
                spriTesheet.move(5.f, 0.f);
                text.move(5.f, 0.f);
                
                if (animation_clock.getElapsedTime().asSeconds() > 0.1)
                {
                    animation_indicator++;
                    spriTesheet.setScale(mario_scale, mario_scale);
                    animation_clock.restart();
                }
            }
            
            animation_indicator = animation_indicator % 3;
            spriTesheet.setTextureRect(IntRect(animation_indicator * 16, 0, 16, 32));
            if (spriTesheet.getGlobalBounds().intersects(coin.getGlobalBounds()))
            {
                coin.setPosition(1001, 700);
                score++;
                text.setString("score:" + to_string(score));
                isCoinVisible = false;
            }
            
        }
        
        coin.setTextureRect(IntRect(coin_animation_idicator * 36, 0, 36, 32));
        if (clock.getElapsedTime().asSeconds() > 0.1)
        {
            coin_animation_idicator++;
            coin_animation_idicator = coin_animation_idicator % 6;
            clock.restart();
        }
        
        window.clear();
        window.setView(camera);
        window.draw(Sky);
        window.draw(spriTesheet);
        window.draw(text);
        window.draw(spGround);
        if (isCoinVisible) 
            window.draw(coin);
        window.draw(coin);
        window.display();
    }
    
    return 0;
}


