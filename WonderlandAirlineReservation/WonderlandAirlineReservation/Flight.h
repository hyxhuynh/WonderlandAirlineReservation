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
			std::string arrivalDateTime
			);

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


	private:
		std::string mOriginLocation;
		std::string mDestinationLocation;
		std::string mDepartureDateTime;
		std::string mArrivalDateTime;

		int mSeatCapacity = 1;
		int mFlightNumber = -1;

		
	};
}