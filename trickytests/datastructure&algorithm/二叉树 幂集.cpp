template<int n>
struct Node{
	int data[n];
	Node *right;
	Node *down;
};

root->data[0] = a[0];
root->down = NULL;
root->right = NULL;

f(root, a, 1)
void f(Node *root, int a[], int n){
	if(root->right == NULL){
		Node *fuck = new Node;
		fuck->down = NULL;
		fuck->right = NULL;
	/*	for(int i = 0; i < N; i++){
			fuck->data[i] = -1;
		}*/
		fuck->data[0] = a[n];
		root->right = fuck;
		
		//g(this->root, fuck);
		//��fuck���潨��fuck������нڵ�� ����*fuck 
		//p1�Ӹ��ڵ㿪ʼ��p1��right��һ��������p2=p1���ŷ����down�ߣ�ÿ��һ����Ҫȡֵ������p2��NULLʱ��p1��right��һ����ֱ��p1�ߵ�fuck
		//���p2���ڣ�p2->data��ֵȫ��ȡ������fuckrun=new node 
		Node *p1 = this->root;
		Node *p2 = this->root;
		Node *fuckrun = fuck;
		
		while(p1 != fuck){
			while(p2 != NULL){
				Node *s = new Node;
				s->down = NULL;
				s->right = NULL;
				fuckrun->down = s;
				for(int i = 0; i < N; i++){
					s->data[i] = p2->data[i];
				}
				for(int i = 0; s->data[i]!=-1; i++){
					if(s->data[i] == -1){
						s->data[i] = fuck->data[0];
						break;
					}
				}
				p2 = p2->down; 
			}
			p1 = p1->right;
			p2 = p1;
		} 
		fuckrun = fuck;
		
	}
	else{
		f(root->right, a, n+1);
	}
}
