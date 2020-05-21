#include "HashTable.h"
#include <math.h>

namespace DataStruc
{
	HashTable::HashTable(int size)
	{
		this->size = size;
		data = new Seat * [size];
		for (int i = 0; i < size; i++)
		{
			data[i] = NULL;
		}

	}

	void HashTable::Insert(Seat* item)
	{
		int key = item->GetSeatID();
		int hash = HashFunction(key);
		//find available space
		while (data[hash] != NULL)
		{
			++hash;
			hash %= size;
		}
		data[hash] = item;
	}

	int HashTable::HashFunction(int key)
	{
		int calc = key % size;
		//handle negative hashes
		calc = std::abs(calc);		
		return calc;
	}

	Seat* HashTable::Find(int key)
	{
		int hash = HashFunction(key);
		while (data[hash] != NULL)
		{
			//check for matching key
			if (data[hash]->GetSeatID() == key)
			{
				return data[hash];
			}
			hash++;
			hash %= size;
		}
		//fallback value for none found
		return NULL;
	}

	Seat* HashTable::Delete(int key)
	{
		int hash = HashFunction(key);
		while (data[hash] != NULL)
		{
			//check for matching key
			if (data[hash]->GetSeatID() == key)
			{
				Seat* temp = data[hash];
				data[hash] = NULL;
				return temp;
			}
			hash++;
			hash %= size;
		}
		//fallback value for none found
		return NULL;
	}
	//process string name into integer key
	int HashTable::ProcessString(std::string in)
	{
		std::hash<std::string> hasher;

		return hasher(in);
	}
}

