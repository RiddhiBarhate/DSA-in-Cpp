class Solution {
    public int[] numberOfLines(int[] widths, String s) {
        int n = s.length();
        int[] result = new int[2];
        int sum = 0;
        int line = 1;

        for(int i = 0; i < n; i++){
            char ch = s.charAt(i);
            int curr = widths[ch - 'a'];
            if(curr + sum > 100){
                line++;
                sum = curr;
            }
            else{
                sum += curr;
            }
        }

        result[0] = line;
        result[1] = sum;

        return result;
    }
}