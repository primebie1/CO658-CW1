#pragma once
#include<string>
namespace DataStruc
{
	enum SeatClass
	{
		First, Business, Economy 
	};
	class Seat
	{
	public:
		int GetSeatID() { return seatID; }
		int GetCustID() { return customerID; }
		std::string GetName() { return name; }
		bool GetDietReq() { return specDietaryReq; }
		Seat(std::string ID, SeatClass stclass);
		bool CheckBooked() { return customerID; }
		void BookSeat(int customerID, bool DietReq);
	private:
		int seatID;
		std::string name;
		int customerID;
		bool specDietaryReq = false;
		SeatClass seatClass;
	};
}


