//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// flip.cpp
//
// Code generation for function 'flip'
//

// Include files
#include "flip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void b_flip(::coder::array<boolean_T, 3U> &x)
{
  if ((x.size(0) != 0) && (x.size(1) != 0) && (x.size(0) > 1)) {
    int i;
    int n;
    int nd2;
    int vlen;
    vlen = x.size(0);
    n = x.size(0) - 1;
    nd2 = x.size(0) >> 1;
    i = x.size(1) - 1;
    for (int j{0}; j <= i; j++) {
      int offset;
      offset = j * vlen;
      for (int k{0}; k < nd2; k++) {
        int i1;
        int tmp_tmp;
        boolean_T tmp;
        tmp_tmp = offset + k;
        tmp = x[tmp_tmp];
        i1 = (offset + n) - k;
        x[tmp_tmp] = x[i1];
        x[i1] = tmp;
      }
    }
  }
}

void flip(::coder::array<double, 3U> &x)
{
  if ((x.size(0) != 0) && (x.size(1) != 0) && (x.size(0) > 1)) {
    int i;
    int n;
    int nd2;
    int vlen;
    vlen = x.size(0);
    n = x.size(0) - 1;
    nd2 = x.size(0) >> 1;
    i = x.size(1) - 1;
    for (int j{0}; j <= i; j++) {
      int offset;
      offset = j * vlen;
      for (int k{0}; k < nd2; k++) {
        double tmp;
        int i1;
        int tmp_tmp;
        tmp_tmp = offset + k;
        tmp = x[tmp_tmp];
        i1 = (offset + n) - k;
        x[tmp_tmp] = x[i1];
        x[i1] = tmp;
      }
    }
  }
}

} // namespace coder

// End of code generation (flip.cpp)
