uint64_t permute(uint64_t input, const int *table, size_t size) {
  uint64_t output = 0;
  for(size_t i = 0; i < size; i++) {
    output <<= 1;
    output |= (input >> (64 - table[i])) & 1;
  }
  return output;
}

uint32_t des_feistel(uint32_t input, uint64_t key) {
  uint64_t expanded = permute(input, E, 48);
  expanded ^= key;

  uint32_t output = 0;
  for(int i = 0; i < 8; i++) {
    uint8_t sixBits = (expanded >> (42 - i * 6)) & 0x3F; // 0b00111111
    uint8_t sValue = S[i][sixBits];
    output |= (sValue << (28 - i * 4));
  }

  return permute(output, P, 32);
}

uint64_t des_key_schedule(uint64_t key, uint8_t round) {
  return 0;
}

uint64_t des_encrypt(uint64_t input, uint64_t key) {
  uint64_t initial = permute(input, IP, 64);
  uint32_t left = initial >> 32;
  uint32_t right = initial & 0xFFFFFFFF;

  for(int i = 0; i < 16; i++) {
    uint32_t temp = right;
    right = left ^ des_feistel(
      right,
      des_key_schedule(key, i)
    );
    left = temp;
  }

  uint64_t result = left << 32 | right;
  return permute(result, FP, 64);
}