
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "cusDB.h"
#define DBFILENAME "./cusDB.txt"




u8 c_CustomerAcc::SetName ()
{
	std::string * newname = new std::string [4];
	u8 j =0;
	std::cout<< "please enter the name in this format : 1st 2nd 3rd 4th"<<std::endl;
	std::cin>>newname[0]>>newname[1]>>newname[2]>>newname[3];
	for(int i = 0 ; i < 4 ; i ++)
	{
		if(newname[i].length()<=1 )
		{
			std::cout<<"name is too short "<<std::endl ;
			delete[]newname;
			return 0;
		}
		else if(newname[i].length()>15)
		{
			std::cout<<"name is too long "<<std::endl ;
			delete[]newname;
			return 0;
		}
		j = 0;
		while(newname[i][j]!='\0')
		{
			if(!((newname[i][j]>='a'&&newname[i][j]<='z')||(newname[i][j]>='A'&&newname[i][j]>='Z')))
			{
				std::cout<<"cant accept any nums or sympols"<<std::endl;
				delete[]newname;
				return 0;
			}
			j++;
		}
	}
	name = newname ;
	return 1 ;
}

u8 c_CustomerAcc::SetNationalID()
{
	u8 j =0;
	std::string newnID ;
	std::cout<<"enter the national your Id :"<<std::endl;
	std::cin>>newnID;
	if(newnID.length()!=14)
	{
		std::cout<<"wrong nID"<<std::endl;
		return 0;
	}
	
	j = 0 ;
	while(newnID[j]!='\0')
	{
		if(newnID[j]>'9'||newnID[j]<'0')
		{
			std::cout<<"cant accept any but nums"<<std::endl;
			return 0;
		}
		j++;
	}
	
	nID=newnID;
	return 1 ;
}
	
u8 c_CustomerAcc::SetUserAddress ()
{
	std::string * newAddress = new std::string [6];
	u8 j =0;
	std::cout<< "please enter the Address in this format :  \"country governorate city  streat building appartment\" :"<<std::endl;
	std::cin>>newAddress[0]>>newAddress[1]>>newAddress[2]>>newAddress[3]>>newAddress[4]>>newAddress[5];
	for(int i = 0 ; i < 6 ; i ++)
	{
		if(newAddress[i].length()<=1 )
		{
			std::cout<<"Address is too short "<<std::endl ;
			delete[]newAddress;
			return 0;
		}
		else if(newAddress[i].length()>20)
		{
			std::cout<<"Address is too long "<<std::endl ;
			delete[]newAddress;
			return 0;
		}
		j = 0;
		while(newAddress[i][j]!='\0')
		{
			if(!((newAddress[i][j]>='a'&&newAddress[i][j]<='z')||(newAddress[i][j]>='A'&&newAddress[i][j]<='Z')||(newAddress[i][j]>='0'&&newAddress[i][j]<='9')))
			{
				std::cout<<"cant accept any sympols"<<std::endl;
				delete[]newAddress;
				return 0;
			}
			j++;
		}
	}
	Address = newAddress[0]+'/'+newAddress[1]+'/'+newAddress[2]+'/'+newAddress[3]+'/'+newAddress[4]+'/'+newAddress[5] ;
	return 1 ;
	
}
		
u8 c_CustomerAcc::SetAccBalance()
{
	u8 j =0;
	std::string newBALANCE ;
	std::cout<<"enter the Balance :"<<std::endl;
	std::cin>>newBALANCE;
	if(newBALANCE.length()>=14)
	{
		std::cout<<"not realitstic"<<std::endl;
		return 0;
	}
	
	j = 0 ;
	while(newBALANCE[j]!='\0')
	{
		if(newBALANCE[j]>'9'||newBALANCE[j]<'0')
		{
			std::cout<<"cant accept any but nums"<<std::endl;
			return 0;
		}
		j++;
	}
	
	Balance=newBALANCE;
	return 1 ;
}

u8 c_CustomerAcc::SetUserAge ()
{
	u8 j =0;
	std::string newAge ;
	std::cout<<"enter Age :"<<std::endl;
	std::cin>>newAge;
	if(newAge.length()>=3)
	{
		std::cout<<"not realitstic"<<std::endl;
		return 0;
	}
	
	j = 0 ;
	while(newAge[j]!='\0')
	{
		if(newAge[j]>'9'||newAge[j]<'0')
		{
			std::cout<<"cant accept any but nums"<<std::endl;
			return 0;
		}
		j++;
	}
	
	Age=newAge;
	return 1 ;
}
		
