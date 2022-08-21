/*
    最小生成树
    Prim算法实现最小生成树
*/

#include "../include/general.h"

/* --------图相关的定义-------- */
typedef char* VertexType;  //顶点类型，字符串
typedef int EdgeType; //边类型
#define MAXVEX 100
#define INF 65536

typedef struct _Graph
{
    VertexType vertexs[MAXVEX];  //顶点数组
    EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵
    int numNodes,numEdges; //当前顶点数和边数
    
}MGraph;

/*
    创建图，图结构见《大话数据结构》P209
*/
void CreateGraph(MGraph *G)
{
    int i,j;
    G->numNodes = 9; //顶点数
    G->numEdges = 15; // 边数

    //初始化邻接矩阵
    for(i=0;i<MAXVEX;i++)
        for(j=0;j<MAXVEX;j++)
        {
             G->arc[i][j] = INF;
              G->arc[i][i] = 0;
        }


    //初始化顶点
    G->vertexs[0] = "V0";
    G->vertexs[1] = "V1";
    G->vertexs[2] = "V2";
    G->vertexs[3] = "V3";
    G->vertexs[4] = "V4";
    G->vertexs[5] = "V5";
    G->vertexs[6] = "V6";
    G->vertexs[7] = "V7";
    G->vertexs[8] = "V8";

    //初始化边,无向图，对称矩阵
    G->arc[0][1] = 10; G->arc[1][0] = 10; 
    G->arc[0][5] = 11; G->arc[5][0] = 11; 
    G->arc[1][2] = 18; G->arc[2][1] = 18; 
    G->arc[1][8] = 12; G->arc[8][1] = 12; 
    G->arc[1][6] = 16; G->arc[6][1] = 16;
    G->arc[3][2] = 22; G->arc[2][3] = 22;  
    G->arc[2][8] = 8; G->arc[8][2] = 8;
    G->arc[3][8] = 21; G->arc[8][3] = 21; 
    G->arc[4][3] = 20; G->arc[3][4] = 20; 
    G->arc[4][5] = 26; G->arc[5][4] = 26; 
    G->arc[5][6] = 17; G->arc[6][5] = 17; 
    G->arc[6][3] = 24; G->arc[3][6] = 24; 
    G->arc[6][7] = 19; G->arc[7][6] = 19; 
    G->arc[7][3] = 16; G->arc[3][7] = 16; 
    G->arc[7][4] = 7; G->arc[4][7] = 7; 
    
     //打印邻接矩阵
    printf("Adjacency Matrix:\n");
    for(i=0;i<G->numNodes;i++)
    {
        printf("%s\t",G->vertexs[i]);
    }
    printf("\n");

   
    for(i=0;i<G->numNodes;i++)
    {
        for(j=0;j<G->numNodes;j++)
        {
            printf("%d\t",G->arc[i][j]);
        }
        printf("\n");
    }
    
}

void MinSpanTree_Prime(MGraph G)
{
    

}

int main()
{
    Status flag;
    MGraph graph;
    CreateGraph(&graph);

    
    return 0;
}