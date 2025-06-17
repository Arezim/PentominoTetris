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

static const std::map<PentominoType, std::vector<std::vector<PentominoType>>> pentominoShapes = {
    {PentominoType::I, {
        {PentominoType::I, PentominoType::I, PentominoType::I, PentominoType::I, PentominoType::I}
    }},
    {PentominoType::X, {
        {PentominoType::X, PentominoType::NONE, PentominoType::X},
        {PentominoType::NONE, PentominoType::X, PentominoType::NONE},
        {PentominoType::X, PentominoType::NONE, PentominoType::X}
    }},
    {PentominoType::Z, {
        {PentominoType::Z, PentominoType::Z, PentominoType::Z},
        {PentominoType::NONE, PentominoType::Z, PentominoType::NONE},
        {PentominoType::Z, PentominoType::Z, PentominoType::Z}
    }},
    {PentominoType::V, {
        {PentominoType::V, PentominoType::V, PentominoType::V},
        {PentominoType::V, PentominoType::NONE, PentominoType::NONE},
        {PentominoType::V, PentominoType::NONE, PentominoType::NONE}
    }},
    {PentominoType::T, {
        {PentominoType::T, PentominoType::T, PentominoType::T},
        {PentominoType::NONE, PentominoType::T, PentominoType::NONE},
        {PentominoType::NONE, PentominoType::T, PentominoType::NONE}
    }},
    {PentominoType::W, {
        {PentominoType::NONE, PentominoType::NONE, PentominoType::W},
        {PentominoType::NONE, PentominoType::W, PentominoType::W},
        {PentominoType::W, PentominoType::W, PentominoType::NONE}
    }},
    {PentominoType::U, {
        {PentominoType::U, PentominoType::U},
        {PentominoType::U, PentominoType::NONE},
        {PentominoType::U, PentominoType::U}
    }},
    {PentominoType::L, {
        {PentominoType::L, PentominoType::NONE},
        {PentominoType::L, PentominoType::NONE},
        {PentominoType::L, PentominoType::NONE},
        {PentominoType::L, PentominoType::L}
    }},
    {PentominoType::N, {
        {PentominoType::NONE, PentominoType::N},
        {PentominoType::N, PentominoType::N},
        {PentominoType::N, PentominoType::NONE},
        {PentominoType::N, PentominoType::NONE}
    }},
    {PentominoType::Y, {
        {PentominoType::Y, PentominoType::NONE},
        {PentominoType::Y, PentominoType::Y},
        {PentominoType::Y, PentominoType::NONE},
        {PentominoType::Y, PentominoType::NONE}
    }},
    {PentominoType::F, {
        {PentominoType::NONE, PentominoType::F, PentominoType::F},
        {PentominoType::F, PentominoType::F, PentominoType::NONE},
        {PentominoType::NONE, PentominoType::F, PentominoType::NONE}
    }},
    {PentominoType::P, {
        {PentominoType::P, PentominoType::P},
        {PentominoType::P, PentominoType::P},
        {PentominoType::P, PentominoType::NONE}
    }}
};

class Pentomino {
private:
    PentominoType type;
    std::vector<std::vector<PentominoType>> shape;

public:
    static Color getColor(PentominoType type);

};

#endif // PENTOMINO_H