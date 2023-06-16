//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imdilate.h
//
// Code generation for function 'imdilate'
//

#ifndef IMDILATE_H
#define IMDILATE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class strel;

}

// Function Declarations
namespace coder {
void b_imdilate(const ::coder::array<boolean_T, 2U> &A, const strel *se,
                ::coder::array<boolean_T, 2U> &B);

void imdilate(const ::coder::array<double, 2U> &A, const strel *se,
              ::coder::array<double, 2U> &B);

void imdilate(const strel *se, ::coder::array<float, 2U> &B);

} // namespace coder

#endif
// End of code generation (imdilate.h)
