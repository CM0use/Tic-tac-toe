/**
 ** This file is part of https://github.com/CM0use/Tic-tac-toe
 ** Copyright 2023 CM0use <dilanuzcs@gmail.com>.
 **
 ** This program is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

# include <iostream>
# include <random>
# include <array>

#include "../header/tictactoe.h"

void TicTacToe::help() noexcept {
		std::puts("Game format\n"
				"---------\n"
				"1 | 2 | 3\n"
				"4 | 5 | 6\n"
				"7 | 8 | 9\n"
				"---------\n");
}

void TicTacToe::board(const std::array<unsigned char, 10>& brands) noexcept {
	TicTacToe::help();
    for (std::uint8_t area = 1; area < 10; ++area)
    {
        if (!brands[area])    /* Available area */
            std::cout << "   ";
        else
            std::cout.put(' ').put(brands[area]).put(' ');
        
        if ((area % 3) != 0)  /* Board margin */
            std::putchar('|');
        
        if ((area % 3) == 0)  /* Sort the board */
            std::cout.put('\n').put('\n');
    }
}

void TicTacToe::movement(std::array<unsigned char, 10>& brands,
                         const unsigned char& user) noexcept {
    std::uint16_t area;
    std::cout << "\nArea (1-9)\n>>> ";

	 while(!TicTacToe::input(area) || (!area || area > 9)
			 || brands[area])
		 std::puts("Invalid Input.Try again\nArea (1-9)\n>>> ");
	 brands[area] = user;
}

void TicTacToe::machine(std::array<unsigned char, 10>& brands,
                        const unsigned char& machine) noexcept {
    std::vector<std::uint8_t> movMachine;
    
    for (std::uint8_t x = 1; x < 10; ++x)
        if (!brands[x])
            movMachine.push_back(x);
        
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<std::uint8_t> dist(0, movMachine.size() - 1);
    brands[movMachine[dist(engine)]] = machine;
}

bool TicTacToe::diagonal(const std::array<unsigned char, 10>& brands,
                            const unsigned char& user) noexcept {
    if (   (brands[1] == user && brands[5] == user && brands[9] == user)
        || (brands[3] == user && brands[5] == user && brands[7] == user))
		 return 1;
	 return 0;
}

bool TicTacToe::horizontal(const std::array<unsigned char, 10>& brands,
                              const unsigned char& user) noexcept {
    if (   (brands[1] == user && brands[2] == user && brands[3] == user)
        || (brands[4] == user && brands[5] == user && brands[6] == user)
        || (brands[7] == user && brands[8] == user && brands[9] == user))
		 return 1;
	 return 0;
}
	
bool TicTacToe::vertical(const std::array<unsigned char, 10>& brands, 
              const unsigned char& user) noexcept {
    if (   (brands[1] == user && brands[4] == user && brands[7] == user)
        || (brands[2] == user && brands[5] == user && brands[8] == user)
        || (brands[3] == user && brands[6] == user && brands[9] == user))
		 return 1;
	 return 0;
}

bool TicTacToe::tie(const std::array<unsigned char, 10>& brands) noexcept {
    std::uint8_t occupied{0};

    for (std::uint8_t n = 1; n < 10; n++)
        if (brands[n])
            occupied++;
        
    if (occupied == 9)
		 return 1;
	 return 0;
}

bool TicTacToe::input(std::uint16_t& opt) noexcept {
	std::cin >> opt;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
		return 0;
	} return 1;
}
