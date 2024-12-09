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
		ofstream file("appointments.txt"); // Open a file to write appointment data
		if (file.is_open()) {
			for (int i = 0; i < appointmentCount; i++) {
				file << appointmentID[i] << "," << patientID[i] << ","
					<< doctorID[i] << "," << appointmentDate[i] << ","
					<< appointmentTime[i] << endl;
			}
			file.close(); // Close the file after saving
		}
		else {
			cout << "Error: Could not open file to save appointment data." << endl;
		}
	}

	void loadAppointments() {
		ifstream file("appointments.txt"); // Open the file for reading
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				int appID, patientIDInput, doctorIDInput;
				string date, time;

				size_t pos1 = line.find(',');
				size_t pos2 = line.find(',', pos1 + 1);
				size_t pos3 = line.find(',', pos2 + 1);
				size_t pos4 = line.find(',', pos3 + 1);

				appID = stoi(line.substr(0, pos1));
				patientIDInput = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
				doctorIDInput = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
				date = line.substr(pos3 + 1, pos4 - pos3 - 1);
				time = line.substr(pos4 + 1);

				appointmentID[appointmentCount] = appID;
				patientID[appointmentCount] = patientIDInput;
				doctorID[appointmentCount] = doctorIDInput;
				appointmentDate[appointmentCount] = date;
				appointmentTime[appointmentCount] = time;

				appointmentCount++; // Increase the count after loading an appointment
			}
			file.close(); // Close the file after loading
		}
		else {
			cout << "No previous appointment data found." << endl;
		}
	}
};
