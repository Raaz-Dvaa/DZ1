#include <iostream>
#include "sorts.h"

void test_sort (int* ar, int size){
    for (int k = 0; k < size - 1;k++){
        if (ar[k] - ar[k+1] > 0){
            std::cout << "fail";
            break;
        }
    }
}

int getMax(int* ar, int size){
    int max = 0;
    int i=1;
    while (i<size){
        if (ar[max] < ar[i]) {
            max = i;
        }
        i++;
    }
    return max;
}

void select_Sort (int* ar, int size){
    while (size) {
        int indMax = getMax(&ar[0], size);
        std::swap(ar[indMax], ar[size - 1]);
        size--;
    }
}

void insert_Sort (int* ar, int size){
    for(int i = 1 ;i < size ;i++)
        for(int j = i ;j > 0 && ar[j-1] > ar[j];j--)
            std::swap(ar[j-1],ar[j]);
}

void bubble_Sort (int* ar, int size){
    for (int i = 0; i < size; i++) {
        bool sorted = true;
        for (int j = 0; j < size - (i + 1); j++) {
            if (ar[j] > ar[j + 1]) {
                sorted = false;
                std::swap(ar[j], ar[j + 1]);
            }
        }
        if (sorted) {
            break;
        }
    }
}

void count_Sort(int* ar, int size) {

    int max = ar[0];

    for (int i = 1; i < size; i++) {
        if (ar[i] > max)
            max = ar[i];
    }

    int* output = new int[size];
    int* count = new int[max+1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[ar[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[ar[i]] - 1] = ar[i];
        count[ar[i]]--;
    }
    for (int i = 0; i < size; i++) {
        ar[i] = output[i];
    }
    delete[] output;
    delete[] count;
}
void spawn_Sort(void(*sorts)(int*, int),int* ar,int size){
    sorts(ar, size);
}

int partition(int* a, int first, int last)
{

    int i = first, j = last;
    int pivot = a[(first + last) / 2];

    while (true) {
        while (a[i] < pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i >= j)
            break;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
        i++;
        j--;
    }
    return j;
}
void quicksort1(int* a, int first, int last) {
    if (first < last) {
        int p = partition(a, first, last);
        quicksort1(a, first, p);
        quicksort1(a, p + 1, last);
    }
}
void quick_Sort(int* a, int size){
    quicksort1 (a, 0, size-1);
}

void merge(int* array, int left, int mid, int right)
{
    int const sizeOne = mid - left + 1;
    int const sizeTwo = right - mid;
    int *leftArray = new int[sizeOne], *rightArray = new int[sizeTwo];
    for (int i = 0; i < sizeOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < sizeTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0,
            indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < sizeOne
           && indexOfSubArrayTwo < sizeTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                    = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                    = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < sizeOne) {
        array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < sizeTwo) {
        array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort1(int* array, int begin, int end) {
    if (begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    mergeSort1(array, begin, mid);
    mergeSort1(array, mid + 1, end);
    merge(array, begin, mid, end);
}
void merge_Sort (int* ar, int size){
    mergeSort1(ar, 0, size-1);
}