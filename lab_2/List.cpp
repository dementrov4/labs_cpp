#include "List.h"

namespace buyer
{
    List::List()
    {
        head = tail = NULL;
        length = 0;
    }

    List::List(const List &list)
    {
        head = tail = NULL;
        length = 0;
        for (Node* temp = list.tail; temp != NULL; temp = temp->prev) {
            add(temp->data);
        }
    }

    List::~List()
    {
        Node *temp = head;
        Node *s_next;

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
        Node *temp = new Node;
        temp->next = NULL;
        temp->prev = NULL;
        temp->data = data;

        if (head == NULL)
        {
            head = tail = temp;
        }
        else if (strcmp(tail->data.getSurname(), temp->data.getSurname()) >= 0)
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
        else if (strcmp(head->data.getSurname(), temp->data.getSurname()) <= 0)
        {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else
        {
            for (Node *operating = tail; operating != NULL; operating = operating->prev)
            {
                if (strcmp(operating->data.getSurname(), temp->data.getSurname()) >= 0)
                {
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

    void List::remove(const char *key)
    {
        try
        {
            bool flag = true;
            for (Node *temp = tail; temp != NULL; temp = temp->prev)
            {
                if (strcmp(key, temp->data.getSurname()) == 0)
                {
                    flag = false;
                    if (temp->next == NULL)
                    {
                        tail = temp->prev;
                        delete temp->next;
                        temp->next = NULL;
                    }
                    else if (temp->prev == NULL)
                    {
                        head = temp->next;
                        delete temp;
                        head->prev = NULL;
                    }
                    else
                    {
                        temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                        delete temp;
                    }
                }
                break;
            }

            if (flag)
            {
                throw std::invalid_argument("removing error: bad key");
            }
            --length;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    void List::print()
    {
        for (Node *temp = tail; temp != NULL; temp = temp->prev)
        {
            std::cout << temp->data;
        }
    }

    void List::update(int id, const Data &data)
    {
        try
        {
            if (id > length - 1 || id < 0)
            {
                throw std::invalid_argument("updating error: bad id");
            }
            Node *temp = tail;
            for (int i = 0; i < id; ++i)
            {
                temp = temp->prev;
            }
            remove(temp->data.getSurname());
            add(data);
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    void List::load(const char *filename)
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

    void List::save(const char *filename)
    {
        std::ofstream file(filename);

        for (Node *temp = tail; temp != NULL; temp = temp->prev)
        {
            file << temp->data;
        }
        file.close();
    }

    Data List::searchAccountNumber(int key)
    {
        try
        {
            for (Node *temp = tail; temp != NULL; temp = temp->prev)
            {
                if (key == temp->data.getAccountNumber())
                {
                    std::cout << "Node with account number: " << key << " "
                              << "is founded in the list" << std::endl;
                    return temp->data;
                }
            }
            throw std::invalid_argument("That's key isn't founded");
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        Data empetyData;
        return empetyData;
    }

    List List::filterTown(const char *town, const char sign)
    {
        List filteredList;

        try
        {
            for (Node *temp = tail; temp != NULL; temp = temp->prev)
            {
                switch (sign)
                {
                case '>':
                    if (temp->data > town)
                    {
                        filteredList.add(temp->data);
                    }
                    break;
                case '<':
                    if (temp->data < town)
                    {
                        filteredList.add(temp->data);
                    }
                    break;
                case '=':
                    if (temp->data == town)
                    {
                        filteredList.add(temp->data);
                    }
                    break;
                default:
                    throw std::invalid_argument("Wrong sign");
                    break;
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }

        return filteredList;
    }
    
    List &List::operator=(const List &list)
    {
        if (this == &list)
            return *this;

        head = tail = NULL;
        length = 0; 

        for (Node* temp = list.tail; temp != NULL; temp = temp->prev) {
            add(temp->data);
        }

        return *this;
    }

    Data &List::operator[](const int id)
    {
        Node *temp = tail;

        for (int index = 0; index < id; ++index)
        {
            temp = temp->prev;
        }
        return temp->data;
    }
    
    List &List::operator+(const Data &data)
    {
        add(data);
        return *this;
    }

    List &operator+(const Data &data, List &list)
    {
        list.add(data);
        return list;
    }

    List &List::operator-(const int _accountNumber)
    {
        try
        {
            bool flag = true;
            for (Node *temp = tail; temp != NULL; temp = temp->prev)
            {
                if (temp->data.getAccountNumber() == _accountNumber)
                {
                    flag = false;
                    if (temp->next == NULL)
                    {
                        tail = temp->prev;
                        delete temp->next;
                        temp->next = NULL;
                    }
                    else if (temp->prev == NULL)
                    {
                        head = temp->next;
                        delete temp;
                        head->prev = NULL;
                    }
                    else
                    {
                        temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                        delete temp;
                    }
                    break;
                }
            }

            if (flag)
            {
                throw std::invalid_argument("removing error: bad key");
            }
            --length;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return *this;
    }
    List &operator-(const int _accountNumber, List &list)
    {
        try
        {
            bool flag = true;
            for (List::Node* temp = list.tail; temp != NULL; temp = temp->prev)
            {
                if (temp->data.getAccountNumber() == _accountNumber)
                {
                    flag = false;
                    if (temp->next == NULL)
                    {
                        list.tail = temp->prev;
                        delete temp->next;
                        temp->next = NULL;
                    }
                    else if (temp->prev == NULL)
                    {
                        list.head = temp->next;
                        delete temp;
                        list.head->prev = NULL;
                    }
                    else
                    {
                        temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                        delete temp;
                    }
                    break;
                }
            }

            if (flag)
            {
                throw std::invalid_argument("removing error: bad key");
            }
            --list.length;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        return list;
    }

    std::ostream &operator<<(std::ostream &out, const List &list)
    {
        for (List::Node *temp = list.tail; temp != NULL; temp = temp->prev)
        {
            out << temp->data;
        }
        return out;
    }

    std::ifstream &operator>>(std::ifstream &in, List &list)
    {
        while (in.good())
        {
            Data temp;
            in >> temp;
            list.add(temp);
        }
        return in;
    }

    void List::loadBinary(const char *filename)
    {
        std::ifstream file(filename, std::ios::binary);

        *this = {};

        Data data;
        char buffer[80];

        while (file.getline(buffer, 80, '\0'))
        {
            file.getline(buffer, 80, '\0');
            data.setSurname(buffer);

            file.getline(buffer, 80, '\0');
            data.setName(buffer);

            file.getline(buffer, 80, '\0');
            data.setTown(buffer);

            file.getline(buffer, 80, '\0');
            data.setStreet(buffer);

            file.getline(buffer, 80, '\0');
            data.setHouseNumber(atoi(buffer));

            file.getline(buffer, 80, '\0');
            data.setApartmentNumber(atoi(buffer));

            file.getline(buffer, 80, '\0');
            data.setAccountNumber(atoi(buffer));

            add(data);
        }
        file.close();
    }
    
    void List::saveBinary(const char *filename)
    {
        std::ofstream file(filename, std::ios::binary);

        for (Node* temp = tail; temp != NULL; temp = temp->prev)
        {
            file.write(temp->data.getSurname(), strlen(temp->data.getSurname()) + 1);

            file.write(temp->data.getName(), strlen(temp->data.getName()) + 1);

            file.write(temp->data.getTown(), strlen(temp->data.getTown()) + 1);

            file.write(temp->data.getStreet(), strlen(temp->data.getStreet()) + 1);

            char _houseNumber[20] = "";
            sprintf(_houseNumber, "%d", temp->data.getHouseNumber());
            file.write(_houseNumber, strlen(_houseNumber) + 1);

            char _apartmentNumber[20] = "";
            sprintf(_apartmentNumber, "%d", temp->data.getApartmentNumber());
            file.write(_apartmentNumber, strlen(_apartmentNumber) + 1);

            char _accountNumber[20] = "";
            sprintf(_accountNumber, "%d", temp->data.getAccountNumber());
            file.write(_accountNumber, strlen(_accountNumber) + 1);
        }

        file.close();
    }
} // namespace buyer