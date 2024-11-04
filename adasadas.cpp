#include <iostream>


struct note
{
    int year;
    int month;
    int day;
    double temp;


    //Оператор сравнения для наблюдений
    bool operator==(const note& b)
    {
        if (((*this).year == b.year) && ((*this).month == b.month) && ((*this).day == b.day) && ((*this).temp == b.temp)) return true;
        else return false;
    }
    
    //Оператор неравенства для наблюдений
    bool operator!=(const note& b)
    {
        if (((*this).year == b.year) && ((*this).month == b.month) && ((*this).day == b.day) && ((*this).temp == b.temp)) return false;
        else return true;
    }
    
    //Оператор меньше
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
        
    //Оператор больше
    bool operator > (const note& b)
    {
        if ((*this).year < b.year) return false;
        if ((*this).year > b.year) return true;
        if ((*this).month > b.month) return true;
        if ((*this).month < b.month) return false;
        if ((*this).day < b.day) return false;
        if ((*this).day > b.day) return true;
        return true;
    }
        
    //Oператор присваивания для записей наблюдений

    
    void print_note()
    {
        printf("%d Year\n ", (*this).year);
        printf("%d Month\n ", (*this).month);
        printf("%d Day\n ", (*this).day);
        printf("%lf Temperature\n ", (*this).temp);
        printf("\n");
    }
};    
        
        
class Weather
{
    private:
        note *magazine;
        int size;
        int res;
        
    public:
  
        Weather()
        {
            magazine = nullptr;
            size = 0;
            res = 0;
        }
        
        Weather(int year1, int month1, int day1, double temp1)
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
        
        Weather(const Weather& other)
        {
            
            size = other.size;
            res = other.res;
            
            note* tempq = new note[other.size];
            for (int i = 0; i < size; i++) tempq[i] = other.magazine[i];
            magazine = tempq;
        }
        
        
        Weather &operator=(const Weather& other)
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
        

        ~Weather()
        {
            delete[] magazine;
        }
        
        
        
        
        //Оператор сравнения для журналов
        bool operator==(const Weather &b) const
        {
            if((*this).size != b.size) return false;
            for(int i = 0; i < size; i++)
            {
                if((*this).magazine[i] != b.magazine[i]) return false;
            }
            return true;
        }
        
        //Оператор неравенства для журналов
        bool operator!=(const Weather &b) const
        {
            if((*this).size != b.size) return true;
            for(int i = 0; i < size; i++)
            {
                if((*this).magazine[i] != b.magazine[i]) return true;
            }
            return false;
        }
        
        //Оператор + для журналов
        Weather operator+(const Weather& b)
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
        
        //Оператор += для журналов
        Weather& operator += (const Weather& b)
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
        
            
        //Добавление наблюдения
        void add(int year1, int month1, int day1, double temp1)
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


        
        //Удаление наблюдения
        void rm(int year, int month, int day, double temp)
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
            
        //Вывод от даты до другой даты в порядке возрастания даты
        void print_magazine(int year1, int month1, int day1, int year2, int month2, int day2)
        {
            // Сортировка массива пузырьком
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
            //ind -= 1;
            
            while ((magazine[ind].year <= year2) && (magazine[ind].month <= month2) && (magazine[ind].day <= day2))
            {
                printf("(%d, %d, %d, %lf)\n", magazine[ind].year, magazine[ind].month, magazine[ind].day, magazine[ind].temp);
                ind++;
            }
            printf("\n");
        }
        
        
        friend std::ostream& operator<<(std::ostream& out, const Weather& number);
        
        
        
        
        
 
};


std::ostream& operator<<(std::ostream& out, const Weather& number)
{
    for(int i = 0; i < number.size; i++)
    {
        out << "(" << number.magazine[i].year << ", " << number.magazine[i].month << ", " << number.magazine[i].day << ", " << number.magazine[i].temp << ")" << std::endl;
    }
    return out;
}


int main()
{
    Weather jour1;
    jour1.add(2024, 4, 24, 15);
    jour1.add(2024, 6, 13, 10);
    jour1.add(2024, 11, 8, -4);
    //jour1(2024, 12, 3) = 233;
    
    Weather jour2 = jour1;
    //jour1.print_magazine(2023, 12, 12, 2024, 12, 27);
    
    std::cout << jour2 << std::endl;

    //jour1.rm(2024, 6, 13, 10);


    Weather jour3(2024, 12, 28, -34);
    jour3.add(2024, 4, 24, 15);
    jour3.add(2024, 6, 13, 10);
    jour3.add(2024, 12, 8, -4);
    
    Weather jour4 = jour3 + jour1;
    
    std::cout << jour4 << std::endl;
    
    
    
    if(jour2 == jour1) printf("Equal\n");
    else printf("Non-equal\n");
    
  return 0;
}

