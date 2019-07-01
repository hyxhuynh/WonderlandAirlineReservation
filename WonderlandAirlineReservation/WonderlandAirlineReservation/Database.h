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
			std::string arrivalDateTime,
			int seatCapacity);
		Flight& getFlight(int flightNumber);

		void addReservation(Flight& flight);

		void showReservedFlights();

		void displayAll() const;

		void displayPassenger() const;

		bool isValidFlight(int flightNumber) const;

		bool isFlightReserved(int flightNumber) const;

		bool isValidPassenger(int passengerId) const;

	private:
		std::vector<Passenger> mPassengers;
		std::vector<Flight> mFlights;
		std::vector<int> mReservedFlights;
		int mNextPassengerID = kFirstPassengerID;
		int mNextFlightNumber = kFirstFlightNumber;
	};
}