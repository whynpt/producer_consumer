#ifndef PRODUCER_H
#define PRODUCER_H

#include "User.h"

class Producer : virtual public User {
private:
    status_t getBuffers(int* outputBuffer);
    status_t dequeueBuffer(int& index);
    status_t queueBuffer(int index);
};
#endif