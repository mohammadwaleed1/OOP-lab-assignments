#include<iostream>
 using namespace std;
 
 class user{
 	public:
 		int age;
 		string name;
 		
 };
int main(int argc, char*argv[]){
user p1;
p1.age=24;
p1.name="Teo";
cout<<"my name is "<<p1.name<<" and my age is "<<p1.age;
return 0;
 }