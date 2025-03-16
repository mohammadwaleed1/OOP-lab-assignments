#include<iostream>
using namespace std;
class student{
    protected:
    string name;
    int id;
    string course;
    public:
    void setvalues(int i,string n,string c){
        name=n;
        id=i;
        course=c;
    }
    void display1(){
        cout<<"name: "<<name<<endl;
        cout<<"id: "<<id<<endl;
        cout<<"course: "<<course<<endl;
    }
};
class mark: public student{
    protected:
    int *marks;
    int courses;
    public:
    void setarray(int n){
        courses=n;
        marks=new int[courses];
        cout<<"enter marks for courses:\n";
        for(int i=0;i<courses;i++){
            cin>>marks[i];
           
        }
    }
    void display(){
        cout<<"marks for "<<courses<<"courses are"<<endl;
        for(int i=0;i<courses;i++){
            cout<<marks[i];
            cout<<endl;
        }
    }
};
class result:public mark{
    protected:
    int total,avg;
    public:
    void totalnavg(){
        for(int i=0;i<courses;i++){
            total+=marks[i];
        }
        cout<<"total is: "<<total;
        cout<<"\naverege: "<<total/courses<<endl;
    }
};
int main(){
    result r1;
    r1.setvalues(207,"waleed","OOP and calculus");
    r1.setarray(2);
    r1.display1();
    r1.display();
    r1.totalnavg();
}