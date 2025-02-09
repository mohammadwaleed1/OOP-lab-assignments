#include<iostream>
 using namespace std;
 
 class date{
 	public:
 		int month;
 		int day;
 		int year;
 	void display(){
 		cout<<day<<"/"<<month<<"/"<<year;
	 }
 };
 int main(int argc, char*argv[]){
 date today;
	today.day=20;
	today.month=1;
	today.year=2025;
	today.display();
 return 0;
 }