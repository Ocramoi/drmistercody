#include "Sprite.hpp"

#include <cmath>

using std::make_shared;

Sprite::Sprite(string _resource) {
    setResource(_resource);
}

Sprite::Sprite(
    string _resource,
    raylib::Vector2 _pos
) {
    setResource(_resource);
    pos = _pos;
}

Sprite::Sprite(
    string _resource,
    raylib::Vector2 _pos,
    float _scale
) {
    setResource(_resource);
    pos = _pos;
    setScale(_scale);
}

raylib::Vector2 Sprite::getPosition() { return pos; }
void Sprite::setPosition(raylib::Vector2 _pos) { pos = _pos; }

float Sprite::getHeight() { return scale*texture->GetHeight(); }
void Sprite::setHeight(float _height) { scale = _height/texture->GetHeight(); }

float Sprite::getWidth() { return scale*texture->GetWidth(); }
void Sprite::setWidth(float _width) { scale = _width/texture->GetWidth(); }

float Sprite::getScale() { return scale; }
void Sprite::setScale(float _scale) { scale = _scale; }

string Sprite::getResource() { return resource; }
void Sprite::setResource(string _resource) {
    resource = _resource;
    texture = make_shared<raylib::Texture>(resource);
}

void Sprite::interact() { return; }

void Sprite::draw(stackType &s) { texture->Draw(pos, 0, scale); }
void Sprite::draw(stackType &s, raylib::Vector2 _pos) { texture->Draw(_pos, 0, scale); }
