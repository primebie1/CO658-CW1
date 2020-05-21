#pragma once
#include <vector>
#include <string>
#include "Seat.h"
namespace DataStruc
{
	class HashTable
	{
	private:
		Seat** data;
		int size;
		int HashFunction(int key);
	public:
		Seat* Find(int key);
		Seat* Delete(int key);
		void Insert(Seat* item);
		static int ProcessString(std::string key);
		HashTable(int size);
		int GetSize() { return size; }
	};

}

