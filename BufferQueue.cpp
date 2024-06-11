#include <iostream>
#include <iomanip>
#include "include/BufferQueue.h"

#define BUFFER_QUEUE_LOCK const std::lock_guard<std::mutex> lock(mMutex)
using namespace std;


BufferQueue::BufferQueue() {
    mBuffer = new int[sCapacity];
    for (int i = 0; i < sCapacity; i++) {
        mBufferInUse[i] = false;
    }
}

BufferQueue::~BufferQueue() {
    delete[] mBuffer;
}

status_t BufferQueue::dequeue(int& index) {
    BUFFER_QUEUE_LOCK;
    for (int i = 0; i < sCapacity; i++) {
        if (!mBufferInUse[i]) {
            index = i;
            mBufferInUse[i] = true;
            return OK;
        }
    }
    return ERROR;
}

status_t BufferQueue::queue(int index) {
    BUFFER_QUEUE_LOCK;
    if (mBufferInUse[index]) {
        mBufferInUse[index] = false;
        return OK;
    } else {
        return ERROR;
    }
}

status_t BufferQueue::getBuffers(int* buffer) {
    BUFFER_QUEUE_LOCK;
    mBuffer = buffer;
    return OK;
}
#ifdef DEBUG_BUFFERQUEUE
void BufferQueue::printBufferQueue() {
    for (int i = 0; i < sCapacity; i++) {
        cout << std::setw(6) << mBuffer[i];
        if (i % 4 == 3) {
            cout <<endl;
        }
    }
}
#endif