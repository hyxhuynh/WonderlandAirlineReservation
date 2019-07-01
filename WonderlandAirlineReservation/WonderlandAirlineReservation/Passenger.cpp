#include <iostream>
#include "Passenger.h"

using namespace std;

namespace WonderlandAirlineReservation {
	Passenger::Passenger(const std::string& firstName,
		const std::string& lastName,
		const std::string& contactInfo)
		: mFirstName(firstName), mLastName(lastName), mContactInfo(contactInfo)
	{
	}

	// First Name
	void Passenger::setFirstName(const string& firstName)
	{
		mFirstName = firstName;
	}

	const string& Passenger::getFirstName() const
	{
		return mFirstName;
	}

	// Last Name
	void Passenger::setLastName(const string& lastName)
	{
		mLastName = lastName;
	}

	const string& Passenger::getLastName() const
	{
		return mLastName;
	}

	// Contact Info
	void Passenger::setContactInfo(const string& contactInfo)
	{
		mContactInfo = contactInfo;
	}

	const string& Passenger::getContactInfo() const
	{
		return mContactInfo;
	}

	// Passenger ID
	void Passenger::setPassengerID(int passengerID) {
		mPassengerID = passengerID;
	}

	int Passenger::getPassengerID() const {
		return mPassengerID;
	}


	void Passenger::addFlightInfo(int flightNumber, int seatNumber) {
		PassengerFlightInfo flightInfo = PassengerFlightInfo(flightNumber, seatNumber);
		mFlightInfos.push_back(flightInfo);
	}

	void Passenger::displayFlightInfo() const {
		for (auto& flightInfo : mFlightInfos) {
			flightInfo.display();
		}
	}

	void Passenger::verifyByID()
	{
		mVerified = true;
	}

	bool Passenger::isVerified() const {
		return mVerified;
	}

	// Display Passenger Information
	void Passenger::display() const
	{
		cout << endl;
		cout << "Passenger: " << getLastName() << ", " << getFirstName() << endl;
		cout << "-------------------------" << endl;
		cout << "Contact Information (Phone/ Email): " << getContactInfo() << endl;
		cout << "Passenger ID: " << getPassengerID() << endl;
		cout << "Flights: " << endl;
		displayFlightInfo();
		cout << endl;
	}

}


