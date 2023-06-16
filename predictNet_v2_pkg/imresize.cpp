//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imresize.cpp
//
// Code generation for function 'imresize'
//

// Include files
#include "imresize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "omp.h"
#include <cmath>

// Function Definitions
namespace coder {
void b_resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                        const ::coder::array<double, 2U> &weights,
                        const ::coder::array<int, 2U> &indices,
                        ::coder::array<unsigned char, 2U> &out)
{
  double sumVal1;
  double v;
  int i;
  int k;
  int linearInds;
  int outCInd;
  int pixelIndex;
  int pixelIndex_tmp;
  int ub_loop;
  ub_loop = in.size(0) - 1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    pixelIndex, linearInds, sumVal1, i, outCInd, k, v, pixelIndex_tmp)

  for (int inRInd = 0; inRInd <= ub_loop; inRInd++) {
    i = weights.size(0);
    for (outCInd = 0; outCInd < 28; outCInd++) {
      sumVal1 = 0.0;
      //  Core - second dimension
      linearInds = weights.size(0) * outCInd + 1;
      for (k = 0; k < i; k++) {
        pixelIndex_tmp = (linearInds + k) - 1;
        pixelIndex = (inRInd + (indices[pixelIndex_tmp] - 1) * in.size(0)) + 1;
        sumVal1 +=
            weights[pixelIndex_tmp] * static_cast<double>(in[pixelIndex - 1]);
      }
      v = std::abs(sumVal1);
      if (v < 4.503599627370496E+15) {
        if (v >= 0.5) {
          v = std::floor(sumVal1 + 0.5);
        } else {
          v = sumVal1 * 0.0;
        }
      } else {
        v = sumVal1;
      }
      if (sumVal1 > 255.0) {
        out[inRInd + out.size(0) * outCInd] = MAX_uint8_T;
      } else if (sumVal1 < 0.0) {
        out[inRInd + out.size(0) * outCInd] = 0U;
      } else {
        out[inRInd + out.size(0) * outCInd] = static_cast<unsigned char>(v);
      }
    }
  }
}

void b_resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                        const ::coder::array<double, 2U> &weights,
                        const ::coder::array<int, 2U> &indices,
                        unsigned char out[784])
{
  double sumVal1;
  double v;
  int i;
  int k;
  int linearInds;
  int outRInd;
  int sumVal1_tmp;
  int ub_loop;
  ub_loop = static_cast<int>(static_cast<double>(in.size(0) * 28) /
                             static_cast<double>(in.size(0))) -
            1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    linearInds, sumVal1, i, outRInd, k, v, sumVal1_tmp)

  for (int inCInd = 0; inCInd <= ub_loop; inCInd++) {
    i = weights.size(0);
    for (outRInd = 0; outRInd < 28; outRInd++) {
      sumVal1 = 0.0;
      linearInds = weights.size(0) * outRInd + 1;
      //  Core - first dimension
      for (k = 0; k < i; k++) {
        sumVal1_tmp = (linearInds + k) - 1;
        sumVal1 += weights[sumVal1_tmp] *
                   static_cast<double>(
                       in[(indices[sumVal1_tmp] + in.size(0) * inCInd) - 1]);
      }
      v = std::abs(sumVal1);
      if (v < 4.503599627370496E+15) {
        if (v >= 0.5) {
          v = std::floor(sumVal1 + 0.5);
        } else {
          v = sumVal1 * 0.0;
        }
      } else {
        v = sumVal1;
      }
      if (sumVal1 > 255.0) {
        out[outRInd + 28 * inCInd] = MAX_uint8_T;
      } else if (sumVal1 < 0.0) {
        out[outRInd + 28 * inCInd] = 0U;
      } else {
        out[outRInd + 28 * inCInd] = static_cast<unsigned char>(v);
      }
    }
  }
}

