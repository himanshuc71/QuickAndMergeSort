#include <iostream>

using namespace std;

void merge(int *ar, int low, int mid, int high) {
    int temp[high + 1];
    int leftStart = low;
    int rightStart = mid + 1;
    int leftEnd = mid;
    int rightEnd = high;
    int indexTemp = leftStart;

    while (leftStart <= leftEnd && rightStart <= rightEnd) {
        if (ar[leftStart] <= ar[rightStart]) {
            temp[indexTemp] = ar[leftStart];
            leftStart++;
        } else {
            temp[indexTemp] = ar[rightStart];
            rightStart++;
        }
        indexTemp++;
    }
    // remaining in leftSubArray
    while (leftStart <= leftEnd) {
        temp[indexTemp] = ar[leftStart];
        indexTemp++;
        leftStart++;
    }
    //remaining in rightSubArray
    while (rightStart <= rightEnd) {
        temp[indexTemp] = ar[rightStart];
        indexTemp++;
        rightStart++;
    }
    // copy all sorted elements from temp back to the original array
    for (int i = low; i < high + 1; i++) {
        ar[i] = temp[i];
    }

}

void mergeSort(int *ar, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        // sort the left half
        mergeSort(ar, low, mid);
        //sort the right half
        mergeSort(ar, mid + 1, high);
        // merge the sorted half
        merge(ar, low, mid, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int pI=high;
    while (low < high) {
        while (arr[low] < pivot) {
            low++;
        }
        while (arr[high] >= pivot) {
            high--;
        }
        if (low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
            low++;
            high--;
        }
    }
    int temp=arr[low];
    arr[low]=arr[pI];
    arr[pI]=temp;

    return low;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}


int main() {
    int array[10] = {5, 3, 7, 10, 33, 44, 43, 7, 23, 14};

    for (int i = 0; i < 10; i++) {
        cout << "Element" << i << "=" << array[i] << " ";
    }
    cout << endl;

    quickSort(array,0,9);

    for (int i = 0; i < 10; i++) {
        cout << "Element" << i << "=" << array[i] << endl;
    }

    return 0;
}