// Nazario, Xavier
// October 23, 2025 ©
// Chapter 11 Programming Assignment
//  *** Challenges 7 AND 8 ***
// References:
//  Gaddis, Tony. Starting Out with C++ from Control
//	 Structures Through Objects. (10th Edition). Pearson Education (US), 2022
//  C++ Tutorial - Data Structures https://cplusplus.com/doc/tutorial/structures/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

// Declare Account Data Structure
//  I think goes before function prototypes?
struct Account
{
	string name;	// Holds Customer Name
	string address;	// Holds Address
	string city;	// Holds City
	string state;	// Holds State
	string zip;		// Holds Zip Code
	string phone;	// Holds Phone Number
	string email;	// Holds Email Address
	double accBal = 0.00;	// Holds Account Balance, Inititalized to 0.00, was getting garbage value
	string lastPayDate; // Holds Date of Last Payment by Customer
};

// Function Prototypes
//  CHECK PARAMETERS TO BE PASSED
//  Leave empty templates for now
void getAcc(Account customers[], int size);		// Get Customer Account
void updateAcc(Account customers[], int size);	// Updates Customer Account
void displayAcc(const Account customers[], int size);	// Displays Customer Account
void searchAcc(const Account customers[], int size);	// Searches Customer Account
void displayMenu();

// Main Function starts here
int main()
{
	// Step 1: Declare variable and array customers
	int choice; // Holds menu choice
	const int SIZE = 10; // Size of customer array
	Account customers[SIZE]; // Array of Account structure

	do {
		// Step 2: Display Menu
		//  ***MOVE INSIDE DO-WHILE LOOP***
		displayMenu();

		// Step 3: Get user choice
		//  Use do-while loop for menu selection
		//  ***MUST VALIDATE USER INPUT***
		cout << "Please enter a number 1 to 5: ";
		cin >> choice;
		cin.ignore(); // Clear input buffer

		// Validate user input
		//  Use switch statment: cases 1 to 5
		switch (choice)
		{
		case 1:
			getAcc(customers, SIZE);
			break;

		case 2:
			updateAcc(customers, SIZE);
			break;

		case 3:
			displayAcc(customers, SIZE);
			break;

		case 4:
			searchAcc(customers, SIZE);
			break;

		case 5:
			cout << "Exiting program. Goodbye!" << endl;
			break;

		default:
			cout << "Please enter a Number 1 to 5." << endl;
			break;
		}

		cout << endl;

	} while (choice != 5);

	cout << endl;

	// Return 0
	return 0;
}

// Function Definitions
void getAcc(Account customers[], int size)
{
	// Step 1: Get customer number
	//  Use n for variable
	int n;
	cout << "Enter customer number (1 to " << size << " to get.: ";
	cin >> n;

	// Validate customer number
	//  Use while loop
	while (n < 1 || n > size)
	{
		cout << "Invalid customer number. Please enter a number between 1 and " << size << ".: ";
		cin >> n;
	}
	cin.ignore(); // Clear input buffer

	// Convert n to zero-based index
	//  Use i for variable
	int i = n - 1;

	// Step 2: Get customer information
	//  Use do-while loop to get each field
	//  Validate each entry
	do {
		cout << "Please enter the customer's name: "; // Gets Name
		getline(cin, customers[i].name);

		// Validate name
		//  Use if statement
		if (customers[i].name.empty())
		{
			cout << "Name cannot be empty. Please enter a name." << endl;
		}
	} while (customers[i].name.empty());

	do {
		cout << "Please enter the customer's address: "; // Gets Address
		getline(cin, customers[i].address);

		// Validate address
		if (customers[i].address.empty())
		{
			cout << "Address cannot be empty. Please enter an address." << endl;
		}
	} while (customers[i].address.empty());

	do {
		cout << "Please enter the customer's city: "; // Gets City
		getline(cin, customers[i].city);

		// Validate city
		if (customers[i].city.empty())
		{
			cout << "City cannot be empty. Please enter a city." << endl;
		}
	} while (customers[i].city.empty());

	do {
		cout << "Please enter the customer's state: "; // Gets State
		getline(cin, customers[i].state);

		// Validate state
		if (customers[i].state.empty())
		{
			cout << "State cannot be empty. Please enter a state." << endl;
		}
	} while (customers[i].state.empty());

	do {
		cout << "Please enter the customer's zip code: "; // Gets Zip Code
		getline(cin, customers[i].zip);

		// Validate zip code
		if (customers[i].zip.empty())
		{
			cout << "Zip code cannot be empty. Please enter a zip code." << endl;
		}
	} while (customers[i].zip.empty());

	do {
		cout << "Please enter the customer's phone number: "; // Gets Phone Number
		getline(cin, customers[i].phone);

		// Validate phone number
		if (customers[i].phone.empty())
		{
			cout << "Phone number cannot be empty. Please enter a phone number." << endl;
		}
	} while (customers[i].phone.empty());
	
	do {
		cout << "Please enter the customer's email address: "; // Gets Email Address
		getline(cin, customers[i].email);

		// Validate email address
		if (customers[i].email.empty())
		{
			cout << "Email address cannot be empty. Please enter an email address." << endl;
		}
	} while (customers[i].email.empty());

	do {
		cout << "Enter Account Balance: $"; // Gets Account Balance
		cin >> customers[i].accBal;

		// Validate account balance
		if (customers[i].accBal < 0)
		{
			cout << "Account balance cannot be negative. Please enter a POSITIVE amount." << endl;
		}
	} while (customers[i].accBal < 0);

	do {
		cout << "Enter Date of Last Payment (MM/DD/YYYY): "; // Gets Date of Last Payment
		getline(cin, customers[i].lastPayDate);

		// Validate date of last payment
		if (customers[i].lastPayDate.empty())
		{
			cout << "Date of last payment cannot be empty. Please enter a date." << endl;
		}
	} while (customers[i].lastPayDate.empty());

	// Step 3: Confirm information saved
	cout << "Customer information saved in slot number: #" << n << ".\n";
}

