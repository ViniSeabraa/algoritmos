#include <stdio.h>
#include <stdlib.h>

void merge(int array0[], int l, int m ,int r){
    int tamanho = r + 1;
    int arraytemp[tamanho];
    for(int i = l; i <= r; i++){
        arraytemp[i] = array0[i];
    }
    int i1 = l;
    int i2 = m + 1;
    for (int curr = l; curr <= r; curr++){
        if (i1 == m+1){
            array0[curr] = arraytemp[i2++];
        }
        else if(i2 > r || arraytemp[i1] <= arraytemp[i2]){
            array0[curr] = arraytemp[i1++];
        }
        else{
            array0[curr] = arraytemp[i2++];
        }
    }
}

void mergesort(int array0[], int l, int r) {
    if (l < r){
        int m = (l + r)/2;
        mergesort(array0, l, m);
        mergesort(array0, m + 1, r);
        merge(array0, l, m, r);
    }
}

int main(){
    int array[] = {1, 5, 2, 8, 0, 9,3, 4, 7};
    mergesort(array, 0, 8);
    for (int i = 0; i <= 8; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
