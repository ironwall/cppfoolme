#include <iostream>
#define N 10
#define M 5
using namespace std;
struct node{
	int data;
	node *next;
};
int main(){
	node *head,*tail,*write;
	write=new node;
	write->next=NULL;
	head=write;
	head->data=1;
	tail=write;
	for(int i=2;i<=N;i++){
		write=new node;
		write->next=NULL;
		write->data=i;
		tail->next=write;
		tail=tail->next;
	}
	tail->next=head;
	write=head;
	for(int count=0;count<=N-1;count++){
		for(int key=1;key<=M-1;key++){
			write=write->next;
			tail=tail->next;
		}
		cout<<write->data<<" ";
		tail->next=tail->next->next;
		delete write;
		write=tail->next;
	}
}
