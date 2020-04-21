#include "Data.h"

namespace buyer
{
Data::Data(const std::string _surname, const std::string _name, const std::string _town, const std::string _street, int _houseNumber, int _apartmentNumber, int _accountNumber)
{
    surname = _surname;
    name = _name;
    town = _town;
    street = _street;
    houseNumber = _houseNumber;
    apartmentNumber = _apartmentNumber;
    accountNumber = _accountNumber;
}

Data::Data(const Data &data)
{
    surname = data.getSurname();
    name = data.getName();
    town = data.getTown();
    street = data.getStreet();
    houseNumber = data.getHouseNumber();
    apartmentNumber = data.getApartmentNumber();
    accountNumber = data.getAccountNumber();
}

Data &Data::setSurname(const std::string _surname)
{
    surname = _surname;

    return *this;
}
Data &Data::setName(const std::string _name)
{
    name = _name;

    return *this;
}
Data &Data::setTown(const std::string _town)
{
    town = _town;

    return *this;
}
Data &Data::setStreet(const std::string _street)
{
    street = _street;

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

Data &Data::setData(const std::string _surname, const std::string _name, const std::string _town, const std::string _street, int _houseNumber, int _apartmentNumber, int _accountNumber)
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

    surname = data.getSurname();
    name = data.getName();
    town = data.getTown();
    street = data.getStreet();
    houseNumber = data.getHouseNumber();
    apartmentNumber = data.getApartmentNumber();
    accountNumber = data.getAccountNumber();

    return *this;
}

bool Data::operator>(const std::string _town) const
{
    return town > _town;
}
bool Data::operator<(const std::string _town) const
{
    return town < _town;
}
bool Data::operator==(const std::string _town) const 
{
    return town == _town;
}

std::ostream &
operator<<(std::ostream &out, const Data &sample)
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