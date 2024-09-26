#include "sort_algorithms.h"
#include <algorithm>
#include <iostream>

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size; ++i){
        int max_index = 0;
        for(int j = 0; j < size - i; j++){
            if(arr[max_index] < arr[j]){
                max_index = j;
            }
        }
        std::swap(arr[size - i-1],arr[max_index]);
    }
}

void bubbleSort(int arr[], int size){
while(size != 0){
    for(int i = 1; i < size; ++i){
        if(arr[i] < arr[i-1]){
            std::swap(arr[i],arr[i -1]);
        }
    }
    size--;
}

}

void insertsSort(int arr[], int size){
    for(int i = 1; i < size; ++i){
        int index = i - 1;
        while((arr[index] > arr[index + 1])&&(index >= 0)){ 
            std::swap(arr[index], arr[index + 1]);
            --index;
        }
    }
}


int  huaraSharing(int arr[], int left, int right){
    int p = arr[(rand()%(right - left) + left)];//(right + left)/2
    while(left <= right){
        while(arr[left] < p){   ++left;     }
        while (arr[right] > p){ --right;    }
        if(left <= right)   {
            std::swap( arr[left], arr[right] );  
            ++left;
            --right;
        }
    }
    return left;
}


void _HuaraSort(int arr[], int start ,int end){
    if(start >= end){return;}
    int left = huaraSharing( arr, start, end);
    _HuaraSort(arr, start , left - 1);
    _HuaraSort(arr, left , end);
}

void fastSortHuara(int arr[], int size){
    _HuaraSort(arr, 0 , size - 1);

}



void merge(int arr[], int left, int  right){
    int mid = (left + right)/2;
    int arr1index = left;
    int arr2index = mid + 1;
    int size = right - left + 1;
    int *tmp = new int(size);
    for (int step = 0; step < size; step++)
    {

        if ( (arr2index > right)||( (arr1index <= mid)&&(arr[arr1index] < arr[arr2index]) ) ){
            tmp[step] = arr[arr1index];
            arr1index++;
        }
        else{
            tmp[step] = arr[arr2index];
            arr2index++;
        }
    }
    for (int step = 0; step < size; step++){
        arr[left + step] = tmp[step];
    }
    delete [] tmp;
}


void _mergeSort(int arr[], int left ,int right){
    if(left == right){ return; }
    int centerElementIndex = ( left + right ) / 2;
    _mergeSort( arr, left, centerElementIndex );
    _mergeSort( arr, centerElementIndex + 1, right );
    merge(arr, left , right);
}


void mergerSort(int arr[], int size){
    _mergeSort(arr, 0, size - 1);
}