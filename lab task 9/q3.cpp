#include <iostream>
#include <string>

using namespace std;

class Doctor;
class BillingStaff;

class PatientRecord {
private:
    string name;
    string id;
    string dateOfBirth;

    string medicalHistory;
    string currentTreatment;
    string billingDetails;

public:
    PatientRecord(string name, string id, string dob)
        : name(name), id(id), dateOfBirth(dob) {}

    string getPublicData() const {
        return "Patient Name: " + name + ", ID: " + id + ", DOB: " + dateOfBirth;
    }

private:
    string getMedicalData() const {
        return "Medical History: " + medicalHistory + "\nTreatment: " + currentTreatment;
    }

    void updateMedicalHistory(const string& history) {
        medicalHistory = history;
    }

    void updateTreatment(const string& treatment) {
        currentTreatment = treatment;
    }

    void addBillingDetails(const string& billing) {
        billingDetails = billing;
    }

    string getBillingDetails() const {
        return billingDetails;
    }

    friend class Doctor;
    friend class BillingStaff;
};

class Doctor {
public:
    void viewMedicalData(const PatientRecord& record) {
        cout << "\nDoctor accessing medical data:\n";
        cout << record.getMedicalData() << "\n";
    }

    void updateMedicalInfo(PatientRecord& record, const string& history, const string& treatment) {
        record.updateMedicalHistory(history);
        record.updateTreatment(treatment);
        cout << " Doctor updated medical history and treatment.\n";
    }
};

class BillingStaff {
public:
    void addBillingInfo(PatientRecord& record, const string& billing) {
        record.addBillingDetails(billing);
        cout << "Billing info updated.\n";
    }

    void viewBillingInfo(const PatientRecord& record) {
        cout << "\n Billing accessing billing info:\n";
        cout << "Billing: " << record.getBillingDetails() << "\n";
    }
};

class Receptionist {
public:
    void tryAccessSensitiveInfo(const PatientRecord& record) {
        cout << "\n Receptionist trying to access data...\n";
        cout << record.getPublicData() << "\n";
        cout << "Access to medical and billing details denied.\n";
    }
};

int main() {
    PatientRecord p1("John Doe", "P12345", "1990-01-01");

    Doctor doc;
    BillingStaff biller;
    Receptionist recep;

    doc.updateMedicalInfo(p1, "Diabetes, Hypertension", "Insulin, Diet Control");
    doc.viewMedicalData(p1);

    biller.addBillingInfo(p1, "$1200 due for treatment");
    biller.viewBillingInfo(p1);

    recep.tryAccessSensitiveInfo(p1);

    return 0;
}
