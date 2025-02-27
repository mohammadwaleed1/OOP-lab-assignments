#include<iostream>
#include<vector>
using namespace std;
class Car{
    private:
    string name;
    int id;
    public:
    Car(string n,int i): name(n),id(i){};
    string getname(){
        return name;
    }
    int getid(){
        return id;
    }
    void getdetails(){
        cout<<"name:"<<name<<"\nid:"<<id;
    }
};
class Garage{
    private:
    vector<Car*>cars; 
	public:
	 
    void parkcar(Car* car){
       cars.push_back(car);
    }
	void listcars(){
        for(int i=0 ;i<cars.size();i++){
            if(cars[i]){
            cars[i]->getdetails();}
            else cout<<"invalid pointer!";

        }
    }
	
};
int main() {
    Garage garage;
    {
    Car car1("Toyota", 101);
    Car car2("Ford", 102);
    Car car3("BMW", 103);

    garage.parkcar(&car1);
    garage.parkcar(&car2);
    garage.parkcar(&car3);

    cout << "List of parked cars in the garage:" << endl;
    garage.listcars(); 
}
	return 0;
}