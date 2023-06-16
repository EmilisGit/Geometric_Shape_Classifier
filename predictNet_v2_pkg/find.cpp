//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// find.cpp
//
// Code generation for function 'find'
//

// Include files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_eml_find(const ::coder::array<boolean_T, 1U> &x,
                ::coder::array<int, 1U> &i, ::coder::array<int, 1U> &j)
{
  int idx;
  int ii;
  idx = 0;
  i.set_size(x.size(0));
  j.set_size(x.size(0));
  ii = 1;
  int exitg1;
  boolean_T guard1{false};
  do {
    exitg1 = 0;
    guard1 = false;
    if (x[ii - 1]) {
      idx++;
      i[idx - 1] = ii;
      j[idx - 1] = 1;
      if (idx >= x.size(0)) {
        exitg1 = 1;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > x.size(0)) {
        exitg1 = 1;
      }
    }
  } while (exitg1 == 0);
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(0);
      j.set_size(0);
    }
  } else {
    if (idx < 1) {
      ii = 0;
    } else {
      ii = idx;
    }
    i.set_size(ii);
    if (idx < 1) {
      idx = 0;
    }
    j.set_size(idx);
  }
}

void eml_find(const ::coder::array<boolean_T, 2U> &x,
              ::coder::array<int, 1U> &i, ::coder::array<int, 1U> &j)
{
  int idx;
  int ii;
  int jj;
  int k;
  boolean_T exitg1;
  k = x.size(0) * x.size(1);
  idx = 0;
  i.set_size(k);
  j.set_size(k);
  ii = 1;
  jj = 1;
  exitg1 = false;
  while ((!exitg1) && (jj <= x.size(1))) {
    boolean_T guard1{false};
    guard1 = false;
    if (x[(ii + x.size(0) * (jj - 1)) - 1]) {
      idx++;
      i[idx - 1] = ii;
      j[idx - 1] = jj;
      if (idx >= k) {
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
    if (guard1) {
      ii++;
      if (ii > x.size(0)) {
        ii = 1;
        jj++;
      }
    }
  }
  if (k == 1) {
    if (idx == 0) {
      i.set_size(0);
      j.set_size(0);
    }
  } else {
    if (idx < 1) {
      k = 0;
    } else {
      k = idx;
    }
    i.set_size(k);
    if (idx < 1) {
      idx = 0;
    }
    j.set_size(idx);
  }
}

} // namespace coder

// End of code generation (find.cpp)
