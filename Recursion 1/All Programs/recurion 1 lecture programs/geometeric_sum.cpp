// Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
// using recursion.
// Input format :
//     Integer k
// Output format :
//     Geometric sum (upto 5 decimal places)


double geometricSum(int k) {
    // Write your code here
    return (2-pow(2,-k));
}


