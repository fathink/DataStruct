/*
    创建图
*/


typedef char VertexType;  //顶点类型
typedef int EdgeType; //边类型
#define MAXVEX 100
#define INFINITY 65535

typedef struct _Graph
{
    VertexType vertexs[MAXVEX];  //顶点数组
    EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵
    int numNodes,numEdges; //当前顶点数和边数
    
}MGraph;



/*
创建图
          V0
       /  |   \
     V1   |    V3
       \  |   /
          V2
*/
void CreateGraph(MGraph *G)
{
     G->numNodes = 4; //顶点数
    G->numEdges = 4; // 边数
    
   

}

int main()
{
    MGraph graph;
    CreateGraph(&graph);

    
    return 0;
}