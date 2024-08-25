int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;

    int maxFreq = -1;
    int ans = 0;

    for(int i = 0; i < arr.size(); i++){
        mp[arr[i]]++;
        maxFreq = max(maxFreq, mp[arr[i]]);
    }

    for(int i = 0; i < arr.size(); i++){
        if(maxFreq == mp[arr[i]]){
            ans = arr[i];
            break;
        }
    }

    return ans;

}