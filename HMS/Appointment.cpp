#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Appointment {
private:
	int appointmentID[100]; // Array to store appointment IDs
	int patientID[100]; // Array to store patient IDs (each appointment is linked to a patient)
	int doctorID[100]; // Array to store doctor IDs (each appointment is linked to a doctor)
	string appointmentDate[100]; // Array to store appointment dates
	string appointmentTime[100]; // Array to store appointment times
	int appointmentCount; // Number of appointments

public:
	Appointment() {
		appointmentCount = 0; // Initialize the appointment counter to 0
		loadAppointments(); // Load appointments when the program starts
	}

	void scheduleAppointment() {
		if (appointmentCount >= 100) {
			cout << "Error: Cannot schedule more appointments, the limit is reached." << endl;
			return;
		}

		int appID, patientIDInput, doctorIDInput;
		string date, time;

		cout << "Enter Appointment ID: ";
		cin >> appID;

		// Check for duplicate Appointment ID
		for (int i = 0; i < appointmentCount; i++) {
			if (appointmentID[i] == appID) {
				cout << "Error: An appointment with this ID already exists." << endl;
				return;
			}
		}

		appointmentID[appointmentCount] = appID;

		cout << "Enter Patient ID: ";
		cin >> patientIDInput;
		patientID[appointmentCount] = patientIDInput;

		cout << "Enter Doctor ID: ";
		cin >> doctorIDInput;
		doctorID[appointmentCount] = doctorIDInput;

		cin.ignore(); // To ignore the newline character left by cin
		cout << "Enter Appointment Date (DD/MM/YYYY): ";
		getline(cin, date);
		appointmentDate[appointmentCount] = date;

		cout << "Enter Appointment Time (HH:MM): ";
		getline(cin, time);
		appointmentTime[appointmentCount] = time;

		// Check if there is already an appointment scheduled at the same time
		for (int i = 0; i < appointmentCount; i++) {
			if (appointmentDate[i] == date && appointmentTime[i] == time) {
				cout << "Error: There is already an appointment at this time." << endl;
				return; // Stop if there is a conflict
			}
		}

		appointmentCount++; // Increment the appointment count
		saveAppointments(); // Save the updated appointment list to file
		cout << "Appointment scheduled successfully!" << endl;
	}

	void displayAppointments() {
		if (appointmentCount == 0) {
			cout << "No appointments scheduled." << endl;
			return;
		}

		cout << "\nScheduled Appointments:" << endl;
		for (int i = 0; i < appointmentCount; i++) {
			cout << "Appointment ID: " << appointmentID[i]
				<< ", Patient ID: " << patientID[i]
				<< ", Doctor ID: " << doctorID[i]
				<< ", Date: " << appointmentDate[i]
				<< ", Time: " << appointmentTime[i] << endl;
		}
	}

	void searchAppointment() {
		int appID;
		cout << "Enter Appointment ID to search: ";
		cin >> appID;

		bool found = false;
		for (int i = 0; i < appointmentCount; i++) {
			if (appointmentID[i] == appID) {
				cout << "Appointment ID: " << appointmentID[i]
					<< ", Patient ID: " << patientID[i]
					<< ", Doctor ID: " << doctorID[i]
					<< ", Date: " << appointmentDate[i]
					<< ", Time: " << appointmentTime[i] << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "No appointment found with ID " << appID << "." << endl;
		}
	}

	void cancelAppointment() {
		int appID;
		cout << "Enter Appointment ID to cancel: ";
		cin >> appID;

		bool found = false;
		for (int i = 0; i < appointmentCount; i++) {
			if (appointmentID[i] == appID) {
				// Shift all appointments down to remove the cancelled appointment
				for (int j = i; j < appointmentCount - 1; j++) {
					appointmentID[j] = appointmentID[j + 1];
					patientID[j] = patientID[j + 1];
					doctorID[j] = doctorID[j + 1];
					appointmentDate[j] = appointmentDate[j + 1];
					appointmentTime[j] = appointmentTime[j + 1];
				}
				appointmentCount--; // Decrease the count after cancellation
				saveAppointments(); // Save the updated appointment list to file
				cout << "Appointment cancelled successfully!" << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "No appointment found with ID " << appID << "." << endl;
		}
	}

	void saveAppointments() {
		ofstream outFile("appointments.txt"); // Open the file for writing

		if (!outFile) {
			cout << "Error: Could not open file for saving appointments." << endl;
			return; // Stop if the file cannot be opened
		}

		// Write all appointments to the file
		for (int i = 0; i < appointmentCount; i++) {
			outFile << appointmentID[i] << " "
				<< patientID[i] << " "
				<< doctorID[i] << " "
				<< appointmentDate[i] << " "
				<< appointmentTime[i] << endl;
		}

		outFile.close(); // Close the file
		cout << "Appointments saved successfully!" << endl;
	}

	void loadAppointments() {
		ifstream inFile("appointments.txt"); // Open the file for reading

		if (!inFile) {
			cout << "No existing appointments found. Starting fresh." << endl;
			return; // Stop if the file doesn't exist
		}

		appointmentCount = 0; // Reset appointment count to load fresh data

		// Read data from the file
		while (inFile >> appointmentID[appointmentCount] >> patientID[appointmentCount]
			>> doctorID[appointmentCount] >> appointmentDate[appointmentCount]
			>> appointmentTime[appointmentCount]) {
			appointmentCount++; // Increment appointment count for each appointment read
		}

		inFile.close(); // Close the file
		cout << "Appointments loaded successfully. Total appointments: " << appointmentCount << endl;
	}

};
