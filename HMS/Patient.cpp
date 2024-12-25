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

	void savePatients() {
		ofstream outFile("patients.txt"); // Open file for writing

		if (!outFile) {
			cout << "Error: Could not open file for saving patients." << endl;
			return; // Stop if the file cannot be opened
		}

		// Write all patient data to the file
		for (int i = 0; i < patientCount; i++) {
			outFile << patientID[i] << " "
				<< patientName[i] << " "
				<< patientAge[i] << " "
				<< diagnosis[i] << endl;
		}

		outFile.close(); // Close the file
		cout << "Patients saved successfully!" << endl;
	}

	void loadPatients() {
		ifstream inFile("patients.txt"); // Open file for reading

		if (!inFile) {
			cout << "No existing patients found. Starting fresh." << endl;
			return; // Stop if the file doesn't exist
		}

		patientCount = 0; // Reset patient count to load fresh data

		// Read data from the file
		while (inFile >> patientID[patientCount]
			>> patientName[patientCount]
			>> patientAge[patientCount]
			>> diagnosis[patientCount]) {
			patientCount++; // Increment patient count for each patient read
		}

		inFile.close(); // Close the file
		cout << "Patients loaded successfully. Total patients: " << patientCount << endl;
	}
};