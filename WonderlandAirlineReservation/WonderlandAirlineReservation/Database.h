#pragma once

#include <iostream>
#include <vector>
#include "Flight.h"
#include "Passenger.h"

namespace WonderlandAirlineReservation {
	const int kFirstPassengerID = 100000;
	const int kFirstFlightNumber = 1000;

	class Database
	{
	public:
		void primeDatabase();

		Passenger& addPassenger(const std::string& firstName,
			const std::string& lastName,
			const std::string& contactInfo);
		// maybe getting passenger to add to vector???
		Passenger& getPassenger(int passengerId);

		Flight& addFlight(const std::string& originLocation,
			const std::string& destinationLocation,
			std::string departureDateTime,
			std::string arrivalDateTime);
		Flight& getFlight(int flightNumber);

		void displayAll() const;

		bool isValidFlight(int flightNumber) const;

	private:
		std::vector<Passenger> mPassengers;
		std::vector<Flight> mFlights;
		int mNextPassengerID = kFirstPassengerID;
		int mNextFlightNumber = kFirstFlightNumber;
	};
}