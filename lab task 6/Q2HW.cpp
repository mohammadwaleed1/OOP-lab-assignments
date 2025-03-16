#include<iostream>
using namespace std;
class vehicles{
    protected:
    double price;
    public:
    vehicles(double p){
        price=p;
    }
};
class car:public vehicles{
    protected:
    int capacity,doors;
    string fueltype;
    public:
    car(double p,int c,int d,string f):vehicles(p){
       capacity=c;
       fueltype=f;
       doors=d;
    }
    void display1(){
        cout<<"capacity: "<<capacity;
        cout<<"\ndoors: "<<doors;
        cout<<"\nfuel type: "<<fueltype;
        cout<<"\nprice: "<<price;
    }
};
class motorcycle:public vehicles{
    protected:
    int cylinder,gears,wheels;
    public:
    
    motorcycle(int c,int g,int w,double p):vehicles(p){
        cylinder=c;
        gears=g;
        wheels=w;
    }
    void display2(){
        cout<<"\ntitle: "<<cylinder;
        cout<<"\nwheels: "<<wheels;
        cout<<"\ngears: "<<gears;
        cout<<"\nprice: "<<price;
    }
};
class audi: public car{
    protected:
    string modeltype;
    public:
    audi(string n,int p ,int c, int d, string f):car(p,c,d,f){
        modeltype=n;
    }
    void display1(){
        cout<<modeltype<<endl;
        cout<<capacity<<endl;
        cout<<doors<<endl;
        cout<<fueltype<<endl;
        cout<<price<<endl;
    }

};
class yamaha: public motorcycle{
    protected:
    string maketype;
    public:
    yamaha(string n,int c,int g,int w,double p):motorcycle(c,g,w,p){
        maketype=n;
    }
    void display2(){
        cout<<maketype<<endl;
        cout<<cylinder<<endl;
        cout<<wheels<<endl;
        cout<<gears<<endl;
        cout<<price<<endl;
    }

};
int main(){
    audi R5("sports",5000,4,4,"petrol");
    yamaha yoyo("1200cc",2,4,2,4000);
    cout<<"R5 details:...\n";
    R5.display1();
    cout<<"\nyoyo details:....\n";
    yoyo.display2();
}
