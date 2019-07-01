// WonderlandAirlineReservation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Database.h"

using namespace std;
using namespace WonderlandAirlineReservation;

int displayMenu();
void passengerInput(Database& db);

//void displayPassenger(Database& db);

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
			reservationDB.displayPassenger();
			break;
		case 3:
			flightReservation(reservationDB);
			break;
		case 4: 
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
	cout << "------------------------------" << endl;
	cout << "Welcome to Wonderland Airline Reservation!" << endl;
	cout << "Please select the following options:" << endl;
	cout << "------------------------------"<< endl;
	cout << "1. Input Passenger Information" << endl;
	cout << "2. Display Passenger and Flight Information" << endl;
	cout << "3. Reserve a flight/seat" << endl;
	cout << "4. Check reserved flights" << endl;
	//cout << "5. Display user ticket information" << endl;
	cout << "0. Exit" << endl;
	cout << endl;
	cout << "Your Selection: ";
	cin >> selection;
	cout << "------------------------------" << endl;
	cout << endl;

	return selection;
}

void passengerInput(Database& db)
{
	string firstName;
	string lastName;
	string phoneNumber;

	cout << endl;
	cout << "Please enter your first name" << endl;
	cin >> firstName ;
	cout << "Please enter your last name" << endl;
	cin >> lastName;
	cout << "Please enter your phone number" << endl;
	cin >> phoneNumber;
	db.addPassenger(firstName, lastName, phoneNumber);
}

/*
void displayPassenger(Database& db)
{
	int passengerID;

	cout << "Passenger ID? ";
	cin >> passengerID;

	try {
		Passenger& passenger = db.getPassenger(passengerID);
		 
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to verify passenger." << exception.what() << endl;
	}


} */



void flightReservation(Database& db) {
	int selectedFlightNumber;
	int selectedSeatNumber;
	int selectedPassengerId;

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Please choose from the following available flights by typing in the FLIGHT NUMBER:" << endl;
	// show flight info from DB
	db.displayAll();

	// continues to ask user for a flight until he/she enters a valid flight number
	bool foundFlight = false;
	while (!foundFlight) {
		cout << "Your Selection for Flight Number: ";
		cin >> selectedFlightNumber;
		foundFlight = db.isValidFlight(selectedFlightNumber);
		if (!foundFlight) {
			cout << endl;
			cout << "You have entered the wrong flight number. Please try again." << endl;
		}
	}
	cout << endl;
	cout << "You have selected flight " << selectedFlightNumber;

	// Get the selected flight
	Flight& f = db.getFlight(selectedFlightNumber);
	
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Please select available seats from the list below" << endl;
	
	// Show seat info from the flight
	f.showAvailableSeats();
	cout << endl;

	// Continue asking for seats until weve selected an available seat number
	bool foundSeat = false;
	while (!foundSeat) {
		cout << "Your Selection for Seat Number: ";
		cin >> selectedSeatNumber;
		foundSeat = f.isSeatAvailable(selectedSeatNumber);
		if (!foundSeat) {
			cout << endl;
			cout << "You have entered the wrong seat number. Please try again." << endl;
		}
	}

	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Please identify which passenger will be taking this seat by typing in the PASSENGER ID:" << endl;
	db.displayPassenger();
	bool foundPassenger = false;
	while (!foundPassenger) {
		cout << "Passenger ID of the person booking the flight: ";
		cin >> selectedPassengerId;
		foundPassenger = db.isValidPassenger(selectedPassengerId);
		if (!foundPassenger) {
			cout << endl;
			cout << "You have entered an invalid passenger ID. Please try again";
		}
	}
	Passenger& p = db.getPassenger(selectedPassengerId);

	cout << "****** You have selected seat " << selectedSeatNumber << " flight number " << selectedFlightNumber << " for passenger " << selectedPassengerId << ".******" << endl;
	f.reserveSeat(selectedSeatNumber);
	p.addFlightInfo(selectedFlightNumber, selectedSeatNumber);


	// save the users reservation to the DB
	db.addReservation(f);
}

void displayBookedFlight(Database& db) {
	db.showReservedFlights();
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
