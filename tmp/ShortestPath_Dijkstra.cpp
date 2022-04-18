//ShortestPath_Dijkstra algorithm by adjacency matrix of directed graphs
//2015/12/13

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define numVertex 6 //Graph's vertex numbers
#define INFINITY 65536

typedef int Patharc[numVertex]; //save the shortest path's inferior
typedef int ShortPathTable[numVertex]; //save the current shortest path weight of sum

string VertexName[numVertex]={"V0","V1","V2","V3","V4","V5"};
void createGraph(int GraphAdjMat[][numVertex], int x, int y,int weight);
void displaygraph(int GraphAdjMat[][numVertex]);
void ShortestPath_Dijkstra(int GraphAdjMat[][numVertex],int V0,int* P,int* D);
void displayResults(int index_V,int* P,int* D);
void PrintPath(int i,int index_V,int* P,int* D);

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
    int P[numVertex]; //save the shortest path's inferior
    int D[numVertex]; //save the current shortest path weight of sum
    cout << "Choose the beginning vertex(such as V0~V5):";
    string begin_V;
    cin >> begin_V;
    int index_V;
    int flag = 0; //whether find the beginning 
    for(int i = 0;i < numVertex;i++){
    	if(VertexName[i] == begin_V){
	    	index_V  = i;
	    	flag = 1;
	    }
    }
    if(flag == 0) {
    	cout << "Not find the beginning vertex!\n";
    	//return -1;
    }
	
    //ShortestPath by Dijkstra algorithm 
    cout << "Running the Shortest Path by Dijkstra...\n";
    ShortestPath_Dijkstra(GraphAdjMat,index_V,P,D);
	
	//Input Results
	cout << "Print the Results:\n";
	displayResults(index_V,P,D);
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

//ShortestPath Dijkstra algorithm
void ShortestPath_Dijkstra(int GraphAdjMat[][numVertex],int V0,int* P,int* D){
	int v,w,k,min;
	int final[numVertex]; //if final[Vw] = 1,then the V0 to Vw shortest path have been found
	//Init
	for(v = 0;v < numVertex;v++){
		final[v] = 0;
		D[v] = GraphAdjMat[V0][v];
		P[v] = V0;
	}
	
	D[V0] = 0;
	final[V0] = 1;
	
	//main loop
	for(v = 1;v < numVertex;v++){
		min = INFINITY;
		for(w = 0;w < numVertex;w++){
			if(!final[w]&&D[w] < min){
				k = w;
				min = D[w];
			}
		}		
		final[k] = 1;
		//adjust the shortest path to current vertex
		for(w = 0;w < numVertex;w++){
			if(!final[w]&&(min + GraphAdjMat[k][w] < D[w])){
				D[w] = min + GraphAdjMat[k][w];
				P[w] = k;
			}
		}
	} 
}

void displayResults(int index_V,int* P,int* D){
	for(int i = 0;i < numVertex;i++){
		if(i != index_V){
			cout << VertexName[i] <<" to " << VertexName[index_V] <<": ";
			cout << VertexName[index_V] <<"->";
			PrintPath(i,index_V,P,D );
			cout << VertexName[i] << "  ShortestPath weight is:";
			cout << D[i] << endl;;
		}
	}
}

void PrintPath(int i,int index_V,int* P,int* D){
	if(P[i] != index_V){
		PrintPath(P[i],index_V,P,D);
		cout << VertexName[P[i]] << "->";
	}
}
