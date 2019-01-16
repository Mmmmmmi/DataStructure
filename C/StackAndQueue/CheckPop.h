

#include "Stack.h"


int CheckPop(int *in, int *out, int insize, int outsize)
{
    Stack stack;
    int ii = 0;
    int oi = 0;
    assert(in != NULL);
    assert(out != NULL);
    if(insize != outsize) {
        printf("error! \n");
        return 0;
    }
    Stack_Initialize(&stack);
    while(ii < insize) {
        if (in[ii] != out[oi]) {    //不相等
            //不相等 并且 栈顶也不相等 入站
            if(!Stack_Empty(&stack) && Stack_Top(&stack) == out[oi]) {
                    Stack_Pop(&stack);
                    oi++;
            }
            else {
                Stack_Push(&stack, in[ii]);
                ii++;
             }
        }
        else {
            ii++;
            oi++;
        }
    }
    while(!Stack_Empty(&stack)) {
        if (Stack_Top(&stack) != out[oi]) {
            printf("error！\n");
            return 0;
        }
        Stack_Pop(&stack);
        oi++;
    }
    printf("true!\n");
    return 1;
}


void CheckPopTest()
{
 //   int push[] = {1, 2, 3, 4, 5};
//    int pop[] = {5, 4, 3, 2, 1};

    
     int push[] = {1, 2, 3, 4, 5, 6, 7}; 
  // int pop[] = {4, 5, 3, 6, 2, 7, 1};
 //    int pop[] = {6, 5, 7, 4, 1, 3, 2};
   int pop[] = {5, 6, 4, 7, 2, 3, 1};
 //  int pop[] = {3, 4, 2, 5, 6, 1, 7};
    
    
    
    int pushsize = sizeof(push) / sizeof(push[0]); 
    int popsize = sizeof(pop) / sizeof(pop[0]); 
    CheckPop(push, pop, pushsize, popsize);
}
