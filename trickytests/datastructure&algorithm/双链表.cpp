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
		throw "位置";
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
		throw "位置";
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
DataType DulLinkList<DataType>::FindMaxIter(Node<DataType> *larger,Node<DataType> *next){ //寻找最大值的函数,最大值那个结点的指针和下一步的指针为参数 
	if(next==NULL) 							//判断next是否为空 ，那么就返回所发现的最大 
		return larger->data;						//返回最大值 
	else{
		if(larger->data<next->data)					//如果指针指向的现有的结点的指针比下个所发现的小，那么 
			FindMaxIter(next,next->next);	//把next传入larger，然后next后移 
		else
			FindMaxIter(larger,next->next);	//如果正常则不变，next后移 
	}
}
template <typename DataType>
void DulLinkList<DataType>::FindMaxDelete(Node<DataType> *p,DataType max){//删除所寻找的最大值的函数 
	if(p==NULL)						//到尾端就返回 
		return ;
	else{
		if(p->data==max){			//如果搜到一个，就删除 
			Node<DataType> *temp=p;
			p=p->next;
			temp->pre->next=temp->next;
			if(temp->next!=NULL)
				temp->next->pre=temp->pre;
			delete temp;
			FindMaxDelete(p,max);	//继续 ，p已经是下个p了 
		}
		else
			FindMaxDelete(p->next,max);	//没有也继续 
	}
}
template <typename DataType>
void DulLinkList<DataType>::FindMaxRecursion(){							//封装一下初始的调用状态
	DataType max=FindMaxIter(first->next,first->next->next);	//假定larger开始是第一个结点，next是第二个结点，找到的最大值返回给max 
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
	cout<<"经过递归的操作之后"<<endl;
	a.PrintList();
	cout<<"再次经过循环的操作之后"<<endl;
	a.FindMaxLoop();
	a.PrintList(); 
	exit(0);
}
