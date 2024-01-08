#include <iostream>
using namespace std;

void HeapBottomUp(int H[], int n){
    for (int i = n/2; i>0; i--){
        int k = i;
        int v = H[k];
        bool heap = false;
        while(!heap && 2*k<= n){
            int j = 2*k;
            if (j < n){
                if (H[j] >= H[j + 1]) j += 1;
            }
            if (v<H[j]){
                heap = true;
            }
            else{
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

int main(){
    int n;
    cin >> n;
    while(n != 0){
        int heap[n];
        for (int i=0; i < n; i++) {
            cin >> heap[i];
        }
        int total = 0;
        while(n>1){
            int x0,x1;
            HeapBottomUp(heap, n);
            x0 = heap[1];
            total += heap[1];
            swap(heap[1], heap[n]);
            n--;
            HeapBottomUp(heap, n);
            x1 = heap[1];
            total += heap[1];
            heap[1] = x0 + x1;
        }
        cout << total << "\n";
        cin >> n;
    }

    return 0;
}