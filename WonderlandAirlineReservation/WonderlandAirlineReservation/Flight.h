#pragma once

#include <string>
#include <vector>

namespace WonderlandAirlineReservation {
	class Flight {
	public:
		Flight() = default;
		Flight(const std::string& originLocation,
			const std::string& destinationLocation,
			std::string departureDateTime,
			std::string arrivalDateTime,
			int seatCapacity);

		void display() const;


		void setOriginLocation(const std::string& originLocation);
		const std::string& getOriginLocation() const;

		void setDestinationLocation(const std::string& originLocation);
		const std::string& getDestinationLocation() const;

		void setDepartureDateTime(std::string departureDateTime);
		const std::string getDepartureDateTime() const;

		void setArrivalDateTime(std::string arrivalDateTime);
		const std::string getArrivalDateTime() const;

		void setFlightNumber(int flightNumber);
		int getFlightNumber() const;	

		void setSeatCapacity(int seatCapacity);
		int getSeatCapacity() const;

		bool isSeatAvailable(int seat) const;

		void showAvailableSeats();

		void reserveSeat(int seat);

		std::string getAvailableSeats() const;

		std::string getReservedSeats() const;

	private:
		std::string mOriginLocation;
		std::string mDestinationLocation;
		std::string mDepartureDateTime;
		std::string mArrivalDateTime;
		std::vector<int> mSeatsTaken;

		int mSeatCapacity = 1;
		int mFlightNumber = -1;

		
	};
}