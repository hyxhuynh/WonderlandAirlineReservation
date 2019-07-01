#include <iostream>
#include "PassengerFlightInfo.h"

using namespace std;

namespace WonderlandAirlineReservation {
	PassengerFlightInfo::PassengerFlightInfo(
		const int flightNumber,
		const int seatNumber)
		: flightNumber(flightNumber), seatNumber(seatNumber)
	{
	}

	void PassengerFlightInfo::display() const {
		cout << "**************************************" << endl;
		cout << "Flight Number: " << flightNumber << endl;
		cout << "Seat Number: " << seatNumber << endl;
	}
}

