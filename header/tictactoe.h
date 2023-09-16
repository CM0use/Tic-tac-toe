/**
 ** This file is part of Tic-tac-toe project
 ** Copyright 2023 CM0use dilanuzcs@gmail.com
 ** URL: https://github.com/CM0use/Tic-tac-toe
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

# ifndef TIC_TIC_TOE_H
# define TIC_TIC_TOE_H

# ifdef _WIN32
# define CLEAN_SCREEN system("CLS");
# elif __APPLE__
# define CLEAN_SCREEN system("clear");
# elif __linux__
# define CLEAN_SCREEN system("clear");
# endif

namespace TicTacToe { 
    void help() noexcept;
    void board(const std::array<unsigned char, 10>&) noexcept;
    void movement(std::array<unsigned char, 10>&, const unsigned char&) noexcept;
    void machine(std::array<unsigned char, 10>&, const unsigned char&) noexcept;
    bool diagonal(const std::array<unsigned char, 10>&, const unsigned char&) noexcept;
    bool horizontal(const std::array<unsigned char, 10>&, const unsigned char&) noexcept;
    bool vertical(const std::array<unsigned char, 10 >&, const unsigned char&) noexcept;
    bool tie(const std::array<unsigned char, 10>&) noexcept;
    bool input(std::uint16_t&) noexcept;
}
# endif
