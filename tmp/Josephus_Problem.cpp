//Լɪ������ı��ʵ��

#include <iostream>
#include <iomanip>
using namespace std;
typedef int ElemType;

//����ѭ����ṹ
typedef struct CirLinkList{
	ElemType data;
	struct CirLinkList* next;
}node;

//��ʼ��ѭ������
void CirLinkListInit(node** pNode,int count){
	ElemType item;
	//int count;
	node* temp;
	node* target;
	while (1){
		//cin >> count;
		for (int i = 1; i <= count; i++){
			item = i;
			//fflush(stdin); //���������
			if ((*pNode) == NULL){  //ѭ��������ֻ��һ�����
				*pNode = (node*)malloc(sizeof(struct CirLinkList));
				if (!(*pNode)) exit(0);
				(*pNode)->data = item;
				(*pNode)->next = *pNode; //��λ����
			}
			else{
				for (target = *pNode; target->next != *pNode; target = target->next)
					;//targetָ�����һ�����
				temp = (node*)malloc(sizeof(struct CirLinkList)); //�����½��
				if (!temp) exit(0);
				temp->data = item;
				temp->next = *pNode; //ָ��ͷ���
				target->next = temp;//������һ�����
			}
		}
		if (item == count) {
			cout << "��ʼ��������" << endl;
			return;//����0������ʼ��
		}
	}
	return;
}

//ѭ�������i��λ��ɾ������
void CirLinkListDelete(node** pNode, int i){
	node* temp;
	node* target; //��ʼ��ָ�����һ������ָ��
	if (i == 1){
		for (target = *pNode; target->next != *pNode; target = target->next)
			;//targetָ�����һ������ָ��
		temp = *pNode;
		*pNode = (*pNode)->next; //ɾ����һ�����
		target->next = *pNode;  //β���ָ���һ�����
		free(temp);
	}
	else{
		target = *pNode;
		for (int j = 1; j < i - 1; ++j){
			target = target->next;    //ָ���i-1�����
		}
		temp = target->next;
		target->next = temp->next; //ɾ��i���
		free(temp);
	}
}

//��ӡѭ������
int CirLinkListPrint(node* L){
	node* temp;
	int count = 0;
	for (temp = L; temp->next != L; temp = temp->next){
		cout << left <<setw(2) <<temp->data << " ";
		count++;
		if (count%10==0) cout << endl;
	}
	cout << left <<setw(2) << temp->data << endl; //������һ��Ԫ��
	
	return 0;
}


int main(){
	node* L = 0;
	int num = 3; //���3
	int count;   //������
	//��ʼ��ѭ������
	cout << "������������";
	//cin >> count;
	count = 12;
	CirLinkListInit(&L,count);
	cout << "�������\n";
	CirLinkListPrint(L);

	cout << "���������£�" << endl;
	node* temp = L;
	while (1){
		cout << "ѡ���" <<right<<setw(2)<< temp->next->next->data << "����" << endl;
		CirLinkListDelete(&temp, num);
		--count;
		if (count == 2) break;
		temp = temp->next->next;
	}

	cout << "ʣ������" << temp->data << " " << temp->next->data << endl;



	return 0;

}