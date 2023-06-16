//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// imdilate.cpp
//
// Code generation for function 'imdilate'
//

// Include files
#include "imdilate.h"
#include "StrelImpl.h"
#include "flip.h"
#include "morphop.h"
#include "rt_nonfinite.h"
#include "strel.h"
#include "coder_array.h"
#include "libmwbwpackctbb.h"
#include "libmwbwunpackctbb.h"
#include "libmwmorphop_binary.h"
#include "libmwmorphop_binary_tbb.h"
#include "libmwmorphop_flat_tbb.h"
#include "libmwmorphop_ipp.h"
#include "libmwmorphop_nonflat_tbb.h"
#include "libmwmorphop_packed.h"
#include <cmath>

// Function Definitions
namespace coder {
void b_imdilate(const ::coder::array<boolean_T, 2U> &A, const strel *se,
                ::coder::array<boolean_T, 2U> &B)
{
  strel b_obj;
  strel obj;
  strel seq;
  array<double, 3U> allheight;
  array<unsigned int, 2U> Apadpack;
  array<unsigned int, 2U> Bpack;
  array<boolean_T, 3U> nhood;
  array<boolean_T, 2U> Apad;
  array<boolean_T, 2U> Apadpre;
  array<boolean_T, 2U> isEachStrelInSE2D;
  double nsizeT_data[3];
  double pad_lr1_data[3];
  double bwSize[2];
  double bwpSize[2];
  int nsizeT_size[2];
  int pad_lr1_size[2];
  int i;
  int i1;
  int i2;
  int k;
  int n;
  int numRows;
  int sInd;
  int vstride;
  signed char fcnNameEnum;
  signed char libNameEnum;
  boolean_T exitg1;
  boolean_T pre_pack;
  boolean_T strel_is_all_flat;
  boolean_T strel_is_single;
  se->decompose(&seq, isEachStrelInSE2D);
  strel_is_single = (seq.StrelArray.size(1) == 1);
  strel_is_all_flat = true;
  sInd = 0;
  exitg1 = false;
  while ((!exitg1) && (sInd <= seq.StrelArray.size(1) - 1)) {
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
    if (obj.StrelArray[0].Flat) {
      sInd++;
    } else {
      strel_is_all_flat = false;
      exitg1 = true;
    }
  }
  for (sInd = 0; sInd < seq.StrelArray.size(1); sInd++) {
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
  }
  pre_pack = ((!strel_is_single) && strel_is_all_flat);
  if (pre_pack) {
    fcnNameEnum = -1;
    libNameEnum = 1;
  } else {
    if (strel_is_single) {
      strel_is_all_flat = false;
      if ((se->StrelArray[0].nhood.size(0) == 3) &&
          (se->StrelArray[0].nhood.size(1) == 3)) {
        strel_is_all_flat = true;
      }
      if (strel_is_all_flat) {
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 9)) {
          if (!se->StrelArray[0].nhood[k]) {
            strel_is_all_flat = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }
      if (strel_is_all_flat) {
        fcnNameEnum = 10;
      } else {
        fcnNameEnum = 11;
      }
    } else {
      fcnNameEnum = 12;
    }
    libNameEnum = 5;
  }
  se->getpadsize(nsizeT_data, nsizeT_size, pad_lr1_data, pad_lr1_size);
  Apadpre.set_size(
      static_cast<int>(static_cast<double>(A.size(0)) + nsizeT_data[0]),
      static_cast<int>(static_cast<double>(A.size(1)) +
                       nsizeT_data[nsizeT_size[0]]));
  i = static_cast<int>(nsizeT_data[1]);
  for (n = 0; n < i; n++) {
    i1 = Apadpre.size(0);
    for (int b_i{0}; b_i < i1; b_i++) {
      Apadpre[b_i + Apadpre.size(0) * n] = false;
    }
  }
  i1 = static_cast<int>(nsizeT_data[1]) + 1;
  i2 = Apadpre.size(1);
  for (n = i1; n <= i2; n++) {
    vstride = static_cast<int>(nsizeT_data[0]);
    for (int b_i{0}; b_i < vstride; b_i++) {
      Apadpre[b_i + Apadpre.size(0) * (n - 1)] = false;
    }
  }
  i1 = A.size(1);
  i2 = A.size(0);
  for (n = 0; n < i1; n++) {
    for (int b_i{0}; b_i < i2; b_i++) {
      Apadpre[(b_i + static_cast<int>(nsizeT_data[0])) +
              Apadpre.size(0) * (n + i)] = A[b_i + A.size(0) * n];
    }
  }
  i = static_cast<int>(static_cast<double>(Apadpre.size(1)) + pad_lr1_data[1]);
  Apad.set_size(
      static_cast<int>(static_cast<double>(Apadpre.size(0)) + pad_lr1_data[0]),
      static_cast<int>(static_cast<double>(Apadpre.size(1)) +
                       pad_lr1_data[pad_lr1_size[0]]));
  i1 = Apadpre.size(1) + 1;
  for (n = i1; n <= i; n++) {
    i2 = Apad.size(0);
    for (int b_i{0}; b_i < i2; b_i++) {
      Apad[b_i + Apad.size(0) * (n - 1)] = false;
    }
  }
  i = Apadpre.size(1);
  i1 = Apadpre.size(0) + 1;
  for (n = 0; n < i; n++) {
    i2 = Apad.size(0);
    for (int b_i{i1}; b_i <= i2; b_i++) {
      Apad[(b_i + Apad.size(0) * n) - 1] = false;
    }
  }
  i = Apadpre.size(1);
  i1 = Apadpre.size(0);
  for (n = 0; n < i; n++) {
    for (int b_i{0}; b_i < i1; b_i++) {
      Apad[b_i + Apad.size(0) * n] = Apadpre[b_i + Apadpre.size(0) * n];
    }
  }
  if (pre_pack) {
    numRows = Apad.size(0);
    vstride =
        static_cast<int>(std::ceil(static_cast<double>(Apad.size(0)) / 32.0));
    Apadpack.set_size(vstride, Apad.size(1));
    bwSize[0] = Apad.size(0);
    bwSize[1] = Apad.size(1);
    bwpSize[0] = vstride;
    bwpSize[1] = Apad.size(1);
    bwPackingtbb(&Apad[0], &bwSize[0], &Apadpack[0], &bwpSize[0], true);
    Apad.set_size(0, 0);
  } else {
    numRows = -1;
    Apadpack.set_size(0, 0);
  }
  Bpack.set_size(Apadpack.size(0), Apadpack.size(1));
  B.set_size(Apad.size(0), Apad.size(1));
  i = seq.StrelArray.size(1);
  for (sInd = 0; sInd < i; sInd++) {
    int nd2;
    int tmp_tmp;
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
    b_obj = seq;
    b_obj.parenReference(static_cast<double>(sInd) + 1.0);
    nhood.set_size(obj.StrelArray[0].nhood.size(0),
                   obj.StrelArray[0].nhood.size(1), 1);
    vstride = obj.StrelArray[0].nhood.size(0) * obj.StrelArray[0].nhood.size(1);
    for (i1 = 0; i1 < vstride; i1++) {
      nhood[i1] = obj.StrelArray[0].nhood[i1];
    }
    allheight.set_size(b_obj.StrelArray[0].height.size(0),
                       b_obj.StrelArray[0].height.size(1), 1);
    vstride =
        b_obj.StrelArray[0].height.size(0) * b_obj.StrelArray[0].height.size(1);
    for (i1 = 0; i1 < vstride; i1++) {
      allheight[i1] = b_obj.StrelArray[0].height[i1];
    }
    flip(allheight);
    if ((allheight.size(0) != 0) && (allheight.size(1) != 0) &&
        (allheight.size(1) > 1)) {
      vstride = allheight.size(0);
      n = allheight.size(1) - 1;
      nd2 = allheight.size(1) >> 1;
      i1 = allheight.size(0) - 1;
      for (int b_i{0}; b_i <= i1; b_i++) {
        for (k = 0; k < nd2; k++) {
          double tmp;
          tmp_tmp = b_i + k * vstride;
          tmp = allheight[tmp_tmp];
          i2 = b_i + (n - k) * vstride;
          allheight[tmp_tmp] = allheight[i2];
          allheight[i2] = tmp;
        }
      }
    }
    strel_is_all_flat = false;
    vstride = 0;
    exitg1 = false;
    while ((!exitg1) &&
           (vstride + 1 <= allheight.size(0) * allheight.size(1))) {
      if ((allheight[vstride] == 0.0) || std::isnan(allheight[vstride])) {
        vstride++;
      } else {
        strel_is_all_flat = true;
        exitg1 = true;
      }
    }
    if (strel_is_all_flat) {
      b_flip(nhood);
      if ((nhood.size(0) != 0) && (nhood.size(1) != 0) && (nhood.size(1) > 1)) {
        vstride = nhood.size(0);
        n = nhood.size(1) - 1;
        nd2 = nhood.size(1) >> 1;
        i1 = nhood.size(0) - 1;
        for (int b_i{0}; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * vstride;
            strel_is_all_flat = nhood[tmp_tmp];
            i2 = b_i + (n - k) * vstride;
            nhood[tmp_tmp] = nhood[i2];
            nhood[i2] = strel_is_all_flat;
          }
        }
      }
    }
    if (pre_pack) {
      bwSize[0] = Apadpack.size(0);
      nsizeT_data[0] = nhood.size(0);
      bwSize[1] = Apadpack.size(1);
      nsizeT_data[1] = nhood.size(1);
      dilate_packed_uint32(&Apadpack[0], &bwSize[0], 2.0, &nhood[0],
                           &nsizeT_data[0], 2.0, &Bpack[0], true);
      Apadpack.set_size(Bpack.size(0), Bpack.size(1));
      vstride = Bpack.size(0) * Bpack.size(1);
      for (i1 = 0; i1 < vstride; i1++) {
        Apadpack[i1] = Bpack[i1];
      }
    } else {
      if (libNameEnum == 5) {
        if (fcnNameEnum == 10) {
          bwSize[0] = Apad.size(0);
          nsizeT_data[0] = nhood.size(0);
          bwSize[1] = Apad.size(1);
          nsizeT_data[1] = nhood.size(1);
          dilate_binary_ones33_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0],
                                   &nsizeT_data[0], 2.0, &B[0]);
        } else if (fcnNameEnum == 11) {
          bwSize[0] = Apad.size(0);
          nsizeT_data[0] = nhood.size(0);
          bwSize[1] = Apad.size(1);
          nsizeT_data[1] = nhood.size(1);
          dilate_binary_twod_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0],
                                 &nsizeT_data[0], 2.0, &B[0]);
        } else if (fcnNameEnum == 12) {
          bwSize[0] = Apad.size(0);
          nsizeT_data[0] = nhood.size(0);
          bwSize[1] = Apad.size(1);
          nsizeT_data[1] = nhood.size(1);
          dilate_binary_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0],
                            &nsizeT_data[0], 2.0, &B[0]);
        }
      } else if (fcnNameEnum == 10) {
        bwSize[0] = Apad.size(0);
        nsizeT_data[0] = nhood.size(0);
        bwSize[1] = Apad.size(1);
        nsizeT_data[1] = nhood.size(1);
        dilate_binary_ones33_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0],
                                 &nsizeT_data[0], 2.0, &B[0]);
      } else if (fcnNameEnum == 11) {
        bwSize[0] = Apad.size(0);
        nsizeT_data[0] = nhood.size(0);
        bwSize[1] = Apad.size(1);
        nsizeT_data[1] = nhood.size(1);
        dilate_binary_twod_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0],
                               &nsizeT_data[0], 2.0, &B[0]);
      } else if (fcnNameEnum == 12) {
        bwSize[0] = Apad.size(0);
        nsizeT_data[0] = nhood.size(0);
        bwSize[1] = Apad.size(1);
        nsizeT_data[1] = nhood.size(1);
        dilate_binary_tbb(&Apad[0], &bwSize[0], 2.0, &nhood[0], &nsizeT_data[0],
                          2.0, &B[0]);
      }
      Apad.set_size(B.size(0), B.size(1));
      vstride = B.size(0) * B.size(1);
      for (i1 = 0; i1 < vstride; i1++) {
        Apad[i1] = B[i1];
      }
    }
  }
  if (pre_pack) {
    if ((Bpack.size(0) == 0) || (Bpack.size(1) == 0)) {
      B.set_size(numRows, Bpack.size(1));
      vstride = numRows * Bpack.size(1);
      for (i = 0; i < vstride; i++) {
        B[i] = false;
      }
    } else {
      B.set_size(numRows, Bpack.size(1));
      bwpSize[0] = Bpack.size(0);
      bwSize[0] = numRows;
      bwpSize[1] = Bpack.size(1);
      bwSize[1] = Bpack.size(1);
      bwUnpackingtbb(&Bpack[0], &bwpSize[0], &B[0], &bwSize[0], true);
    }
  }
}

