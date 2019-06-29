
#include <iostream>
#include <stdexcept>
#include "Database.h"

using namespace std;

namespace WonderlandAirlineReservation {

	// Prime Database
	void Database::primeDatabase()
	{
		// Add a bunch of starter flights
		addFlight("Seattle", "Portland", "1/1/2019 9:00 AM", "1/1/2019 11:00 AM");
		addFlight("Seattle", "Portland", "1/1/2019 1:00 PM", "1/1/2019 3:00 PM");
		addFlight("Seattle", "St. Louis", "1/3/2019 9:00 PM", "1/4/2019 1:00 AM");
	}

	// Flights
	Flight& Database::addFlight(const std::string& originLocation,
		const std::string& destinationLocation,
		std::string departureDateTime,
		std::string arrivalDateTime)
	{
		Flight theFlight(originLocation, destinationLocation, departureDateTime, arrivalDateTime);
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


	// Display all flights
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

}
