#ifndef GAME_H
#define GAME_H
#include <QSize>

class Game
{
public:
    Game();
    static const QSize RESOLUTION;
    const int w;
    const QString PATH_TO_TILES;
    const QString PATH_TO_FACE;
    int grid[12][12];
    int sgrid[12][12];
    const float ITERATION_VALUE;


    void init();
};

#endif // GAME_H
