

#include "Stack.h"




typedef struct HTStack {
    DataType *array;
    int Capacity;
    int Top1;
    int Top2;
}HTStack;


void HTStackInitialize(HTStack *pHTStack)
{
    assert(pHTStack != NULL);
    pHTStack->array = (DataType *) malloc (sizeof(HTStack) * DEFAULT_CAPACITY);
    assert(pHTStack->array != NULL);
    pHTStack->Capacity = DEFAULT_CAPACITY;
    pHTStack->Top1 = 0;
    pHTStack->Top2 = pHTStack->Capacity - 1;
}


void HTStackDestroy(HTStack *pHTStack)
{
    assert(pHTStack != NULL);
    free(pHTStack->array);
    pHTStack->array = NULL;
    pHTStack->Capacity = 0;
    pHTStack->Top1 = 0;
    pHTStack->Top2 = 0;
}

void CheckCapacity(HTStack *pHTStack)
{
    int i1 = 0;
    int i2 = 0;
    int newcapacity = 0;
    DataType *newarray = NULL;
    assert(pHTStack != NULL);
    if(pHTStack->Top1 == pHTStack->Top2 + 1) {
        newcapacity = pHTStack->Capacity * 2;
        newarray = (DataType *) malloc (sizeof(DataType) * newcapacity);
        assert(newarray != NULL);
        //挪1
        
        for(i1 = 0; i1 < pHTStack->Top1; i1++) {
            newarray[i1]  = pHTStack->array[i1];
        }


        //挪2
        for(i2 = pHTStack->Capacity - 1; i2 > pHTStack->Top2; i2--) {
            newarray[i2 + pHTStack->Capacity] = pHTStack->array[i2];
        }

        pHTStack->Top2 += (newcapacity - pHTStack->Capacity);
        pHTStack->array = newarray;
        pHTStack->Capacity = newcapacity;
    }
}

void HTStackPush1(HTStack *pHTStack, DataType data)
{
    assert(pHTStack != NULL);
    CheckCapacity(pHTStack);
    pHTStack->array[pHTStack->Top1] = data;
    pHTStack->Top1 += 1;
}

                                                      
void HTStackPush2(HTStack *pHTStack, DataType data)   
{                                                     
    assert(pHTStack != NULL);                         
    CheckCapacity(pHTStack);                          
    pHTStack->array[pHTStack->Top2] = data;           
    pHTStack->Top2 -= 1;                              
}                                   

DataType HTStackTop1(HTStack *pHTStack)
{   
    assert(pHTStack != NULL);
    assert(pHTStack->Top1 >= 0);
    return pHTStack->array[pHTStack->Top1 - 1]; 
}


DataType HTStackTop2(HTStack *pHTStack)     
{                                           
    assert(pHTStack != NULL);               
    assert((pHTStack->Top2) <= (pHTStack->Capacity));            
    return pHTStack->array[pHTStack->Top2 + 1]; 
}                                           

void HTStackPop1(HTStack *pHTStack)
{
    assert(pHTStack != NULL);                 
    if(pHTStack->Top1 == 0) {
        return;
    }
    pHTStack->Top1 -= 1;                         
}


void HTStackPop2(HTStack *pHTStack)           
{ 
    assert(pHTStack != NULL);                 
    if(pHTStack->Top2 == pHTStack->Capacity - 1) {    
         return;                  
    }                            
    pHTStack->Top2 += 1;                                     
}                                             

int HTStackEmpty1(HTStack *pHTStack)
{
    return pHTStack->Top1 == 0;
}


int HTStackEmpty2(HTStack *pHTStack)   
{                                      
    return pHTStack->Top2 == pHTStack->Capacity - 1;        
}                                      

void HTStackTest()
{
    HTStack htstack;
    HTStackInitialize(&htstack);
    HTStackPush1(&htstack, 1);
    
 //   printf("%d ", htstack.Top1); 
 //   printf("%d ", htstack.Top2); 
    
 //   printf("\n");                     
    
    HTStackPush1(&htstack, 2);
  
//    printf("%d ", htstack.Top1);   
//    printf("%d ", htstack.Top2);     
//    printf("\n");                    
    HTStackPush1(&htstack, 3);
    HTStackPush2(&htstack, 4);
  
//    printf("%d ", htstack.Top1);   
//    printf("%d ", htstack.Top2);      
//    printf("\n");                     
   
    HTStackPush2(&htstack, 5);
    HTStackPush2(&htstack, 6);
  
//    printf("%d ", htstack.Top1);   
//    printf("%d ", htstack.Top2);   
//    printf("\n");                  
    
    HTStackPush2(&htstack, 7);
    
//    printf("%d ", htstack.Top1);
//    printf("%d ", htstack.Top2);
//    printf("\n");
    while(!HTStackEmpty1(&htstack)) {
        printf("%d ", HTStackTop1(&htstack));
        HTStackPop1(&htstack);
    }

    printf("\n");                              
    while(!HTStackEmpty2(&htstack)) {          
        printf("%d ", HTStackTop2(&htstack));  
        HTStackPop2(&htstack);                 
    }  
    printf("\n");                      
   // printf("%d ", HTStackTop2(&htstack));  
  //  HTStackPop2(&htstack);                 

//    printf("%d ", HTStackTop2(&htstack));  
 //   HTStackPop2(&htstack);                 

 //   printf("%d ", HTStackTop2(&htstack));  
  //  HTStackPop2(&htstack);                 
       
    printf("%d ", htstack.Top1);       
    printf("%d ", htstack.Top2);       
    printf("\n");                      
 //   printf("\n");

    HTStackDestroy(&htstack);


}
