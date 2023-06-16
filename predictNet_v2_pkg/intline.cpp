//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// intline.cpp
//
// Code generation for function 'intline'
//

// Include files
#include "intline.h"
#include "colon.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>

// Function Definitions
namespace coder {
namespace iptui {
void intline(double x1, double x2, double b_y1, double y2,
             ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
  array<double, 2U> b_y;
  double dx;
  double dy;
  double dy_tmp;
  double t;
  t = x2 - x1;
  dx = std::abs(t);
  dy_tmp = y2 - b_y1;
  dy = std::abs(dy_tmp);
  if ((dx == 0.0) && (dy == 0.0)) {
    x.set_size(1);
    x[0] = x1;
    y.set_size(1);
    y[0] = b_y1;
  } else {
    int c_flip;
    int md2;
    int nx;
    c_flip = 0;
    if (dx >= dy) {
      dx = dy_tmp / t;
      if (std::isnan(x1) || std::isnan(x2)) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else if (x2 < x1) {
        b_y.set_size(1, 0);
      } else if ((std::isinf(x1) || std::isinf(x2)) && (x1 == x2)) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else if (std::floor(x1) == x1) {
        nx = static_cast<int>(x2 - x1);
        b_y.set_size(1, nx + 1);
        for (md2 = 0; md2 <= nx; md2++) {
          b_y[md2] = x1 + static_cast<double>(md2);
        }
      } else {
        eml_float_colon(x1, x2, b_y);
      }
      x.set_size(b_y.size(1));
      nx = b_y.size(1);
      for (md2 = 0; md2 < nx; md2++) {
        x[md2] = b_y[md2];
      }
      y.set_size(x.size(0));
      nx = x.size(0);
      for (md2 = 0; md2 < nx; md2++) {
        y[md2] = b_y1 + dx * (x[md2] - x1);
      }
      nx = y.size(0);
      for (md2 = 0; md2 < nx; md2++) {
        y[md2] = std::round(y[md2]);
      }
    } else {
      if (b_y1 > y2) {
        t = x1;
        x1 = x2;
        x2 = t;
        t = b_y1;
        b_y1 = y2;
        y2 = t;
        c_flip = 1;
      }
      t = y2 - b_y1;
      dx = (x2 - x1) / t;
      if (std::isnan(b_y1) || std::isnan(y2)) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else if (y2 < b_y1) {
        b_y.set_size(1, 0);
      } else if ((std::isinf(b_y1) || std::isinf(y2)) && (b_y1 == y2)) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else if (std::floor(b_y1) == b_y1) {
        b_y.set_size(1, static_cast<int>(t) + 1);
        nx = static_cast<int>(y2 - b_y1);
        for (md2 = 0; md2 <= nx; md2++) {
          b_y[md2] = b_y1 + static_cast<double>(md2);
        }
      } else {
        eml_float_colon(b_y1, y2, b_y);
      }
      y.set_size(b_y.size(1));
      nx = b_y.size(1);
      for (md2 = 0; md2 < nx; md2++) {
        y[md2] = b_y[md2];
      }
      x.set_size(y.size(0));
      nx = y.size(0);
      for (md2 = 0; md2 < nx; md2++) {
        x[md2] = x1 + dx * (y[md2] - b_y1);
      }
      nx = x.size(0);
      for (md2 = 0; md2 < nx; md2++) {
        x[md2] = std::round(x[md2]);
      }
    }
    if (c_flip != 0) {
      c_flip = x.size(0) - 1;
      md2 = x.size(0) >> 1;
      for (int i{0}; i < md2; i++) {
        t = x[i];
        nx = c_flip - i;
        x[i] = x[nx];
        x[nx] = t;
      }
      c_flip = y.size(0) - 1;
      md2 = y.size(0) >> 1;
      for (int i{0}; i < md2; i++) {
        t = y[i];
        nx = c_flip - i;
        y[i] = y[nx];
        y[nx] = t;
      }
    }
  }
}

} // namespace iptui
} // namespace coder

// End of code generation (intline.cpp)
