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
		ofstream outFile("bills.txt"); // Open the file for writing

		if (!outFile) {
			cout << "Error: Could not open file for saving bills." << endl;
			return; // Stop if the file cannot be opened
		}

		// Write all bills to the file
		for (int i = 0; i < billCount; i++) {
			outFile << billingID[i] << " "
				<< patientID[i] << " "
				<< consultationFee[i] << " "
				<< additionalCharges[i] << endl;
		}

		outFile.close(); // Close the file
		cout << "All bills have been saved successfully." << endl;
	}

	void loadBills() {
		ifstream inFile("bills.txt"); // Open the file for reading

		if (!inFile) {
			cout << "No existing bills found. Starting fresh." << endl;
			return; // Stop if the file doesn't exist
		}

		billCount = 0; // Reset bill count to load fresh data

		// Read data from the file
		while (inFile >> billingID[billCount] >> patientID[billCount]
			>> consultationFee[billCount] >> additionalCharges[billCount]) {
			billCount++; // Increment bill count for each bill read
		}

		inFile.close(); // Close the file
		cout << "Bills loaded successfully. Total bills: " << billCount << endl;
	}

};

//Constructor in C++ is a special method that is invoked automatically at the time an object of a class is created.
// It is used to initialize the data members of new objects generally.
// The constructor in C++ has the same name as the class or structure.
// It constructs the values i.e. provides data for the object which is why it is known as a constructor.
