#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Patient {
private:
	int patientID[100]; // Array to store patient IDs
	string patientName[100]; // Array to store patient names
	int patientAge[100]; // Array to store patient ages
	string diagnosis[100]; // Array to store diagnoses
	int patientCount; // Number of patients

public:
	// Constructor to initialize patientCount
	Patient() {
		patientCount = 0; // Start with no patients
		loadPatients(); // Load existing patient data from file
	}

	// Function to add a new patient
	void addPatient() {
		if (patientCount >= 100) {
			cout << "Error: Cannot add more patients, the limit is reached." << endl;
			return; // Stop if the maximum number of patients is reached
		}

		int id;
		cout << "Enter Patient ID: ";
		cin >> id;

		// Check if the patient ID already exists
		for (int i = 0; i < patientCount; i++) {
			if (patientID[i] == id) {
				cout << "Error: A patient with this ID already exists." << endl;
				return; // Stop if the patient ID is already used
			}
		}
		patientID[patientCount] = id;

		cin.ignore(); // To ignore the newline character left by cin
		string name;
		cout << "Enter Patient Name: ";
		getline(cin, name);
		if (name.empty()) {
			cout << "Error: Name cannot be empty." << endl;
			return; // Stop if name is empty
		}
		patientName[patientCount] = name;

		int age;
		cout << "Enter Patient Age: ";
		cin >> age;
		if (age <= 0) {
			cout << "Error: Age must be a positive number." << endl;
			return; // Stop if the age is invalid
		}
		patientAge[patientCount] = age;

		cin.ignore(); // To ignore the newline character left by cin
		string diag;
		cout << "Enter Diagnosis: ";
		getline(cin, diag);
		if (diag.empty()) {
			cout << "Error: Diagnosis cannot be empty." << endl;
			return; // Stop if diagnosis is empty
		}
		diagnosis[patientCount] = diag;

		patientCount++; // Increase the patient count

		savePatients(); // Save the updated patient list to the file
		cout << "Patient added successfully!" << endl;
	}

	// Function to save all patients to a file
	void savePatients() {
		ofstream file("patients.txt"); // Open a file for writing
		if (file.is_open()) {
			for (int i = 0; i < patientCount; i++) {
				// Save each patient's details to the file, separated by commas
				file << patientID[i] << "," << patientName[i] << ","
					<< patientAge[i] << "," << diagnosis[i] << endl;
			}
			file.close(); // Close the file after writing
		}
		else {
			cout << "Error: Could not open file to save data." << endl;
		}
	}

	// Function to load patients from the file
	void loadPatients() {
		ifstream file("patients.txt"); // Open the file for reading
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				// Extract patient details from the line
				int id, age;
				string name, diag;

				size_t pos1 = line.find(',');
				size_t pos2 = line.find(',', pos1 + 1);
				size_t pos3 = line.find(',', pos2 + 1);

				id = stoi(line.substr(0, pos1));
				name = line.substr(pos1 + 1, pos2 - pos1 - 1);
				age = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
				diag = line.substr(pos3 + 1);

				patientID[patientCount] = id;
				patientName[patientCount] = name;
				patientAge[patientCount] = age;
				diagnosis[patientCount] = diag;

				patientCount++; // Increase the patient count
			}
			file.close(); // Close the file after reading
		}
		else {
			cout << "No previous patient data found." << endl;
		}
	}

	// Function to search for a patient by ID
	void searchPatient() {
		int id;
		cout << "Enter Patient ID to search: ";
		cin >> id;

		bool found = false;
		for (int i = 0; i < patientCount; i++) {
			if (patientID[i] == id) {
				cout << "Patient ID: " << patientID[i] << endl;
				cout << "Name: " << patientName[i] << endl;
				cout << "Age: " << patientAge[i] << endl;
				cout << "Diagnosis: " << diagnosis[i] << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "No patient found with ID " << id << "." << endl;
		}
	}

	// Function to display all patients
	void displayPatients() {
		if (patientCount == 0) {
			cout << "No patients to display." << endl;
			return; // Stop if there are no patients
		}

		cout << "\nPatient List:" << endl;
		for (int i = 0; i < patientCount; i++) {
			cout << "Patient ID: " << patientID[i]
				<< ", Name: " << patientName[i]
				<< ", Age: " << patientAge[i]
				<< ", Diagnosis: " << diagnosis[i] << endl;
		}
	}
};