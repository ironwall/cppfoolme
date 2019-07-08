#include <iostream>
using namespace std;

template <typename DataType>
struct Node{
	DataType data;
	Node<DataType> *next;
	Node<DataType> *pre; 
};
template <typename DataType>
class DulLinkList{
public:
	DataType max();
	DataType max1(Node<DataType> *FirstElement, Node<DataType> *RestElement);
	void FindMaxRecursion();
	void FindMaxDelete(Node<DataType> *p,DataType max);
	DataType FindMaxIter(Node<DataType> *larger,Node<DataType> *next);
	void FindMaxLoop();
	DulLinkList();
	DulLinkList(DataType a[], int n);
	~DulLinkList();
	int Length();
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i, DataType x);
	DataType Delete(int i);
	void PrintList();
private:
	Node<DataType> *first;
};
template <typename DataType>
void DulLinkList<DataType>::PrintList() {
	Node<DataType> *p = first->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout<<endl;
}

template <typename DataType>
int DulLinkList<DataType>::Length() {
	Node<DataType> *p = first->next;
	int count = 0;
	while (p != NULL) {
		p = p->next;
		count++;
	}
	return count;
}

template <typename DataType>
DataType DulLinkList<DataType>::Get(int i) {
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL&&count < i) {
		p = p->next;
		count++;
	}
	if (p == NULL)
		throw "λ��";
	else 
		return p->data;
}

template <typename DataType>
int DulLinkList<DataType>::Locate(DataType x) {
	Node<DataType> *p = first->next;
	int count = 1;
	while (p != NULL) {
		if (p->data == x)
			return count;
		p = p->next;
		count++;
	}
	return 0;
}

template <typename DataType>
void DulLinkList<DataType>::Insert(int top, DataType x) {
	Node<DataType> *s = new Node<DataType>;
	s->data=x;
	Node<DataType> *p=first;
	int length=Length();
	if(top>(length+1))
		throw "λ��";
	else{
		for(int i=1;i<top;i++)
			p=p->next;
		s->pre=p;
		s->next=p->next;
		if(p->next!=NULL)
			(p->next)->pre=s;
		p->next=s;
	} 
}

template <typename DataType>
DulLinkList<DataType>::DulLinkList() {
	first = new Node<DataType>;
	first->next = NULL;
	first->pre = NULL;
}

template <typename DataType>
DataType DulLinkList<DataType>::Delete(int x) {
	Node<DataType> *p = first;
	for(int i=1;i<=x;i++)
		p=p->next;
	if(p->next!=NULL){
		p->pre->next=p->next;
		p->next->pre=p->pre;
	}
	else{
		p->pre->next=NULL;
	}
	delete p;
}

template <typename DataType>
DulLinkList<DataType>::DulLinkList(DataType a[], int n) {
	first = new Node<DataType>;
	first->next = NULL;
	first->pre = NULL;
	for (int i = 0; i < n; i++) {
		Insert(i+1,a[i]);
	}
}

template <typename DataType>
DulLinkList<DataType>::~DulLinkList() {
	while (first != NULL) {
		Node<DataType> *q = first;
		first = first->next;
		delete q;
	}
}
template <typename DataType>
void DulLinkList<DataType>::FindMaxLoop(){
	DataType max;
	Node<DataType> *p=first->next;
	while(p!=NULL){
		if(max<p->data)
			max=p->data;
		p=p->next;
	}
	p=first->next;
	while (p != NULL) {
		if (p->data == max){
			Node<DataType> *temp=p;
			p=p->next;
			temp->pre->next=temp->next;
			if(temp->next!=NULL)
				temp->next->pre=temp->pre;
			delete temp;
		}
		else
			p=p->next;
	}
} 
template <typename DataType>
DataType DulLinkList<DataType>::FindMaxIter(Node<DataType> *larger,Node<DataType> *next){ //Ѱ�����ֵ�ĺ���,���ֵ�Ǹ�����ָ�����һ����ָ��Ϊ���� 
	if(next==NULL) 							//�ж�next�Ƿ�Ϊ�� ����ô�ͷ��������ֵ���� 
		return larger->data;						//�������ֵ 
	else{
		if(larger->data<next->data)					//���ָ��ָ������еĽ���ָ����¸������ֵ�С����ô 
			FindMaxIter(next,next->next);	//��next����larger��Ȼ��next���� 
		else
			FindMaxIter(larger,next->next);	//��������򲻱䣬next���� 
	}
}
template <typename DataType>
void DulLinkList<DataType>::FindMaxDelete(Node<DataType> *p,DataType max){//ɾ����Ѱ�ҵ����ֵ�ĺ��� 
	if(p==NULL)						//��β�˾ͷ��� 
		return ;
	else{
		if(p->data==max){			//����ѵ�һ������ɾ�� 
			Node<DataType> *temp=p;
			p=p->next;
			temp->pre->next=temp->next;
			if(temp->next!=NULL)
				temp->next->pre=temp->pre;
			delete temp;
			FindMaxDelete(p,max);	//���� ��p�Ѿ����¸�p�� 
		}
		else
			FindMaxDelete(p->next,max);	//û��Ҳ���� 
	}
}
template <typename DataType>
void DulLinkList<DataType>::FindMaxRecursion(){							//��װһ�³�ʼ�ĵ���״̬
	DataType max=FindMaxIter(first->next,first->next->next);	//�ٶ�larger��ʼ�ǵ�һ����㣬next�ǵڶ�����㣬�ҵ������ֵ���ظ�max 
	FindMaxDelete(first,max);
}
template <typename DataType>
DataType DulLinkList<DataType>::max1(Node<DataType> *FirstElement, Node<DataType> *RestElement){
	if(RestElement==NULL)
		return FirstElement->data;
	else{
		DataType a = FirstElement->data;
		DataType b = max1(FirstElement->next,RestElement->next);
		return a>b?a:b;
	}
}
template <typename DataType>
DataType DulLinkList<DataType>::max(){
	return	max1(first->next,first->next->next);
}
int main(){
	int b[10]={900,488,38,12,10,6,77,90,2,6000};
	DulLinkList<int> a(b,10);
	a.PrintList();
	a.FindMaxRecursion();
	cout<<"�����ݹ�Ĳ���֮��"<<endl;
	a.PrintList();
	cout<<"�ٴξ���ѭ���Ĳ���֮��"<<endl;
	a.FindMaxLoop();
	a.PrintList(); 
	exit(0);
}
