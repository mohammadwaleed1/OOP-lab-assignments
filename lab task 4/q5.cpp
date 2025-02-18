#include<iostream>
using namespace std;
 class bank{
 	private:
 		double balance;
 	public:
 		void setbalance(double b){
 			if(b<0) cout<<"invalid balance";
 			else balance=b;
		}
		int getbalance(){
			return balance;
		}
		double addbalance(double add){
			balance+=add;
		}
 		double withdraw(double remove){
 			if(remove<balance) balance-=remove;
 			else cout<<"invalid input";
		 }
};
int main(){
	bank user1;
	double amount,credit,debit;
	cout<<"enter balance: ";
	cin>> amount;
	user1.setbalance(amount);
	cout<<"current balance is:"<< user1.getbalance();
	cout<<"enter credit amount: ";   
	cin>>credit;
	cout<<"new amount after credit: "<< user1.addbalance(credit);
	cout<<"enter debit amount:";
	cin>>debit;
	cout<<"new amoutn after debit is: "<< user1.withdraw(debit);
	
	
}