#include "Typedefine.h"
#include<stdio.h>
#include "Conversions.h"
#include "Tables.h"
#include<iostream>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<ctype.h>
#include<cstring>
#define LL unsigned long long
#define h1t35h using
#define rocks namespace
#define theworld std;
#define SI(n) scanf("%d",&n);
#define SF(n) scanf("%f",&n);
#define SLL(n) scanf("%lld",&n);
#define SC(n) scanf("%c",&n);
#define PC(n) printf("%c",&n);
#define PI(n) printf("%d",n);
#define PF(n) printf("%f",n);
#define PLL(n) printf("%lld",n);
#define FOR(n) for(LL x=0;x<n;x++)
#define FORL(a,b) for(LL x=a;x<b;x++)
#define MAX(a,b) ( ((a) > (b)) ? (a) : (b) )
#define MIN(a,b) ( ((a) < (b)) ? (a) : (b) )

h1t35h rocks theworld;

int main()
{
    string nstr ("DX");
    int w;
    loadRegisterTables();
    string a=findRegisterBinary(nstr,w);
    cout<<endl<<w<<"\t a:"<<a;
    return 0;
}
