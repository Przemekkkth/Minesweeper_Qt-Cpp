#include "gamescene.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QTimer>
#include <QGraphicsPixmapItem>

GameScene::GameScene(QObject *parent)
    : QGraphicsScene{parent}, m_game(), m_timer(new QTimer(this)), m_x(0), m_y(0), m_resetVal(false)
{
    loadPixmap();
    setSceneRect(0,0, m_game.RESOLUTION.width(), m_game.RESOLUTION.height());
    connect(m_timer, &QTimer::timeout, this, &GameScene::update);
    m_timer->start(m_game.ITERATION_VALUE);
}

void GameScene::update()
{
    clear();
    QGraphicsPixmapItem *faceItem = new QGraphicsPixmapItem(m_facePixmap.copy(int(m_resetVal)*m_facePixmap.width()/2, 0, m_facePixmap.width()/2, m_facePixmap.height()));
    addItem(faceItem);
    faceItem->setPos( 5 * m_game.w,0);
    for (int i = 1;i <= 10; i++)
    {
        for (int j = 1;j <= 10; j++)
        {
            if ( m_game.sgrid[m_x][m_y] == 9)
            {
                m_game.sgrid[i][j] = m_game.grid[i][j];
            }
            QGraphicsPixmapItem *gridItem =
                    new QGraphicsPixmapItem(m_tilesPixmap.copy( m_game.sgrid[i][j]*m_game.w, 0, m_game.w, m_game.w) );
            gridItem->setPos(i*m_game.w, j*m_game.w);
            addItem(gridItem);
        }
    }
}

void GameScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Qt::MouseButton button = event->button();

    QPointF clickedPos =  event->scenePos();
    m_x = static_cast<int>(clickedPos.x()) / m_game.w;
    m_y = static_cast<int>(clickedPos.y()) / m_game.w;

    qDebug() << "x " << m_x << " y " << m_y;

    if(button == Qt::LeftButton)
    {
        m_game.sgrid[m_x][m_y] = m_game.grid[m_x][m_y];
        checkResetClick(m_x, m_y);
    }
    else if(button == Qt::RightButton)
    {
        m_game.sgrid[m_x][m_y] = 11;
    }
    QGraphicsScene::mousePressEvent(event);
}

void GameScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_resetVal)
    {
        m_resetVal = false;
        m_game.init();
    }
    QGraphicsScene::mouseReleaseEvent(event);
}

void GameScene::loadPixmap()
{
    if(m_tilesPixmap.load(m_game.PATH_TO_TILES))
    {
        qDebug() << "TilesPixmap is loaded successfully";
    }
    else
    {
        qDebug() << "TilesPixmap is not loaded successfully";
    }

    if(m_facePixmap.load(m_game.PATH_TO_FACE))
    {
        qDebug() << "FacePixmap is loaded successfully";
    }
    else
    {
        qDebug() << "FacePixmap is not loaded successfully";
    }
}

void GameScene::checkResetClick(int x, int y)
{
    if( y == 0 && (x == 5 || x == 6))
    {
        m_resetVal = true;
    }
}
