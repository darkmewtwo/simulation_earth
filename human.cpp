#include <iostream>
#include <chrono>
#include <thread>
#include "human.h"
using namespace std;

Human::Human(int age, char gender) : gen(std::random_device()()), distribution(0, 100)
{
    cout << age << gender;
    this->age = age;
    this->gender = gender;
    this->timeOfBirth = std::chrono::high_resolution_clock::now();
    this->isAlive = true;
    // lifeTimeThread = std::thread(&Human::aging, this);
}

Human::~Human()
{

    cout << "inside destructor";
    isAlive = false;
    if (lifeTimeThread.joinable())
    {
        cout << "going to join thread";
        lifeTimeThread.join();
    }
        // death();
}

void Human::death()
{
    std::cout << "human died" << endl;
    // auto n = std::chrono::high_resolution_clock::now();
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(n.time_since_epoch()).count();
    auto birthTime = timeOfBirth;
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(timeOfBirth.time_since_epoch()).count();
    delete this;
    auto i = std::chrono::duration_cast<std::chrono::microseconds>(timeOfDeath - birthTime).count();
    std::chrono::duration<double> duration = timeOfDeath - timeOfBirth;
    
    // Convert duration to seconds
    double seconds = duration.count();
    std::cout << i << endl
              << "lived : " << i / 24 << " days";
    // cout << std::chrono::high_resolution_clock::now() - birthTime
}

void Human::aging()
{
    cout << "are we here";
    auto birthTime = timeOfBirth;
    while (isAlive)
    {
        cout << "Are we inside the loop";
        auto currentAge = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - birthTime).count();

        int ran = distribution(gen);
        std::cout << ran << std::endl;
        std::cout << age << std::endl
                  << gender;

        if (currentAge / 24 > 3000)
        {

            isAlive = false;
        }
    }
    cout << "\ngoing to die" << isAlive << endl;
    timeOfDeath = std::chrono::high_resolution_clock::now();
    // death();
}
