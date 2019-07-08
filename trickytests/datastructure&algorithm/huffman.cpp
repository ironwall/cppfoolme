#include <iostream>
using namespace std;

struct element{					//哈夫曼树节点结构体，此哈夫曼算法用数组表达 
	int weight;
	int lchild,rchild,parent;
}; 
void Select(element HT[],int n,int &s1, int &s2){	//查找权值最小的两个节点  
	element temp[n];						//建立一棵空的哈夫曼树，要把传入的树进行筛选存入		
	for(int i=0;i<n;i++){					 
		temp[i].parent=0;
		temp[i].lchild=0;
		temp[i].rchild=0;
		temp[i].weight=0;
	}
	for(int i=0;i<n;i++){
		if(HT[i].parent==-1){				//如果传入的树的节点的双亲节点为空，那么考虑他，加入选取的范围之内 
			temp[i].parent=-1;
			temp[i].lchild=HT[i].lchild;
			temp[i].rchild=HT[i].rchild;
			temp[i].weight=HT[i].weight;
		}
	}
	for(int i=0;i<n;i++){
		if(temp[i].parent==-1){				//选出最小的 
			s1=i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(temp[i].parent==-1){
			if(temp[i].weight<temp[s1].weight)
				s1=i;
		}
	}
	temp[s1].parent=0;						//剔除最小的 
	temp[s1].lchild=0;
	temp[s1].rchild=0;
	temp[s1].weight=0;
	for(int i=0;i<n;i++){					//选出剔除后剩下的最小的 
		if(temp[i].parent==-1){
			s2=i;
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(temp[i].parent==-1){
			if(temp[i].weight<temp[s2].weight)
				s2=i;
		}
	}
}
void HuffmanTree(element huffTree[],int w[],int n){
	for(int i=0;i<2*n-1;i++){		//对整个哈夫曼数组初始化，初始化所有节点 
		huffTree[i].parent=-1;
		huffTree[i].lchild=-1;
		huffTree[i].rchild=-1;
	}
	for(int i=0;i<n;i++){			//把权值数组存入哈夫曼数组的前n个，权值数组也是n个 
		huffTree[i].weight=w[i];
	}
	for(int i=n;i<2*n-1;i++)		//哈夫曼数组其余成员令其权值为-1
		huffTree[i].weight=-1; 
	//----------------------- 
	for(int i=0;i<2*n-1;i++){
		cout<<"weight:"<<huffTree[i].weight<<"  parent:"<<huffTree[i].parent<<"  lchild:"<<huffTree[i].lchild<<"  rchild:"<<huffTree[i].rchild<<endl;
	}
	cout<<endl<<endl;
	for(int k=n;k<2*n-1;k++){		//从n到2*n-1这段数组进行构建哈夫曼树 
		int i1,i2;					//选出其中权值最小的两个 
		Select(huffTree,k,i1,i2);	//选择函数 
		huffTree[i1].parent=k;
									//后续操作设定了树的每个节点的左右孩子和双亲节点的下标关系
		huffTree[i2].parent=k;
		huffTree[k].weight=huffTree[i1].weight+huffTree[i2].weight;
		huffTree[k].lchild=i1;
		huffTree[k].rchild=i2;
	}
	for(int i=0;i<2*n-1;i++){
		cout<<"weight:"<<huffTree[i].weight<<"  parent:"<<huffTree[i].parent<<"  lchild:"<<huffTree[i].lchild<<"  rchild:"<<huffTree[i].rchild<<endl;
	}
}
int main(){
	int a[4]={2,3,4,5};
	element hfm[2*4-1];		//权值数组长度为n 哈夫曼树数组的长度为 n*2-1 
	HuffmanTree(hfm,a,4);	//调用 
}
