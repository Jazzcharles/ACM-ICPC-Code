#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
struct student{
	int money;
	int id;
	string name;
	int ave;
	int score;
	string gb;
	string west;
	int num;
}stu[maxn];

int cmp(struct student a,struct student b){
	if(a.money==b.money) return a.id>b.id;
	else return a.money<b.money;
}
int main(){
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].ave>>stu[i].score>>stu[i].gb>>stu[i].west>>stu[i].num;
		stu[i].id=i;
		if(stu[i].ave>80 && stu[i].num>=1) stu[i].money+=8000;
		if(stu[i].ave>85 && stu[i].score>80) stu[i].money+=4000;
		if(stu[i].ave>90) stu[i].money+=2000;
		if(stu[i].ave>85 && stu[i].west[0]=='Y') stu[i].money+=1000;
		if(stu[i].score>80 && stu[i].gb[0]=='Y') stu[i].money+=850;
		ans+=stu[i].money;
	}
	sort(stu,stu+n,cmp);
	cout<<stu[n-1].name<<endl<<stu[n-1].money<<endl<<ans<<endl;
	return 0;
}
