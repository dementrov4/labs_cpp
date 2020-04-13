#include "List.h"

namespace buyer
{
	List::List()
	{
		head = tail = NULL;
		length = 0;
	}

	List::~List()
	{
		Node* temp = head;
		Node* s_next;

		while (temp != NULL)
		{
			s_next = temp->next;
			delete temp;
			temp = s_next;
		}

		length = 0;
	}

	void List::add(Data data)
	{
		Node* temp = new Node;
		temp->next = NULL;
		temp->prev = NULL;
		temp->data = data;
		
		if (head == NULL) {
			head = tail = temp;
		} else if (strcmp(tail->data.getSurname(), temp->data.getSurname()) >= 0) {
			temp->prev = tail;
			tail->next = temp; 
			tail = temp;
		} else if (strcmp(head->data.getSurname(), temp->data.getSurname()) <= 0) {
			temp->next = head;
			head->prev = temp;
			head = temp;
		} else {
			for (Node* operating = tail; operating != NULL; operating = operating->prev) {
				if (strcmp(operating->data.getSurname(), temp->data.getSurname()) >= 0) {
					operating->next->prev = temp;
					temp->next = operating->next;
					operating->next = temp;
					temp->prev = operating;
					break;
				}
			}
		}
		++length;
	} 

	void List::remove(const char* key)
	{
		try {
			bool flag = true;
			for (Node* temp = tail; temp != NULL; temp = temp->prev) {
				if (strcmp(key, temp->data.getSurname()) == 0) {
					flag = false;
					if (temp->next == NULL) {
						tail = temp->prev; 
						delete temp->next;
						temp->next = NULL;
					} else if (temp -> prev == NULL) {
						head = temp->next; 
						delete temp;
						head->prev = NULL;
					} else {
						temp->next->prev = temp->prev;
						temp->prev->next = temp->next;
						delete temp;
					}
				}
			}

			if (flag) {
				throw std::invalid_argument("removing error: bad key");
			}
			--length;
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	void List::print()
	{
		for (Node* temp = tail; temp != NULL; temp = temp->prev)
		{
			std::cout << temp->data;
		}
	}

	void List::update(int id, const Data& data)
	{
		try {
			if (id > length-1 || id < 0) {
				throw std::invalid_argument("updating error: bad id");
			}
			Node* temp = tail;
			for (int i = 0; i < id; ++i) {
				temp = temp->prev;
			}
			remove(temp->data.getSurname());
			add(data);
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	void List::load(const char* filename)
	{
		std::ifstream file(filename);
		while (file.good())
		{
			Data temp;
			file >> temp;
			add(temp);
		}
		file.close();
	}

	void List::save(const char* filename)
	{
		std::ofstream file(filename);

		for (Node* temp = tail; temp != NULL; temp = temp->prev)
		{
			file << temp->data;
		}
		file.close();
	}

	Data List::searchAccountNumber(int key) 
	{
		try {
			for (Node* temp = tail; temp != NULL; temp = temp->prev) {
				if (key == temp->data.getAccountNumber()) {
					std::cout << "Node with account number: " << key << " " 
							  << "is founded in the list" << std::endl;
					return temp->data;
				}
			}
			throw std::invalid_argument("That's key isn't founded");
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		Data empetyData; 
		return empetyData;
	}

	List List::filterTown(const char* town, const char sign) 
	{
		List filteredList;

		try {
			for (Node *temp = tail; temp != NULL; temp = temp->prev) {
				switch (sign)
				{
				case '>':
					if (strcmp(town, temp->data.getTown()) > 0) {
						filteredList.add(temp->data);
					}
					break;
				case '<':
					if (strcmp(town, temp->data.getTown()) < 0) {
						filteredList.add(temp->data);
					}
					break;
				case '=':
					if (strcmp(town, temp->data.getTown()) == 0) {
						filteredList.add(temp->data);
					}
					break; 
				case '~':
					if (strcmp(town, temp->data.getTown()) != 0) {
						filteredList.add(temp->data);
					}
					break;
				default:
					throw std::invalid_argument("Wrong sign");
					break;
				}
			}
		} catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}

		return filteredList;
	}
}