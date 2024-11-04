#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>

struct note
{
    int year;
    int month;
    int day;
    double temp;

    bool operator==(const note& b) const;
    bool operator!=(const note& b) const;
    bool operator < (const note& b) const;
    bool operator > (const note& b) const;
    void print_note() const;
};


#endif
