#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdib>
#include "../common/common.h"

using namespace std;

uint64_t modular_pow(uint64_t base, uint64_t exp, uint64_t mod) {
  uint64_t res = 1;
  base = base % mod;
  while (exp) {
    if (exp & 1) res = (res * base) % mod;
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
