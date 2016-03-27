//- Binary Search

#include <cstdio>


int binarySearch(int a[], int n, int key) {

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

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", binarySearch(data, 10, 10));

    return 0;
}