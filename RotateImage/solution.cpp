// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]
// Example 2:


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 20
// -1000 <= matrix[i][j] <= 1000

/*

Solution idea:
1. each element should have to able to move N-1 step.
2. follow the pattern of right, down, left, up
3. for each layer, only traverse first row is enough because remaining will be shifted.
4. it would be N-1 traversal
5. then move to inner layer.


Idea:

1. Rotate layer by layer, from outer layer to inner layer.
2. In one layer, only iterate along the top row of that layer.
3. For each position, rotate 4 cells:
      top -> right
      right -> bottom
      bottom -> left
      left -> top
4. Use one temporary variable to store one value during the swap.
5. Number of layers = n / 2



#include <vector>
using namespace std;

class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        // move layer by layer
        for (int layer = 0; layer < n / 2; layer++)
        {
            int first = layer;
            int last = n - 1 - layer;

            // only traverse the first row of this layer
            for (int i = first; i < last; i++)
            {
                int offset = i - first;

                // save top
                int temp = matrix[first][i];

                // left -> top
                matrix[first][i] = matrix[last - offset][first];

                // bottom -> left
                matrix[last - offset][first] = matrix[last][last - offset];

                // right -> bottom
                matrix[last][last - offset] = matrix[i][last];

                // top -> right
                matrix[i][last] = temp;
            }
        }
    }
};









// solution alternative but i dont quite intuitive to this:
.. why the hell doing this can achieve rotation hmmm

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();

        // Step 1: transpose
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: reverse each row
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};



*/