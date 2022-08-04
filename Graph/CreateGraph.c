/*
    创建图
*/



typedef char VertexType;  //顶点类型
typedef int EdgeType; //边类型
#define MAXVEX 100
#define INFINITY 65535

typedef struct _Graph
{
    VertexType vertexs[MAXVEX]; //顶点数组
    EdgeType arc[MAXVEX][MAXVEX];  //邻接矩阵
    int numNodes,numEdges; //当前顶点数和边数
    
}MGraph;
