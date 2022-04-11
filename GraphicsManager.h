#ifndef INCLUDEED_GRAPHICS_MANAGER_H
#include <SFML/Graphics.hpp>
#include <iostream>

#define INCLUDED_GRAPHICS_MANAGER_H
#define ROW 16
#define COLUMNS 32
#define BACKGROUND_COLOR sf::Color::Black
#define ON sf::Color::Red
#define OFF sf::Color(210,210,210,255) // RGB e alfa, intervalo de [0,255]
#define LED_RADIUS 15.0f
#define DISTANCE_BETWEEN_THE_LEDS 10.0f
#define BORDER_X 40.0f
#define BORDER_Y 40.0f

#define SIZE_WINDOW_X (2*COLUMNS*LED_RADIUS + (COLUMNS-1)*DISTANCE_BETWEEN_THE_LEDS + 2 * BORDER_X)
#define SIZE_WINDOW_Y (2*ROW*LED_RADIUS + (ROW-1)*DISTANCE_BETWEEN_THE_LEDS + 2 * BORDER_Y)
#define GAME_NAME "Pong"

class GraphicsManager {
private:
    class Led {
    private:
        char flag;
        sf::CircleShape shape;

    public:
        Led(const float radius = LED_RADIUS);
        ~Led();

        void setRadius(const float radius);
        void setPosition(const float x, const float y);
        const float getPositionX() const;
        const float getPositionY() const;
        void On();
        void Off();
        sf::CircleShape* getShape();
        const bool isOn() const;
    };
    sf::RenderWindow window;
    sf::View view;
    sf::Event event;
    sf::Clock clock;
    static float delta_time;

    Led matrix[ROW][COLUMNS];

public:

    GraphicsManager();
    ~GraphicsManager();

    /*
     * window management functions
     */
    const bool isOpen();
    const bool pollEvent();
    void Clear();
    void display();
    void close();
    const bool closed();
    void ResizeView();
    bool resized();
    void Draw();
    void data();
    void checkEvent();
    const unsigned char controlUser01();
    const unsigned char controlUser02();

    /*
     * game-related functions
     */
    void turnOn(const unsigned int posx, const unsigned int posy); // turn on the led
    void turnOff(const unsigned int posx, const unsigned int posy);// turn off the led
    const bool isOn(const unsigned int row, const unsigned int columns) const; // check if the led is on
    void setDeltaTime(); // calculate loop time
    static float getDelta(); // returns the time of each loop

};

#endif // INCLUDE_GRAPHICS_MANAGER_H
