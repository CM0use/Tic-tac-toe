
//          Copyright CM0use.
// Distributed under the Boost Software License, Version 1.0.
//    https://github.com/CM0use/Tic-tac-toe/blob/main/LICENSE
//          https://www.boost.org/LICENSE_1_0.txt

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
