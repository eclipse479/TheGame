#pragma once
#pragma once
template <typename T>
class node
{
public:
	node<T>* m_next = nullptr;
	node<T>* m_prev = nullptr;

	T m_data = 0;
};

template <typename T>
class linkedList
{
private:
			int m_nodeCount = 0;
public:
	//sentinel nodes
	node<T>* m_start = nullptr;
	node<T>* m_end = nullptr;

	linkedList()
	{
		m_start = new node<T>();
		m_end = new node<T>();

		m_start->m_next = m_end;
		m_end->m_prev = m_start;

	}

	~linkedList()
	{
		node<T>* current = m_start->m_next;
		while (current != m_end)
		{
			node<T>* next = current->m_next;
			delete current;
			current = nullptr;
			current = next;

		}
		delete m_start;
		m_start = nullptr;
		delete m_end;
		m_end = nullptr;

	}

	void pushFront(int data) // put data in the front of the list
	{
		node<T>* current = new node<T>();
		current->m_data = data;


		//cross link at end
		current->m_prev = m_start;
		current->m_next = m_start->m_next;

		m_start->m_next = current;
		current->m_next->m_prev = current;
		m_nodeCount++;
	}
	void pushBack(int data) // put data at the back of the list
	{
		node<T>* current = new node<T>();
		current->m_data = data;


		//cross link at end
		current->m_next = m_end;
		current->m_prev = m_end->m_prev;
		m_end->m_prev = current;
		current->m_prev->m_next = current;
		m_nodeCount++;
	}

	void insert(const int a_data, const size_t a_index) // adds data to a chosen point in the list
	{
		//count to the index 
		node<T>* current = m_start->m_next;
		size_t counter = 0;
		while (counter < a_index && current != m_end)
		{
			++counter; 
			current = current->m_next;
		}

		//create the node
		node<T>*  newNode = new node<T>();
		newNode->m_data = a_data;

		//cross link at end
		newNode->m_next = current;
		newNode->m_prev = current->m_prev;
		current->m_prev = newNode;
		
		newNode->m_prev->m_next = newNode;
		//link
		m_nodeCount++;
	}

	node<T>* begin() //returns the start of the list
	{
		return m_start;
	}
	node<T>* end() // returns the end of the list
	{
		return m_end;
	}

	T first() //returns the  first element by value
	{
		begin()->m_next->m_data;
	}
	T last() // returns the last element by value
	{
		m_end->m_prev->m_data;
	}

	size_t count() // returns how mant nodes in the list there are
	{
		return m_nodeCount;
	}

	node<T>* erase(const size_t a_index) //removes an element
	{
		node<T>* current = m_start->m_next;
		size_t counter = 0;
		while (counter < a_index && current != m_end)
		{
			++counter;
			current = current->m_next;
		}
		node<T>* out_node = nullptr;

		if (current != m_end)
		{
			current->m_next->m_prev = current->m_prev;
			current->m_prev->m_next = current->m_next;
			delete current;
			current = nullptr;
		}
		m_nodeCount--;
		return out_node;
	}
	void remove(const T& a_value)   //removes all elements with a matching value
	{
		node<T>* current = m_start->m_next;
		size_t counter = 0;
		while (counter <= m_nodeCount && current != m_end)
		{
			if (a_value == current->m_data)
			{
				erase(counter);
			}
			else
			{
				++counter;
				current = current->m_next;
			}
		}
	}

	void popBack() //removes the last value in the list
	{
		if (m_nodeCount > 0)
			erase(m_nodeCount - 1);
	}

	void popFront() // removes the first element in the list
	{
		if (m_nodeCount > 0)
			erase(0);
	}

	bool empty() // returns if the list is empty or not
	{
		return !(bool(m_nodeCount));
	}

	void clear() //removes all elements in the list
	{
		while (m_nodeCount > 0)
		{
			erase(0);
		}
	}


	void bubbleSort()
	{
		node<T>* current = m_start;
		node<T>* placeHolder = m_start;
		int counter = m_nodeCount;
		int times = 0;
		bool sorted = false;
		while (!sorted)
		{
			sorted = true;
			for (int i = 0; i < counter; i++)
			{
				if (current->m_data > current->m_next->m_data)
				{
					placeHolder->m_data = current->m_next->m_data;
					current->m_next->m_data = current->m_data;
					current->m_data = placeHolder->m_data;
					sorted = false;
				}
			current = current->m_next;
			}
			current = m_start;
			counter--;
		}
	}


	void ShakerSort()
	{
		node<T>* current = m_start;
		node<T>* placeHolder = m_start;
		bool swapped = false;
		int start = 0;
		int end = (m_nodeCount - 1);
		while (!swapped)
		{
			swapped = true;
			//for loop going up the array
			for (int i = start; i < end; i++)
			{
				// compare all all elements
				if (current->m_data > current->m_next->m_data)
				{ // swap
					placeHolder->m_data = current->m_next->m_data;
					current->m_next->m_data = current->m_data;
					current->m_data = placeHolder->m_data;
					swapped = false;
				}
				current = current->m_next;
			}
			end--;
			if (swapped)
				break;

			//for loop going down 
			for (int i = end; i >= start; i--)
			{
				// compare all all elements
				if (current->m_data < current->m_prev->m_data)
				{ //swap
					placeHolder->m_data = current->m_prev->m_data;
					current->m_prev->m_data = current->m_data;
					current->m_data = placeHolder->m_data;
					swapped = false;
				}
				current = current->m_prev;
			}
			if (swapped)
				break;
			start++;
		}

	}


	void insertSort()
	{
		node<T>* current = m_start->m_next;
		node<T>* spare = m_start->m_next;
		int key = 0;

		while(current != m_end->m_prev)
		{
			key = current->m_next->m_data;
			spare = current;
			while ((spare != m_start) && (spare->m_data > key))
			{
				spare->m_next->m_data = spare->m_data;
				spare->m_data = key;
				spare = spare->m_prev;
			}
			current = current->m_next;
		
		}
	}


	void search()
	{
		node<T>* current = m_start;
		T numberToFind;
		std::cout << "What would you like to find?\n";
		std::cin >> numberToFind;
		bool found = false;
		int count = 0;
		while (current->m_next != end())
		{
			if (current->m_data == numberToFind)
			{
				std::cout << "the number was found and was in position: " << count << std::endl;
				found = true;
			}
			current = current->m_next;
			count++;
		}
		if (!found)
			std::cout << "the number was not found in the array.\n";
	}
};