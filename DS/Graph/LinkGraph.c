//
// Created by zhouq on 25-8-25.
//

//邻接表实现

#define MAX_SIZE 10

typedef struct ArcNode {
  int vexIndex;
  int weight;
  struct ArcNode *next;
}ArcNode;

typedef struct VexNode {
  char data;
}VexNode;

typedef struct Graph {
  VexNode node[MAX_SIZE];
  int arcNum, nodeNum;
}Graph;