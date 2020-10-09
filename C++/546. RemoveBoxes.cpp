/*
Given several boxes with different colors represented by different positive numbers.
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

 

Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
*/
class Solution
{
public:
    int removeBoxes(vector<int> &boxes)
    {
        int lookup[100][100][100] = {0};
        return removeBoxesHelper(boxes, 0, boxes.size() - 1, 0, lookup);
    }

private:
    int removeBoxesHelper(const vector<int> &boxes, int l, int r, int k, int lookup[100][100][100])
    {
        if (l > r)
        {
            return 0;
        }
        if (lookup[l][r][k])
        {
            return lookup[l][r][k];
        }

        auto &result = lookup[l][r][k];
        while (l < r && boxes[l + 1] == boxes[l])
        {
            ++l, ++k;
        }
        result = removeBoxesHelper(boxes, l + 1, r, 0, lookup) + (k + 1) * (k + 1);
        for (int i = l + 1; i <= r; ++i)
        {
            if (boxes[i] == boxes[l])
            {
                result = max(result,
                             removeBoxesHelper(boxes, l + 1, i - 1, 0, lookup) +
                                 removeBoxesHelper(boxes, i, r, k + 1, lookup));
            }
        }
        return result;
    }
};