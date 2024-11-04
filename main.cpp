#include "struct.h"
#include "class.h"


int main()
{
    Weather jour1;
    jour1(2024, 4, 24) = 15;
    jour1(2024, 6, 13) = 10;
    jour1(2024, 11, 8) = -4;
    jour1.add(2024, 12, 3, -303);
    jour1.rm(2024, 11, 8, -4);
    
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


