#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include "game.h"

class QTimer;
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GameScene(QObject *parent = nullptr);

signals:

private slots:
    void update();
private:
    void loadPixmap();
    void checkResetClick(int x, int y);
    Game m_game;
    QPixmap m_tilesPixmap;
    QPixmap m_facePixmap;
    QTimer *m_timer;
    int m_x, m_y;
    bool m_resetVal;
    // QGraphicsScene interface
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // GAMESCENE_H
