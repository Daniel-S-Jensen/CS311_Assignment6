#include <iostream>
#include <ctime>

void allocate(int length);

int main() {

    // create time variables
    clock_t startTime = 0;
    clock_t endTime = 0;

    // create variable to hold difference in time
    double seconds;

    // In a loop that runs from 0 to 1,000,000, allocate an array of 100,000 doubles statically (before runtime)
    std::cout << "A took: ";
    startTime = clock();
    double array [100000];
    for (int i = 0; i < 100000; i++) {
        array[i] = i;
    }
    endTime = clock();
    seconds = endTime - startTime;
    std::cout << seconds << " seconds" << std::endl;

    //In a second loop that runs from 0 to 1,000,000 allocate an array of 100,000 doubles on the run time stack (a variable in a function)
    std::cout << "B took: ";
    startTime = clock();
    allocate(100000);

    endTime = clock();
    seconds = endTime - startTime;
    std::cout << seconds << " seconds" << std::endl;

    //In a third loop create an array of 100,000 doubles dynamically  (at runtime).
    std::cout << "C took: ";
    startTime = clock();
    double * array3;
    array3 = new double[100000];
    for (int i = 0; i < 100000; i++) {
        array3[i] = i;
    }

    endTime = clock();
    seconds = endTime - startTime;
    std::cout << seconds << " seconds" << std::endl;

    delete [] array3;

    return 0;
}

void allocate(int length) {
    double array2 [length];
    for (int i = 0; i < length; i++) {
        array2[i] = i;
    }
}