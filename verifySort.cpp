//
// Created by Kiet Nguyen on 10/19/2022.
//
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;
/* test to ensure that the array is in sorted order */
void verifySort(int arr[]) {
    int temp = 0;
    for (int i = 1; i < 1000000; i ++) {
        if (arr[i] >= arr[i - 1]) {
            temp = arr[i];
        } else {
            printf("Array is not sorted\n");
            return;
        }
    }
    printf("\nArray is sorted\n");
}
int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Please include input filename and output filename in param list.\n";
        cout << "Example:\n";
        cout << "     % mySort numbers.txt mySorted.txt\n";
        exit(EXIT_SUCCESS);
    }
    const int MAX = 1000000;
    ofstream fout;
    ifstream fin;
    int n;

    int arr[MAX];
    int count = 0;

    fin.open(argv[1]);
    while (fin >> n )
    {
        arr[count++] = n;	// insert a number into the array and increase the index
    }

    verifySort(arr);
    cout<<"Array Size: "<<end(arr) - begin(arr)<<endl;

    fout.open(argv[2], ios::out | ios::trunc);
    for (int i = 0; i < count; i++)
        fout << arr[i]<<endl;


    fout.close();
    fin.close();

    verifySort(arr);
    return 0;
}

