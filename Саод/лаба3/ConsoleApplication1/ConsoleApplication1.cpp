#include <iostream>
#include <vector>

#define BOARD_SIZE 8

bool isValid(std::vector<int> board, int horse_count) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (board[i] == -1) {
			return false;
		}
		for (int j = i + 1; j < BOARD_SIZE; j++) {
			if (abs(i - j) * abs(i + j) == horse_count && board[j] == -1) {
				return false;
			}
		}
	}
	return true;
}

void printBoard(std::vector<int>& board) {
	std::cout << " " << "a" << " b" << " c" << " d" << " e" << " f" << " g" << " h" << std::endl;
	for (int r = 0; r < BOARD_SIZE; r++) {
		std::cout << r + 1 << " ";
		for (int c = 0; c < BOARD_SIZE; c++) {
			int index = r * BOARD_SIZE + c;
			if (board[index] == -2) {
				std::cout << ". ";
			}
			else if (board[index] > -2) {
				int horse_number = board[index];
				std::string horse_color = "W";
				if (horse_number % 2 == 0) {
					horse_color = "B";
				}
				std::cout << horse_number << " " << horse_color << " ";
			}
			else {
				std::cout << board[index] << " ";
			}
		}
		std::cout << std::endl;
	}
}

std::vector<std::vector<int>> solve(int horse_count, int depth = 0, std::vector<int> partial_board = {}) {
	if (depth == BOARD_SIZE * BOARD_SIZE) {
		return {};
	}

	partial_board.
		push_back(-1);

	// Check if current partial solution is valid
	if (!isValid(partial_board, horse_count)) {
		partial_board.pop_back();
		return {};
	};

	auto result = solve(horse_count, depth + 1, partial_board);

	// Backtracking
	partial_board.pop_back();

	if (depth > 0 && partial_board.back() == -1) {
		for (int i = depth - 1; i >= 0; --i) {
			partial_board[BOARD_SIZE * i] = -2;
		};
		result.insert(result.end(), solve(horse_count, 0, partial_board));
		partial_board[-1] = -1;
	};

	return result;
}

int main() {
	int horse_count = 12;
	int board_size = BOARD_SIZE;

	std::vector<int> empty_board(board_size * board_size);
	printBoard(empty_board);
	for (auto solution : solve(horse_count)) {
		printBoard(solution);
	}

	return 0;
}