/*
    图的最短路径算法
    ·Dijkstra算法：时间复杂度为O(N^2)；
    ·Floyd算法：时间复杂度为O(N^3)；    
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
    创建图，图结构见《大话数据结构》P220
*/
void CreateGraph(MGraph *G)
{
    int i,j;
    G->numNodes = 9; //顶点数
    G->numEdges = 16; // 边数

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
    G->arc[0][1] = 1; G->arc[1][0] = 1; 
    G->arc[0][2] = 5; G->arc[2][0] = 5; 
    G->arc[1][2] = 3; G->arc[2][1] = 3; 
    G->arc[1][4] = 5; G->arc[4][1] = 5; 
    G->arc[1][3] = 7; G->arc[3][1] = 7; 
    G->arc[2][4] = 1; G->arc[4][2] = 1; 
    G->arc[2][5] = 7; G->arc[5][2] = 7; 
    G->arc[3][4] = 2; G->arc[4][3] = 2;
    G->arc[3][6] = 3; G->arc[6][3] = 3; 
    G->arc[4][5] = 3; G->arc[5][4] = 3; 
    G->arc[4][6] = 6; G->arc[6][4] = 6; 
    G->arc[4][7] = 9; G->arc[7][4] = 9; 
    G->arc[5][7] = 5; G->arc[7][5] = 5; 
    G->arc[6][7] = 2; G->arc[7][6] = 2;
    G->arc[6][8] = 7; G->arc[8][6] = 7;
    G->arc[7][8] = 4; G->arc[8][7] = 4;   

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
    printf("\n");
    
}


int main()
{
    Status flag;
    MGraph graph;
    CreateGraph(&graph);
    
    // //Prime算法实现最小生成树 
    // MinSpanTree_Prime(graph);

    // //Kruskal算法生成最小生成树
    // MinSpanTree_Kruskal(graph);
    
    return 0;
}