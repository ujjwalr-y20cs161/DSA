/*

Problem  : Set Matrix Zeroes

Statement :
=> Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

LINK:: https://leetcode.com/problems/set-matrix-zeroes/

Company : Microsoft

 */

void BetterSetZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    // creating arrays to mark the rows and cols that have zero
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // traverse the whole matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // using row and col arrays, mark the column and row that should be zeroed
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // traversing rows
    for (int i = 0; i < n; i++)
    {
        // if row is marked
        if (row[i] == 1)
        {
            // row is filled with zeros
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // traversing columns
    for (int j = 0; j < m; j++)
    {
        // if columns are marked
        if (col[j] == 1)
        {
            // fill the column with zeros
            for (int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// Basically same logic instead of using additional arrays, we mark the 0th row
// and 0th column, there will be a clash between row array and column array
void OptimizedSetZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // the conflit is resolved by an additional variable
    int col0 = 1;

    // traverse and mark
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                // special marking, if column is 0
                if (j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                    col0 = 0;
            }
        }
    }

    // fill marked rows other than 0th row, because filling zeroth row will corrupt the markings
    for (int i = 1; i < n; i++)
    {
        if (matrix[i][0] == 0)
            for (int j = 0; j < m; j++)
                matrix[i][j] = 0;
    }
    // fill marked columns excpet 0th column, filling that will corrupt marking
    for (int j = 1; j < m; j++)
    {
        if (matrix[0][j] == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    // atlast 0th row is checked and filled.
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    // atlast 0th column is checked and filled.
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}
