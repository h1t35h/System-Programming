#include "Typedefine.h"
#include<string>
#include<cctype>
#include<stdio.h>
#include<iostream>
#include<cstdlib>
typefun findmode(std::string instruction,std::string &MOD,std::string &MOV,std::string &D)
{
    typefun ret_val;
    type t1,t2;
    if(instruction[0]!='M'|| instruction[1]!='O' || instruction[2]!='V')
    {
        printf("Error Invalid Input\nExiting!!");
        exit(27);
    }
    else
    {
        std::string T1,T2;
        std::string::iterator i;
        i=instruction.begin();
        i=i+4;
        while(*i!=',')
        {
            T1.push_back(*i);
            i++;
        }
        i++;
        while(i!=instruction.end())
        {
            T2.push_back(*i);
            i++;
        }
        t1=findtype(T1);
        t2=findtype(T2);
    }
    if(t1==REGISTER && t2== REGISTER)
    {
        ret_val= REGISTER_REGISTER;
        MOD="11";
        MOV="100010";
        D="1";
    }
    else if(t1==REGISTER && t2==ADDRESS)
    {
        ret_val=REGISTER_ADDRESS;
        MOD="00";
        MOV="100010";
        D="1";
    }
    else if(t1==ADDRESS && t2==REGISTER)
    {
        ret_val=ADDRESS_REGISTER;
        MOD="00";
        MOV="100010";
        D="0";
    }
    else
    {
        ret_val=REGISTER_IMMEDIATE;
        MOD="00";
        MOV="1011";
        D="WRRR";//Signifies Change in Code
    }
    return ret_val;
}

type findtype(std::string  parameter)
{
    type ret_val;
    std::string::iterator i;
    i=parameter.begin();
    if(*i=='[')
    {
        ret_val=ADDRESS;
    }
    else if(parameter.length()>2 && *parameter.end()=='H')
    {
        ret_val=IMMEDIATE;
    }
    else if(*parameter.end()=='H'&& parameter.compare(0,2,"AH")!=0 && parameter.compare(0,2,"CH")!=0
    && parameter.compare(0,2,"DH")!=0 && parameter.compare(0,2,"BH")!=0)
    {
        ret_val=IMMEDIATE;
    }
    else
    {
        if(isdigit(*parameter.begin()))
        {
            ret_val=IMMEDIATE;
        }
        else
        {
            ret_val=REGISTER;
        }
    }
    return ret_val;
}
