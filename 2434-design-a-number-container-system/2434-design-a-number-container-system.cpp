class NumberContainers {
public:

    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIdx;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(idxToNum.count(index)) { 
            int prevNum = idxToNum[index];
            numToIdx[prevNum].erase(index); 
            if(numToIdx[prevNum].empty()) {
                numToIdx.erase(prevNum); 
            }
        }

        idxToNum[index] = number;
        numToIdx[number].insert(index);
    }
    
    int find(int number) {
        if(numToIdx.count(number)) { //O(1)
            return *numToIdx[number].begin(); //O(1)
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */