#include "ghostsort.h"

void ghostsort_unstable(size_t elements_count, int *elements) {
  int element;
  size_t gap = elements_count;
  size_t i;
  size_t j;

  while (gap > 15) {
    gap = (gap >> 5) + (gap >> 3);
    i = gap;

    while (i < elements_count) {
      element = elements[i];
      j = i;

      while (
        j >= gap &&
        elements[j - gap] > element
      ) {
        elements[j] = elements[j - gap];
        j -= gap;
      }

      elements[j] = element;
      i++;
    }
  }

  i = 1;
  gap = 0;

  while (i < elements_count) {
    element = elements[i];
    j = i;

    while (
      j > 0 &&
      elements[gap] > element
    ) {
      elements[j] = elements[gap];
      j = gap;
      gap--;
    }

    elements[j] = element;
    gap = i;
    i++;
  }
}
