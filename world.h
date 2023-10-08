#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <mutex>
#include <unordered_map>

#include <map>
#include "human.h"

class World
{

public:
     std::unordered_map<std::string, std::thread> threadMap;
    std::unordered_map<int, Human> humans;
    std::mutex map_mutex_;
    void run_world();
    void life(int age, char gender);
    void new_human(const Human& human);
    void new_life(const Human& human1, const Human& human2);
    // void life();
};

#endif