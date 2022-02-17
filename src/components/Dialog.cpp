#include "Dialog.hpp"

#include <algorithm>

#include "../utils/Util.hpp"

using std::max;

float Dialog::dialogPadding{15.f},
    Dialog::fontSize{20.f};
raylib::Color Dialog::bgColor{198, 205, 161},
    Dialog::borderColor{27, 27, 27};

Dialog::Dialog(string _text, raylib::Vector2 _pos, float _width) {
    setPosition(_pos);
    setWidth(_width);
    setText(_text);
}

raylib::Vector2 Dialog::getPosition() { return pos; }
void Dialog::setPosition(raylib::Vector2 _pos) {
    pos = _pos;
    txtPos = pos.Add({ dialogPadding, dialogPadding });
    pane.SetPosition(pos);
}

void Dialog::setSize(float _width, float _height) { setWidth(_width); setHeight(_height); }

float Dialog::getHeight() { return height; }
void Dialog::setHeight(float _height) {
    if (_height <= 0) return;
    height = _height;
    pane.SetHeight(height);
}

float Dialog::getWidth() { return width; }
void Dialog::setWidth(float _width) {
    if (_width <= 0) return;
    width = _width;
    pane.SetWidth(width);
}

void Dialog::interact() {}

void Dialog::draw(stackType &s) {
    if (!visible) return;
    pane.Draw(bgColor); pane.DrawLines(borderColor, 4);
    raylib::DrawText(
        formatedText,
        txtPos.GetX(), txtPos.GetY(),
        fontSize, borderColor
    );
    raylib::DrawText(
        "> CONTINUE...",
        txtPos.GetX(), txtPos.GetY() + txtHeight + dialogPadding,
        fontSize, raylib::Color::Black()
    );
}

void Dialog::draw(stackType &s, raylib::Vector2 _pos) {
    setPosition(_pos);
    draw(s);
}

string Dialog::getText() { return text; }
void Dialog::setText(string _text) {
    text = _text;
    auto cText{Util::clampText(text, width - 2*dialogPadding, fontSize)};
    formatedText = cText.first;
    txtHeight = cText.second*fontSize + max(1.f*cText.second - 1, 0.f)*(fontSize/2);
    setHeight(txtHeight + 3*dialogPadding + fontSize);
}

bool Dialog::getVisibility() { return visible; }
void Dialog::setVisibility(bool _visible) { visible = _visible; }
void Dialog::switchVisibility() { visible = !visible; }
