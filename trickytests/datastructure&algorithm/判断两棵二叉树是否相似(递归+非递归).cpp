#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
struct BiNode{
	BiNode *lchild,*rchild;
};

class BiTree{
public:
	BiTree(int number);
	~BiTree(){Release(root);}
	void build1();
	void build2();
	void Release(BiNode *bt);
	BiNode *root;
};

BiTree::BiTree(int number){
	root=NULL;
	if(number==1)
		build1();
	else
		build2();
}

void BiTree::build1(){
	root = new BiNode;
	BiNode *p2=new BiNode;
	BiNode *p3=new BiNode;
	BiNode *p4=new BiNode;
	root->lchild=p2;
	root->rchild=NULL;
	p2->lchild=p3;
	p3->lchild=NULL;
	p3->rchild=NULL;
	p2->rchild=p4;
	p4->lchild=NULL;
	p4->rchild=NULL;
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
}

void BiTree::Release(BiNode *bt){
	if(bt!=NULL){
		Release(bt->lchild);
		Release(bt->rchild);
		delete bt;
		bt = NULL;
	}
}
int Like(BiNode *s, BiNode *t)
{
  if (!s && !t) return 1;
    else if ((!s && t) || (s && !t)) return 0;
          else  {
               int  same=Like(s->lchild, t->lchild);
                if (same) same=Like(s->rchild, t->rchild);
                return  same; 
          }
}
int Like2(BiNode *s,BiNode *t){
	BiNode *stack1[20];
	BiNode *stack2[20];
	int top1=-1;
	int top2=-1;
	while(t!=NULL||top1!=-1){ 			//整棵二叉树走完既循环跳出 
		while(1){						//设置跳出环境 
			if(t!=NULL && s!=NULL){		//如果正常两个二叉树向左都能正常遍历 
				stack1[++top1]=t;
				t=t->lchild;
				stack2[++top2]=s;
				s=s->lchild;
			}
			if(t!=NULL && s==NULL){		//如果t能遍历的时候s无法遍历，即为不相似 
				return 0;
			}
			if(t==NULL)					//如果t向左 走到尽头，就应该返回上一层了 
				break;
		}
		t=stack1[top1--];
		t=t->rchild;
		s=stack2[top2--];
		s=s->rchild;
	}
	top1=-1;top2=-1;
	while(s!=NULL||top2!=-1){ 
		while(1){
			if(s!=NULL && t!=NULL){
				stack2[++top2]=s;
				s=s->lchild;
				stack1[++top1]=s;
				t=t->lchild;
			}
			if(s!=NULL && t==NULL){
				return 0;
			}
			if(s==NULL)
				break;
		}
		s=stack2[top2--];
		s=s->rchild;
		t=stack1[top1--];
		t=t->rchild;
	}
	return 1;
}

int main(){
	BiTree a(2);
	BiTree b(1);
	cout<<"如果a是树形2，b是树形1，输出0是不相似，输出1是相似: ";  
	cout<<Like(a.root,b.root);
	cout<<Like2(a.root,b.root);
	cout<<endl; 
	a.Release(a.root);
	a.build2();
	b.Release(b.root);
	b.build2();
	cout<<"如果a是树形2，b是树形2，输出0是不相似，输出1是相似: ";  
	cout<<Like(a.root,b.root);
	cout<<Like2(a.root,b.root); 
	return 0;
}
