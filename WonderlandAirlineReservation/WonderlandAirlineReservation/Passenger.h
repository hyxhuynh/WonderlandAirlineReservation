#pragma once
#include <string>
#include "PassengerFlightInfo.h"

namespace WonderlandAirlineReservation {

	class Passenger
	{
	public:
		Passenger() = default;
		Passenger(const std::string& firstName,
			const std::string& lastName, 
			const std::string& contactInfo);


		void display() const;
		void verifyByID();

		
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setContactInfo(const std::string& contactInfo);
		const std::string& getContactInfo() const;

		void setPassengerID(int passengerID);
		int getPassengerID() const;

		void addFlightInfo(int flightNumber, int seatNumber);
		void displayFlightInfo() const;

		bool isVerified() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		std::string mContactInfo;
		std::vector<PassengerFlightInfo> mFlightInfos;
		int mPassengerID = -1;
		bool mVerified = false;

	};
}