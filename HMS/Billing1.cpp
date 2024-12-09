#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Billing {
private:
	int billingID[100];           // Array to store billing IDs
	int patientID[100];           // Array to store patient IDs
	double consultationFee[100];  // Array to store consultation fees
	double additionalCharges[100]; // Array to store additional charges
	int billCount;                // Number of bills

public:
	// Constructor to initialize billCount and load existing bills from file
	Billing() {
		billCount = 0; // Start with no bills
		loadBills();   // Load existing bills from file
	}

	void generateBill() {
		if (billCount >= 100) {
			cout << "Error: Cannot generate more bills, the limit is reached." << endl;
			return; // Stop if the maximum number of bills is reached
		}

		cout << "Enter Billing ID: ";
		cin >> billingID[billCount];
		cout << "Enter Patient ID: ";
		cin >> patientID[billCount];
		cout << "Enter Consultation Fee: ";
		cin >> consultationFee[billCount];
		cout << "Enter Additional Charges: ";
		cin >> additionalCharges[billCount];

		billCount++;    // Increment bill count
		saveBills();    // Save the new bill to file
		cout << "Bill generated successfully!" << endl;
	}

	void displayBills() {
		if (billCount == 0) {
			cout << "No bills available to display." << endl;
			return; // Stop if there are no bills
		}

		cout << "\nBilling Records:" << endl;
		for (int i = 0; i < billCount; i++) {
			double totalAmount = consultationFee[i] + additionalCharges[i];
			cout << "Billing ID: " << billingID[i]
				<< ", Patient ID: " << patientID[i]
				<< ", Consultation Fee: " << consultationFee[i]
				<< ", Additional Charges: " << additionalCharges[i]
				<< ", Total Amount: " << totalAmount << endl;
		}
	}

	void saveBills() {
		ofstream file("billing_records.txt"); // Open file for writing
		if (file.is_open()) {
			for (int i = 0; i < billCount; i++) {
				// Save each bill's details in a comma-separated format
				file << billingID[i] << "," << patientID[i] << ","
					<< consultationFee[i] << "," << additionalCharges[i] << endl;
			}
			file.close(); // Close the file
		}
		else {
			cout << "Error: Could not open file to save data." << endl;
		}
	}

	void loadBills() {
		ifstream file("billing_records.txt"); // Open file for reading
		if (file.is_open()) {
			string line;
			while (getline(file, line)) {
				size_t pos1 = line.find(',');
				size_t pos2 = line.find(',', pos1 + 1);
				size_t pos3 = line.find(',', pos2 + 1);

				billingID[billCount] = stoi(line.substr(0, pos1));
				patientID[billCount] = stoi(line.substr(pos1 + 1, pos2 - pos1 - 1));
				consultationFee[billCount] = stod(line.substr(pos2 + 1, pos3 - pos2 - 1));
				additionalCharges[billCount] = stod(line.substr(pos3 + 1));

				billCount++; // Increment bill count
			}
			file.close(); // Close the file
		}
		else {
			cout << "No previous billing records found." << endl;
		}
	}
};
