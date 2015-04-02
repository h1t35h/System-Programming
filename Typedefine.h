#ifndef TYPEDEFINE_H_INCLUDED
#define TYPEDEFINE_H_INCLUDED
#include<string>
typedef enum{REGISTER_REGISTER,REGISTER_ADDRESS,ADDRESS_REGISTER,REGISTER_IMMEDIATE} typefun;
typedef enum{REGISTER,ADDRESS,IMMEDIATE} type;
typefun findmode(std::string instruction,std::string &MOD,std::string &MOV,std::string &D);
type findtype(std::string parameter);

#endif // TYPEDEFINE_H_INCLUDED