u8 c_CustomerAcc::SetAccState (u8 newstate)
{
	if (newstate==1)
	{
		state="active";
		return 1;
	}
	else
	{
		char s ;
		std::cout<<"enter the state :: 1: active account  2: restricted Account 3: closed Account"<<std::endl;
		std::cin>>s;
		if (s=='1')
		{
			state="active";
		}
		else if (s=='2')
		{
			state= "restricted";
		}
		else if (s=='3')
		{
			state= "closed";
		}
		else
		{return 0;}
		return backinplace();
	}
	
}
	
u8 c_CustomerAcc::SetGaurdianID()
{
	u32 agenum = strtoint(Age);
	if(agenum<21)
	{
		u8 j =0;
		std::string newGnID ;
		std::cout<<"enter the national your Id :"<<std::endl;
		std::cin>>newGnID;
		if(newGnID.length()!=14)
		{
			std::cout<<"wrong nID"<<std::endl;
			return 0;
		}
		
		j = 0 ;
		while(newGnID[j]!='\0')
		{
			if(newGnID[j]>'9'||newGnID[j]<'0')
			{
				std::cout<<"cant accept any but nums"<<std::endl;
				return 0;
			}
			j++;
		}
		
		GnID=newGnID;
		return 1 ;				
	}
	else
	{
		GnID="00000000000000";
		return 1 ;				

	}
}


u8 c_CustomerAcc::SetLastBID()
{
	std::fstream myfile ;
	myfile.open("cusDB.txt",std::ios::ate);
	std::string bid ;
	if(myfile.is_open())
	{
		std::vector<std::string> tokens ;
		std::string tok ;

		u8 i = 0 ;
		while(getline(myfile,tok,'\t'))
		{
				i++ ;
				tokens.push_back(tok);
				if(i == 11)
				{
					getline(myfile,tok,'\n');
					tokens.push_back(tok);
					i=0;
					bid=tokens[0];
					tokens.clear();				
				}
			
			
		}
	}
	myfile.close();
	u32 bidint = strtoint(bid);
	bidint+=1;
	bid=inttostr(bidint);
	while(bid.length()!=14)
	{bid='0'+bid;}
	BID=bid;
	return 1;
}
		
u8 c_CustomerAcc::creatnewAccount()
{
	u8 flag = 0 ;
	u8 q = 'y' ;
	SetLastBID();
	flag=0;
	do{flag=SetName();}while(flag==0);
	flag=0;
	do{flag=SetNationalID();}while(flag==0);
	flag=0;
	do{flag=SetUserAddress();}while(flag==0);
	flag=0;
	do{flag=SetAccBalance();}while(flag==0);
	flag=0;
	do{flag=SetUserAge();}while(flag==0);
	flag=0;
	do{flag=SetAccState(1);}while(flag==0);
	flag=0;
	do{flag=SetGaurdianID();}while(flag==0);
	flag=0;
	SetRandomPass();
	
	char y= 'n';
	std::cout<<"r u sure u want to add this account y/n"<<std::endl;
	std::cin>>y;
	if(y=='y')
	{WriteAtBack();}
	else{return 0;}
	return 1;
}

		
u8 c_CustomerAcc::SetRandomPass ()
{
	u32 pass = 0 ;
	while(pass<1000||pass>9999)
	{pass=rand();}
	Password = inttostr(pass);
}

u8 c_CustomerAcc::WriteAtBack()
{
	
	std::fstream myfile ;
	myfile.open("cusDB.txt",std::ios::app);
	if(myfile.is_open())
	{
		
		myfile<<BID<<'\t'	;
		myfile<<name[0]<<'\t'	;
		myfile<<name[1]<<'\t'	;
		myfile<<name[2]<<'\t'	;
		myfile<<name[3]<<'\t'	;
		myfile<<Password<<'\t';
		myfile<<state<<'\t'	;
		myfile<<Balance<<'\t' ;
		myfile<<nID	<<'\t'	;
		myfile<<Address<<'\t'	;
		myfile<<Age	<<'\t'	;
		myfile<<GnID	<<'\n';
			
		}
	
	myfile.close();
	return 1;

	
}


