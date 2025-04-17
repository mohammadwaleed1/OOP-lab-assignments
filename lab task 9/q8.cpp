#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    virtual float getTuition(const string& status, int creditHours) = 0;
};

class GraduateStudent : public Student {
private:
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    float getTuition(const string& status, int creditHours) override {
        if (status == "undergraduate") return creditHours * 200;
        if (status == "graduate") return creditHours * 300;
        if (status == "doctoral") return creditHours * 400;
        return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("Artificial Intelligence in Medicine");

    string status = "graduate";
    int credits = 12;

    cout << "Research Topic: " << gs.getResearchTopic() << endl;
    cout << "Status: " << status << ", Credits: " << credits << endl;
    cout << "Tuition Fee: $" << gs.getTuition(status, credits) << endl;

    return 0;
}
