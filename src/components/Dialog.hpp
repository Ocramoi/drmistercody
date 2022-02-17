#ifndef DIALOG_H_
#define DIALOG_H_

#include "./UIElement.cpp"

class Dialog : public UIElement {
    private:
        string text{""},
            formatedText{""};
        float width{0.f},
            height{-1.f},
            txtHeight{0.f};
        raylib::Vector2 pos{0.f, 0.f},
            txtPos{0.f, 0.f};
        bool visible{false},
            fixedHeight{false};
        raylib::Rectangle pane{0.f, 0.f, 0.f, 0.f};
    public:
        static float dialogPadding,
            fontSize;
        static raylib::Color bgColor,
            borderColor;

        Dialog();
        Dialog(string _text, raylib::Vector2 _pos, float _width);
        raylib::Vector2 getPosition();
        void setPosition(raylib::Vector2 _pos);
        float getHeight();
        void setHeight(float _height);
        float getWidth();
        void setWidth(float _width);
        void interact();
        void draw(stackType& s);
        void draw(stackType& s, raylib::Vector2 _pos);

        string getText();
        void setText(string _text);
        void setSize(float _width, float _height);
        bool getVisibility();
        void setVisibility(bool _visible);
        void switchVisibility();
};

#endif // DIALOG_H_
