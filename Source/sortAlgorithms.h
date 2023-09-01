#pragma once
#include "support.h"

//BUBBLE SORT--------------------------------------
void bubbleSortRunTime(int* arr, int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - 2; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]), swapped = 1;
        }
        if (!swapped)
            return;
    }
}

void bubbleSortCount(int* arr, int n, unsigned long long& com) {
    int i, j;
    bool swapped;
    for (i = 0; ++com && i < n - 1; i++) {
        swapped = 0;
        for (j = 0; ++com && j < n - 2; j++) {
            if (++com && arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]), swapped = 1;
        }
        if (!swapped)
            return;
    }
}

//SHAKER SORT--------------------------------------
void shakerSortRunTime(int* arr, int n) {
    int i, j;
    bool swapped;
    for (j = 0; j < n / 2; j++) {
        swapped = 0;
        for (i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]), swapped = 1;
            }
        }
        if (!swapped)
            return;
        swapped = 0;
        for (i = n - 2; i > j; i--) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]), swapped = 1;
            }
        }
        if (!swapped)
            return;
    }
}

void shakerSortCount(int* arr, int n, unsigned long long &com) {
    bool swapped;
    for (int j = 0;++com && j < n / 2; j++) {
        swapped = 0;
        for (int i = 0;++com && i < n - 1; i++) {
            if (++com && arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]), swapped = 1;
            }
        }
        if (!swapped)
            return;
        swapped = 0;
        for (int i = n - 2; ++com && i > j; i--) {
            if (++com && arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]), swapped = 1;
            }
        }
        if (!swapped)
            return;
    }
}

