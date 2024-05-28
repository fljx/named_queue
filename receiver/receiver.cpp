#include <boost/interprocess/ipc/message_queue.hpp>
#include <thread>
#include <chrono>
#include <iostream>
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

    unsigned int priority;
    boost::interprocess::message_queue::size_type recvd_size;
    
    while(running)
    {
        std::cout << "Server waiting for message...";
        ipc::message    msg;

        if (queue.try_receive(
            &msg, sizeof(msg), recvd_size, priority))
        {
            print(msg);
            std::cout << "\n";
        }

        std::this_thread::sleep_for(1s);
    }
}