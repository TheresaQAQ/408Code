//
// Created by zhouq on 25-8-25.
//

//图的邻接矩阵实现
#define MAX_SIZE 10

typedef struct MGraph{
  char vex[MAX_SIZE];
  int weight[MAX_SIZE][MAX_SIZE];
  int vexNum,arcNum;
}Graph;