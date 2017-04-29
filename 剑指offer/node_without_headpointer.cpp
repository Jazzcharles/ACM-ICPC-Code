#include<bits/stdc++.h>
using namespace std;


struct node{
	int val;
	node *next;
};


void add2(node *&phead,int val){
	if(phead == NULL) {
		phead = new node();
		phead->val = val;	
		phead->next = NULL;
	}
	else{
		node *i = phead;
		node *temp = new node();
		temp->val = val;
		temp->next = NULL;
		while(i->next != NULL){
			i = i->next;
		}
		i->next = temp;
	}
	
}


void print2(node *head){
	if(head == NULL) return ;
	node *i = head;
	while(i!=NULL){
		cout<<i->val<<' ';
		i = i->next; 
	}
	cout<<endl;
}


void remove(node *&head,int val){
	node *p = head;
	node *q = head->next;
	if(p==NULL) return ;
	if(p->val == val){
		head = q;
		delete p;
		return ;
	}
	while(q != NULL && q->val!=val){
		p = q;
		q = q->next; 
	}
	p->next = q->next;
	q->next = NULL;
	delete q;
} 


int main(){
		
	node *b = NULL;
	add2(b,3);
	add2(b,4);
	add2(b,5);
	add2(b,6);
	add2(b,7);
	
	print2(b); 
	remove(b,3);
	print2(b);
	
	
	return 0;
}
