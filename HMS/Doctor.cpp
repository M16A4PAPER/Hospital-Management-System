#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Doctor {
private:
	int doctorID[100]; // Array to store doctor IDs
	string doctorName[100]; // Array to store doctor names
	string specialization[100]; // Array to store specializations
	int consultations[100]; // Array to store consultation counts
	int doctorCount; // Number of doctors

public:
	// Constructor to initialize doctorCount and consultations
	Doctor() {
		doctorCount = 0; // Start with no doctors
		for (int i = 0; i < 100; i++) {
			consultations[i] = 0; // Start consultations count at 0
		}
		loadDoctors(); // Load existing doctor data from file
	}

	void addDoctor() {
		if (doctorCount >= 100) {
			cout << "Error: Cannot add more doctors, the limit is reached." << endl;
			return; // Stop if the maximum number of doctors is reached
		}

		int id;
		cout << "Enter Doctor ID: ";
		cin >> id;

		// Check if the doctor ID already exists
		for (int i = 0; i < doctorCount; i++) {
			if (doctorID[i] == id) {
				cout << "Error: A doctor with this ID already exists." << endl;
				return; // Stop if the doctor ID is already used
			}
		}
		doctorID[doctorCount] = id;

		cin.ignore(); // To ignore the newline character left by cin
		string name;
		cout << "Enter Doctor Name: ";
		getline(cin, name);
		if (name.empty()) {
			cout << "Error: Name cannot be empty." << endl;
			return; // Stop if name is empty
		}
		doctorName[doctorCount] = name;

		string spec;
		cout << "Enter Specialization: ";
		getline(cin, spec);
		if (spec.empty()) {
			cout << "Error: Specialization cannot be empty." << endl;
			return; // Stop if specialization is empty
		}
		specialization[doctorCount] = spec;

		consultations[doctorCount] = 0; // Start with 0 consultations
		doctorCount++; // Increase the doctor count

		saveDoctors(); // Save the updated doctor list to the file
		cout << "Doctor added successfully!" << endl;
	}

	void assignDoctorToPatient() {
		if (doctorCount == 0) {
			cout << "Error: No doctors available." << endl;
			return; // Stop if no doctors are available
		}

		int id;
		cout << "Enter Doctor ID to assign: ";
		cin >> id;

		bool found = false;
		for (int i = 0; i < doctorCount; i++) {
			if (doctorID[i] == id) {
				consultations[i]++; // Increase the consultation count
				found = true;
				saveDoctors(); // Save updated consultation data to file
				cout << "Doctor " << doctorName[i] << " has been assigned to a patient." << endl;
				break;
			}
		}

		if (!found) {
			cout << "Error: No doctor found with ID " << id << "." << endl;
		}
	}

	void displayConsultationStatistics() {
		if (doctorCount == 0) {
			cout << "Error: No doctors in the system to display statistics." << endl;
			return; // Stop if no doctors are available
		}

		cout << "\nDoctor Consultation Statistics:" << endl;
		for (int i = 0; i < doctorCount; i++) {
			cout << "Doctor ID: " << doctorID[i]
				<< ", Name: " << doctorName[i]
				<< ", Specialization: " << specialization[i]
				<< ", Consultations: " << consultations[i] << endl;
		}
	}

	void saveDoctors() {
		ofstream outFile("doctors.txt"); // Open file for writing

		if (!outFile) {
			cout << "Error: Could not open file for saving doctors." << endl;
			return; // Stop if the file cannot be opened
		}

		// Write all doctor data to the file
		for (int i = 0; i < doctorCount; i++) {
			outFile << doctorID[i] << " "
				<< doctorName[i] << " "
				<< specialization[i] << " "
				<< consultations[i] << endl;
		}

		outFile.close(); // Close the file
		cout << "Doctors saved successfully!" << endl;
	}

	void loadDoctors() {
		ifstream inFile("doctors.txt"); // Open file for reading

		if (!inFile) {
			cout << "No existing doctors found. Starting fresh." << endl;
			return; // Stop if the file doesn't exist
		}

		doctorCount = 0; // Reset doctor count to load fresh data

		// Read data from the file
		while (inFile >> doctorID[doctorCount]
			>> doctorName[doctorCount]
			>> specialization[doctorCount]
			>> consultations[doctorCount]) {
			doctorCount++; // Increment doctor count for each doctor read
		}

		inFile.close(); // Close the file
		cout << "Doctors loaded successfully. Total doctors: " << doctorCount << endl;
	}
};