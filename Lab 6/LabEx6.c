#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Worker structure
struct worker
{
    int id;
    int workerAge;
    char workerName[50]; 
};

// Counters for comparisons and data transfer operations
int mergeSortComparisons = 0;
int mergeSortDataTransfers = 0;

int quickSortComparisons = 0;
int quickSortDataTransfers = 0;

const char *predefinedNames[] = {"Alice", "Varun", "Bob", "Rahul", "Sonia", "Muhammed", "Micheal", "Manu", "Timmy", "Rodrigues", "Charlie", "David", "Emma", "Frank", "Grace", "Henry", "Ivy", "Jack"};

void generateRandomName(char *name)
{
    int randomIndex = rand() % (sizeof(predefinedNames) / sizeof(predefinedNames[0]));
    strcpy(name, predefinedNames[randomIndex]);
}

void merge(struct worker arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct worker L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        mergeSortComparisons++; // Increment comparison count
        if (L[i].workerAge <= R[j].workerAge) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        mergeSortDataTransfers++; // Increment data transfer count
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        mergeSortDataTransfers++; // Increment data transfer count
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        mergeSortDataTransfers++; // Increment data transfer count
        j++;
        k++;
    }
}

void mergeSort(struct worker arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to partition the array and return the partition index
int partition(struct worker arr[], int low, int high) {
    int pivot = arr[high].workerAge;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        quickSortComparisons++; // Increment comparison count
        if (arr[j].workerAge < pivot) {
            i++;
            // Swap arr[i] and arr[j]
            struct worker temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            quickSortDataTransfers += 3; // Increment data transfer count (3 for the swap)
        }
    }
    // Swap arr[i + 1] and arr[high] (pivot)
    struct worker temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    quickSortDataTransfers += 3; // Increment data transfer count (3 for the swap)

    return (i + 1);
}

// Function to perform Quick Sort on an array of workers based on their ages
void quickSort(struct worker arr[], int low, int high) {
    if (low < high) {
        // Find the partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after the partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to write worker data to a file
void writeToFile(struct worker arr[], int n, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file != NULL)
    {
        fwrite(arr, sizeof(struct worker), n, file);
        fclose(file);
    }
}

// Function to read worker data from a file
void readFromFile(struct worker arr[], int n, const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file != NULL)
    {
        fread(arr, sizeof(struct worker), n, file);
        fclose(file);
    }
}

// Function to print worker data
void printWorkers(struct worker arr[], int n)
{
    printf("Worker Information\n");
    for (int i = 0; i < n; i++)
    {
        printf("[ ID: %d \tName:%s \tAge: %d ]\n", arr[i].id,arr[i].workerName, arr[i].workerAge);
    }
}

int main()
{
    int n = 10; // Number of workers (you can change this based on your data)
    struct worker workers[n];

    // Generate random worker data (you can replace this with your actual data)
    for (int i = 0; i < n; i++) {
        workers[i].id = i + 1; // Assigning a simple ID for demonstration
        workers[i].workerAge = rand() % 30 + 20; // Example: Generating random worker ages between 20 and 50
        generateRandomName(workers[i].workerName); // Generating a random worker name
        // Add other attributes and data generation logic as needed
    }

    writeToFile(workers, n, "unsorted_workers.dat");
    printf("\nUnsorted Workers :\n");
    printWorkers(workers, n);

    // Read unsorted data from the common file
    // Perform Merge Sort
    readFromFile(workers, n, "unsorted_workers.dat");
    mergeSort(workers, 0, n - 1);

    // Write sorted data to a file
    writeToFile(workers, n, "sorted_workers_merge_sort.dat");

    // Read data from the sorted file
    readFromFile(workers, n, "sorted_workers_merge_sort.dat");

    // Print merge sorted workers
    printf("\nSorted Workers (Merge Sort):\n");
    printWorkers(workers, n);
     // Print comparison and data transfer counts for Merge Sort
    printf("Merge Sort Comparisons: %d\n", mergeSortComparisons);
    printf("Merge Sort Data Transfers: %d\n", mergeSortDataTransfers);

    // ---------------------------------------------------------------
    
    // Read unsorted data from the common file
    // Perform Quick Sort
    readFromFile(workers, n, "unsorted_workers.dat");
    quickSort(workers, 0, n - 1);

    // Write sorted data to a file
    writeToFile(workers, n, "sorted_workers_quick_sort.dat");

    // Read data from the sorted file
    readFromFile(workers, n, "sorted_workers_quick_sort.dat");

    // Print quick sorted workers
    printf("\nSorted Workers (Quick Sort):\n");
    printWorkers(workers, n);

    // Print comparison and data transfer counts for Quick Sort
    printf("Quick Sort Comparisons: %d\n", quickSortComparisons);
    printf("Quick Sort Data Transfers: %d\n", quickSortDataTransfers);

    printf("\n\n");

    if(quickSortComparisons<mergeSortComparisons){
        printf("QuickSort has lesser Data Comparisons\n");
    }
    else if(quickSortComparisons>mergeSortComparisons){
        printf("MergeSort has lesser Data Comparisons\n");
    }
    else{
        printf("They have Equal Data Comparisons\n");
    }

    if(quickSortDataTransfers<mergeSortDataTransfers){
        printf("QuickSort has lesser Data Transfers\n");
    }
    else if(quickSortDataTransfers>mergeSortDataTransfers){
        printf("MergeSort has lesser Data Transfers\n");
    }
     else{
        printf("They have Equal Data Transfers\n");
    }




    return 0;


}
