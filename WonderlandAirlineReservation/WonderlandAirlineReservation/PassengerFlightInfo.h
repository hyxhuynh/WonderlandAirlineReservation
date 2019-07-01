#pragma once

#include <iostream>
#include <vector>

namespace WonderlandAirlineReservation {

	class PassengerFlightInfo {

	public:
		int flightNumber;
		int seatNumber;

		PassengerFlightInfo() = default;
		PassengerFlightInfo(
			const int flightNumber,
			const int seatNumber);


		void display() const;

	};
}