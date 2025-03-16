#include<iostream>
using namespace std;
class bankaccount{
    protected:
	int accnum;
	float balance;
	public:
	bankaccount(int num,float bal){
		accnum=num;
		balance=bal;
	}
	void deposite(float amount){
		balance+=amount;
	}
	void withdraw(float amount){
		balance-=amount;
	}
	int getnum(){return accnum;}
	float getbalance(){return balance;}
	
	
	void setbalance(float a){
		balance=a;
	}
    void display() const {
        cout<< "Account Number: " << accnum << " ,Balance: " << balance<<endl;
    }
};
class savingsaccount:public bankaccount{
	float monthinterest;
	public:
	savingsaccount(float interest,int num,float bal):bankaccount(num,bal){
		monthinterest=interest;
    }
	void applyinterest(){
		balance+=monthinterest;
	}
    void display1() const {
        display();
        cout << "Monthly Interest is: " << monthinterest << endl;
    }
};
class CheckingAccount: public bankaccount{
	float over;
	public:
		CheckingAccount(float limit,int num,float bal):bankaccount(num,bal){
			over=limit;
		}
		void withdraw(float amount) {
			if (balance - amount >= over)
				balance -= amount;
			else
				cout << "Overdraft limit exceeded!" << endl;
		}
		void display2() const {
			display();
			cout << "Overdraft Limit: " << over << endl;
		}
};
class businessacc: public bankaccount{
	float tax;
	public:
		businessacc(float t,int num,float bal):bankaccount(num,bal){
			tax=t;
		}
		void deposit(float amount) {
			balance += amount - (amount * (tax / 100));
		}
		void display3() const {
			display();
			cout << "Corporate Tax is: " << tax<< endl;
		}
}; 
class User {
	protected:
		string name;
	public:
		User(string n) : name(n) {}
		void displayRole(){
			cout << name << " is a User." << endl;
		}
};
class Customer : public User {
	public:
		Customer(string n) : User(n) {}
		
		void deposit(bankaccount &acc, float amount) {
			acc.deposite(amount);
		}
		
		void withdraw(bankaccount&acc, float amount) {
			acc.withdraw(amount);
		}
		
		void displayRole() const {
			cout << name << " is a Customer." << endl;
		}
	};
class Employee : public User {
		public:
			Employee(string n) : User(n) {}
};
class Teller : public Employee {
	public:
		Teller(string n) : Employee(n) {}
		
		void freezeAccount(bankaccount &acc) {
			cout << "Account " << acc.getnum() << " has been frozen." << endl;
		}
		void deposit(bankaccount &acc, float amount) {
			acc.deposite(amount);
		}
		
		void withdraw(bankaccount &acc, float amount) {
			acc.withdraw(amount);
		}
		
		void displayRole(){
			cout << name << " is a Teller." << endl;
		}
};
class Manager : public Employee {
	public:
		Manager(string n) : Employee(n) {}
		
		void overrideLimits(bankaccount &acc, float newBalance) {
			acc.setbalance(newBalance);
			cout << "Manager has overridden account balance." << endl;
		}
		void deposit(bankaccount &acc, float amount) {
			acc.deposite(amount);
		}
		
		void withdraw(bankaccount &acc, float amount) {
			acc.withdraw(amount);
		}
		void freezeAccount(bankaccount &acc) {
			cout << "Manager has frozen account " << acc.getnum() << "." << endl;
		}
		
		void adjustOverdraftLimit(CheckingAccount &acc, float newLimit) {
			acc = CheckingAccount(acc.getnum(), acc.getbalance(), newLimit);
			cout << "Manager has adjusted overdraft limit." << endl;
		}
		
		void displayRole() const {
			cout << name << " is a Manager." << endl;
		}

	};
	int main() {
		savingsaccount sa(100, 2004, 2000);
		CheckingAccount ca(-5000, 2005, 1000);
		businessacc ba(500, 2006, 2500);
		
		Customer cust("Alice");
		Teller tell("Bob");
		Manager mgr("Charlie");
		
		cout << "Initial Account Details:" << endl;
		sa.display1();
		ca.display2();
		ba.display3();
		
		cout << "\nApplying Interest to Savings Account..." << endl;
		sa.applyinterest();
		sa.display1();
		
		cout << "\nTeller depositing to Checking Account..." << endl;
		tell.deposit(ca, 500);
		ca.display2();
		
		cout << "\nTeller withdrawing from Checking Account..." << endl;
		tell.withdraw(ca, 1000);
		ca.display2();
		
		cout << "\nTeller freezing Business Account..." << endl;
		tell.freezeAccount(ba);
		
		cout << "\nManager depositing to Savings Account..." << endl;
		mgr.deposit(sa, 1000);
		sa.display1();
		
		cout << "\nManager withdrawing from Checking Account..." << endl;
		mgr.withdraw(ca, 200);
		ca.display2();
		
		cout << "\nManager overriding Savings Account balance..." << endl;
		mgr.overrideLimits(sa, 5000);
		sa.display1();
		
		cout << "\nManager adjusting overdraft limit for Checking Account..." << endl;
		mgr.adjustOverdraftLimit(ca, 300);
		ca.display2();
		
		return 0;
	}
	