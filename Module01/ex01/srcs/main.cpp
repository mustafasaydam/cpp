#include "../includes/Zombie.hpp"

int main(void){
    Zombie *my_zombies;

    my_zombies = zombieHorde(10, "Patricks");
    delete [] my_zombies;

    Zombie *my_zombies2;

    my_zombies2 = zombieHorde(-1, "POulet");
    delete [] my_zombies2;

    return (0);
}