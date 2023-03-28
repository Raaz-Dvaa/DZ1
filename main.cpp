#include <iostream>
#include <ctime>
#include <chrono>
#include "sorts.h"
#include <fstream>

void randAr(int* a,int size){
    srand(time(NULL));
    for(int i = 0; i<size; i++){
        int x;
        a[i] = std::rand();
    }
}

int main() {

    void(*sorts[6])(int*, int) = {count_Sort,quick_Sort, merge_Sort, select_Sort, insert_Sort, bubble_Sort};

    FILE* res = fopen("res.txt", "w");
    float sort_time = 0;
    int c1 = 6;
    for (int i = 1000; c1 > 0 && i < 2000000; i = i*1.1){
       float* values = new float[4];
           for (int c = 0; c < c1; c++) {
               int *ar = new int[i];
               randAr(ar, i);
               auto start = std::chrono::high_resolution_clock::now();
               spawn_Sort(sorts[c], ar, i);
               auto end = std::chrono::high_resolution_clock::now();
               test_sort(ar, i);
               std::chrono::duration<float> duration = end - start;
               sort_time = duration.count();
               if (sort_time > 20) {
                   values[c] = sort_time;
                   c1--;
               }
               values[c] = sort_time;
               delete[] ar;
           }
           fprintf(res,"\n%u\t", i);
           for (int n = 0; n < c1; n++) {
               fprintf(res,"%f\t", values[n]);
           }
       delete[] values;
    }
    fclose(res);
    return 0;
}
