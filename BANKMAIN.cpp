#include <iostream>
#include <fstream>
#include <string>
#include "Customer.h"
#include "Admin.h"

int main ()
{
	
	

	u8 flag = 0 ;
	char op  ;
	char q = 'n';
	char op2 ;
	u8 adminflag = 0 ;
	u8 userflag =0 ;
	while (1)
	{
		std::cout<<"1-enter as a custmer 2- enter as an admin"<<std::endl;
		std::cin>>op ;
		if(op=='2')
		{
			Admin a1 ;
			
			if(a1.signin())
			{adminflag=1;}
			while(adminflag==1)
			{
			
					std::cout<<"choose from options 1- creat new acc 2- open existing acc 3- exit"<<std::endl;
					std::cin>>op2;
					if(op2=='1')
					{
						a1.CreatAcc();
					}
					else if(op2=='2')
					{
						a1.OpenExistingAcc();
						
					}
					else
					{adminflag=0;a1.~Admin();break;}
					
					
				
			}
		}
		else
		{
			Customer c1 ;
			if(c1.signin())
			{userflag=1;}
			while(userflag==1)
			{
					std::cout<<"getcash 1 : getaccount info 2 :quit 3  :deposit 4 : change password 5 :transaction 6"<<std::endl;
					std::cin>>op2;
					if(op2=='1')
					{
						c1.uGetchash();
					}
					else if(op2=='2')
					{
						c1.uPrintinfo();
					}
					else if(op2=='3')
					{
						userflag=0; break;
					}
					else if(op2=='4')
					{
						c1.uDeposit();
					}
					else if(op2=='5')
					{
						c1.uChangePass();
					}
					else if(op2=='6')
					{
						c1.uTransaction();
					}
				
			
			
			}
				
		}
	
	
		
	}
	
	
			
}

