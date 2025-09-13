#include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void)
        {
            (void)1;
        }
        Zombie(std::string name);
        void announce( void );
        void setName(std::string name);
        ~Zombie();
};



Zombie *newZombie( std::string name );
void randomChump( std::string name );
Zombie* zombieHorde( int N, std::string name );