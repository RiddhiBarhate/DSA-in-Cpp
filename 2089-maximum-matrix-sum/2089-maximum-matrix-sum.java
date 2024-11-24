class Solution {
    public long maxMatrixSum(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        long sum = 0;
        int countNegatives = 0;
        int smallestAbsoluteValue = Integer.MAX_VALUE;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += Math.abs(matrix[i][j]);

                if (matrix[i][j] < 0) {
                    countNegatives++;
                }

                smallestAbsoluteValue = Math.min(smallestAbsoluteValue, Math.abs(matrix[i][j]));
            }
        }

        if (countNegatives % 2 == 0) {
            return sum;
        }

        return sum - 2L * smallestAbsoluteValue;
    }
}