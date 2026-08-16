class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();

        bool firstrowzero = false;
        bool firstcolzero = false;

        //for first row
        for(int i=0; i<n; i++){
            if(matrix[0][i] == 0){
                firstrowzero = true;
            }
        }
        //for first col
        for(int j=0; j<m; j++){
            if(matrix[j][0] == 0){
                firstcolzero = true;
            }
        }

        //set markers
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        //for remaining rows
        for(int i=1; i<m; i++){
            if(matrix[i][0] == 0){

                for(int j=0; j<n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        //for remaining col
        for(int j=1; j<n; j++){
            if(matrix[0][j] == 0){

                for(int i=1; i<m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstrowzero){
            for(int i=0; i<n; i++){
                matrix[0][i] =  0;
            }

        }

        if(firstcolzero){
            for(int j=0; j<m; j++){
                matrix[j][0] = 0;
            }
        }

    }
};


