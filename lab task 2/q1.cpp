#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
int sum=0;
for (int i=1;i<argc;i++){
	int num=atoi(argv[i]);
    sum+=num;
}
cout<<"second largest"<<sum;


return 0;
}
