#include "GraphicsManager.h"

GraphicsManager::Led::Led(const float radius):
    flag(0)
{
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setFillColor(OFF);
    shape.setTexture(nullptr);
}

GraphicsManager::Led::~Led() {}

void GraphicsManager::Led::setRadius(const float radius) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
}

void GraphicsManager::Led::setPosition(const float x, const float y) {
    shape.setPosition(x,y);
}

const float GraphicsManager::Led::getPositionX() const {
    return shape.getPosition().x;
}

const float GraphicsManager::Led::getPositionY() const {
    return shape.getPosition().y;
}

void GraphicsManager::Led::On() {
    shape.setFillColor(ON);
    flag = 1;
}

void GraphicsManager::Led::Off() {
    shape.setFillColor(OFF);
    flag = 0;
}

sf::CircleShape* GraphicsManager::Led::getShape(){
    return &shape;
}

const bool GraphicsManager::Led::isOn() const {
    return flag ? true : false;
}

/*
 * function Graphics Manager
 */

float GraphicsManager::delta_time = 0.0f;
GraphicsManager::GraphicsManager():
    window(sf::VideoMode(SIZE_WINDOW_X, SIZE_WINDOW_Y), GAME_NAME, sf::Style::Close | sf::Style::Resize),
    view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SIZE_WINDOW_X, SIZE_WINDOW_Y))
{
    unsigned int i,j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COLUMNS; j++) {
            matrix[i][j].setPosition(BORDER_X + ((2*j + 1) * LED_RADIUS) + (j*DISTANCE_BETWEEN_THE_LEDS), BORDER_Y + ((2*i + 1) * LED_RADIUS) + (i*DISTANCE_BETWEEN_THE_LEDS));
        }
    }
}

GraphicsManager::~GraphicsManager() {
}

const bool GraphicsManager::isOpen() {
    return window.isOpen();
}
const bool GraphicsManager::pollEvent(){
    return(window.pollEvent(event));
}
void GraphicsManager::Clear(){
    window.clear(BACKGROUND_COLOR);
}
void GraphicsManager::display(){
    window.display();
}
void GraphicsManager::close() {
    window.close();
}
const bool GraphicsManager::closed() {
    return(event.type == sf::Event::Closed);
}
void GraphicsManager::ResizeView() {
    float ratio = (float)window.getSize().x / window.getSize().y;
    view.setSize(view.getSize().y * ratio, view.getSize().y);
}
bool GraphicsManager::resized() {
    return(event.type == sf::Event::Resized);
}
void GraphicsManager::Draw() {
    unsigned int i,j;
    sf::CircleShape* ptr = NULL;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COLUMNS; j++) {
            ptr = matrix[i][j].getShape();
            window.draw(*ptr);
        }
    }
}

void GraphicsManager::data() {
    printf("Time loop: %.3fs\n", delta_time);
    printf("Window Position: ( %.2f, %.2f )\n", (float)window.getPosition().x, (float)window.getPosition().y);
    printf("Window Size: ( %.2f, %.2f )\n", (float)window.getSize().x, (float)window.getSize().y);
    printf("View Position: ( %.2f, %.2f )\n", view.getCenter().x, view.getCenter().y);
    printf("View Size: ( %.2f, %.2f )\n", view.getSize().x, view.getSize().y);
    printf("Mouse Position: ( %.2f, %.2f )\n", (float)sf::Mouse::getPosition().x, (float)sf::Mouse::getPosition().y);
}

void GraphicsManager::checkEvent() {
    while(this->pollEvent())
    {
        if(this->closed())
        {
            this->close();
        }
        if(this->resized())
        {
            this->ResizeView();
        }
    }
}

const unsigned char GraphicsManager::controlUser01() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        return 1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        return 2;
    }
    return 0;
}
const unsigned char GraphicsManager::controlUser02() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        return 1;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        return 2;
    }
    return 0;
}

void GraphicsManager::turnOn(const unsigned int posx, const unsigned int posy) {
    if( (posy >= 0) && (posy < ROW) ) {
        matrix[posy][posx].On();
    }
}

void GraphicsManager::turnOff(const unsigned int posx, const unsigned int posy) {
    if( (posy >= 0) && (posy < ROW) ) {
        matrix[posy][posx].Off();
    }
}

const bool GraphicsManager::isOn(const unsigned int row, const unsigned int columns) const {
    return matrix[row][columns].isOn();
}

void GraphicsManager::setDeltaTime() {
    delta_time = clock.restart().asSeconds();
}

float GraphicsManager::getDelta() {
    return delta_time;
}


