#define TEST_HASHING
#define TEST_STATIC_STACK
#define TEST_DYNAMIC_STACK
#define TEST_QUEUE

#ifdef TEST_HASHING
#include "hashing.h"
#endif

#ifdef TEST_STATIC_STACK
#include "static_stack.h"
#endif

#ifdef TEST_DYNAMIC_STACK
#include "dynamic_stack.h"
#endif

#ifdef TEST_QUEUE
#include "queue.h"
#endif