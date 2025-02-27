#include <iostream>

using namespace std;

class Blend {
public:
    void blend() {
        cout << "Blending the fruits" << endl;
        for (int i = 0; i < 100; i++) { }

        cout << "Blending complete!" << endl;
    }
};


class Grind {
public:
    void grind() {
        cout << "Grinding the fruits" << endl;
        for (int i = 0; i < 100; i++) { }

        cout << "Grinding complete!" << endl;
    }
};
class JuiceMaker {
private:
    Blend blendProcess;  
    Grind grindProcess; 

public:
    void blendJuice() {
        blendProcess.blend(); 
    }

    void grindJuice() {
        grindProcess.grind(); 
    }
};
int main() {
    JuiceMaker juiceMaker;

    cout << "Starting juice making process" << endl;

    juiceMaker.blendJuice();
    juiceMaker.grindJuice();

    cout << "Juice is ready!" << endl;

    return 0;
}
