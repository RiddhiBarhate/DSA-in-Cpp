class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        //to store the obstacle in string form
        unordered_set<string> st; 
        for(vector<int>& obstacle : obstacles){
            string key = to_string(obstacle[0]) + "_" + to_string(obstacle[1]);
            st.insert(key);
        }

        //pointing north
        int x = 0;
        int y = 0;
        int maxD = 0;

        pair<int, int> dir = {0, 1};    //N
        for(int i = 0; i <commands.size(); i++){
            //left 90 degree
            if(commands[i] == -2){
                dir = {-dir.second, dir.first};
            }
            //right 90 degree
            else if(commands[i] == -1){
                dir = {dir.second, -dir.first};
            }
            //move towards dir step by step
            else{
                for(int steps = 0; steps < commands[i]; steps++){
                    int newX = x + dir.first;
                    int newY = y + dir.second;
                    
                    string newkey = to_string(newX) + "_" + to_string(newY);

                    if(st.find(newkey) != st.end()){
                        break;
                    }

                    x = newX;
                    y = newY;
                }
            }
            maxD = max(maxD, x*x + y*y);
        }
        return maxD;
    }
};