#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

namespace buyer
{
class Data
{
private:
    char *surname;
    char *name;
    char *town;
    char *street;
    int houseNumber;
    int apartmentNumber;
    int accountNumber;

public:
    Data(
        const char *_surname = "",
        const char *_name = "",
        const char *_town = "",
        const char *_street = "",
        const int houseNumber = 0,
        const int apartmentNumber = 0,
        const int accountNumber = 0);
    Data(const Data &);

    char *getSurname() const { return surname; }
    char *getName() const { return name; }
    char *getTown() const { return town; }
    char *getStreet() const { return street; }
    int getHouseNumber() const { return houseNumber; }
    int getApartmentNumber() const { return apartmentNumber; }
    int getAccountNumber() const { return accountNumber; }

    Data &setSurname(const char *);
    Data &setName(const char *);
    Data &setTown(const char *);
    Data &setStreet(const char *);
    Data &setHouseNumber(const int);
    Data &setApartmentNumber(const int);
    Data &setAccountNumber(const int);

    Data &setData(
        const char *_surname = "",
        const char *_name = "",
        const char *_town = "",
        const char *_street = "",
        const int houseNumber = 0,
        const int apartmentNumber = 0,
        const int accountNumber = 0);

    Data &operator=(const Data &);

    bool operator>(const char *) const;
    bool operator<(const char *) const;
    bool operator==(const char *) const;

    friend std::ostream &operator<<(std::ostream &, const Data &);
    friend std::istream &operator>>(std::istream &, Data &);
};
} // namespace buyer
