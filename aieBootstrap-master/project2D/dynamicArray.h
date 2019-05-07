#pragma once
#include "solidObject.h"
template <typename T>
class dynamicArray :public solidObject{
public:
	//constructor
	dynamicArray()
	{
		//std::cout << "constructor called\n";
		//m_data = new T[baseCapacity]; // ->pointer to the array
		//count = 0;						// -> how much is in use
		//capacity = baseCapacity;		// -> how much memory is allocated
		///*positionX = 0;
		/*positionY = -10;
		objectHeight = 0;
		objectRadius = 0;
		objectTexture = nullptr;
		objectWidth = 0;*/

	}

	//deconstructor
	~dynamicArray()
	{
		std::cout << "destructor called\n";
		delete m_data;
		m_data = nullptr;
		count = 0;
		capacity = 0;
	}
	//copy constructor
	dynamicArray(const dynamicArray& a_base)
	{
		std::cout << "copy constructor called\n";
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}
		count = a_base.count;	// -> how much is in use
		capacity = a_base.capacity;		// -> how much memory is allocated
		m_data = new T [a_base.capacity]; // ->pointer to the array

		for (size_t i = 0; i < capacity; i++)
		{
			m_data[i] = a_base.m_data[i];
		}
	}
	dynamicArray& operator = (const dynamicArray& a_obj)
	{
		std::cout << "copy assignment operator called\n";
		if (this == &a_obj)
		{
			return *this;
		}
		if (m_data)
		{
			delete[] m_data;
			m_data = nullptr;
		}

		T* newArray = new T[a_obj.capacity];

		delete[] m_data;
		m_data = nullptr;

		count = a_obj.count;	// -> how much is in use
		capacity = a_obj.capacity;		// -> how much memory is allocated
		m_data = new T[a_obj.capacity]; // ->pointer to the array

		for (size_t i = 0; i < capacity; i++)
		{
			this->m_data[i] = a_obj.m_data[i];
		}
	}

//	void grow()
//	{
	//	capacity *= 2;
	//	T* newLocation = new T[capacity]; // creates new location
	//	for (size_t i = 0; i < count; i++)
	//	{
	//		newLocation[i] = m_data[i]; // deep copy of the data
	//	}
	//	delete m_data; //delete old storage
	//	m_data = newLocation; // move to new storage
	//};

	//add data
	void push(T num)
	{
		if (count == capacity) // if the capacity is full
		{
			grow();
		}
		m_data[count] = num;
		count++;

	}
	//remove data
	void pop()
	{
		if (count > 0)
			count--;
	}
	//element count
	size_t counter()
	{
		std::cout << "the count is: " << count << "\n";
		return count;
	}
	//capacity count
	size_t maxCap()
	{
		std::cout << "the max capacity is: " << capacity << "\n";
		return capacity;
	}
	//clearing the array
	void clear()
	{
		delete m_data;
		m_data = new T[baseCapacity]; // ->pointer to the array
		count = 0;						// -> how much is in use
		capacity = baseCapacity;		// -> how much memory is allocated
	}
	//add a elements to the middle of the array
	void addMiddle(T add, int space)
	{
		if ((count + 1) >= capacity) // if the capacity is reached
		{
			grow();
		}

		for (size_t i = (count + 1); i > (space - 1); i--)
		{
			m_data[i + 1] = m_data[i];// moves the values of the array one across
		}

		m_data[space] = add; // puts in the new value
		count++;
	}
	void addMultiple(const T whatToAdd[], int howManyNumbers, int where)
	{
		while ((count + howManyNumbers) >= capacity) // if the capacity is reached
		{
			grow();
		}

		for (size_t i = (count - 1); i >= (where - 1); --i)
		{
			m_data[i + howManyNumbers] = m_data[i];// moves the values of the array across
		}

		size_t j = 0;
		for (size_t i = (where - 1); i < (where - 1) + howManyNumbers; i++, j++)
		{
			m_data[i] = whatToAdd[j];// moves the values of the array one across
		}
		count += howManyNumbers;
	}
	//remove an element form the middle of the array
	void removeMiddle(int where, int amount = 1)
	{

		for (size_t i = (where - 1); i < (capacity); i++)
		{
			m_data[i] = m_data[i + amount];// moves the values of the array one across
		}
		count -= amount;
	}
	//writing out the numbers
	void writeBetween(int firstSpot, int secondSpot)
	{
		if (count > 0)
		{
			for (int i = (firstSpot - 1); i < secondSpot; i++)
			{
				std::cout << m_data[i] << "\n";

			}
		}
	}
	void writeAll()
	{
		if (count > 0)
		{
			for (int i = 0; i < count; i++)
			{
				std::cout << m_data[i] << "\n";
			}
		}
	}
	//removal of extra space
	void removeCap()
	{
		if (capacity > count)
			capacity = (count + 1);
	}


	void bubbleSort()
	{
		int counter = 1;
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < count; i++)
			{
				for (int k = 0; k < (count - counter); k++)
				{
					if (m_data[k] > m_data[k + 1])
					{
						int temp = m_data[k + 1];
						m_data[k + 1] = m_data[k];
						m_data[k] = temp;
					}
				}
			}
			counter++;
		}
	}

void ShakerSort()
	{
		bool swapped = false;
		int start = 0;
		int end = (count-1);
		while (!swapped)
		{
			swapped = true;
			//for loop going up the array
			for (int i = start; i < end; i++)
			{
				// compare all all elements
				if (m_data[i] > m_data[i + 1])
				{ // swap
					int temp = m_data[i + 1];
					m_data[i + 1] = m_data[i];
					m_data[i] = temp;
					swapped = false;
				}
			}
			end--;
			if (swapped)
				break;

			//for loop going down 
			for (int i = end; i >= start; i--)
			{
				// compare all all elements
				if (m_data[i] < m_data[i - 1])
				{ //swap
					int temp = m_data[i - 1];
					m_data[i - 1] = m_data[i];
					m_data[i] = temp;
					swapped = false;
				}
			}
			if (swapped)
				break;
			start++;
		}

	}

void insertSort()
{
	int key = 0;
	int j = 0;

	for (int i = 1; i < count; i++)
	{
		key = m_data[i];
		j = i - 1;
		while ((j >= 0) && (m_data[j] > key))
		{
			m_data[j + 1] = m_data[j];
			m_data[j] = key;
			j--;
		}
	}
}

size_t getCount()
{
	return count;
}




	//void player_bullet_update(float deltaTime)
	//{
	//	for(int i = 0; i < count ; i++)
	//	m_data[i].positionX += deltaTime * 300;
	//}




private:
	//pointer to storage

	//data type
	T* m_data;
	//current length
	size_t count = 0;
	//current capacity
	size_t capacity = 0;
	const size_t baseCapacity = 12;
};

