#include <iostream>
#include <typeinfo>
int main()
{
    int arraylist[] = {2,4,5,6,7};

    
    int lenlist = sizeof(arraylist)/sizeof(arraylist[0]);//length
    int *poi = arraylist + lenlist;//addressing after array end
    *poi = arraylist[0]; //assign tail to pointer
    int *nuin = &arraylist[1];//take head address
    for (int i = 1; i < lenlist+1; i++)
    {
        std::cout << "array "<< i <<": " << *nuin << std::endl;
        nuin++;
    }

    return 0;
}