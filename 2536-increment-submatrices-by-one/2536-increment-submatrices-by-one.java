class Solution {
    int [][] arr;
    public int[][] rangeAddQueries(int n, int[][] v) {
        arr=new int[n][n];
        boolean vis[][]=new boolean[n][n];
        for(int [] x: v){
            int row1=x[0];
            int c1=x[1];
            int row2=x[2];
            int c2=x[3];
            for(int i=row1;i<=row2;i++){
                for(int j=c1;j<=c2;j++){
                    arr[i][j]++;
                }
            }
        }
        return arr;
        }
}