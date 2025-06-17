#include "pentomino.h"

Color Pentomino::getColor(PentominoType type)
        {
            auto pair = colorMap.find(type);
            if (pair != colorMap.end()) {
                return pair->second;
            }
            return LIGHTGRAY; // Default color for unknown types
        }