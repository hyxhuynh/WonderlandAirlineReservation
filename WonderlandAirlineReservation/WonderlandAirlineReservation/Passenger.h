#pragma once
#include <string>

namespace WonderlandAirlineReservation {

	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName,
			const std::string& lastName, 
			const std::string& contactInfo);

		void display() const;

		
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setContactInfo(const std::string& contactInfo);
		const std::string& getContactInfo() const;

		void setPassengerID(int passengerID);
		int getPassengerID() const;

		void setSeatNumber(int seatNumber);
		int getSeatNumber() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mContactInfo;
		int mSeatNumber = -1;
		int mPassengerID = -1;

	};
}