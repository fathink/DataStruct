//ShortestPath_Floyd algorithm by adjacency matrix of directed graphs
//2015/12/13

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define numVertex 6 //Graph's vertex numbers
#define INFINITY 65536

string VertexName[numVertex]={"V0","V1","V2","V3","V4","V5"};
void createGraph(int GraphAdjMat[][numVertex], int x, int y,int weight);
void displaygraph(int GraphAdjMat[][numVertex]);
void ShortestPath_Folyd(int GraphAdjMat[][numVertex],int (*P)[numVertex],int (*D)[numVertex]);

int main(){
	
	//init the adjacency matrix of graph
	int(*GraphAdjMat)[numVertex] = (int(*)[numVertex])malloc(sizeof(int)*numVertex*numVertex);
	for (int i = 0; i < numVertex; ++i)
		for (int j = 0; j < numVertex; ++j)
			GraphAdjMat[i][j] = INFINITY;
	for(int i = 0;i < numVertex;++i)
        GraphAdjMat[i][i] = 0;
	
	//creat the adjacenxy matrix of graph
	cout << "Creating a graph...\n";
	createGraph(GraphAdjMat, 0, 2, 10);
	createGraph(GraphAdjMat, 0, 4, 30);
	createGraph(GraphAdjMat, 0, 5, 100);
	createGraph(GraphAdjMat, 1, 2, 5);
	createGraph(GraphAdjMat, 2, 3, 50);
	createGraph(GraphAdjMat, 3, 5, 10);
	createGraph(GraphAdjMat, 4, 3, 20);
	createGraph(GraphAdjMat, 4, 5, 60);
    displaygraph(GraphAdjMat);
    //ShortestPath by Floya algorithm 
    cout << "Running the Shortest Path by Floyd...\n\n";
    int P[numVertex][numVertex];
    int D[numVertex][numVertex];
    ShortestPath_Folyd(GraphAdjMat,P,D);
    
    //Print Results
    cout << "The shortest path index is:\n";
    displaygraph(P);
    cout << "The shortest path weight is:\n";
    displaygraph(D);
    return 0;
}

//creat a graph's agjacency matirx
void createGraph(int GraphAdjMat[][numVertex], int x, int y, int weight){
	GraphAdjMat[x][y] = weight;
}

void displaygraph(int GraphAdjMat[][numVertex]){
	for (int i = 0; i < numVertex; ++i){
		for (int j = 0; j<numVertex; ++j)
			cout << left << setw(7) << GraphAdjMat[i][j];
		cout << "\n";
	}
	cout << "\n";
}

void ShortestPath_Folyd(int GraphAdjMat[][numVertex],int (*P)[numVertex],int (*D)[numVertex]){
	int i,j,k;
	//Init
	for(i = 0;i < numVertex;i++){
		for(j = 0;j < numVertex;j++){
			P[i][j] = j;
 			D[i][j] = GraphAdjMat[i][j];
		}
	}
	//main loop
	for(k = 0;k < numVertex;k++)
	    for(i = 0;i < numVertex;i++)
	        for(j = 0;j < numVertex;j++){
        		if(D[i][j] > D[i][k] + D[k][j]){
		        	D[i][j] = D[i][k] + D[k][j];
		        	P[i][j] = P[i][k];
		        }
        	}
}