u8 c_CustomerAcc::S_deposit ()
{
	std::string depositamount ;
	std::cout<<"enter the amount u want to deposit :"<<std::endl;
	std::cin>>depositamount;
	if(depositamount.length()>14)
	{
		std::cout<<"unrealistic"<<std::endl;
		return 0 ;
	}
	u8 j = 0 ;
	while(depositamount[j]!='\0')
	{
		if(depositamount[j]>'9'||depositamount[j]<'0')
		{
			printf("cant accept any but nums \n");
			return 0 ;
		}
		j++;
	}
	
	
	u32 trans =strtoint(depositamount);
	u32 bal =strtoint(Balance);
	bal += trans ;
	Balance=inttostr(bal);
	backinplace();
	return 1;

	
}


u8 c_CustomerAcc::S_withdrow ()
{
	std::string withdrowamount ;
	std::cout<<"enter the amount u want to get :"<<std::endl;
	std::cin>>withdrowamount;
	if(withdrowamount.length()>14)
	{
		std::cout<<"unrealistic"<<std::endl;
		return 0 ;
	}
	u8 j = 0 ;
	while(withdrowamount[j]!='\0')
	{
		if(withdrowamount[j]>'9'||withdrowamount[j]<'0')
		{
			printf("cant accept any but nums \n");
			return 0 ;
		}
		j++;
	}
	
	
	u32 trans =strtoint(withdrowamount);
	
	u32 bal =strtoint(Balance);
	if(trans>bal)
	{
		std::cout<<"ur balanc < this amount "<<std::endl;
		return 0;
	}
	bal -= trans ;
	Balance=inttostr(bal);
	backinplace();
	return 1;

	
}



u8 c_CustomerAcc::S_changePASS ()
{
	std::string p1 ,p2;
		std::cout<<"enter the new password "<<std::endl;
		std::cin>>p1;
		std::cout<<"enter the new password again "<<std::endl;
		std::cin>>p2;
		if(p1==p2)
		{
			Password=p1;
			backinplace();
			return 1 ;
		}
		else
		{
			std::cout<<"are u kiddin?? u enterd 2 different passwords !! "<<std::endl;
			return 0;
		}
}


u8 c_CustomerAcc::S_transaction ()
{
	c_CustomerAcc cus2 ;
	std::string secondbid;
	std::string withdrowamount ;

	u8 j = 0 ;
	u8 flag = 0 ;
	u32 trans;
	u32 bal;
	do
	{
		flag=0;
		std::cout<<"please enter the secondbid"<<std::endl;
		std::cin>>secondbid;
		if(secondbid.length()!=12)
		{
			std::cout<<"wrong BID"<<std::endl;
			flag=1;
		}
		
		j = 0 ;
		while(secondbid[j]!='\0'&&flag==0)
		{
			if(secondbid[j]>'9'||secondbid[j]<'0')
			{
				std::cout<<"cant accept any but nums"<<std::endl;
				flag=2;
			}
			j++;
		}
		
		if(cus2.GetAccByBid(secondbid)==0 &&flag==0)
		{
			std::cout<<"cant find this Account"<<std::endl;
			flag = 3;
		}
		
		
		if(flag==0)
		{
			std::cout<<"enter the amount u want to trans :"<<std::endl;
			std::cin>>withdrowamount;
			
			if(withdrowamount.length()>14)
			{
				std::cout<<"unrealistic"<<std::endl;
				flag = 4 ;
			}
			j = 0 ;
			while(withdrowamount[j]!='\0'&&flag==0)
			{
				if(withdrowamount[j]>'9'||withdrowamount[j]<'0')
				{
					printf("cant accept any but nums \n");
					flag=5;
				}
				j++;
			}
		
			trans =strtoint(withdrowamount);
			bal =strtoint(Balance);
			if(trans>bal&&flag==0)
			{
				std::cout<<"ur balanc < this amount "<<std::endl;
				flag=6;
			}
		}
		if(flag!=0)
		{
			char q = 'n';
			std::cout<<"want to try again y/n"<<std::endl;
			std::cin>>q;
			if(q=='n')
			{return 0 ;}

		}
		
	}while(flag!=0);



	u32 bal2=cus2.strtoint(cus2.Balance);
	bal -= trans ;
	bal2+=trans;
	Balance=inttostr(bal);
	cus2.Balance=inttostr(bal2);
	cus2.backinplace();
	backinplace();
	return 1 ;

	
	
	
}



