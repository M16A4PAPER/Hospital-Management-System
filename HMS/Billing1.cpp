#include <iostream>
using namespace std;

class Billing {
public:
    int billingId;
    int patientId;
    double consultationFee;
    double additionalCharges;

    // Constructor to initialize the class
    Billing(int id, int pId, double fee, double charges)
        : billingId(id), patientId(pId), consultationFee(fee), additionalCharges(charges) {}

    // Method to calculate the total bill amount
    double getTotalAmount() const {
        return consultationFee + additionalCharges;
    }

    // Method to display the details
    void displayBill() const {
        cout << "Billing ID: " << billingId
            << "\nPatient ID: " << patientId
            << "\nConsultation Fee: " << consultationFee
            << "\nAdditional Charges: " << additionalCharges
            << "\nTotal Amount: " << getTotalAmount() << endl;
    }
};


