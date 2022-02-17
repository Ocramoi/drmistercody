#ifndef SPRITE_H_
#define SPRITE_H_

#include <memory>
#include "../include/raylib-cpp/raylib-cpp.hpp"

#include "./UIElement.cpp"

using std::shared_ptr;

class Sprite : public UIElement {
    private:
        raylib::Vector2 pos{0, 0};
        float scale{1.f};
        string resource{""};
        shared_ptr<raylib::Texture> texture{nullptr};
    public:
        Sprite(string _resource);
        Sprite(string _resource, raylib::Vector2 _pos);
        Sprite(string _resource, raylib::Vector2 _pos, float _scale);
        raylib::Vector2 getPosition();
        void setPosition(raylib::Vector2 _pos);
        float getHeight();
        void setHeight(float _height);
        float getWidth();
        void setWidth(float _width);
        float getScale();
        void setScale(float _scale);
        string getResource();
        void setResource(string _resource);
        void interact();
        void draw(stackType& s);
        void draw(stackType& s, raylib::Vector2 _pos);
};

#endif // SPRITE_H_
