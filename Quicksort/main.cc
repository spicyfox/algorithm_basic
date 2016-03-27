// Quicksort - lomuto partition algorithm
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

//const int N = 0x2FFFFF;
const int N = 0x2FFFFF;

int DATA[N];


void init() {
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        DATA[i] = rand() % N;
    }
}

inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(int a[], int l, int r) {
    int x = a[r];
    int i = l - 1;

    for (int j = l; j <=  r - 1; j++) {
        if (a[j] <= x) {
            i++, swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[r]);
    return i + 1;

}

void quickSort_(int a[], int l, int r) {
    if (l < r) {
        int s = partition(a, l, r);
        quickSort_(a, l, s - 1);
        quickSort_(a, s + 1, r);
    }
}

void quickSort(int a[], int l, int r) {
    if (l < r) {
        int i = l - 1;
        for (int j = l; j <= r - 1; j++) {
            if (a[j] <= a[r]) {
                i++, swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);

        quickSort(a, l, i);
        quickSort(a, i + 2, r);
    }
}
void countingSort(int a[], int l, int r) {
    //int temp[r + 1] = {0,};
    int *temp = new int[r + 1];
    for(int i = 0; i <= r; i++) {
        temp[i] = 0;
    }

    for(int i = l; i <= r; i++) {
        temp[a[i]]++;
    }

    int index = 0;
    for(int i = 0; i <= r; i++) {
        for(int j = 0; j < temp[i]; j++) {
            a[index++] = i;
        }
    }

}

void show() {
    for (int i = 0; i < N; i++) {
        printf("%d ", DATA[i]);
    }
    printf("\n");
}

typedef void (*callFunc)(int [], int, int);

void check(callFunc func, int a[], int l, int  r) {
    long start = clock();
    init();
    //show();
    func(a, l, r);
    printf("=> %.3fs\n", (float)((clock() - start)/ (float)CLOCKS_PER_SEC));
}

int main() {


    //show();
    //quickSort(DATA, 0, N - 1);
    check(quickSort, DATA, 0, N - 1);
    //show();
    check(countingSort, DATA, 0, N - 1);
    //show();

    return 0;
}