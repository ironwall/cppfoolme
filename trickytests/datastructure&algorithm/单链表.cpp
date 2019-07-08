#include <iostream>
using namespace std;

template <class DataType>
struct Node{			//�������� 
	DataType data;
	Node<DataType> *next; 
};

template <class DataType>
class LinkList{			//������������ 
public:
	void FindMaxDeleteLoop();		//�ҵ����ֵɾ����ѭ���汾 
	void FindMaxDeleteRecursion();  //�ҵ����ֵɾ�����ݹ�汾
	void MaxDelete(Node<DataType> *pre,Node<DataType> *p,DataType max);		//�ݹ�汾��Ҫ�ĺ���1 
	DataType FindMax(Node<DataType> *first, Node<DataType> *except_larger); //�ݹ�汾��Ҫ�ĺ���2 
	LinkList(DataType a[], int n);	//�вι��캯�� 
	~LinkList();					//�������� 
	void PrintList();				//����Ĵ�ӡ 
private:
	Node<DataType> *first;			//ͷָ�� 
};
template <class DataType>
void LinkList<DataType>::PrintList() {
	Node<DataType> *p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
}

template <class DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
	first = new Node<DataType>;
	first->next = NULL;
	for (int i = 0; i < n; i++) {
		Node<DataType> *s = new Node<DataType>;
		s->data = a[i];
		s->next = first->next;
		first->next = s;
	}
}

template <class DataType>
LinkList<DataType>::~LinkList() {
	while (first != NULL) {
		Node<DataType> *q = first;
		first = first->next;
		delete q;
	}
}
template <class DataType>			//����first��Ϊ��ÿ�δ���ǰһ���ڵ��ֵ�� except_first�����º������еĽ�㣨��first�� 
DataType LinkList<DataType>::FindMax(Node<DataType> *first, Node<DataType> *except_first){	
	if(except_first==NULL)		//���������� 
		return first->data;		// �� ��ʼ 
	else{
		DataType a = first->data;	//����ÿ��first�Ľ���a 
		DataType b = FindMax(first->next,except_first->next); //b�Ǻ������нڵ������� 
		return a>b?a:b;				//�Ƚϵ�һ���ͺ��������ģ�ȡ��ķ��� 
	}
}
template <class DataType>
void LinkList<DataType>::MaxDelete(Node<DataType> *pre,Node<DataType> *p,DataType max){
	if(p==NULL)				
		return ;
	else{
		if(p->data==max){			
			pre->next=p->next;
			delete p;
			p=pre->next;
			MaxDelete(pre,p,max);	
		}
		else
			MaxDelete(pre->next,p->next,max);	
	}
}
template <class DataType>
void LinkList<DataType>::FindMaxDeleteRecursion(){	
	DataType max=FindMax(first->next,first->next->next);	 
	MaxDelete(first,first->next,max);
}

template <typename DataType>
void LinkList<DataType>::FindMaxDeleteLoop(){
	DataType max;
	Node<DataType> *p=first->next;
	
	while(p!=NULL){			//����1���ҵ����ֵ	
		if(max<p->data)		//����̨����Ĵ���max 
			max=p->data;			
		p=p->next;			//����ָ����� 
	}
	
	p=first->next;
	Node<DataType> *pre=first;	//������ɾ��p��Ҫ��¼pǰһ���ڵ�ĵ�ַ 
	
	while (p != NULL) {		//����2��ɾ�����к����ֵһ���Ľ�� 
		if (p->data == max){	
			pre->next=p->next;
			delete p;
			p=pre->next;			
		}
		else{
			p=p->next;
			pre=pre->next;
		}
	}
}



int main(void){
	int i[10]={899,9,2,4,6,87,19,5,53,999};
	LinkList<int> a(i,10);
	a.PrintList();
	cout<<"�ݹ����"<<endl;
	a.FindMaxDeleteRecursion();
	a.PrintList();
	cout<<"ѭ������"<<endl;
	a.FindMaxDeleteLoop();
	a.PrintList();
} 
