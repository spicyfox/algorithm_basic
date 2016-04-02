//- Binary Search

#include <cstdio>


int binarySearch2(int a[], int n, int key) {

    int low = 0;
    int high = n -1 ;
    int mid;

    while(low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            high = mid - 1;
        } else { // a[mid] < n
            low = mid + 1;
        }
 
    }

    return -1;

}

int binarySearch(int a[], int start, int end, int key) {
    int mid = (start + end) / 2;

    if (start <= end ) {
        if (a[mid] == key) {
            return mid;
        } else if (a[mid] > key) {
            return binarySearch(a, start, mid - 1, key);
        } else if (a[mid] < key) {
            return binarySearch(a, mid + 1, end, key);
        }
    }

    return -1;
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 1; i <= 10; i++) {
        printf("> %d %d\n", binarySearch2(data, 10, i), binarySearch(data, 0, 9, i));     
    }


    return 0;
}