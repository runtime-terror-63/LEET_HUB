class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        vector<int>row(rowLen, 0), col(colLen, 0);
        for(int i=0; i<rowLen; i++){
            for(int j=0; j<colLen; j++){
                if(matrix[i][j]==0){
                    row[i] = -1;
                    col[j] = -1;
                }
            }
        }

        for(int i=0; i<rowLen; i++){
            for(int j=0; j<colLen; j++){
                if(row[i]==-1 || col[j]==-1)
                matrix[i][j] = 0;
            }
        }
    }
};