#include "include/Entity.h"

//Initialize
void Entity::initVariables() {
    
    //RenderWindow
    this->render_window = nullptr;

    //Keyboard
    this->is_key_pressed.resize(1000);
}

//Constructor and Destructor
Entity::Entity() {
    
    this->initVariables();
}
Entity::~Entity() {

}

//Accessors
void Entity::setRenderWindow(sf::RenderWindow* render_window) {

    this->render_window = render_window;
}
sf::RenderWindow* Entity::getRenderWindow() {

    return this->render_window;
}
void Entity::setSprite(std::string sprite_path) {

    this->texture.loadFromFile(sprite_path);
    this->sprite_width = this->texture.getSize().x;
    this->sprite_height = this->texture.getSize().y;

    this->sprite.setTexture(this->texture);
    this->sprite.setOrigin(sf::Vector2f(this->sprite_width / 2, this->sprite_height / 2));
    this->sprite.setPosition(this->x, this->y);

    std::cout << "set Sprite" << std::endl;
}
sf::Sprite Entity::getSprite() {

    return this->sprite;
}
void Entity::setPosition(double x, double y) {

    this->x = x;
    this->y = y;
}
sf::Vector2f Entity::getPosition() {
    
    return sf::Vector2f(this->x, this->y);
}

//Functions
void Entity::create() {

}
void Entity::update() {

}
void Entity::render() {

    this->drawSelf();
}

void Entity::drawSelf() {

    this->sprite.setPosition(this->x, this->y);
    this->render_window->draw(this->sprite);
}

//Keyboard
bool Entity::keyboardCheck(sf::Keyboard::Key key) {

    return sf::Keyboard::isKeyPressed(key);
}

bool Entity::keyboardCheckPressed(sf::Keyboard::Key key) {

    if(this->keyboardCheck(key) && !this->is_key_pressed.at(sf::Keyboard::Key::A)) {
        
        this->is_key_pressed.at(sf::Keyboard::Key::A) = true;
        return true;
    }
    else if(!this->keyboardCheck(key)) {

        this->is_key_pressed.at(sf::Keyboard::Key::A) = false;
    }
    return false;
}