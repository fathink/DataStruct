//ѭ���������ز���
//fazuo 2015/10/24
#include <iostream>
using namespace std;
typedef int ElemType;

//����ѭ������ṹ��
typedef struct CirLinkList{
	ElemType data; //������
	struct CirLinkList* next; //ָ����
}node; //node��CirLinkList�ı���

//��ʼ��ѭ������
void CirLinkListInit(node** pNode){
	ElemType item, count = 1;
	node* temp; 
	node* target;
	while (1){
		cout << "�����" << count << "����ֵ������0������ʼ����";
		cin >> item;
		
		//for (int i = 8; i >= 0; i--){
		//	item = i;

			fflush(stdin); //���������
			if (item == 0) {
				cout << "��ʼ��������" << endl;
				return;//����0������ʼ��
			}
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


		//}

		++count; //�������1
	}
	return;
}

//ѭ�������i��λ�ò���Ԫ��
//item�Ǵ�����Ԫ�أ�i�ǲ����λ��
void CirLinkListInsert(node** pNode, ElemType item, int i){
	node *temp;
	node *target;
	if (i ==1){//��һ��λ�ò���Ԫ��
		temp = (node*)malloc(sizeof(struct CirLinkList));//����ʱ�ڵ����ռ�
		if (!temp) exit(0);  //����ʧ�ܣ��˳�����
		temp->data = item;
		for (target = *pNode; target->next != *pNode; target = target->next)
			;//targetΪָ�����һ������ָ��
		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;//*pNodeָ��ͷ���
	}
	else{
		target = *pNode;
		for (int j = 1; j < i - 1; ++j){
			target = target->next;   //ָ���i-1�����
		}
		temp = (node*)malloc(sizeof(struct CirLinkList));
		if (!temp) exit(0); //����ʧ�ܣ��˳�����
		temp->data = item;
		node* p = target->next; 
		target->next = temp;
		temp->next = p; 
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

//���Ҳ���������Ԫ�أ����ظ�Ԫ�����ڵ�λ��
int CirLinkListSearch(node* pNode, ElemType e){
	int i = 1;
	node* target;
	for (target = pNode; target->data != e || target->next == pNode; ++i){
		target = target->next;
	}
	if (target->next == pNode) {
		cout << "���в����ڸ�Ԫ�أ�" << endl;
		return 0;
	}
	else return i;
}

//��ӡѭ������
int CirLinkListPrint(node* L){
	node* temp;
	for (temp = L; temp->next != L; temp = temp->next)
		cout << temp->data << " ";
	cout << temp->data << endl; //������һ��Ԫ��
	return 0;
}


int main(){
	int idx; //����������
	ElemType e; int i,pos; 
	node* L = NULL; //��ѭ�������ʼ��Ϊnull
	cout << "============================================" << endl;
	cout << "1.�����ʼ����2.�������Ԫ�أ�3.����ɾ��Ԫ��" << endl;
	cout << "4.������Ҳ�����0.��������" << endl;
	cout << "============================================" << endl;
	cout << "���������������ţ�";
	while (1){
		//cin.unget();
		cin >> idx;
		switch (idx){
		case 1:
			CirLinkListInit(&L);
			cout << "�����ʼ����ѭ������" << endl;
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 2:
			cout << "�������������ֵ��λ�ã�";
			cin >> e >> i;
			CirLinkListInsert(&L, e, i);
			cout << "���������\n";
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 3:
			cout << "�����ɾ������λ�ã�";
			cin >> i;
			CirLinkListDelete(&L,i);
			cout << "���������\n";
			CirLinkListPrint(L);
			cout << endl;
			break;
		case 4:
			cout << "���������Ԫ�ص�ֵ��";
            cin >> e;
		    pos = CirLinkListSearch(L, e);
		    cout << "Ԫ��ֵΪ" << e << "������Ϊ" << pos << "\n";
		    cout << endl;
		    break;
		default:
			break;
		}
		
		if (idx == 0){
			cout << "����������\n"<<endl;
			break;
		}
		else{
			cout << "���������������ţ�";
		}
		
	}

	////��ʼ��ѭ������
	//CirLinkListInit(&L);
	//
	////���ѭ������S
	//cout << "���ѭ������\n";
	//CirLinkListPrint(L);

	////��i��λ�ò�����
	//CirLinkListInsert(&L, 5, 1);
	//cout << "���ѭ������\n";
	//CirLinkListPrint(L);
	//
	////��i��λ��ɾ�����
	//CirLinkListDelete(&L, 4);
	//cout << "���ѭ������\n";
	//CirLinkListPrint(L);

	////����Ԫ��
	//int i = 5;
	//int pos=CirLinkListSearch(L, i);
	//cout << "Ԫ��ֵΪ"<<i<<"������Ϊ"<<pos<<"\n";
	//
	return 0;
}