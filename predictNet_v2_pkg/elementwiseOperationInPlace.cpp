//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// elementwiseOperationInPlace.cpp
//
// Code generation for function 'elementwiseOperationInPlace'
//

// Include files
#include "elementwiseOperationInPlace.h"
#include "rt_nonfinite.h"
#include "omp.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace layer {
void b_elementwiseOperationInPlace(float X[12544])
{
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int iElem = 0; iElem < 12544; iElem++) {
    X[iElem] = std::fmax(0.0F, X[iElem]);
  }
}

void c_elementwiseOperationInPlace(float X[64])
{
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int iElem = 0; iElem < 64; iElem++) {
    X[iElem] = std::fmax(0.0F, X[iElem]);
  }
}

void elementwiseOperationInPlace(float X[25088])
{
#pragma omp parallel for num_threads(omp_get_max_threads())

  for (int iElem = 0; iElem < 25088; iElem++) {
    X[iElem] = std::fmax(0.0F, X[iElem]);
  }
}

} // namespace layer
} // namespace coder

// End of code generation (elementwiseOperationInPlace.cpp)