void updateAcc(Account customers[], int size)
{
	// Step 1: Get customer number to update 
	//  Use n for variable
	int n;
	cout << "Enter customer number (1 to " << size << ") to update.: ";
	cin >> n;

	// Validate customer number
	//  Use while loop
	while (n < 1 || n > size)
	{
		cout << "Invalid customer number. Please enter a number between 1 and " << size << ".: ";
		cin >> n;
	}

	cin.ignore(); // Clear input buffer

	// Convert n to zero-based index
	//  Use i for variable
	int i = n - 1;

	// Declare variable for to update
	//  Use s for variable
	string s;

	// Step 2: Update customer information
	//  Use Enter to skip update for fields
	//  Show current value for each field THEN prompt for new value, if changed
	cout << "Updating information for Customer #" << n << ":\n"; // Shows which customer is being updated
	
	cout << "Current Name: " << customers[i].name << endl;
	cout << "Enter new name or press Enter to keep current: "; // Gets Name, if changed
	getline(cin, s);

	// Validate and update name
	if (!s.empty()) {
		customers[i].name = s;
	}

	cout << "Current Address: " << customers[i].address << endl;
	cout << "Enter new address or press Enter to keep current: "; // Gets Address, if changed
	getline(cin, s);

	// Validate and update address
	if (!s.empty()) {
		customers[i].address = s;
	}

	cout << "Current City: " << customers[i].city << endl;
	cout << "Enter new city or press Enter to keep current: "; // Gets City, if changed
	getline(cin, s);

	// Validate and update city
	if (!s.empty()) {
		customers[i].city = s;
	}

	cout << "Current State: " << customers[i].state << endl;
	cout << "Enter new state or press Enter to keep current: "; // Gets State, if changed
	getline(cin, s);

	// Validate and update state
	if (!s.empty()) {
		customers[i].state = s;
	}

	cout << "Current Zip Code: " << customers[i].zip << endl;
	cout << "Enter new zip code or press Enter to keep current: "; // Gets Zip, if changed
	getline(cin, s);

	// Validate and update zip code
	if (!s.empty()) {
		customers[i].zip = s;
	}

	cout << "Current Phone Number: " << customers[i].phone << endl;
	cout << "Enter new phone number or press Enter to keep current: "; // Gets Phone, if changed
	getline(cin, s);

	// Validate and update phone number
	if (!s.empty()) {
		customers[i].phone = s;
	}

	cout << "Current Email Address: " << customers[i].email << endl;
	cout << "Enter new email address or press Enter to keep current: "; // Gets Email, if changed
	getline(cin, s);

	// Validate and update email address
	if (!s.empty()) {
		customers[i].email = s;
	}

	cout << "Current Account Balance: $" << fixed << setprecision(2) << customers[i].accBal << endl;
	cout << "Enter new account balance or press Enter to keep current: $"; // Gets Account Balance, if changed
	getline(cin, s);

	// Validate and update account balance
	if (!s.empty()) {
		double newBal = stod(s);
		if (newBal >= 0) {
			customers[i].accBal = newBal;
		} else {
			cout << "Account balance cannot be negative. Keeping current balance." << endl;
		}
	}

	cout << "Current Date of Last Payment: " << customers[i].lastPayDate << endl;
	cout << "Enter new date of last payment or press Enter to keep current: "; // Gets Date of Last Payment, if changed
	getline(cin, s);

	// Validate and update date of last payment
	if (!s.empty()) {
		customers[i].lastPayDate = s;
	}

	// Step 3: Confirm information updated
	cout << "Customer information updated successfully.\n";
}

