class Solution {
    public String restoreString(String s, int[] indices) {
        int n = s.length();
        char[] result = new char[n];

        for(int i = 0; i < n; i++){
            char ch = s.charAt(i);
            int pos = indices[i];

            result[pos] = ch;
        }

        return new String(result);
    }
}