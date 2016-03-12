//BreadthFirstSearch_BFS by adjacency link of directed graphs
//Input the vertex value is int type
//2015/12/7

#include <iostream>
#include <iomanip>
using namespace std;
#define numVertex 5 //Graph's vertex numbers
typedef int ElemType;

//define the graph adjacency link node
typedef struct GraphAdjLinkNode{
	int vertex;
	struct GraphAdjLinkNode* next;
}GraphEdge;

//define the queue
typedef struct QueueNode{
	int value;
	struct QueueNode* pre;
	struct QueueNode* next;
}QNode;

QNode* front; //the queue's front point
QNode* rear; //the queue's rear point

void createGraph(GraphEdge** GraphAdjLink,int x,int y);
void displayGraph(GraphEdge** GraphAdjLink);
void BFS_Travel(GraphEdge** GraphAdjLink,int* VertexStatusArray);
void BFS(GraphEdge** GraphAdjLink,int* VertexStatusArray,int i);
void putQueue(int vertex);
int* getQueue();

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
    
    //Breadth First Search the directed graph
	BFS_Travel(GraphAdjLink, VertexStatusArray);
    cout << endl;
	    
	    
	    
 
	return 0;
}



//creat a graph
void createGraph(GraphEdge** GraphAdjLink,int x,int y){
	GraphEdge* newEdge = (GraphEdge*)malloc(sizeof(GraphEdge));
	newEdge->vertex = y; //the current vertex's next vertex is y
	newEdge->next = NULL;
	GraphAdjLink = GraphAdjLink + x; //the current vertex's link
	while(*GraphAdjLink != NULL)
        GraphAdjLink = &((*GraphAdjLink)->next);
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

//depth first search s
void BFS_Travel(GraphEdge** GraphAdjLink,int* VertexStatusArray){
	cout << "start breadth first serach...\n";
	for (int i = 0; i < numVertex; ++i){
			BFS(GraphAdjLink, VertexStatusArray, i);
	}
	
}

void BFS(GraphEdge** GraphAdjLink,int* VertexStatusArray,int i){
	putQueue(i);
	int *quValue = NULL;
	while((quValue=getQueue())!= NULL){
		if(VertexStatusArray[*quValue] == 0){
			cout << *quValue << " ";
			VertexStatusArray[*quValue] = 1;
			
			GraphEdge* p = *(GraphAdjLink + *quValue);
			while(p!=NULL){
				putQueue(p->vertex);
				p = p->next;
			}
		}
	}
}

//insert queue
void putQueue(int vertex){
	QNode* temp = (QNode *)malloc(sizeof(QNode));
	temp->value = vertex;
	temp->pre = NULL;
	temp->next = NULL;
	if(front == NULL || rear == NULL){
		front = rear = temp;
	}
	else{
		rear->next = temp;
		temp->pre = rear;
		rear = temp;
	}
}

//get the value from the queue
int* getQueue(){
	if(front == NULL || rear == NULL){
		return NULL;
	}
	else{
		int* res = (int*)malloc(sizeof(int));
		*res = front->value; //get the front value
		
		QNode* p = front;
		front = front->next;
		if(front == NULL){
			rear = front;
		}
		else{
			front->pre = NULL;
		}
		free(p);
		p = NULL;
		return res; 
	}
}
