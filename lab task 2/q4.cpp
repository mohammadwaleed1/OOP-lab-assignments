#include<iostream>
using namespace std;
typedef struct employee{
	int id;
	string name;
	double salary;
}emp;
typedef struct organisation{
	emp details;
	string orgname;
	string orgnumber;
}org;
int main(){
org p1;
cout<<"organisation name:";
cin>>p1.orgname;
cout<<"organisaion number:";
cin>>p1.orgnumber;
cout<<"employee id:";
cin>>p1.details.id;
cout<<"employee name:";
cin>>p1.details.name;
cout<<"employee salary:";
cin>>p1.details.salary;

cout<<"size is:"<<sizeof(p1);
cout<<"organisation name:"<<p1.orgname<<endl;
cout<<"organisaion number:"<<p1.orgnumber<<endl;
cout<<"employee id:"<<p1.details.id<<endl;
cout<<"employee name:"<<p1.details.name<<endl;
cout<<"employee salary:"<<p1.details.salary<<endl;

return 0;
}