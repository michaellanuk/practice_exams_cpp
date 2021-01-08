#include "correct.h"

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
    *binary = '\0';
}

char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

void text_to_binary(std::string text, char* binary) {
  for (int i = 0; i < 512; i++) {
    binary[i] = '\0';
  }
  
  char binary_char[9];

  int offset = 0;
  for (int i = 0; i < text.length(); i++) {
    ascii_to_binary(text[i], binary_char);
    for (int j = 0 + offset, k = 0; j < 8 + offset; j++, k++) {
      binary[j] = binary_char[k];
    }
    offset += 8;
  }
}

void binary_to_text(std::string digits, char* text) {
  for (int i = 0; i < 32; i++) {
    text[i] = '\0';
  }

  std::vector<std::string> bytes;

  std::string byte = "";
  for (int i = 0; i < digits.length(); i++) {
    if (i % 8 == 0 && i != 0) {
      bytes.push_back(byte);
      byte = "";
    }
    byte.push_back(digits[i]);
  }
  bytes.push_back(byte);
  
  for (int i = 0; i < bytes.size(); i++) {
    const char * c = bytes[i].c_str();
    text[i] = binary_to_ascii(c);
  }
}

void add_error_correction(std::string digits, char* correct) {
  for (int i = 0; i < 512; i++) {
    correct[i] = '\0';
  }

  std::vector<std::string> d_bits;

  std::string d_bit;
  for (int i = 0; i < digits.length(); i++) {
    if (i % 4 == 0 && i != 0) {
      d_bits.push_back(d_bit);
      d_bit = "";
    }
    d_bit.push_back(digits[i]);
  }
  d_bits.push_back(d_bit);

  int offset = 0;
  for (int i = 0; i < d_bits.size(); i++) {
    error_correct_bits(d_bits[i], correct, offset);
    offset += 7;
  }
}

void error_correct_bits(std::string bits, char* correct, int offset) {
  char c1 = '0', c2 = '0', c3 = '0';
  char d1 = bits[0], d2 = bits[1], d3 = bits[2], d4 = bits[3];

  /* check parity of c1 */
  int ones = 0;
  for (int i = 0; i < bits.length(); i++) {
    if (i == 2) {
      continue;
    }
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    c1 = '1';
  }
  ones = 0;
  /* check parity of c2 */
  for (int i = 0; i < bits.length(); i++) {
    if (i == 1) {
      continue;
    }
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    c2 = '1';
  }
  ones = 0;
  /* check parity of c3 */
  for (int i = 1; i < bits.length(); i++) {
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    c3 = '1';
  }

  correct[0 + offset] = c1;
  correct[1 + offset] = c2;
  correct[2 + offset] = d1;
  correct[3 + offset] = c3;
  correct[4 + offset] = d2;
  correct[5 + offset] = d3;
  correct[6 + offset] = d4;
}

int decode(std::string bits, char* decoded) {
  int errors = 0;
  for (int i = 0; i < 512; i++) {
    decoded[i] = '\0';
  }

  std::vector<std::string> seven_bit_codes;

  std::string seven_bits;
  for (int i = 0; i < bits.length(); i++) {
    if (i % 7 == 0 && i != 0) {
      seven_bit_codes.push_back(seven_bits);
      seven_bits = "";
    }
    seven_bits.push_back(bits[i]);
  }
  seven_bit_codes.push_back(seven_bits);

  int offset = 0;
  for (int i = 0; i < seven_bit_codes.size(); i++) {
    decode(seven_bit_codes[i], decoded, offset, errors);
    offset += 4;
  }
  return errors;
}

void decode(std::string bits, char* decoded, int offset, int &errors) {
  int ones = 0;
  int parity_errors = 0;

  char p1 = '0', p2 = '0', p3 = '0';
  //char b3 = bits[2], b5 = bits[4], b6 = bits[5], b7 = bits[6];
  /* check parity of p1 */
  for (int i = 3; i < bits.length(); i++) {
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    parity_errors++;
    p1 = '1';
  }
  ones = 0;
  /* check parity of p2 */
  for (int i = 0; i < bits.length(); i++) {
    if (i == 0 || i == 3 || i == 4) {
      continue;
    }
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    parity_errors++;
    p2 = '1';
  }
  ones = 0;
  /* check parity of p3 */
  for (int i = 0; i < bits.length(); i++) {
    if (i == 1 || i == 3 || i == 5) {
      continue;
    }
    if (bits[i] == '1') {
      ones++;
    }
  }
  if (ones % 2 == 1) {
    parity_errors++;
    p3 = '1';
  }
  
  /* check for no errors */
  if (parity_errors == 0) {
    decoded[0 + offset] = bits[2];
    decoded[1 + offset] = bits[4];
    decoded[2 + offset] = bits[5];
    decoded[3 + offset] = bits[6];
    return;
  }

  errors++;
  
  int position_error = 0;
  if (p1 == '1') {
    position_error += 4;
  }
  if (p2 == '1') {
    position_error += 2;
  }
  if (p3 == '1') {
    position_error += 1;
  }

  if (bits[position_error - 1] == '1') {
    bits[position_error - 1] = '0';
  } else {
    bits[position_error - 1] = '1';
  }

  decoded[0 + offset] = bits[2];
  decoded[1 + offset] = bits[4];
  decoded[2 + offset] = bits[5];
  decoded[3 + offset] = bits[6];
  return;
}