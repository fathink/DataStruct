//Binary Sort Tree operation,such as SerachSort_Delete_Insert
//Serach Sort_Delete_Insert
//2015/12/16

#include <iostream>
#include <iomanip>
#define ERROR 0
#define OK 1
using namespace std;

typedef int ElemType;
typedef int Status;
typedef struct BinTreeNode{
	ElemType data;
	struct BinTreeNode *lchild, *rchild;

}BinTreeNode, *BinSortTree;

void createBinSortTree(BinSortTree* T, ElemType e, ElemType* a);
Status Search_BST(BinSortTree T, ElemType key, BinSortTree f, BinSortTree* p);
void Sort_BST(BinSortTree T, int level);
Status Insert_BST(BinSortTree* T, int key);
Status Delete_BST(BinSortTree* T, int key);


int main(){
	ElemType a[9] = { 70, 105, 115, 104, 67, 46, 99, 111, 109 };
    
    cout << "        The Binary Sort Operation\n";
    cout << "+++++++Search, Sort, Insert, Delete+++++++\n";
    
	//create the binary sort tree
	cout << "Input the binary tree numbers:\n";
	BinSortTree T = NULL;
	//	for (int i = 0; i < 9; i++)
	//		createBinSortTree(&T, a[i], a);
	//	
	ElemType e;
	while (char c = cin.get() != '\n'){
		cin.unget();
		cin >> e; //70 105 115 104 67 46 99 111 109 
		Insert_BST(&T, e);
	}
    cout << endl;
    
	//Sort the Binary sort tree
	cout << "after sort the binary tree:\n";
	Sort_BST(T, 1);
	cout << "\n\n";

	//Search the binary sort tree
	ElemType key;
	cout << "Input the search element:";
	cin >> key;
	//ElemType key = 70;
	BinSortTree p = NULL;
	if(Search_BST(T, key, NULL, &p)){
		cout << "Search succeed!";
	} 
	else cout << "Search failed!";
	cout << "\n\n";
    
	//Delete the binary sort tree
	cout << "Input the delete element:";
	cin >> key;
	if(Delete_BST(&T, key)){
		cout << "after delete the binary tree sort is:\n";
		Sort_BST(T, 1);
	}
	cout << "\n\n";
	
	return 0;

}

//Init the binary tree
void createBinSortTree(BinSortTree* T, ElemType e, ElemType* a){
	if (*T == NULL){
		*T = (BinTreeNode*)malloc(sizeof(BinSortTree));
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		return;
	}
	if ((*T)->data < e){
		createBinSortTree(&(*T)->rchild, e, a);
		return;
	}
	else if ((*T)->data > e){
		createBinSortTree(&(*T)->lchild, e, a);
		return;
	}
	else if ((*T)->data = e){
		cout << "Exist equal number,ERROE!\n";
		return;
	}
}

//Middle order traverse the binary sort tree
void Sort_BST(BinSortTree T, int level){
	if (T){
		Sort_BST(T->lchild, level + 1); //left child
		//cout << T->data << " level is " << level << endl;
		cout << T->data << " ";
		Sort_BST(T->rchild, level + 1); //ср╫з╣Ц
	}
}

//Search Binary Sort Tree
Status Search_BST(BinSortTree T, ElemType key, BinSortTree f, BinSortTree* p){
	if (!T){
		*p = f;
		return ERROR; //search false
	}
	else if (key == T->data){
		*p = T;
		return OK; //search succeed
	}
	else if (key < T->data){
		return Search_BST(T->lchild, key, T, p);
	}
	else{
		return Search_BST(T->rchild, key, T, p);
	}
}

//Insert Binary sort tree
Status Insert_BST(BinSortTree* T, int key){
	BinSortTree p, s;
	if (!Search_BST(*T, key, NULL, &p)){
		s = (BinSortTree)malloc(sizeof(BinTreeNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p){
			*T = s;
		}
		else if (key<p->data){
			p->lchild = s;   //insert the left child
		}
		else{
			p->rchild = s;
		}
		return OK;
	}
	else{
		return ERROR; //the tree have same number
	}
}
//Delete Binary sort tree
Status Delete(BinSortTree* p);
Status Delete_BST(BinSortTree* T, int key){
	if (!*T){
		cout << "Delete Failed!\n";
		return ERROR;
	}
	else{
		if (key == (*T)->data){
			return Delete(T);
		}
		else if (key < (*T)->data){
			return Delete_BST(&(*T)->lchild, key);
		}
		else{
			return Delete_BST(&(*T)->rchild, key);
		}
	}
}

//delete current node,p is point the node 
Status Delete(BinSortTree* p){
	BinSortTree q, s;
	if ((*p)->rchild == NULL){
		q = *p;
		(*p) = (*p)->lchild;
		delete q;
	}
	else if ((*p)->lchild == NULL){
		q = *p;
		(*p) = (*p)->rchild;
		delete q;
	}
	else{
		q = *p;
		s = (*p)->lchild;
		while (s->rchild){ //search the delete node's prior data
			q = s;
			s = s->rchild;
		}

		(*p)->data = s->data;

		if (q != *p){
			q->rchild = s->lchild;
		}
		else{
			q->lchild = s->lchild;
		}
	}
	return OK;
}
