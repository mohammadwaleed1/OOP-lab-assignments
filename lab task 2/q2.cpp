#include<iostream>
using namespace std;

void* sum (int* arr,int size){
    // int *array =(int *)arr; will use this if we had arr in void to convert to int since here arr is in int so no need to use it
    static int summing=0;
    for(int i=0;i<size;i++){
        summing+= arr[i];
    }
    return (void*)&summing;
}
int main(int argc, char* argv[]){  
    int size= argc-1;
    int a[size];
    for(int i=0;i < size;i++){
        a[i]=atoi(argv[i+1]);
    }
    void* result = sum(a,size);
    cout<<"sum is:"<<*(int*)result;
} 
	
	
	
	
	