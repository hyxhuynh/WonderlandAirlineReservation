// WonderlandAirlineReservation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"

using namespace std;
using namespace WonderlandAirlineReservation;

int displayMenu();
void passengerInput(Database& db);
void flightReservation(Database& db);
void displayBookedFlight(Database& db);

int main()
{
	Database reservationDB;
	reservationDB.primeDatabase();

	while (true) {
		int selection = displayMenu();
		switch (selection) {
		case 0:
			return 0;
		case 1:
			passengerInput(reservationDB);
			break;
		case 2:
			flightReservation(reservationDB);
			break;
		case 3: 
			displayBookedFlight(reservationDB);
			break;
		default:
			cerr << "Unknown option. Please try again." << endl;
			break;
		}
	}
	return 0;
}

int displayMenu()
{
	int selection;

	cout << endl;
	cout << "Welcome to Wonderland Airline Reservation!" << endl;
	cout << "Please select the following options:" << endl;
	cout << "------------------------------";
	cout << "1. Input Passenger Information" << endl;
	cout << "2. Reserve a flight" << endl;
	cout << "3. Check booked flights" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
	cout << "------------------------------";

	cin >> selection;

	return selection;
}

void passengerInput(Database& db)
{
	string firstName;
	string lastName;
	string phoneNumber;

	cout << "Please enter your first name" << endl;
	cin >> firstName ;
	cout << "Please enter your last name" << endl;
	cin >> lastName;
	cout << "Please enter your phone number" << endl;
	cin >> phoneNumber;

	db.addPassenger(firstName, lastName, phoneNumber);
}

void flightReservation(Database& db) {
	int selectedFlightNumber;
	int selectedSeatNumber;

	cout << "Please choose from the following available flights by typing in the Flight Number:";
	// show flight info from DB
	db.displayAll();

	// continues to ask user for a flight until he/she enters a valid flight number
	bool foundFlight = false;
	while (!foundFlight) {
		cin >> selectedFlightNumber;
		foundFlight = db.isValidFlight(selectedFlightNumber);
		if (!foundFlight) {
			cout << "You have entered the wrong flight number. Please try again.";
		}
	}
	cout << "You have selected flight " << selectedFlightNumber;

	cout << "Please select available seats from the list below" << endl;
	// Show seat info from DB
	cin >> selectedSeatNumber;
	// if statement for if the selected seat number is equal to the seat number in the database, seatsAvailable--)
	cout << "You have selected seat " << selectedFlightNumber;
	// else cout << "You have entered the wrong seat number. Please try again." 

	// save the users reservation to the DB
	// db.addReservationI( selectedFlightNumber, selectedSeatNumber )
}

void displayBookedFlight(Database& db) {

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