void imdilate(const ::coder::array<double, 2U> &A, const strel *se,
              ::coder::array<double, 2U> &B)
{
  strel b_seq;
  strel obj;
  strel seq;
  array<double, 3U> allheight;
  array<double, 2U> Apad;
  array<double, 2U> Apadpre;
  array<double, 1U> height;
  array<unsigned int, 2U> P;
  array<int, 1U> r;
  array<int, 1U> r1;
  array<boolean_T, 3U> nhood;
  array<boolean_T, 2U> isEachStrelInSE2D;
  array<boolean_T, 2U> x;
  double nsizeT_data[3];
  double pad_lr_data[3];
  double pad_ul_data[3];
  double sizeB[2];
  int pad_ul_size[2];
  int i;
  int i1;
  int i2;
  int k;
  int nd2;
  int sInd;
  int tmp_tmp;
  int vlen;
  int xpageoffset;
  signed char libNameEnum;
  boolean_T exitg1;
  boolean_T pre_pad;
  boolean_T strel_is_all_flat;
  boolean_T tmp;
  se->decompose(&seq, isEachStrelInSE2D);
  strel_is_all_flat = true;
  sInd = 0;
  exitg1 = false;
  while ((!exitg1) && (sInd <= seq.StrelArray.size(1) - 1)) {
    b_seq = seq;
    b_seq.parenReference(static_cast<double>(sInd) + 1.0);
    if (b_seq.StrelArray[0].Flat) {
      sInd++;
    } else {
      strel_is_all_flat = false;
      exitg1 = true;
    }
  }
  for (sInd = 0; sInd < seq.StrelArray.size(1); sInd++) {
    b_seq = seq;
    b_seq.parenReference(static_cast<double>(sInd) + 1.0);
  }
  if (seq.StrelArray.size(1) != 1) {
    int nz[3];
    boolean_T b_x[3];
    se->decomposeImpl(&b_seq);
    P.set_size(b_seq.StrelArray.size(1), 3);
    xpageoffset = b_seq.StrelArray.size(1) * 3;
    for (i = 0; i < xpageoffset; i++) {
      P[i] = 1U;
    }
    i = b_seq.StrelArray.size(1);
    for (sInd = 0; sInd < i; sInd++) {
      P[sInd] = static_cast<unsigned int>(b_seq.StrelArray[sInd].nhood.size(0));
      P[sInd + P.size(0)] =
          static_cast<unsigned int>(b_seq.StrelArray[sInd].nhood.size(1));
      P[sInd + P.size(0) * 2] = 1U;
    }
    xpageoffset = P.size(0) * 3 - 1;
    vlen = 0;
    for (int b_i{0}; b_i <= xpageoffset; b_i++) {
      if (static_cast<int>(P[b_i]) == 0) {
        vlen++;
      }
    }
    r.set_size(vlen);
    vlen = 0;
    for (int b_i{0}; b_i <= xpageoffset; b_i++) {
      if (static_cast<int>(P[b_i]) == 0) {
        r[vlen] = b_i + 1;
        vlen++;
      }
    }
    xpageoffset = r.size(0) - 1;
    for (i = 0; i <= xpageoffset; i++) {
      P[r[i] - 1] = 1U;
    }
    x.set_size(P.size(0), 3);
    xpageoffset = P.size(0) * 3;
    for (i = 0; i < xpageoffset; i++) {
      x[i] = (static_cast<int>(P[i]) != 1);
    }
    vlen = x.size(0);
    if (x.size(0) == 0) {
      nz[0] = 0;
      nz[1] = 0;
      nz[2] = 0;
    } else {
      for (int b_i{0}; b_i < 3; b_i++) {
        xpageoffset = b_i * x.size(0);
        nz[b_i] = x[xpageoffset];
        for (k = 2; k <= vlen; k++) {
          nz[b_i] += x[(xpageoffset + k) - 1];
        }
      }
    }
    b_x[0] = (nz[0] == 1);
    b_x[1] = (nz[1] == 1);
    b_x[2] = (nz[2] == 1);
    tmp = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 3)) {
      if (b_x[k]) {
        tmp = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (!tmp) {
      pre_pad = true;
    } else {
      pre_pad = false;
    }
  } else {
    pre_pad = false;
  }
  if (strel_is_all_flat) {
    libNameEnum = 6;
  } else {
    libNameEnum = 7;
  }
  if (pre_pad) {
    int pad_lr_size[2];
    se->getpadsize(pad_ul_data, pad_ul_size, pad_lr_data, pad_lr_size);
    if ((A.size(0) == 0) || (A.size(1) == 0)) {
      sizeB[0] = static_cast<double>(A.size(0)) + pad_ul_data[0];
      sizeB[1] = static_cast<double>(A.size(1)) + pad_ul_data[1];
      Apadpre.set_size(static_cast<int>(sizeB[0]), static_cast<int>(sizeB[1]));
      xpageoffset = static_cast<int>(sizeB[0]) * static_cast<int>(sizeB[1]);
      for (i = 0; i < xpageoffset; i++) {
        Apadpre[i] = rtMinusInf;
      }
    } else {
      Apadpre.set_size(
          static_cast<int>(static_cast<double>(A.size(0)) + pad_ul_data[0]),
          static_cast<int>(static_cast<double>(A.size(1)) +
                           pad_ul_data[pad_ul_size[0]]));
      i = static_cast<int>(pad_ul_data[1]);
      for (vlen = 0; vlen < i; vlen++) {
        i1 = Apadpre.size(0);
        for (int b_i{0}; b_i < i1; b_i++) {
          Apadpre[b_i + Apadpre.size(0) * vlen] = rtMinusInf;
        }
      }
      i = static_cast<int>(pad_ul_data[1]) + 1;
      i1 = Apadpre.size(1);
      for (vlen = i; vlen <= i1; vlen++) {
        i2 = static_cast<int>(pad_ul_data[0]);
        for (int b_i{0}; b_i < i2; b_i++) {
          Apadpre[b_i + Apadpre.size(0) * (vlen - 1)] = rtMinusInf;
        }
      }
      i = A.size(1);
      i1 = A.size(0);
      for (vlen = 0; vlen < i; vlen++) {
        for (int b_i{0}; b_i < i1; b_i++) {
          Apadpre[(b_i + static_cast<int>(pad_ul_data[0])) +
                  Apadpre.size(0) * (vlen + static_cast<int>(pad_ul_data[1]))] =
              A[b_i + A.size(0) * vlen];
        }
      }
    }
    if ((Apadpre.size(0) == 0) || (Apadpre.size(1) == 0)) {
      sizeB[0] = static_cast<double>(Apadpre.size(0)) + pad_lr_data[0];
      sizeB[1] = static_cast<double>(Apadpre.size(1)) + pad_lr_data[1];
      Apad.set_size(static_cast<int>(sizeB[0]), static_cast<int>(sizeB[1]));
      xpageoffset = static_cast<int>(sizeB[0]) * static_cast<int>(sizeB[1]);
      for (i = 0; i < xpageoffset; i++) {
        Apad[i] = rtMinusInf;
      }
    } else {
      i = static_cast<int>(static_cast<double>(Apadpre.size(1)) +
                           pad_lr_data[1]);
      Apad.set_size(static_cast<int>(static_cast<double>(Apadpre.size(0)) +
                                     pad_lr_data[0]),
                    static_cast<int>(static_cast<double>(Apadpre.size(1)) +
                                     pad_lr_data[pad_lr_size[0]]));
      i1 = Apadpre.size(1) + 1;
      for (vlen = i1; vlen <= i; vlen++) {
        i2 = Apad.size(0);
        for (int b_i{0}; b_i < i2; b_i++) {
          Apad[b_i + Apad.size(0) * (vlen - 1)] = rtMinusInf;
        }
      }
      i = Apadpre.size(1);
      i1 = Apadpre.size(0) + 1;
      for (vlen = 0; vlen < i; vlen++) {
        i2 = Apad.size(0);
        for (int b_i{i1}; b_i <= i2; b_i++) {
          Apad[(b_i + Apad.size(0) * vlen) - 1] = rtMinusInf;
        }
      }
      i = Apadpre.size(1);
      i1 = Apadpre.size(0);
      for (vlen = 0; vlen < i; vlen++) {
        for (int b_i{0}; b_i < i1; b_i++) {
          Apad[b_i + Apad.size(0) * vlen] =
              Apadpre[b_i + Apadpre.size(0) * vlen];
        }
      }
    }
  } else {
    Apad.set_size(A.size(0), A.size(1));
    xpageoffset = A.size(0) * A.size(1);
    for (i = 0; i < xpageoffset; i++) {
      Apad[i] = A[i];
    }
    pad_ul_size[1] = 2;
    pad_ul_data[0] = -1.0;
    pad_lr_data[0] = -1.0;
    pad_ul_data[1] = -1.0;
    pad_lr_data[1] = -1.0;
  }
  B.set_size(Apad.size(0), Apad.size(1));
  i = seq.StrelArray.size(1);
  for (sInd = 0; sInd < i; sInd++) {
    b_seq = seq;
    b_seq.parenReference(static_cast<double>(sInd) + 1.0);
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
    nhood.set_size(b_seq.StrelArray[0].nhood.size(0),
                   b_seq.StrelArray[0].nhood.size(1), 1);
    xpageoffset =
        b_seq.StrelArray[0].nhood.size(0) * b_seq.StrelArray[0].nhood.size(1);
    for (i1 = 0; i1 < xpageoffset; i1++) {
      nhood[i1] = b_seq.StrelArray[0].nhood[i1];
    }
    allheight.set_size(obj.StrelArray[0].height.size(0),
                       obj.StrelArray[0].height.size(1), 1);
    xpageoffset =
        obj.StrelArray[0].height.size(0) * obj.StrelArray[0].height.size(1);
    for (i1 = 0; i1 < xpageoffset; i1++) {
      allheight[i1] = obj.StrelArray[0].height[i1];
    }
    flip(allheight);
    if ((allheight.size(0) != 0) && (allheight.size(1) != 0) &&
        (allheight.size(1) > 1)) {
      vlen = allheight.size(0);
      xpageoffset = allheight.size(1) - 1;
      nd2 = allheight.size(1) >> 1;
      i1 = allheight.size(0) - 1;
      for (int b_i{0}; b_i <= i1; b_i++) {
        for (k = 0; k < nd2; k++) {
          double b_tmp;
          tmp_tmp = b_i + k * vlen;
          b_tmp = allheight[tmp_tmp];
          i2 = b_i + (xpageoffset - k) * vlen;
          allheight[tmp_tmp] = allheight[i2];
          allheight[i2] = b_tmp;
        }
      }
    }
    tmp = false;
    vlen = 0;
    exitg1 = false;
    while ((!exitg1) && (vlen + 1 <= allheight.size(0) * allheight.size(1))) {
      if ((allheight[vlen] == 0.0) || std::isnan(allheight[vlen])) {
        vlen++;
      } else {
        tmp = true;
        exitg1 = true;
      }
    }
    if (tmp) {
      b_flip(nhood);
      if ((nhood.size(0) != 0) && (nhood.size(1) != 0) && (nhood.size(1) > 1)) {
        vlen = nhood.size(0);
        xpageoffset = nhood.size(1) - 1;
        nd2 = nhood.size(1) >> 1;
        i1 = nhood.size(0) - 1;
        for (int b_i{0}; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * vlen;
            tmp = nhood[tmp_tmp];
            i2 = b_i + (xpageoffset - k) * vlen;
            nhood[tmp_tmp] = nhood[i2];
            nhood[i2] = tmp;
          }
        }
      }
    }
    xpageoffset = nhood.size(0) * nhood.size(1) - 1;
    vlen = 0;
    for (int b_i{0}; b_i <= xpageoffset; b_i++) {
      if (nhood[b_i]) {
        vlen++;
      }
    }
    r1.set_size(vlen);
    vlen = 0;
    for (int b_i{0}; b_i <= xpageoffset; b_i++) {
      if (nhood[b_i]) {
        r1[vlen] = b_i + 1;
        vlen++;
      }
    }
    xpageoffset = r1.size(0);
    height.set_size(r1.size(0));
    for (i1 = 0; i1 < xpageoffset; i1++) {
      height[i1] = allheight[r1[i1] - 1];
    }
    if (libNameEnum == 7) {
      sizeB[0] = Apad.size(0);
      nsizeT_data[0] = nhood.size(0);
      sizeB[1] = Apad.size(1);
      nsizeT_data[1] = nhood.size(1);
      dilate_nonflat_real64_tbb(&Apad[0], &sizeB[0], 2.0, &nhood[0],
                                &nsizeT_data[0], 2.0, &(height.data())[0],
                                &B[0]);
    } else {
      sizeB[0] = Apad.size(0);
      nsizeT_data[0] = nhood.size(0);
      sizeB[1] = Apad.size(1);
      nsizeT_data[1] = nhood.size(1);
      dilate_flat_real64_tbb(&Apad[0], &sizeB[0], 2.0, &nhood[0],
                             &nsizeT_data[0], 2.0, &B[0]);
    }
    Apad.set_size(B.size(0), B.size(1));
    xpageoffset = B.size(0) * B.size(1);
    for (i1 = 0; i1 < xpageoffset; i1++) {
      Apad[i1] = B[i1];
    }
  }
  if (pre_pad) {
    vlen = pad_ul_size[1];
    xpageoffset = pad_ul_size[1];
    for (i = 0; i < xpageoffset; i++) {
      nsizeT_data[i] = pad_ul_data[i] + 1.0;
    }
    for (i = 0; i < vlen; i++) {
      sizeB[i] = (((nsizeT_data[i] + static_cast<double>(B.size(i))) -
                   pad_ul_data[i]) -
                  pad_lr_data[i]) -
                 1.0;
    }
    if (nsizeT_data[0] > sizeB[0]) {
      i = -1;
      i1 = -1;
    } else {
      i = static_cast<int>(nsizeT_data[0]) - 2;
      i1 = static_cast<int>(sizeB[0]) - 1;
    }
    if (nsizeT_data[1] > sizeB[1]) {
      i2 = 0;
      nd2 = 0;
    } else {
      i2 = static_cast<int>(nsizeT_data[1]) - 1;
      nd2 = static_cast<int>(sizeB[1]);
    }
    vlen = nd2 - i2;
    for (nd2 = 0; nd2 < vlen; nd2++) {
      xpageoffset = i1 - i;
      for (tmp_tmp = 0; tmp_tmp < xpageoffset; tmp_tmp++) {
        B[tmp_tmp + xpageoffset * nd2] =
            B[((i + tmp_tmp) + B.size(0) * (i2 + nd2)) + 1];
      }
    }
    B.set_size(i1 - i, vlen);
  }
}

