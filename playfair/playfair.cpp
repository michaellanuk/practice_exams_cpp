#include "playfair.h"

void prepare(std::string input, char* prepared) {
    std::string output;

    for (int i = 0; i < 100; i++) {
        prepared[i] = '\0';
    }

    for (int i = 0; i < input.length(); i++) {
        if (isalpha(input[i]) || isdigit(input[i])) {
            char ch = toupper(input[i]);
            output.push_back(ch);
        }
    }

    if (output.length() % 2 == 1) {
        output.push_back('X');
    }

    for (int i = 0; i < output.length(); i++) {
        prepared[i] = output[i];
    }
}

void grid(std::string codeword, char square[6][6]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            square[i][j] = '\0';
        }
    }

    std::string alt_codeword;

    for (int i = 0; i < codeword.length(); i++) {
        int j = 0;
        for (j = 0; j < i; j++) {
            if (codeword[i] == codeword[j]) {
                break;
            }
        }
        if (i == j) {
            alt_codeword.push_back(codeword[i]);
        }
    }

    std::string square_alphabet;

    for (int i = 0; i < alt_codeword.length(); i++) {
        square_alphabet.push_back(alt_codeword[i]);
    }

    std::string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < alphabet.length(); i++) {
        if (std::find(std::begin(codeword), std::end(codeword), alphabet[i]) 
        != std::end(codeword)) {
            continue;
        }
        square_alphabet.push_back(alphabet[i]);
    }
    
    for (char ch = '0'; ch <= '9'; ch++) {
        square_alphabet.push_back(ch);
    }

    int k = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            square[i][j] = square_alphabet[k];
            k++;
        }
    }
}

void bigram(char square[6][6], char in1, char in2, char &out1, char &out2) {
    int row1 = 0, col1 = 0, row2 = 0, col2 = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (square[i][j] == in1) {
                row1 = i;
                col1 = j;
            }
            if (square[i][j] == in2) {
                row2 = i;
                col2 = j;
            }
        }
    }

    out1 = square[row1][col2];
    out2 = square[row2][col1];
}

void encode(char square[6][6], char* word, char* encoded) {
    char out1, out2;
    char in1 = *word;
    word++;
    char in2 = *word;
    word++;

    if (in1 == '\0') {
        return;
    }

    bigram(square, in1, in2, out1, out2);
    *encoded = out1;
    encoded++;
    *encoded = out2;
    encoded++;

    encode(square, word, encoded);
}