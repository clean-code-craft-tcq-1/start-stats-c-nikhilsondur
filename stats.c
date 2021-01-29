#include "stats.h"
#ifdef NAN

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;
    
    float sum;
    int count = 0;
    
    if(setlength == 0)       //Condition to check for empty array and return NaN.
    {
    s.average = NAN;
    s.min = NAN;
    s.max = NAN;
   
    return s;
    }
    
    while(count < setlength) //using while loop to find the average.
    {
     sum+=numberset[count];   
     count+=1;
    }
    
    s.average = sum/setlength; //Calculating the average once the sum is found.
    
    int location = 0;  //initialising the location of the minimum value as the first element of array. This variable point to the minimum value in the array after the loop.
    
    for (count = 1; count < setlength; count++)     //Loop through to find the minimum value in the array by comparing and updating the location variable.
        if (numberset[count] < numberset[location])
            location = count;
    
    s.min = numberset[location];                    //the array member at the location value will be the minimum value.
    
    location = 0; // initialising location variable back to 0
    
    for (count = 1; count < setlength; count++)     //Loop through to find the maximum value in the array by comparing and updating the location variable.
       if (numberset[count] > numberset[location])
           location = count;
    
    s.max = numberset[location];                    //the array member at the location value will be the minimum value.
    
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
#endif
