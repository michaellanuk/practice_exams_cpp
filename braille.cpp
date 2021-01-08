#include "braille.h"

int encode_character(char ch, char* braille) {
    int size = 0, offset = 0;

    if (isupper(ch) || isdigit(ch)) {
        size = 12;
        offset = 6;
        braille[12] = '\0';
    } else {
        size = 6;
        for (int i = 0 + offset; i < 6 + offset; i++) {
                braille[i] = '.';
        }
        for (int i = 6; i < 12; i++) {
                braille[i] = '\0';
        }
    }

    char one[29] = {'a', '1', 'b', '2', 'c', '3', 'd', '4', 'e', '5', 'f', '6',
                    'g', '7', 'h', '8', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                    'u', 'v', 'x', 'y', 'z'};
    char two[27] = {'b', '2', 'f', '6', 'g', '7', 'h', '8', 'i', '9', 'j', '0',
                    'l', 'p', 'q', 'r', 's', 't', 'v', 'w', '.', ',', ';', '!',
                    '?', '(', ')'};
    char three[21] = {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 
                     'v', 'x', 'y', 'z', ';', '-', '!', '?', '(', ')'};
    char four[21] = {'c', '3', 'd', '4', 'f', '6', 'g', '7', 'i', '9', 'j',
                     '0', 'm', 'n', 'p', 'q', 's', 't', 'w', 'x', 'y'};
    char five[22] = {'d', '4', 'e', '5', 'g', '7', 'h', '8', 'j', '0', 'n',
                     'o', 'q', 'r', 't', 'w', 'y', 'z', '.', '!', '(', ')'};
    char six[11] = {'u', 'v', 'w', 'x', 'y', 'z', '.', '-', '?', '(', ')'};

    if (isalpha(ch)) {
        if (isupper(ch)) {
            for (int i = 0; i < 5; i++) {
                braille[i] = '.';
            }
            braille[5] = 'O';
            for (int i = 0 + offset; i < 6 + offset; i++) {
                braille[i] = '.';
            }
        }
    } else if (isdigit(ch)) {
        braille[0] = '.';
        braille[1] = '.';
        for (int i = 2; i < 6; i++) {
            braille[i] = 'O';
        }
        for (int i = 0 + offset; i < 6 + offset; i++) {
            braille[i] = '.';
        }
    }

    if (isalpha(ch) && isupper(ch)) {
        ch = tolower(ch);
    }

    if (std::find(std::begin(one), std::end(one), ch) != std::end(one)) {
        braille[0 + offset] = 'O';
    }
    if (std::find(std::begin(two), std::end(two), ch) != std::end(two)) {
        braille[1 + offset] = 'O';
    }
    if (std::find(std::begin(three), std::end(three), ch) != std::end(three)) {
        braille[2 + offset] = 'O';
    }
    if (std::find(std::begin(four), std::end(four), ch) != std::end(four)) {
        braille[3 + offset] = 'O';
    }
    if (std::find(std::begin(five), std::end(five), ch) != std::end(five)) {
        braille[4 + offset] = 'O';
    }
    if (std::find(std::begin(six), std::end(six), ch) != std::end(six)) {
        braille[5 + offset] = 'O';
    }

    return size;
}

void encode(const char* word, char* braille) {
    if (*word == '\0') {
        return;
    }

    encode_character(*word, braille);

    if (isupper(*word) || isdigit(*word)) {
        braille += 12;
    } else {
        braille += 6;
    }
    word++;

    encode(word, braille);
}

void print_braille(const char* word, std::ostream& cout) {
    std::cout << '\n';

    char braille[512];
    braille[0] = '\0';

    encode(word, braille);

    int i = 0;
    while (braille[i] != '\0') {
        if ((i % 6 == 0) || (i % 6 == 3)) {
            std::cout << braille[i];
            if (i % 6 == 3) {
                std::cout << ' ';
            }
        }
        i++;
    }
    std::cout << '\n';
    i = 0;
    while (braille[i] != '\0') {
        if ((i % 6 == 1) || (i % 6 == 4)) {
            std::cout << braille[i];
            if (i % 6 == 4) {
                std::cout << ' ';
            }
        }
        i++;
    }
    i = 0;
    std::cout << '\n';
    while (braille[i] != '\0') {
        if ((i % 6 == 2) || (i % 6 == 5)) {
            std::cout << braille[i];
            if (i % 6 == 5) {
                std::cout << ' ';
            }
        }
        i++;
    }
    std::cout << '\n';

    while (*word != '\0') {
        if ((isalpha(*word) && isupper(*word)) || isdigit(*word)) {
            std::cout << "   ";
        }
        std::cout << *word << "  ";
        word++;
    }

}