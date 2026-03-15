// https://leetcode.com/problems/surrounded-regions/

void dfs(char** board, int sc, int sr, int M, int N) {
    if (sc < 0 || sc >= N || sr < 0 || sr >= M || board[sr][sc] != 'O') {
        return;
    } 

    board[sr][sc] = '1';

    dfs(board, sc+1, sr, M, N);
    dfs(board, sc-1, sr, M, N);
    dfs(board, sc, sr+1, M, N);
    dfs(board, sc, sr-1, M, N);
}

void solve(char** board, int boardSize, int* boardColSize) {
    int M = boardSize;
    int N = boardColSize[0];

    for (int i = 0; i < M; i++) {
        dfs(board, 0, i, M, N);
        dfs(board, N - 1, i, M, N);
    }

    for (int i = 0; i < N; i++) {
        dfs(board, i, 0, M, N);
        dfs(board, i, M - 1, M, N);
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
            else if (board[i][j] == '1') {
                board[i][j] = 'O';
            }
        }
    }
}

// [["X","O","X","O","X","O"]
// ,["O","X","O","X","O","X"]
// ,["X","O","X","O","X","O"]
// ,["O","X","O","X","O","X"]]