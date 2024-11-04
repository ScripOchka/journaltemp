#include <iostream>
#include "class.h"

Weather::Weather()
{
	magazine = nullptr;
	size = 0;
	res = 0;
}


Weather::Weather(int year1, int month1, int day1, double temp1)
{
	note value;
	value.year = year1;
	value.month = month1;
	value.day = day1;
	value.temp = temp1;

	magazine = new note[8];
	magazine[0] = value;
	size = 1;
	res = 7;
}


Weather::Weather(const Weather& other)
{

	size = other.size;
	res = other.res;

	note* tempq = new note[other.size];
	for (int i = 0; i < size; i++) tempq[i] = other.magazine[i];
	magazine = tempq;
}


Weather &Weather::operator=(const Weather& other)
{
	if(&other == this) return *this;

	this-> ~Weather();

	size = other.size;
	res = other.res;

	note* tempq = new note[other.size];
	for (int i = 0; i < size; i++) tempq[i] = other.magazine[i];
	magazine = tempq;
	return *this;
}


Weather::~Weather()
{
	delete[] magazine;
}


bool Weather::operator==(const Weather &b)
{
	if((*this).size != b.size) return false;
	for(int i = 0; i < size; i++)
	{
		if((*this).magazine[i] != b.magazine[i]) return false;
	}
	return true;
}


bool Weather::operator!=(const Weather &b)
{
	if((*this).size != b.size) return true;
	for(int i = 0; i < size; i++)
	{
		if((*this).magazine[i] != b.magazine[i]) return true;
	}
	return false;
}


Weather Weather::operator+(const Weather& b)
{
	Weather c;

	c.size = (*this).size + b.size;
	c.magazine = new note[c.size];
	for(int i = 0; i < c.size; i++)
	{
		if (i < size ) c.magazine[i] = (*this).magazine[i];
		else c.magazine[i] = b.magazine[i - (*this).size];
	}

	return c;
}


Weather& Weather::operator += (const Weather& b)
{
	note * temp = new note[size + b.size];
	for(int i = 0; i < size + b.size; i++)
	{
		if (i < size) temp[i] = magazine[i];
		else temp[i] = b.magazine[i - size];
	}

	delete[] magazine;
	size += b.size;
	magazine = temp;
	return *this;
}

double &Weather::operator()(int year1, int month1, int day1)
        {
            add(year1, month1, day1, 0);
            return magazine[size-1].temp;
        }


void Weather::add(int year1, int month1, int day1, double temp1)
{
	if(temp1 > -273.15)
	{

		note value = {year1, month1, day1, temp1};

		if(res == 0)
		{
			int n_size = (size == 0 ? 8 : 3*size / 2);
			note* tempq = new note[n_size];
			for (int i = 0; i < size; i++) tempq[i] = magazine[i];
			tempq[size] = value;
			delete[] magazine;
			magazine = tempq;

			size++;
			res = n_size - size;
		}

		else
		{
			magazine[size] = value;
			res -= 1;
			size++;
		}
	}
}




void Weather::rm(int year, int month, int day, double temp)
{
	note value;
	value.year = year;
	value.month = month;
	value.day = day;
	value.temp = temp;

	int k;
	for(int i = 0; i < size; i++)
	{
		if(magazine[i] == value)
		{
			k = i;
			break;
		}
	}

	note* tempq = new note[size - 1];
	for(int i = 0; i < size - 1; i++)
	{
		if (i < k) tempq[i] = magazine[i];
		else tempq[i] = magazine[i+1];
	}

	delete[] magazine;
	magazine = tempq;
	size--;
}


void Weather::print_magazine(int year1, int month1, int day1, int year2, int month2, int day2) const
{
	note tempq;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (magazine[j] > magazine[j + 1])
			{

				tempq = magazine[j];
				magazine[j] = magazine[j + 1];
				magazine[j + 1] = tempq;
			}
		}
	}

	int ind = 0;
	while ((magazine[ind].year <= year1) && (magazine[ind].month <= month1) && (magazine[ind].day <= day1)) ind++;

	while ((magazine[ind].year <= year2) && (magazine[ind].month <= month2) && (magazine[ind].day <= day2))
	{
		printf("(%d, %d, %d, %lf)\n", magazine[ind].year, magazine[ind].month, magazine[ind].day, magazine[ind].temp);
		ind++;
	}
	printf("\n");
}


std::ostream& operator<<(std::ostream& out, const Weather& number)
{
	for(int i = 0; i < number.size; i++)
	{
		out << "(" << number.magazine[i].year << ", " << number.magazine[i].month << ", " << number.magazine[i].day << ", " << number.magazine[i].temp << ")" << std::endl;
	}
	return out;
}





