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


/*
    Dijkstra算法求最短路径
    Args: G,图结构， v0表示出发顶点的索引
*/
void ShortestPathByDijkstra(MGraph G, int v0)
{
    int Path[G.numNodes]; // Path[v]的值表示前驱顶点的下标
    int Dis[G.numNodes]; // Dis[v]表示v0到v的最短路径
    int final[G.numNodes]; // final[v]表示求得v0到v的最短路径

    int v,min,w,k;
    //初始化
    for(v=0;v<G.numNodes;v++)
    {
        Path[v] = -1;
        Dis[v] = G.arc[v0][v];
        final[v] = 0;
    }

    Dis[v0] = 0; //v0到v0的路径为0
    final[v0] = 1; //v0到v0不需要求最短路径

    //主循环，每次求的v0到v的最短距离
    for(v=1; v<G.numNodes; v++)
    {
        min = INF;
        for(w=0;w<G.numNodes;w++)
        {
            if(final[w]!=1 && Dis[w] < min)
            {
                k = w;  
                min = Dis[w]; 
            }

        }

        final[k] = 1; //找到当前距离v0的最小距离的节点为k

        //更新最短距离,关键逻辑
        for(w=0;w<G.numNodes;w++)
        {
            if(final[w]!=1 && min+G.arc[k][w] < Dis[w])
            {
                Dis[w] = min+G.arc[k][w]; // 更新v0到w的最短路径
                Path[w] = k; // w的前驱节点为k，站在k的基础上使得距离最短

            }

        }

    }

    //输出最短路径
    printf("\n");
    for(v=0; v<G.numNodes; v++)
    {
        printf("%s\t",G.vertexs[v]);
    }
    printf("\n");
    for(v=0;v<G.numNodes;v++)
    {
        printf("%d\t",Dis[v]); // v0到各个节点的最短距离
    }
    printf("\n");

    for(v=0;v<G.numNodes;v++)
    {
        printf("%d\t",Path[v]);
    }

    //v0到任意点的最短路径
    printf("\nShort Path: ");
    v=8;
    while(1)
    {
        if(Path[v]==-1){
            printf("%d<-%d",v,v0);  // 前驱为-1，表示到达起始点
            break;
        } 
        printf("%d<-",v);
        v=Path[v];
    }
    printf("\n");
    
    
    


}


int main()
{
    Status flag;
    MGraph graph;
    CreateGraph(&graph);
    
    //Dijkstra算法求最短路径
    ShortestPathByDijkstra(graph, 0);

    // //Kruskal算法生成最小生成树
    // MinSpanTree_Kruskal(graph);
    
    return 0;
}