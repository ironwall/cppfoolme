#include <iostream>

using namespace std;

struct element{
	int D;
	int d;
	bool boost;
};
struct TreeNode{
	element data;
	char name;
	TreeNode *first,*right;
};

class Tree{
	public:
		Tree();
		~Tree(){Release(root);}
		void print(){print(root);}
		void CalcD(){CalcD(root);}
		void SetAMP(int stand){SetAMP(root,stand);} 
	private:
		TreeNode *root;
		void Release(TreeNode *root);
		int CalcD(TreeNode *root);
		void print(TreeNode *root);
		void SetAMP(TreeNode *root,int stand);
};
void Tree::print(TreeNode *root){
	if(root!=NULL){
		print(root->first);
		cout<<root->name<<" "<<root->data.d<<" "<<root->data.D<<endl;
		print(root->right);
	}
	else
		return ;
}
Tree::Tree(){
	TreeNode *A=new TreeNode;
	TreeNode *B=new TreeNode;
	TreeNode *C=new TreeNode;
	TreeNode *D=new TreeNode;
	TreeNode *E=new TreeNode;
	TreeNode *F=new TreeNode;	
	TreeNode *G=new TreeNode;
	TreeNode *H=new TreeNode;
	TreeNode *I=new TreeNode;
	TreeNode *J=new TreeNode;
	TreeNode *K=new TreeNode;
	
	root=A;
	
	A->name='A';
	A->first=B;
	A->right=NULL;
	A->data.d=0;
	A->data.boost=0;
	
	B->name='B';
	B->first=D;
	B->right=C;
	B->data.d=1;
	B->data.boost=0;
	
	D->name='D';
	D->first=H;
	D->right=E;
	D->data.d=2;
	D->data.boost=0;
	
	H->name='H';
	H->first=NULL;
	H->right=I;
	H->data.d=2;
	H->data.D=0;
	H->data.boost=0;
	
	I->name='I';
	I->first=NULL; 
	I->right=NULL;
	I->data.d=1;
	I->data.D=0;
	I->data.boost=0;
	
	E->name='E';
	E->first=NULL;
	E->right=NULL;
	E->data.D=0;
	E->data.d=2;
	E->data.boost=0;
	
	C->name='C';
	C->first=F;
	C->right=NULL;
	C->data.d=3;
	C->data.boost=0;
	
	F->name='F';
	F->first=J;
	F->right=G;
	F->data.d=1;
	F->data.boost=0;
	
	G->name='G';
	G->first=K;
	G->right=NULL;
	G->data.d=2;
	G->data.boost=0;
	
	J->name='J';
	J->first=NULL;
	J->right=NULL;
	J->data.D=0;
	J->data.d=2;
	J->data.boost=0;
	
	K->name='K';
	K->first=NULL;
	K->right=NULL;
	K->data.D=0;
	K->data.d=2;
	K->data.boost=0;
}
void Tree::Release(TreeNode *root){
	if(root!=NULL){
		Release(root->first);
		Release(root->right);
		delete root;
	} 
}

int Tree::CalcD(TreeNode *root){
	if(root->first==NULL){				//如果root是叶子节点 
		return root->data.D;
	}			//返回D值 
	else{						//需要根据支路的数量创建变量
		int count=1; 				//计数孩子个数 
		TreeNode *temp=root->first;
		while(temp->right!=NULL){
			count++;
			temp=temp->right;
		}
		temp=root->first;
		int a[count]={0};		//支路是count条，每条支路都应该返回一个D值 
		for(int n=0;n<count;n++){
			for(int i=0;i<n;i++)
				temp=temp->right;
			a[n]=CalcD(temp);
			if(temp->data.boost==1)
				a[n]=0;
			a[n]=temp->data.d+a[n];
		}
		int max=0;;
		for(int i=0;i<count;i++){
			if(a[i]>max)
				max=a[i];
		}
		root->data.D=max;
		return root->data.D;
	}
}
void Tree::SetAMP(TreeNode *root,int stand){
	//中序遍历按照每个节点的顺序考虑其是否应该设置放大器。
	 TreeNode *s[80];
	 int top=-1;
	 while(root!=NULL||top!=-1){
	 	while(root!=NULL){
	 		s[++top]=root;
	 		root=root->first;
		}
		if(top!=-1){
			root=s[top--];
			if((root->data.d+root->data.D)>stand){
				root->data.boost=1;
				CalcD();
			}
			root=root->right;
		}
	 } 
}
int main(){
	Tree A;
	A.print();
	cout<<endl;
	A.CalcD();
	A.print();
	cout<<endl;
	A.SetAMP(3);
	A.print();
	cout<<endl;
} 
