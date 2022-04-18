//BreadthFirstSearch_BFS by adjacency matrix of directed graphs
//Input the vertex value is int type
//2015/12/7

#include <iostream>
#include <iomanip>
using namespace std;
#define numVertex 5 //Graph's vertex numbers
typedef int ElemType;


typedef struct QueueNode{
	ElemType value;
	struct QueueNode* pre;
	struct QueueNode* next;
}QNode;

QNode* front;  //the queue's front point
QNode* rear;  //the queue's rear point

void createGraph(int GraphAdjMat[][numVertex], int x, int y);
void displaygraph(int GraphAdjMat[][numVertex]);
void BFS_Travel(int GraphAdjMat[][numVertex],int* VertexStatusArray);
void BFS(int GraphAdjMat[][numVertex],int* VertexStatusArray,int i);
void putQueue(int Vertex);
int* getQueue();
void putRelatedQueue(int GraphAdjMat[][numVertex],int vertex);


int main(){
	cout << "#Bread First Search#\n";
	cout << "Adjacency matrix save graph's edge\n";
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
	
	BFS_Travel(GraphAdjMat,VertexStatusArray);
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

//Breadth First search
void BFS_Travel(int GraphAdjMat[][numVertex],int* VertexStatusArray){
	cout << "start breadth first serach...\n";
	for (int i = 0; i < numVertex; ++i){
			BFS(GraphAdjMat, VertexStatusArray,i);
	}
}

void BFS(int GraphAdjMat[][numVertex],int* VertexStatusArray,int i){
	putQueue(i);//put the i-th to queue
	int* quValue = NULL;
	while((quValue = getQueue())!=NULL){
		if(VertexStatusArray[*quValue] == 0){
			cout << *quValue <<" ";
			VertexStatusArray[*quValue] = 1;
			
			//current vertex related vertex join in queue
			for(int j=0;j < numVertex; ++j){
		        if(GraphAdjMat[*quValue][j] == 1){
			         putQueue(j);
		        }
            }
			//putRelatedQueue(GraphAdjMat,*quValue);
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

void putRelatedQueue(int GraphAdjMat[][numVertex],int vertex){
	for(int i=0;i < numVertex; ++i){
		if(GraphAdjMat[vertex][i] == 1){
			putQueue(i);
		}
	}
	
}

