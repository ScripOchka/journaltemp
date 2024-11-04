#include <struct.h>


bool operator==(const note& b)
{
	if (((*this).year == b.year) && ((*this).month == b.month) && ((*this).day == b.day) && ((*this).temp == b.temp)) return true;
	else return false;
}


bool operator!=(const note& b)
{
    return !((*this) == b);
}


bool operator < (const note& b)
{
	if ((*this).year > b.year) return false;
	if ((*this).year < b.year) return true;
	if ((*this).month < b.month) return true;
	if ((*this).month > b.month) return false;
	if ((*this).day > b.day) return false;
	if ((*this).day < b.day) return true;
	return true;
}

bool operator > (const note& b)
{
    return !(((*this) < b) && ((*this) != b));
}

void print_note()
{
	printf("%d Year\n ", (*this).year);
	printf("%d Month\n ", (*this).month);
	printf("%d Day\n ", (*this).day);
	printf("%lf Temperature\n ", (*this).temp);
	printf("\n");
}




