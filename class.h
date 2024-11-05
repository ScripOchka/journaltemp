#ifndef CLASS_H
#define CLASS_H
#include <iostream>
#include "struct.h"

class Weather
{
    public:
        class TemperatureProxy;
    protected:
        note *magazine;
        int size;
        int res;
        
    public:
        Weather();
        Weather(const int year1, const int month1, const int day1, const double temp1);
        Weather(const Weather& other);
        Weather &operator=(const Weather& other);
        ~Weather();
        bool operator==(const Weather &b) const;
        bool operator!=(const Weather &b) const;
        Weather operator+(const Weather& b);
        Weather& operator += (const Weather& b);
        TemperatureProxy operator()(const int year1, const int month1, const int day1);
        void add(const int year1, const int month1, const int day1, const double temp1);
        void rm(const int year, const int month, const int day, const double temp);
        void print_magazine(const int year1, const int month1, const int day1, const int year2, const int month2, const int day2) const;
        friend std::ostream& operator<<(std::ostream& out, const Weather& number);

    class TemperatureProxy {
      private:
        Weather& weather;
        int year, month, day;

      public:
        TemperatureProxy( Weather& weather, const int year, const int month, const int day):
            weather(weather),
            year(year),
            month(month), 
            day(day) {}

        TemperatureProxy& operator=(const double value){
            if (value > -273.15) {
                weather.add(year, month, day, value);
            }
            return *this;
        }
    };  
};

#endif
