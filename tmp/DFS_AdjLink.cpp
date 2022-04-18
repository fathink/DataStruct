//DepthFirstSearch_DFS by adjacency links of directed graphs
//2015/12/7

#include <iostream>
#include <iomanip>
using namespace std;
#define numVertex 5  //Graph's vertex numbers

//define the graph adjacency link node
typedef struct GraphAdjLinkNode{
	int vertex;
	struct GraphAdjLinkNode* next;
}GraphEdge;


//creat graph
void createGraph(GraphEdge** GraphAdjLink,int x,int y){
	GraphEdge* newEdge = (GraphEdge*)malloc(sizeof(GraphEdge));
	newEdge->vertex = y;
	newEdge->next = NULL;
	GraphAdjLink = GraphAdjLink + x;
	while(*GraphAdjLink != NULL){
		GraphAdjLink = &((*GraphAdjLink)->next);
	}
	*GraphAdjLink = newEdge;
}
 
//dispaly the adjacency link
void displayGraph(GraphEdge** GraphAdjLink){
	GraphEdge* p; //a temp point
	for (int i= 0;i < numVertex;++i){
		cout << i << ":";
		p = *(GraphAdjLink+i);
		while(p != NULL){
			cout << p->vertex << " ";
			p = p->next;
		}
		cout << "\n";
	}	
	return;
}

void DFS(GraphEdge** GraphAdjLink,int* VertexStatusArray,int i){
	if(VertexStatusArray[i]==1) return;
	VertexStatusArray[i] = 1; //the i-th vertex changed to 1,mean is visted
	cout << i << " "; 
	GraphEdge* p = *(GraphAdjLink+i);
	GraphEdge* temp;
	while(p != NULL){
		DFS(GraphAdjLink,VertexStatusArray,p->vertex);
		p = p->next;
	}
}

//depth first search s
void DFS_Travel(GraphEdge** GraphAdjLink,int* VertexStatusArray){
	cout << "start depth first serach...\n";
	for (int i = 0; i < numVertex; ++i){
		if (!VertexStatusArray[i])
			DFS(GraphAdjLink, VertexStatusArray, i);
	}
	
}



int main(){
	
	//init the adjacency link of graph
	GraphEdge** GraphAdjLink =  (GraphEdge**)malloc(sizeof(GraphEdge)*numVertex);
	for(int i = 0;i < numVertex;++i)
	    GraphAdjLink[i] = NULL;
    
    //init the vertex status array
    int VertexStatusArray[numVertex];
    for(int i = 0;i < numVertex; ++i)
        VertexStatusArray[i] = 0;
    
    //creat the adjacenxy Link of graph
	cout << "After initialization of the adjacency matrix of graph: \n";
	displayGraph(GraphAdjLink);
	cout << "Creating a graph...\n";
	createGraph(GraphAdjLink, 0, 3);
	createGraph(GraphAdjLink, 0, 4);
	createGraph(GraphAdjLink, 3, 1);
	createGraph(GraphAdjLink, 3, 2);
	createGraph(GraphAdjLink, 4, 1);
	cout << "After creat a graph: \n";
	displayGraph(GraphAdjLink);
    
    //Depth First Search the directed graph
	DFS_Travel(GraphAdjLink, VertexStatusArray);
    cout << endl;
	    
	    
	    
 
	return 0;
}
