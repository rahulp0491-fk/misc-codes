#ifndef STRING_MATCHER_H
#define STRING_MATCHER_H

#include <cstring>
#include <string>

using namespace std;

/* All string matching related function definitions come here */
void naive_string_matcher(string, string);
bool naive_string_matcher_for_pattern_with_gaps(string, string);
void rabin_karp_matcher(string, string, uint64_t, uint64_t);

#endif
