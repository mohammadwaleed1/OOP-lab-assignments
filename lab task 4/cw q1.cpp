#include<iostream>
using namespace std;

class matrix{
	public:
		int rows;
		int cols;
		int **arr;

	matrix(int r=0,int c=0){
		rows=r;
		cols=c;
		arr=new int*[r];
		for(int i=0;i<r;i++){
			arr[i]=new int[c];
			for(int j=0;j<c;j++){
				arr[i][j]=2;
			}
		}
	}
	~matrix(){
	for(int i=0;i<rows;i++){
		delete[] arr[i];
	}
	delete[] arr;
}
int getrows(){
	return rows;
}
int getcols(){
	return cols;
}
void fill_values(){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>arr[i][j];
		}
	}
}
	int* value(int r,int c){
		return &arr[r][c];
	
	}

void display(){
	if(arr!= nullptr){
	
	for (int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
		cout<<arr[i][j]<<" ";
		}
	}

}
else cout<<"NULL";
}
matrix(matrix& other){
	rows=other.rows;
	cols=other.cols;
	arr=new int*[rows];
		for(int i=0;i<rows;i++){
			arr[i]=new int[cols];
			for(int j=0;j<cols;j++){
				arr[i][j]=0;
			}
		}
	cout<<"matrix B is "<<endl;
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			arr[i][j]=other.arr[i][j];
		}
	}
}
	matrix(matrix&& other) noexcept {
	rows=other.rows;
	cols=other.cols;
	arr= other.arr;
	other.arr = nullptr;
	
}
void fill(int a){
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			arr[i][j]=a;
		}
	}
}
matrix transpose(){
	matrix mat(cols,rows);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			mat.arr[j][i]=arr[i][j];
		}
	}
	return mat;
}

};

int main(){
	int r1,c1;
	int R1,C1,n;

    cout << "Enter rows for m1 :";
    cin >>r1;
	cout << "Enter cols for m1 :";
    cin >>c1;
	matrix A(r1,c1);

	
	cout<<"enter row and cols to find element in matrix 1:";
	cin>>R1;
	cin>>C1;
	A.fill(4);
	cout<<"answer is ";
	int ans=*(A.value(R1,C1));
	cout<<ans<<endl;
	matrix B=A;
	B.display();
	cout<<endl;
	matrix C=move(A);
	cout<<"matrix c is :"<<endl;
	C.display();
	cout<<endl<<"matrix A is:"<<endl;
	A.display();
	cout<<endl;
	matrix D=B.transpose();
	cout<<"tranpose of B is stored in D:"<<endl;
	D.display();
	

	
}