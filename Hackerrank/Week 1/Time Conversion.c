#include <stdio.h>

void timeConversion(char t[]) 
{
    int hh, mm, ss;
    char ampm[3];

 
    hh = (t[0] - '0') * 10 + (t[1] - '0');
    mm = (t[3] - '0') * 10 + (t[4] - '0');
    ss = (t[6] - '0') * 10 + (t[7] - '0');

   
    ampm[0] = t[8];
    ampm[1] = t[9];
    ampm[2] = '\0'; 
    
    if (ampm[0] == 'A' && hh == 12) 
    {
        hh = 0; // midnight 
    }
    if (ampm[0] == 'P' && hh != 12) 
    {
        hh += 12; // afternoon/evening 
    }

    printf("%02d:%02d:%02d\n", hh, mm, ss);
}

int main() 
{
    char time[11];
    scanf("%s", time);
    timeConversion(time);
    return 0;
}