void contributions(int in_length, double scale, double kernel_width,
                   ::coder::array<double, 2U> &weights,
                   ::coder::array<int, 2U> &indices)
{
  array<double, 2U> b;
  array<double, 2U> x;
  array<int, 2U> aux;
  array<int, 2U> b_indices;
  array<int, 2U> r;
  array<int, 2U> r1;
  array<boolean_T, 2U> copyCols;
  double u[28];
  double k;
  int left[28];
  int firstBlockLength;
  int hi;
  int lastBlockLength;
  int nblocks;
  int xoffset;
  int yk;
  //  Contributions, using pixel indices
  if (scale < 1.0) {
    kernel_width = 2.0 / scale;
  }
  k = 0.5 * (1.0 - 1.0 / scale);
  for (int b_k{0}; b_k < 28; b_k++) {
    double d;
    d = (static_cast<double>(b_k) + 1.0) / scale + k;
    u[b_k] = d;
    left[b_k] = static_cast<int>(std::floor(d - kernel_width / 2.0));
  }
  firstBlockLength = static_cast<int>(std::ceil(kernel_width) + 2.0);
  aux.set_size(1, firstBlockLength);
  aux[0] = 0;
  yk = 0;
  for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
    yk++;
    aux[b_k - 1] = yk;
  }
  b_indices.set_size(28, aux.size(1));
  nblocks = aux.size(1) - 1;
  for (int b_k{0}; b_k <= nblocks; b_k++) {
    for (firstBlockLength = 0; firstBlockLength < 28; firstBlockLength++) {
      b_indices[firstBlockLength + 28 * b_k] =
          left[firstBlockLength] + aux[b_k];
    }
  }
  b.set_size(28, b_indices.size(1));
  firstBlockLength = 28 * b_indices.size(1);
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    b[nblocks] = b_indices[nblocks];
  }
  x.set_size(28, b.size(1));
  nblocks = b.size(1) - 1;
  for (int b_k{0}; b_k <= nblocks; b_k++) {
    for (firstBlockLength = 0; firstBlockLength < 28; firstBlockLength++) {
      x[firstBlockLength + 28 * b_k] =
          u[firstBlockLength] - b[firstBlockLength + 28 * b_k];
    }
  }
  if (scale < 1.0) {
    firstBlockLength = 28 * x.size(1);
    x.set_size(28, x.size(1));
    for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
      x[nblocks] = scale * x[nblocks];
    }
  }
  firstBlockLength = 28 * x.size(1);
  x.set_size(28, x.size(1));
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    x[nblocks] =
        (x[nblocks] + 1.0) *
            static_cast<double>((x[nblocks] >= -1.0) && (x[nblocks] < 0.0)) +
        (1.0 - x[nblocks]) *
            static_cast<double>((x[nblocks] >= 0.0) && (x[nblocks] <= 1.0));
  }
  if (scale < 1.0) {
    firstBlockLength = 28 * x.size(1);
    x.set_size(28, x.size(1));
    for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
      x[nblocks] = scale * x[nblocks];
    }
  }
  if (x.size(1) <= 1024) {
    firstBlockLength = x.size(1);
    lastBlockLength = 0;
    nblocks = 1;
  } else {
    firstBlockLength = 1024;
    nblocks = x.size(1) / 1024;
    lastBlockLength = x.size(1) - (nblocks << 10);
    if (lastBlockLength > 0) {
      nblocks++;
    } else {
      lastBlockLength = 1024;
    }
  }
  for (int xj{0}; xj < 28; xj++) {
    u[xj] = x[xj];
  }
  for (int b_k{2}; b_k <= firstBlockLength; b_k++) {
    xoffset = (b_k - 1) * 28;
    for (int xj{0}; xj < 28; xj++) {
      u[xj] += x[xoffset + xj];
    }
  }
  for (firstBlockLength = 2; firstBlockLength <= nblocks; firstBlockLength++) {
    double bsum[28];
    yk = (firstBlockLength - 1) * 28672;
    for (int xj{0}; xj < 28; xj++) {
      bsum[xj] = x[yk + xj];
    }
    if (firstBlockLength == nblocks) {
      hi = lastBlockLength;
    } else {
      hi = 1024;
    }
    for (int b_k{2}; b_k <= hi; b_k++) {
      xoffset = yk + (b_k - 1) * 28;
      for (int xj{0}; xj < 28; xj++) {
        bsum[xj] += x[xoffset + xj];
      }
    }
    for (int xj{0}; xj < 28; xj++) {
      u[xj] += bsum[xj];
    }
  }
  b.set_size(28, x.size(1));
  firstBlockLength = 28 * x.size(1);
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    b[nblocks] = x[nblocks];
  }
  firstBlockLength = x.size(1);
  x.set_size(28, firstBlockLength);
  nblocks = firstBlockLength - 1;
  for (int b_k{0}; b_k <= nblocks; b_k++) {
    for (firstBlockLength = 0; firstBlockLength < 28; firstBlockLength++) {
      x[firstBlockLength + 28 * b_k] =
          b[firstBlockLength + 28 * b_k] / u[firstBlockLength];
    }
  }
  //  Create the auxiliary matrix:
  yk = in_length << 1;
  aux.set_size(1, yk);
  aux[0] = 1;
  aux[in_length] = in_length;
  for (lastBlockLength = 2; lastBlockLength <= in_length; lastBlockLength++) {
    aux[lastBlockLength - 1] = aux[lastBlockLength - 2] + 1;
    firstBlockLength = in_length + lastBlockLength;
    aux[firstBlockLength - 1] = aux[firstBlockLength - 2] - 1;
  }
  //  Mirror the out-of-bounds indices using mod:
  nblocks = 28 * b_indices.size(1);
  for (lastBlockLength = 0; lastBlockLength < nblocks; lastBlockLength++) {
    k = static_cast<double>(b_indices[lastBlockLength]) - 1.0;
    if (yk == 0) {
      if (static_cast<double>(b_indices[lastBlockLength]) - 1.0 == 0.0) {
        k = 0.0;
      }
    } else if (static_cast<double>(b_indices[lastBlockLength]) - 1.0 == 0.0) {
      k = 0.0;
    } else {
      k = std::fmod(static_cast<double>(b_indices[lastBlockLength]) - 1.0,
                    static_cast<double>(yk));
      if (k == 0.0) {
        k = 0.0;
      } else if (static_cast<double>(b_indices[lastBlockLength]) - 1.0 < 0.0) {
        k += static_cast<double>(yk);
      }
    }
    b_indices[lastBlockLength] = aux[static_cast<int>(k)];
  }
  copyCols.set_size(1, x.size(1));
  firstBlockLength = x.size(1);
  for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
    copyCols[nblocks] = false;
  }
  firstBlockLength = x.size(1);
  yk = 0;
  for (lastBlockLength = 0; lastBlockLength < firstBlockLength;
       lastBlockLength++) {
    boolean_T exitg1;
    hi = yk + 28;
    nblocks = yk;
    yk += 28;
    exitg1 = false;
    while ((!exitg1) && (nblocks + 1 <= hi)) {
      if ((x[nblocks] == 0.0) || std::isnan(x[nblocks])) {
        nblocks++;
      } else {
        copyCols[lastBlockLength] = true;
        exitg1 = true;
      }
    }
  }
  yk = copyCols.size(1) - 1;
  firstBlockLength = 0;
  for (lastBlockLength = 0; lastBlockLength <= yk; lastBlockLength++) {
    if (copyCols[lastBlockLength]) {
      firstBlockLength++;
    }
  }
  r.set_size(1, firstBlockLength);
  firstBlockLength = 0;
  for (lastBlockLength = 0; lastBlockLength <= yk; lastBlockLength++) {
    if (copyCols[lastBlockLength]) {
      r[firstBlockLength] = lastBlockLength + 1;
      firstBlockLength++;
    }
  }
  weights.set_size(r.size(1), 28);
  firstBlockLength = r.size(1);
  for (nblocks = 0; nblocks < 28; nblocks++) {
    for (yk = 0; yk < firstBlockLength; yk++) {
      weights[yk + weights.size(0) * nblocks] = x[nblocks + 28 * (r[yk] - 1)];
    }
  }
  yk = copyCols.size(1) - 1;
  firstBlockLength = 0;
  for (lastBlockLength = 0; lastBlockLength <= yk; lastBlockLength++) {
    if (copyCols[lastBlockLength]) {
      firstBlockLength++;
    }
  }
  r1.set_size(1, firstBlockLength);
  firstBlockLength = 0;
  for (lastBlockLength = 0; lastBlockLength <= yk; lastBlockLength++) {
    if (copyCols[lastBlockLength]) {
      r1[firstBlockLength] = lastBlockLength + 1;
      firstBlockLength++;
    }
  }
  indices.set_size(r1.size(1), 28);
  firstBlockLength = r1.size(1);
  for (nblocks = 0; nblocks < 28; nblocks++) {
    for (yk = 0; yk < firstBlockLength; yk++) {
      indices[yk + indices.size(0) * nblocks] =
          b_indices[nblocks + 28 * (r1[yk] - 1)];
    }
  }
}

void resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                      const ::coder::array<double, 2U> &weights,
                      const ::coder::array<int, 2U> &indices,
                      ::coder::array<unsigned char, 2U> &out)
{
  double sumVal1;
  double v;
  int i;
  int k;
  int linearInds;
  int outRInd;
  int sumVal1_tmp;
  int ub_loop;
  ub_loop = static_cast<int>(static_cast<double>(in.size(0) * in.size(1)) /
                             static_cast<double>(in.size(0))) -
            1;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    linearInds, sumVal1, i, outRInd, k, v, sumVal1_tmp)

  for (int inCInd = 0; inCInd <= ub_loop; inCInd++) {
    i = weights.size(0);
    for (outRInd = 0; outRInd < 28; outRInd++) {
      sumVal1 = 0.0;
      linearInds = weights.size(0) * outRInd + 1;
      //  Core - first dimension
      for (k = 0; k < i; k++) {
        sumVal1_tmp = (linearInds + k) - 1;
        sumVal1 += weights[sumVal1_tmp] *
                   static_cast<double>(
                       in[(indices[sumVal1_tmp] + in.size(0) * inCInd) - 1]);
      }
      v = std::abs(sumVal1);
      if (v < 4.503599627370496E+15) {
        if (v >= 0.5) {
          v = std::floor(sumVal1 + 0.5);
        } else {
          v = sumVal1 * 0.0;
        }
      } else {
        v = sumVal1;
      }
      if (sumVal1 > 255.0) {
        out[outRInd + 28 * inCInd] = MAX_uint8_T;
      } else if (sumVal1 < 0.0) {
        out[outRInd + 28 * inCInd] = 0U;
      } else {
        out[outRInd + 28 * inCInd] = static_cast<unsigned char>(v);
      }
    }
  }
}

