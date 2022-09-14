/*
    最小生成树,边权重和最小的树，核心有两种算法实现最小生成树，Prim&Kruskal
    ·Prim算法：基于顶点出发，时间复杂度为O(N^2),针对稠密图更有优势；
    ·Kruskal算法：基于边出发，时间复杂度为O(NLogN),针对稀疏图有很大的优势；    
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
    G->arc[2][8] = 8;  G->arc[8][2] = 8;
    G->arc[3][8] = 21; G->arc[8][3] = 21; 
    G->arc[4][3] = 20; G->arc[3][4] = 20; 
    G->arc[4][5] = 26; G->arc[5][4] = 26; 
    G->arc[5][6] = 17; G->arc[6][5] = 17; 
    G->arc[6][3] = 24; G->arc[3][6] = 24; 
    G->arc[6][7] = 19; G->arc[7][6] = 19; 
    G->arc[7][3] = 16; G->arc[3][7] = 16; 
    G->arc[7][4] = 7;  G->arc[4][7] = 7; 
    
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

/*-------------- Prime --------------*/

void MinSpanTree_Prime(MGraph G)
{
    printf("Prime:\n");
    int total = 0;
    int min,i,j,k;
    int adjvex[MAXVEX]; // 索引是顶点，值是该顶点当前最小权重边所连接的顶点
    int lowcost[MAXVEX]; // 索引是顶点，值是该顶点最小的边权值

    lowcost[0] = 0; // 初始化第一个权值为0，即将V0加入最小生成树，值为0表示加入最小生成树
    adjvex[0] = 0; // 第一个顶点下标为0
    for(j=1;j<G.numNodes;j++){
        lowcost[j]=G.arc[0][j];
        adjvex[j] = 0;
    }

    for(i=1;i<G.numNodes;i++)
    {
        min = INF;

        // 遍历所有节点
        j = 1; k=0;
        while (j<G.numNodes)
        {
            if(lowcost[j]!=0 && lowcost[j] < min){
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        total+=G.arc[adjvex[k]][k];
        printf("Edge=(%d,%d),Weight=%d,Total=%d\n",adjvex[k],k,G.arc[adjvex[k]][k],total); // 打印当前的最短路径
        lowcost[k] = 0; //将k节点加入最小生成树

        //更新lowcost数组
        for(j=1;j<G.numNodes;j++)
        {
            //以k为节点，遍历k节点的所有边，如果有边所连接的节点权重小于之前的权重，则更新
            if(lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
            {
                lowcost[j] = G.arc[k][j];
                adjvex[j] = k; //节点j与节点k连接
            }
        }
        
    }

}

/*-------------- Kruskal-----------*/
//定义边集数组
typedef struct _Edge
{
    int begin;
    int end;
    int weight;
}Edge;

void sort(Edge edges[],int length)
{
    int i,j;
    Edge e;

    //简单冒泡排序
    for(i=0;i<length-1;i++)
    {
        for(j=0;j<length-1;j++)
        {
            if(edges[j].weight > edges[j+1].weight)
            {
                e = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = e;
            }
        }
    }
}

// 查找连接线的尾部下标
int Find(int *parent, int f)
{
    while (parent[f]>0)
    {
        f = parent[f];
    }

    return f;
    
}

void MinSpanTree_Kruskal(MGraph G)
{
    printf("\nKruskal:\n");
    
    int i,j,n,m;
    Edge edges[G.numEdges]; //定义边集数组
    int parent[G.numEdges]; //定义一维数组用于判断呢是否形成回路
  

    //邻接矩阵转换成边集数组
    int k=0;
    for(i=0;i<G.numNodes;i++)
    {
        for(j=i+1;j<G.numNodes;j++)
        {
            if(G.arc[i][j]!=INF){
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.arc[i][j];
                k++;
            }

        }
    }
    for(i=0;i<G.numNodes;i++)
    {
        parent[i] = 0;
    }
    

    //边集数组按照weight从小到大排序
    sort(edges,G.numEdges);

    //循环每一条边
    int total = 0;
    for(i=0;i<G.numEdges;i++)
    {
        n = Find(parent, edges[i].begin);
        m = Find(parent, edges[i].end);

        // m和n不相等，说明没有形成环路,加入最小生成树
        if(n!=m)
        {
            parent[n] = m;

            total += edges[i].weight;
            printf("Edge=(%d,%d),Weight=%d,Total=%d\n",edges[i].begin,edges[i].end,edges[i].weight,total);
            
        }

    }
    printf("\n");

}

int main()
{
    Status flag;
    MGraph graph;
    CreateGraph(&graph);
    
    //Prime算法实现最小生成树 
    MinSpanTree_Prime(graph);

    //Kruskal算法生成最小生成树
    MinSpanTree_Kruskal(graph);
    
    return 0;
}