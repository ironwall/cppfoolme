#include <iostream>
using namespace std;

template <class DataType>
struct Node{			//单链表结点 
	DataType data;
	Node<DataType> *next; 
};

template <class DataType>
class LinkList{			//创建单链表类 
public:
	void FindMaxDeleteLoop();		//找到最大值删除：循环版本 
	void FindMaxDeleteRecursion();  //找到最大值删除：递归版本
	void MaxDelete(Node<DataType> *pre,Node<DataType> *p,DataType max);		//递归版本需要的函数1 
	DataType FindMax(Node<DataType> *first, Node<DataType> *except_larger); //递归版本需要的函数2 
	LinkList(DataType a[], int n);	//有参构造函数 
	~LinkList();					//析构函数 
	void PrintList();				//链表的打印 
private:
	Node<DataType> *first;			//头指针 
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
template <class DataType>			//参数first是为了每次存下前一个节点的值， except_first分配下后面所有的结点（给first） 
DataType LinkList<DataType>::FindMax(Node<DataType> *first, Node<DataType> *except_first){	
	if(except_first==NULL)		//如果分配完毕 
		return first->data;		// 归 开始 
	else{
		DataType a = first->data;	//存下每个first的结点给a 
		DataType b = FindMax(first->next,except_first->next); //b是后面所有节点中最大的 
		return a>b?a:b;				//比较第一个和后面中最大的，取大的返回 
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
	
	while(p!=NULL){			//遍历1，找到最大值	
		if(max<p->data)		//打擂台，大的存入max 
			max=p->data;			
		p=p->next;			//工作指针后移 
	}
	
	p=first->next;
	Node<DataType> *pre=first;	//单链表删除p需要记录p前一个节点的地址 
	
	while (p != NULL) {		//遍历2，删除所有和最大值一样的结点 
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
	cout<<"递归操作"<<endl;
	a.FindMaxDeleteRecursion();
	a.PrintList();
	cout<<"循环操作"<<endl;
	a.FindMaxDeleteLoop();
	a.PrintList();
} 
