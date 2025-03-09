#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

// typedef struct EventLess {
//       bool operator()(const Event* a, const Event* b) const {
//       return a->time > b->time;  // Min-heap: earlier times have higher priority
//       }
//       //write the operator() required to make this a functor that compares Events by time
// } EventLess;
	
struct EventLess {
    bool operator()(const Event* a, const Event* b) const {
        if (a->time == b->time)
            return a->wire->getId() > b->wire->getId();
        return a->time > b->time;
    }
};


#endif