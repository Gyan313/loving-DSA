// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.


int countZeros(int n) {
    if(n>=1 && n<10){
        return 0;
    }
    if(n==0){
        return 1;
    }
    int ans=countZeros(n/10);
    if(n%10==0){
        return ans+1;
    }
    else{
        return ans;
    }
}


