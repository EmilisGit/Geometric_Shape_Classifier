//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// intline.h
//
// Code generation for function 'intline'
//

#ifndef INTLINE_H
#define INTLINE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace iptui {
void intline(double x1, double x2, double b_y1, double y2,
             ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y);

}
} // namespace coder

#endif
// End of code generation (intline.h)
