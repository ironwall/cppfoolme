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
		//在fuck下面建立fuck左侧所有节点的 复制*fuck 
		//p1从根节点开始，p1向right走一步，创建p2=p1接着疯狂往down走（每走一步都要取值），当p2是NULL时，p1向right走一步，直到p1走到fuck
		//如果p2存在，p2->data的值全部取出放入fuckrun=new node 
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
