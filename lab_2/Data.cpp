#include "Data.h"

namespace buyer
{
    Data::Data(const char *_surname, const char *_name, const char *_town, const char *_street, int _houseNumber, int _apartmentNumber, int _accountNumber)
    {
        surname = new char[strlen(_surname) + 1];
        name = new char[strlen(_name) + 1];
        town = new char[strlen(_town) + 1];
        street = new char[strlen(_street) + 1];
        houseNumber = _houseNumber;
        apartmentNumber = _apartmentNumber;
        accountNumber = _accountNumber;

        strcpy(surname, _surname);
        strcpy(name, _name);
        strcpy(town, _town);
        strcpy(street, _street);
    }

    Data::Data(const Data &data)
    {
        surname = new char[strlen(data.getSurname()) + 1];
        name = new char[strlen(data.getName()) + 1];
        town = new char[strlen(data.getTown()) + 1];
        street = new char[strlen(data.getStreet()) + 1];
        houseNumber = data.getHouseNumber();
        apartmentNumber = data.getApartmentNumber();
        accountNumber = data.getAccountNumber();

        strcpy(surname, data.getSurname());
        strcpy(name, data.getName());
        strcpy(town, data.getTown());
        strcpy(street, data.getStreet());
    }

    Data &Data::setSurname(const char *_surname)
    {
        delete[] surname;

        surname = new char[strlen(_surname) + 1];
        strcpy(surname, _surname);

        return *this;
    }
    Data &Data::setName(const char *_name)
    {
        delete[] name;

        name = new char[strlen(_name) + 1];
        strcpy(name, _name);

        return *this;
    }
    Data &Data::setTown(const char *_town)
    {
        delete[] town;

        town = new char[strlen(_town) + 1];
        strcpy(town, _town);

        return *this;
    }
    Data &Data::setStreet(const char *_street)
    {
        delete[] street;

        street = new char[strlen(_street) + 1];
        strcpy(street, _street);

        return *this;
    }
    Data &Data::setHouseNumber(const int _houseNumber)
    {
        houseNumber = _houseNumber;
        return *this;
    }
    Data &Data::setApartmentNumber(const int _apartmentNumber)
    {
        apartmentNumber = _apartmentNumber;
        return *this;
    }
    Data &Data::setAccountNumber(const int _accountNumber)
    {
        accountNumber = _accountNumber;
        return *this;
    }

    Data &Data::setData(const char *_surname, const char *_name, const char *_town, const char *_street, int _houseNumber, int _apartmentNumber, int _accountNumber)
    {
        setSurname(_surname);
        setName(_name);
        setTown(_town);
        setStreet(_street);
        setHouseNumber(_houseNumber);
        setApartmentNumber(_apartmentNumber);
        setAccountNumber(_accountNumber);
        return *this;
    }

    Data &Data::operator=(const Data &data)
    {
        if (this == &data)
            return *this;

        surname = new char[strlen(data.getSurname()) + 1];
        name = new char[strlen(data.getName()) + 1];
        town = new char[strlen(data.getTown()) + 1];
        street = new char[strlen(data.getStreet()) + 1];
        houseNumber = data.getHouseNumber();
        apartmentNumber = data.getApartmentNumber();
        accountNumber = data.getAccountNumber();

        strcpy(surname, data.getSurname());
        strcpy(name, data.getName());
        strcpy(town, data.getTown());
        strcpy(street, data.getStreet());

        return *this;
    }

    bool Data::operator>(const char* _town) const
    {
        return strcmp(town, _town) > 1;
    }
    bool Data::operator<(const char* _town) const
    {
        return strcmp(town, _town) < -1;
    }
    bool Data::operator==(const char* _town) const
    {
        return strcmp(town, _town) == 0;
    }

    std::ostream &operator<<(std::ostream &out, const Data &sample)
    {
        out << "Buyer:" << std::endl
            << "Surname ----------- : " << sample.surname << std::endl
            << "Name -------------- : " << sample.name << std::endl
            << "Town -------------- : " << sample.town << std::endl
            << "Street ------------ : " << sample.street << std::endl
            << "House number ------ : " << sample.houseNumber << std::endl
            << "Apartment number -- : " << sample.apartmentNumber << std::endl
            << "Account number ---- : " << sample.accountNumber << std::endl
            << std::endl;
        return out;
    }

    std::istream &operator>>(std::istream &in, Data &sample)
    {
        char buffer[80];

        in.getline(buffer, 80);
        sample.setSurname(buffer);

        in.getline(buffer, 80);
        sample.setName(buffer);

        in.getline(buffer, 80);
        sample.setTown(buffer);

        in.getline(buffer, 80);
        sample.setStreet(buffer);

        in.getline(buffer, 80);
        sample.setHouseNumber(atoi(buffer));

        in.getline(buffer, 80);
        sample.setApartmentNumber(atoi(buffer));

        in.getline(buffer, 80);
        sample.setAccountNumber(atoi(buffer));

        return in;
    }

} // namespace buyer