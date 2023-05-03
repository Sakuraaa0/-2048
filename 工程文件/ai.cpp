#include "ai.h"
#include "box.h"
#include "ui_box.h"

bool AI::moved(int directions)
{



    bool flag1 = false;//记录是否有移动
    bool flag2 = false;//记录是否有方块相加
    bool flag[4][4];//记录格子是否参加过合并
    memset(flag, false, sizeof(flag));//初始化
    int i, j, k;
    switch (directions)
    {
    case 0:
        for (i = 0; i < 4; i++)//逐列计算
        {
            k = 0;
            for(j=0;j<4;j++)
            {
                if(cellMatrix[j][i] == 0)//跳到第一个不为零的方块
                    continue;
                if(j != k)
                    flag1 = Swap(cellMatrix[j][i], cellMatrix[k][i]);//交换（j,i）(k,i) 并记录存在方块移动

                if (k > 0 && cellMatrix[k][i] == cellMatrix[k - 1][i] && !flag[k - 1][i])//相邻两数相同相加，记录加过的位值防止连加
                {
                    cellMatrix[k - 1][i] <<= 1;//被加位乘2
                    cellMatrix[k][i] = 0;//加位置0
                    Score += cellMatrix[k - 1][i];//分数增加为合并获得的数
                    countNumber--;//非零数字位数-1
                    flag[k - 1][i] = true;//该格子已参加过合并
                    flag2 = true;//存在方块相加


                }
                else//相邻两数不同，k进位
                    k++;

            }
        }
        break;
        //下面三种运算原理相同，不再注释
    case 1:
        for (i = 0; i < 4; i++)
        {
            k = 3;
            for(j=3;j>=0;j--)
            {
                 if(cellMatrix[j][i] == 0)
                    continue;
                if(j != k)
                    flag1 = Swap(cellMatrix[j][i], cellMatrix[k][i]);

                if (k < 3 && cellMatrix[k][i] == cellMatrix[k + 1][i] && !flag[k + 1][i])
                {
                    cellMatrix[k + 1][i] <<= 1;
                    flag[k + 1][i] = true;
                    cellMatrix[k][i] = 0;
                    Score += cellMatrix[k + 1][i];
                    countNumber--;
                    flag2 = true;


                }
                else
                    k--;

            }
        }
        break;
    case 2:
        for (i = 0; i < 4; i++)
        {
            k = 0;
            for(j=0;j<4;j++)
            {
                if(cellMatrix[i][j] == 0)
                    continue;
                if(j != k)
                    flag1 = Swap(cellMatrix[i][j], cellMatrix[i][k]);

                if (k > 0 && cellMatrix[i][k] == cellMatrix[i][k - 1] && !flag[i][k - 1])
                {
                   cellMatrix[i][k - 1] <<= 1;
                   cellMatrix[i][k] = 0;
                    flag[i][k - 1] = true;
                    Score += cellMatrix[i][k - 1];
                    countNumber--;
                    flag2 = true;

                }
                else
                    k++;

            }
        }
        break;
    case 3:
        for (i = 0; i < 4; i++)
        {
            k = 3;
            for(j=3;j>=0;j--)
            {
                if (cellMatrix[i][j] == 0)
                    continue;
                if(j !=k)
                    flag1 = Swap(cellMatrix[i][j], cellMatrix[i][k]);

                if (k < 3 && cellMatrix[i][k] == cellMatrix[i][k + 1] && !flag[i][k + 1])
                {
                    cellMatrix[i][k + 1] <<= 1;
                    cellMatrix[i][k] = 0;
                    flag[i][k + 1] = true;
                    Score += cellMatrix[i][k + 1];
                    countNumber--;
                    flag2 = true;

                }
                else
                    k--;

            }
        }
        break;
    }
    if (flag1 || flag2)//存在有效移动或方块相加
    {
       return 1;
    }
else
        return 0;

}

