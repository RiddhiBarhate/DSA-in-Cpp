class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        
        int i = 0, j = n-1;
        int sum = skill[i] + skill[j];
        long long chem = 0;

        while(i < j){
            int currSum = skill[i] + skill[j];
            if(currSum != sum)
                return -1;

            chem += skill[i] * skill[j];
            i++;
            j--;
        }

        return chem;
    }
};