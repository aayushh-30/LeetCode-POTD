// Last updated: 3/15/2026, 11:04:26 PM
    long comma = 1;

    long ans = 0;

    for(int i=0;i<arr.length;i++){

        long left = arr[i][0];
        long right = arr[i][1];

        long diff = 0 , mul = 0;

        if(n>=left && n<=right){

             diff = n - left;
            diff++;

              mul = diff * comma;
            ans+=mul;

        }else if(n>right){
             diff = right - left;
            diff++;

             mul = diff * comma;
            ans+=mul;
        }
        comma++;
    }
    
    return ans;
} 
// 1,002 , 1,000,023   , 12,232,323 ,  1,293,929,394
// 1,000 == 999,999
// 1,000,000 == 999,999,999
// 1,000,000,000 == 999,999,999,999
// 1,000,000,000,000 == 999,999,999,999,999    1,000,000,000,000,000 