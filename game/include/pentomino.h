#ifndef PENTOMINO_H
#define PENTOMINO_H

#include <vector>
#include <map>
#include "raylib.h"

enum class PentominoType {
    I,
    X,
    Z,
    V,
    T,
    W,
    U,
    L,
    N,
    Y,
    F,
    P,
    NONE // Used for empty cells
};

static const std::map<PentominoType, Color> colorMap = {
    {PentominoType::I, RED},
    {PentominoType::X, BLUE},
    {PentominoType::Z, GREEN},
    {PentominoType::V, YELLOW},
    {PentominoType::T, PURPLE},
    {PentominoType::W, ORANGE},
    {PentominoType::U, PINK},
    {PentominoType::L, BROWN},
    {PentominoType::N, GRAY},
    {PentominoType::Y, DARKPURPLE},
    {PentominoType::F, DARKBLUE},
    {PentominoType::P, DARKGREEN},
    {PentominoType::NONE, LIGHTGRAY} // Color for empty cells
};  

class Pentomino {
private:
    PentominoType type;
    std::vector<std::vector<PentominoType>> shape;

public:
    static Color getColor(PentominoType type);

};

#endif // PENTOMINO_H