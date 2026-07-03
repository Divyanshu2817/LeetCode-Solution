class Solution {
public:
    bool mover(vector<vector<int>>& grid, int move, int row, int col, int n){
        if(move==n*n-1) return true;
        int newCol, newRow;
        if(col>1 && row>0){
            newRow= row-1;
            newCol= col-2;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }
        if(col>1 && row<n-1){
            newRow= row+1;
            newCol= col-2;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col<n-2 && row>0){
            newRow= row-1;
            newCol= col+2;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col<n-2 && row<n-1){
            newRow= row+1;
            newCol= col+2;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col<n-1 && row>1){
            newRow= row-2;
            newCol= col+1;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col>0 && row>1){
            newRow= row-2;
            newCol= col-1;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col<n-1 && row<n-2){
            newRow= row+2;
            newCol= col+1;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        if(col>0 && row<n-2){
            newRow= row+2;
            newCol= col-1;
            if(grid[newRow][newCol] == move+1){
                return mover(grid,move+1,newRow,newCol,n);
            }
        }

        return false;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        int n=grid.size();
        return mover(grid,0,0,0,n);
    }
};