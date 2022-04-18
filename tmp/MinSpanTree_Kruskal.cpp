//Minimum Spanning Tree by Kruskal algorithm and the save data is adjacency matrix
//The Graph is undirected
//2015/12/10

#include <iostream>
#include <iomanip>
using namespace std;
#define NUMVERTEX 6 //define the numbers of vertex of the graph
#define INFINITY 65536

//define the edges set struct array
typedef struct{
	int start;   //edge's start 
	int end;     //edge's end
	int weight;  //edge's weight
}Edge;

string VertexName[NUMVERTEX]={"V0","V1","V2","V3","V4","V5"};
void createGraph(int GraphAdjMat[][NUMVERTEX],int i,int j,int weight,int* numEdges);
void displayGraph(int (*GraphAdjMat)[NUMVERTEX]);
void displayEdgesSetArray(Edge EdgesArray[],int numEdges);
Edge SortEdgeSetArray(Edge EdgesArray[],int numEdges);
int Find(int* parent,int f);
void MinSpanTree_Kruskal(Edge EdgesArray[],int numEdges);

int main(){
	
	//init the adjacency matrix of graph
	int (*GraphAdjMat)[NUMVERTEX] = (int (*)[NUMVERTEX])malloc(sizeof(int)*NUMVERTEX*NUMVERTEX);
	for(int i = 0;i < NUMVERTEX;++i)
	    for(int j = 0;j < NUMVERTEX;++j)
	        GraphAdjMat[i][j] = INFINITY;
    for(int i = 0;i < NUMVERTEX;++i)
        GraphAdjMat[i][i] = 0;
//    cout << "The initialization of the graph:\n";
//    displayGraph(GraphAdjMat);
    
    //Create the adjacency matrix of graph
    int numEdges = 0;
    cout << "Creating the graph...\n";
    createGraph(GraphAdjMat,0,1,6,&numEdges);
    createGraph(GraphAdjMat,0,2,1,&numEdges);
	createGraph(GraphAdjMat,0,3,5,&numEdges);
	createGraph(GraphAdjMat,1,2,5,&numEdges);
	createGraph(GraphAdjMat,1,4,3,&numEdges);
	createGraph(GraphAdjMat,2,3,5,&numEdges);
	createGraph(GraphAdjMat,2,4,6,&numEdges);
	createGraph(GraphAdjMat,2,5,4,&numEdges);
	createGraph(GraphAdjMat,3,5,2,&numEdges);
	createGraph(GraphAdjMat,4,5,6,&numEdges);
    cout << "After creat a graph: \n";
    displayGraph(GraphAdjMat);
    
    //Create edges set array
    Edge EdgesArray[numEdges];
    int k = 0;
    while(k < numEdges){
    	for(int i = 0;i < NUMVERTEX;++i)
            for(int j = i;j < NUMVERTEX	;++j){
        	    if(GraphAdjMat[i][j]!=0 && GraphAdjMat[i][j] < INFINITY){
        	    	EdgesArray[k].start = i;
    	        	EdgesArray[k].end = j;
    	        	EdgesArray[k].weight = GraphAdjMat[i][j];
    	        	k++;
    	        }		
        }
    }
    
    //display edges set
//    cout << "The edges set is: \n";
//    displayEdgesSetArray(EdgesArray,numEdges);
//    cout << "\n";
    
    //sort the edges set
    cout << "After sort the edges array is: \n";
    SortEdgeSetArray(EdgesArray,numEdges);
    displayEdgesSetArray(EdgesArray,numEdges);
    cout << "\n";
    
    
    //Minimum spanning tree by Kruskal algorithm
    cout << "The Minimum Spanning Tree is:\n";
    MinSpanTree_Kruskal(EdgesArray,numEdges);
	
}


//creat the adjacency matrix of graph
void createGraph(int GraphAdjMat[][NUMVERTEX],int i,int j,int weight,int* numEdges){
	GraphAdjMat[i][j] = weight;
	GraphAdjMat[j][i] = weight;
	(*numEdges)++;
}

//display the graph
void displayGraph(int (*GraphAdjMat)[NUMVERTEX]){
	for(int i = 0;i < NUMVERTEX;++i){
		for(int j = 0;j < NUMVERTEX;++j)
		    cout << left << setw(7) << GraphAdjMat[i][j];
        cout << "\n";
	}
	cout << "\n";
}

//display the edges set array
void displayEdgesSetArray(Edge EdgesArray[],int numEdges){
	for(int k = 0;k < numEdges; ++k){
		cout << EdgesArray[k].start << "->" << EdgesArray[k].end << " ";
	    cout << EdgesArray[k].weight;
	    cout << endl;
	}
}

//Sort the edges set array according weight
Edge SortEdgeSetArray(Edge EdgesArray[],int numEdges){
	 //sort the edges set
    Edge temp;
    for(int i = 0;i < numEdges;++i)
        for(int j =0;j < numEdges-1-i;++j){
        	if(EdgesArray[j].weight > EdgesArray[j+1].weight){
	        	temp = EdgesArray[j];
	        	EdgesArray[j] = EdgesArray[j+1];
	        	EdgesArray[j+1] = temp;
	        }
        }
}

int Find(int* parent,int f){
	while(parent[f] > 0){
		f = parent[f];
	}
	return f;
}

void MinSpanTree_Kruskal(Edge EdgesArray[],int numEdges){
	int n,m;
	int parent[NUMVERTEX];
	for(int i = 0;i < NUMVERTEX;++i)
	    parent[i] = 0;
    for(int i = 0;i < numEdges;++i){
    	n = Find(parent,EdgesArray[i].start);
    	m = Find(parent,EdgesArray[i].end);
    	
    	if(n!=m){
	    	parent[n] = m;
	    	cout << VertexName[EdgesArray[i].start] << "->" ;
	    	cout << VertexName[EdgesArray[i].end] <<"\n";
	    }
    }
}



