/******************************************************************************
NAME: TANUBRATA DEY
COURSE- CSCI 135-136
INSTRUCTOR: PROF. MARYASH
TASK: E6.8

THIS PROGRAM WANTS TO CREATE A FUNCTION TO VERIFY WHETHER TWO ARRAYS HAVE SAME ELEMENTS IN SAME ORDER
*******************************************************************************/
#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size);

bool equals(int a[], int a_size, int b[], int b_size) {
    if (a_size != b_size) {
        return false;
    }
    
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    
    return true;
}
