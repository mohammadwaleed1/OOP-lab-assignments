#include<iostream>
using namespace std;
class Engine{
	public:
	bool Isrunning;
	Engine(){
		cout<<"ENGINE CREATED\n";
	}
		void start(){
			cout<<"engine started\n";
			Isrunning=true;
		}
		void stop(){
			cout<<"engine stopped\n";
			Isrunning=false;
		}
	~Engine(){
		cout<<"engine destroyed\n";
	}
	
	
};
class car{
    private:
    Engine engine;
    public:
		car(){
            cout<<"car created\n";
			engine.start();
        	engine.stop();
    }
		
	
	~car(){
		cout<<"car destryoed\n";
	}
};
int main(){
	car c1;

	return 0;
}