/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int> (n, -1));

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = m - 1;
        int endingCol = n - 1;

        while(head){
            //printing first row
            for(int i = startingCol; i <= endingCol && head; i++){
                matrix[startingRow][i] = head -> val;
                head = head -> next;
            }
            startingRow++;

            //printing last col
            for(int i = startingRow; i <= endingRow && head; i++){
                matrix[i][endingCol] = head -> val;
                head = head -> next;
            }
            endingCol--;

            //printing last row
            for(int i = endingCol; i >= startingCol && head; i--){
                matrix[endingRow][i] = head -> val;
                head = head -> next;
            }
            endingRow--;

            //printing first col
            for(int i = endingRow; i >= startingRow && head; i--){
                matrix[i][startingCol] = head -> val;
                head = head -> next;
            }
            startingCol++;
        }

        return matrix;
    }
};