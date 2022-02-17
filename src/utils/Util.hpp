#ifndef UTIL_H_
#define UTIL_H_

#include "../include/raylib-cpp/raylib-cpp.hpp"

#include <optional>

using std::string_view;
using std::string;
using std::optional;
using std::pair;

namespace Util {
    pair<string, unsigned short> clampText(
        const string &str,
        int maxWidth,
        int fontSize);
    pair<string, unsigned short> clampText(
        const string &str,
        int maxWidth,
        int fontSize,
        unsigned int& maxTok);
}

#endif // UTIL_H_
