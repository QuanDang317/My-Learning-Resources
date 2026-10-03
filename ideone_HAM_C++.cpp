#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 100000;
int arr[MAX];
//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    
//    return 0;
//}
//Hàm kiem tra so hoàn hao (Perfect number)
bool isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n/2; i++) {
        if (n % i == 0) sum += i;
    }
    return sum == n && n != 0;
}
//2. Hàm kiem tra so Armstrong
bool isArmstrong(int n) {
    int original = n, sum = 0;
    int digits = 0;
    int temp = n;

    while (temp) {
        digits++;
        temp /= 10;
    }
    temp = n;
    while (temp) {
        int d = temp % 10;
        sum += pow(d, digits);
        temp /= 10;
    }
    return sum == original;
}
// Hàm fibonacci (d? quy)
ll fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

// Hàm kiem tra so nguyên to
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm sàng so nguyên to (Sieve of Eratosthenes)
void sieve(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (isPrime[i]) cout << i << " ";
    cout << "\n";
}
// Ham tinh tong
int Tong(int n) {
    if (n <= 0)    return 0;       
    return n + Tong(n - 1);
}
// Hàm tính giai th?a (d? quy)
ll factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n-1);
}

// Hàm tìm max trong m?ng
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

// Hàm tính gcd 
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Hàm tính lcm 
int lcm(int a, int b) {
    return (a / gcd(a,b)) * b;
}

// Hàm dao nguoc mang
void reverseArray(int arr[], int n) {
    for (int i=0; i < n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }
}

// Hàm tính t?ng ch? s?
int tongChuSo(int n) {
    if (n < 0) n = -n;
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Hàm kiem tra so thuan nghich
bool isPalindrome(int n) {
    if (n < 0) return false;
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// Tìm kiem tuyen tính (linear search)
bool linearSearch(int arr[], int n, int x) {
    for (int i=0; i<n; i++)
        if (arr[i] == x) return true;
    return false;
}

// Tìm kiem nhi phân (binary search) 
bool binarySearch(int arr[], int n, int x) {
    int left=0, right=n-1;
    while (left <= right) {
        int mid = left + (right-left)/2;
        if (arr[mid] == x) return true;
        else if (arr[mid] < x) left = mid + 1;
        else right = mid -1;
    }
    return false;
}

// Selection Sort
void selectionSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        int min_idx = i;
        for (int j=i+1; j<n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

// Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(arr + l, arr + m + 1);
    vector<int> R(arr + m + 1, arr + r + 1);

    int i=0, j=0, k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Quick Sort
void quickSort(int arr[], int l, int r) {
    if (l >= r) return;
    int pivot = arr[r];
    int i = l - 1;
    for (int j=l; j<r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    quickSort(arr, l, i);
    quickSort(arr, i+2, r);
}

// Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i=n/2 - 1; i>=0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Radix Sort helper
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i=1; i<n; i++)
        if (arr[i] > mx) mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp) {
    vector<int> output(n);
    int count[10] = {0};

    for (int i=0; i<n; i++)
        count[(arr[i]/exp) % 10]++;

    for (int i=1; i<10; i++)
        count[i] += count[i-1];

    for (int i=n-1; i>=0; i--) {
        output[count[(arr[i]/exp) % 10] - 1] = arr[i];
        count[(arr[i]/exp) % 10]--;
    }

    for (int i=0; i<n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int m = getMax(arr
