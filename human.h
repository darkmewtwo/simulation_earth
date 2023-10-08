#ifndef HUMAN_H
#define HUMAN_H
#include <chrono>
#include <random>
#include <atomic>
#include <thread>

class Human
{

private:
    char gender;
    int age;
    std::chrono::high_resolution_clock::time_point timeOfBirth;
    std::chrono::high_resolution_clock::time_point timeOfDeath;
    // std::random_device rd;
    std::mt19937 gen;  // Mersenne Twister engine

    // Define a distribution (in this case, integers between 1 and 100)
    std::uniform_int_distribution<int> distribution;
    // std::atomic<bool> isAlive;
    bool isAlive;
    // std::thread lifeTimeThread;


public:
    Human& operator=(const Human& other) {
        // Implement the assignment logic as needed
        // For example, you may need to copy member variables
        // and handle any resource management.
        // This is a simple example assuming you have member variables 'name' and 'age'.
        this->gender = other.gender;
        this->age = other.age;
        return *this;
    }
    Human(): age(0), gender('O') {}
    Human(int age,char gender);
    void death();
    ~Human();
    void aging();
    int get_age() const;
    char get_gender() const;
};

#endif