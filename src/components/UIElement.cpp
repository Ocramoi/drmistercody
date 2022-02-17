#ifndef UIELEMENT_H_
#define UIELEMENT_H_

#include <iostream>
#include <optional>
#include <vector>
#include <memory>

#include "../include/raylib-cpp/raylib-cpp.hpp"

using std::string;
using std::optional;
using std::vector;
using std::shared_ptr;

class UIElement;

using stackType=vector<shared_ptr<UIElement>>;

class UIElement {
    public:
        virtual ~UIElement() = default;
        virtual raylib::Vector2 getPosition() = 0;
        virtual void setPosition(raylib::Vector2) = 0;
        virtual float getHeight() = 0;
        virtual float getWidth() = 0;
        virtual void interact() = 0;
        virtual void draw(stackType&) = 0;
        virtual void draw(stackType&, raylib::Vector2) = 0;
};

#endif // UIELEMENT_H_
