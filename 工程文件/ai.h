#ifndef AI_H
#define AI_H
#include <QWidget>
#include <QFile>
#include <QPainter>
#include <QFont>
#include <QPushButton>
#include <QList>
#include <QTimer>
#include<cmath>
#include "box.h"
class AI:public Box
{
private:
    bool playerTurn = true;
    int score;

    int vectors[4][2] = {
                  {0, -1}, // up
                  {1, 0},  // right
                  {0, 1},  // down
                  {-1, 0}   // left
    };

public:
    int cellMatrix[4][4];
    Box aibox;
    bool moved(int directions);//仅矩阵变化
    AI(){}
    AI(Box* a)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                this->cellMatrix[i][j]=a->givebox(i,j);
                this->aibox.box_get(i,j,a->givebox(i,j));
            }
    }
    AI(Box a)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                this->cellMatrix[i][j]=a.givebox(i,j);
                this->aibox.box_get(i,j,a.givebox(i,j));
            }
    }
    void get(Box* a);

    bool isCellAvailable(int cnt_x, int cnt_y) ;
    bool isInBounds(int cnt_x, int cnt_y);
    double smoothness();
    double monotonicity() ;
    int getMax();

    double maxValue();
    int getEmptyNum();
    double evaluate() ;
    SearchResult search(int depth, double alpha, double beta, int positions, int cutoffs);
    void changeplayTurn_false();

    // 基于alpha-beta的Minimax搜索，进行迭代深搜
     int iterativeDeep();
     int getBestMove() ;

};

#endif // AI_H
