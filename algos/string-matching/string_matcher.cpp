#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include "string_matcher.h"
#include "../number-theory/nt_common.h"

#define DEBUG 0

using namespace std;

/*
 * Naive string matching algorithm:
 * Finds all shifts in text which matches the supplied pattern
 */
void naive_string_matcher(string t, string p) {
  for (int i = 0; i < t.length() - p.length(); i++) {
    int j;
    for (j = 0; j < p.length(); j++) {
      if (p[j] != t[i+j]) break;
    }
    if (j == p.length()) printf ("[%s] Pattern exists with shift %d\n", __FUNCTION__, i + 1);
  }
}

/*
 * Cormen: 32.1-4
 * Pattern might have gap characters in it.
 * Returns true if pattern is present in text, else false
 */
bool naive_string_matcher_for_pattern_with_gaps(string t, string p) {
  int offset = 0;
  for (int i = 0; i < t.length(); i++) {
    int j;
    for (j = offset; j < p.length() && i+j-offset < t.length(); j++) {
      if (p[j] == '*') {
	offset = j + 1;
	break;
      }
      else if (p[j] != t[i+j-offset]) {
	break;
      }
    }
    if (j == p.length()) {
      return true;
    }
  }
  return false;
}

/*
 * Rabin Karp Algorithm for string matching
 * Find all shifts in the text which matches the supplied pattern
 * Hash value is pretty naive for now. Same as given in Cormen
 * [TO DO]
 *        - Improve hashing
 */

const uint64_t rbm_d = 256;         // Ascii for now !
const uint64_t rbm_q = 1000000007;

void rabin_karp_matcher(string T, string P, uint64_t d, uint64_t q) {
  int n = T.length();
  int m = P.length();
  uint64_t h = modular_pow(d, m-1, q);
  uint64_t p = 0, t = 0;
  
  /* Pre-processing */
  for (int i = 0; i < m; i++) {
    p = ((d*p % q) + P[i]) % q;
    t = ((d*t % q) + T[i]) % q;
  }
  
  /* Matching */
  for (int s  = 0; s < n-m+1; s++) {

#if DEBUG
    printf ("[%s] p=%llu, t=%llu\n", __FUNCTION__, p, t);  
#endif

    if (p == t) {
      /* Collision check */
      int i;
      for (i = 0; i < m; i++) {
	if (P[i] != T[s+i]) break;
      }

      if (i == m) printf ("[%s] Pattern exists with shift %d\n", __FUNCTION__,  s + 1);
    }
    /* Calculating hash value for next m characters in t */
    if (s < n-m) t = ((d * ((t - ((T[s] * h) % q) + q) % q)) % q + T[s+m]) % q;
  }
}

int main() {
  string t, p;
  getline(cin, t);
  getline(cin, p);
  
#if 0
  /* naive_string_matcher */
  naive_string_matcher(t, p);
  
  /* 
   * Cormen: 32.1-4
   * naive string matcher with gaps
   */
  if (naive_string_matcher_for_pattern_with_gaps(t, p)) {
    printf ("Naive_gaps: Pattern exists !\n");
  }
  else {
    printf ("Naive_gaps: Pattern does not exists !\n");
  }
#endif
  
  /* Rabin-Karp */
  rabin_karp_matcher(t, p, rbm_d, rbm_q);

  return 0;
}