SearchResult AI::search(int depth, double alpha, double beta, int positions, int cutoffs)
{
    double bestScore;
    int bestMove = -1;
          SearchResult result ;
           int directions[4] = {0,1,2,3};

           if (this->playerTurn) {  // Max 层
               bestScore = alpha;
               for (int i=3; i>=0;i--) {  // 玩家遍历四个滑动方向，找出一个最好的
                  // AI *newGrid = new AI(this->aibox);
                   AI newGrid(this->aibox);
                   if (newGrid.moved(directions[i])) {
                       for(int a=0;a<4;a++)
                           for(int b=0;b<4;b++)
                               newGrid.aibox.box_get(a,b,newGrid.cellMatrix[a][b]);
                       positions++;

                       newGrid.changeplayTurn_false();

                       if (depth == 0) { //如果depth=0,搜索到该层后不再向下搜索
                           result.move = directions[i];
                           result.score = newGrid.evaluate();
                       } else { //如果depth>0,则继续搜索下一层，下一层为电脑做出决策的层
                           result = newGrid.search(depth - 1, bestScore, beta, positions, cutoffs);


                           positions = result.positions;
                           cutoffs = result.cutoffs;
                       }

                       //如果当前搜索分支的格局分数要好于之前得到的分数，则更新决策，同时更新bestScore，也即alpha的值
                       if (result.score > bestScore) {
                           bestScore = result.score;
                           bestMove = directions[i];
                       }
                       //如果当前bestScore也即alpha>beta时，表明这个节点下不会再有更好解，于是剪枝
                       if (bestScore > beta) {
                           cutoffs++;  //剪枝
                             SearchResult a;
                             a.move=bestMove;
                             a.score=beta;
                             a.positions=positions;
                             a.cutoffs=cutoffs;

                             return a;
                       }
                   }

               }
           } else {
               // Min 层，该层为电脑层(也即我们的对手)，这里我们假设对手(电脑)足够聪明，总是能做出使格局变到最坏的决策
               bestScore = beta;

               // 尝试给每个空闲块填入2或4，然后计算格局的评估值


               // 找出使格局变得最坏的所有可能操作

               // 然后遍历这些操作，基于这些操作向下搜索，找到使得格局最坏的分支
               for (int i = 0; i < 4; i++)
               {

                   for(int j=0;j<4;j++)
                   {

                   AI newGrid(this->aibox);
                   if(newGrid.cellMatrix[i][j]!=0)
                       continue;
                   positions++;
                   // 向下搜索，下一层为Max层，轮到玩家进行决策
                   newGrid.playerTurn = true;
                   newGrid.cellMatrix[i][j]=2;
                   // 这里depth没有减1是为了保证搜索到最深的层为Max层
                   result = newGrid.search(depth, alpha, bestScore, positions, cutoffs);
                   positions = result.positions;
                   cutoffs = result.cutoffs;

                   // 该层为Min层，哪个分支的局势最不好，就选哪个分支，这里的bestScore代表beta
                   if (result.score < bestScore) {
                       bestScore = result.score;
                   }
                   // 如果当前bestScore也即beta<alpha时，表明这个节点下不会再有更好解，于是剪枝
                   if (bestScore < alpha) {
                       cutoffs++;  //减枝
                       SearchResult a;
                       a.move=-1;
                       a.score=alpha;
                       a.positions=positions;
                       a.cutoffs=cutoffs;
                       return a;
                   }
               }
               }
           }
           SearchResult a;
           a.move=bestMove;
           a.score=bestScore;
           a.positions=positions;
           a.cutoffs=cutoffs;
           return a;

}
void AI::get(Box* a)
{

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            this->cellMatrix[i][j]=a->givebox(i,j);
        }
}
bool AI::isCellAvailable(int cnt_x, int cnt_y) {
     return cellMatrix[cnt_x][cnt_y] == 0;
}
bool AI::isInBounds(int cnt_x, int cnt_y) {
    return cnt_x >= 0 && cnt_x < 4 && cnt_y >= 0 && cnt_y < 4;
}
double AI::smoothness() {
    int smoothness = 0;
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            if (this->cellMatrix[x][y] != 0)
            {
                double value = log(this->cellMatrix[x][y]) / log(2);
                // 计算水平方向和垂直方向的平滑性评估值
                for (int direction = 1; direction <= 2; direction++)
                {
                    int a[2] = { this->vectors[direction][0], this->vectors[direction][1] };
                    int cnt_x = x, cnt_y = y;
                    do {
                        cnt_x += a[0];
                        cnt_y += a[1];
                    } while (isInBounds(cnt_x, cnt_y) && isCellAvailable(cnt_x, cnt_y));
                    if (isInBounds(cnt_x, cnt_y)) {
                        if (cellMatrix[cnt_x][cnt_y] != 0) {
                            double targetValue = log(cellMatrix[cnt_x][cnt_y]) / log(2);
                            smoothness -= abs(value - targetValue);
                        }
                    }
                }
            }
        }
    }
    return smoothness;
}
double AI::monotonicity() {
    // 保存四个方向格局单调性的评估值
    int totals[4] = { 0, 0, 0, 0 };

    // 左/右 方向
    for (int x = 0; x < 4; x++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && this->cellMatrix[x][next] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (this->cellMatrix[x][current] != 0) ? log(this->cellMatrix[x][current]) / log(2) : 0;
            double nextValue = (this->cellMatrix[x][next] != 0) ? log(this->cellMatrix[x][next]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[0] += nextValue - currentValue;
            }
            else if (nextValue > currentValue) {
                totals[1] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }

    // 上/下 方向
    for (int y = 0; y < 4; y++) {
        int current = 0;
        int next = current + 1;
        while (next < 4) {
            while (next < 4 && this->cellMatrix[next][y] == 0) next++;
            if (next >= 4) next--;
            double currentValue = (this->cellMatrix[current][y] != 0) ? log(this->cellMatrix[current][y]) / log(2) : 0;
            double nextValue = (this->cellMatrix[next][y] != 0) ? log(this->cellMatrix[next][y]) / log(2) : 0;
            if (currentValue > nextValue) {
                totals[2] += nextValue - currentValue;
            }
            else if (nextValue > currentValue) {
                totals[3] += currentValue - nextValue;
            }
            current = next;
            next++;
        }
    }

    // 取四个方向中最大的值为当前格局单调性的评估值
    return (totals[0]> totals[1])?totals[0]:totals[1] + (totals[2]> totals[3])?totals[2]:totals[3];
}
int AI::getMax()
{
int high = 0;
for (int i = 0;i < 4;i++)
{
    for (int j = 0;j < 4;j++)
        if (this->cellMatrix[i][j] > high)
            high = cellMatrix[i][j];
}
return high;
}
double AI::maxValue() {
    return log(getMax()) / log(2);
}
int AI::getEmptyNum() {
    int sum = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (cellMatrix[i][j] == 0) sum++;
    return sum;
}
double AI::evaluate() {
    double smoothWeight = 0.1, //平滑性权重系数
        monoWeight = 1.3, //单调性权重系数
        emptyWeight = 2.7, //空格数权重系数
        maxWeight = 1.0; //最大数权重系数
    return smoothness() * smoothWeight
        + monotonicity() * monoWeight
        + log(getEmptyNum()) * emptyWeight
            + maxValue() * maxWeight;
}

void AI::changeplayTurn_false()
{
    this->playerTurn=false;
}
// 基于alpha-beta的Minimax搜索，进行迭代深搜
 int AI::iterativeDeep(){
     int depth = 0;
     int best = -1;
     int i=1;
     do {
         SearchResult newBest = this->search(depth, -10000, 10000, 0, 0);
         if (newBest.move == -1) break;
         else best = newBest.move;
         depth++;
         i--;
     } while (i>0);
     return best;
 }
 int AI::getBestMove() {
         return this->iterativeDeep();
     }
