#include <math.h>
#include <cstring>
#include"Conversions.h"
long long decimalToBinary(long long n)
{
    long long rem,i=1,binary=0;
    while (n!=0)
    {
        rem=n%2;
        n/=2;
        binary+=rem*i;
        i*=10;
    }
    return binary;
}
long long binaryToDecimal(long long n)
{
    long long decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(2,i);
        ++i;
    }
    return decimal;
}
long long hexToBinary(char hex[])
{
    long long i, length, decimal=0, binary=0;
    for(length=0; hex[length]!='\0'; ++length);
    for(i=0; hex[i]!='\0'; ++i, --length)
    {
        if(hex[i]>='0' && hex[i]<='9')
            decimal+=(hex[i]-'0')*pow(16,length-1);
        if(hex[i]>='A' && hex[i]<='F')
            decimal+=(hex[i]-55)*pow(16,length-1);
        if(hex[i]>='a' && hex[i]<='f')
            decimal+=(hex[i]-87)*pow(16,length-1);
    }
    /* At this point, variable decimal contains the hexadecimal number in decimal format. */

    i=1;
    while (decimal!=0)
    {
        binary+=(decimal%2)*i;
        decimal/=2;
        i*=10;
    }
    return binary;
}

void binaryTohex(long long n, char hex[])
{
    int i=0,decimal=0, rem;
    while (n!=0)
    {
        decimal += (n%10)*pow(2,i);
        n/=10;
        ++i;
    }

    /* At this point, variable decimal contains binary number in decimal format. */
    i=0;
    while (decimal!=0)
    {
        rem=decimal%16;
        switch(rem)
        {
        case 10:
            hex[i]='A';
            break;
        case 11:
            hex[i]='B';
            break;
        case 12:
            hex[i]='C';
            break;
        case 13:
            hex[i]='D';
            break;
        case 14:
            hex[i]='E';
            break;
        case 15:
            hex[i]='F';
            break;
        default:
            hex[i]=rem+'0';
            break;
        }
        ++i;
        decimal/=16;
    }
    hex[i]='\0';
    strrev(hex);
}
