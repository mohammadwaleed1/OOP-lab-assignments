#include<iostream>
using namespace std;
class books{
    protected:
    string genre;
    public:
    books(string n){
        genre=n;
    }
};
class derive1:public books{
    private:
    string title,author;
    public:
    
    derive1(string t,string a):books("novel"){
        title=t;
        author=a;
    }
    void display1(){
        cout<<"title: "<<title;
        cout<<"\nauthor: "<<author;
        cout<<"\ngenre: "<<genre;
    }
};
class derive2:public books{
    private:
    string title,author;
    public:
    
    derive2(string t,string a):books("narrative"){
        title=t;
        author=a;
    }
    void display2(){
        cout<<"\ntitle: "<<title;
        cout<<"\nauthor: "<<author;
        cout<<"\ngenre: "<<genre;
    }
};
int main(){
    derive1 d1("waleed","THE GREAT");
    derive2 d2("ali","THE ALIEN");
    cout<<"BOOK 1:\n";
    d1.display1();
    cout<<"\nBOOK 2:";
    d2.display2();
}