void resizeAlongDim2D(const ::coder::array<unsigned char, 2U> &in,
                      const ::coder::array<double, 2U> &weights,
                      const ::coder::array<int, 2U> &indices,
                      unsigned char out[784])
{
  double sumVal1;
  double v;
  int i;
  int k;
  int linearInds;
  int outCInd;
  int pixelIndex;
  int pixelIndex_tmp;
#pragma omp parallel for num_threads(omp_get_max_threads()) private(           \
    pixelIndex, linearInds, sumVal1, i, outCInd, k, v, pixelIndex_tmp)

  for (int inRInd = 0; inRInd < 28; inRInd++) {
    i = weights.size(0);
    for (outCInd = 0; outCInd < 28; outCInd++) {
      sumVal1 = 0.0;
      //  Core - second dimension
      linearInds = weights.size(0) * outCInd + 1;
      for (k = 0; k < i; k++) {
        pixelIndex_tmp = (linearInds + k) - 1;
        pixelIndex = (inRInd + (indices[pixelIndex_tmp] - 1) * 28) + 1;
        sumVal1 +=
            weights[pixelIndex_tmp] * static_cast<double>(in[pixelIndex - 1]);
      }
      v = std::abs(sumVal1);
      if (v < 4.503599627370496E+15) {
        if (v >= 0.5) {
          v = std::floor(sumVal1 + 0.5);
        } else {
          v = sumVal1 * 0.0;
        }
      } else {
        v = sumVal1;
      }
      if (sumVal1 > 255.0) {
        out[inRInd + 28 * outCInd] = MAX_uint8_T;
      } else if (sumVal1 < 0.0) {
        out[inRInd + 28 * outCInd] = 0U;
      } else {
        out[inRInd + 28 * outCInd] = static_cast<unsigned char>(v);
      }
    }
  }
}

} // namespace coder

// End of code generation (imresize.cpp)
