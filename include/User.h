#ifndef USER_H
#define USER_H

typedef int status_t;
class User {
public:
    virtual status_t getBuffers(int* outputBuffer) = 0;
    virtual status_t dequeueBuffer(int& index) = 0;
    virtual status_t queueBuffer(int index) =  0;
};
#endif