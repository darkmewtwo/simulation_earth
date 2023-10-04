#include <iostream>
#include <chrono>
#include <atomic>
#include <thread>
#include <signal.h>
#include "human.h"
#include "world.h"
using namespace std;

// std::atomic<bool> terminateFlag(false);

// void handleKeyboardInterrupt(int signum)
// {
//     std::cout << "Keyboard interrupt received. Terminating...\n";
//     terminateFlag = true;
// }

int main()
{
    // signal(SIGINT, handleKeyboardInterrupt);

    // Human *p = new Human(12, 'M');
    // // {
    // // Human* p = new Human(12, 'M');

    // //
    // // std::this_thread::sleep_for(std::chrono::seconds(5));
    // // delete p;
    // cout << "\n when do we get here\n";
    // // p->death();
    // while (!terminateFlag)
    // {
    //     Human n(19, 'F');
    // }
    // cout << "haha";
    // return 0;
    // p->aging();

    World world;
    world.run_world();

}