class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int size = rectangles.size();

        vector<vector<int>> xaxis;
        vector<vector<int>> yaxis;

        for(int i = 0; i < size; i++){
            int x1 = rectangles[i][0];
            int y1 = rectangles[i][1];
            int x2 = rectangles[i][2];
            int y2 = rectangles[i][3];

            xaxis.push_back({x1, x2});
            yaxis.push_back({y1, y2});   
        }

        sort(xaxis.begin(), xaxis.end());
    
        vector<vector<int>> hor;
        hor.push_back(xaxis[0]);
        
        for(int i = 1; i < size; i++){
            if(xaxis[i][0] < hor.back()[1]){
                hor.back()[1] = max(hor.back()[1], xaxis[i][1]);
            }else{
                hor.push_back(xaxis[i]);
            }
        }

        sort(yaxis.begin(), yaxis.end());
    
        vector<vector<int>> ver;
        ver.push_back(yaxis[0]);
        
        for(int i = 1; i < size; i++){
            if(yaxis[i][0] < ver.back()[1]){
                ver.back()[1] = max(ver.back()[1], yaxis[i][1]);
            }else{
                ver.push_back(yaxis[i]);
            }
        }

        return hor.size() >= 3 || ver.size() >= 3;

    }
};