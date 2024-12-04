#include <iostream>
using namespace std;

class AdmissionRecord1 {
public:
    int recordId;
    int patientId;
    string admissionDate;
    string dischargeDate;

    // Constructor to initialize the class
    AdmissionRecord1(int id, int pId, string aDate, string dDate = "")
        : recordId(id), patientId(pId), admissionDate(aDate), dischargeDate(dDate) {}

    // Method to display the details
    void displayAdmission() const {
        cout << "Record ID: " << recordId
            << "\nPatient ID: " << patientId
            << "\nAdmission Date: " << admissionDate
            << "\nDischarge Date: " << (dischargeDate.empty() ? "Not Discharged" : dischargeDate) << endl;
    }
};
