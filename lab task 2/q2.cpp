#include<iostream>
using namespace std;
typedef struct organisation{
	string orgname;
	int orgnumber;
}org;
typedef struct employee{
	org details;
	int id;
	string name;
	int salary;
}emp;
int main(){
org p1;
emp p2;
cout<<"organisation name:";
cin>>p1.orgname;
cout<<"organisaion number:";
cin>>p1.orgnumber;
cout<<"employee id:";
cin>>p2.id;
cout<<"employee name:";
cin>>p2.name;
cout<<"employee salary:";
cin>>p2.salary;

cout<<"organisation name:"<<p1.orgname<<endl;
cout<<"organisaion number:"<<p1.orgnumber<<endl;
cout<<"employee id:"<<p2.id<<endl;
cout<<"employee name:"<<p2.name<<endl;
cout<<"employee salary:"<<p2.salary<<endl;


return 0;
}
