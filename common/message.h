#ifndef MESSAGE_H_
#   define MESSAGE_H_


namespace ipc
{
    struct message
    {
        unsigned    pid;
        unsigned long timestamp;
    };
    
} // namespace ipc

#endif // MESSAGE_H_
