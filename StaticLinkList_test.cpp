#include <iostream>
using namespace std;
typedef char ElemType;
#define MAXSIZE 100
#define OK  1
#define ERROR -1
typedef struct SNode{
	ElemType data;   //����
	int cur;        //�α�
}SNode;
typedef struct SNode StaticLinkList[MAXSIZE];


//��̬�����ʼ��
bool InitStaticLinkList(StaticLinkList &L){
	int i;
	for (i = 0; i < MAXSIZE - 1; i++)
		L[i].cur = i + 1;
	L[MAXSIZE-1].cur = 0; //���һ��ָ����ָ��
	return OK;
}

//��ӡ��̬����
bool StaticLinkListPrint(StaticLinkList &L){
	int i = L[MAXSIZE - 1].cur;
	while (i != 0){
		cout << L[i].data << " ";
		i = L[i].cur;
	}
	cout << endl;
	return OK;

}
//����SLL��Ԫ�صĸ���
int length_SLL(StaticLinkList L){
	int j = 0;
	int i = L[MAXSIZE - 1].cur;//��һ��Ԫ���±�
	while (i){
		i = L[i].cur;
		++j;
	}
	return j;
}
//�������һ�����н��
int malloc_SLL(StaticLinkList L){
	int i = L[0].cur;//ȡͷ���֮���һ�����н��������
	if (L[0].cur)
		L[0].cur = L[i].cur;//���µ�һ�������αָ꣬���һ��δ������ݵ��±�
	return i; //���ص�һ��δ���Ԫ�ص��±�
}

//�ͷ�һ�����н��,�����±�Ϊi
void free_SLL(StaticLinkList L,int i){
	L[i].cur = L[0].cur;//�����յĽ�����ͷ���֮��
	L[0].cur = i;

}

//��̬����L����Ԫ��,i������
bool StaticLinkListInsert(StaticLinkList &L,int i,ElemType e){
	int j, k, l;
	k = MAXSIZE - 1;//�������һ��Ԫ���±�
	if (i<1 || i>length_SLL(L) + 1){
		cout << "������󣬵�ǰ������Ϊ" << length_SLL(L)
			<< ",���뷶ΧΪ1 ~ " << length_SLL(L) + 1 <<endl;
		return -1; }
	j = malloc_SLL(L); //��ȡδ���Ԫ�ص��±����
	if (j){
		L[j].data = e;
		for (l = 1; l <= i - 1; l++){  //���������ҵ��α�Ϊ0���±�
			k = L[k].cur;
		}
		L[j].cur = L[k].cur; //�������һ��Ԫ�ص��α꣬���һ��Ԫ�ص��α����Ϊ0
		L[k].cur = j;        //���µ�һ���α��ֵ��ָ���һ��δ���ֵ���±�
		return OK;
	}
	return ERROR;
}

//��̬����ɾ��iԪ��
bool StaticLinkListDelete(StaticLinkList &L, int i){
	int j, k;
	if (i < 1 || i>length_SLL(L)){ 
		cout << "������󣬵�ǰ������Ϊ " << length_SLL(L)
			<< ",���뷶ΧΪ1 ~ " << length_SLL(L) << endl;
		return ERROR; }
	k = MAXSIZE - 1; //�������һ��Ԫ���±�
	for (j = 1; j <= i - 1; j++)
		k = L[k].cur; //���������ҵ���ɾ�����ǰһ�������±�
	j = L[k].cur;     //��ɾ�������±�
	L[k].cur = L[j].cur; //ɾ�����
	free_SLL(L, j);
	return OK;
}


int main(){
	StaticLinkList L;

	//��ʼ����̬����
	InitStaticLinkList(L);
	
	//����Ԫ��
	StaticLinkListInsert(L, 1, 'a');
	StaticLinkListInsert(L, 2, 'c');
	StaticLinkListInsert(L, 3, 'd');
	StaticLinkListInsert(L, 2, 'b');
	StaticLinkListInsert(L, 5, 'f');

	//��ӡ��̬����
	cout << "�������" ;
	StaticLinkListPrint(L);

	//��������
	int i; ElemType data;
	cout << "���������λ�úͲ���Ԫ�أ�";
	cin >> i >> data;
	StaticLinkListInsert(L, i, data);
	cout << "�������Ԫ�غ������";
	StaticLinkListPrint(L);

	//ɾ����̬������i��Ԫ�أ�
	cout << "������ɾ��Ԫ���±꣺";
	cin >> i ;
	StaticLinkListDelete(L, i);
	cout << "���ɾ��Ԫ�غ������";
	StaticLinkListPrint(L);
	   
	//cout << length_SLL(L);

	return 0;
}