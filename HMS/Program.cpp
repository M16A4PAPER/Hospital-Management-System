#include <iostream>
#include "Billing1.cpp"
#include "AdmissionRecord1.cpp"
#include "Appointment1.cpp"
#include "Doctor.cpp"
#include "Patient.cpp"

using namespace std;

// Function prototypes

void billingOptions();
void admissionRecordOptions();
void appointmentOptions();
void doctorOptions();
void patientOptions();

int main() {
	cout << "Welcome to the Hospital Management System!" << endl;

	int choice;

	do {
		cout << "\nPlease select an option:" << endl;
		cout << "1. Billing Options" << endl;
		cout << "2. Admission Record Options" << endl;
		cout << "3. Appointment Options" << endl;
		cout << "4. Doctor Options" << endl;
		cout << "5. Patient Options" << endl;
		cout << "0. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			billingOptions();
			break;
		case 2:
			admissionRecordOptions();
			break;
		case 3:
			appointmentOptions();
			break;
		case 4:
			doctorOptions();
			break;
		case 5:
			patientOptions();
			break;
		case 0:
			cout << "Exiting the system. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}

void billingOptions() {
	cout << "Billing Options Menu" << endl;
	// Add functionality for billing operations
}

void admissionRecordOptions() {
	cout << "Admission Record Options Menu" << endl;
	// Add functionality for admission record operations
}

void appointmentOptions() {
	cout << "Appointment Options Menu" << endl;
	// Add functionality for appointment operations
}

void doctorOptions() {
	Doctor doctorManager; // Create an instance of Doctor class

	int choice;
	do {
		cout << "\nDoctor Options Menu:" << endl;
		cout << "1. Add Doctor" << endl;
		cout << "2. Assign Doctor to Patient" << endl;
		cout << "3. Display Doctor Consultation Statistics" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			doctorManager.addDoctor();
			break;
		case 2:
			doctorManager.assignDoctorToPatient();
			break;
		case 3:
			doctorManager.displayConsultationStatistics();
			break;
		case 0:
			cout << "Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
}

void patientOptions() {
	Patient patientManager; // Create an instance of Patient class

	int choice;
	do {
		cout << "\nPatient Options Menu:" << endl;
		cout << "1. Add Patient Details" << endl;
		cout << "2. Search for Patient Details" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			patientManager.addPatient();
			break;
		case 2:
			patientManager.searchPatient();
			break;
		case 0:
			cout << "Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
}


