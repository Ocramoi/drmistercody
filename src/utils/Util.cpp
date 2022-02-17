#include "Util.hpp"

#include <unordered_map>
#include <optional>
#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

using std::to_string;
using std::vector;
using std::stringstream;
using std::max;

pair<string, unsigned short> Util::clampText(
    const string &str,
    int maxWidth,
    int fontSize) {
    unsigned int ignore{0};
    return clampText(str, maxWidth, fontSize, ignore);
}

pair<string, unsigned short> Util::clampText(
    const string &str,
    int maxWidth,
    int fontSize,
    unsigned int& maxTok
) {
    stringstream scriptStream(str);
    string temp,
        line{""},
        clamped{""};
    unsigned short nLines{1};
    maxTok = 0;
    while (std::getline(scriptStream, temp, ' ')) {
        auto curLen = raylib::MeasureText(line + temp, fontSize);
        maxTok = max<int>(maxTok, curLen);
        if (curLen > maxWidth) {
            clamped.append(line + "\n");
            line.clear();
            nLines++;
        }
        line.append(temp + " ");
    }
    if (!line.empty()) clamped.append(line);
    else nLines--;
    return { clamped, nLines };
}