//SELECTION SORT--------------------------------------
void selectionSortRunTime(int* arr, int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

void selectionSortCount(int* arr, int n, unsigned long long& cnt_cmp) {
    int i, j, min_idx;

    for (i = 0; ++cnt_cmp && i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; ++cnt_cmp && j < n; j++)
            if (++cnt_cmp && arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

//MERGE SORT--------------------------------------

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge_RunTime(int* array, int const left, int const mid, int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    int* leftArray = dynamicArray(1 + subArrayOne),
        * rightArray = dynamicArray(1 + subArrayTwo);

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++) {
        leftArray[i] = array[left + i];
    }
    for (int j = 0; j < subArrayTwo; j++) {
        rightArray[j] = array[mid + 1 + j];
    }
    int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted 
void mergeSortRunTime(int* array, int const begin, int const end)
{
    if (begin >= end) {
        return; // Returns recursively
    }

    int mid = begin + (end - begin) / 2;
    mergeSortRunTime(array, begin, mid);
    mergeSortRunTime(array, mid + 1, end);
    merge_RunTime(array, begin, mid, end);
}

void merge_Comparison(int* array, int const left, int const mid, int const right, unsigned long long& cnt_cmp)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    int* leftArray = dynamicArray(1 + subArrayOne),
        * rightArray = dynamicArray(1 + subArrayTwo);

    for (auto i = 0; ++cnt_cmp && i < subArrayOne; i++) {
        leftArray[i] = array[left + i];
    }
    for (auto j = 0; ++cnt_cmp && j < subArrayTwo; j++) {
        rightArray[j] = array[mid + 1 + j];
    }
    int indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (++cnt_cmp && indexOfSubArrayOne < subArrayOne && ++cnt_cmp && indexOfSubArrayTwo < subArrayTwo) {
        if (++cnt_cmp && leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (++cnt_cmp && indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (++cnt_cmp && indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort_Comparison(int* array, int const begin, int const end, unsigned long long& cnt_cmp)
{
    if (++cnt_cmp && begin >= end) {
        return; // Returns recursively
    }

    auto mid = begin + (end - begin) / 2;
    mergeSort_Comparison(array, begin, mid, cnt_cmp);
    mergeSort_Comparison(array, mid + 1, end, cnt_cmp);
    merge_Comparison(array, begin, mid, end, cnt_cmp);
}

//RADIX SORT--------------------------------------

// A utility function to get maximum value in arr[]
int getMax_RunTime(int* arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }

    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void radixSortExp_RunTime(int* arr, int n, int exp)
{
    int* output = dynamicArray(1 + n);
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    delete[] output;
}

// The main function to that sorts arr[] of size n using Radix Sort
void radixSort_RunTime(int* arr, int n)
{
    int m = getMax_RunTime(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        radixSortExp_RunTime(arr, n, exp);
    }
}

//The same as runtime, but get var cnt_cmp to count the comparison of radix sort.
int getMax_Comparison(int* arr, int n, unsigned long long& cnt_cmp)
{
    int mx = arr[0];
    for (int i = 1; ++cnt_cmp && i < n; i++) {
        if (++cnt_cmp && arr[i] > mx) {
            mx = arr[i];
        }
    }

    return mx;
}

void radixSortExp_Comparison(int* arr, int n, int exp, unsigned long long& cnt_cmp)
{
    int* output = dynamicArray(1 + n);
    int i, count[10] = { 0 };

    for (i = 0; ++cnt_cmp && i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (i = 1; ++cnt_cmp && i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (i = n - 1; ++cnt_cmp && i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; ++cnt_cmp && i < n; i++) {
        arr[i] = output[i];
    }
    delete[] output;
}

void radixSort_Comparison(int* arr, int n, unsigned long long& cnt_cmp)
{
    int m = getMax_Comparison(arr, n, cnt_cmp);

    for (int exp = 1; ++cnt_cmp && m / exp > 0; exp *= 10) {
        radixSortExp_Comparison(arr, n, exp, cnt_cmp);
    }
}

//SHELL SORT--------------------------------------
void shellSortRunTime(int* arr, int n) {
    int interval, i, j, temp;

    // biến interval có giá trị = n/2 đại diện cho khoảng cách các phần tử mà ta ghép thành 1 mảng con đê thực hiện sắp xếp chèn.
    for (interval = n / 2; interval > 0; interval /= 2)
    {
        for (i = interval; i < n; i++) // Insertion sort.
        {
            temp = arr[i];
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval)
            {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
}

void shellSortCount(int* a, int n, unsigned long long& tmp) {
    int interval, i, j, temp;
    for (interval = n / 2; ++tmp && interval > 0; interval /= 2)
    {
        for (i = interval; ++tmp && i < n; i++)
        {
            temp = a[i];
            for (j = i; ++tmp && j >= interval && ++tmp && a[j - interval] > temp; j -= interval)
            {
                a[j] = a[j - interval];
            }
            a[j] = temp;
        }
    }
}

//QUICK SORT--------------------------------------
void quickSortRunTime(int* arr, int l, int r) {
    int p = arr[(l + r) / 2];

    int i = l, j = r;

    while (i < j) {
        while (arr[i] < p)
        {
            i++;
        }
        while (arr[j] > p) {
            j--;
        }
        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (i < r) {
        quickSortRunTime(arr, i, r);
    }
    if (l < j) {
        quickSortRunTime(arr, l, j);
    }
}

void quickSortCount(int* arr, int l, int r, unsigned long long& tmp) {

    int p = arr[(l + r) / 2];

    int i = l, j = r;

    while (++tmp && i < j) {
        while (++tmp && arr[i] < p)
        {
            i++;
        }
        while (++tmp && arr[j] > p) {
            j--;
        }
        if (++tmp && i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    if (++tmp && i < r) {
        quickSortCount(arr, i, r, tmp);
    }
    if (++tmp && l < j) {
        quickSortCount(arr, l, j, tmp);
    }
}

//HEAP SORT--------------------------------------
void heapConstructCount(int* arr, int n, int i, unsigned long long& tmp)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (++tmp && l < n && ++tmp && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (++tmp && r < n && ++tmp && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (++tmp && largest != i)
    {
        swap(arr[i], arr[largest]);
        heapConstructCount(arr, n, largest, tmp);
    }
}

void heapSortCount(int* arr, int n, unsigned long long& tmp)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; ++tmp && i >= 0; i--)
        heapConstructCount(arr, n, i, tmp);

    // One by one extract an element
    // from heap
    for (int i = n - 1; ++tmp && i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapConstructCount(arr, i, 0, tmp);
    }
}

void heapConstructRunTime(int arr[], int n, int i)
{
    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int l = 2 * i + 1;

    // right = 2*i + 2
    int r = 2 * i + 2;
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    // If right child is larger than largest
    // so far
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapConstructRunTime(arr, n, largest);
    }
}
// Main function to do heap sort
void heapSortRunTime(int* arr, int n) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapConstructRunTime(arr, n, i);

    // One by one extract an element
    // from heap
    for (int i = n - 1; i > 0; i--) {

        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapConstructRunTime(arr, i, 0);
    }
}

//INSERTION SORT--------------------------------------
void insertionSortCount(int* arr, int n, unsigned long long& comp)
{
    int i, key, j;
    for (i = 1; ++comp && i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (++comp && j >= 0 && ++comp && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void insertionSortRunTime(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;

        }

        arr[j + 1] = key;
    }
}

//COUNTING SORT--------------------------------------
void countingSortCount(int input[], int n, unsigned long long& count)
{
    int* output = dynamicArray(1 + n); // The output will have sorted input array
    int max = input[0];
    int min = input[0];
    for (int i = 1; ++count && i < n; i++)
    {
        if (++count && input[i] > max)
        {
            max = input[i];
        }
        else if (++count && input[i] < min)
        {
            min = input[i];
        }
    }

    int k = max - min + 1; // Size of count array

    int* count_array = dynamicArray(1 + k); // Create a count_array to store count of each individual input value
    fill_n(count_array, k, 0); // Initialize count_array elements as zero

    for (int i = 0; ++count && i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for (int i = 1; ++count && i < k; i++)
        count_array[i] += count_array[i - 1];


    // Populate output array using count_array and input array
    for (int i = 0; ++count && i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }

    for (int i = 0; ++count && i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values
    delete[] output;
    delete[]count_array;
}
void countingSortRunTime(int input[], int n)
{
    int* output = dynamicArray(1 + n); // The output will have sorted input array
    int max = input[0];
    int min = input[0];

    for (int i = 1; i < n; i++)
    {
        if (input[i] > max)
        {
            max = input[i];
        }
        else if (input[i] < min)
        {
            min = input[i];
        }
    }

    int k = max - min + 1; // Size of count array

    int* count_array = dynamicArray(1 + k); // Create a count_array to store count of each individual input value
    fill_n(count_array, k, 0); // Initialize count_array elements as zero

    for (int i = 0; i < n; i++)
        count_array[input[i] - min]++; // Store count of each individual input value

    /* Change count_array so that count_array now contains actual
     position of input values in output array */
    for (int i = 1; i < k; i++)
        count_array[i] += count_array[i - 1];


    // Populate output array using count_array and input array
    for (int i = 0; i < n; i++)
    {
        output[count_array[input[i] - min] - 1] = input[i];
        count_array[input[i] - min]--;
    }


    for (int i = 0; i < n; i++)
        input[i] = output[i]; // Copy the output array to input, so that input now contains sorted values

    delete[] output;
    delete[]count_array;
}

//FLASH SORT--------------------------------------
void flashSortCount(int a[], int n, unsigned long long& count)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int* l = dynamicArray(1 + m);
    for (int i = 0; ++count && i < m; i++)
        l[i] = 0;
    for (int i = 1; ++count && i < n; i++)
    {
        if (++count && a[i] < minVal)
        {
            minVal = a[i];
        }
        if (++count && a[i] > a[max])
        {
            max = i;
        }
    }
    if (++count && a[max] == minVal)
    {
        return;
    }
    double c1 = (double(m) - 1.0) / (double(a[max]) - minVal);
    for (int i = 0; ++count && i < n; i++)
    {
        int k = int(c1 * (double(a[i]) - minVal));
        ++l[k];
    }
    for (int i = 1; ++count && i < m; i++)
        l[i] += l[i - 1];
    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++count && nmove < n - 1)
    {
        while (++count && j > l[k] - 1)
        {
            j++;
            k = int(c1 * (double(a[j]) - minVal));
        }
        flash = a[j];
        if (++count && k < 0)
        {
            break;
        }
        while (++count && j != l[k])
        {
            k = int(c1 * (double(flash) - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    //Insertion sort
    int q, key, p;

    for (q = 1; ++count && q < n; q++)
    {
        key = a[q];
        p = q - 1;

        while (++count && p >= 0 && ++count && a[p] > key)
        {
            a[p + 1] = a[p];
            p = p - 1;

        }

        a[p + 1] = key;
    }
}
void flashSortRunTime(int a[], int n)
{
    int minVal = a[0];
    int max = 0;
    int m = int(0.45 * n);
    int* l = dynamicArray(1 + m);
    for (int i = 0; i < m; i++)
        l[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
        {
            minVal = a[i];
        }
        if (a[i] > a[max])
        {
            max = i;
        }
    }
    if (a[max] == minVal)
    {
        return;
    }
    double c1 = (double(m) - 1.0) / (double(a[max]) - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (double(a[i]) - minVal));
        l[k]++;
    }
    for (int i = 1; i < m; i++)
        l[i] += l[i - 1];
    swap(a[max], a[0]);
    int nmove = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (nmove < n - 1)
    {
        while (j > l[k] - 1)
        {
            j++;
            k = int(c1 * (double(a[j]) - minVal));
        }
        flash = a[j];
        if (k < 0)
        {
            break;
        }
        while (j != l[k])
        {
            k = int(c1 * (double(flash) - minVal));
            int hold = a[t = --l[k]];
            a[t] = flash;
            flash = hold;
            ++nmove;
        }
    }
    delete[] l;
    //Insertion sort
    int q, key, p;

    for (q = 1; q < n; q++)
    {
        key = a[q];
        p = q - 1;

        while (p >= 0 && a[p] > key)
        {
            a[p + 1] = a[p];
            p = p - 1;

        }

        a[p + 1] = key;
    }
}
