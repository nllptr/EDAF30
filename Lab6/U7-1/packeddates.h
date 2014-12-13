#ifndef PACKEDDATES_H
#define PACKEDDATES_H

#include <stdexcept>

short int packDate(int year, int month, int day)
{
    short int packed = 0;

    if(year < 0 || year > 99) throw std::out_of_range("Year has to be within the range 0-99");
    year = year << 9;
    if(month < 1 || month > 12) throw std::out_of_range("Month has to be within the range 1-12");
    month = month << 5;
    if(day < 1 || day > 31) throw std::out_of_range("Day has to be within the range 1-31");
    packed = year | month | day;
    return packed;
}

void unpackDate(short int packedDate, int &year, int &month, int &day)
{
    int unpacked_year = (packedDate & 0b1111111000000000) >> 9;
    if(unpacked_year < 0 || unpacked_year > 99) throw std::invalid_argument("Packed date contained invald year.");
    year = unpacked_year;
    int unpacked_month = (packedDate & 0b111100000) >> 5;
    if(unpacked_month < 1 || unpacked_month > 12) throw std::invalid_argument("Packed date contained invalid month.");
    month = unpacked_month;
    int unpacked_day = (packedDate & 0b11111);
    if(unpacked_day < 1 || unpacked_day > 31) throw std::invalid_argument("Packed date contained invalid day.");
    day = unpacked_day;
}

#endif // PACKEDDATES_H
