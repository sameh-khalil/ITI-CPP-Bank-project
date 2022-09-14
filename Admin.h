
#ifndef __ADMIN__

#define	__ADMIN__


class Admin {
	private:
		std::string name ;
		std::string Password ;
	public:
		Admin();
		u8 signin ();		
		void CreatAcc ();
		void OpenExistingAcc();		
		~Admin();
};


#endif