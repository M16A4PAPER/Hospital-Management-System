#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AdmissionRecord1 {
private:
	int recordId[100];       // Array to store record IDs
	int patientId[100];      // Array to store patient IDs
	string admissionDate[100]; // Array to store admission dates
	string dischargeDate[100]; // Array to store discharge dates
	int recordCount;         // Number of records

public:
	// Constructor to initialize recordCount and load records from file
	AdmissionRecord1() {
		recordCount = 0; // Start with no records
		for (int i = 0; i < 100; i++) {
			dischargeDate[i] = ""; // Initialize discharge dates as empty
		}
		loadRecords(); // Load existing records from file
	}

	void admitPatient() {
		if (recordCount >= 100) {
			cout << "Error: Cannot admit more patients, the limit is reached." << endl;
			return;
		}

		cout << "Enter Record ID: ";
		cin >> recordId[recordCount];
		cout << "Enter Patient ID: ";
		cin >> patientId[recordCount];
		cin.ignore(); // To handle the newline character
		cout << "Enter Admission Date (DD/MM/YYYY): ";
		getline(cin, admissionDate[recordCount]);

		dischargeDate[recordCount] = ""; // Mark as not discharged
		recordCount++; // Increment record count

		saveRecords(); // Save the updated records to file
		cout << "Patient admitted successfully!" << endl;
	}

	void dischargePatient() {
		int id;
		cout << "Enter Record ID to discharge: ";
		cin >> id;

		bool found = false;
		for (int i = 0; i < recordCount; i++) {
			if (recordId[i] == id) {
				if (!dischargeDate[i].empty()) {
					cout << "Error: Patient is already discharged on " << dischargeDate[i] << "." << endl;
					return;
				}
				cin.ignore(); // Handle newline character
				cout << "Enter Discharge Date (DD/MM/YYYY): ";
				getline(cin, dischargeDate[i]);
				saveRecords(); // Save updated records to file
				cout << "Patient discharged successfully!" << endl;
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "Error: Record with ID " << id << " not found." << endl;
		}
	}

	void displayRecords() {
		if (recordCount == 0) {
			cout << "No admission records available." << endl;
			return;
		}

		cout << "\nAdmission Records:" << endl;
		for (int i = 0; i < recordCount; i++) {
			cout << "Record ID: " << recordId[i]
				<< ", Patient ID: " << patientId[i]
				<< ", Admission Date: " << admissionDate[i]
				<< ", Discharge Date: " << (dischargeDate[i].empty() ? "Not Discharged" : dischargeDate[i]) << endl;
		}
	}

	void saveRecords() {
		ofstream outFile("admission_records.txt"); // Open the file for writing

		if (!outFile) {
			cout << "Error: Could not open file for saving admission records." << endl;
			return; // Stop if the file cannot be opened
		}

		// Write all admission records to the file
		for (int i = 0; i < recordCount; i++) {
			outFile << recordId[i] << " "
				<< patientId[i] << " "
				<< admissionDate[i] << " "
				<< (dischargeDate[i].empty() ? "-" : dischargeDate[i]) << endl;
		}

		outFile.close(); // Close the file
		cout << "All admission records have been saved successfully." << endl;
	}

	void loadRecords() {
		ifstream inFile("admission_records.txt"); // Open the file for reading

		if (!inFile) {
			cout << "No existing admission records found. Starting fresh." << endl;
			return; // Stop if the file doesn't exist
		}

		recordCount = 0; // Reset the record count to load fresh data

		// Read data from the file
		while (inFile >> recordId[recordCount] >> patientId[recordCount]) {
			inFile.ignore(); // Handle the space between fields
			getline(inFile, admissionDate[recordCount], ' '); // Read until space
			getline(inFile, dischargeDate[recordCount]); // Read until the end of the line

			// If dischargeDate is "-", it means the patient is not discharged
			if (dischargeDate[recordCount] == "-") {
				dischargeDate[recordCount] = "";
			}

			recordCount++; // Increment record count for each record read
		}

		inFile.close(); // Close the file
		cout << "Admission records loaded successfully. Total records: " << recordCount << endl;
	}

};
