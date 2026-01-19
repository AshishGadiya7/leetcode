class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int row,col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='R'){
                    row=i,col=j;
                    break;
                }
            }
        }
         int res=0;
        int i=row-1,j;
        while(i>=0 && board[i][col]!='B'){
            if(board[i][col]=='p'){
                res++;
                break;
            }i--;
        }
        i=row+1;
        while(i<n &&  board[i][col]!='B'){
            if(board[i][col]=='p'){
                res++;
                break;
            }i++;
        }
        j=col-1;
        while(j>=0 && board[row][j]!='B'){
            if(board[row][j]=='p'){
                res++;
                break;
            }j--;
        }
        j=col+1;
        while(j<m && board[row][j]!='B'){
            if(board[row][j]=='p'){
                res++;
                break;
            }j++;
        }
        return res;
    }
};