void displayAcc(const Account customers[], int size)
{
	cout << endl;

	cout << "Current Customer Accounts" << endl;
	cout << "-----------------------------------------------" << endl;
	
	// Step 1: Display all customer accounts
	//  Use for loop to display each account and field
	for (int i = 0; i < size; i++)
	{
		cout << "Customer #" << (i + 1) << " Information:" << endl;
		cout << "Name: " << customers[i].name << endl;
		cout << "Address: " << customers[i].address << endl;
		cout << "City: " << customers[i].city << endl;
		cout << "State: " << customers[i].state << endl;
		cout << "Zip Code: " << customers[i].zip << endl;
		cout << "Phone Number: " << customers[i].phone << endl;
		cout << "Email Address: " << customers[i].email << endl;
		cout << fixed << setprecision(2);
		cout << "Account Balance: $" << customers[i].accBal << endl;
		cout << "Date of Last Payment: " << customers[i].lastPayDate << endl;
		cout << "-----------------------------------------------\n" << endl;
	}
}

void searchAcc(const Account customers[], int size)
{
	// Step 1: Get customer name to search
	//  Use custname for variable
	string custname;
	cout << "Enter customer name to search.: ";
	getline(cin, custname);

	// Convert custname to lowercase for case-insensitive search
	//  Use custnameLower for variable
	//  Use for loop to convert each character to lowercase
	string custNameLower = custname;
	for (char& c : custNameLower) {
		c = tolower(c);
	}

	// Declare boolean variable found and initialize to false
	bool found = false;

	// Step 2: Search for customer by name
	//  Use for loop to search each account
	for (int i = 0; i < size; i++)
	{
		//	Convert customer name from ACCOUNT structure to lowercase for comparison
		//  Use accNameLower for variable
		//  Use for loop to convert each character to lowercase
		string accNameLower = customers[i].name;
		for (char& c : accNameLower) {
			c = tolower(c);
		}
		
		// Check if customer name matches
		//  Use if statement
		//  Needs to be partial matches
		if (accNameLower.find(custNameLower) != string::npos && !custname.empty())
		{
			// Step 3: Display customer information if found
			//  Use found set to true in boolean variable
			found = true;
			cout << "Customer found:\n";
			cout << "Name: " << customers[i].name << endl;
			cout << "Address: " << customers[i].address << endl;
			cout << "City: " << customers[i].city << endl;
			cout << "State: " << customers[i].state << endl;
			cout << "Zip Code: " << customers[i].zip << endl;
			cout << "Phone Number: " << customers[i].phone << endl;
			cout << "Email Address: " << customers[i].email << endl;
			cout << fixed << setprecision(2);
			cout << "Account Balance: $" << customers[i].accBal << endl;
			cout << "Date of Last Payment: " << customers[i].lastPayDate << endl;
		}
	}

	// Step 4: If NOT found, display message
	if (!found)
	{
		cout << "Customer not found. Please enter a new name and try to search again.\n";
	}
}

void displayMenu()
{
	// Step 1: Display Options
	cout << "Please read carefully and select one of the options." << endl;
	cout << "You can choose from the following menu options." << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "1. Enter Customer Account" << endl;
	cout << "2. Update Customer Account" << endl;
	cout << "3. Display Customer Accounts" << endl;
	cout << "4. Search Customer Account" << endl;
	cout << "5. Exit" << endl;
	cout << "-----------------------------------------------" << endl;
}