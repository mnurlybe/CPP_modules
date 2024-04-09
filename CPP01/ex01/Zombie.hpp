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
        void setName(std::string name, int i);
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
