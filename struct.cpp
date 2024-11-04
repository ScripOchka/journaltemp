#include "struct.h"
#include "class.h"


bool note::operator==(const note& b) const
{
	if (((*this).year == b.year) && ((*this).month == b.month) && ((*this).day == b.day) && ((*this).temp == b.temp)) return true;
	else return false;
}


bool note::operator!=(const note& b) const
{
    return !((*this) == b);
}


bool note::operator < (const note& b) const
{
        if(year != b.year) return year < b.year;
        if(month != b.month) return month < b.month;
        return day < b.day;
}

bool note::operator > (const note& b) const
{
    return !(((*this) < b) && ((*this) != b));
}

void note::print_note() const
{
	printf("%d Year\n ", (*this).year);
	printf("%d Month\n ", (*this).month);
	printf("%d Day\n ", (*this).day);
	printf("%lf Temperature\n ", (*this).temp);
	printf("\n");
}



