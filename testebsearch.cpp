#include <stdio.h>

int bs(int array[], int l, int r, int k){
    if (r >= l){
        int m = (l+r)/2;
        if (k == array[m]){
            return m;
        }
        else if (k < array[m]){
            return bs(array, l, m-1, k);
        }
        else{
            return bs(array, m+1, r, k);
        }
    }
    else{
        return -1;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; j++){
        int k;
        scanf("%d", &k);
        printf("%d\n", bs(array, 0, n-1, k));
    }
    return 0;
}