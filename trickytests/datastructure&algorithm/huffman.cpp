#include <iostream>
using namespace std;

struct element{					//���������ڵ�ṹ�壬�˹������㷨�������� 
	int weight;
	int lchild,rchild,parent;
}; 
void Select(element HT[],int n,int &s1, int &s2){	//����Ȩֵ��С�������ڵ�  
	element temp[n];						//����һ�ÿյĹ���������Ҫ�Ѵ����������ɸѡ����		
	for(int i=0;i<n;i++){					 
		temp[i].parent=0;
		temp[i].lchild=0;
		temp[i].rchild=0;
		temp[i].weight=0;
	}
	for(int i=0;i<n;i++){
		if(HT[i].parent==-1){				//�����������Ľڵ��˫�׽ڵ�Ϊ�գ���ô������������ѡȡ�ķ�Χ֮�� 
			temp[i].parent=-1;
			temp[i].lchild=HT[i].lchild;
			temp[i].rchild=HT[i].rchild;
			temp[i].weight=HT[i].weight;
		}
	}
	for(int i=0;i<n;i++){
		if(temp[i].parent==-1){				//ѡ����С�� 
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
	temp[s1].parent=0;						//�޳���С�� 
	temp[s1].lchild=0;
	temp[s1].rchild=0;
	temp[s1].weight=0;
	for(int i=0;i<n;i++){					//ѡ���޳���ʣ�µ���С�� 
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
	for(int i=0;i<2*n-1;i++){		//�����������������ʼ������ʼ�����нڵ� 
		huffTree[i].parent=-1;
		huffTree[i].lchild=-1;
		huffTree[i].rchild=-1;
	}
	for(int i=0;i<n;i++){			//��Ȩֵ�����������������ǰn����Ȩֵ����Ҳ��n�� 
		huffTree[i].weight=w[i];
	}
	for(int i=n;i<2*n-1;i++)		//���������������Ա����ȨֵΪ-1
		huffTree[i].weight=-1; 
	//----------------------- 
	for(int i=0;i<2*n-1;i++){
		cout<<"weight:"<<huffTree[i].weight<<"  parent:"<<huffTree[i].parent<<"  lchild:"<<huffTree[i].lchild<<"  rchild:"<<huffTree[i].rchild<<endl;
	}
	cout<<endl<<endl;
	for(int k=n;k<2*n-1;k++){		//��n��2*n-1���������й����������� 
		int i1,i2;					//ѡ������Ȩֵ��С������ 
		Select(huffTree,k,i1,i2);	//ѡ���� 
		huffTree[i1].parent=k;
									//���������趨������ÿ���ڵ�����Һ��Ӻ�˫�׽ڵ���±��ϵ
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
	element hfm[2*4-1];		//Ȩֵ���鳤��Ϊn ������������ĳ���Ϊ n*2-1 
	HuffmanTree(hfm,a,4);	//���� 
}
