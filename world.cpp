#include <atomic>
#include <iostream>
#include <mutex>
#include <unordered_map>
#include <signal.h>
#include "world.h"

std::atomic<bool> terminateFlag(false);

void handleKeyboardInterrupt(int signum)
{
    std::cout << "Keyboard interrupt received. Terminating...\n";
    terminateFlag = true;
}

void World::run_world()
{

    signal(SIGINT, handleKeyboardInterrupt);

    while (!terminateFlag)
    {
        std::cout << "world running";
         std::thread lifeThreadM(&World::life, this, 14, 'M');
          std::thread lifeThreadF(&World::life, this, 16, 'F');
          std::this_thread::sleep_for(std::chrono::seconds(5));
        //   terminateFlag = true;

    for (const auto& pair : humans) {
        std::cout << "Key: " << pair.first << ", Value:"<< std::endl;
    }
          lifeThreadM.join();
          lifeThreadF.join();
    }
}

void World::life(int age, char gender){
    std::cout << std::endl << age << gender;

    Human human(age, gender);
    new_human(human);


}

void World::new_human( const Human& human){
        std::lock_guard<std::mutex> lock(map_mutex_);
        std::cout <<"\nhere new human"<< human.age<< human.gender;
        humans[1] = human;

}
