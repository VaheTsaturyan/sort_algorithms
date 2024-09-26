#include "sort_algorithms.h"
#include <iostream>
#include <functional>



void test(std::function<void(int[], int)> sort){
        int arr[10] = {9,15,3,7,4,19,20,11,10,3};
        sort(arr,10);
        for(auto el : arr){
            std::cout<<el<<'\t';
        }
        std::cout<<std::endl;
}



int main(){

    test(&selectionSort);
    test(&bubbleSort);
    test(&insertsSort);
    test(&fastSortHuara);
    test(&mergerSort);

    return 0;
}