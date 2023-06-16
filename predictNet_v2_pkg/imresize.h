//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imresize.h
//
// Code generation for function 'imresize'
//

#ifndef IMRESIZE_H
#define IMRESIZE_H

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void b_resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                        const ::coder::array<double, 2U> &weights,
                        const ::coder::array<int, 2U> &indices,
                        ::coder::array<unsigned char, 2U> &out);

void b_resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                        const ::coder::array<double, 2U> &weights,
                        const ::coder::array<int, 2U> &indices,
                        unsigned char out[784]);

void contributions(int in_length, double scale, double kernel_width,
                   ::coder::array<double, 2U> &weights,
                   ::coder::array<int, 2U> &indices);

void resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                      const ::coder::array<double, 2U> &weights,
                      const ::coder::array<int, 2U> &indices,
                      ::coder::array<unsigned char, 2U> &out);

void resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                      const ::coder::array<double, 2U> &weights,
                      const ::coder::array<int, 2U> &indices,
                      unsigned char out[784]);

} // namespace coder

#endif
// End of code generation (imresize.h)
