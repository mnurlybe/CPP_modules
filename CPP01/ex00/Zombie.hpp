#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        ~Zombie();
        void setName(std::string name){
            this->name = name;
        }
        void announce(void)
        {
            std::cout << this->name << "> BraiiiiiiinnnzzzZ..." << std::endl;
        }
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
