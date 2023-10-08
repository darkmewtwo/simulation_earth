#include <iostream>
#include <chrono>
#include <thread>
#include "human.h"
#include "world.h"
using namespace std;

Human::Human(int age, char gender) : gen(std::random_device()()), distribution(0, 100)
{
    // cout << age << gender;
    this->age = age;
    this->gender = gender;
    this->timeOfBirth = std::chrono::high_resolution_clock::now();
    this->isAlive = true;
    // lifeTimeThread = std::thread(&Human::aging, this);
    aging();
}

Human::~Human()
{

    cout << "\ninside destructor\n";
    auto i = std::chrono::duration_cast<std::chrono::microseconds>(timeOfDeath - timeOfBirth).count();
    cout << "lived : "<< gender << i / 24 << " days";

    // cout << age << gender << endl;

    // isAlive = false;
    // if (lifeTimeThread.joinable())
    // {
    //     cout << "going to join thread";
    //     lifeTimeThread.join();
    // }
        // death();
}

void Human::death()
{
    std::cout << "\nhuman died \t" + gender << endl;
    // auto n = std::chrono::high_resolution_clock::now();
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(n.time_since_epoch()).count();
    auto birthTime = timeOfBirth;
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(timeOfBirth.time_since_epoch()).count() << endl;
    // std::cout << std::chrono::duration_cast<std::chrono::microseconds>(timeOfDeath.time_since_epoch()).count();
    // auto o = std::chrono::duration_cast<std::chrono::microseconds>(timeOfBirth.time_since_epoch()).count();
    // auto p = std::chrono::duration_cast<std::chrono::microseconds>(timeOfDeath.time_since_epoch()).count();
    // cout << (p - o) << endl;
    auto i = std::chrono::duration_cast<std::chrono::microseconds>(timeOfDeath - birthTime).count();
    std::chrono::duration<double> duration = timeOfDeath - timeOfBirth;
    
    // Convert duration to seconds
    double seconds = duration.count();
    // std::cout << i << endl
    //           << "lived : " << i / 24 << " days" << " gender  "<< gender;
    delete this;
    // cout << std::chrono::high_resolution_clock::now() - birthTime
}

void Human::aging()
{
    try{
    // cout << "\nare we here\n";
    auto birthTime = timeOfBirth;
    while (isAlive)
    {
        // cout << "Are we inside the loop";
        auto currentAge = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - birthTime).count();
        // cout << currentAge << endl << currentAge / 24 << endl;
        int ran = distribution(gen);
        // std::cout << ran << std::endl;
        // std::cout << age << std::endl
        //           << gender;

        if (currentAge / 24 > 3000)
        {

            isAlive = false;
        }
    }
    timeOfDeath = std::chrono::high_resolution_clock::now();
    cout << "\ngoing to die " << isAlive << endl;
    
    // death();
    }
    catch(const std::exception& e) {
         std::cout << "Exception occurred: " << e.what() << "\n";
    }
}

int Human::get_age() const{
    return age;
}

char Human::get_gender() const{
    return gender;
}
