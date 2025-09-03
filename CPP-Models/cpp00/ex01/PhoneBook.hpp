#if !defined(PHONEBOOK)
#define PHONEBOOK

#include <iostream>

class PhoneBook
{
    private:
        int id;
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        void Set(int _id, std::string _FirstName, std::string _LastName, 
            std::string _NickName, std::string _PhoneNumber, std::string _DarkestSecret)
        {
            id = _id;
            FirstName = _FirstName;
            LastName = _LastName;
            NickName = _NickName;
            PhoneNumber = _PhoneNumber;
            DarkestSecret = _DarkestSecret;
        }
        void Display()
        {
            std::cout << "index : " << id << std::endl;
            std::cout << "First Name : " << FirstName << std::endl;
            std::cout << "Last Name : " << LastName << std::endl;
            std::cout << "Nick Name : " << NickName << std::endl;
        }
};



#endif
