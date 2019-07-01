#include <iostream>
#include <vector>
#include "Flight.h"

using namespace std;

namespace WonderlandAirlineReservation {
	
	Flight::Flight(const std::string& originLocation,
		const std::string& destinationLocation,
		std::string departureDateTime,
		std::string arrivalDateTime,
		int seatCapacity)
		: mOriginLocation(originLocation),
		mDestinationLocation(destinationLocation),
		mDepartureDateTime(departureDateTime),
		mArrivalDateTime(arrivalDateTime),
		mSeatCapacity(seatCapacity)
		{}

	// Origin Location 
	void Flight::setOriginLocation(const std::string& originLocation)
	{
		mOriginLocation = originLocation;
	}
	const std::string& Flight::getOriginLocation() const
	{
		return mOriginLocation; 
	}

	// Destination Location
	void Flight::setDestinationLocation(const std::string& destinationLocation)
	{
		mDestinationLocation = destinationLocation;
	}
	const std::string& Flight::getDestinationLocation() const
	{
		return mDestinationLocation;
	}

	// Departure Date and Time
	void Flight::setDepartureDateTime(std::string departureDateTime)
	{
		mDepartureDateTime = departureDateTime;
	}
	const std::string Flight::getDepartureDateTime() const
	{
		return mDepartureDateTime;
	}
	
	// Arrival Date and Time
	void Flight::setArrivalDateTime(std::string arrivalDateTime)
	{
		mArrivalDateTime = arrivalDateTime;
	}
	const std::string Flight::getArrivalDateTime() const
	{
		return mArrivalDateTime;
	}

	// Flight Number
	void Flight::setFlightNumber(int flightNumber)
	{
		mFlightNumber = flightNumber;
	}
	int Flight::getFlightNumber() const {
		return mFlightNumber;
	}

	// Seat Capacity
	void Flight::setSeatCapacity(int seatCapacity)
	{
		mSeatCapacity = seatCapacity;
	}

	int Flight::getSeatCapacity() const {
		return mSeatCapacity;
	}

	// Check if user-selected seat is available 
	bool Flight::isSeatAvailable(int seat) const {
		// user-selected seat must be within seat capacity
		if (seat < 1 || seat > mSeatCapacity) {
			return false;
		}

		// For each taken seat number in the vector mSeatsTaken
		for (int seatNumber : mSeatsTaken) {
			// Seat is not available (false) if it's contained within mSeatsTaken
			if (seat == seatNumber) {
				return false;
			}
		}

		// Once the loop completes and it never hit the condition inside, 
		// that means that the seat is available
		return true;
	}

	std::string Flight::getAvailableSeats() const {
		std::string availableSeats;

		// Used to identify whether we need to add a comma,
		// if its the first seat dont add a comma
		bool isFirstAvailableSeat = true;

		for (int i = 1; i <= mSeatCapacity; i++) {
			if (isSeatAvailable(i)) {

				// If its the first available seat dont add a comma
				// Otherwise add a comma before the number
				if (isFirstAvailableSeat) {
					availableSeats += std::to_string(i);
				}
				else {
					availableSeats += ", " + std::to_string(i);
				}

				isFirstAvailableSeat = false;
			}
		}

		return availableSeats;
	}

	std::string Flight::getReservedSeats() const {
		std::string reservedSeats;

		bool isFirstSeat = true;
		for (int seatNumber : mSeatsTaken) {
			if (isFirstSeat) {
				reservedSeats += std::to_string(seatNumber);
			}
			else {
				reservedSeats += ", " + std::to_string(seatNumber);
			}
			isFirstSeat = false;
		}

		return reservedSeats;
	}

	void Flight::showAvailableSeats() {
		cout << getAvailableSeats() << endl;
	}

	// Display Flight Details
	void Flight::display() const
	{
		cout << endl;
		cout << "Origin: " << getOriginLocation() << endl;
		cout << "Destination: " << getDestinationLocation() << endl;
		cout << "Departure Date/Time: " << getDepartureDateTime() << endl;
		cout << "Arrival Date/Time: " << getArrivalDateTime() << endl;
		cout << "Flight No.: " << getFlightNumber() << endl;
		cout << "Seat Capacity: " << getSeatCapacity() << endl;
		cout << "Reserved Seats: " << getReservedSeats() << endl;
		cout << "Available Seats: " << getAvailableSeats() << endl;
		cout << endl;
	}

	void Flight::reserveSeat(int seat) {
		mSeatsTaken.push_back(seat);
	}
}