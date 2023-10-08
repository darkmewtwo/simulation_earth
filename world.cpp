#include <atomic>
#include <iostream>
#include <sstream>
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
    int st;
    signal(SIGINT, handleKeyboardInterrupt);
    std::ostringstream oss, oss1;

    // while (!terminateFlag)
    // {
        try {
            oss << 14 << "M";
            oss1 << 16 << "F";
            // std::string p = oss; 
            threadMap[oss.str()] =  std::thread(&World::life, this, 14, 'M');
            // std::thread(&World::life, this, 16, 'F');
            // std::thread lifeThreadMF(&World::life, this, 18, 'L');

            std::cout << "ah come on\n";

            threadMap[oss.str()].join();
            threadMap.erase(oss.str());
            // lifeThreadF.join();
            // lifeThreadMF.join();
        } catch (const std::exception& e) {
            std::cout << "Exception occurred: " << e.what() << "\n";
        }


        std::cout << "\n";
        for (const auto& pair : humans) {
        std::cout << "Key: " << pair.first << ", Value:"<< pair.second.get_age() << pair.second.get_gender()<< std::endl;
    }
          std::cout << "enter 1 to continue";
          std::cin >> st;

    // }
    //     for (const auto& pair : humans) {
    //     std::cout << "Key: " << pair.first << ", Value:"<< pair.second.age << pair.second.gender<< std::endl;
    // }
}

void World::life(int age, char gender){
    std::cout << std::endl << age << gender;

    try{
    Human human(age, gender);
     new_human(human);
    } catch (const std::exception& e) {
         std::cout << "Exception occurred: \n" << e.what() << "\n";}
    std::cout << "\n human living thread \t" << age << gender;
 
   
    // human.aging();


}

void World::new_human( const Human& human){
        std::lock_guard<std::mutex> lock(map_mutex_);
        // std::cout <<"\nhere new human"<< human.age<< human.gender;
        humans[human.get_age()] = human;
        // humans.insert(std::make_pair(1, human));
    return;

}

void World::new_life(const Human& human1, const Human& human2){
    
    // std::string name_t = "ello";
    
    // std::thread name_t(&World::life, this, 20, 'F');
    // name_t.join();

}