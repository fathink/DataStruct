/*
    创建图
*/

#include "../include/general.h"

typedef char VertexType;  //顶点类型
typedef int EdgeType; //边类型
#define MAXVEX 100
#define INF 65535

typedef struct _Graph
{
    VertexType vertexs[MAXVEX];  //顶点数组
    EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵
    int numNodes,numEdges; //当前顶点数和边数
    
}MGraph;



/*
创建图
          A
       /  |   \
     B    E    D
       \  |   /
          C
*/
void CreateGraph(MGraph *G)
{
    int i,j;
    G->numNodes = 5; //顶点数
    G->numEdges = 5; // 边数

    for(i=0;i<MAXVEX;i++)
        for(j=0;j<MAXVEX;j++)
            G->arc[i][j] = INF;

    //初始化顶点
    G->vertexs[0] = 'A';
    G->vertexs[1] = 'B';
    G->vertexs[2] = 'C';
    G->vertexs[3] = 'D';
    G->vertexs[4] = 'E';

    //初始化边,无向图，对称矩阵
    G->arc[0][1] = 1; G->arc[1][0] = 1; 
    G->arc[0][3] = 1; G->arc[3][0] = 1;
    G->arc[0][4] = 1; G->arc[4][0] = 1;
    G->arc[1][2] = 1; G->arc[2][1] = 1;
    G->arc[2][3] = 1; G->arc[3][2] = 1;
    G->arc[2][4] = 1; G->arc[4][2] = 1;

    //打印邻接矩阵
    printf("Adjacency Matrix:\n");
    for(i=0;i<G->numNodes;i++)
    {
        for(j=0;j<G->numNodes;j++)
        {
            printf("%d\t",G->arc[i][j]);
        }
        printf("\n");
    }
}

/*
 深度优先遍历（DFS,Depth First Search） 
 */
Bool visited[MAXVEX]={FALSE}; // 记录访问过的节点
void DFS(MGraph G, int i)
{
    int j;
    visited[i] = TRUE;
    printf("%c",G.vertexs[i]); // 打印访问的节点

    for(j=0;j<G.numNodes;j++)
    {
        if(G.arc[i][j] != INF && visited[j] != TRUE)
            DFS(G,j);
    }


}

/*
 广度优先遍历（BFS,Breadth First Search） 
 */

void BFS()
{

}


int main()
{
    MGraph graph;
    CreateGraph(&graph);

    printf("\n深度优先遍历图:\n");
    DFS(graph,0);
    printf("\n");
    
    return 0;
}