c_CustomerAcc::c_CustomerAcc()
		{
			BID ="";
			name=NULL ;
			Password= "" ;	
			state = "";		
			Balance ="" ;	
			nID	= "";
			Address = "";	
			Age	="";
			GnID ="";	
			Admin =0;
			
		}
						
u8 c_CustomerAcc::deposit()
		{
			if(state=="active")
			{return S_deposit();}
			else
			{std::cout<<"this acc is "<<state<<"cant do the process"<<std::endl;return 0;}
		}
u8 c_CustomerAcc::withdrow()
		{
			if(state=="active")
			{return S_withdrow();}
			else
			{std::cout<<"this acc is "<<state<<"cant do the process"<<std::endl;return 0;}

		}
u8 c_CustomerAcc::changePASS()
		{
			if(state=="active")
			{return S_changePASS();}
			else
			{std::cout<<"this acc is "<<state<<"cant do the process"<<std::endl;return 0;}

		}
		
u8 c_CustomerAcc::transaction()
		{
			if(state=="active")
			{return S_transaction();}
			else
			{std::cout<<"this acc is "<<state<<"cant do the process"<<std::endl;return 0;}
		}
		
u8 c_CustomerAcc::SetAsAdmin (std::string Adminname , std::string pass)
		{
			
			std::fstream myfile ;
			myfile.open("employeeDB.txt",std::ios::in);
			if(myfile.is_open())
			{
				std::vector<std::string> tokens ;
				std::string tok ;

				u8 i = 0 ;
				while(getline(myfile,tok,'\t'))
				{
					tokens.push_back(tok);
					getline(myfile,tok,'\n');
					tokens.push_back(tok);

					if(tokens[0]==Adminname&&tokens[1]==pass)
					{
						myfile.close();
						Admin=1;
						return 1;
					}
					tokens.clear();				
				}
				
					
			}
		
			myfile.close();

			return 0;
		
		}
		
void c_CustomerAcc::printCusInfo ()
		{
			std::cout<< "Bank ID: " <<BID <<std::endl;
			std::cout<< "Name : " <<name [0]<<" "<<name[1]<<" "<<name[2]<< " "<<name[3] <<std::endl;
			std::cout<< "Password : " <<Password  <<std::endl;
			std::cout<< "State : " <<state <<std::endl;
			std::cout<< "Balance : " <<Balance <<std::endl;
			std::cout<< "nID :" <<nID	<<std::endl;
			std::cout<< "Address : " <<Address <<std::endl;
			std::cout<< "Age : " <<Age	 <<std::endl;
			std::cout<< "Gardian nID : " <<GnID 	 <<std::endl;
		}

void c_CustomerAcc::A_SET_State()
		{
			if(Admin==0)
			{std::cout<<"only Admin can do this"<<std::endl;}
			else
			{SetAccState(0);}			
		}
u8 c_CustomerAcc::A_creatnewAccount()
		{
			if(Admin==0)
			{std::cout<<"only Admin can do this"<<std::endl;}
			else
			{return creatnewAccount();}
		}
		
u8 c_CustomerAcc::SearchAcc ()
		{
			std::string * NAME =new std::string [4]  ;
			std::string PASS ;
			std::cout<<"please enter the name in this formt 1st 2nd 3d 4th"<<std::endl;
			std::cin>>NAME[0];
			std::cin>>NAME[1];
			std::cin>>NAME[2];
			std::cin>>NAME[3];
			std::cout<<"please enter the password"<<std::endl;
			std::cin>>PASS;

			std::fstream myfile ;
			myfile.open("cusDB.txt",std::ios::in);
			if(myfile.is_open())
			{
				std::vector<std::string> tokens ;
				std::string tok ;

				u8 i = 0 ;
				while(getline(myfile,tok,'\t'))
				{
						i++ ;
						tokens.push_back(tok);
						if(i == 11)
						{
							getline(myfile,tok,'\n');
							tokens.push_back(tok);
							if(tokens[1]==NAME[0]&&tokens[2]==NAME[1]&&tokens[3]==NAME[2]&&tokens[4]==NAME[3]&&tokens[5]==PASS)
							{
								BID		=tokens[0];
								name	= new std::string [4];;
								name[0]	=(std::string)tokens[1];
								name[1]	=(std::string)tokens[2];
								name[2]	=(std::string)tokens[3];
								name[3]	=(std::string)tokens[4];
								Password=tokens[5];	
								state	=tokens[6];		
								Balance =tokens[7];
								nID		=tokens[8];
								Address	=tokens[9];	
								Age		=tokens[10];
								GnID	=tokens[11];
								myfile.close();
								std::cout<<"bb";
								delete[]NAME;
								return 1;
							}
							i=0;
							tokens.clear();				
						}
					
					
				}
			}
			delete[]NAME;
			myfile.close();
			return 0;
		}
	
