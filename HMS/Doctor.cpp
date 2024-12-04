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

	// Function to add a new doctor
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

	// Function to save all doctors to a file
	void saveDoctors() {
		ofstream file("doctors.txt"); // Open a file for writing
		if (file.is_open()) {
			for (int i = 0; i < doctorCount; i++) {
				// Save each doctor's details to the file, separated by commas
				file << doctorID[i] << "," << doctorName[i] << ","
					<< specialization[i] << "," << consultations[i] << endl;
			}
			file.close(); // Close the file after writing
		}
		else {
			cout << "Error: Could not open file to save data." << endl;
		}
	}

	// Function to load doctors from the file
	void loadDoctors() {
		ifstream file("doctors.txt"); // Open the file for reading
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				// Extract doctor details from the line
				int id;
				string name, spec;
				int consultation;

				size_t pos1 = line.find(',');
				size_t pos2 = line.find(',', pos1 + 1);
				size_t pos3 = line.find(',', pos2 + 1);

				id = stoi(line.substr(0, pos1));
				name = line.substr(pos1 + 1, pos2 - pos1 - 1);
				spec = line.substr(pos2 + 1, pos3 - pos2 - 1);
				consultation = stoi(line.substr(pos3 + 1));

				doctorID[doctorCount] = id;
				doctorName[doctorCount] = name;
				specialization[doctorCount] = spec;
				consultations[doctorCount] = consultation;

				doctorCount++; // Increase the doctor count
			}
			file.close(); // Close the file after reading
		}
		else {
			cout << "No previous doctor data found." << endl;
		}
	}

	// Function to assign a doctor to a patient
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

	// Function to display consultation statistics for all doctors
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
};