#include <iostream>
#include <vector>
#include "Flight.h"

using namespace std;

namespace WonderlandAirlineReservation {
	
	Flight::Flight(const std::string& originLocation,
		const std::string& destinationLocation,
		std::string departureDateTime,
		std::string arrivalDateTime)
		: mOriginLocation(originLocation),
		mDestinationLocation(destinationLocation),
		mDepartureDateTime(departureDateTime),
		mArrivalDateTime(arrivalDateTime)
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

	// Display Flight Details
	void Flight::display() const
	{
		cout << "Origin: " << getOriginLocation() << endl;
		cout << "Destination: " << getDestinationLocation() << endl;
		cout << "Departure Date/Time: " << getDepartureDateTime() << endl;
		cout << "Arrival Date/Time: " << getArrivalDateTime() << endl;
		cout << "Flight No.: " << getFlightNumber() << endl;
		cout << "Seat Capacity" <<getSeatCapacity() << endl;
		cout << endl;
	}
}