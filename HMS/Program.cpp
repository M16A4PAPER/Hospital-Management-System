#include <iostream>
#include "Billing1.cpp"
#include "AdmissionRecord1.cpp"
#include "Doctor.cpp"
#include "Patient.cpp"
#include "Appointment.cpp"

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
	Billing billingManager; // Create an instance of the Billing class
	int choice;

	do {
		cout << "\nBilling Menu:" << endl;
		cout << "1. Generate Bill" << endl;
		cout << "2. Display All Bills" << endl;
		cout << "3.Save Bills" << endl;
		cout << "4.Load Bills" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			billingManager.generateBill();
			break;
		case 2:
			billingManager.displayBills();
			break;
		case 3:
			billingManager.saveBills();
			break;
		case 4:
			billingManager.loadBills();
			break;
		case 0:
			cout << "Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
}

void admissionRecordOptions() {
	AdmissionRecord1 admissionManager; // Create an instance of AdmissionRecord1 class

	int choice;
	do {
		cout << "\nAdmission Record Options Menu:" << endl;
		cout << "1. Add Admission Record" << endl;
		cout << "2. Discharge Patient" << endl;
		cout << "3. Display All Admission Records" << endl;
		cout << "4. Save Records to File" << endl;
		cout << "5. Load Records from File" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			admissionManager.admitPatient();
			break;
		case 2:
			admissionManager.dischargePatient();
			break;
		case 3:
			admissionManager.displayRecords();
			break;
		case 4:
			admissionManager.saveRecords();
			break;
		case 5:
			admissionManager.loadRecords();
			break;
		case 0:
			cout << "Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
}

void appointmentOptions() {
	Appointment appointmentManager; // Create an instance of Appointment class

	int choice;
	do {
		cout << "\nAppointment Options Menu:" << endl;
		cout << "1. Schedule a New Appointment" << endl;
		cout << "2. Display All Appointments" << endl;
		cout << "3. Search for an Appointment by ID" << endl;
		cout << "4. Cancel an Appointment" << endl;
		cout << "0. Return to Main Menu" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			appointmentManager.scheduleAppointment();
			break;
		case 2:
			appointmentManager.displayAppointments();
			break;
		case 3:
			appointmentManager.searchAppointment();
			break;
		case 4:
			appointmentManager.cancelAppointment();
			break;
		case 0:
			cout << "Returning to Main Menu..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);
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
