#ifndef PRODUCER_CONSUMER_BUFFERQUEUE_H
#define PRODUCER_CONSUMER_BUFFERQUEUE_H

#include <mutex>

#define DEBUG_BUFFERQUEUE

typedef enum {
    OK,
    ERROR,
} status_t;
class BufferQueue {
public:
    BufferQueue();
    ~BufferQueue();

private:
    static const int sCapacity = 32;
    int* mBuffer;
    bool mBufferInUse[sCapacity];
    std::mutex mMutex;

    status_t getBuffers(int* buffer);
    status_t dequeue(int& index);
    status_t queue(int index);

#ifdef DEBUG_BUFFERQUEUE
    void printBufferQueue();
#endif
};
#endif