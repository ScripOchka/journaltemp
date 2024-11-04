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
        Weather(int year1, int month1, int day1, double temp1);
        Weather(const Weather& other);
        Weather &operator=(const Weather& other);
        ~Weather();
        bool operator==(const Weather &b);
        bool operator!=(const Weather &b);
        Weather operator+(const Weather& b);
        Weather& operator += (const Weather& b);
        TemperatureProxy operator()(int year1, int month1, int day1);
        void add(int year1, int month1, int day1, double temp1);
        void rm(int year, int month, int day, double temp);
        void print_magazine(int year1, int month1, int day1, int year2, int month2, int day2) const;
        friend std::ostream& operator<<(std::ostream& out, const Weather& number);

    class TemperatureProxy {
      private:
        Weather& weather;
        int year, month, day;

      public:
        TemperatureProxy(Weather& weather, int year, int month, int day):
            weather(weather),
            year(year),
            month(month), 
            day(day) {}

        TemperatureProxy& operator=(double value) {
            if (value > -273.15) {
                weather.add(year, month, day, value);
            }
            return *this;
        }
    };  
};

#endif