#include <boost/interprocess/ipc/message_queue.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <unistd.h> // getpid

#include "message.h"

using namespace std::chrono_literals;

bool running = true;

void print(const ipc::message &msg)
{
    std::cout << "{pid: "<< msg.pid
        << ", timestamp: " << msg.timestamp << "}";
}

int main()
{
    boost::interprocess::message_queue queue(
        boost::interprocess::open_or_create,
        "named_queue",
        8,  // Max messages in queue.
        sizeof(ipc::message)
    );

    pid_t pid = getpid();

    unsigned int priority = 0;
    
    while(running)
    {
        std::cout << "Preparing to send message...";
        ipc::message    msg{
            static_cast<decltype(msg.pid)>(pid),
            static_cast<decltype(msg.timestamp)>(std::chrono::seconds(std::time(nullptr)).count()           )
        };

        if (queue.try_send(
            &msg, sizeof(msg), priority))
        {
            print(msg);
            std::cout << "\n";
        }

        std::this_thread::sleep_for(800ms);
    }
}
