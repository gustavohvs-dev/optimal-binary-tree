// Dynamic Programming code for Optimal Binary Search
// Tree Problem
 
/* A Dynamic Programming based function that calculates
minimum cost of a Binary Search Tree. */
function optimalSearchTree(keys, freq, n)
{
    /* Create an auxiliary 2D matrix to store results
    of subproblems */

    debugger

    var cost = new Array(n);
    for (var i = 0; i < n; i++){
        cost[i] = new Array(n);
    }
  
    /* cost[i][j] = Optimal cost of binary search tree
    that can be formed from keys[i] to keys[j].
    cost[0][n-1] will store the resultant cost */
  
    // For a single key, cost is equal to frequency of the key
    for (var i = 0; i < n; i++){
        cost[i][i] = freq[i];
    }
        
    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (var L = 2; L <= n; L++)
    {
        // i is row number in cost[][]
        for (var i = 0; i <= n-L+1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            var j = i+L-1;
            var off_set_sum = sum(freq, i, j);
            if ( i >= n || j >= n)
                break
            cost[i][j] = Number. MAX_SAFE_INTEGER;
  
            // Try making all keys in interval keys[i..j] as root
            for (var r = i; r <= j; r++)
            {
                // c = cost when keys[r] becomes root of this subtree
                var c = 0;
                if (r > i){
                    c += cost[i][r-1]
                }
                if (r < j){
                    c += cost[r+1][j];
                }
                c += off_set_sum;
                if (c < cost[i][j]){
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n-1];
}
  
// A utility function to get sum of array elements
// freq[i] to freq[j]
function sum(freq, i, j)
{
    var s = 0;
    for (var k = i; k <= j; k++){
        s += freq[k];
    }
    return s;
}
var keys = [10, 20, 30, 40];
var freq = [4, 2, 6, 3];
var n = keys.length;

document.write("Cost of Optimal BST is " + optimalSearchTree(keys, freq, n));
  
// This code contributed by shubhamsingh10
