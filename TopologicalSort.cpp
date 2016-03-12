//this function is the Topological Sort algorithm
//2015/12/14

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define numVertex 12  //Graph's vertex numbers
#define ERROE -1
#define OK 1

//define the edges table struct
typedef struct EdgeNode{
	int adjvex;
	struct EdgeNode* next;
}EdgeNode;

//define the vertex table struct
typedef struct VertexNode{
	int indegree;
	string data;
	EdgeNode* firstedge;
}VertexNode;

void createGraph(VertexNode** GraphAdjLink, int x, int y, int indegree, string data);
void displayLink(VertexNode** GraphAdjLink);
int TopologicalSort(VertexNode** GraphAdjLink);


int main(){
	//init the adjacency link of graphs
	VertexNode** GraphAdjLink = (VertexNode**)malloc(sizeof(VertexNode)*numVertex);
	for (int i = 0; i < numVertex; ++i)
		GraphAdjLink[i] = NULL;

	cout << "Creating a graph...\n";
	createGraph(GraphAdjLink, 0, 1, 0, "C1");
	createGraph(GraphAdjLink, 0, 2, 0, "C1");
	createGraph(GraphAdjLink, 0, 3, 0, "C1");
	createGraph(GraphAdjLink, 0, 11, 0, "C1");
	createGraph(GraphAdjLink, 1, 1, 1, "C2");
	createGraph(GraphAdjLink, 2, 4, 1, "C3");
	createGraph(GraphAdjLink, 2, 6, 1, "C3");
	createGraph(GraphAdjLink, 2, 7, 1, "C3");
	createGraph(GraphAdjLink, 3, 4, 1, "C4");
	createGraph(GraphAdjLink, 4, 6, 2, "C5");
	createGraph(GraphAdjLink, 5, 7, 1, "C6");
	createGraph(GraphAdjLink, 6, 6, 2, "C7");
	createGraph(GraphAdjLink, 7, 7, 2, "C8");
	createGraph(GraphAdjLink, 8, 9, 0, "C9");
	createGraph(GraphAdjLink, 8, 10, 0, "C9");
	createGraph(GraphAdjLink, 8, 11, 0, "C9");
	createGraph(GraphAdjLink, 9, 11, 1, "C10");
	createGraph(GraphAdjLink, 10, 5, 1, "C11");
	createGraph(GraphAdjLink, 11, 11, 3, "C12");
    
    cout <<"Print edges table\n";
    displayLink(GraphAdjLink);
    
    //Topological sort  
    cout << "The Topological sort is:\n";
    TopologicalSort(GraphAdjLink);
    
	return 0;
}

void createGraph(VertexNode** GraphAdjLink, int x, int y, int indegree, string data){
	GraphAdjLink = GraphAdjLink + x;
	if (!(*GraphAdjLink)){
		//VertexNode* newNode = (VertexNode*)malloc(sizeof(VertexNode));
		VertexNode* newNode;
		newNode = new VertexNode;
		newNode->indegree = indegree;
		newNode->data = data;
		newNode->firstedge = NULL; 
		*GraphAdjLink = newNode;
	}
	//OutDegree is not zero
	if (x != y){
		EdgeNode* tempEdgeNode;
		EdgeNode* p ;
		tempEdgeNode = (*GraphAdjLink)->firstedge;
		//tempEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
		if (!tempEdgeNode){
			EdgeNode* newEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
			newEdgeNode->adjvex = y;
			newEdgeNode->next = NULL;
			(*GraphAdjLink)->firstedge = newEdgeNode;
		}
		else{
			p = tempEdgeNode;
			while (p->next != NULL)
				p = p->next;   //p point to the link end
			EdgeNode* newEdgeNode = (EdgeNode*)malloc(sizeof(EdgeNode));
			newEdgeNode->adjvex = y;
			newEdgeNode->next = NULL;
			p->next = newEdgeNode;
			(*GraphAdjLink)->firstedge = tempEdgeNode;
		}
	}
}

void displayLink(VertexNode** GraphAdjLink){
	VertexNode* p; //a temp point
	for (int i= 0;i < numVertex;++i){
		p = *(GraphAdjLink+i);
		cout<< left << setw(2) << i << " " << p->indegree << " ";
		cout<< left << setw(3) << p->data << " ";
		if(p->firstedge){
			EdgeNode* e = p->firstedge; 
			while(e != NULL){
				//cout << "->" << e->adjvex;
				cout << "->" << (*(GraphAdjLink+e->adjvex))->data;
				e= e->next;
			}
		}
		cout << "\n";
	}	
	return;
}

int TopologicalSort(VertexNode** GraphAdjLink){
	EdgeNode* e;
	int i,k,gettop;
	int top = 0; //stack point
	int count = 0; //save the vertex numbers
	int *stack;
	stack = (int *)malloc(sizeof(int)*numVertex);
	
	for(i = 0;i < numVertex;++i){
		if(GraphAdjLink[i]->indegree == 0){
			stack[++top] = i;    //push stack
		}
	}
	
	while(top != 0){
		gettop = stack[top--]; //pop stack
		
	    //cout << gettop << " ";
	    cout << (*(GraphAdjLink+gettop))->data << " ";
	    count++;
	    for(e = GraphAdjLink[gettop	]->firstedge; e ; e = e->next){
    		k = e->adjvex;
    		if(!(--GraphAdjLink[k]->indegree)){
		    	stack[++top] = k;
		    }
    	}
	}
	cout << endl;
	if(count < numVertex){
		cout << "Exist cycle!";
		return ERROE;
	}
	
	return OK;
}

