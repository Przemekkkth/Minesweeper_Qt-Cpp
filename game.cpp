#include "game.h"

const QSize Game::RESOLUTION = QSize(400, 400);

Game::Game()
    : w(32), PATH_TO_TILES(":/images/tiles.png"), PATH_TO_FACE(":/images/face.png"), ITERATION_VALUE(1000.0f/60.0f)
{
    init();
}

void Game::init()
{
    srand(time(0));
    for (int i=1;i<=10;i++)
    {
        for (int j=1;j<=10;j++)
         {
           sgrid[i][j]=10;
           if (rand()%5==0)  grid[i][j]=9;
           else grid[i][j]=0;
         }
    }


    for (int i=1 ; i<=10 ; i++)
    {
        for (int j=1; j<=10; j++)
         {
           int n=0;
           if (grid[i][j] == 9)
           {
               continue;
           }
           if (grid[i+1][j] == 9)
           {
               n++;
           }
           if (grid[i][j+1] == 9)
           {
               n++;
           }
           if (grid[i-1][j] == 9)
           {
               n++;
           }
           if (grid[i][j-1] == 9)
           {
               n++;
           }
           if (grid[i+1][j+1] == 9)
           {
               n++;
           }
           if (grid[i-1][j-1] == 9)
           {
               n++;
           }
           if (grid[i-1][j+1] == 9)
           {
               n++;
           }
           if (grid[i+1][j-1] == 9)
           {
               n++;
           }
           grid[i][j]=n;
         }
    }
}
