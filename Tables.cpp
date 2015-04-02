#include "Tables.h"
#include "Conversions.h"
#include<fstream>
#include<string>
#include<iostream>
std::string Regs[8][4];
void loadRegisterTables(void)
{
    std::ifstream input;
    input.open("RegTables");
    for(int i=0;i<8;i++)
    {
        input>>Regs[i][0]>>Regs[i][1]>>Regs[i][2]>>Regs[i][3];
    }
}

std::string findRegisterBinary(std::string a,int &w)
{
    bool found=false;
    std::string ret_val;
    for(int i=0;i<8 && found!=true;i++)
    {
        if(Regs[i][1].compare(a)==0)
        {
            w=0;
            found=true;
            ret_val=Regs[i][0];
        }
        else if(Regs[i][2].compare(a)==0 || Regs[i][3].compare(a)==0)
        {
            w=1;
            found=true;
            ret_val=Regs[i][0];
        }
    }
    return ret_val;
}
