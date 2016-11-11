#ifndef LEVENSHTEIN_ALGORITHM_H
#define LEVENSHTEIN_ALGORITHM_H
#include <cstdlib>

template <class T>
static int levenshtein_distance(T src, T dst);
template <class T>
static int damerau_levenshtein_distance(T  src, T  dst);

#endif // LEVENSHTEIN_ALGORITHM_H
