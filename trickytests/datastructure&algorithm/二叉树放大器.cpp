#include <iostream>

using namespace std;

struct element{
	int D;         // �ý���˥����
	int d;        // ������˥����
	bool boost;   //���ҽ����������÷Ŵ�������boostΪtrue
};
struct BiNode{
	element data;
	char name;
	BiNode *lchild,*rchild;
};

class BiTree{
	public:
		BiTree();
		~BiTree(){Release(root);}
		void CalcD(){CalcD(root);}
		void print(){print(root);}
		void SetAMP(int stand){SetAMP(root,stand);} 
		
	private:
		BiNode *root;
		void Release(BiNode *root);
		int CalcD(BiNode *root);
		void print(BiNode *root);
		void SetAMP(BiNode *root,int stand);
};
void BiTree::print(BiNode *root){
	if(root!=NULL){
		print(root->lchild);
		print(root->rchild);
		cout<<root->name<<" "<<root->data.d<<" "<<root->data.D<<endl;
	}
	else return ;
}
BiTree::BiTree(){
	BiNode *A=new BiNode;
	BiNode *B=new BiNode;
	BiNode *C=new BiNode;
	BiNode *D=new BiNode;
	BiNode *E=new BiNode;
	BiNode *F=new BiNode;	
	BiNode *G=new BiNode;
	BiNode *H=new BiNode;
	BiNode *I=new BiNode;
	BiNode *J=new BiNode;
	BiNode *K=new BiNode;
	
	root=A;
	A->name='A';
	A->lchild=B;
	A->rchild=C;
	A->data.d=0;
	A->data.boost=0;
	
	B->name='B';
	B->lchild=D;
	B->rchild=E;
	B->data.d=1;
	B->data.boost=0;
	
	D->name='D';
	D->lchild=H;
	D->rchild=I;
	D->data.d=2;
	D->data.boost=0;
	
	H->name='H';
	H->lchild=NULL;
	H->rchild=NULL;
	H->data.d=2;
	H->data.D=0;
	H->data.boost=0;
	
	I->name='I';
	I->lchild=NULL; 
	I->rchild=NULL;
	I->data.d=1;
	I->data.D=0;
	I->data.boost=0;
	
	E->name='E';
	E->lchild=NULL;
	E->rchild=NULL;
	E->data.D=0;
	E->data.d=2;
	E->data.boost=0;
	
	C->name='C';
	C->lchild=F;
	C->rchild=G;
	C->data.d=3;
	C->data.boost=0;
	
	F->name='F';
	F->lchild=J;
	F->rchild=NULL;
	F->data.d=1;
	F->data.boost=0;
	
	G->name='G';
	G->lchild=K;
	G->rchild=NULL;
	G->data.d=2;
	G->data.boost=0;
	
	J->name='J';
	J->lchild=NULL;
	J->rchild=NULL;
	J->data.D=0;
	J->data.d=2;
	J->data.boost=0;
	
	K->name='K';
	K->lchild=NULL;
	K->rchild=NULL;
	K->data.D=0;
	K->data.d=2;
	K->data.boost=0;
	
}
void BiTree::Release(BiNode *root){
	if(root!=NULL){
		Release(root->lchild);
		Release(root->rchild);
		delete root; 
	} 
}

int BiTree::CalcD(BiNode *root){
	if(root->lchild==NULL && root->rchild==NULL)	//���root��Ҷ�ӽڵ� 
		return root->data.D;						//����Dֵ 
	else{
		int n=0,m=0,left=0,right=0;
		if(root->lchild!=NULL){						//���root������ 
			n=CalcD(root->lchild);					//����root��������Dֵ 
			if(root->lchild->data.boost==1)			//����������˷Ŵ��� 
				n=0;								//������������Dֵ 
			left=root->lchild->data.d+n;			//root��������Dֵ 
		}
		if(root->rchild!=NULL){						//���root���Һ��� 
			m=CalcD(root->rchild);					//����root�Һ��ӵ�Dֵ 
			if(root->rchild->data.boost==1)			//����������˷Ŵ��� 
				m=0;								//������������Dֵ 
			right=root->rchild->data.d+m;			//root�Ҳ������Dֵ 
		}
		root->data.D=(left>right)?(left):(right);	//root��Dֵ�������Ҳ�Ľϴ�ֵ 
	}
}

void BiTree::SetAMP(BiNode *root,int stand){		//����ջ������ʡ��flag�ķ��� 
	BiNode *s[200];
	int top=-1;
	BiNode *visit;
	s[++top]=root;
	s[++top]=root;
	while(s&&top>=0){
		root=s[top];
		top--;
		visit=s[top];
		if(root->rchild!=NULL && root==visit){
			s[++top]=root->rchild;
			s[++top]=root->rchild;
		}
		if(root->lchild!=NULL && root==visit){
			s[++top]=root->lchild;
			s[++top]=root->lchild;
		}
		if(root->lchild==NULL && root->rchild==NULL){
			if(root->data.D+root->data.d>stand){ 
				root->data.boost=1;
				CalcD();
			} 
			top--;
		}
		if(root!=visit){
			if(root->data.D+root->data.d>stand){ 
				root->data.boost=1;
				CalcD();
			} 
		}
	}
	CalcD();			//�Ľ�һ�½ڵ��Dֵ 
}

int main(){
	BiTree test;
	test.CalcD();
	cout<<endl;
	test.print();
	cout<<endl;
	test.SetAMP(3);
	test.print();
	return 0;
}
