#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
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

const uint64_t rkm_d = 256;         // Ascii for now !
const uint64_t rkm_q = 1000000007;

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

/*
 * Cormern: 32.2-2 - Part 1
 * Rabin Karp to search for k patterns of same length
 */
void rkm_for_k_patterns_of_same_len(string T, vector <string> P, uint32_t k, uint64_t d, uint64_t q) {
  int n = T.length();
  int m = P[0].length();
  uint64_t h = modular_pow(d, m-1, q);
  uint64_t p[k], t = 0;

  memset(p, 0, sizeof(p));

  /* Pre-processing - patterns */
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < m; j++) {
      p[i] = ((d*p[i] % q) + P[i][j]) % q;
    }
  }

  /* Pre-processing - text */
  for (int i = 0; i < m; i++) {
     t = ((d*t % q) + T[i]) % q;
  }

  /* Matching */
  for (int s = 0; s < n-m+1; s++) {
    for (int i = 0; i < k; i++) {

#if DEBUG
      printf ("[%s] pattern=%s, p=%llu, t=%llu\n", __FUNCTION__, P[i].c_str(), p[i], t);
#endif 

      if (p[i] == t) {
	int j;
	for (j = 0; j < m; j++) {
	  if (P[i][j] != T[s+j]) break;
	}
	if (j == m) printf ("[%s] Pattern %s exists with shift %d\n", __FUNCTION__, P[i].c_str(), s+1);
      }
    }
    /* Calculating hash */
    if (s < n-m) t = ((d * ((t - ((T[s] * h) % q) + q) % q)) % q + T[s+m]) % q;
  }
}

int main() {
  
  /* Input */
  uint64_t k;
  string t, temp;
  getline(cin, t);
  scanf ("%llu\n", &k);
  vector <string> p;
  for (int i = 0; i < k; i++) {
    getline(cin, temp);
    p.push_back(temp);
  }

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
  
  /* Rabin-Karp */
  rabin_karp_matcher(t, p, rkm_d, rkm_q);
#endif

  /*
   * Cormen: 32.2-2
   * Rabin Karp for searching k patterns of same length
   */
  rkm_for_k_patterns_of_same_len(t, p, k, rkm_d, rkm_q);

  return 0;
}


