
#include <iostream>

using namespace std;

int main()
{
    int number = 851347;
    int number_reverse = 0;
    
    while(10*number/10 != 0){
        number_reverse = number%10;
        /* draw score number here, from left to right (<--)
        draw_number();
        
        and shift X to left by size of a new number in pixels
        */
        cout << number_reverse; // for test
        number = number/10;
        
    }

    return 0;
}
