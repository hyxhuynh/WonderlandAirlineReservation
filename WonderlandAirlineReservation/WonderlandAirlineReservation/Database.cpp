
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace WonderlandAirlineReservation {

	// Prime Database
	
	void Database::primeDatabase()
	{
		// Add a bunch of starter flights
		addFlight("Seattle", "Portland", "7/1/2019 9:00 AM", "7/1/2019 9:45 AM", 30);
		addFlight("Seattle", "Portland", "9/21/2019 1:00 PM", "9/21/2019 1:45 PM", 40);
		addFlight("Seattle", "St. Louis", "12/3/2019 9:00 PM", "12/4/2019 1:00 AM", 10);
	}

	// Flights
	Flight& Database::addFlight(const std::string& originLocation,
		const std::string& destinationLocation,
		std::string departureDateTime,
		std::string arrivalDateTime,
		int seatCapacity)
	{
		Flight theFlight(originLocation, destinationLocation, departureDateTime, arrivalDateTime, seatCapacity);
		theFlight.setFlightNumber(mNextFlightNumber++);
		mFlights.push_back(theFlight);

		return mFlights[mFlights.size() - 1];
	}

	Flight& Database::getFlight(int flightNumber)
	{
		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == flightNumber) {
				return flight;
			}
		}
		throw logic_error("No flight found.");
	}


	// Display all passenger
	void Database::displayAll() const
	{
		for (const auto& flight : mFlights) {
			flight.display();
		}
	}

	bool Database::isValidFlight(int flightNumber) const
	{
		for (auto& flight : mFlights) {
			if (flight.getFlightNumber() == flightNumber) {
				return true;
			}
		}
		return false;
	}


	// Passengers
	Passenger& Database::addPassenger(const std::string& firstName,
		const std::string& lastName,
		const std::string& contactInfo)
	{
		Passenger thePassenger(firstName, lastName, contactInfo);
		thePassenger.setPassengerID(mNextPassengerID++);
		mPassengers.push_back(thePassenger);

		return mPassengers[mPassengers.size() - 1];
	}

	Passenger& Database::getPassenger(int passengerID)
	{
		for (auto& passenger : mPassengers) {
			if (passenger.getPassengerID() == passengerID) {
				return passenger;
			}
		}
		throw logic_error("No passenger found.");
	}

	// Display all passengers
	void Database::displayPassenger() const
	{
		for (const auto& passenger : mPassengers) {
			// If the passenger is verified
			//if(passenger.isVerified())
			//	passenger.display();
			passenger.display();
		}
	}

	void Database::addReservation(Flight& flight) {
		if (!isFlightReserved(flight.getFlightNumber())) {
			mReservedFlights.push_back(flight.getFlightNumber());
		}
	}

	void Database::showReservedFlights() {
		cout << "Reserved Flights Information: " << endl;
		for (int flightNum : mReservedFlights) {
			cout << "-----------------------------";
			getFlight(flightNum).display();
			cout << "-----------------------------";
		}
	}

	bool Database::isFlightReserved(int flightNumber) const {
		for (int flightNum : mReservedFlights) {
			if (flightNum == flightNumber) {
				return true;
			}
		}
		return false;
	}

	bool Database::isValidPassenger(int passengerId) const {
		for (auto& passenger : mPassengers) {
			if (passenger.getPassengerID() == passengerId) {
				return true;
			}
		}
		return false;
	}
}
