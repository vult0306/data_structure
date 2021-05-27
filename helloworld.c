#include "helloworld.h"

#ifdef TEST_HASHING
int test_hashing(void);
#endif
#ifdef TEST_STATIC_STACK
int test_static_stack(void);
#endif
#ifdef TEST_DYNAMIC_STACK
int test_dynamic_stack(void);
#endif
#ifdef TEST_QUEUE
int test_queue(void);
#endif


int main()
{
#ifdef TEST_HASHING
    test_hashing();
#endif

#ifdef TEST_STATIC_STACK
    test_static_stack();
#endif

#ifdef TEST_DYNAMIC_STACK
    test_dynamic_stack();
#endif
#ifdef TEST_QUEUE
    test_queue();
#endif

    return 0;
}

#ifdef TEST_HASHING
int test_hashing(void)
{
    dummyItem = (struct dataItem*) malloc(sizeof(struct dataItem));
    dummyItem->data = -1;  
    dummyItem->key = -1; 

    insert(1, 21);
    insert(2, 71);
    insert(42, 81);
    insert(52, 91);
    insert(62, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();
    item = search(91);

    if(item != NULL) {
            printf("Element found: %d\n", item->data);
    } else {
            printf("Element not found\n");
    }
    return 0;
}
#endif

#ifdef TEST_STATIC_STACK
int test_static_stack(void)
{
    struct Stack* stack = ss_createStack(100);
 
    ss_push(stack, 10);
    ss_push(stack, 20);
    ss_push(stack, 30);
 
    printf("%d popped from stack\n", ss_pop(stack));
 
    return 0;
}
#endif

#ifdef TEST_DYNAMIC_STACK
int test_dynamic_stack(void)
{
    struct StackNode* root = NULL;
 
    ds_push(&root, 10);
    ds_push(&root, 20);
    ds_push(&root, 30);
 
    printf("%d popped from stack\n", ds_pop(&root));
 
    printf("Top element is %d\n", ds_peek(root));
 
    return 0;
}
#endif

// Driver program to test above functions./
int test_queue()
{
    struct Queue* queue = q_createQueue(1000);
 
    q_enqueue(queue, 10);
    q_enqueue(queue, 20);
    q_enqueue(queue, 30);
    q_enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",
           q_dequeue(queue));
 
    printf("Front item is %d\n", q_front(queue));
    printf("Rear item is %d\n", q_rear(queue));
 
    return 0;
}