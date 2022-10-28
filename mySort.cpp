#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <iostream>
#include <fstream>


using namespace std;

void printA(int arr[], int n)
{
    for (int i = n-1; i>=0, i--)
        cout<<arr[i];
}
struct a{
    int* pter;
    int low;
    int high;
};

void quickSort(int *array, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = array[(i + j) / 2];
    int temp;

    while (i <= j)
    {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);

    //printf("Quicksort");

}

void qsort (int arr[], int n)
{
    cout<< "Starting Array Quick Sort with "<<n<< " items\n";
    quickSort(arr,0, n-1);
    cout << "Ending Quick Sort\n";
}

// merge function for merging two parts
void merge(int arr[], int low, int mid, int high)
{
    int* left = new int[mid - low + 1];
    int* right = new int[high - mid];

    // n1 is size of left part and n2 is size
    // of right part
    int n1 = mid - low + 1, n2 = high - mid, i, j;

    // storing values in left part
    for (i = 0; i < n1; i++)
        left[i] = arr[i + low];

    // storing values in right part
    for (i = 0; i < n2; i++)
        right[i] = arr[i + mid + 1];

    int k = low;
    i = j = 0;

    // merge left and right in ascending order
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < n1) {
        arr[k++] = left[i++];
    }

    // insert remaining values from right
    while (j < n2) {
        arr[k++] = right[j++];
    }
}



void* quickSort(void* ptr)
{
    a* args = (a*) ptr;
    int *arr;
    //find low and high
    int low = args->low;
    int high = args -> high;

    quickSort(arr, low, high);

    return nullptr;


}


int main(int argc, char* argv[])
{
    int arr[16]= {12, 21,4,12,42,12,5,23,52,124,2,534,12,54,2,23};


    // Split the constructor into 8 threads
    a list1;
    list1.pter = arr;
    list1.low= 0;
    list1.high=2;

    a list2;
    list2.pter = arr;
    list2.low= 3;
    list2.high=5;

    a list3;
    list3.pter = arr;
    list3.low= 6;
    list3.high=8;

    a list4;
    list4.pter = arr;
    list4.low= 9;
    list4.high=11;

    a list5;
    list5.pter = arr;
    list5.low= 12;
    list5.high=14;

    a list6;
    list6.pter = arr;
    list6.low= 15;
    list6.high=17;

    a list7;
    list7.pter = arr;
    list7.low= 18;
    list7.high=20;

    a list8;
    list8.pter = arr;
    list8.low= 21;
    list8.high=23;



    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7;

    /* Create independent threads each of which will execute function */
     iret0 = pthread_create( &thread0, NULL, quickSort, (void*)
             &list1);
     iret1 = pthread_create( &thread1, NULL, quickSort, (void*)
             &list2);
     iret2 = pthread_create( &thread2, NULL, quickSort, (void*)
             &list3);
     iret3 = pthread_create( &thread3, NULL, quickSort, (void*)
             &list4);
    iret4 = pthread_create( &thread0, NULL, quickSort, (void*)
            &list5);
    iret5 = pthread_create( &thread1, NULL, quickSort, (void*)
            &list6);
    iret6 = pthread_create( &thread2, NULL, quickSort, (void*)
            &list7);
    iret7 = pthread_create( &thread3, NULL, quickSort, (void*)
            &list8);



    pthread_join( thread0, NULL);
    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
    pthread_join( thread3, NULL);
    pthread_join( thread4, NULL);
    pthread_join( thread5, NULL);
    pthread_join( thread6, NULL);
    pthread_join( thread7, NULL);


    merge(arr, 0, 2, 5);
    merge(arr, 6, 8, 11);
    merge(arr, 12, 14, 17);
    merge(arr, 18, 20, 23);
    merge(arr, 0, 5, 11);
    merge(arr, 12, 17, 23);
    merge(arr, 0, 11, 23);

    printA(arr, 16);


    return 0;
}
