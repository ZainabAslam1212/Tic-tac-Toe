import java.util.Scanner;

public class tictactoe {
    private char[][] board;
    private char currentPlayer;

    public tictactoe() {
        board = new char[3][3];
        currentPlayer = 'X';

        // Initialize the board with empty spaces
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = ' ';
            }
        }
    }

    public void printBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(board[i][j]);
                if (j < 2) {
                    System.out.print(" | ");
                }
            }
            System.out.println();
            if (i < 2) {
                System.out.println("---------");
            }
        }
        System.out.println();
    }

    public boolean makeMove(int row, int col) {
        // Check if the chosen cell is empty
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            System.out.println("Invalid move. Try again.");
            return false;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

        return true;
    }

    public boolean checkForWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
                return true; // Row win
            }
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
                return true; // Column win
            }
        }

        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true; // Diagonal win (top-left to bottom-right)
        }
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
            return true; // Diagonal win (top-right to bottom-left)
        }

        return false;
    }

    public boolean isBoardFull() {
        // Check if the board is full
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false; // There is an empty cell
                }
            }
        }
        return true; // Board is full
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        tictactoe game = new tictactoe();

        while (true) {
            // Print the current board
            game.printBoard();

            // Get the player's move
            System.out.println("Player " + game.currentPlayer + ", enter your move (row and column):");
            int row = scanner.nextInt();
            int col = scanner.nextInt();

            // Make the move
            if (game.makeMove(row, col)) {
                // Check for a win
                if (game.checkForWin()) {
                    // Print the final board
                    game.printBoard();
                    System.out.println("Player " + game.currentPlayer + " wins!");
                    break;
                }

                // Check for a tie
                if (game.isBoardFull()) {
                    // Print the final board
                    game.printBoard();
                    System.out.println("The game is a tie!");
                    break;
                }
            }
        }

        scanner.close();
    }
}
