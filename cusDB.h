
#ifndef __CUS_DB_H__

#define	__CUS_DB_H__

#include "STD_TYPES.h"



class c_CustomerAcc {
	private:
		std::string BID ;
		std::string * name ;
		std::string Password ;	
		std::string state;		
		std::string Balance ;	
		std::string nID	;
		std::string Address;	
		std::string Age	;
		std::string GnID ;	
		u8 Admin ;
		u8 SetName ();		
		u8 SetNationalID();			
		u8 SetUserAddress ();				
		u8 SetAccBalance();		
		u8 SetUserAge ();				
		u8 SetAccState (u8 newstate);		
		u8 SetGaurdianID();		
		u8 SetLastBID();				
		u8 creatnewAccount();		
		u8 SetRandomPass ();		
		u8 WriteAtBack();	
		u8 S_deposit ();		
		u8 S_withdrow ();
		u8 S_changePASS ();		
		u8 S_transaction ();	
	public:
		c_CustomerAcc();
		u8 deposit();
		u8 withdrow();
		u8 changePASS();
		u8 transaction();
		u8 SetAsAdmin (std::string Adminname , std::string pass);		
		void printCusInfo ();
		void A_SET_State();
		u8 A_creatnewAccount();		
		u8 SearchAcc ();	
		u8 GetAccByBid(std::string bid);
		u8 backinplace();	
		std::string inttostr (u32 num);
		u32 strtoint (std::string x);
		~c_CustomerAcc(void);
		


};










#endif