void imdilate(const strel *se, ::coder::array<float, 2U> &B)
{
  strel b_obj;
  strel obj;
  strel seq;
  array<double, 3U> allheight;
  array<double, 1U> height;
  array<float, 2U> Apad;
  array<float, 2U> Apadpre;
  array<int, 1U> r;
  array<boolean_T, 3U> nhood;
  array<boolean_T, 2U> isEachStrelInSE2D;
  double nsizeT_data[3];
  double pad_lr1_data[3];
  double asizeT[2];
  int nsizeT_size[2];
  int pad_lr1_size[2];
  int i;
  int i1;
  int i2;
  int n;
  int sInd;
  int vstride;
  signed char libNameEnum;
  boolean_T exitg1;
  boolean_T strel_is_all_flat;
  se->decompose(&seq, isEachStrelInSE2D);
  strel_is_all_flat = true;
  sInd = 0;
  exitg1 = false;
  while ((!exitg1) && (sInd <= seq.StrelArray.size(1) - 1)) {
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
    if (obj.StrelArray[0].Flat) {
      sInd++;
    } else {
      strel_is_all_flat = false;
      exitg1 = true;
    }
  }
  for (sInd = 0; sInd < seq.StrelArray.size(1); sInd++) {
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
  }
  if (strel_is_all_flat) {
    libNameEnum = 6;
  } else {
    libNameEnum = 7;
  }
  se->getpadsize(nsizeT_data, nsizeT_size, pad_lr1_data, pad_lr1_size);
  n = nsizeT_size[1];
  for (i = 0; i < n; i++) {
    asizeT[i] = nsizeT_data[i] + 1.0;
  }
  Apadpre.set_size(static_cast<int>(asizeT[0]), static_cast<int>(asizeT[1]));
  i = static_cast<int>(nsizeT_data[1]);
  for (vstride = 0; vstride < i; vstride++) {
    i1 = Apadpre.size(0);
    for (int b_i{0}; b_i < i1; b_i++) {
      Apadpre[b_i + Apadpre.size(0) * vstride] = rtMinusInfF;
    }
  }
  i = static_cast<int>(nsizeT_data[1]) + 1;
  i1 = Apadpre.size(1);
  for (vstride = i; vstride <= i1; vstride++) {
    i2 = static_cast<int>(nsizeT_data[0]);
    for (int b_i{0}; b_i < i2; b_i++) {
      Apadpre[b_i + Apadpre.size(0) * (vstride - 1)] = rtMinusInfF;
    }
  }
  Apadpre[static_cast<int>(nsizeT_data[0]) +
          Apadpre.size(0) * static_cast<int>(nsizeT_data[1])] = 1.0F;
  i = static_cast<int>(static_cast<double>(Apadpre.size(1)) + pad_lr1_data[1]);
  Apad.set_size(
      static_cast<int>(static_cast<double>(Apadpre.size(0)) + pad_lr1_data[0]),
      static_cast<int>(static_cast<double>(Apadpre.size(1)) +
                       pad_lr1_data[pad_lr1_size[0]]));
  i1 = Apadpre.size(1) + 1;
  for (vstride = i1; vstride <= i; vstride++) {
    i2 = Apad.size(0);
    for (int b_i{0}; b_i < i2; b_i++) {
      Apad[b_i + Apad.size(0) * (vstride - 1)] = rtMinusInfF;
    }
  }
  i = Apadpre.size(1);
  i1 = Apadpre.size(0) + 1;
  for (vstride = 0; vstride < i; vstride++) {
    i2 = Apad.size(0);
    for (int b_i{i1}; b_i <= i2; b_i++) {
      Apad[(b_i + Apad.size(0) * vstride) - 1] = rtMinusInfF;
    }
  }
  i = Apadpre.size(1);
  i1 = Apadpre.size(0);
  for (vstride = 0; vstride < i; vstride++) {
    for (int b_i{0}; b_i < i1; b_i++) {
      Apad[b_i + Apad.size(0) * vstride] =
          Apadpre[b_i + Apadpre.size(0) * vstride];
    }
  }
  B.set_size(Apad.size(0), Apad.size(1));
  i = seq.StrelArray.size(1);
  for (sInd = 0; sInd < i; sInd++) {
    obj = seq;
    obj.parenReference(static_cast<double>(sInd) + 1.0);
    b_obj = seq;
    b_obj.parenReference(static_cast<double>(sInd) + 1.0);
    if (images::internal::coder::useIPP(obj.StrelArray[0].nhood,
                                        b_obj.StrelArray[0].height) &&
        strel_is_all_flat) {
      double b_tmp;
      int k;
      int nd2;
      int tmp_tmp;
      signed char iv[3];
      boolean_T tmp;
      iv[0] = static_cast<signed char>(
          std::fmod(static_cast<double>(obj.StrelArray[0].nhood.size(0)), 2.0));
      iv[1] = static_cast<signed char>(
          std::fmod(static_cast<double>(obj.StrelArray[0].nhood.size(1)), 2.0));
      iv[2] = 1;
      tmp = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 3)) {
        if (iv[k] == 0) {
          tmp = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (tmp) {
        double d;
        double d1;
        double numColPad;
        b_tmp = (static_cast<double>(obj.StrelArray[0].nhood.size(0)) -
                 2.0 * std::ceil(static_cast<double>(
                                     obj.StrelArray[0].nhood.size(0)) /
                                 2.0)) +
                1.0;
        numColPad = (static_cast<double>(obj.StrelArray[0].nhood.size(1)) -
                     2.0 * std::ceil(static_cast<double>(
                                         obj.StrelArray[0].nhood.size(1)) /
                                     2.0)) +
                    1.0;
        nhood.set_size(
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(0)) + b_tmp),
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(1)) +
                numColPad),
            1);
        n = static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(0)) + b_tmp) *
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(1)) +
                numColPad);
        for (i1 = 0; i1 < n; i1++) {
          nhood[i1] = false;
        }
        allheight.set_size(
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(0)) + b_tmp),
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(1)) +
                numColPad),
            1);
        n = static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(0)) + b_tmp) *
            static_cast<int>(
                static_cast<double>(obj.StrelArray[0].nhood.size(1)) +
                numColPad);
        for (i1 = 0; i1 < n; i1++) {
          allheight[i1] = 0.0;
        }
        d = std::fmod(b_tmp, 4.294967296E+9);
        if (d < 0.0) {
          i1 = -static_cast<int>(static_cast<unsigned int>(-d));
        } else {
          i1 = static_cast<int>(static_cast<unsigned int>(d));
        }
        if (b_tmp + 1.0 > obj.StrelArray[0].nhood.size(0) + i1) {
          i1 = 1;
        } else {
          i1 = static_cast<int>(b_tmp + 1.0);
        }
        d1 = std::fmod(numColPad, 4.294967296E+9);
        if (d1 < 0.0) {
          i2 = -static_cast<int>(static_cast<unsigned int>(-d1));
        } else {
          i2 = static_cast<int>(static_cast<unsigned int>(d1));
        }
        if (numColPad + 1.0 > obj.StrelArray[0].nhood.size(1) + i2) {
          i2 = 1;
        } else {
          i2 = static_cast<int>(numColPad + 1.0);
        }
        if (d < 0.0) {
          n = -static_cast<int>(static_cast<unsigned int>(-d));
        } else {
          n = static_cast<int>(static_cast<unsigned int>(d));
        }
        vstride = obj.StrelArray[0].nhood.size(0) + n;
        n = obj.StrelArray[0].nhood.size(0);
        nd2 = obj.StrelArray[0].nhood.size(1);
        for (tmp_tmp = 0; tmp_tmp < nd2; tmp_tmp++) {
          for (k = 0; k < n; k++) {
            nhood[((i1 + k) + vstride * ((i2 + tmp_tmp) - 1)) - 1] =
                obj.StrelArray[0]
                    .nhood[k + obj.StrelArray[0].nhood.size(0) * tmp_tmp];
          }
        }
        if (d < 0.0) {
          i1 = -static_cast<int>(static_cast<unsigned int>(-d));
        } else {
          i1 = static_cast<int>(static_cast<unsigned int>(d));
        }
        if (b_tmp + 1.0 > obj.StrelArray[0].nhood.size(0) + i1) {
          i1 = 1;
        } else {
          i1 = static_cast<int>(b_tmp + 1.0);
        }
        if (d1 < 0.0) {
          i2 = -static_cast<int>(static_cast<unsigned int>(-d1));
        } else {
          i2 = static_cast<int>(static_cast<unsigned int>(d1));
        }
        if (numColPad + 1.0 > obj.StrelArray[0].nhood.size(1) + i2) {
          i2 = 1;
        } else {
          i2 = static_cast<int>(numColPad + 1.0);
        }
        if (d < 0.0) {
          n = -static_cast<int>(static_cast<unsigned int>(-d));
        } else {
          n = static_cast<int>(static_cast<unsigned int>(d));
        }
        vstride = obj.StrelArray[0].nhood.size(0) + n;
        n = b_obj.StrelArray[0].height.size(0);
        nd2 = b_obj.StrelArray[0].height.size(1);
        for (tmp_tmp = 0; tmp_tmp < nd2; tmp_tmp++) {
          for (k = 0; k < n; k++) {
            allheight[((i1 + k) + vstride * ((i2 + tmp_tmp) - 1)) - 1] =
                b_obj.StrelArray[0]
                    .height[k + b_obj.StrelArray[0].height.size(0) * tmp_tmp];
          }
        }
      } else {
        nhood.set_size(obj.StrelArray[0].nhood.size(0),
                       obj.StrelArray[0].nhood.size(1), 1);
        n = obj.StrelArray[0].nhood.size(0) * obj.StrelArray[0].nhood.size(1);
        for (i1 = 0; i1 < n; i1++) {
          nhood[i1] = obj.StrelArray[0].nhood[i1];
        }
        allheight.set_size(b_obj.StrelArray[0].height.size(0),
                           b_obj.StrelArray[0].height.size(1), 1);
        n = b_obj.StrelArray[0].height.size(0) *
            b_obj.StrelArray[0].height.size(1);
        for (i1 = 0; i1 < n; i1++) {
          allheight[i1] = b_obj.StrelArray[0].height[i1];
        }
      }
      flip(allheight);
      if ((allheight.size(0) != 0) && (allheight.size(1) != 0) &&
          (allheight.size(1) > 1)) {
        vstride = allheight.size(0);
        n = allheight.size(1) - 1;
        nd2 = allheight.size(1) >> 1;
        i1 = allheight.size(0) - 1;
        for (int b_i{0}; b_i <= i1; b_i++) {
          for (k = 0; k < nd2; k++) {
            tmp_tmp = b_i + k * vstride;
            b_tmp = allheight[tmp_tmp];
            i2 = b_i + (n - k) * vstride;
            allheight[tmp_tmp] = allheight[i2];
            allheight[i2] = b_tmp;
          }
        }
      }
      tmp = false;
      vstride = 0;
      exitg1 = false;
      while ((!exitg1) &&
             (vstride + 1 <= allheight.size(0) * allheight.size(1))) {
        if ((allheight[vstride] == 0.0) || std::isnan(allheight[vstride])) {
          vstride++;
        } else {
          tmp = true;
          exitg1 = true;
        }
      }
      if (tmp) {
        b_flip(nhood);
        if ((nhood.size(0) != 0) && (nhood.size(1) != 0) &&
            (nhood.size(1) > 1)) {
          vstride = nhood.size(0);
          n = nhood.size(1) - 1;
          nd2 = nhood.size(1) >> 1;
          i1 = nhood.size(0) - 1;
          for (int b_i{0}; b_i <= i1; b_i++) {
            for (k = 0; k < nd2; k++) {
              tmp_tmp = b_i + k * vstride;
              tmp = nhood[tmp_tmp];
              i2 = b_i + (n - k) * vstride;
              nhood[tmp_tmp] = nhood[i2];
              nhood[i2] = tmp;
            }
          }
        }
      }
      asizeT[0] = Apad.size(0);
      nsizeT_data[0] = nhood.size(0);
      asizeT[1] = Apad.size(1);
      nsizeT_data[1] = nhood.size(1);
      dilate_real32_ipp(&Apad[0], &asizeT[0], &nhood[0], &nsizeT_data[0],
                        &B[0]);
    } else {
      int nd2;
      int tmp_tmp;
      boolean_T tmp;
      nhood.set_size(obj.StrelArray[0].nhood.size(0),
                     obj.StrelArray[0].nhood.size(1), 1);
      n = obj.StrelArray[0].nhood.size(0) * obj.StrelArray[0].nhood.size(1);
      for (i1 = 0; i1 < n; i1++) {
        nhood[i1] = obj.StrelArray[0].nhood[i1];
      }
      allheight.set_size(b_obj.StrelArray[0].height.size(0),
                         b_obj.StrelArray[0].height.size(1), 1);
      n = b_obj.StrelArray[0].height.size(0) *
          b_obj.StrelArray[0].height.size(1);
      for (i1 = 0; i1 < n; i1++) {
        allheight[i1] = b_obj.StrelArray[0].height[i1];
      }
      flip(allheight);
      if ((allheight.size(0) != 0) && (allheight.size(1) != 0) &&
          (allheight.size(1) > 1)) {
        vstride = allheight.size(0);
        n = allheight.size(1) - 1;
        nd2 = allheight.size(1) >> 1;
        i1 = allheight.size(0) - 1;
        for (int b_i{0}; b_i <= i1; b_i++) {
          for (int k{0}; k < nd2; k++) {
            double b_tmp;
            tmp_tmp = b_i + k * vstride;
            b_tmp = allheight[tmp_tmp];
            i2 = b_i + (n - k) * vstride;
            allheight[tmp_tmp] = allheight[i2];
            allheight[i2] = b_tmp;
          }
        }
      }
      tmp = false;
      vstride = 0;
      exitg1 = false;
      while ((!exitg1) &&
             (vstride + 1 <= allheight.size(0) * allheight.size(1))) {
        if ((allheight[vstride] == 0.0) || std::isnan(allheight[vstride])) {
          vstride++;
        } else {
          tmp = true;
          exitg1 = true;
        }
      }
      if (tmp) {
        b_flip(nhood);
        if ((nhood.size(0) != 0) && (nhood.size(1) != 0) &&
            (nhood.size(1) > 1)) {
          vstride = nhood.size(0);
          n = nhood.size(1) - 1;
          nd2 = nhood.size(1) >> 1;
          i1 = nhood.size(0) - 1;
          for (int b_i{0}; b_i <= i1; b_i++) {
            for (int k{0}; k < nd2; k++) {
              tmp_tmp = b_i + k * vstride;
              tmp = nhood[tmp_tmp];
              i2 = b_i + (n - k) * vstride;
              nhood[tmp_tmp] = nhood[i2];
              nhood[i2] = tmp;
            }
          }
        }
      }
      n = nhood.size(0) * nhood.size(1) - 1;
      vstride = 0;
      for (int b_i{0}; b_i <= n; b_i++) {
        if (nhood[b_i]) {
          vstride++;
        }
      }
      r.set_size(vstride);
      vstride = 0;
      for (int b_i{0}; b_i <= n; b_i++) {
        if (nhood[b_i]) {
          r[vstride] = b_i + 1;
          vstride++;
        }
      }
      n = r.size(0);
      height.set_size(r.size(0));
      for (i1 = 0; i1 < n; i1++) {
        height[i1] = allheight[r[i1] - 1];
      }
      if (libNameEnum == 7) {
        asizeT[0] = Apad.size(0);
        nsizeT_data[0] = nhood.size(0);
        asizeT[1] = Apad.size(1);
        nsizeT_data[1] = nhood.size(1);
        dilate_nonflat_real32_tbb(&Apad[0], &asizeT[0], 2.0, &nhood[0],
                                  &nsizeT_data[0], 2.0, &(height.data())[0],
                                  &B[0]);
      } else {
        asizeT[0] = Apad.size(0);
        nsizeT_data[0] = nhood.size(0);
        asizeT[1] = Apad.size(1);
        nsizeT_data[1] = nhood.size(1);
        dilate_flat_real32_tbb(&Apad[0], &asizeT[0], 2.0, &nhood[0],
                               &nsizeT_data[0], 2.0, &B[0]);
      }
    }
    Apad.set_size(B.size(0), B.size(1));
    n = B.size(0) * B.size(1);
    for (i1 = 0; i1 < n; i1++) {
      Apad[i1] = B[i1];
    }
  }
}

} // namespace coder

// End of code generation (imdilate.cpp)
