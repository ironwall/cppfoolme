#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct BiNode{
	int data;
	BiNode *lchild,*rchild;
};

class BiTree{
public:
	BiTree(int num); 
	~BiTree(){Release(root);}
	void build();
	void build1();
	void build2();
	void PreOrder(){PreOrder(root);}
	void InOrder(){InOrder(root);}
	void LeverOrder();
	BiNode *rtr();
private:
	BiNode *root=NULL;
	BiNode *Creat(BiNode *bt,int data);
	void Release(BiNode *bt);
	void PreOrder(BiNode *bt);
	void InOrder(BiNode *bt);
};
BiNode *BiTree::rtr(){
	return root;
}
void BiTree::build1(){
	root = new BiNode;
	BiNode *p2=new BiNode;
	BiNode *p3=new BiNode;
	BiNode *p4=new BiNode;
	root->lchild=p2;
	root->lchild=NULL;
	p2->lchild=p3;
	p3->lchild=NULL;
	p3->rchild=NULL;
	p2->rchild=p4;
	p4->lchild=NULL;
	p4->rchild=NULL;
	cout<<"完成1"<<endl; 
}
void BiTree::build2(){
	root = new BiNode;
	BiNode *p2=new BiNode;
	BiNode *p3=new BiNode;
	BiNode *p4=new BiNode;
	root->rchild=p2;
	root->lchild=NULL;
	p2->lchild=p3;
	p3->lchild=NULL;
	p3->rchild=NULL;
	p2->rchild=p4;
	p4->lchild=NULL;
	p4->rchild=NULL;
	cout<<"完成2"<<endl; 
}
BiTree::BiTree(int num){
	if(num==1){
		build1();
	}
	else{
		build2();
	}
}
void BiTree::build(){      
    srand(time(NULL)); 
    int temp = rand() % 20 + 1;     
    for(int i = 0; i < temp; ++i)
    {
        int data = rand() % 100;   
        root=Creat(root,data);
    }
}

BiNode *BiTree::Creat(BiNode *root,int data){
	if(root==NULL){
		root=new BiNode;
		root->lchild=NULL;
		root->rchild=NULL;
		root->data=data;
	}
	else if(data>root->data)
		root->rchild=Creat(root->rchild,data);
	else if(data<root->data)
		root->lchild=Creat(root->lchild,data);
	else 
		return root;
}

void BiTree::PreOrder(BiNode *bt){
	if(bt==NULL)
		return ;
	else{
		cout<<bt->data<<" ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void BiTree::InOrder(BiNode *bt){
	if(bt==NULL)
		return ;
	else{
		InOrder(bt->lchild);
		cout<<bt->data<<" ";
		InOrder(bt->rchild);
	}
}

void BiTree::Release(BiNode *bt){
	
	if(bt!=NULL){
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
	}
} 

int Like(BiNode *s,BiNode *t);
int main(){
	BiTree a(1);
	BiTree b(1);
	int c=Like (a.rtr(),b.rtr());
	cout<<c;
	return 0;
}
int Like(BiNode *s,BiNode *t){
	if(!s && !t) 
		return 1;
    else if((!s && t)||(s && !t))
		return 0;
	else{
        int same=Like(s->lchild, t->lchild);
        if(same) 
			same=Like(s->rchild, t->rchild);
        return same; 
    }

}

