#include <stdio.h>

void plusMinus(int size, int values[]) 
{
    int count_up = 0;
    int count_down = 0;
    int count_zero = 0;

    for (int i = 0; i < size; i++) 
    {
        if (values[i] > 0) 
        {
            count_up++;
        } else if (values[i] < 0)
        {
            count_down++;
        } else 
        {
            count_zero++;
        }
    }

    float total = (float)size;
    float ratio_up = count_up / total;
    float ratio_down = count_down / total;
    float ratio_zero = count_zero / total;

    printf("%.6f\n", ratio_up);
    printf("%.6f\n", ratio_down);
    printf("%.6f\n", ratio_zero);
}

int main() {
    int size;
    scanf("%d", &size);

    int values[size];
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &values[i]);
    }
    plusMinus(size, values);

    return 0;
}
