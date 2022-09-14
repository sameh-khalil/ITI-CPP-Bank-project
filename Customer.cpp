
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "STD_TYPES.h"
#include "Customer.h"
#define DBFILENAME "./cusDB.txt"



Customer::Customer(){}
u8 Customer::signin()
{return ca.SearchAcc();}
u8 Customer::uGetchash()
{
	return ca.withdrow();
}
u8 Customer::uChangePass ()
{
	return ca.changePASS();
}
u8 Customer::uPrintinfo ()
{
	ca.printCusInfo();
	return 1 ;
}
u8 Customer::uDeposit()
{
	return ca.deposit ();
}
u8 Customer::uTransaction()
{
	return ca.transaction();
}




