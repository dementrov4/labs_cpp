#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

namespace buyer
{
class Data
{
private:
    std::string surname;
    std::string name;
    std::string town;
    std::string street;
    int houseNumber;
    int apartmentNumber;
    int accountNumber;

public:
    Data(
        const std::string _surname = "",
        const std::string _name = "",
        const std::string _town = "",
        const std::string _street = "",
        const int houseNumber = 0,
        const int apartmentNumber = 0,
        const int accountNumber = 0);
    Data(const Data &);

    std::string getSurname() const { return surname; }
    std::string getName() const { return name; }
    std::string getTown() const { return town; }
    std::string getStreet() const { return street; }
    int getHouseNumber() const { return houseNumber; }
    int getApartmentNumber() const { return apartmentNumber; }
    int getAccountNumber() const { return accountNumber; }

    Data &setSurname(const std::string);
    Data &setName(const std::string);
    Data &setTown(const std::string);
    Data &setStreet(const std::string);
    Data &setHouseNumber(const int);
    Data &setApartmentNumber(const int);
    Data &setAccountNumber(const int);

    Data &setData(
        const std::string _surname = "",
        const std::string _name = "",
        const std::string _town = "",
        const std::string _street = "",
        const int houseNumber = 0,
        const int apartmentNumber = 0,
        const int accountNumber = 0);

    Data &operator=(const Data &);

    bool operator>(const std::string) const;
    bool operator<(const std::string) const;
    bool operator==(const std::string) const;

    friend std::ostream &operator<<(std::ostream &, const Data &);
    friend std::istream &operator>>(std::istream &, Data &);
};
} // namespace buyer
