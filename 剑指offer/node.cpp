#include<bits/stdc++.h>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;
#include <ext/hash_map>
#include <ext/hash_set>
#include <ext/rope>





struct node{
	int val;
	node *next;
	node(){};
	node(int val,node *next){
		this->val = val;
		this->next = next;
	} 
};

hash_map<int,node*> mp; 
void addtotail(node *head,int val){
	node *t=new node();
	t->val = val;
	t->next = NULL;
	mp[val] = t;
	node *i = head;
	while(i->next != NULL){
		i = i->next;
	}
	i->next = t;
}

void print(node *head){
	if(head == NULL) return ;
	node *i = head;;
	while(i!=NULL){
		if(i->val != -1) cout<<i->val<<' ';
		i = i->next; 
	}
	cout<<endl;
}


void remove(node *&head,int val){
	node *q = head;
	node *del = NULL;
	if(q == NULL) return ;
	while(q->next != NULL && q->next->val!=val){
		q = q->next; 
	}
	//q为前驱结点
	if(q->next != NULL && q->next->val == val){
		del = q->next;
		q->next = q->next->next;
	}
	if(del != NULL) {
		delete del;	
		del = NULL;
	}
} 


//逆序输出 
void rprint(node *cur){
	if(cur == NULL) return ;
	rprint(cur->next);
	if(cur->val != -1)cout<<cur->val<<' ';
} 


//找链表中倒数第k个结点 ,双指针 
int search(node *head,int k){
	if(head == NULL) return -1;
	node *p =head,*q = p;
	int ct = 0 ;
	while(p!=NULL) ct++,p=p->next;	
	if(ct < k) return -1;
	p = q;
	while(k-->1) q = q->next;
	while(q->next != NULL) {
		//cout<<p->val<<' '<<q->val<<endl;
		q = q->next, p = p->next;
	}
	if(p!=NULL) return p->val; 
	return -1;
} 


//链表翻转，返回新的头结点 
node *reverse(node *head){
	node *newhead = NULL;
	node *p = head->next;
	node *pre = NULL;
	while(p != NULL){
	//if(p!=NULL)	cout<<p->val<<endl;
		node *nxt = p->next;
		if(nxt == NULL) newhead = p;
		p->next = pre;
		pre = p;
		p = nxt;
		
	}
	//cout<<newhead->val<<endl;
	return newhead;
}



//合并两个有序链表 ,返回合并后的新头结点 
node *merge(node *ha,node *hb){
	if(ha == NULL) return hb;
	else if(hb == NULL) return ha;
	node *newhead = NULL;
	//cout<<ha->val<<' '<<hb->val<<endl;
	if(ha->val <= hb->val){
		newhead = ha;
		ha->next = merge(ha->next,hb);
	}
	else{
		newhead = hb;
		hb->next = merge(ha,hb->next);
	}
	return newhead;
}



int main(){	
	node *a = new node(-1,NULL);
	remove(a,1);
	node *b = new node(-2,NULL);
	node *c = new node(-1,NULL);
	node *d = new node(-1,NULL);
	addtotail(c,1);
	addtotail(c,3);
	addtotail(c,5);
	addtotail(d,2);
	addtotail(d,4);
	addtotail(d,6);
	node *e = merge(c,d);
	print(e);
	
	addtotail(a,1);
	addtotail(a,2);
	addtotail(a,5);
	addtotail(a,4);
	addtotail(a,3);
	addtotail(a,7);
	addtotail(a,8);
	remove(a,1);
	
	print(a);
	node *newa = reverse(a);
	print(newa);
//	int k;
//	cin>>k;
//	cout<<search(a,k)<<endl;
	
	//print(a);
	//remove(a,2);
	//print(a);
	
	//rprint(a);
	return 0;
}
