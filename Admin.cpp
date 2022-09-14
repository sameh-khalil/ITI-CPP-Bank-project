
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "STD_TYPES.h"
#include "cusDB.h"
#include "Admin.h"


#define DBFILENAME "./cusDB.txt"

Admin::Admin()
{}




u8 Admin::signin()
{
	
	std::string tempname ;
	std::string tempPassword ;

	std::cout<<"enter the name"<<std::endl;
	std::cin>>tempname;
	std::cout<<"enter the password"<<std::endl;
	std::cin>>tempPassword;
	std::fstream myfile ;
	myfile.open("employeeDB.txt",std::ios::in);
	if(myfile.is_open())
	{
		std::vector<std::string> tokens ;
		std::string tok ;
		u32 i = 0 ;
		u32 j=0;
		while(getline(myfile,tok,'\t'))
		{
				tokens.push_back(tok);
				getline(myfile,tok,'\n');
				tokens.push_back(tok);
				if(tokens[0]==tempname&&tokens[1]==tempPassword)
				{
					name=tempname;
					std::cout<<"welcome "<<name;
					Password=tempPassword;
					myfile.close();
					return 1;
				}
				tokens.clear();
			
			
		}
	}
	myfile.close();
	
	std::cout<<"wrong name or pass"<<std::endl;
	
	
	return 0 ;

}

void Admin::CreatAcc ()
{
	c_CustomerAcc cus ;
	if(cus.SetAsAdmin(name,Password))
	{
		cus.A_creatnewAccount();
	}
	else{std::cout<<"how did that happend"<<std::endl;}
	
}
	
void Admin::OpenExistingAcc()
{
	c_CustomerAcc cus ;
	if(cus.SetAsAdmin(name,Password))
	{
		if(cus.SearchAcc())
		{
			cus.printCusInfo();
			char op = '0';
			while(1)
			{
				std::cout<<"choose the operation 1: transaction 	2: change account status	3:deposit 	4: return   5: get cash \n"<<std::endl;
				std::cin>>op;
				if(op=='1')
				{cus.transaction();cus.printCusInfo();}
				else if(op=='2')
				{cus.A_SET_State();cus.printCusInfo();}
				else if(op=='3')
				{cus.deposit();cus.printCusInfo();}
				else if(op=='4')
				{return ;}
				else if(op=='5')
				{cus.withdrow();cus.printCusInfo();}
		
		}}
		
	}
	else{std::cout<<"how did that happend"<<std::endl;}

}


Admin::~Admin()
{}

