#include <iostream>
#include "AppointmentStatus1.cpp"
using namespace std;

class Appointment1 {
public:
    int appointmentId;
    int patientId;
    int doctorId;
    string date;
    AppointmentStatus status; // Enum for status

    // Constructor to initialize the class
    Appointment1(int id, int pId, int dId, string d, AppointmentStatus s)
        : appointmentId(id), patientId(pId), doctorId(dId), date(d), status(s) {}

    // Method to display the details
    void displayDetails() {
        cout << "Appointment ID: " << appointmentId
            << "\nPatient ID: " << patientId
            << "\nDoctor ID: " << doctorId
            << "\nDate: " << date
            << "\nStatus: " << (status == AppointmentStatus::Scheduled ? "Scheduled" : "Completed") << endl;
    }
};
