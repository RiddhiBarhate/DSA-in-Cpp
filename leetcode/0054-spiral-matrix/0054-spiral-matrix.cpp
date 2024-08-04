class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        int total=row*col;

        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;

        int count =0;
        while(count<total)
        {
            //printing startingrow
            for(int i=startingCol; i<=endingCol; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            

            //printing endingcol
            for(int i=startingRow; count<total && i<=endingRow; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            

            //printing endingrow
            for(int i=endingCol; count<total && i>=startingCol; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
           

            //printing startingcol
            for(int i=endingRow; count<total && i>=startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
            
        }
        return ans;
    }
};