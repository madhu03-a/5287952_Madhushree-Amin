#include <stdio.h>

void miniMaxSum(int numbers[5]) {
    long sum = 0;
    int min = numbers[0];      
    int max = numbers[0];      

    int i = 0;
    while (i < 5) 
    {
        sum = sum + numbers[i];

        if (numbers[i] < min) 
        {
            min = numbers[i];
        }

        if (numbers[i] > max) 
        {
            max = numbers[i];
        }

        i++;
    }

    long minTotal = sum - max;  
    long maxTotal = sum - min;  

    printf("%ld %ld\n", minTotal, maxTotal);
}

int main() 
{
    int input[5];  
    int i = 0;
    while (i < 5) 
    {
        scanf("%d", &input[i]);
        i++;
    }

    miniMaxSum(input);

    return 0;
}

