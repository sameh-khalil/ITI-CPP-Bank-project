
#ifndef __CUSTOMER_H__

#define	__CUSTOMER_H__
#include "cusDB.h"

class Customer {
	private:
		c_CustomerAcc ca ;
	public:
		Customer();
		u8 signin();
		u8 uGetchash();
		u8 uChangePass ();
		u8 uPrintinfo ();
		u8 uDeposit();
		u8 uTransaction();
	
};


#endif