u8 c_CustomerAcc::GetAccByBid(std::string bid)
		{
			std::fstream myfile ;
			myfile.open("cusDB.txt",std::ios::in);
			if(myfile.is_open())
			{
				std::vector<std::string> tokens ;
				std::string tok ;

				u8 i = 0 ;
				while(getline(myfile,tok,'\t'))
				{
						i++ ;
						tokens.push_back(tok);
						if(i == 11)
						{
							getline(myfile,tok,'\n');
							tokens.push_back(tok);

							if(tokens[0]==bid)
							{
								BID		=tokens[0];
								name	= new std::string [4];;
								name[0]	=(std::string)tokens[1];
								name[1]	=(std::string)tokens[2];
								name[2]	=(std::string)tokens[3];
								name[3]	=(std::string)tokens[4];
								Password=tokens[5];	
								state	=tokens[6];		
								Balance =tokens[7];	
								nID		=tokens[8];
								Address	=tokens[9];	
								Age		=tokens[10];
								GnID	=tokens[11];
								myfile.close();
								return 1;
							}
							i=0;
							tokens.clear();				
						}
					
					
				}
			}
			myfile.close();
			return 0;
		

		}
u8 c_CustomerAcc::backinplace()
		{
			
			std::fstream myfile ,temp ;
			myfile.open("cusDB.txt",std::ios::in);
			temp.open("temp.txt",std::ios::app);
			if(myfile.is_open()&&temp.is_open())
			{
				std::vector<std::string> tokens ;
				std::string tok ;

				u8 i = 0 ;
				while(getline(myfile,tok,'\t'))
				{
						i++ ;
						tokens.push_back(tok);
						if(i == 11)
						{
							getline(myfile,tok,'\n');
							tokens.push_back(tok);

							if(tokens[0]==BID)
							{
								temp<<BID<<'\t'	;
								temp<<name[0]<<'\t'	;
								temp<<name[1]<<'\t'	;
								temp<<name[2]<<'\t'	;
								temp<<name[3]<<'\t'	;
								temp<<Password<<'\t';
								temp<<state<<'\t'	;
								temp<<Balance<<'\t' ;
								temp<<nID	<<'\t'	;
								temp<<Address<<'\t'	;
								temp<<Age	<<'\t'	;
								temp<<GnID	<<'\n';
							}
							else
							{
								temp<<tokens[0]		<<'\t'	;
								temp<<tokens[1]		<<'\t'	;
								temp<<tokens[2]		<<'\t'	;
								temp<<tokens[3]		<<'\t'	;
								temp<<tokens[4]		<<'\t'	;
								temp<<tokens[5]		<<'\t';
								temp<<tokens[6]		<<'\t'	;
								temp<<tokens[7]		<<'\t' ;
								temp<<tokens[8]		<<'\t'	;
								temp<<tokens[9]		<<'\t'	;
								temp<<tokens[10]	<<'\t'	;
								temp<<tokens[11]	<<'\n';
							}
							i=0;
							tokens.clear();				
						}
					
					
				}
			}
			myfile.close();
			temp.close();
			remove("cusDB.txt");
			rename("temp.txt","cusDB.txt");
			return 1;

			
		}
	
		
std::string c_CustomerAcc::inttostr (u32 num)
		{
			std::string b ="" ;
			while(num>0)
			{
				b=(char)((char)(num%10)+'0')+b;
				num/=10;
			}
			return b ;

		}
		
		
u32 c_CustomerAcc::strtoint (std::string x)
		{
			s32 j=x.length()-1;
			u32 k = 1 ;
			u32 num = 0;
			while(j>=0)
			{
				num+=((char)x[j]-'0')*k;
				k*=10;
				j--;
			}
			return num;
		}

		
c_CustomerAcc::~c_CustomerAcc()
		{
			delete[]name;
		}
		
