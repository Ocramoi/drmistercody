#include "./include/raylib-cpp/raylib-cpp.hpp"
#include "./include/emscripten/emscripten.h"

#include <vector>
#include <array>
#include <memory>
#include <algorithm>

#include "./components/UIElement.cpp"
#include "./components/Sprite.hpp"
#include "./components/Dialog.hpp"

using namespace std;
using std::pair;

// GLOBAL VARIABLES
constexpr int winWidth{550},
    winHeight{502};
raylib::Window win{winWidth, winHeight};
vector<shared_ptr<UIElement>> drawFrame,
    drawStatic;
Sprite bg{"../resources/bg.png"},
    pointer{"../resources/pointer.png"};
Dialog dialogPane{"", raylib::Vector2{ 75.f, 205.f}, winWidth - 150.f};

array<raylib::Vector2, 5> pointerPositions{
raylib::Vector2{ 7.f, 412.f }, raylib::Vector2{ 7.f, 435.f }, raylib::Vector2{7.f, 458.f},
raylib::Vector2{ 304.f, 412.f }, raylib::Vector2{ 304.f, 441.f }
};
size_t pointerIdx{0};

vector<pair<short, vector<string>>> dialogs{
{ 0, { "THE BOARS ARE COMING FOR YOUR CHILDREN!!!", "Especifically 40 or 50 of them.", "They are spreading their piggy seed all over the US!!! WE TOLD Y'ALL!" } },
{ 0, { "* sighs * Well, time for some... Warmbo... I guess.", "Warmbo? WARMBO??? WHERE ARE YOU BUDDY?", "FUCK! He got lost in the inter dimensional space again..." } },
{ 0, { "Do you know who else loves to... Commit... Hmm... Financial fraud?", "THAT'S RIGHT, THE PRODUCTS AND SERVICES THAT SUPPORT THIS CHANNEL!", "They'll provide you with premium quality audio or vitamins or audiobooks or... Something, I supose." } },
{ 0, { "Katy, do we really need to do this?", "Ok, ok... Hmmmm I'm feeling... Energized?" } },
{ 0, { "So great to see everyone wearing masks at the party!", "Pearl white masks...", "With encrusted jewels and exagerated features...", "Ok so this is the kind of party we're dealing with * sigh *" } },
};
short curDialog{0};

void gameLoop() {
    win.BeginDrawing();
    win.ClearBackground(raylib::Color::Gray());

    for (const auto& el : drawStatic) if (el) el->draw(drawFrame);
    for (const auto& el : drawFrame) if (el) el->draw(drawFrame);
    drawFrame.clear();

    switch (GetKeyPressed()) {
        case KEY_DOWN:
        case KEY_J:
        case KEY_S:
            pointerIdx = min(pointerIdx + 1, pointerPositions.size() - 1);
            pointer.setPosition(pointerPositions.at(pointerIdx));
            break;
        case KEY_UP:
        case KEY_K:
        case KEY_W:
            pointerIdx = max(static_cast<int>(pointerIdx) - 1, 0);
            pointer.setPosition(pointerPositions.at(pointerIdx));
            break;
        case KEY_ENTER:
            if (!dialogPane.getVisibility()) {
                curDialog = pointerIdx;
                dialogPane.setText(dialogs.at(curDialog).second.at(dialogs.at(curDialog).first));
                dialogPane.switchVisibility();
            } else {
                dialogs.at(curDialog).first++;
                dialogs.at(curDialog).first %= dialogs.at(curDialog).second.size();
                dialogPane.setText(dialogs.at(curDialog).second.at(dialogs.at(curDialog).first));
                if (!dialogs.at(curDialog).first) dialogPane.switchVisibility();
            }
            break;
        default:
            break;
    }

    win.EndDrawing();
}

int main() {
    win.SetTargetFPS(24);

    bg.setPosition({ 0, 0 });
    drawStatic.push_back(shared_ptr<UIElement>(&bg));

    pointer.setHeight(14);
    pointer.setPosition(pointerPositions.at(0));
    drawStatic.push_back(shared_ptr<UIElement>(&pointer));

    drawStatic.push_back(shared_ptr<UIElement>(&dialogPane));

    emscripten_set_main_loop(gameLoop, 0, 1);

    return 0;
}
