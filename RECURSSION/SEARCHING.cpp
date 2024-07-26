/*
// LINEAR SEARCH
#include<iostream>
using namespace std;

bool search(int arr[], int size, int key) {
    if(size == 0) {
        cout<<"false";
        return false;
    }
    if(arr[0] == key) {
        cout<<"present";
        return true;
        }
    else {
    return search(arr+1, size-1, key);
    }
}

int main () {
    int arr[5] = {3,5,1,7,8};
    int size = 5;
    int key = 10;
    bool ans = search(arr, size, key);
}
*/





/*
// BINARY SEARCH
#include<iostream>
using namespace std;

bool search(int *arr, int start, int end, int key) {
    if(start>end) return false;
    int mid = start + (end-start)/2;
    if(arr[mid] == key) return true;
    else if(arr[mid] > key) return search(arr, start, mid-1, key);
    else return search(arr, mid+1, end, key);

}

// // if u want return index;
// 
// int search(int *arr, int start, int end, int key) {
//     if(start>end) return -1;
//     int mid = start + (end-start)/2;
//     if(arr[mid] == key) return mid;
//     else if(arr[mid] > key) return search(arr, start, mid-1, key);
//     else return search(arr, mid+1, end, key);

// }

int main () {
    int arr[5] = {3,5,1,7,8};
    int size = 5;
    int key = 1 ;
    cout<< search(arr, 0, size-1, key);
}
*/