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
		ofstream file("admission_records.txt");
		if (file.is_open()) {
			for (int i = 0; i < recordCount; i++) {
				file << recordId[i] << "," << patientId[i] << ","
					<< admissionDate[i] << "," << (dischargeDate[i].empty() ? "Not Discharged" : dischargeDate[i]) << endl;
			}
			file.close();
		}
		else {
			cout << "Error: Could not open file to save data." << endl;
		}
	}

	void loadRecords() {
		ifstream file("admission_records.txt");
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				size_t pos1 = line.find(',');
				size_t pos2 = line.find(',', pos1 + 1);
				size_t pos3 = line.find(',', pos2 + 1);

				recordId[recordCount] = stoi(line.substr(0, pos1));
				patientId[recordCount] = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
				admissionDate[recordCount] = line.substr(pos2 + 1, pos3 - pos2 - 1);
				dischargeDate[recordCount] = line.substr(pos3 + 1);
				if (dischargeDate[recordCount] == "Not Discharged") {
					dischargeDate[recordCount] = "";
				}
				recordCount++;
			}
			file.close();
		}
		else {
			cout << "No previous admission records found." << endl;
		}
	}
};
