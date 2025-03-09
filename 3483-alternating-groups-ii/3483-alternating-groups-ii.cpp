class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> app(colors.begin(), colors.end());
        for(int i = 0; i < k-1; i++){
            app.push_back(colors[i]);   //to avoid circular array
        }

        int size = app.size();
        int grp = 0;

        int i = 0, j = 1;
        while(j < size){
            if(app[j] == app[j-1]){
                i = j;
                j++;
                continue;
            }

            if(j-i+1 == k){
                grp++;
                i++;
            }

            j++;
        }

        return grp;
    }
};