//Minimum Spanning Tree by Prim algorithm and the save data is adjacency matrix
//The Graph is undirected
//2015/12/9

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define NUMVERTEX 6 //define the numbers of vertex of the graph
#define INFINITY 65536

string VertexName[NUMVERTEX]={"V0","V1","V2","V3","V4","V5"};

void createGraph(int GraphAdjMat[][NUMVERTEX],int i,int j,int weight);
void displayGraph(int (*GraphAdjMat)[NUMVERTEX]);
void MinSpanTree_Prim(int GraphAdjMat[][NUMVERTEX]);

int main(){
	
	//init the adjacency matrix of graph
	int (*GraphAdjMat)[NUMVERTEX] = (int (*)[NUMVERTEX])malloc(sizeof(int)*NUMVERTEX*NUMVERTEX);
	for(int i = 0;i < NUMVERTEX;++i)
	    for(int j = 0;j < NUMVERTEX;++j)
	        GraphAdjMat[i][j] = INFINITY;
    for(int i = 0;i < NUMVERTEX;++i)
        GraphAdjMat[i][i] = 0;
    cout << "The initialization of the graph:\n";
    displayGraph(GraphAdjMat);
    
    //Create the adjacency matrix of graph
    cout << "Creating the graph...\n";
    createGraph(GraphAdjMat,0,1
	,6);
    createGraph(GraphAdjMat,0,2,1);
	createGraph(GraphAdjMat,0,3,5);
	createGraph(GraphAdjMat,1,2,5);
	createGraph(GraphAdjMat,1,4,3);
	createGraph(GraphAdjMat,2,3,5);
	createGraph(GraphAdjMat,2,4,6);
	createGraph(GraphAdjMat,2,5,4);
	createGraph(GraphAdjMat,3,5,2);
	createGraph(GraphAdjMat,4,5,6);
    cout << "After creat a graph: \n";
    displayGraph(GraphAdjMat);
    
    //Minimum spanning tree by prim algorithm
    cout << "The Minimum spanning tree is:\n";
    MinSpanTree_Prim(GraphAdjMat);
	
}


//creat the adjacency matrix of graph
void createGraph(int GraphAdjMat[][NUMVERTEX],int i,int j,int weight){
	GraphAdjMat[i][j] = weight;
	GraphAdjMat[j][i] = weight;
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

//Minimum spanning tree by Prim
void MinSpanTree_Prim(int GraphAdjMat[][NUMVERTEX]){
	int min,i,j,k;
	int lowcost[NUMVERTEX]; //correlation vertex's edge weight
	int adjvec[NUMVERTEX];  //correlation vertex's inferior
	
	//Initialization
	for(j = 0;j < NUMVERTEX;++j){
		lowcost[j] = GraphAdjMat[0][j];
		adjvec[j] = 0;
	}
	
	//Create spanning tree
	for(i = 1;i < NUMVERTEX;++i){
		//find the lowcost array minimum value
		min = INFINITY; //Init as 65535
		j = 1;
		k = 0;
		while(j < NUMVERTEX){
			if(lowcost[j] != 0 && lowcost[j] < min){
				min = lowcost[j];
				k = j;   //min value's inferior save to k
			}
			j++;
		}
		
		//print current vertex 
		cout <<"(" << VertexName[adjvec[k]] << "," << VertexName[k] << ")\n";
		//cout <<"(" << adjvec[k] << "," << k << ")";
		lowcost[k] = 0; // current vertex has end search
		
		for(j = 0;j < NUMVERTEX;++j){
			if(lowcost[j] != 0 && GraphAdjMat[k][j]<lowcost	[j]){
				lowcost[j] = GraphAdjMat[k][j];
				adjvec[j] = k;
			}
		}
	}
}

