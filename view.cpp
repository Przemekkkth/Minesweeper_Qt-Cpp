#include "view.h"
#include "game.h"
#include "gamescene.h"
View::View()
    : QGraphicsView(), m_gameScene(new GameScene(this))
{
    resize(Game::RESOLUTION.width()+2, Game::RESOLUTION.height()+2);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(m_gameScene);
}
