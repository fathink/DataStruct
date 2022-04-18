//�������˫������ʵ�����¹���
//����һ��������ʹ��26����ĸ���������仯��������3
//���: DEFGHIJKLMNOPQRSTUVWXYZABC,������-3
//���: XYZABCDEFGHIJKLMNOPQRSTUVW

#include <iostream>
#define OK 1
#define ERROR 0
using namespace std;
typedef int ElemType;
typedef int Status; //�������ָʾ

//˫���������ݽṹ
typedef struct DualNode{
	ElemType data;
	struct DualNode* prior;//ǰ�����
	struct DualNode* next; //��̽��
}DualNode,*DualLinkList; //��������

Status InitDualLinkList(DualLinkList *L){
	DualNode *p, *q; //����p��q����ָ�뽻�渳ֵ
	*L = (DualLinkList)malloc(sizeof(DualNode));
	if (!(*L)){
		return ERROR; //������ռ�ʧ��
	}
	(*L)->next = (*L)->prior = NULL; //��ʼ��ͷ���
	p = (*L); // ��ʼ��p

	for (int i = 0; i < 26; i++){
		q = (DualNode*)malloc(sizeof(DualNode));
		if (!q){
			return ERROR;
		}
		q->data = 'A' + i;
		q->prior = p; //q��ǰ�����
		q->next = p->next;//q->next = NULL���벻���
		p->next = q;
		p = q;//p��q�ı�λ��
	}
	p->next = (*L)->next; //����һ��ѭ��
	(*L)->next->prior = p;

	return OK;
}

void AlphabetSort(DualLinkList* L, int i){
	if (i > 0){
		do{
			(*L) = (*L)->next;
		} while (--i);
	}
	if (i < 0){
		do{
			(*L) = (*L)->next;
		} while (++i);
	}
}
int main(){
	DualNode* L;
	int n;
	//��ʼ��˫������
	InitDualLinkList(&L); 

	cout << "������һ��������";
	cin >> n;
	AlphabetSort(&L, n);
	for (int i = 0; i < 26; i++){
		L = L->next;
		cout << char(L->data);
	}
	cout << endl;
	return 0;

}
