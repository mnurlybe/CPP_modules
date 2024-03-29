#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string name;
        int id;

    public:
        Zombie();
        ~Zombie();
        void setName(std::string name, int i){
            this->name = name;
            this->id = i;
        }
        void announce(void)
        {
            std::cout << this->name << this->id << ": BraiiiiiiinnnzzzZ..." << std::endl;
        }
};

Zombie* zombieHorde( int N, std::string name );

#endif
