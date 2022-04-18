//DepthFirstSearch_DFS by adjacency matrix of directed graphs
//2015/12/7


#include <iostream>
#include <iomanip>
using namespace std;
#define numVertex 5  //Graph's vertex numbers

void createGraph(int GraphAdjMat[][numVertex], int x, int y);
void displaygraph(int GraphAdjMat[][numVertex]);
void DFS(int GraphAdjMat[][numVertex], int* VertexStatusArray, int i);
void DFS_Travel(int GraphAdjMat[][numVertex], int* VertexStatusArray);

int main(){

	//init the adjacency matrix of graph
	int(*GraphAdjMat)[numVertex] = (int(*)[numVertex])malloc(sizeof(int)*numVertex*numVertex);
	for (int i = 0; i < numVertex; ++i)
		for (int j = 0; j < numVertex; ++j)
			GraphAdjMat[i][j] = 0;
  
	//init the status array
	//int* VertexStatusArray = (int *)malloc(sizeof(int)*numVertex);
	int VertexStatusArray[numVertex];
	for (int i = 0; i < numVertex; ++i)
		VertexStatusArray[i] = 0;

	//creat the adjacenxy matrix of graph
	cout << "After initialization of the adjacency matrix of graph: \n";
	displaygraph(GraphAdjMat);
	cout << "Creating a graph...\n";
	createGraph(GraphAdjMat, 0, 3);
	createGraph(GraphAdjMat, 0, 4);
	createGraph(GraphAdjMat, 3, 1);
	createGraph(GraphAdjMat, 3, 2);
	createGraph(GraphAdjMat, 4, 1);
	cout << "After creat a graph: \n";
	displaygraph(GraphAdjMat);

	//Depth First Search the directed graph
	DFS_Travel(GraphAdjMat, VertexStatusArray);
    cout << endl;

	return 0;
}



//creat a graph's agjacency matirx
void createGraph(int GraphAdjMat[][numVertex], int x, int y){
	GraphAdjMat[x][y] = 1;
}

void displaygraph(int GraphAdjMat[][numVertex]){
	for (int i = 0; i < numVertex; ++i){
		for (int j = 0; j<numVertex; ++j)
			cout << left << setw(3) << GraphAdjMat[i][j];
		cout << "\n";
	}
	cout << "\n";
}

void DFS(int GraphAdjMat[][numVertex], int* VertexStatusArray, int i){
	VertexStatusArray[i] = 1;//the i-th vertex changed to 1,mean is visted
	cout << i << " ";
	for (int j = 0; j < numVertex; ++j){
		if (GraphAdjMat[i][j] == 1 && !VertexStatusArray[j])
			DFS(GraphAdjMat, VertexStatusArray, j);
	}
}


//depth first search 
void DFS_Travel(int GraphAdjMat[][numVertex], int* VertexStatusArray){
	cout << "start depth first serach...\n";
	for (int i = 0; i < numVertex; ++i){
		if (!VertexStatusArray[i])
			DFS(GraphAdjMat, VertexStatusArray, i);
	}
}


