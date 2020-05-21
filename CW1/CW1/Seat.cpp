#include "Seat.h"
#include "HashTable.h"
namespace DataStruc
{
	Seat::Seat(std::string ID, SeatClass stclass)
	{
		seatClass = stclass;
		name = ID;
		seatID = HashTable::ProcessString(ID);
		customerID = 0;
	}
	void Seat::BookSeat(int customerID, bool DietReq)
	{
		this->customerID = customerID;
		specDietaryReq = DietReq;
	}
	

}

