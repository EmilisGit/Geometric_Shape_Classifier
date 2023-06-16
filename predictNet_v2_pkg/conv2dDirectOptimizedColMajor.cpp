//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// conv2dDirectOptimizedColMajor.cpp
//
// Code generation for function 'conv2dDirectOptimizedColMajor'
//

// Include files
#include "conv2dDirectOptimizedColMajor.h"
#include "elementwiseOperationInPlace.h"
#include "rt_nonfinite.h"
#include <cstring>

// Function Declarations
static void b_convolution(const float *inputTensor, float *outputTensor, const
  float *weights, const float *bias);
static void b_convolutionKernel(const float *inputBufferPtr, float
  *outputBufferPtr, const float *weightsPtr);
static void convolution(const float *inputTensor, float *outputTensor, const
  float *weights, const float *bias);
static void convolutionKernel(const float *inputBufferPtr, float
  *outputBufferPtr, const float *weightsPtr);

// Function Definitions
static void b_convolution(const float *inputTensor, float *outputTensor, const
  float *weights, const float *bias)
{
  static float inputBuffer[4096];
  static boolean_T bufferInitialized;
  float outputBuffer[12544];
  float *elemRefOutputBufferVar;
  int bufferIdx2;
  int bufferIdx3;
  int inputIdx;
  int inputIdx2;
  int inputIdx3;
  int weightsIdx;
  if (!bufferInitialized) {
    std::memset(&inputBuffer[0], 0, 16384U);
    bufferInitialized = true;
  }

  std::memset(&outputBuffer[0], 0, 50176U);
  inputIdx = 0;
  weightsIdx = 0;
  for (int inputChannelBlockIdx{0}; inputChannelBlockIdx < 2;
       inputChannelBlockIdx++) {
    bufferIdx2 = 272;
    inputIdx2 = inputIdx;
    for (int inputWidthIdx{0}; inputWidthIdx < 14; inputWidthIdx++) {
      bufferIdx3 = bufferIdx2;
      inputIdx3 = inputIdx2;
      for (int inputHeightIdx{0}; inputHeightIdx < 14; inputHeightIdx++) {
        for (int bufferChannelIdx{0}; bufferChannelIdx < 16; bufferChannelIdx++)
        {
          inputBuffer[bufferIdx3 + bufferChannelIdx] = inputTensor[inputIdx3 +
            bufferChannelIdx * 196];
        }

        bufferIdx3 += 16;
        inputIdx3++;
      }

      bufferIdx2 += 256;
      inputIdx2 += 14;
    }

    bufferIdx2 = weightsIdx;
    inputIdx2 = 0;
    for (int inputWidthIdx{0}; inputWidthIdx < 4; inputWidthIdx++) {
      bufferIdx3 = 0;
      inputIdx3 = inputIdx2;
      for (int inputHeightIdx{0}; inputHeightIdx < 14; inputHeightIdx++) {
        b_convolutionKernel(&inputBuffer[bufferIdx3], &outputBuffer[inputIdx3],
                            &weights[bufferIdx2]);
        bufferIdx3 += 256;
        inputIdx3 += 14;
      }

      bufferIdx2 += 4608;
      inputIdx2 += 3136;
    }

    inputIdx += 3136;
    weightsIdx += 144;
  }

  bufferIdx2 = 0;
  inputIdx2 = 0;
  for (int inputWidthIdx{0}; inputWidthIdx < 64; inputWidthIdx++) {
    float biasRegister;
    biasRegister = bias[inputWidthIdx];
    bufferIdx3 = bufferIdx2;
    for (int inputHeightIdx{0}; inputHeightIdx < 196; inputHeightIdx++) {
      inputIdx3 = inputIdx2 + inputHeightIdx;
      elemRefOutputBufferVar = &outputBuffer[inputIdx3];
      *elemRefOutputBufferVar += biasRegister;
      outputTensor[bufferIdx3] = outputBuffer[inputIdx3];
      bufferIdx3++;
    }

    bufferIdx2 += 196;
    inputIdx2 += 196;
  }
}

static void b_convolutionKernel(const float *inputBufferPtr, float
  *outputBufferPtr, const float *weightsPtr)
{
  int inputBufferIdx1;
  inputBufferIdx1 = 0;
  for (int outputHeightBlockIdx{0}; outputHeightBlockIdx < 2;
       outputHeightBlockIdx++) {
    float ab_outputRegister;
    float ac_outputRegister;
    float ad_outputRegister;
    float ae_outputRegister;
    float b_outputRegister;
    float bb_outputRegister;
    float bc_outputRegister;
    float bd_outputRegister;
    float be_outputRegister;
    float c_outputRegister;
    float cb_outputRegister;
    float cc_outputRegister;
    float cd_outputRegister;
    float ce_outputRegister;
    float d_outputRegister;
    float db_outputRegister;
    float dc_outputRegister;
    float dd_outputRegister;
    float de_outputRegister;
    float e_outputRegister;
    float eb_outputRegister;
    float ec_outputRegister;
    float ed_outputRegister;
    float ee_outputRegister;
    float f_outputRegister;
    float fb_outputRegister;
    float fc_outputRegister;
    float fd_outputRegister;
    float fe_outputRegister;
    float g_outputRegister;
    float gb_outputRegister;
    float gc_outputRegister;
    float gd_outputRegister;
    float ge_outputRegister;
    float h_outputRegister;
    float hb_outputRegister;
    float hc_outputRegister;
    float hd_outputRegister;
    float he_outputRegister;
    float i_outputRegister;
    float ib_outputRegister;
    float ic_outputRegister;
    float id_outputRegister;
    float ie_outputRegister;
    float j_outputRegister;
    float jb_outputRegister;
    float jc_outputRegister;
    float jd_outputRegister;
    float je_outputRegister;
    float k_outputRegister;
    float kb_outputRegister;
    float kc_outputRegister;
    float kd_outputRegister;
    float ke_outputRegister;
    float l_outputRegister;
    float lb_outputRegister;
    float lc_outputRegister;
    float ld_outputRegister;
    float le_outputRegister;
    float m_outputRegister;
    float mb_outputRegister;
    float mc_outputRegister;
    float md_outputRegister;
    float n_outputRegister;
    float nb_outputRegister;
    float nc_outputRegister;
    float nd_outputRegister;
    float o_outputRegister;
    float ob_outputRegister;
    float oc_outputRegister;
    float od_outputRegister;
    float outputRegister;
    float p_outputRegister;
    float pb_outputRegister;
    float pc_outputRegister;
    float pd_outputRegister;
    float q_outputRegister;
    float qb_outputRegister;
    float qc_outputRegister;
    float qd_outputRegister;
    float r_outputRegister;
    float rb_outputRegister;
    float rc_outputRegister;
    float rd_outputRegister;
    float s_outputRegister;
    float sb_outputRegister;
    float sc_outputRegister;
    float sd_outputRegister;
    float t_outputRegister;
    float tb_outputRegister;
    float tc_outputRegister;
    float td_outputRegister;
    float u_outputRegister;
    float ub_outputRegister;
    float uc_outputRegister;
    float ud_outputRegister;
    float v_outputRegister;
    float vb_outputRegister;
    float vc_outputRegister;
    float vd_outputRegister;
    float w_outputRegister;
    float wb_outputRegister;
    float wc_outputRegister;
    float wd_outputRegister;
    float x_outputRegister;
    float xb_outputRegister;
    float xc_outputRegister;
    float xd_outputRegister;
    float y_outputRegister;
    float yb_outputRegister;
    float yc_outputRegister;
    float yd_outputRegister;
    int ab_outputRegister_tmp;
    int ac_outputRegister_tmp;
    int ad_outputRegister_tmp;
    int ae_outputRegister_tmp;
    int b_outputRegister_tmp;
    int bb_outputRegister_tmp;
    int bc_outputRegister_tmp;
    int bd_outputRegister_tmp;
    int be_outputRegister_tmp;
    int c_outputRegister_tmp;
    int cb_outputRegister_tmp;
    int cc_outputRegister_tmp;
    int cd_outputRegister_tmp;
    int ce_outputRegister_tmp;
    int d_outputRegister_tmp;
    int db_outputRegister_tmp;
    int dc_outputRegister_tmp;
    int dd_outputRegister_tmp;
    int de_outputRegister_tmp;
    int e_outputRegister_tmp;
    int eb_outputRegister_tmp;
    int ec_outputRegister_tmp;
    int ed_outputRegister_tmp;
    int ee_outputRegister_tmp;
    int f_outputRegister_tmp;
    int fb_outputRegister_tmp;
    int fc_outputRegister_tmp;
    int fd_outputRegister_tmp;
    int fe_outputRegister_tmp;
    int g_outputRegister_tmp;
    int gb_outputRegister_tmp;
    int gc_outputRegister_tmp;
    int gd_outputRegister_tmp;
    int ge_outputRegister_tmp;
    int h_outputRegister_tmp;
    int hb_outputRegister_tmp;
    int hc_outputRegister_tmp;
    int hd_outputRegister_tmp;
    int he_outputRegister_tmp;
    int i_outputRegister_tmp;
    int ib_outputRegister_tmp;
    int ic_outputRegister_tmp;
    int id_outputRegister_tmp;
    int ie_outputRegister_tmp;
    int inputBufferIdx2;
    int j_outputRegister_tmp;
    int jb_outputRegister_tmp;
    int jc_outputRegister_tmp;
    int jd_outputRegister_tmp;
    int je_outputRegister_tmp;
    int k_outputRegister_tmp;
    int kb_outputRegister_tmp;
    int kc_outputRegister_tmp;
    int kd_outputRegister_tmp;
    int ke_outputRegister_tmp;
    int l_outputRegister_tmp;
    int lb_outputRegister_tmp;
    int lc_outputRegister_tmp;
    int ld_outputRegister_tmp;
    int m_outputRegister_tmp;
    int mb_outputRegister_tmp;
    int mc_outputRegister_tmp;
    int md_outputRegister_tmp;
    int n_outputRegister_tmp;
    int nb_outputRegister_tmp;
    int nc_outputRegister_tmp;
    int nd_outputRegister_tmp;
    int o_outputRegister_tmp;
    int ob_outputRegister_tmp;
    int oc_outputRegister_tmp;
    int od_outputRegister_tmp;
    int outputRegister_tmp;
    int p_outputRegister_tmp;
    int pb_outputRegister_tmp;
    int pc_outputRegister_tmp;
    int pd_outputRegister_tmp;
    int q_outputRegister_tmp;
    int qb_outputRegister_tmp;
    int qc_outputRegister_tmp;
    int qd_outputRegister_tmp;
    int r_outputRegister_tmp;
    int rb_outputRegister_tmp;
    int rc_outputRegister_tmp;
    int rd_outputRegister_tmp;
    int s_outputRegister_tmp;
    int sb_outputRegister_tmp;
    int sc_outputRegister_tmp;
    int sd_outputRegister_tmp;
    int t_outputRegister_tmp;
    int tb_outputRegister_tmp;
    int tc_outputRegister_tmp;
    int td_outputRegister_tmp;
    int u_outputRegister_tmp;
    int ub_outputRegister_tmp;
    int uc_outputRegister_tmp;
    int ud_outputRegister_tmp;
    int v_outputRegister_tmp;
    int vb_outputRegister_tmp;
    int vc_outputRegister_tmp;
    int vd_outputRegister_tmp;
    int w_outputRegister_tmp;
    int wb_outputRegister_tmp;
    int wc_outputRegister_tmp;
    int wd_outputRegister_tmp;
    int weightsIdx;
    int x_outputRegister_tmp;
    int xb_outputRegister_tmp;
    int xc_outputRegister_tmp;
    int xd_outputRegister_tmp;
    int y_outputRegister_tmp;
    int yb_outputRegister_tmp;
    int yc_outputRegister_tmp;
    int yd_outputRegister_tmp;
    outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
    outputRegister_tmp = outputHeightBlockIdx * 7 + 1;
    b_outputRegister = outputBufferPtr[outputRegister_tmp];
    b_outputRegister_tmp = outputHeightBlockIdx * 7 + 2;
    c_outputRegister = outputBufferPtr[b_outputRegister_tmp];
    c_outputRegister_tmp = outputHeightBlockIdx * 7 + 3;
    d_outputRegister = outputBufferPtr[c_outputRegister_tmp];
    d_outputRegister_tmp = outputHeightBlockIdx * 7 + 4;
    e_outputRegister = outputBufferPtr[d_outputRegister_tmp];
    e_outputRegister_tmp = outputHeightBlockIdx * 7 + 5;
    f_outputRegister = outputBufferPtr[e_outputRegister_tmp];
    f_outputRegister_tmp = outputHeightBlockIdx * 7 + 6;
    g_outputRegister = outputBufferPtr[f_outputRegister_tmp];
    g_outputRegister_tmp = outputHeightBlockIdx * 7 + 196;
    h_outputRegister = outputBufferPtr[g_outputRegister_tmp];
    h_outputRegister_tmp = outputHeightBlockIdx * 7 + 197;
    i_outputRegister = outputBufferPtr[h_outputRegister_tmp];
    i_outputRegister_tmp = outputHeightBlockIdx * 7 + 198;
    j_outputRegister = outputBufferPtr[i_outputRegister_tmp];
    j_outputRegister_tmp = outputHeightBlockIdx * 7 + 199;
    k_outputRegister = outputBufferPtr[j_outputRegister_tmp];
    k_outputRegister_tmp = outputHeightBlockIdx * 7 + 200;
    l_outputRegister = outputBufferPtr[k_outputRegister_tmp];
    l_outputRegister_tmp = outputHeightBlockIdx * 7 + 201;
    m_outputRegister = outputBufferPtr[l_outputRegister_tmp];
    m_outputRegister_tmp = outputHeightBlockIdx * 7 + 202;
    n_outputRegister = outputBufferPtr[m_outputRegister_tmp];
    n_outputRegister_tmp = outputHeightBlockIdx * 7 + 392;
    o_outputRegister = outputBufferPtr[n_outputRegister_tmp];
    o_outputRegister_tmp = outputHeightBlockIdx * 7 + 393;
    p_outputRegister = outputBufferPtr[o_outputRegister_tmp];
    p_outputRegister_tmp = outputHeightBlockIdx * 7 + 394;
    q_outputRegister = outputBufferPtr[p_outputRegister_tmp];
    q_outputRegister_tmp = outputHeightBlockIdx * 7 + 395;
    r_outputRegister = outputBufferPtr[q_outputRegister_tmp];
    r_outputRegister_tmp = outputHeightBlockIdx * 7 + 396;
    s_outputRegister = outputBufferPtr[r_outputRegister_tmp];
    s_outputRegister_tmp = outputHeightBlockIdx * 7 + 397;
    t_outputRegister = outputBufferPtr[s_outputRegister_tmp];
    t_outputRegister_tmp = outputHeightBlockIdx * 7 + 398;
    u_outputRegister = outputBufferPtr[t_outputRegister_tmp];
    u_outputRegister_tmp = outputHeightBlockIdx * 7 + 588;
    v_outputRegister = outputBufferPtr[u_outputRegister_tmp];
    v_outputRegister_tmp = outputHeightBlockIdx * 7 + 589;
    w_outputRegister = outputBufferPtr[v_outputRegister_tmp];
    w_outputRegister_tmp = outputHeightBlockIdx * 7 + 590;
    x_outputRegister = outputBufferPtr[w_outputRegister_tmp];
    x_outputRegister_tmp = outputHeightBlockIdx * 7 + 591;
    y_outputRegister = outputBufferPtr[x_outputRegister_tmp];
    y_outputRegister_tmp = outputHeightBlockIdx * 7 + 592;
    ab_outputRegister = outputBufferPtr[y_outputRegister_tmp];
    ab_outputRegister_tmp = outputHeightBlockIdx * 7 + 593;
    bb_outputRegister = outputBufferPtr[ab_outputRegister_tmp];
    bb_outputRegister_tmp = outputHeightBlockIdx * 7 + 594;
    cb_outputRegister = outputBufferPtr[bb_outputRegister_tmp];
    cb_outputRegister_tmp = outputHeightBlockIdx * 7 + 784;
    db_outputRegister = outputBufferPtr[cb_outputRegister_tmp];
    db_outputRegister_tmp = outputHeightBlockIdx * 7 + 785;
    eb_outputRegister = outputBufferPtr[db_outputRegister_tmp];
    eb_outputRegister_tmp = outputHeightBlockIdx * 7 + 786;
    fb_outputRegister = outputBufferPtr[eb_outputRegister_tmp];
    fb_outputRegister_tmp = outputHeightBlockIdx * 7 + 787;
    gb_outputRegister = outputBufferPtr[fb_outputRegister_tmp];
    gb_outputRegister_tmp = outputHeightBlockIdx * 7 + 788;
    hb_outputRegister = outputBufferPtr[gb_outputRegister_tmp];
    hb_outputRegister_tmp = outputHeightBlockIdx * 7 + 789;
    ib_outputRegister = outputBufferPtr[hb_outputRegister_tmp];
    ib_outputRegister_tmp = outputHeightBlockIdx * 7 + 790;
    jb_outputRegister = outputBufferPtr[ib_outputRegister_tmp];
    jb_outputRegister_tmp = outputHeightBlockIdx * 7 + 980;
    kb_outputRegister = outputBufferPtr[jb_outputRegister_tmp];
    kb_outputRegister_tmp = outputHeightBlockIdx * 7 + 981;
    lb_outputRegister = outputBufferPtr[kb_outputRegister_tmp];
    lb_outputRegister_tmp = outputHeightBlockIdx * 7 + 982;
    mb_outputRegister = outputBufferPtr[lb_outputRegister_tmp];
    mb_outputRegister_tmp = outputHeightBlockIdx * 7 + 983;
    nb_outputRegister = outputBufferPtr[mb_outputRegister_tmp];
    nb_outputRegister_tmp = outputHeightBlockIdx * 7 + 984;
    ob_outputRegister = outputBufferPtr[nb_outputRegister_tmp];
    ob_outputRegister_tmp = outputHeightBlockIdx * 7 + 985;
    pb_outputRegister = outputBufferPtr[ob_outputRegister_tmp];
    pb_outputRegister_tmp = outputHeightBlockIdx * 7 + 986;
    qb_outputRegister = outputBufferPtr[pb_outputRegister_tmp];
    qb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1176;
    rb_outputRegister = outputBufferPtr[qb_outputRegister_tmp];
    rb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1177;
    sb_outputRegister = outputBufferPtr[rb_outputRegister_tmp];
    sb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1178;
    tb_outputRegister = outputBufferPtr[sb_outputRegister_tmp];
    tb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1179;
    ub_outputRegister = outputBufferPtr[tb_outputRegister_tmp];
    ub_outputRegister_tmp = outputHeightBlockIdx * 7 + 1180;
    vb_outputRegister = outputBufferPtr[ub_outputRegister_tmp];
    vb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1181;
    wb_outputRegister = outputBufferPtr[vb_outputRegister_tmp];
    wb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1182;
    xb_outputRegister = outputBufferPtr[wb_outputRegister_tmp];
    xb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1372;
    yb_outputRegister = outputBufferPtr[xb_outputRegister_tmp];
    yb_outputRegister_tmp = outputHeightBlockIdx * 7 + 1373;
    ac_outputRegister = outputBufferPtr[yb_outputRegister_tmp];
    ac_outputRegister_tmp = outputHeightBlockIdx * 7 + 1374;
    bc_outputRegister = outputBufferPtr[ac_outputRegister_tmp];
    bc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1375;
    cc_outputRegister = outputBufferPtr[bc_outputRegister_tmp];
    cc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1376;
    dc_outputRegister = outputBufferPtr[cc_outputRegister_tmp];
    dc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1377;
    ec_outputRegister = outputBufferPtr[dc_outputRegister_tmp];
    ec_outputRegister_tmp = outputHeightBlockIdx * 7 + 1378;
    fc_outputRegister = outputBufferPtr[ec_outputRegister_tmp];
    fc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1568;
    gc_outputRegister = outputBufferPtr[fc_outputRegister_tmp];
    gc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1569;
    hc_outputRegister = outputBufferPtr[gc_outputRegister_tmp];
    hc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1570;
    ic_outputRegister = outputBufferPtr[hc_outputRegister_tmp];
    ic_outputRegister_tmp = outputHeightBlockIdx * 7 + 1571;
    jc_outputRegister = outputBufferPtr[ic_outputRegister_tmp];
    jc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1572;
    kc_outputRegister = outputBufferPtr[jc_outputRegister_tmp];
    kc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1573;
    lc_outputRegister = outputBufferPtr[kc_outputRegister_tmp];
    lc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1574;
    mc_outputRegister = outputBufferPtr[lc_outputRegister_tmp];
    mc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1764;
    nc_outputRegister = outputBufferPtr[mc_outputRegister_tmp];
    nc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1765;
    oc_outputRegister = outputBufferPtr[nc_outputRegister_tmp];
    oc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1766;
    pc_outputRegister = outputBufferPtr[oc_outputRegister_tmp];
    pc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1767;
    qc_outputRegister = outputBufferPtr[pc_outputRegister_tmp];
    qc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1768;
    rc_outputRegister = outputBufferPtr[qc_outputRegister_tmp];
    rc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1769;
    sc_outputRegister = outputBufferPtr[rc_outputRegister_tmp];
    sc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1770;
    tc_outputRegister = outputBufferPtr[sc_outputRegister_tmp];
    tc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1960;
    uc_outputRegister = outputBufferPtr[tc_outputRegister_tmp];
    uc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1961;
    vc_outputRegister = outputBufferPtr[uc_outputRegister_tmp];
    vc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1962;
    wc_outputRegister = outputBufferPtr[vc_outputRegister_tmp];
    wc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1963;
    xc_outputRegister = outputBufferPtr[wc_outputRegister_tmp];
    xc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1964;
    yc_outputRegister = outputBufferPtr[xc_outputRegister_tmp];
    yc_outputRegister_tmp = outputHeightBlockIdx * 7 + 1965;
    ad_outputRegister = outputBufferPtr[yc_outputRegister_tmp];
    ad_outputRegister_tmp = outputHeightBlockIdx * 7 + 1966;
    bd_outputRegister = outputBufferPtr[ad_outputRegister_tmp];
    bd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2156;
    cd_outputRegister = outputBufferPtr[bd_outputRegister_tmp];
    cd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2157;
    dd_outputRegister = outputBufferPtr[cd_outputRegister_tmp];
    dd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2158;
    ed_outputRegister = outputBufferPtr[dd_outputRegister_tmp];
    ed_outputRegister_tmp = outputHeightBlockIdx * 7 + 2159;
    fd_outputRegister = outputBufferPtr[ed_outputRegister_tmp];
    fd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2160;
    gd_outputRegister = outputBufferPtr[fd_outputRegister_tmp];
    gd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2161;
    hd_outputRegister = outputBufferPtr[gd_outputRegister_tmp];
    hd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2162;
    id_outputRegister = outputBufferPtr[hd_outputRegister_tmp];
    id_outputRegister_tmp = outputHeightBlockIdx * 7 + 2352;
    jd_outputRegister = outputBufferPtr[id_outputRegister_tmp];
    jd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2353;
    kd_outputRegister = outputBufferPtr[jd_outputRegister_tmp];
    kd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2354;
    ld_outputRegister = outputBufferPtr[kd_outputRegister_tmp];
    ld_outputRegister_tmp = outputHeightBlockIdx * 7 + 2355;
    md_outputRegister = outputBufferPtr[ld_outputRegister_tmp];
    md_outputRegister_tmp = outputHeightBlockIdx * 7 + 2356;
    nd_outputRegister = outputBufferPtr[md_outputRegister_tmp];
    nd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2357;
    od_outputRegister = outputBufferPtr[nd_outputRegister_tmp];
    od_outputRegister_tmp = outputHeightBlockIdx * 7 + 2358;
    pd_outputRegister = outputBufferPtr[od_outputRegister_tmp];
    pd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2548;
    qd_outputRegister = outputBufferPtr[pd_outputRegister_tmp];
    qd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2549;
    rd_outputRegister = outputBufferPtr[qd_outputRegister_tmp];
    rd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2550;
    sd_outputRegister = outputBufferPtr[rd_outputRegister_tmp];
    sd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2551;
    td_outputRegister = outputBufferPtr[sd_outputRegister_tmp];
    td_outputRegister_tmp = outputHeightBlockIdx * 7 + 2552;
    ud_outputRegister = outputBufferPtr[td_outputRegister_tmp];
    ud_outputRegister_tmp = outputHeightBlockIdx * 7 + 2553;
    vd_outputRegister = outputBufferPtr[ud_outputRegister_tmp];
    vd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2554;
    wd_outputRegister = outputBufferPtr[vd_outputRegister_tmp];
    wd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2744;
    xd_outputRegister = outputBufferPtr[wd_outputRegister_tmp];
    xd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2745;
    yd_outputRegister = outputBufferPtr[xd_outputRegister_tmp];
    yd_outputRegister_tmp = outputHeightBlockIdx * 7 + 2746;
    ae_outputRegister = outputBufferPtr[yd_outputRegister_tmp];
    ae_outputRegister_tmp = outputHeightBlockIdx * 7 + 2747;
    be_outputRegister = outputBufferPtr[ae_outputRegister_tmp];
    be_outputRegister_tmp = outputHeightBlockIdx * 7 + 2748;
    ce_outputRegister = outputBufferPtr[be_outputRegister_tmp];
    ce_outputRegister_tmp = outputHeightBlockIdx * 7 + 2749;
    de_outputRegister = outputBufferPtr[ce_outputRegister_tmp];
    de_outputRegister_tmp = outputHeightBlockIdx * 7 + 2750;
    ee_outputRegister = outputBufferPtr[de_outputRegister_tmp];
    ee_outputRegister_tmp = outputHeightBlockIdx * 7 + 2940;
    fe_outputRegister = outputBufferPtr[ee_outputRegister_tmp];
    fe_outputRegister_tmp = outputHeightBlockIdx * 7 + 2941;
    ge_outputRegister = outputBufferPtr[fe_outputRegister_tmp];
    ge_outputRegister_tmp = outputHeightBlockIdx * 7 + 2942;
    he_outputRegister = outputBufferPtr[ge_outputRegister_tmp];
    he_outputRegister_tmp = outputHeightBlockIdx * 7 + 2943;
    ie_outputRegister = outputBufferPtr[he_outputRegister_tmp];
    ie_outputRegister_tmp = outputHeightBlockIdx * 7 + 2944;
    je_outputRegister = outputBufferPtr[ie_outputRegister_tmp];
    je_outputRegister_tmp = outputHeightBlockIdx * 7 + 2945;
    ke_outputRegister = outputBufferPtr[je_outputRegister_tmp];
    ke_outputRegister_tmp = outputHeightBlockIdx * 7 + 2946;
    le_outputRegister = outputBufferPtr[ke_outputRegister_tmp];
    inputBufferIdx2 = inputBufferIdx1;
    weightsIdx = 0;
    for (int kernelWidthIdx{0}; kernelWidthIdx < 3; kernelWidthIdx++) {
      int inputBufferIdx3;
      inputBufferIdx3 = inputBufferIdx2;
      for (int kernelHeightIdx{0}; kernelHeightIdx < 3; kernelHeightIdx++) {
        for (int inputChannelIdx{0}; inputChannelIdx < 16; inputChannelIdx++) {
          float b_inputRegister;
          float c_inputRegister;
          float d_inputRegister;
          float e_inputRegister;
          float f_inputRegister;
          float g_inputRegister;
          float inputRegister;
          float weightsRegister;
          int inputRegister_tmp;
          inputRegister_tmp = inputBufferIdx3 + inputChannelIdx;
          inputRegister = inputBufferPtr[inputRegister_tmp];
          b_inputRegister = inputBufferPtr[inputRegister_tmp + 16];
          c_inputRegister = inputBufferPtr[inputRegister_tmp + 32];
          d_inputRegister = inputBufferPtr[inputRegister_tmp + 48];
          e_inputRegister = inputBufferPtr[inputRegister_tmp + 64];
          f_inputRegister = inputBufferPtr[inputRegister_tmp + 80];
          g_inputRegister = inputBufferPtr[inputRegister_tmp + 96];
          inputRegister_tmp = weightsIdx + inputChannelIdx;
          weightsRegister = weightsPtr[inputRegister_tmp];
          outputRegister += inputRegister * weightsRegister;
          b_outputRegister += b_inputRegister * weightsRegister;
          c_outputRegister += c_inputRegister * weightsRegister;
          d_outputRegister += d_inputRegister * weightsRegister;
          e_outputRegister += e_inputRegister * weightsRegister;
          f_outputRegister += f_inputRegister * weightsRegister;
          g_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 288];
          h_outputRegister += inputRegister * weightsRegister;
          i_outputRegister += b_inputRegister * weightsRegister;
          j_outputRegister += c_inputRegister * weightsRegister;
          k_outputRegister += d_inputRegister * weightsRegister;
          l_outputRegister += e_inputRegister * weightsRegister;
          m_outputRegister += f_inputRegister * weightsRegister;
          n_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 576];
          o_outputRegister += inputRegister * weightsRegister;
          p_outputRegister += b_inputRegister * weightsRegister;
          q_outputRegister += c_inputRegister * weightsRegister;
          r_outputRegister += d_inputRegister * weightsRegister;
          s_outputRegister += e_inputRegister * weightsRegister;
          t_outputRegister += f_inputRegister * weightsRegister;
          u_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 864];
          v_outputRegister += inputRegister * weightsRegister;
          w_outputRegister += b_inputRegister * weightsRegister;
          x_outputRegister += c_inputRegister * weightsRegister;
          y_outputRegister += d_inputRegister * weightsRegister;
          ab_outputRegister += e_inputRegister * weightsRegister;
          bb_outputRegister += f_inputRegister * weightsRegister;
          cb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1152];
          db_outputRegister += inputRegister * weightsRegister;
          eb_outputRegister += b_inputRegister * weightsRegister;
          fb_outputRegister += c_inputRegister * weightsRegister;
          gb_outputRegister += d_inputRegister * weightsRegister;
          hb_outputRegister += e_inputRegister * weightsRegister;
          ib_outputRegister += f_inputRegister * weightsRegister;
          jb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1440];
          kb_outputRegister += inputRegister * weightsRegister;
          lb_outputRegister += b_inputRegister * weightsRegister;
          mb_outputRegister += c_inputRegister * weightsRegister;
          nb_outputRegister += d_inputRegister * weightsRegister;
          ob_outputRegister += e_inputRegister * weightsRegister;
          pb_outputRegister += f_inputRegister * weightsRegister;
          qb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1728];
          rb_outputRegister += inputRegister * weightsRegister;
          sb_outputRegister += b_inputRegister * weightsRegister;
          tb_outputRegister += c_inputRegister * weightsRegister;
          ub_outputRegister += d_inputRegister * weightsRegister;
          vb_outputRegister += e_inputRegister * weightsRegister;
          wb_outputRegister += f_inputRegister * weightsRegister;
          xb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2016];
          yb_outputRegister += inputRegister * weightsRegister;
          ac_outputRegister += b_inputRegister * weightsRegister;
          bc_outputRegister += c_inputRegister * weightsRegister;
          cc_outputRegister += d_inputRegister * weightsRegister;
          dc_outputRegister += e_inputRegister * weightsRegister;
          ec_outputRegister += f_inputRegister * weightsRegister;
          fc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2304];
          gc_outputRegister += inputRegister * weightsRegister;
          hc_outputRegister += b_inputRegister * weightsRegister;
          ic_outputRegister += c_inputRegister * weightsRegister;
          jc_outputRegister += d_inputRegister * weightsRegister;
          kc_outputRegister += e_inputRegister * weightsRegister;
          lc_outputRegister += f_inputRegister * weightsRegister;
          mc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2592];
          nc_outputRegister += inputRegister * weightsRegister;
          oc_outputRegister += b_inputRegister * weightsRegister;
          pc_outputRegister += c_inputRegister * weightsRegister;
          qc_outputRegister += d_inputRegister * weightsRegister;
          rc_outputRegister += e_inputRegister * weightsRegister;
          sc_outputRegister += f_inputRegister * weightsRegister;
          tc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2880];
          uc_outputRegister += inputRegister * weightsRegister;
          vc_outputRegister += b_inputRegister * weightsRegister;
          wc_outputRegister += c_inputRegister * weightsRegister;
          xc_outputRegister += d_inputRegister * weightsRegister;
          yc_outputRegister += e_inputRegister * weightsRegister;
          ad_outputRegister += f_inputRegister * weightsRegister;
          bd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 3168];
          cd_outputRegister += inputRegister * weightsRegister;
          dd_outputRegister += b_inputRegister * weightsRegister;
          ed_outputRegister += c_inputRegister * weightsRegister;
          fd_outputRegister += d_inputRegister * weightsRegister;
          gd_outputRegister += e_inputRegister * weightsRegister;
          hd_outputRegister += f_inputRegister * weightsRegister;
          id_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 3456];
          jd_outputRegister += inputRegister * weightsRegister;
          kd_outputRegister += b_inputRegister * weightsRegister;
          ld_outputRegister += c_inputRegister * weightsRegister;
          md_outputRegister += d_inputRegister * weightsRegister;
          nd_outputRegister += e_inputRegister * weightsRegister;
          od_outputRegister += f_inputRegister * weightsRegister;
          pd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 3744];
          qd_outputRegister += inputRegister * weightsRegister;
          rd_outputRegister += b_inputRegister * weightsRegister;
          sd_outputRegister += c_inputRegister * weightsRegister;
          td_outputRegister += d_inputRegister * weightsRegister;
          ud_outputRegister += e_inputRegister * weightsRegister;
          vd_outputRegister += f_inputRegister * weightsRegister;
          wd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 4032];
          xd_outputRegister += inputRegister * weightsRegister;
          yd_outputRegister += b_inputRegister * weightsRegister;
          ae_outputRegister += c_inputRegister * weightsRegister;
          be_outputRegister += d_inputRegister * weightsRegister;
          ce_outputRegister += e_inputRegister * weightsRegister;
          de_outputRegister += f_inputRegister * weightsRegister;
          ee_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 4320];
          fe_outputRegister += inputRegister * weightsRegister;
          ge_outputRegister += b_inputRegister * weightsRegister;
          he_outputRegister += c_inputRegister * weightsRegister;
          ie_outputRegister += d_inputRegister * weightsRegister;
          je_outputRegister += e_inputRegister * weightsRegister;
          ke_outputRegister += f_inputRegister * weightsRegister;
          le_outputRegister += g_inputRegister * weightsRegister;
        }

        weightsIdx += 16;
        inputBufferIdx3 += 16;
      }

      inputBufferIdx2 += 256;
    }

    outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
    outputBufferPtr[outputRegister_tmp] = b_outputRegister;
    outputBufferPtr[b_outputRegister_tmp] = c_outputRegister;
    outputBufferPtr[c_outputRegister_tmp] = d_outputRegister;
    outputBufferPtr[d_outputRegister_tmp] = e_outputRegister;
    outputBufferPtr[e_outputRegister_tmp] = f_outputRegister;
    outputBufferPtr[f_outputRegister_tmp] = g_outputRegister;
    outputBufferPtr[g_outputRegister_tmp] = h_outputRegister;
    outputBufferPtr[h_outputRegister_tmp] = i_outputRegister;
    outputBufferPtr[i_outputRegister_tmp] = j_outputRegister;
    outputBufferPtr[j_outputRegister_tmp] = k_outputRegister;
    outputBufferPtr[k_outputRegister_tmp] = l_outputRegister;
    outputBufferPtr[l_outputRegister_tmp] = m_outputRegister;
    outputBufferPtr[m_outputRegister_tmp] = n_outputRegister;
    outputBufferPtr[n_outputRegister_tmp] = o_outputRegister;
    outputBufferPtr[o_outputRegister_tmp] = p_outputRegister;
    outputBufferPtr[p_outputRegister_tmp] = q_outputRegister;
    outputBufferPtr[q_outputRegister_tmp] = r_outputRegister;
    outputBufferPtr[r_outputRegister_tmp] = s_outputRegister;
    outputBufferPtr[s_outputRegister_tmp] = t_outputRegister;
    outputBufferPtr[t_outputRegister_tmp] = u_outputRegister;
    outputBufferPtr[u_outputRegister_tmp] = v_outputRegister;
    outputBufferPtr[v_outputRegister_tmp] = w_outputRegister;
    outputBufferPtr[w_outputRegister_tmp] = x_outputRegister;
    outputBufferPtr[x_outputRegister_tmp] = y_outputRegister;
    outputBufferPtr[y_outputRegister_tmp] = ab_outputRegister;
    outputBufferPtr[ab_outputRegister_tmp] = bb_outputRegister;
    outputBufferPtr[bb_outputRegister_tmp] = cb_outputRegister;
    outputBufferPtr[cb_outputRegister_tmp] = db_outputRegister;
    outputBufferPtr[db_outputRegister_tmp] = eb_outputRegister;
    outputBufferPtr[eb_outputRegister_tmp] = fb_outputRegister;
    outputBufferPtr[fb_outputRegister_tmp] = gb_outputRegister;
    outputBufferPtr[gb_outputRegister_tmp] = hb_outputRegister;
    outputBufferPtr[hb_outputRegister_tmp] = ib_outputRegister;
    outputBufferPtr[ib_outputRegister_tmp] = jb_outputRegister;
    outputBufferPtr[jb_outputRegister_tmp] = kb_outputRegister;
    outputBufferPtr[kb_outputRegister_tmp] = lb_outputRegister;
    outputBufferPtr[lb_outputRegister_tmp] = mb_outputRegister;
    outputBufferPtr[mb_outputRegister_tmp] = nb_outputRegister;
    outputBufferPtr[nb_outputRegister_tmp] = ob_outputRegister;
    outputBufferPtr[ob_outputRegister_tmp] = pb_outputRegister;
    outputBufferPtr[pb_outputRegister_tmp] = qb_outputRegister;
    outputBufferPtr[qb_outputRegister_tmp] = rb_outputRegister;
    outputBufferPtr[rb_outputRegister_tmp] = sb_outputRegister;
    outputBufferPtr[sb_outputRegister_tmp] = tb_outputRegister;
    outputBufferPtr[tb_outputRegister_tmp] = ub_outputRegister;
    outputBufferPtr[ub_outputRegister_tmp] = vb_outputRegister;
    outputBufferPtr[vb_outputRegister_tmp] = wb_outputRegister;
    outputBufferPtr[wb_outputRegister_tmp] = xb_outputRegister;
    outputBufferPtr[xb_outputRegister_tmp] = yb_outputRegister;
    outputBufferPtr[yb_outputRegister_tmp] = ac_outputRegister;
    outputBufferPtr[ac_outputRegister_tmp] = bc_outputRegister;
    outputBufferPtr[bc_outputRegister_tmp] = cc_outputRegister;
    outputBufferPtr[cc_outputRegister_tmp] = dc_outputRegister;
    outputBufferPtr[dc_outputRegister_tmp] = ec_outputRegister;
    outputBufferPtr[ec_outputRegister_tmp] = fc_outputRegister;
    outputBufferPtr[fc_outputRegister_tmp] = gc_outputRegister;
    outputBufferPtr[gc_outputRegister_tmp] = hc_outputRegister;
    outputBufferPtr[hc_outputRegister_tmp] = ic_outputRegister;
    outputBufferPtr[ic_outputRegister_tmp] = jc_outputRegister;
    outputBufferPtr[jc_outputRegister_tmp] = kc_outputRegister;
    outputBufferPtr[kc_outputRegister_tmp] = lc_outputRegister;
    outputBufferPtr[lc_outputRegister_tmp] = mc_outputRegister;
    outputBufferPtr[mc_outputRegister_tmp] = nc_outputRegister;
    outputBufferPtr[nc_outputRegister_tmp] = oc_outputRegister;
    outputBufferPtr[oc_outputRegister_tmp] = pc_outputRegister;
    outputBufferPtr[pc_outputRegister_tmp] = qc_outputRegister;
    outputBufferPtr[qc_outputRegister_tmp] = rc_outputRegister;
    outputBufferPtr[rc_outputRegister_tmp] = sc_outputRegister;
    outputBufferPtr[sc_outputRegister_tmp] = tc_outputRegister;
    outputBufferPtr[tc_outputRegister_tmp] = uc_outputRegister;
    outputBufferPtr[uc_outputRegister_tmp] = vc_outputRegister;
    outputBufferPtr[vc_outputRegister_tmp] = wc_outputRegister;
    outputBufferPtr[wc_outputRegister_tmp] = xc_outputRegister;
    outputBufferPtr[xc_outputRegister_tmp] = yc_outputRegister;
    outputBufferPtr[yc_outputRegister_tmp] = ad_outputRegister;
    outputBufferPtr[ad_outputRegister_tmp] = bd_outputRegister;
    outputBufferPtr[bd_outputRegister_tmp] = cd_outputRegister;
    outputBufferPtr[cd_outputRegister_tmp] = dd_outputRegister;
    outputBufferPtr[dd_outputRegister_tmp] = ed_outputRegister;
    outputBufferPtr[ed_outputRegister_tmp] = fd_outputRegister;
    outputBufferPtr[fd_outputRegister_tmp] = gd_outputRegister;
    outputBufferPtr[gd_outputRegister_tmp] = hd_outputRegister;
    outputBufferPtr[hd_outputRegister_tmp] = id_outputRegister;
    outputBufferPtr[id_outputRegister_tmp] = jd_outputRegister;
    outputBufferPtr[jd_outputRegister_tmp] = kd_outputRegister;
    outputBufferPtr[kd_outputRegister_tmp] = ld_outputRegister;
    outputBufferPtr[ld_outputRegister_tmp] = md_outputRegister;
    outputBufferPtr[md_outputRegister_tmp] = nd_outputRegister;
    outputBufferPtr[nd_outputRegister_tmp] = od_outputRegister;
    outputBufferPtr[od_outputRegister_tmp] = pd_outputRegister;
    outputBufferPtr[pd_outputRegister_tmp] = qd_outputRegister;
    outputBufferPtr[qd_outputRegister_tmp] = rd_outputRegister;
    outputBufferPtr[rd_outputRegister_tmp] = sd_outputRegister;
    outputBufferPtr[sd_outputRegister_tmp] = td_outputRegister;
    outputBufferPtr[td_outputRegister_tmp] = ud_outputRegister;
    outputBufferPtr[ud_outputRegister_tmp] = vd_outputRegister;
    outputBufferPtr[vd_outputRegister_tmp] = wd_outputRegister;
    outputBufferPtr[wd_outputRegister_tmp] = xd_outputRegister;
    outputBufferPtr[xd_outputRegister_tmp] = yd_outputRegister;
    outputBufferPtr[yd_outputRegister_tmp] = ae_outputRegister;
    outputBufferPtr[ae_outputRegister_tmp] = be_outputRegister;
    outputBufferPtr[be_outputRegister_tmp] = ce_outputRegister;
    outputBufferPtr[ce_outputRegister_tmp] = de_outputRegister;
    outputBufferPtr[de_outputRegister_tmp] = ee_outputRegister;
    outputBufferPtr[ee_outputRegister_tmp] = fe_outputRegister;
    outputBufferPtr[fe_outputRegister_tmp] = ge_outputRegister;
    outputBufferPtr[ge_outputRegister_tmp] = he_outputRegister;
    outputBufferPtr[he_outputRegister_tmp] = ie_outputRegister;
    outputBufferPtr[ie_outputRegister_tmp] = je_outputRegister;
    outputBufferPtr[je_outputRegister_tmp] = ke_outputRegister;
    outputBufferPtr[ke_outputRegister_tmp] = le_outputRegister;
    inputBufferIdx1 += 112;
  }
}

static void convolution(const float *inputTensor, float *outputTensor, const
  float *weights, const float *bias)
{
  static float outputBuffer[25088];
  static float inputBuffer[14400];
  static boolean_T bufferInitialized;
  float *elemRefOutputBufferVar;
  int bufferIdx2;
  int bufferIdx3;
  int inputIdx2;
  int inputIdx3;
  if (!bufferInitialized) {
    std::memset(&inputBuffer[0], 0, 57600U);
    bufferInitialized = true;
  }

  std::memset(&outputBuffer[0], 0, 100352U);
  bufferIdx2 = 496;
  inputIdx2 = 0;
  for (int inputWidthIdx{0}; inputWidthIdx < 28; inputWidthIdx++) {
    bufferIdx3 = bufferIdx2;
    inputIdx3 = inputIdx2;
    for (int inputHeightIdx{0}; inputHeightIdx < 28; inputHeightIdx++) {
      inputBuffer[bufferIdx3] = inputTensor[inputIdx3];
      bufferIdx3 += 16;
      inputIdx3++;
    }

    bufferIdx2 += 480;
    inputIdx2 += 28;
  }

  bufferIdx2 = 0;
  inputIdx2 = 0;
  for (int inputWidthIdx{0}; inputWidthIdx < 2; inputWidthIdx++) {
    bufferIdx3 = 0;
    inputIdx3 = inputIdx2;
    for (int inputHeightIdx{0}; inputHeightIdx < 28; inputHeightIdx++) {
      convolutionKernel(&inputBuffer[bufferIdx3], &outputBuffer[inputIdx3],
                        &weights[bufferIdx2]);
      bufferIdx3 += 480;
      inputIdx3 += 28;
    }

    bufferIdx2 += 2304;
    inputIdx2 += 12544;
  }

  bufferIdx2 = 0;
  inputIdx2 = 0;
  for (int inputWidthIdx{0}; inputWidthIdx < 32; inputWidthIdx++) {
    float biasRegister;
    biasRegister = bias[inputWidthIdx];
    bufferIdx3 = bufferIdx2;
    for (int inputHeightIdx{0}; inputHeightIdx < 784; inputHeightIdx++) {
      inputIdx3 = inputIdx2 + inputHeightIdx;
      elemRefOutputBufferVar = &outputBuffer[inputIdx3];
      *elemRefOutputBufferVar += biasRegister;
      outputTensor[bufferIdx3] = outputBuffer[inputIdx3];
      bufferIdx3++;
    }

    bufferIdx2 += 784;
    inputIdx2 += 784;
  }
}

static void convolutionKernel(const float *inputBufferPtr, float
  *outputBufferPtr, const float *weightsPtr)
{
  int inputBufferIdx1;
  inputBufferIdx1 = 0;
  for (int outputHeightBlockIdx{0}; outputHeightBlockIdx < 4;
       outputHeightBlockIdx++) {
    float ab_outputRegister;
    float ac_outputRegister;
    float ad_outputRegister;
    float ae_outputRegister;
    float b_outputRegister;
    float bb_outputRegister;
    float bc_outputRegister;
    float bd_outputRegister;
    float be_outputRegister;
    float c_outputRegister;
    float cb_outputRegister;
    float cc_outputRegister;
    float cd_outputRegister;
    float ce_outputRegister;
    float d_outputRegister;
    float db_outputRegister;
    float dc_outputRegister;
    float dd_outputRegister;
    float de_outputRegister;
    float e_outputRegister;
    float eb_outputRegister;
    float ec_outputRegister;
    float ed_outputRegister;
    float ee_outputRegister;
    float f_outputRegister;
    float fb_outputRegister;
    float fc_outputRegister;
    float fd_outputRegister;
    float fe_outputRegister;
    float g_outputRegister;
    float gb_outputRegister;
    float gc_outputRegister;
    float gd_outputRegister;
    float ge_outputRegister;
    float h_outputRegister;
    float hb_outputRegister;
    float hc_outputRegister;
    float hd_outputRegister;
    float he_outputRegister;
    float i_outputRegister;
    float ib_outputRegister;
    float ic_outputRegister;
    float id_outputRegister;
    float ie_outputRegister;
    float j_outputRegister;
    float jb_outputRegister;
    float jc_outputRegister;
    float jd_outputRegister;
    float je_outputRegister;
    float k_outputRegister;
    float kb_outputRegister;
    float kc_outputRegister;
    float kd_outputRegister;
    float ke_outputRegister;
    float l_outputRegister;
    float lb_outputRegister;
    float lc_outputRegister;
    float ld_outputRegister;
    float le_outputRegister;
    float m_outputRegister;
    float mb_outputRegister;
    float mc_outputRegister;
    float md_outputRegister;
    float n_outputRegister;
    float nb_outputRegister;
    float nc_outputRegister;
    float nd_outputRegister;
    float o_outputRegister;
    float ob_outputRegister;
    float oc_outputRegister;
    float od_outputRegister;
    float outputRegister;
    float p_outputRegister;
    float pb_outputRegister;
    float pc_outputRegister;
    float pd_outputRegister;
    float q_outputRegister;
    float qb_outputRegister;
    float qc_outputRegister;
    float qd_outputRegister;
    float r_outputRegister;
    float rb_outputRegister;
    float rc_outputRegister;
    float rd_outputRegister;
    float s_outputRegister;
    float sb_outputRegister;
    float sc_outputRegister;
    float sd_outputRegister;
    float t_outputRegister;
    float tb_outputRegister;
    float tc_outputRegister;
    float td_outputRegister;
    float u_outputRegister;
    float ub_outputRegister;
    float uc_outputRegister;
    float ud_outputRegister;
    float v_outputRegister;
    float vb_outputRegister;
    float vc_outputRegister;
    float vd_outputRegister;
    float w_outputRegister;
    float wb_outputRegister;
    float wc_outputRegister;
    float wd_outputRegister;
    float x_outputRegister;
    float xb_outputRegister;
    float xc_outputRegister;
    float xd_outputRegister;
    float y_outputRegister;
    float yb_outputRegister;
    float yc_outputRegister;
    float yd_outputRegister;
    int ab_outputRegister_tmp;
    int ac_outputRegister_tmp;
    int ad_outputRegister_tmp;
    int ae_outputRegister_tmp;
    int b_outputRegister_tmp;
    int bb_outputRegister_tmp;
    int bc_outputRegister_tmp;
    int bd_outputRegister_tmp;
    int be_outputRegister_tmp;
    int c_outputRegister_tmp;
    int cb_outputRegister_tmp;
    int cc_outputRegister_tmp;
    int cd_outputRegister_tmp;
    int ce_outputRegister_tmp;
    int d_outputRegister_tmp;
    int db_outputRegister_tmp;
    int dc_outputRegister_tmp;
    int dd_outputRegister_tmp;
    int de_outputRegister_tmp;
    int e_outputRegister_tmp;
    int eb_outputRegister_tmp;
    int ec_outputRegister_tmp;
    int ed_outputRegister_tmp;
    int ee_outputRegister_tmp;
    int f_outputRegister_tmp;
    int fb_outputRegister_tmp;
    int fc_outputRegister_tmp;
    int fd_outputRegister_tmp;
    int fe_outputRegister_tmp;
    int g_outputRegister_tmp;
    int gb_outputRegister_tmp;
    int gc_outputRegister_tmp;
    int gd_outputRegister_tmp;
    int ge_outputRegister_tmp;
    int h_outputRegister_tmp;
    int hb_outputRegister_tmp;
    int hc_outputRegister_tmp;
    int hd_outputRegister_tmp;
    int he_outputRegister_tmp;
    int i_outputRegister_tmp;
    int ib_outputRegister_tmp;
    int ic_outputRegister_tmp;
    int id_outputRegister_tmp;
    int ie_outputRegister_tmp;
    int inputBufferIdx2;
    int j_outputRegister_tmp;
    int jb_outputRegister_tmp;
    int jc_outputRegister_tmp;
    int jd_outputRegister_tmp;
    int je_outputRegister_tmp;
    int k_outputRegister_tmp;
    int kb_outputRegister_tmp;
    int kc_outputRegister_tmp;
    int kd_outputRegister_tmp;
    int ke_outputRegister_tmp;
    int l_outputRegister_tmp;
    int lb_outputRegister_tmp;
    int lc_outputRegister_tmp;
    int ld_outputRegister_tmp;
    int m_outputRegister_tmp;
    int mb_outputRegister_tmp;
    int mc_outputRegister_tmp;
    int md_outputRegister_tmp;
    int n_outputRegister_tmp;
    int nb_outputRegister_tmp;
    int nc_outputRegister_tmp;
    int nd_outputRegister_tmp;
    int o_outputRegister_tmp;
    int ob_outputRegister_tmp;
    int oc_outputRegister_tmp;
    int od_outputRegister_tmp;
    int outputRegister_tmp;
    int p_outputRegister_tmp;
    int pb_outputRegister_tmp;
    int pc_outputRegister_tmp;
    int pd_outputRegister_tmp;
    int q_outputRegister_tmp;
    int qb_outputRegister_tmp;
    int qc_outputRegister_tmp;
    int qd_outputRegister_tmp;
    int r_outputRegister_tmp;
    int rb_outputRegister_tmp;
    int rc_outputRegister_tmp;
    int rd_outputRegister_tmp;
    int s_outputRegister_tmp;
    int sb_outputRegister_tmp;
    int sc_outputRegister_tmp;
    int sd_outputRegister_tmp;
    int t_outputRegister_tmp;
    int tb_outputRegister_tmp;
    int tc_outputRegister_tmp;
    int td_outputRegister_tmp;
    int u_outputRegister_tmp;
    int ub_outputRegister_tmp;
    int uc_outputRegister_tmp;
    int ud_outputRegister_tmp;
    int v_outputRegister_tmp;
    int vb_outputRegister_tmp;
    int vc_outputRegister_tmp;
    int vd_outputRegister_tmp;
    int w_outputRegister_tmp;
    int wb_outputRegister_tmp;
    int wc_outputRegister_tmp;
    int wd_outputRegister_tmp;
    int weightsIdx;
    int x_outputRegister_tmp;
    int xb_outputRegister_tmp;
    int xc_outputRegister_tmp;
    int xd_outputRegister_tmp;
    int y_outputRegister_tmp;
    int yb_outputRegister_tmp;
    int yc_outputRegister_tmp;
    int yd_outputRegister_tmp;
    outputRegister = outputBufferPtr[outputHeightBlockIdx * 7];
    outputRegister_tmp = outputHeightBlockIdx * 7 + 1;
    b_outputRegister = outputBufferPtr[outputRegister_tmp];
    b_outputRegister_tmp = outputHeightBlockIdx * 7 + 2;
    c_outputRegister = outputBufferPtr[b_outputRegister_tmp];
    c_outputRegister_tmp = outputHeightBlockIdx * 7 + 3;
    d_outputRegister = outputBufferPtr[c_outputRegister_tmp];
    d_outputRegister_tmp = outputHeightBlockIdx * 7 + 4;
    e_outputRegister = outputBufferPtr[d_outputRegister_tmp];
    e_outputRegister_tmp = outputHeightBlockIdx * 7 + 5;
    f_outputRegister = outputBufferPtr[e_outputRegister_tmp];
    f_outputRegister_tmp = outputHeightBlockIdx * 7 + 6;
    g_outputRegister = outputBufferPtr[f_outputRegister_tmp];
    g_outputRegister_tmp = outputHeightBlockIdx * 7 + 784;
    h_outputRegister = outputBufferPtr[g_outputRegister_tmp];
    h_outputRegister_tmp = outputHeightBlockIdx * 7 + 785;
    i_outputRegister = outputBufferPtr[h_outputRegister_tmp];
    i_outputRegister_tmp = outputHeightBlockIdx * 7 + 786;
    j_outputRegister = outputBufferPtr[i_outputRegister_tmp];
    j_outputRegister_tmp = outputHeightBlockIdx * 7 + 787;
    k_outputRegister = outputBufferPtr[j_outputRegister_tmp];
    k_outputRegister_tmp = outputHeightBlockIdx * 7 + 788;
    l_outputRegister = outputBufferPtr[k_outputRegister_tmp];
    l_outputRegister_tmp = outputHeightBlockIdx * 7 + 789;
    m_outputRegister = outputBufferPtr[l_outputRegister_tmp];
    m_outputRegister_tmp = outputHeightBlockIdx * 7 + 790;
    n_outputRegister = outputBufferPtr[m_outputRegister_tmp];
    n_outputRegister_tmp = outputHeightBlockIdx * 7 + 1568;
    o_outputRegister = outputBufferPtr[n_outputRegister_tmp];
    o_outputRegister_tmp = outputHeightBlockIdx * 7 + 1569;
    p_outputRegister = outputBufferPtr[o_outputRegister_tmp];
    p_outputRegister_tmp = outputHeightBlockIdx * 7 + 1570;
    q_outputRegister = outputBufferPtr[p_outputRegister_tmp];
    q_outputRegister_tmp = outputHeightBlockIdx * 7 + 1571;
    r_outputRegister = outputBufferPtr[q_outputRegister_tmp];
    r_outputRegister_tmp = outputHeightBlockIdx * 7 + 1572;
    s_outputRegister = outputBufferPtr[r_outputRegister_tmp];
    s_outputRegister_tmp = outputHeightBlockIdx * 7 + 1573;
    t_outputRegister = outputBufferPtr[s_outputRegister_tmp];
    t_outputRegister_tmp = outputHeightBlockIdx * 7 + 1574;
    u_outputRegister = outputBufferPtr[t_outputRegister_tmp];
    u_outputRegister_tmp = outputHeightBlockIdx * 7 + 2352;
    v_outputRegister = outputBufferPtr[u_outputRegister_tmp];
    v_outputRegister_tmp = outputHeightBlockIdx * 7 + 2353;
    w_outputRegister = outputBufferPtr[v_outputRegister_tmp];
    w_outputRegister_tmp = outputHeightBlockIdx * 7 + 2354;
    x_outputRegister = outputBufferPtr[w_outputRegister_tmp];
    x_outputRegister_tmp = outputHeightBlockIdx * 7 + 2355;
    y_outputRegister = outputBufferPtr[x_outputRegister_tmp];
    y_outputRegister_tmp = outputHeightBlockIdx * 7 + 2356;
    ab_outputRegister = outputBufferPtr[y_outputRegister_tmp];
    ab_outputRegister_tmp = outputHeightBlockIdx * 7 + 2357;
    bb_outputRegister = outputBufferPtr[ab_outputRegister_tmp];
    bb_outputRegister_tmp = outputHeightBlockIdx * 7 + 2358;
    cb_outputRegister = outputBufferPtr[bb_outputRegister_tmp];
    cb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3136;
    db_outputRegister = outputBufferPtr[cb_outputRegister_tmp];
    db_outputRegister_tmp = outputHeightBlockIdx * 7 + 3137;
    eb_outputRegister = outputBufferPtr[db_outputRegister_tmp];
    eb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3138;
    fb_outputRegister = outputBufferPtr[eb_outputRegister_tmp];
    fb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3139;
    gb_outputRegister = outputBufferPtr[fb_outputRegister_tmp];
    gb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3140;
    hb_outputRegister = outputBufferPtr[gb_outputRegister_tmp];
    hb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3141;
    ib_outputRegister = outputBufferPtr[hb_outputRegister_tmp];
    ib_outputRegister_tmp = outputHeightBlockIdx * 7 + 3142;
    jb_outputRegister = outputBufferPtr[ib_outputRegister_tmp];
    jb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3920;
    kb_outputRegister = outputBufferPtr[jb_outputRegister_tmp];
    kb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3921;
    lb_outputRegister = outputBufferPtr[kb_outputRegister_tmp];
    lb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3922;
    mb_outputRegister = outputBufferPtr[lb_outputRegister_tmp];
    mb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3923;
    nb_outputRegister = outputBufferPtr[mb_outputRegister_tmp];
    nb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3924;
    ob_outputRegister = outputBufferPtr[nb_outputRegister_tmp];
    ob_outputRegister_tmp = outputHeightBlockIdx * 7 + 3925;
    pb_outputRegister = outputBufferPtr[ob_outputRegister_tmp];
    pb_outputRegister_tmp = outputHeightBlockIdx * 7 + 3926;
    qb_outputRegister = outputBufferPtr[pb_outputRegister_tmp];
    qb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4704;
    rb_outputRegister = outputBufferPtr[qb_outputRegister_tmp];
    rb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4705;
    sb_outputRegister = outputBufferPtr[rb_outputRegister_tmp];
    sb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4706;
    tb_outputRegister = outputBufferPtr[sb_outputRegister_tmp];
    tb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4707;
    ub_outputRegister = outputBufferPtr[tb_outputRegister_tmp];
    ub_outputRegister_tmp = outputHeightBlockIdx * 7 + 4708;
    vb_outputRegister = outputBufferPtr[ub_outputRegister_tmp];
    vb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4709;
    wb_outputRegister = outputBufferPtr[vb_outputRegister_tmp];
    wb_outputRegister_tmp = outputHeightBlockIdx * 7 + 4710;
    xb_outputRegister = outputBufferPtr[wb_outputRegister_tmp];
    xb_outputRegister_tmp = outputHeightBlockIdx * 7 + 5488;
    yb_outputRegister = outputBufferPtr[xb_outputRegister_tmp];
    yb_outputRegister_tmp = outputHeightBlockIdx * 7 + 5489;
    ac_outputRegister = outputBufferPtr[yb_outputRegister_tmp];
    ac_outputRegister_tmp = outputHeightBlockIdx * 7 + 5490;
    bc_outputRegister = outputBufferPtr[ac_outputRegister_tmp];
    bc_outputRegister_tmp = outputHeightBlockIdx * 7 + 5491;
    cc_outputRegister = outputBufferPtr[bc_outputRegister_tmp];
    cc_outputRegister_tmp = outputHeightBlockIdx * 7 + 5492;
    dc_outputRegister = outputBufferPtr[cc_outputRegister_tmp];
    dc_outputRegister_tmp = outputHeightBlockIdx * 7 + 5493;
    ec_outputRegister = outputBufferPtr[dc_outputRegister_tmp];
    ec_outputRegister_tmp = outputHeightBlockIdx * 7 + 5494;
    fc_outputRegister = outputBufferPtr[ec_outputRegister_tmp];
    fc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6272;
    gc_outputRegister = outputBufferPtr[fc_outputRegister_tmp];
    gc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6273;
    hc_outputRegister = outputBufferPtr[gc_outputRegister_tmp];
    hc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6274;
    ic_outputRegister = outputBufferPtr[hc_outputRegister_tmp];
    ic_outputRegister_tmp = outputHeightBlockIdx * 7 + 6275;
    jc_outputRegister = outputBufferPtr[ic_outputRegister_tmp];
    jc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6276;
    kc_outputRegister = outputBufferPtr[jc_outputRegister_tmp];
    kc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6277;
    lc_outputRegister = outputBufferPtr[kc_outputRegister_tmp];
    lc_outputRegister_tmp = outputHeightBlockIdx * 7 + 6278;
    mc_outputRegister = outputBufferPtr[lc_outputRegister_tmp];
    mc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7056;
    nc_outputRegister = outputBufferPtr[mc_outputRegister_tmp];
    nc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7057;
    oc_outputRegister = outputBufferPtr[nc_outputRegister_tmp];
    oc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7058;
    pc_outputRegister = outputBufferPtr[oc_outputRegister_tmp];
    pc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7059;
    qc_outputRegister = outputBufferPtr[pc_outputRegister_tmp];
    qc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7060;
    rc_outputRegister = outputBufferPtr[qc_outputRegister_tmp];
    rc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7061;
    sc_outputRegister = outputBufferPtr[rc_outputRegister_tmp];
    sc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7062;
    tc_outputRegister = outputBufferPtr[sc_outputRegister_tmp];
    tc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7840;
    uc_outputRegister = outputBufferPtr[tc_outputRegister_tmp];
    uc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7841;
    vc_outputRegister = outputBufferPtr[uc_outputRegister_tmp];
    vc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7842;
    wc_outputRegister = outputBufferPtr[vc_outputRegister_tmp];
    wc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7843;
    xc_outputRegister = outputBufferPtr[wc_outputRegister_tmp];
    xc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7844;
    yc_outputRegister = outputBufferPtr[xc_outputRegister_tmp];
    yc_outputRegister_tmp = outputHeightBlockIdx * 7 + 7845;
    ad_outputRegister = outputBufferPtr[yc_outputRegister_tmp];
    ad_outputRegister_tmp = outputHeightBlockIdx * 7 + 7846;
    bd_outputRegister = outputBufferPtr[ad_outputRegister_tmp];
    bd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8624;
    cd_outputRegister = outputBufferPtr[bd_outputRegister_tmp];
    cd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8625;
    dd_outputRegister = outputBufferPtr[cd_outputRegister_tmp];
    dd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8626;
    ed_outputRegister = outputBufferPtr[dd_outputRegister_tmp];
    ed_outputRegister_tmp = outputHeightBlockIdx * 7 + 8627;
    fd_outputRegister = outputBufferPtr[ed_outputRegister_tmp];
    fd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8628;
    gd_outputRegister = outputBufferPtr[fd_outputRegister_tmp];
    gd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8629;
    hd_outputRegister = outputBufferPtr[gd_outputRegister_tmp];
    hd_outputRegister_tmp = outputHeightBlockIdx * 7 + 8630;
    id_outputRegister = outputBufferPtr[hd_outputRegister_tmp];
    id_outputRegister_tmp = outputHeightBlockIdx * 7 + 9408;
    jd_outputRegister = outputBufferPtr[id_outputRegister_tmp];
    jd_outputRegister_tmp = outputHeightBlockIdx * 7 + 9409;
    kd_outputRegister = outputBufferPtr[jd_outputRegister_tmp];
    kd_outputRegister_tmp = outputHeightBlockIdx * 7 + 9410;
    ld_outputRegister = outputBufferPtr[kd_outputRegister_tmp];
    ld_outputRegister_tmp = outputHeightBlockIdx * 7 + 9411;
    md_outputRegister = outputBufferPtr[ld_outputRegister_tmp];
    md_outputRegister_tmp = outputHeightBlockIdx * 7 + 9412;
    nd_outputRegister = outputBufferPtr[md_outputRegister_tmp];
    nd_outputRegister_tmp = outputHeightBlockIdx * 7 + 9413;
    od_outputRegister = outputBufferPtr[nd_outputRegister_tmp];
    od_outputRegister_tmp = outputHeightBlockIdx * 7 + 9414;
    pd_outputRegister = outputBufferPtr[od_outputRegister_tmp];
    pd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10192;
    qd_outputRegister = outputBufferPtr[pd_outputRegister_tmp];
    qd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10193;
    rd_outputRegister = outputBufferPtr[qd_outputRegister_tmp];
    rd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10194;
    sd_outputRegister = outputBufferPtr[rd_outputRegister_tmp];
    sd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10195;
    td_outputRegister = outputBufferPtr[sd_outputRegister_tmp];
    td_outputRegister_tmp = outputHeightBlockIdx * 7 + 10196;
    ud_outputRegister = outputBufferPtr[td_outputRegister_tmp];
    ud_outputRegister_tmp = outputHeightBlockIdx * 7 + 10197;
    vd_outputRegister = outputBufferPtr[ud_outputRegister_tmp];
    vd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10198;
    wd_outputRegister = outputBufferPtr[vd_outputRegister_tmp];
    wd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10976;
    xd_outputRegister = outputBufferPtr[wd_outputRegister_tmp];
    xd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10977;
    yd_outputRegister = outputBufferPtr[xd_outputRegister_tmp];
    yd_outputRegister_tmp = outputHeightBlockIdx * 7 + 10978;
    ae_outputRegister = outputBufferPtr[yd_outputRegister_tmp];
    ae_outputRegister_tmp = outputHeightBlockIdx * 7 + 10979;
    be_outputRegister = outputBufferPtr[ae_outputRegister_tmp];
    be_outputRegister_tmp = outputHeightBlockIdx * 7 + 10980;
    ce_outputRegister = outputBufferPtr[be_outputRegister_tmp];
    ce_outputRegister_tmp = outputHeightBlockIdx * 7 + 10981;
    de_outputRegister = outputBufferPtr[ce_outputRegister_tmp];
    de_outputRegister_tmp = outputHeightBlockIdx * 7 + 10982;
    ee_outputRegister = outputBufferPtr[de_outputRegister_tmp];
    ee_outputRegister_tmp = outputHeightBlockIdx * 7 + 11760;
    fe_outputRegister = outputBufferPtr[ee_outputRegister_tmp];
    fe_outputRegister_tmp = outputHeightBlockIdx * 7 + 11761;
    ge_outputRegister = outputBufferPtr[fe_outputRegister_tmp];
    ge_outputRegister_tmp = outputHeightBlockIdx * 7 + 11762;
    he_outputRegister = outputBufferPtr[ge_outputRegister_tmp];
    he_outputRegister_tmp = outputHeightBlockIdx * 7 + 11763;
    ie_outputRegister = outputBufferPtr[he_outputRegister_tmp];
    ie_outputRegister_tmp = outputHeightBlockIdx * 7 + 11764;
    je_outputRegister = outputBufferPtr[ie_outputRegister_tmp];
    je_outputRegister_tmp = outputHeightBlockIdx * 7 + 11765;
    ke_outputRegister = outputBufferPtr[je_outputRegister_tmp];
    ke_outputRegister_tmp = outputHeightBlockIdx * 7 + 11766;
    le_outputRegister = outputBufferPtr[ke_outputRegister_tmp];
    inputBufferIdx2 = inputBufferIdx1;
    weightsIdx = 0;
    for (int kernelWidthIdx{0}; kernelWidthIdx < 3; kernelWidthIdx++) {
      int inputBufferIdx3;
      inputBufferIdx3 = inputBufferIdx2;
      for (int kernelHeightIdx{0}; kernelHeightIdx < 3; kernelHeightIdx++) {
        for (int inputChannelIdx{0}; inputChannelIdx < 16; inputChannelIdx++) {
          float b_inputRegister;
          float c_inputRegister;
          float d_inputRegister;
          float e_inputRegister;
          float f_inputRegister;
          float g_inputRegister;
          float inputRegister;
          float weightsRegister;
          int inputRegister_tmp;
          inputRegister_tmp = inputBufferIdx3 + inputChannelIdx;
          inputRegister = inputBufferPtr[inputRegister_tmp];
          b_inputRegister = inputBufferPtr[inputRegister_tmp + 16];
          c_inputRegister = inputBufferPtr[inputRegister_tmp + 32];
          d_inputRegister = inputBufferPtr[inputRegister_tmp + 48];
          e_inputRegister = inputBufferPtr[inputRegister_tmp + 64];
          f_inputRegister = inputBufferPtr[inputRegister_tmp + 80];
          g_inputRegister = inputBufferPtr[inputRegister_tmp + 96];
          inputRegister_tmp = weightsIdx + inputChannelIdx;
          weightsRegister = weightsPtr[inputRegister_tmp];
          outputRegister += inputRegister * weightsRegister;
          b_outputRegister += b_inputRegister * weightsRegister;
          c_outputRegister += c_inputRegister * weightsRegister;
          d_outputRegister += d_inputRegister * weightsRegister;
          e_outputRegister += e_inputRegister * weightsRegister;
          f_outputRegister += f_inputRegister * weightsRegister;
          g_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 144];
          h_outputRegister += inputRegister * weightsRegister;
          i_outputRegister += b_inputRegister * weightsRegister;
          j_outputRegister += c_inputRegister * weightsRegister;
          k_outputRegister += d_inputRegister * weightsRegister;
          l_outputRegister += e_inputRegister * weightsRegister;
          m_outputRegister += f_inputRegister * weightsRegister;
          n_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 288];
          o_outputRegister += inputRegister * weightsRegister;
          p_outputRegister += b_inputRegister * weightsRegister;
          q_outputRegister += c_inputRegister * weightsRegister;
          r_outputRegister += d_inputRegister * weightsRegister;
          s_outputRegister += e_inputRegister * weightsRegister;
          t_outputRegister += f_inputRegister * weightsRegister;
          u_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 432];
          v_outputRegister += inputRegister * weightsRegister;
          w_outputRegister += b_inputRegister * weightsRegister;
          x_outputRegister += c_inputRegister * weightsRegister;
          y_outputRegister += d_inputRegister * weightsRegister;
          ab_outputRegister += e_inputRegister * weightsRegister;
          bb_outputRegister += f_inputRegister * weightsRegister;
          cb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 576];
          db_outputRegister += inputRegister * weightsRegister;
          eb_outputRegister += b_inputRegister * weightsRegister;
          fb_outputRegister += c_inputRegister * weightsRegister;
          gb_outputRegister += d_inputRegister * weightsRegister;
          hb_outputRegister += e_inputRegister * weightsRegister;
          ib_outputRegister += f_inputRegister * weightsRegister;
          jb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 720];
          kb_outputRegister += inputRegister * weightsRegister;
          lb_outputRegister += b_inputRegister * weightsRegister;
          mb_outputRegister += c_inputRegister * weightsRegister;
          nb_outputRegister += d_inputRegister * weightsRegister;
          ob_outputRegister += e_inputRegister * weightsRegister;
          pb_outputRegister += f_inputRegister * weightsRegister;
          qb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 864];
          rb_outputRegister += inputRegister * weightsRegister;
          sb_outputRegister += b_inputRegister * weightsRegister;
          tb_outputRegister += c_inputRegister * weightsRegister;
          ub_outputRegister += d_inputRegister * weightsRegister;
          vb_outputRegister += e_inputRegister * weightsRegister;
          wb_outputRegister += f_inputRegister * weightsRegister;
          xb_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1008];
          yb_outputRegister += inputRegister * weightsRegister;
          ac_outputRegister += b_inputRegister * weightsRegister;
          bc_outputRegister += c_inputRegister * weightsRegister;
          cc_outputRegister += d_inputRegister * weightsRegister;
          dc_outputRegister += e_inputRegister * weightsRegister;
          ec_outputRegister += f_inputRegister * weightsRegister;
          fc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1152];
          gc_outputRegister += inputRegister * weightsRegister;
          hc_outputRegister += b_inputRegister * weightsRegister;
          ic_outputRegister += c_inputRegister * weightsRegister;
          jc_outputRegister += d_inputRegister * weightsRegister;
          kc_outputRegister += e_inputRegister * weightsRegister;
          lc_outputRegister += f_inputRegister * weightsRegister;
          mc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1296];
          nc_outputRegister += inputRegister * weightsRegister;
          oc_outputRegister += b_inputRegister * weightsRegister;
          pc_outputRegister += c_inputRegister * weightsRegister;
          qc_outputRegister += d_inputRegister * weightsRegister;
          rc_outputRegister += e_inputRegister * weightsRegister;
          sc_outputRegister += f_inputRegister * weightsRegister;
          tc_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1440];
          uc_outputRegister += inputRegister * weightsRegister;
          vc_outputRegister += b_inputRegister * weightsRegister;
          wc_outputRegister += c_inputRegister * weightsRegister;
          xc_outputRegister += d_inputRegister * weightsRegister;
          yc_outputRegister += e_inputRegister * weightsRegister;
          ad_outputRegister += f_inputRegister * weightsRegister;
          bd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1584];
          cd_outputRegister += inputRegister * weightsRegister;
          dd_outputRegister += b_inputRegister * weightsRegister;
          ed_outputRegister += c_inputRegister * weightsRegister;
          fd_outputRegister += d_inputRegister * weightsRegister;
          gd_outputRegister += e_inputRegister * weightsRegister;
          hd_outputRegister += f_inputRegister * weightsRegister;
          id_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1728];
          jd_outputRegister += inputRegister * weightsRegister;
          kd_outputRegister += b_inputRegister * weightsRegister;
          ld_outputRegister += c_inputRegister * weightsRegister;
          md_outputRegister += d_inputRegister * weightsRegister;
          nd_outputRegister += e_inputRegister * weightsRegister;
          od_outputRegister += f_inputRegister * weightsRegister;
          pd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 1872];
          qd_outputRegister += inputRegister * weightsRegister;
          rd_outputRegister += b_inputRegister * weightsRegister;
          sd_outputRegister += c_inputRegister * weightsRegister;
          td_outputRegister += d_inputRegister * weightsRegister;
          ud_outputRegister += e_inputRegister * weightsRegister;
          vd_outputRegister += f_inputRegister * weightsRegister;
          wd_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2016];
          xd_outputRegister += inputRegister * weightsRegister;
          yd_outputRegister += b_inputRegister * weightsRegister;
          ae_outputRegister += c_inputRegister * weightsRegister;
          be_outputRegister += d_inputRegister * weightsRegister;
          ce_outputRegister += e_inputRegister * weightsRegister;
          de_outputRegister += f_inputRegister * weightsRegister;
          ee_outputRegister += g_inputRegister * weightsRegister;
          weightsRegister = weightsPtr[inputRegister_tmp + 2160];
          fe_outputRegister += inputRegister * weightsRegister;
          ge_outputRegister += b_inputRegister * weightsRegister;
          he_outputRegister += c_inputRegister * weightsRegister;
          ie_outputRegister += d_inputRegister * weightsRegister;
          je_outputRegister += e_inputRegister * weightsRegister;
          ke_outputRegister += f_inputRegister * weightsRegister;
          le_outputRegister += g_inputRegister * weightsRegister;
        }

        weightsIdx += 16;
        inputBufferIdx3 += 16;
      }

      inputBufferIdx2 += 480;
    }

    outputBufferPtr[outputHeightBlockIdx * 7] = outputRegister;
    outputBufferPtr[outputRegister_tmp] = b_outputRegister;
    outputBufferPtr[b_outputRegister_tmp] = c_outputRegister;
    outputBufferPtr[c_outputRegister_tmp] = d_outputRegister;
    outputBufferPtr[d_outputRegister_tmp] = e_outputRegister;
    outputBufferPtr[e_outputRegister_tmp] = f_outputRegister;
    outputBufferPtr[f_outputRegister_tmp] = g_outputRegister;
    outputBufferPtr[g_outputRegister_tmp] = h_outputRegister;
    outputBufferPtr[h_outputRegister_tmp] = i_outputRegister;
    outputBufferPtr[i_outputRegister_tmp] = j_outputRegister;
    outputBufferPtr[j_outputRegister_tmp] = k_outputRegister;
    outputBufferPtr[k_outputRegister_tmp] = l_outputRegister;
    outputBufferPtr[l_outputRegister_tmp] = m_outputRegister;
    outputBufferPtr[m_outputRegister_tmp] = n_outputRegister;
    outputBufferPtr[n_outputRegister_tmp] = o_outputRegister;
    outputBufferPtr[o_outputRegister_tmp] = p_outputRegister;
    outputBufferPtr[p_outputRegister_tmp] = q_outputRegister;
    outputBufferPtr[q_outputRegister_tmp] = r_outputRegister;
    outputBufferPtr[r_outputRegister_tmp] = s_outputRegister;
    outputBufferPtr[s_outputRegister_tmp] = t_outputRegister;
    outputBufferPtr[t_outputRegister_tmp] = u_outputRegister;
    outputBufferPtr[u_outputRegister_tmp] = v_outputRegister;
    outputBufferPtr[v_outputRegister_tmp] = w_outputRegister;
    outputBufferPtr[w_outputRegister_tmp] = x_outputRegister;
    outputBufferPtr[x_outputRegister_tmp] = y_outputRegister;
    outputBufferPtr[y_outputRegister_tmp] = ab_outputRegister;
    outputBufferPtr[ab_outputRegister_tmp] = bb_outputRegister;
    outputBufferPtr[bb_outputRegister_tmp] = cb_outputRegister;
    outputBufferPtr[cb_outputRegister_tmp] = db_outputRegister;
    outputBufferPtr[db_outputRegister_tmp] = eb_outputRegister;
    outputBufferPtr[eb_outputRegister_tmp] = fb_outputRegister;
    outputBufferPtr[fb_outputRegister_tmp] = gb_outputRegister;
    outputBufferPtr[gb_outputRegister_tmp] = hb_outputRegister;
    outputBufferPtr[hb_outputRegister_tmp] = ib_outputRegister;
    outputBufferPtr[ib_outputRegister_tmp] = jb_outputRegister;
    outputBufferPtr[jb_outputRegister_tmp] = kb_outputRegister;
    outputBufferPtr[kb_outputRegister_tmp] = lb_outputRegister;
    outputBufferPtr[lb_outputRegister_tmp] = mb_outputRegister;
    outputBufferPtr[mb_outputRegister_tmp] = nb_outputRegister;
    outputBufferPtr[nb_outputRegister_tmp] = ob_outputRegister;
    outputBufferPtr[ob_outputRegister_tmp] = pb_outputRegister;
    outputBufferPtr[pb_outputRegister_tmp] = qb_outputRegister;
    outputBufferPtr[qb_outputRegister_tmp] = rb_outputRegister;
    outputBufferPtr[rb_outputRegister_tmp] = sb_outputRegister;
    outputBufferPtr[sb_outputRegister_tmp] = tb_outputRegister;
    outputBufferPtr[tb_outputRegister_tmp] = ub_outputRegister;
    outputBufferPtr[ub_outputRegister_tmp] = vb_outputRegister;
    outputBufferPtr[vb_outputRegister_tmp] = wb_outputRegister;
    outputBufferPtr[wb_outputRegister_tmp] = xb_outputRegister;
    outputBufferPtr[xb_outputRegister_tmp] = yb_outputRegister;
    outputBufferPtr[yb_outputRegister_tmp] = ac_outputRegister;
    outputBufferPtr[ac_outputRegister_tmp] = bc_outputRegister;
    outputBufferPtr[bc_outputRegister_tmp] = cc_outputRegister;
    outputBufferPtr[cc_outputRegister_tmp] = dc_outputRegister;
    outputBufferPtr[dc_outputRegister_tmp] = ec_outputRegister;
    outputBufferPtr[ec_outputRegister_tmp] = fc_outputRegister;
    outputBufferPtr[fc_outputRegister_tmp] = gc_outputRegister;
    outputBufferPtr[gc_outputRegister_tmp] = hc_outputRegister;
    outputBufferPtr[hc_outputRegister_tmp] = ic_outputRegister;
    outputBufferPtr[ic_outputRegister_tmp] = jc_outputRegister;
    outputBufferPtr[jc_outputRegister_tmp] = kc_outputRegister;
    outputBufferPtr[kc_outputRegister_tmp] = lc_outputRegister;
    outputBufferPtr[lc_outputRegister_tmp] = mc_outputRegister;
    outputBufferPtr[mc_outputRegister_tmp] = nc_outputRegister;
    outputBufferPtr[nc_outputRegister_tmp] = oc_outputRegister;
    outputBufferPtr[oc_outputRegister_tmp] = pc_outputRegister;
    outputBufferPtr[pc_outputRegister_tmp] = qc_outputRegister;
    outputBufferPtr[qc_outputRegister_tmp] = rc_outputRegister;
    outputBufferPtr[rc_outputRegister_tmp] = sc_outputRegister;
    outputBufferPtr[sc_outputRegister_tmp] = tc_outputRegister;
    outputBufferPtr[tc_outputRegister_tmp] = uc_outputRegister;
    outputBufferPtr[uc_outputRegister_tmp] = vc_outputRegister;
    outputBufferPtr[vc_outputRegister_tmp] = wc_outputRegister;
    outputBufferPtr[wc_outputRegister_tmp] = xc_outputRegister;
    outputBufferPtr[xc_outputRegister_tmp] = yc_outputRegister;
    outputBufferPtr[yc_outputRegister_tmp] = ad_outputRegister;
    outputBufferPtr[ad_outputRegister_tmp] = bd_outputRegister;
    outputBufferPtr[bd_outputRegister_tmp] = cd_outputRegister;
    outputBufferPtr[cd_outputRegister_tmp] = dd_outputRegister;
    outputBufferPtr[dd_outputRegister_tmp] = ed_outputRegister;
    outputBufferPtr[ed_outputRegister_tmp] = fd_outputRegister;
    outputBufferPtr[fd_outputRegister_tmp] = gd_outputRegister;
    outputBufferPtr[gd_outputRegister_tmp] = hd_outputRegister;
    outputBufferPtr[hd_outputRegister_tmp] = id_outputRegister;
    outputBufferPtr[id_outputRegister_tmp] = jd_outputRegister;
    outputBufferPtr[jd_outputRegister_tmp] = kd_outputRegister;
    outputBufferPtr[kd_outputRegister_tmp] = ld_outputRegister;
    outputBufferPtr[ld_outputRegister_tmp] = md_outputRegister;
    outputBufferPtr[md_outputRegister_tmp] = nd_outputRegister;
    outputBufferPtr[nd_outputRegister_tmp] = od_outputRegister;
    outputBufferPtr[od_outputRegister_tmp] = pd_outputRegister;
    outputBufferPtr[pd_outputRegister_tmp] = qd_outputRegister;
    outputBufferPtr[qd_outputRegister_tmp] = rd_outputRegister;
    outputBufferPtr[rd_outputRegister_tmp] = sd_outputRegister;
    outputBufferPtr[sd_outputRegister_tmp] = td_outputRegister;
    outputBufferPtr[td_outputRegister_tmp] = ud_outputRegister;
    outputBufferPtr[ud_outputRegister_tmp] = vd_outputRegister;
    outputBufferPtr[vd_outputRegister_tmp] = wd_outputRegister;
    outputBufferPtr[wd_outputRegister_tmp] = xd_outputRegister;
    outputBufferPtr[xd_outputRegister_tmp] = yd_outputRegister;
    outputBufferPtr[yd_outputRegister_tmp] = ae_outputRegister;
    outputBufferPtr[ae_outputRegister_tmp] = be_outputRegister;
    outputBufferPtr[be_outputRegister_tmp] = ce_outputRegister;
    outputBufferPtr[ce_outputRegister_tmp] = de_outputRegister;
    outputBufferPtr[de_outputRegister_tmp] = ee_outputRegister;
    outputBufferPtr[ee_outputRegister_tmp] = fe_outputRegister;
    outputBufferPtr[fe_outputRegister_tmp] = ge_outputRegister;
    outputBufferPtr[ge_outputRegister_tmp] = he_outputRegister;
    outputBufferPtr[he_outputRegister_tmp] = ie_outputRegister;
    outputBufferPtr[ie_outputRegister_tmp] = je_outputRegister;
    outputBufferPtr[je_outputRegister_tmp] = ke_outputRegister;
    outputBufferPtr[ke_outputRegister_tmp] = le_outputRegister;
    inputBufferIdx1 += 112;
  }
}

namespace coder
{
  namespace layer
  {
    void b_conv2dDirectOptimizedColMajor(const float X[6272], float Z[12544])
    {
      static const float weights2[18432]{ 0.0139928646F, -0.0971087217F,
        -0.0176945515F, 0.00420112954F, -0.0281408802F, 0.0513152033F,
        -0.00914214086F, -0.0108570736F, -0.0469993763F, 0.0540165044F,
        0.0258195028F, 0.00554052228F, 0.143420443F, -0.0571867749F,
        0.0928963795F, 0.0758009255F, -0.0265332051F, -0.0601552948F,
        -0.0137366243F, 0.0614525266F, 0.111250132F, -0.0912750736F,
        -0.00969569106F, 0.0905200616F, 0.0520720631F, -0.0104733063F,
        0.0585018508F, -0.0244896933F, 0.027805604F, -0.0418923534F,
        0.0346650556F, -0.0921911225F, -0.0274181198F, -0.0891123265F,
        -0.029270675F, 0.0507002659F, 0.103379071F, 0.0801240727F, -0.128718674F,
        -0.0206677932F, -0.0695890188F, -0.0427769385F, -0.0925886407F,
        0.00320581067F, 0.035116341F, 0.0405295566F, 0.0578582361F,
        -0.105511524F, 0.0894444287F, 0.0349081941F, 0.0415217802F,
        0.0449308418F, 0.0367935523F, 0.0198957678F, 0.0723482668F,
        -0.0525186881F, -0.0669819117F, -0.0481108278F, 0.0446662046F,
        -0.0794838518F, 0.0128056202F, 0.0793472752F, -0.0599126145F,
        -0.0627983734F, -0.0885558277F, -0.0109173637F, -0.0838708729F,
        -0.0445751064F, 0.04536248F, 0.0485996529F, 0.0200622734F, 0.0587461367F,
        -0.00233387435F, -0.0112253986F, -0.0219726264F, -0.0231084339F,
        -0.0358638838F, 0.0213086624F, 0.0972600058F, -0.0129769761F,
        0.0177579075F, -0.00863619149F, -0.00655363873F, -0.00771255419F,
        0.00817091F, 0.0353638642F, -0.0473625623F, 0.0262949187F,
        -0.0451769419F, 0.053826604F, 0.0354490653F, 0.0121544991F,
        0.0534120277F, 0.0540312864F, 0.0827005729F, 0.0567016751F,
        -0.0690110922F, 0.0263111088F, -0.0801557228F, -0.0293363575F,
        0.0340719558F, -0.00915326F, -0.081886F, -0.0920131281F, -0.0953673199F,
        -0.0243003163F, 0.00136690296F, 0.0549399033F, -0.034667816F,
        0.0582897961F, -0.0501172F, -0.116054468F, -0.0281866826F, 0.0451662056F,
        -0.086695224F, 0.0451847501F, 0.0444899909F, 0.00522791594F,
        -0.0702765509F, 0.0524807274F, -0.0736341625F, 0.0441474058F,
        -0.00237376522F, -0.0565801337F, -0.0133648235F, -0.0549255759F,
        0.0706542581F, -0.0212919805F, -0.0333973877F, 0.0138539523F,
        -0.0213006884F, -0.0725350901F, 0.0963716F, -0.0128825679F,
        -0.0135338521F, 0.043227382F, 0.0314512737F, -0.0420440137F,
        0.00762227876F, -0.0456325226F, 0.0364081413F, -0.0688375384F,
        -0.123847991F, 0.030746432F, 0.0313251317F, 0.05832709F, -0.00253715599F,
        0.110698357F, 0.0204051509F, -0.0330860429F, -0.0954811871F,
        -0.00424585026F, -0.0423691496F, 0.101577565F, -0.00964454748F,
        0.0940516442F, -0.00369057013F, 0.0937308744F, -0.0264447462F,
        0.061862573F, 0.0259782467F, -0.058010973F, -0.0540685542F,
        -0.000456144713F, -0.0623975508F, -0.045522403F, -0.0280493442F,
        0.130533099F, 0.0262523405F, -0.0121099465F, 0.0388504602F,
        -0.0169727094F, 0.0354105718F, -0.0326105468F, 0.0480862968F,
        0.0474805683F, -0.0107509438F, -0.0766700432F, 0.0161329769F,
        0.0530831255F, -0.118507549F, 0.0823281556F, -0.103553146F,
        -0.0315735824F, -0.0559232831F, 0.0651772F, 0.0372335911F, 0.0460296534F,
        -0.0067624473F, 0.028975999F, 0.072871238F, 0.0458409265F, 0.139436454F,
        0.0977144837F, 0.082877934F, 0.0333027467F, -0.00782455F, -0.028268693F,
        -0.0321789198F, -0.0408039615F, -0.0706039071F, 0.0203552134F,
        0.0916124284F, 0.0916147083F, -0.012834101F, -0.0248463843F,
        0.0111587336F, 0.0697601363F, 0.00880245678F, -0.0565527081F,
        0.0316124894F, -0.017608434F, -0.0289538465F, 0.0163690653F,
        0.0535324924F, -0.0173566863F, -0.0348952897F, 0.113322057F,
        -0.0143165318F, -0.00416975282F, 0.0774258152F, 0.00576902647F,
        -0.0178974066F, -0.0809389129F, -0.024412496F, 0.0149600524F,
        0.0820313767F, 0.0547328368F, -0.0689641535F, -0.091753684F,
        -0.0967152417F, -0.0744966641F, 0.0573181F, 0.097272113F, 0.0327780433F,
        0.101118699F, -0.0640673041F, -0.068292886F, -0.0236264784F,
        0.0600003824F, 0.0767874122F, -0.0123149566F, -0.0824665502F,
        0.0424911156F, -0.118023537F, -0.00798986666F, -0.0219807867F,
        -0.0415348299F, 0.00136804604F, 0.0373136327F, 0.0715996549F,
        -0.0382494889F, -0.0211177468F, -0.0980057791F, -0.0561236218F,
        -0.0409424715F, 0.0293830838F, 0.0598675832F, -0.0456795096F,
        0.0240852535F, -0.127697468F, -0.0664646849F, -0.110727303F,
        0.0300671179F, 0.0696807206F, 0.0681730509F, -0.0157520678F,
        -0.013003638F, -0.087382637F, -0.0281891823F, 0.0411946438F, 0.0422288F,
        0.0448508635F, -0.0364359356F, -0.0178490784F, -0.0478788242F,
        -0.0622870922F, 0.0496482141F, 0.0543621071F, -0.00404320564F,
        -0.027380472F, -0.0850647911F, 0.00714385603F, -0.0375251733F,
        0.0602720454F, -0.0241835471F, -0.024711417F, -0.0425154492F,
        0.0432845354F, 0.0398725867F, 0.0670306608F, -0.0515801497F,
        -0.0652264953F, -0.0890467167F, -0.0481927432F, -0.0424606651F,
        -0.0123495301F, 0.0061966097F, 0.0604485199F, 0.105678961F,
        -0.0691769943F, -0.0221052859F, -0.0356635116F, 0.00902205426F,
        0.10228546F, 0.0599403679F, -0.108446814F, -0.0452507026F, -0.100987621F,
        -0.10398335F, -0.100165613F, -0.0688194707F, -0.136297688F,
        -0.0605098382F, 0.0585332252F, 0.0260627735F, 0.0937714428F,
        0.0307235345F, -0.000821377733F, -0.011591848F, 0.0999488086F,
        -0.070714213F, 0.0411370695F, 0.0172712635F, -0.0280677229F,
        0.0385323651F, 0.0864312425F, 0.0822225735F, 0.133735567F, 0.0545346029F,
        0.0412304662F, -0.00764656859F, 0.0781367719F, -0.0121263191F,
        -0.0565673783F, 0.0866100267F, 0.0120042553F, -0.0492925271F,
        0.0371316858F, -0.0514466502F, 0.0108421408F, 0.00126447226F,
        0.0601597726F, 0.0730698556F, 0.0520889759F, -0.028484799F, -0.081358F,
        -0.0695199072F, 0.0350111611F, -0.0328586362F, 0.0700386092F,
        0.026811827F, -0.00688877888F, -0.0422742069F, -0.0106304735F,
        -0.0590386316F, 0.0620810576F, 0.0318830833F, 0.0136097558F,
        -0.112523451F, -0.0478673577F, 0.0235200934F, 0.0276557803F,
        0.0883752704F, 0.0839890465F, -0.0548167229F, -0.0785018355F,
        -0.0385834F, 0.00343025383F, 0.0629792F, -0.0244496241F, 0.0921936408F,
        -0.00168380432F, -0.0764772221F, -0.0883584693F, 0.0209812168F,
        0.047635667F, 0.0523470528F, -0.00128064735F, 0.0738409162F,
        -0.0143624963F, 0.0133271869F, 0.0633161813F, 0.0456656553F,
        0.0256736241F, -0.0936063528F, -0.0662637949F, -0.0117996754F,
        -0.120485552F, -0.00743267359F, -0.00148917781F, 0.0522048101F,
        0.0312730595F, -0.00322529953F, -0.111863546F, -0.0642259493F,
        -0.0411129333F, 0.0476820469F, 0.0410002358F, 0.0483020842F,
        -0.0578033365F, -0.0414658412F, -0.00784889F, 0.0191212893F,
        0.086093992F, 0.0269882809F, 0.00498498324F, 0.0353114158F,
        -0.091296792F, -0.118815094F, 0.0520073324F, 0.0592156947F,
        0.0440472066F, -0.0215868149F, -0.00620837463F, -0.091672577F,
        0.0305149946F, -0.0449136905F, 0.00153533241F, -0.0376713648F,
        -0.0236407239F, -0.0233079679F, -0.0451372F, -0.0838868767F,
        -0.0879880711F, -0.0436448678F, -0.0962202698F, -0.0241061486F,
        -0.0656460077F, 0.0219871551F, -0.00100208574F, 0.0296257343F,
        0.00339595531F, 0.11773283F, 0.0773428455F, 0.0419092514F,
        -0.0558631346F, 0.0200018343F, 0.0813833103F, 0.0126347076F,
        0.0132697355F, 0.0158394333F, -0.036243394F, -0.00317263021F,
        -0.0306770653F, 0.0395840444F, -0.0226534046F, 0.0768402591F,
        -0.0673254877F, -0.00306255044F, -0.0965509042F, -0.062389832F,
        0.0295414962F, 0.0180749148F, 0.0706036687F, 0.0658500567F,
        -0.023375839F, -0.0230032895F, 0.0622460954F, -0.106933117F,
        -0.0350828543F, -0.107122831F, 0.0664928928F, 0.062549524F,
        -0.0417211056F, 0.08029522F, -0.00999340229F, 0.0173067451F,
        0.017338939F, -0.124776907F, -0.0175345354F, 0.0257239901F,
        -0.0268831272F, 0.0580166653F, 0.048942171F, -0.112201139F,
        0.0812617317F, -0.0543424636F, 0.0371444821F, 0.057141263F,
        -0.0228101257F, -0.0182730332F, 0.00601953035F, 0.0600435361F,
        0.0255284943F, 0.0910138711F, -0.0874989629F, -0.101364948F,
        0.0866211951F, 0.00612571975F, 0.0128934328F, -0.103337839F,
        -0.0208378267F, 0.0660608783F, -0.0368377604F, 0.020133106F,
        0.00266081397F, -0.0531306304F, -0.044773683F, -0.0665497482F,
        0.0682914555F, 0.0451003425F, -0.0412433334F, -0.0794312134F,
        -0.0441946462F, 0.038663134F, 0.018516669F, 0.0378047265F,
        0.000757167232F, -0.0625158399F, -0.0183178466F, -0.0864144489F,
        0.0631679222F, 0.134392753F, -0.0971968397F, -0.0208249185F,
        -0.117355958F, -0.0528318398F, -0.0339506716F, -0.0563662425F,
        -0.053475704F, -0.0868463367F, 0.0636813045F, -0.0635662526F,
        -0.0137781091F, 0.0889422894F, -0.0484773256F, 0.131520107F,
        -0.0413684808F, -0.125478491F, 0.0594047606F, -0.0684376806F,
        -0.0823713765F, -0.0107816951F, -0.101656184F, 0.0189709403F,
        -0.0151021648F, -0.0468594097F, -0.0675586835F, -0.063767463F,
        -0.118612722F, 0.0696201324F, 0.021635389F, -0.0100645619F, -0.10494142F,
        0.0594157912F, 0.030919183F, 0.0263065267F, -0.0768820718F,
        0.0450003706F, 0.0723344162F, -0.0182342734F, -0.0804802105F,
        -0.0779622495F, -0.0930822343F, -0.0717452839F, 0.0290964078F,
        -0.0931868702F, -0.0747626647F, -0.00482050655F, -0.068295978F,
        -0.07626798F, -0.0944366753F, -0.0597784482F, -0.0265540127F,
        -0.0179265495F, -0.0210780576F, -0.0693838745F, -0.0634977669F,
        -0.0549308658F, 0.00379538233F, -0.00103525957F, 0.0214487351F,
        -0.103008151F, 0.039942909F, -0.0106708137F, -0.072192736F,
        0.0444534384F, -0.0287922844F, -0.0694476739F, 0.0839629695F,
        -0.0172228049F, -0.0758317634F, 0.0482430384F, -0.0164944883F,
        -0.0745538697F, 0.0184618812F, -0.0330740884F, 0.0173492674F,
        -0.0845414F, -0.0773177519F, 0.0627266F, -0.05492137F, 0.0382747762F,
        -0.0606591329F, 0.0452077053F, 0.0688847527F, 0.0130828153F,
        -0.105563372F, -0.052756317F, -0.0956550241F, -0.0920122936F,
        0.0210473407F, -0.0748619139F, -0.0117480243F, -0.0582631156F,
        0.00229935185F, -0.00962476F, -0.00711448444F, -0.019019993F,
        -0.0280117299F, -0.00748667F, 0.0110304337F, -0.0545870289F,
        0.0616963096F, -0.0238423068F, -0.0159650482F, -0.0703007951F,
        -0.0279302932F, -0.0796299055F, 0.0114803063F, 0.0619412549F,
        -0.0405915715F, -0.0048782425F, -0.00966490246F, 0.0419961847F,
        -0.0242718272F, -0.0528454706F, 0.0506656356F, 0.0101161767F,
        -0.00616051815F, 0.0680296198F, -0.00453358702F, -0.0352738164F,
        0.0182997733F, 0.0509335883F, -0.0733022094F, -0.0356913917F,
        -0.0102927983F, -0.0608498864F, -0.0386350341F, -0.045357F,
        0.0486589409F, -0.014442116F, 0.0222965628F, -0.0858165473F,
        0.0594878048F, -0.0291831084F, -0.0953602F, 0.0209651291F, 0.0646406859F,
        0.0727359876F, -0.0413237698F, -0.0462845974F, -0.0384022407F,
        -0.0336692855F, -0.0420861505F, -0.0892590135F, 0.0329495333F,
        -0.0726291537F, -0.0327833183F, -0.0998235419F, -0.017818654F,
        -0.076283522F, -0.0278159492F, -0.0216022506F, -0.0196508076F,
        -0.0309089534F, -0.0274755657F, 0.0068234927F, -0.0480441861F,
        -0.0166163631F, 0.0389523804F, 0.0672870278F, -0.00219191168F,
        0.106850319F, 0.0500230417F, 0.0818162411F, 0.0635484681F, 0.0544425547F,
        0.0521287732F, 0.0552243814F, -0.0379151F, -0.0189306978F, 0.0490813628F,
        0.00460491795F, -0.0477642F, 0.0676320866F, -0.0810510665F,
        -0.077355817F, 0.0906640887F, 0.0934106112F, 0.00173395185F,
        0.0365296789F, 0.00937384553F, 0.0868824646F, 0.0802738741F,
        0.0964648277F, 0.0888690501F, 0.0352702625F, -0.0881936923F,
        0.0174828023F, -0.0333670788F, 0.0781232864F, -0.0344598889F,
        -0.0488664657F, 0.086328961F, -0.0744039938F, -0.0384383872F,
        0.0516089201F, -0.00298759947F, 0.0436123498F, 0.0479242764F,
        -0.0541318916F, 0.043722406F, -0.0289450269F, 0.0373672806F,
        0.101236723F, -0.0435010903F, 0.0604340062F, -0.0407025255F,
        -0.0391462334F, -0.0864740461F, 0.00197514938F, 0.0333070122F,
        -0.0148743633F, -0.0100749396F, 0.0110749425F, -0.0212902725F,
        -0.104199253F, 0.0393776223F, -0.0340720899F, -0.0127866818F,
        -0.0813752F, 0.0223416593F, -0.0118816448F, 0.0338442475F,
        -0.0196449365F, 0.0118748406F, 0.049406644F, -0.0592330359F,
        -0.00888539758F, -0.0893534496F, -0.0794971213F, 0.0445884578F,
        0.0469674803F, -0.0625862405F, -0.0839127F, 0.0422957502F, 0.0224003252F,
        0.0659009218F, -0.0661356F, 0.0635753497F, -0.00399759691F,
        -0.0462066792F, -0.0620598048F, 0.0293135624F, -0.00979192741F,
        0.0304568633F, 0.0449909456F, -0.00530518964F, 0.00176248199F,
        0.0620712414F, -0.0172761045F, 0.058185596F, -0.0471712723F,
        0.0280777607F, -0.0796734244F, -0.0241986718F, -0.0170798022F,
        0.0715288445F, 0.0428498499F, -0.0104258526F, -0.0598966479F,
        0.092152819F, -0.0619620644F, 0.0381143577F, -0.000816921878F,
        -0.0483442321F, -0.0492171608F, 0.0254637934F, 0.00139992579F,
        0.0382943F, -0.107184455F, -0.0327588655F, 0.0530715138F, 0.00868829899F,
        0.0162829924F, 0.0589798763F, 0.0145897884F, -0.0245813597F,
        0.0178922508F, 0.0592219867F, -0.0959094539F, 0.00683809444F,
        0.0380090475F, 0.0287993F, -0.0317669772F, -0.131755412F, 0.00396336475F,
        0.0517128557F, 0.0251900572F, -0.0865463614F, 0.0714799687F,
        -0.024012439F, 0.0262256879F, -0.0620799661F, -0.0873996839F,
        0.0387086608F, -0.0518660657F, -0.0525849275F, -0.0742191F,
        -0.0284971036F, -0.102479115F, -0.0729983523F, 0.0318847373F,
        -0.0537561178F, -0.0437908173F, 0.092858091F, -0.0377921611F,
        -0.0728601888F, 0.0696561411F, 0.00645000627F, 0.0332204737F,
        -0.0786379948F, -0.021840265F, -0.0202842988F, 0.0393997505F,
        0.0354509205F, -0.019425597F, 0.0648941398F, -0.000619009312F,
        0.0688157454F, -0.0415737815F, -0.0485357083F, -0.0600457229F,
        0.0687323287F, 0.0394749939F, 0.090003483F, 0.0629036501F,
        -0.0881213769F, -0.0429177508F, -0.0426334739F, -0.0596543811F,
        -0.0325279944F, 0.0852043107F, 0.0245811753F, 0.069705449F,
        0.0639864951F, -0.0610630102F, 0.0812177882F, 0.081126146F,
        0.0605524555F, -0.0110357022F, 0.0982386842F, 0.0358387791F,
        0.0455675423F, 0.0336901806F, -0.0415415913F, 0.0819723383F,
        0.0329791978F, -0.0559349656F, -0.0394273847F, -0.0302213375F,
        -0.0313697308F, 0.0474985428F, 0.0186600536F, 0.00353891798F,
        -0.0260659643F, -0.0560787581F, 0.022310568F, 0.0327881388F,
        -0.0750675574F, 0.0312725492F, -0.0466111712F, -0.0192177836F,
        -0.0345031805F, -0.0346327499F, -0.00753356889F, -0.0437279455F,
        0.0611063763F, 0.0823043585F, 0.0116525423F, -0.0210944097F,
        -0.0884988755F, 0.039293468F, -0.0527418032F, 0.0671716258F,
        -0.0194929633F, 0.0312669873F, -0.0667743161F, -0.0517920963F,
        0.0380726382F, 0.0250595044F, 0.00813843776F, 0.0462701507F,
        0.0546798557F, -0.0191714186F, 0.00815292634F, 0.062654078F,
        -0.0469435826F, -0.0130798817F, 0.0647372901F, -0.0402633511F,
        0.0963727906F, 0.0555900373F, 0.0634988621F, 0.00291131763F,
        -0.0386579111F, -0.0575897023F, 0.0412760302F, 0.0443223678F,
        0.0791882426F, -0.0427546315F, -0.0651657954F, -0.0959002823F,
        0.0156417321F, 0.0072374F, -0.0867681727F, 0.0243977252F, -0.0345134102F,
        0.0273017883F, -0.065743871F, -7.68478203E-5F, 0.0873604789F,
        0.0556131676F, 0.0464957692F, 0.00261979783F, -0.0334699228F,
        0.0227096733F, 0.0319684818F, -0.0269271545F, -0.0443207063F,
        0.0223896373F, -0.0954679921F, 0.0385120362F, -0.0844930559F,
        -0.0600959733F, -0.0194501337F, 0.0628431141F, 0.000862813729F,
        0.00894684251F, 0.068761386F, -0.0835555568F, 0.101754874F,
        0.0543434843F, -0.048765853F, 0.00794044882F, -0.00466574403F,
        -0.0554749481F, -0.0175396148F, 0.0564456F, 0.0497004688F, 0.0844360515F,
        -0.0753064454F, -0.0221486893F, 0.0410497449F, 0.0726732165F,
        -0.0280250907F, -0.00526044518F, 0.100807332F, -0.0264318623F,
        0.0300481804F, 0.100685239F, 0.0168934632F, -0.0625621825F,
        0.0502687432F, -0.0233637765F, -0.01337713F, 0.019520238F, -0.040198978F,
        0.0193518866F, -0.029402893F, 0.0888387561F, 0.0683286786F,
        -0.0484871939F, -0.0709668919F, -0.0932276174F, -0.073883079F,
        0.0441798419F, -0.0575495958F, -0.0472954139F, 0.0190626904F,
        -0.0260296632F, -0.051762633F, -0.0356994234F, -0.032859426F,
        0.0337900594F, 0.0438798629F, 0.0552205779F, -0.0441610217F,
        0.015774766F, -0.00280628796F, 0.024367772F, -0.0161123388F,
        -0.059445668F, -0.0598152019F, -0.0111419391F, -0.103606746F,
        0.065683946F, -0.0544928F, -0.0606832691F, 0.0218945742F, -0.081297F,
        0.0747236833F, -0.0780284703F, 0.0141577199F, 0.0101142051F,
        0.0657557473F, 0.0313887708F, 0.0286386404F, -0.0258983F, -0.0393138714F,
        0.0743048638F, 0.026521204F, -0.0719215572F, -0.0815536305F,
        -0.0143125933F, 0.0955719203F, -0.0307392981F, 0.0261343066F,
        0.0403786413F, 0.00839565694F, 0.0321894251F, 0.085631296F,
        -0.0210598949F, 0.0603879653F, 0.0582883F, -0.11021737F, -0.0171702374F,
        0.0493481457F, 0.0339347832F, 0.0423156843F, 0.100476049F, 0.0680185F,
        0.0164189767F, 0.103216216F, 0.0310510341F, -0.0444860831F,
        -0.00505794445F, 0.0728809386F, 0.112834767F, 0.0242748167F,
        0.0453743264F, 0.0327980965F, -0.0170291904F, 0.0462735221F,
        0.0522918217F, -0.119585745F, -0.00586811407F, -0.0618018396F,
        0.00883635879F, 0.0261242483F, -0.0430222526F, -0.105578713F,
        0.0330105871F, -0.0895998925F, 0.093349576F, -0.0565119162F,
        0.0812966749F, 0.0118515417F, -0.0506514385F, -0.0331176F, 0.0750965178F,
        0.028808523F, 0.0807795674F, 0.0212646537F, -0.0269257892F, 0.124391675F,
        -0.0149106104F, 0.0427012593F, -0.000580102729F, 0.0796439052F,
        0.0674939081F, -0.0104043772F, 0.084112145F, -0.0674097463F,
        -0.107523933F, -0.0801353455F, 0.0302441083F, -0.068931751F,
        0.0381702445F, -0.00867728703F, 0.067781657F, 0.00319259241F,
        0.0436298363F, 0.00451137731F, 0.0856259465F, 0.0873016194F,
        0.0832500085F, 0.0638611615F, 0.0919616073F, -0.0570231266F,
        0.0113788564F, 0.0642351732F, 0.0454356074F, -0.0936377719F,
        -0.0177108273F, 0.0982700884F, -0.0210576337F, 0.0850939602F,
        -0.0692343637F, -0.00808310229F, 0.0966204F, 0.0185624249F,
        0.0223338641F, 0.0864397734F, 0.0400988236F, -0.0774091F, -0.0280219335F,
        -0.0747458786F, 0.00789416768F, 0.0825966522F, -0.00315578887F,
        -0.0308633894F, 0.137285978F, 0.120497599F, 0.0174443927F,
        -0.0671397671F, 0.0246745013F, 0.00826500263F, -0.00422356045F,
        0.0268508941F, 0.0708979517F, -0.0364317596F, 0.00725918869F,
        -0.0136406897F, 0.0111369882F, -0.109778747F, -0.0108579984F,
        0.0829077512F, -0.0529238619F, 0.0830775648F, -0.0510750897F, 0.0138069F,
        0.0519724786F, -0.0390451513F, 0.0568452328F, -0.0951756611F,
        0.0976053476F, -0.0504688658F, 0.0597813427F, -0.0630830079F,
        -0.0220497381F, -0.0844741538F, -0.0356315449F, 0.033203464F,
        -0.0475664102F, 0.0431832559F, 0.0470583364F, 0.0333148241F,
        0.00247300696F, 0.0583727397F, -0.0423986726F, 0.0837913454F,
        0.0582162179F, -0.00781096471F, 0.0383234F, 0.0377069376F,
        -0.0408719033F, -0.0725031793F, -0.0403681F, 0.08457876F,
        -0.00924999826F, -0.0266486537F, 0.0128408652F, -0.0461126231F,
        -0.0570780225F, -0.00861923F, 0.0691790879F, 0.0283070635F,
        0.0594262406F, 0.00188137009F, -0.0515141524F, -0.024135299F,
        0.0616659708F, -0.107757702F, 0.0676903203F, 0.00650511403F,
        -0.0584917478F, 0.0235350803F, -0.0716005042F, -0.070264712F,
        0.00593544031F, -0.0866922438F, -0.100332461F, -0.0386445783F,
        -0.0835712478F, -0.0382498205F, -0.0277644433F, 0.0557274409F,
        0.0658892468F, 0.0734220445F, 0.121202707F, -0.0127341421F,
        -0.0601497032F, -0.0270044655F, 0.0310825408F, 0.00791460555F,
        0.00701102521F, -0.0680335909F, -0.0121930121F, -0.0665905625F,
        0.0296323653F, 0.0107894344F, 0.013993863F, -0.0510077477F,
        0.0689899549F, -0.0384827368F, 0.0209729243F, 0.0732392445F, -0.104351F,
        -0.0371233895F, 0.0711311698F, -0.0424233712F, 0.0170370471F,
        0.0109658707F, -0.0994827896F, -0.0549722873F, 0.0616105944F,
        -0.0680728257F, -0.048446849F, -0.0619333759F, 0.0758397505F,
        0.0471639745F, -0.0216633864F, 0.0602587871F, -0.0580663532F,
        0.0190043915F, -0.0109345885F, 0.0550661385F, -0.0689685345F,
        0.113988578F, 0.00912385434F, 0.0462820195F, -0.0657458752F,
        -0.0488473214F, 0.00731392624F, -0.0831652209F, 0.0134454584F,
        -0.0892440155F, -0.0484184362F, 0.0289678611F, -0.00436599879F,
        0.101902686F, -0.0415134318F, 0.036216747F, -0.0338250175F,
        0.0931881592F, 0.0322997123F, -0.0203987863F, 0.0174531098F,
        0.0629595071F, -0.0416331217F, -0.00266563427F, -0.0651415065F,
        -0.0119592603F, 0.0298106149F, 0.0206552017F, 0.00342037645F,
        0.0124882376F, -0.0523901097F, 0.0747122F, -0.0139452415F,
        -0.0749855787F, -0.0572486147F, 0.0604327209F, 0.0849730149F,
        -0.00607542F, 0.0491186716F, 0.0364360921F, 0.00557635399F,
        0.0800128877F, 0.0608475618F, -0.0555493981F, 0.0423459038F,
        0.0713490471F, -0.061712198F, -0.0729567334F, 0.0271832179F,
        0.0579026565F, -0.0148292584F, -0.0455808342F, 0.051664196F,
        0.0141442521F, -0.0608829483F, -0.0147080272F, 0.0283429213F,
        -0.0173075069F, 0.0550732315F, 0.0874275118F, -0.0868977234F,
        0.00774650695F, 0.0787104443F, 0.0119791236F, 0.000750415376F,
        -0.0261376332F, 0.0387302302F, 0.0651660413F, 0.00395924179F,
        0.024868777F, -0.117640257F, 0.0605850965F, 0.0254144501F, 0.0429528169F,
        0.0470230505F, -0.0761465058F, 0.0485710651F, 0.0401100852F,
        0.0671887845F, 0.0389452167F, 0.0835463479F, 0.112426527F, 0.0618974492F,
        0.0518983938F, -0.0020924923F, -0.0899717361F, 0.00183542771F,
        -0.0778911337F, -0.0400890298F, -0.0787674785F, -0.0949299932F,
        0.0137504227F, -0.0469522215F, 0.0625993237F, 0.0441464148F,
        -0.0492006019F, -0.0171852242F, 0.00372075313F, -0.0231636818F,
        -0.0138695482F, 0.00576701667F, 0.0657858551F, 0.0724109337F,
        0.0599470846F, 0.00333767105F, -0.0471703187F, 0.0298468545F,
        -0.0258099586F, 0.0385977291F, 0.0915055871F, -0.0855031535F,
        -0.0853784382F, -0.0793450549F, 0.0070460774F, 0.0883362293F,
        -0.0143276807F, 0.0603580773F, -0.0599398091F, -0.0527705625F,
        -0.00266818958F, 0.0545123219F, -0.0782993808F, 0.0666123778F,
        0.0442904048F, -0.106669143F, -0.0393062532F, -0.0561323613F,
        -0.0767242908F, 0.0309373159F, 0.0315277763F, 0.000932917406F,
        -0.0575098619F, -0.10081391F, 0.0341682434F, -0.0383706465F,
        0.0187320486F, -0.0642317384F, -0.119462952F, 0.0279079862F, 0.0190384F,
        -0.0955363512F, 0.0864026397F, -0.0876044482F, 0.0441174619F,
        0.0078586461F, 0.0167402588F, 0.0573479235F, 0.0615724549F,
        -0.058222577F, 0.0333175361F, -0.107843608F, -0.0808948651F,
        0.0337033942F, -0.036840681F, 0.013281987F, 0.0689375401F,
        0.00517795514F, -0.0193497017F, -0.0423070788F, 0.00918419659F,
        0.0475320294F, 0.0220590532F, 0.0176782683F, -0.0253451522F,
        -0.0475917533F, -0.00243773498F, -0.0153965466F, 0.0330661424F,
        0.0624796413F, -0.0515345261F, -0.0188977178F, 0.0217974707F,
        -0.0833726525F, -0.0250138566F, -0.00576529186F, 0.0487887785F,
        0.0548151731F, 0.0790523887F, 0.00362404552F, 0.00236450881F,
        0.0243639462F, -0.0229618549F, -0.0927816704F, 0.0856145471F,
        -0.0295243394F, -0.068324931F, 0.0427244678F, 0.0686291382F,
        -0.00121626572F, 0.097108528F, -0.0149051202F, -0.0557566322F,
        0.0610966235F, 0.0553509295F, 0.112734444F, -0.00844994467F,
        -0.0806978345F, 0.0472890846F, 0.0315348245F, 0.014224831F,
        -0.0406520739F, -0.0536709353F, 0.0261944383F, -0.04781387F,
        -0.0871796757F, 0.0139552681F, 0.0372595713F, -0.0167490561F,
        -0.0460012294F, -0.00970428344F, 0.027266F, -0.00992752612F,
        -0.0280594397F, -0.135436803F, 0.00279866089F, -0.0642870739F,
        -0.0663970038F, -0.0770834163F, -0.00387350703F, 0.00572159793F,
        0.0773792043F, 0.0218026526F, 0.0152021982F, -0.0436521024F,
        -0.0279043261F, 0.0200559609F, 0.0834869072F, 0.00534156F,
        -0.0397263616F, -0.00533913309F, -0.0323718823F, -0.0736886337F,
        -0.0586859211F, 0.0100069446F, 0.0758104F, -0.112988181F, 0.0438471F,
        0.120189227F, 0.0185488947F, -0.0280233826F, -0.0710619241F,
        -0.0817032084F, 0.0485705249F, -0.0404376648F, 0.0809908658F,
        -0.00585222337F, 0.0366077758F, -0.00540210353F, 0.0737708434F,
        0.050297223F, 0.136723638F, 0.01083613F, 0.0299567915F, 0.0843271837F,
        -0.0716900304F, 0.0274616946F, 0.0746847615F, -0.0359125547F,
        -0.0644127503F, 0.0168334749F, 0.0546876192F, -0.0410912931F,
        -0.00458403304F, 0.119241305F, 0.145221457F, 0.0619052835F,
        0.0531962737F, 0.0605820343F, -0.0761377215F, 0.00745510729F,
        0.0687735677F, -0.0472574569F, -0.0357462F, -0.0194782075F,
        -0.106317677F, -6.02836371E-5F, -0.0902379F, -0.0431755222F,
        -0.0790695697F, 0.0303048566F, -0.109551F, 0.0315403342F, 1.16963056E-5F,
        -0.0492397957F, 0.0715395361F, -0.0258630347F, -0.0497295223F,
        0.0348075069F, 0.0139013873F, 0.0249478705F, 0.00680250255F,
        -0.105107591F, -0.088764146F, -0.0603705794F, -0.0270006787F,
        -0.0584015697F, 0.0220735893F, 0.0402840264F, -0.0945794135F,
        -0.0602885447F, -0.0243377183F, -0.0584944263F, -0.0652679726F,
        0.0283819791F, 0.0828715935F, 0.0713097304F, 0.000328825699F,
        0.00261629303F, 0.00673721218F, -0.102694698F, -0.0615410879F,
        -0.0333552584F, 0.0266730115F, 0.10150709F, 0.130742192F, -0.0437082872F,
        0.0121044479F, 0.099064216F, -0.0374947339F, -0.0926252529F,
        0.101066887F, 0.0331292115F, -0.110248566F, 0.0319607146F, -0.027035214F,
        -0.0765797198F, -0.000337408477F, 0.0221135542F, 0.0721731558F,
        0.0545523651F, 0.0713940784F, 0.054063566F, 0.0205924138F,
        -0.0187692158F, 0.0578678437F, -0.085097678F, 0.116726696F,
        -0.0889134631F, -0.128150716F, 0.0842090845F, -0.0780919641F,
        -0.0427005291F, -0.0206621177F, -0.00842322409F, 0.023276452F,
        -0.0592678674F, -0.0924254F, 0.094293572F, -0.0121621517F, 0.0121270763F,
        0.0393272936F, 0.00649720477F, -0.0600901395F, -0.010527839F,
        0.116038628F, 0.0703084245F, -0.0615761578F, -0.00361507223F,
        -0.0700083375F, 0.104863569F, -0.0410716198F, 0.0604400486F,
        -0.0116114914F, 0.00777712278F, -0.0344260894F, 0.075936608F,
        0.0190510023F, -0.0506089702F, -0.0463991202F, 0.0792779848F,
        -0.0116784284F, -0.00395729439F, -0.0652738884F, -0.00293832039F,
        -0.0354989544F, -0.00915645435F, 0.00285211671F, 0.0564198196F,
        -0.0423199683F, 0.0322815366F, 0.0269991439F, -0.0623535439F,
        -0.0480395295F, 0.0327726789F, 0.0735959709F, -0.0275557078F,
        0.103823587F, -0.0356469341F, -0.00470354687F, -0.0556484349F,
        0.0509441607F, -0.0604583099F, 0.0590155236F, -0.0140405884F,
        0.034401726F, 0.0221083667F, -0.00962164253F, 0.0958802924F,
        0.0643231571F, 0.0318238512F, 0.0378420278F, 0.0394034907F,
        0.0596693531F, -0.0126987F, -0.0301338825F, 0.128773063F, -0.109353215F,
        0.120825991F, 0.0341928564F, -0.119232848F, -0.00764031382F,
        0.0245596822F, -0.0363270901F, 0.0560606234F, 0.0446003973F,
        -0.0633782819F, -0.107749589F, 0.074256964F, 0.0269857962F,
        -0.0240113232F, 0.0410412326F, 0.0314021744F, -0.0162128564F,
        0.0858305469F, 0.00942997448F, -0.0174486507F, -0.00917091221F,
        -0.0644219741F, -0.0284099579F, -0.0708893687F, -0.0510290079F,
        -0.0760709867F, -0.0788411F, -0.101601504F, 0.0324980244F, 0.0160087235F,
        -0.098005563F, 0.00231003715F, -0.0995154381F, -0.0631484091F,
        -0.107308403F, -0.0483105257F, -0.103269883F, 0.0891333F, -0.058016181F,
        -0.0440191403F, 0.0448681079F, -0.061243251F, 0.0359148607F, 0.0415989F,
        0.0624023154F, -0.0422258489F, -0.0305833574F, -0.0133255478F,
        -0.011090612F, -0.0960055217F, -0.0416766889F, -0.106869981F,
        0.0836176351F, 0.0426389F, -0.0396632515F, 0.0023498768F,
        -0.00645773811F, 0.0301175639F, -0.0610515513F, 0.120438971F,
        0.023021359F, -0.0182320047F, -0.081857644F, 0.0718598738F,
        0.00611818582F, 0.12295825F, 0.0136264218F, -0.067748934F,
        -0.00725562777F, -0.0130578969F, 0.0392436199F, 0.124842174F,
        0.0612378456F, -0.106518686F, -0.0639461279F, 0.0959716663F,
        0.00140666158F, -0.0500919931F, -0.076019451F, -0.0338547714F,
        -0.0882811621F, 0.0974860564F, 0.0122003267F, -0.0909371376F,
        -0.0476700403F, -0.0473644696F, -0.0111571867F, 0.000625477056F,
        0.0405081F, -0.081414327F, -0.00845515449F, -0.0898411F, 0.132737204F,
        -0.069665581F, 0.109514579F, 0.0190154295F, -0.0828009248F,
        -0.054435946F, 0.112353466F, -0.0396383591F, -0.0559368469F,
        -0.0386872478F, -0.0505167432F, -0.0263234768F, -0.0955098942F,
        -0.00224418845F, 0.04384638F, 0.0230810549F, -0.0199404284F,
        0.0440802276F, 0.106724761F, 0.0566356555F, -0.0918667838F,
        -0.0107758846F, 0.0174117628F, 0.0637818649F, -0.0181392916F,
        -0.0959293768F, 0.0198133681F, -0.098814182F, 0.0223490261F, 0.034319F,
        0.0432266071F, 0.0455289036F, 0.0728314F, 0.0217377469F, 0.0727292374F,
        0.0423823372F, -0.0501240417F, -0.0643105581F, 0.0326994024F,
        0.00154308369F, -0.0750782341F, -0.0796596706F, -0.0992465615F,
        -0.0991356298F, -0.0322582088F, 0.0385676734F, 0.0792470053F,
        0.0236551668F, 0.0457732864F, 0.000473908964F, 0.0281669963F,
        0.00744245527F, 0.00338624488F, 0.0148452884F, 0.0183381047F,
        -0.000549936667F, 0.0409115F, 0.02120528F, -0.0567922816F, -0.052731324F,
        -0.0320121832F, -0.0684060678F, -0.0393481813F, -0.0512050278F,
        0.0433110297F, 0.00302837882F, -0.0498433299F, -0.0295988508F,
        0.0293722879F, -0.00632891338F, -0.00759266224F, 0.0381097123F,
        -0.0345802456F, -0.0234201644F, -0.0352866612F, -0.0208601747F,
        -0.053391654F, -0.0836569816F, 0.0201780647F, 0.0453344472F,
        -0.112536378F, -0.0218474101F, -0.0129780136F, -0.0733995363F,
        0.00790239219F, 0.0783595368F, 0.0633404478F, -0.0673847944F,
        -0.0595831499F, -0.103055283F, -0.0200402178F, 0.0857419819F,
        0.0349381268F, -0.0237631574F, -0.0295976102F, 0.0473909639F,
        0.0435857102F, -0.0938564315F, 0.0308260042F, -0.0463494286F,
        -0.0645306483F, -0.010497204F, -0.0848069638F, 0.037943244F,
        -0.0477541573F, 0.0477189794F, 0.0359243378F, -0.0147920894F,
        -0.025174316F, 0.048308365F, -0.0333265886F, 0.0156371333F,
        0.00070902938F, 0.0161614027F, -0.0639821F, -0.0232133958F,
        -0.000961137936F, -0.0874993354F, -0.0268873814F, 0.0262758248F,
        0.00183767965F, -0.0443660505F, 0.0356675163F, 0.0245108064F,
        -0.0466822125F, -0.0479581803F, 0.0231573191F, 0.0732062384F,
        0.0434693396F, 0.00604505278F, 0.0244131815F, -0.0178504437F,
        -0.040691264F, 0.0143182809F, 0.0383538269F, 0.0635198951F,
        0.0720811784F, -0.0306136068F, -0.0133214174F, 0.0419045649F,
        0.0170408189F, 0.0892671F, 0.0575733483F, 0.0199884828F, -0.0758131F,
        -0.0815624744F, -0.0981352329F, -0.0930572152F, -0.0569678061F,
        -0.000458880735F, 0.0800903067F, -0.048620861F, -0.000422148441F,
        0.053790506F, -0.0616723038F, -0.0897203609F, 0.0962278321F,
        0.0930341631F, -0.105337575F, -0.00332669728F, -0.0411154851F,
        -0.0685586F, -0.0606206954F, 0.0120959524F, 0.0344734117F,
        -0.0342593081F, -0.0102292988F, -0.0133075407F, -0.0770741105F,
        0.0483076498F, 0.0144687835F, -0.0649462268F, -0.0098173609F,
        0.109951891F, -0.0272787288F, 0.0708773136F, -0.0943284631F,
        0.0389393978F, 0.0389990509F, 0.0175900795F, -0.0362698473F,
        -0.112284914F, 0.017198788F, 0.10354086F, 0.0424515121F, -0.0144153256F,
        -0.0144195696F, -0.0918642506F, 0.0763157904F, 0.105887361F,
        -0.068524234F, -0.0212289654F, 0.0163473673F, -0.0935992F, -0.110780485F,
        -0.0049731466F, -0.0684837F, -0.0687717646F, 0.0294346046F,
        0.0113477157F, -0.0130739221F, 0.0311418232F, 0.0692528412F,
        -0.0961541608F, 0.0596765429F, -0.0137144318F, -0.0552145429F,
        0.0297754779F, -0.0321244672F, -0.0060012769F, -0.00404899F,
        -0.0337536968F, -0.0166373756F, -0.00136957574F, 0.0269253459F,
        0.0187120494F, 0.0186092537F, -0.0894139707F, -0.0195169933F,
        -0.0308918618F, -0.0667609647F, -0.0943327248F, 0.0457393751F,
        -0.0407526083F, 0.0205005053F, 0.0326750763F, 0.00377202802F,
        -0.0881968886F, 0.0129748341F, -0.0827275515F, 0.0477023199F,
        0.0383699574F, -0.0942589268F, -0.119352959F, 0.0856011808F,
        -0.0955381542F, 0.0727000087F, -0.0187960099F, -0.0606531315F,
        -0.0607677437F, -0.0486206412F, 0.0168644469F, 0.0313986354F,
        0.019526517F, -0.00925878156F, 0.0602122545F, 0.00902896561F,
        0.000696983305F, 0.0357092582F, -0.0286591072F, -0.0838242546F,
        -0.0792411491F, 0.0195958819F, 0.00385535695F, 0.0159100629F,
        -0.096257247F, 0.0499528386F, 0.0159790274F, -0.0286981929F,
        0.00436934177F, 0.00488584163F, 0.033662267F, 0.0334738456F,
        0.0710778236F, -0.0510963947F, 0.0557028875F, 0.0256840326F,
        -0.0150194373F, -0.0585024171F, -0.00721675111F, -0.102041647F,
        -0.0255974457F, -0.0959824622F, -0.0333055F, -0.0421616621F,
        0.0518110693F, 0.012922314F, -0.088768132F, -0.0320684724F,
        -0.059274748F, 0.0155116776F, 0.039909713F, -0.0172409657F,
        -0.0598168261F, 0.0778877512F, -0.0370340496F, 0.0397157669F,
        -0.0603786968F, -0.087908417F, -0.0621243976F, -0.076175563F,
        0.0605115257F, -0.000197493224F, 0.042190671F, -0.0809226409F,
        0.034599185F, -0.0806684867F, -0.0110943774F, -0.076690644F,
        -0.0563493744F, -0.0543696769F, 0.0370340832F, -0.0774760246F,
        -0.0712137222F, -0.0955494195F, -0.0694908351F, -0.00138341612F,
        -0.00182776502F, 0.0330259763F, 0.0237126835F, -0.103625149F,
        0.00654191105F, -0.00140816125F, -0.0182536561F, -0.0556080453F,
        -0.0242863614F, -0.0577169098F, -0.0937155262F, -0.0130332345F,
        0.0007735049F, 0.0552767403F, -0.0219094325F, -0.0462726317F,
        -0.0950002074F, 0.000149600382F, -0.102304094F, -0.0336998515F,
        0.00211773021F, -0.0683978721F, -0.00947428215F, 0.0684823543F,
        -0.0626075789F, -0.0602297373F, -0.102711536F, 0.0321209207F,
        0.0782485828F, 0.0205712933F, 0.0349093042F, -0.039893046F,
        0.0594595633F, 0.00032372534F, 0.00437649712F, -0.111204445F,
        0.041447565F, 0.00256738416F, 0.0403633974F, 0.0237228926F,
        -0.0241340678F, 0.00524833333F, 0.0750636384F, -0.0549222082F,
        0.0478566512F, -0.0864052698F, 0.0188098159F, -0.0501842909F, -0.070944F,
        0.0264778491F, 0.026958514F, 0.00893222075F, 0.0712421164F, -0.10775727F,
        -0.0204323903F, 0.0380735062F, 0.0512468927F, -0.0576836094F,
        -0.0692185089F, -0.109383516F, -0.0330378227F, 0.0537825227F,
        -0.00471588271F, 0.0245999433F, -0.0270961951F, 0.0231440272F,
        -0.0782835186F, -0.0136040254F, 0.0127585577F, -0.0839041546F,
        0.0275497511F, -0.0489479043F, -0.0828477293F, -0.0418758392F,
        -0.0613970086F, -0.119500831F, 0.027094366F, -0.0619605F, 0.11615704F,
        0.0415029563F, 0.0627412871F, 0.122609675F, 0.0107303057F, 0.0170494858F,
        0.0854605287F, -0.0281808376F, -0.00460738968F, -0.0752305165F,
        -0.0812718645F, 0.0509923585F, 0.0102152154F, 0.0389362723F,
        0.0218844488F, 0.0593110956F, 0.0546465144F, 0.0365142599F,
        0.0129665472F, 0.0924397185F, 0.148307204F, -0.0165610369F, 0.124147959F,
        -0.044497367F, -0.0395589918F, -0.0487808473F, -0.0599604696F,
        0.126134306F, 0.0532534383F, -0.0502103791F, -0.0843306631F,
        -0.0540537387F, 0.002810715F, 0.0318848714F, -0.0601430796F, 0.144151F,
        0.00826227479F, 0.0157159977F, 0.12115638F, -0.0686966404F,
        0.0287203528F, -0.0741170049F, -0.0541691296F, 0.0799590871F,
        -0.00655622547F, 0.0180646051F, -0.020704072F, -0.0725844204F,
        -0.00281404587F, 0.0321795791F, -0.045776397F, -0.0188332759F,
        0.033700835F, 0.0374850221F, 0.0500000753F, -0.0242350101F,
        -0.0917228758F, -0.00497076567F, 0.00740429899F, -0.0296791177F,
        -0.0765648335F, -0.0823966265F, -0.0059378352F, -0.038008403F,
        -0.0687108412F, -0.0526648946F, -0.000715248054F, 0.00838759914F,
        -0.0364529379F, -0.0454636924F, 0.0466515198F, -0.0531837642F,
        -0.0666309223F, 0.0167228356F, -0.023829801F, -0.0788017958F,
        -0.0627689734F, -0.00289097242F, -0.0153071312F, -0.0837853178F,
        -0.0913642123F, -0.0739675611F, 0.0178455152F, -0.0484510623F,
        -0.0567045435F, -0.0225483961F, 0.0652927905F, -0.0965025127F,
        -0.0137031507F, 0.0565385409F, -0.0619895756F, 0.0375792831F,
        -0.0863011852F, -0.0498911329F, -0.00871768408F, -0.0319053307F,
        0.052153904F, -0.0245598648F, -0.0468620956F, 0.089153178F,
        -0.0316409245F, -0.0112652294F, -0.021057779F, 0.0360911228F,
        -0.0792341F, 0.0749594867F, 0.0246067718F, -0.0198092908F,
        -0.0770501196F, -0.0345426612F, -0.00334011531F, -0.0702668205F,
        0.0330783911F, -0.0284376871F, 0.0691780522F, -0.0261633843F,
        -0.0304509439F, 0.0183228552F, 0.00866532605F, 0.0433763452F,
        0.0257756542F, -0.0113877943F, 0.00916352775F, -0.0880980864F,
        -0.0391815118F, -0.0182191655F, -0.0275336746F, -0.0689680055F,
        -0.0658983663F, -0.0643778518F, 0.0275225043F, -0.0605331585F,
        0.0882336274F, 0.0102675334F, 0.0448811799F, -0.0703845695F,
        -0.0367608853F, 0.0053511993F, 0.0108170602F, -0.0315537602F,
        -0.0771408379F, -0.0555641949F, 0.089320831F, -0.0705721155F,
        0.114376538F, 0.0130516347F, 0.0150347147F, 0.0669669583F, 0.0624001138F,
        -0.0362459123F, -0.0587401241F, -0.00488451449F, 0.101618603F,
        -0.0517142974F, -0.0292741172F, 0.00218961062F, 0.0759806708F,
        -0.00617557159F, 0.0139684631F, 0.0229102727F, 0.0940612108F,
        0.0943674743F, 0.0708451F, -0.0567101166F, 0.0812203214F, -0.0222320501F,
        -0.0850148126F, -0.0684684515F, 0.0694898665F, 0.0024048537F,
        -0.0216105655F, 0.0845685F, 0.0645518675F, 0.0497114696F, -0.0450954698F,
        0.0791072F, -0.0293023568F, 0.060501609F, 0.0652126372F, 0.00672689872F,
        0.095178F, 0.105095617F, -0.0394715853F, -0.0800555125F, -0.0795901641F,
        -0.0383248739F, 0.0483194701F, 0.0148634715F, -0.032879319F,
        -0.00360439857F, -0.0273347553F, -0.0253432319F, -0.0837757F,
        -0.0576700531F, -0.0205714498F, -0.0727113262F, -0.0564484969F,
        0.0357622951F, -0.0496477522F, -0.0574317761F, -0.0345464908F,
        -0.0379497446F, -0.000227114535F, -0.0177101269F, -0.0458935276F,
        -0.0482414477F, 0.028249247F, 0.0712313876F, -0.013627314F,
        0.0442996956F, -0.0845634F, 0.0597047F, 0.0157057121F, -0.0331621207F,
        0.000221840048F, 0.11488416F, -0.0321752355F, 0.00987267587F,
        0.0878663138F, -0.0131317694F, -0.0222189836F, 0.0265982635F,
        -0.0265351441F, -0.00881384779F, 0.0104819071F, -0.0352310687F,
        -0.0709803775F, 0.0273037758F, 0.00722011784F, 0.0422484092F,
        0.0331591219F, -0.00526331365F, 0.0515489951F, 0.0115410183F,
        -0.0401345901F, 0.088553369F, -0.044800438F, 0.0836123675F,
        -0.0342078432F, -0.0355202854F, 0.0337368771F, -0.0437548347F,
        -0.0170186702F, -0.0252860058F, -0.0473181605F, 0.0444185287F,
        -0.0883245F, 0.0160324704F, 0.00923139136F, -0.000520585221F,
        0.0428414382F, -0.0468661301F, 0.0172100104F, -0.029833287F,
        0.0668634698F, 0.0856483355F, -0.0376138873F, 0.0187421087F,
        -0.00529883F, 0.0376319252F, -0.0340186544F, 0.053028658F,
        -0.0356057398F, 0.0747769326F, -0.0614516251F, -0.0269645434F,
        0.0192633662F, -0.101381764F, 0.0345569663F, -0.085551694F,
        -0.0273583923F, -0.0484966561F, 0.0234696083F, 0.0366045088F,
        -0.0504377708F, 0.0338636935F, -0.0283599589F, 0.111016981F,
        0.0589765795F, 0.023616178F, -0.0306601431F, 0.0465606749F, 0.116128743F,
        0.0218559913F, 0.0799092948F, 0.0391568765F, 0.0346214883F,
        -0.0188847445F, -0.038766861F, 0.0742468163F, -0.033863768F,
        0.0184534546F, 0.107178487F, 0.0434602536F, 0.00809621904F, 0.10848555F,
        0.0529157035F, -0.0550990514F, 0.0153749483F, 0.00894009788F,
        0.0848036557F, -0.0072891F, 0.0360785313F, -0.108231291F, 0.0583617613F,
        -0.0710959956F, -0.0190045293F, 0.0381082557F, -0.0120037338F,
        -0.0177997332F, 0.0263675023F, -0.0570060946F, 0.0432821102F,
        0.0820024908F, -0.0403412F, -0.0530982241F, 0.0973800346F, 0.0148391649F,
        0.0202089027F, 0.0736636F, -0.051713042F, -0.0811432749F, 0.0499805734F,
        -0.0310692675F, -0.0979131237F, -0.111972697F, -0.131134093F,
        -0.102440849F, -0.126837939F, -0.0681812838F, 0.0990318581F,
        -0.0988262743F, -0.0908368677F, -0.0659945682F, -0.00637408067F,
        -0.0332194F, -0.0918852612F, -0.0660652295F, -0.0790737644F,
        0.0127069987F, -0.0373692624F, 0.0737718642F, 0.0590896383F,
        -0.0462684333F, -0.0414469689F, -0.0876666084F, -0.0591347851F,
        0.0545924269F, 0.0361824036F, 0.124269903F, 0.0401178561F, 0.0202386342F,
        0.0204159F, 0.0302950386F, -0.0871356428F, 0.0373663865F, -0.0090082325F,
        0.0234408118F, -0.0620413348F, -0.0586045943F, 0.104109108F,
        -0.101135761F, 0.00107766804F, -0.0520757064F, -0.0128159551F,
        0.00619080104F, 0.129136577F, 0.0044760271F, -0.0705295056F,
        -0.0487695225F, 0.0956257F, -0.00423194841F, 0.0811409876F,
        -0.00623037666F, 0.0326963924F, -0.0150976134F, -0.0839355662F,
        -0.0835656822F, 0.0563241914F, 0.100709759F, -0.0717525557F,
        -0.0721705854F, 0.0101088546F, -0.0397209153F, 0.0726116598F,
        -0.00673837028F, 0.101581149F, 0.06302277F, 0.0688398182F, 0.0468831323F,
        -0.0238185991F, 0.0187188014F, -0.066662021F, -0.0683054179F,
        -0.0233574733F, 0.0043453835F, -0.124020271F, -0.0371186174F,
        -0.0237407349F, 0.100168444F, -0.119878344F, -0.025048105F,
        -0.116727889F, -0.00508699333F, 0.0368493497F, 0.0169464219F,
        -0.00307136355F, 0.0682001784F, 0.0184724778F, -0.0407030769F,
        0.0456433408F, 0.00822519F, -0.0383020192F, 0.0325573646F, 0.1027155F,
        0.095358938F, -0.00108833029F, 0.105778195F, -0.0566047318F,
        0.00780418282F, 0.0275755916F, -0.0494599193F, -0.0733323917F,
        0.0774934068F, 0.0871265903F, -0.0306920838F, 0.128408447F,
        0.000779148424F, -0.00318887644F, 0.0501439385F, 0.142902762F,
        0.124919564F, 0.0456123315F, -0.0736662075F, 0.0815786719F,
        -0.101212032F, 0.0771547481F, -0.0156276245F, -0.0115744136F, 0.0874616F,
        -0.00781640504F, 0.00413071644F, 0.0743528F, -0.00666923728F,
        -0.128298894F, -0.100167409F, -0.0356150828F, 0.0937066525F,
        -0.026668014F, 9.35667777E-6F, -0.038325686F, -0.0868846625F,
        0.000256088126F, 0.0554252379F, 0.0110693071F, -0.0294582341F,
        -0.0438495204F, -0.0413411371F, 0.0475142F, -0.0249859057F,
        -0.0364283286F, 0.0305341762F, 0.0723312497F, 0.106007963F,
        -0.0309810024F, 0.00367774535F, -0.0762506F, -0.0221878961F,
        -0.00654021604F, 0.0894613713F, -0.00828388613F, 0.0421701893F,
        0.00749397045F, 0.0385600738F, -0.049818F, 0.00174996071F, 0.105102465F,
        0.0982714072F, 0.0124365063F, 0.0495095775F, -0.0228088871F, 0.065286F,
        -0.0411382355F, 0.0762719736F, 0.0243888441F, 0.0452687517F,
        -0.000176756F, 0.0459075756F, -0.0192951262F, 0.045520179F,
        -0.0647597238F, -0.00339211524F, -0.00126304035F, 0.030902192F,
        -0.0286045428F, -0.059863653F, -0.00687284814F, -0.0795841143F,
        -0.0644978806F, -0.0355529152F, -0.0746728F, 0.0411766693F,
        -0.0966835544F, -0.0453264043F, -0.0468506142F, -0.0772212297F,
        -0.0714750439F, -0.0336187519F, -0.130325705F, -0.0252070669F,
        -0.0823417157F, 0.0699544474F, 0.0331976824F, -0.0122556249F,
        -0.0627899095F, -0.107237719F, -0.126771376F, 0.0391063951F,
        0.0122544104F, -0.00703557068F, -0.0243151411F, -0.061638F,
        0.0744294599F, -0.0806604F, 0.00906779803F, -0.0529313795F,
        -0.0653248504F, -0.00920129567F, 0.043057777F, 0.135737434F,
        0.038320519F, 0.0207724422F, 0.121276349F, 0.142209336F, 0.0417152F,
        0.115614004F, 0.00566292554F, -0.0440757498F, 0.0558771081F,
        0.0936562642F, -0.0780860633F, -0.0396348387F, 0.0474810787F,
        -0.0905818641F, 0.0748998523F, -0.0343562849F, -0.0835589096F,
        -0.0328614078F, 0.106685534F, 0.0125632752F, -0.0229904875F,
        0.0341470912F, 0.127484903F, -0.0461669117F, -0.0280850139F,
        -0.0186697319F, -0.0909623131F, -0.0407986678F, 0.0231024083F,
        0.0062068156F, -0.0138702476F, 0.0643672645F, -0.0569585189F,
        -0.0250167232F, 0.0588688068F, -0.0733449832F, 0.00739894528F,
        -0.0794057474F, 0.00511102751F, -0.0250678305F, -0.0978530571F,
        -0.0569445416F, -0.0269163214F, 0.0255646985F, -0.0275858119F,
        0.0171090346F, -0.0318480916F, 0.0143788317F, 0.0410524867F,
        -0.0324494652F, -0.0492527187F, 0.0148764979F, 0.042136956F,
        0.0990999788F, -0.0467560589F, 0.011084253F, 0.0131836813F,
        -0.0220659953F, -0.0888183936F, 0.0720648F, -0.018962102F, 0.0937202051F,
        0.00267337635F, 0.0972574577F, 0.0529702157F, 0.0726768374F,
        0.128241345F, 0.0282201879F, 0.125020549F, 0.0746342763F, 0.00812737644F,
        0.00119108916F, 0.0251767877F, 0.110261522F, -0.0293230899F,
        0.0690547302F, -0.0537683107F, -0.00796615F, 0.104064085F, 0.0788376778F,
        -0.0108646266F, -0.0591675751F, 0.0465356447F, 0.099317193F,
        0.00449583074F, -0.0679500848F, 0.0652477F, -0.0769653916F,
        -0.143787429F, 0.0025233156F, -0.069786936F, 0.00237002107F,
        -0.0591249391F, 0.0695609897F, -0.0172005408F, -0.0201985985F,
        0.143028125F, 0.0607630461F, 0.138822541F, 0.0283546038F, -0.100420132F,
        0.0164511129F, -0.0715917572F, -0.0324785709F, 0.0225845613F,
        -0.054847829F, -0.0595955476F, -0.0271502715F, -0.0956143141F,
        0.0615243651F, -0.0953794569F, 0.0276215337F, -0.04708983F,
        -0.0302502848F, -0.0477504954F, -0.00571608869F, -0.0734264106F,
        -0.0217700154F, 0.0347239822F, -0.131863937F, -0.103068382F,
        -0.0453738868F, -0.0512767658F, -0.103745267F, -0.0613463446F,
        0.0334027223F, 0.0274296552F, -0.0197021607F, -0.0560057797F,
        -0.0474050716F, -0.0663919821F, -0.00162511307F, -0.045777943F,
        0.0283946F, 0.0331367627F, -0.0267875474F, 0.010859577F, -0.0708451718F,
        -0.0137134595F, -0.0845190212F, 0.117240474F, 0.0550054647F,
        0.0861241147F, 0.0213061199F, 0.0140693728F, -0.00655647134F,
        0.0175148118F, -0.0469644368F, -0.103198878F, -0.0597001873F,
        0.0258857738F, 0.0531535558F, 0.112427779F, 0.0812888369F, 0.0124281114F,
        -0.0882411823F, 0.0314717256F, 0.0675861537F, 0.0772851631F,
        0.0381495655F, 0.0676714703F, -0.0870867223F, 0.0500950925F,
        0.102391653F, -0.0673958361F, -0.102446258F, -0.0881921053F,
        0.00494369678F, 0.0394849442F, 0.0148330862F, 0.0455149375F,
        -0.0608206168F, 0.044680804F, -0.0546286106F, -0.0035612951F,
        -0.0385905765F, -0.0044018128F, -0.033085037F, -0.0477700979F,
        0.0567095466F, -0.0641216636F, -0.0663388669F, 0.0124826729F,
        -0.0741339549F, -0.0234873015F, 0.0783792585F, -0.0254232734F,
        -0.0822138F, -0.023016138F, -0.027971141F, 0.0649171919F, 0.0714088306F,
        0.00994569622F, 0.0571952872F, 0.0614380203F, -0.0519808978F,
        0.0175395943F, 0.0174531974F, 0.0779089481F, -0.0339159593F,
        -0.118506119F, 0.0430621393F, 0.0889955834F, -0.0650358275F,
        0.0376152657F, 0.0385556743F, 0.086488992F, -0.0325011089F,
        0.0982925296F, -0.0672249198F, 0.109506197F, -0.0414265208F,
        0.018205842F, 0.0599060021F, 0.0614822917F, -0.0726072565F, 0.100536346F,
        -0.0422452651F, -0.0543029495F, -0.0984804779F, -0.0210830029F,
        0.111282401F, -0.0206175428F, -0.0330827348F, 0.0162662119F,
        -0.0682277232F, 0.0551245175F, 0.0311179236F, -0.0263483599F,
        -0.0942268819F, -0.0518268086F, 0.00692242384F, -0.00243653404F,
        0.0800416395F, -0.0098037F, -0.120528594F, 0.0717090592F, -0.0770750567F,
        -0.0293999594F, 0.0671909899F, 0.0318700783F, 0.00113239279F,
        0.0533956289F, -0.0402194783F, -0.0201935209F, 0.0635310039F,
        0.0119300317F, 0.0676060766F, 0.0330472328F, 0.043896582F,
        -0.0319560096F, -0.000848360069F, -0.0838634F, 0.0570829846F,
        -0.0537711792F, -0.044255238F, 0.0148816947F, -0.0488517582F,
        -0.0489059426F, 0.0143193882F, -0.087356329F, -0.0116245402F,
        -0.0450222306F, -0.0510213412F, -0.035470102F, 0.0243026763F,
        -0.0985408276F, -0.116994552F, 0.067459546F, -0.0515022F, -0.0602305345F,
        0.0107898377F, -0.0542296395F, 0.0520919077F, -0.0183759537F,
        0.0511065535F, 0.0324823484F, 0.0348665416F, -0.116006978F,
        0.0383057296F, -0.0451032594F, -0.00368725369F, -0.0155447926F,
        0.0620843582F, -0.0364929549F, 0.00355996704F, -0.0626212284F,
        -0.095836781F, -0.0958670229F, -0.00515633449F, 0.0621483475F,
        -0.00986075774F, 0.00102161174F, 0.0563376136F, -0.0899807811F,
        -0.0677408725F, 0.0200595446F, 0.0389162935F, -0.0238123015F,
        -0.0979669467F, -0.0639300272F, -0.0743026435F, -0.0483102426F,
        -0.0481488556F, -0.0469718128F, 0.0457985848F, -0.0037314177F,
        0.0204868782F, 0.0426459722F, 0.0895612761F, -0.0497219563F,
        -0.0369882435F, 0.0255103465F, -0.0134859774F, 0.0299398378F,
        0.0280122552F, 0.0384735353F, 0.0607611388F, 0.0621803887F,
        -0.00444201799F, -0.0931478068F, -0.0858323F, 0.022995539F,
        0.0306675155F, -0.0745220184F, -0.000672091439F, -0.030252235F,
        0.0638349131F, 0.0362840965F, -0.0437888131F, 0.0316045359F,
        0.00972121675F, 0.0720858F, -0.0403079502F, 0.0505753383F,
        -0.0720874816F, 0.0406821221F, -0.119507648F, -0.071302779F,
        -0.0584094822F, 0.0458785966F, -0.00418950943F, 0.0428335F,
        0.0450305603F, -0.0315709226F, -0.0314558856F, -0.0373898447F,
        -0.00571133941F, 0.0401044488F, -0.0315833502F, -0.0202572532F,
        0.0771682709F, -0.0655950308F, -0.0558550097F, 0.0624580868F,
        -0.00327143027F, -0.0558034778F, 0.0678898096F, -0.0758182928F,
        0.117620423F, 0.0944588408F, -0.0456701964F, 0.111244038F, -0.063117452F,
        -0.0145787029F, 0.0353769176F, 0.0661109313F, 0.00752359722F,
        0.0664384738F, -0.0999967456F, 0.0307792667F, -0.0405542776F,
        0.028826382F, -0.0323056355F, -0.0712961629F, 0.101003833F,
        -0.0846413448F, -0.0174147859F, -0.00558750657F, 0.0257766116F,
        0.0406310335F, -0.0817520693F, 0.0638191923F, 0.0345914885F,
        0.0226076562F, -0.10274896F, -0.0501308702F, -0.0778252482F, 0.0700691F,
        -0.0189645793F, 0.0286768265F, -0.0432621129F, -0.067128174F,
        0.00239589042F, -0.0386354662F, -0.0238862485F, 0.10644377F,
        -0.00679519167F, 0.0312145632F, 0.000416490017F, -0.0388239846F,
        0.098948136F, -0.0609050021F, 0.0650842562F, -0.0759668648F,
        -0.0548191592F, -0.0115444716F, -0.0326919593F, 0.0297234077F,
        -0.0750808269F, 0.0742071F, -0.00704878755F, 0.0877241045F,
        0.0805801824F, -0.0186947081F, -0.0684451386F, -0.0712864548F,
        0.0443067402F, -0.0771428123F, -0.063484706F, -0.00649599545F,
        0.0395526215F, 0.0471551046F, -0.0664430559F, 0.0634022951F,
        0.028645711F, 0.0715868175F, 0.107567772F, 0.0195596907F, 0.08867044F,
        0.0428769626F, 0.0588242337F, 0.00472635357F, -0.049102433F,
        0.018417567F, 0.0560103133F, -0.0303688105F, 0.037567459F, 0.0543292686F,
        0.0334945433F, 0.0157751739F, -0.0556221493F, 0.0330702F, 0.0735316724F,
        -0.0148918657F, 0.0429540947F, -0.0591174848F, 0.00242846692F,
        -0.0313323066F, 0.0881926F, -0.0119957281F, -0.00161229121F,
        0.0879846513F, -0.00979999453F, 0.0300859027F, -0.0116615826F,
        -0.0405151211F, -0.00636197347F, -0.0967993736F, -0.112316005F,
        -0.0327323F, 0.103383973F, -0.0518049113F, 0.0601146892F, -0.0226330366F,
        -0.104054689F, -0.0127310948F, 0.0374156311F, -0.00424411753F,
        0.0150550595F, 0.00463321619F, 0.112989776F, 0.112149611F,
        -0.0463890284F, -0.0231479891F, 0.111863688F, 0.0201820061F,
        -0.0568827949F, -0.0788884759F, -0.0463851206F, 0.0348691866F,
        0.0402262919F, 0.0481935851F, -0.0331030674F, -0.0030881397F,
        -0.0677215904F, 0.00339888735F, -0.0298350491F, 0.0497740731F,
        0.0726333559F, -0.106566496F, 0.0515129752F, 0.102583908F,
        0.00482460205F, 0.0310171377F, 0.0782044902F, -0.0388584957F,
        -0.00625373702F, -0.0159014724F, -0.0399136469F, -0.0461373739F,
        0.0509619117F, 0.0669364631F, 0.118223473F, 0.114430189F, -0.0145015167F,
        -0.102900714F, 0.0900313109F, 0.0285534393F, -0.0233102422F,
        0.0536947101F, -0.0539106503F, 0.0281232353F, -0.0294278599F,
        0.0529053435F, 0.034587048F, -0.137710646F, -0.114872701F,
        -0.0639286041F, -0.0280866325F, -0.0607480034F, -0.102538757F,
        -0.101004407F, 0.0193667989F, 0.00294007733F, 0.0385084674F,
        -0.0158945713F, -0.0973189F, -0.0969911292F, -0.106874608F,
        -0.0748775154F, -0.0491657332F, -0.0574581586F, 0.00574921258F,
        -0.0874298587F, 0.0526588745F, 0.0304687303F, -0.0767862126F,
        -0.037525285F, -0.0259781219F, -0.040172413F, 0.0620205887F,
        -0.0488594547F, -0.0580868386F, -0.0331222638F, -0.0833288953F,
        -0.0236428399F, 0.0283663832F, 0.0370782688F, 0.0791117772F,
        -0.0841639712F, 0.0375492275F, -0.0276413597F, 0.043183554F,
        0.0167524423F, 0.0184395574F, 0.035506621F, -0.0574653633F,
        0.0683220327F, -0.0234975405F, -0.0237131547F, -0.0100082923F,
        0.0588632F, 0.0762402788F, 0.0968052745F, -0.00435500639F, 0.0294197872F,
        -0.0151569676F, -0.0365917124F, 0.0245943945F, -0.0232781693F,
        -0.0540332049F, -0.0685083047F, -0.092704758F, 0.0353234634F,
        -0.0134367067F, -0.018199956F, 0.0461366475F, -0.0209835675F,
        0.0999377593F, 0.0829085857F, -0.0248026643F, -0.0246555042F,
        -0.0359582305F, -0.0165131651F, 0.0896044F, -0.0733402222F,
        -0.0342791043F, -0.0666956827F, -0.0395830534F, 0.0865782201F,
        -0.0253941976F, -0.0703711F, -0.0996030793F, -0.063415885F,
        -0.0184610412F, -0.0636651143F, 0.0363923125F, -0.0449107885F,
        -0.0398182608F, 0.0784938931F, -0.0302447379F, 0.0388263203F,
        -0.0591677688F, 0.0213972516F, 0.070292823F, 0.00326008862F,
        0.038415011F, 0.0439637415F, 0.0312303025F, -0.109335758F, 0.0821288079F,
        0.0048408322F, -0.00513621652F, -0.118839473F, 0.0547866039F,
        0.0942591801F, 0.0226288065F, -0.0159143563F, -0.0398998223F,
        0.0189755037F, 0.0699989945F, 0.040367052F, -0.0429943316F,
        0.0284411833F, 0.0225189701F, -0.055665914F, 0.0634301379F,
        0.0616242476F, 0.0495822206F, -0.0288692433F, 0.0655578822F,
        0.111584492F, 0.0355494954F, 0.028000176F, -0.0616398379F, 0.0399332941F,
        -0.0974272117F, 0.0586961769F, -0.0481154174F, 0.0444786586F,
        0.0104309311F, 0.00860088691F, 0.0536021218F, -0.0174922161F,
        0.0976476595F, 0.0450813472F, -0.0318152122F, 0.063214466F,
        0.00820345245F, 0.0131835751F, 0.0458104871F, 0.0372194F, -0.0175915062F,
        -0.0900519341F, -0.0965255573F, -0.00361276441F, -0.0369962491F,
        -0.051952567F, -0.0208964422F, -0.0712322891F, -0.0149416849F,
        -0.0858918428F, 0.0665711686F, 0.0282794032F, -0.0365863666F,
        -0.0679670423F, 0.0327199399F, -0.00333389291F, 0.0505829491F,
        0.0191276129F, -0.040908318F, 0.0645783618F, -0.10526371F, 0.0114478925F,
        0.0722203553F, -0.0513220131F, -0.0382691696F, 0.089507252F,
        -0.0535836667F, -0.0719302222F, -0.0499540903F, -0.0735927522F,
        -0.0313607082F, -0.053133335F, -0.0579869635F, -0.0187617932F,
        0.0703144372F, -0.132587329F, -0.101867191F, 0.0290801637F,
        0.0355511568F, 0.0161582511F, 0.0186279062F, -0.0278510451F,
        -0.0157103837F, 0.0274104606F, -0.0294533838F, 0.0669538081F,
        0.0523968078F, 0.00736733666F, 0.100981116F, -0.0472659618F,
        0.00792476069F, 0.0335291401F, -0.0438281558F, -0.067767404F, 0.0328802F,
        -0.0181612819F, 0.152794421F, 0.0398719162F, 0.112317353F, 0.122418486F,
        0.01275336F, -0.0465220511F, -0.0576327108F, 0.00404902035F,
        0.109189264F, 0.0443109497F, -0.0244352967F, -0.0178195164F,
        -0.115097523F, 0.0871636122F, 0.0956464261F, 0.0726239383F,
        0.00395745737F, -0.00222527981F, -0.0119716134F, 0.00693286024F,
        0.016402876F, -0.106797405F, -0.111617111F, 0.0230757687F, 0.0903357938F,
        0.0371366739F, -0.046418611F, 0.00814729184F, -0.0214837603F,
        0.0473068208F, -0.0445895903F, 0.0531382859F, 0.0535073616F,
        0.0125327511F, 0.0389023684F, 0.0402048379F, 0.00832894258F,
        0.0165270194F, 0.0523374565F, -0.0448910445F, 0.0535129979F,
        -0.0825526714F, -0.0189186651F, -0.06778723F, 0.00516940141F,
        -0.0979740769F, -0.0665208399F, -0.10756319F, -0.0499752872F,
        -0.00328470441F, -0.0737416893F, 0.0964852F, -0.0306367837F,
        -0.019320935F, 0.115544252F, 0.0135187861F, 0.0948978588F, 0.0632852092F,
        0.114614047F, -0.0372182801F, -0.133383542F, 0.0202087481F,
        0.000335044198F, -0.0301140528F, -0.0170114134F, 0.0911775157F,
        0.0667837039F, 0.0657953322F, 0.0219395515F, -0.0713636726F,
        -0.0344133563F, 0.0397635959F, 0.0498724952F, 0.0258645788F,
        0.0155034056F, 0.0909095258F, -0.0608854927F, 0.0792124942F,
        0.0484144092F, 0.0328731686F, 0.00138689438F, 0.0304900594F,
        -0.00236927392F, 0.0658729374F, -0.0465541668F, -0.0434450023F,
        0.0847350284F, 0.032371968F, 0.0817294642F, -0.0100546507F,
        -0.0541778207F, 0.0373059511F, 0.021524081F, 0.0427953079F, -0.0707172F,
        -0.0277981721F, -0.102104947F, 0.0245529767F, -0.0286632609F,
        0.0175695568F, 0.0301925093F, -0.0838940218F, 0.0101961363F,
        0.0729792267F, -0.0353559293F, -0.0639471859F, 0.0182405729F,
        -0.0635206476F, 0.0285596382F, -0.0302971713F, 0.0856619328F,
        -0.0420675F, -0.0477202497F, 0.00424928125F, -0.0629367083F,
        -0.00240041711F, -0.0191879421F, 0.0148625737F, 0.063863039F,
        0.0227368847F, -0.00206112885F, 0.011325229F, 0.0489532761F,
        0.0555793755F, -0.0635435581F, 0.0780166164F, 0.071441412F,
        -0.0697571188F, -0.0344001129F, 0.0115126502F, 0.0281757377F,
        0.058814358F, 0.0403265767F, -0.00646075746F, 0.00389839732F, 0.0557804F,
        -0.00883139484F, 0.0639981776F, -0.0903378725F, 0.0587347336F,
        -0.0365763605F, -0.0365933888F, -0.0722692534F, -0.0640833527F,
        -0.0317087546F, 0.00164205208F, -0.0557771362F, 0.0252343509F,
        0.0558066629F, -0.00073469145F, 0.0599342845F, 0.0502938926F,
        0.0736513361F, 0.0576249734F, 0.0492469594F, -0.061399322F,
        0.0462869294F, -0.0457611382F, -0.00160577288F, -0.0333038755F,
        -0.0756096095F, -0.017545972F, -0.0795351416F, -0.00472250441F,
        0.0506843589F, 0.0269768648F, 0.0595005378F, 0.021574961F,
        -0.0766852573F, 0.0234416034F, -0.0517365746F, 0.0436233059F,
        0.00571401184F, -0.0210584663F, 0.0710433275F, -0.0722644925F,
        0.00846092403F, -0.00023503491F, -0.066531077F, -0.0599634759F,
        -0.0973480046F, -0.0572029538F, -0.0441260934F, 0.000950999849F,
        -0.0552037321F, -0.0416600965F, -0.0106339259F, 0.0326808318F,
        -0.0465965085F, -0.0305958223F, 0.0397294834F, -0.0123593519F,
        -0.0614737049F, 0.0848980248F, 0.00235678442F, -0.0755455F,
        -0.0721317381F, -0.0146462852F, -0.0744041726F, 0.0434085801F,
        -0.0358580649F, -0.00182294182F, -0.0443589911F, 0.0155751817F,
        0.0179051179F, -0.014221401F, -0.0414664261F, 0.0531525724F,
        0.0541721173F, 0.0142575987F, 0.0335607119F, -0.048354663F,
        -0.0679589659F, 0.0475311875F, -0.0602129623F, -0.0405252129F,
        0.035871774F, -0.0854177549F, -0.0656409413F, -0.0930756852F,
        0.0282989517F, -0.041194357F, 0.0247518681F, -0.0700009838F,
        0.0885109678F, 0.0178859551F, 0.0372620299F, 0.0111847054F,
        -0.0877687484F, -0.0305755939F, -0.00149930723F, -0.0390305519F,
        0.0268937889F, 0.0117744394F, -0.0422127843F, 0.0256672855F,
        0.0117965024F, 0.0624157786F, 0.0544238426F, 0.0408631749F,
        0.0350132436F, 0.057236407F, -0.0906632F, 0.0489591509F, -0.0132900672F,
        -0.0817961395F, -0.0660825744F, -0.0611485764F, 0.0213828012F,
        0.0666695833F, -0.0561035089F, -0.0918885395F, -0.0376601331F,
        -0.00984959863F, -0.00980458595F, -0.0448148064F, 0.0717955902F,
        -0.0236999188F, -0.0618862435F, -0.0123802796F, -0.0472870246F,
        0.0718361735F, 0.0417349488F, 0.0999018177F, -0.0708581433F,
        0.0497663468F, -0.0786795616F, 0.0368992947F, -0.0226771291F,
        0.00513941469F, 0.0954500586F, -0.0510575362F, 0.0483714156F,
        -0.0775224F, 0.0179492142F, 0.0890366659F, -0.0469398275F,
        0.00338732661F, 0.00448862F, -0.0296447109F, 0.0633603185F,
        -0.00367958704F, 0.0107557541F, -0.0747545809F, -0.00844197161F,
        0.0428793095F, -0.0275151506F, 0.00438348902F, 0.00724882539F,
        -0.011573703F, -0.0896201432F, -0.0197054911F, 0.0760325268F,
        -0.0125153493F, -0.0799030736F, 0.0727541149F, -0.025898356F,
        0.066795975F, -0.0880379453F, 0.0403938331F, 0.0249724481F,
        -5.39212488E-6F, -0.0260995142F, -0.101743713F, -0.104568899F,
        0.017892886F, 0.0483268388F, 0.00590691203F, -0.0460580178F,
        0.00700619118F, 0.101111405F, -0.020750355F, -0.0740373433F,
        0.0353845395F, 0.025770478F, -0.0844161585F, -0.000124773214F,
        -0.00126576645F, 0.0423823483F, -0.019154707F, 0.0219365135F,
        -0.0803105906F, -0.0145468488F, 0.000443509605F, -0.0318863317F,
        -0.0737808868F, 0.0690715F, 0.0379357971F, -0.00516232057F,
        0.0671904683F, -0.0264694449F, 0.062965855F, 0.0494924784F,
        0.0308917053F, 0.0338879786F, -0.00305639859F, -0.07133995F,
        0.0370213799F, 0.041048497F, -0.0454086289F, 0.0580995604F,
        0.0457675196F, -0.0349996239F, 0.030127639F, -0.058304023F,
        -0.0481038503F, -0.0020286683F, 0.0449222364F, 0.0609281175F,
        0.0773944184F, 0.0406570956F, -0.0653565302F, -0.0854641348F,
        -0.00587622076F, -0.0770565048F, -0.0157762971F, 0.0420194864F,
        0.0119830882F, 0.0362897627F, -0.0677244142F, -0.0426675491F,
        0.0650338233F, 0.0290489774F, 0.0555408522F, -0.0759458467F,
        -0.0215932168F, -0.0175136682F, -0.0544919707F, -0.0472098179F,
        -0.0634211376F, -0.089487344F, -0.0093089221F, -0.0578256808F,
        0.0410311222F, 0.0829247385F, 0.0390179045F, -0.0437785238F,
        0.0361277685F, -0.0663013384F, 0.0512468815F, -0.0280394983F,
        -0.0169922188F, 0.0910614878F, 0.0593006052F, -0.0449678116F,
        0.0328724496F, 0.0160407946F, 0.0861063451F, -0.00965787098F,
        -0.0837622955F, 0.0190511812F, 0.0450529829F, 0.0349252187F,
        0.0416826457F, 0.024758365F, 0.0362261087F, -0.040472243F,
        -0.0636162609F, 0.00473701488F, 0.0151804024F, 0.016747063F,
        -0.0733157173F, 0.0164645F, 0.0203101579F, 0.0578994453F,
        -0.00503899343F, 0.00375610939F, -0.0964300856F, 0.00608677045F,
        0.0736376867F, -0.0170550589F, 0.117661133F, 0.0264898613F,
        -0.0168085787F, -0.0331671722F, -0.0871065F, 0.016434839F, 0.0350390114F,
        -0.0738065392F, -0.104075707F, 0.052514188F, -0.130936965F,
        0.0506442152F, -0.010864337F, -0.00085904164F, 0.0167465694F,
        0.0504349098F, -0.0129282912F, -0.0241877269F, -0.058053311F,
        -0.0421191081F, -0.0325861834F, 0.0418696254F, -0.0390168615F,
        -0.0738263726F, -0.038729351F, -0.0881047249F, -0.0342524201F,
        0.0827898532F, 0.0915416479F, -0.00774808042F, 0.0533809699F,
        -0.0466416925F, -0.0846546739F, 0.076957345F, -0.0468792543F,
        -0.0576776117F, 0.093053259F, 0.047862675F, -0.0880628154F,
        -0.0131223919F, 0.0537346825F, 0.0367212892F, 0.0811687037F,
        0.0336752534F, -0.00182562775F, -0.00354092498F, -0.0387680158F,
        -0.0418160744F, -0.024557054F, 0.0169757567F, 0.0853937343F,
        -0.00137780758F, -0.0540627353F, -0.0879005641F, 0.09840177F, -0.085448F,
        -0.137497202F, 0.0110304095F, -0.0157894231F, 0.0448424444F,
        0.0301368982F, -0.127137288F, -0.0859355852F, 0.00615722686F,
        -0.0519559346F, -0.0498292632F, 0.0830599815F, -0.0821640939F,
        0.00337598892F, -0.031548325F, 0.0239031892F, 0.0526768118F,
        -0.085197255F, -0.00489386497F, 0.0367227644F, 0.0265662596F,
        0.06585107F, -0.0599401221F, 0.00506811589F, 0.053428337F, 0.07169386F,
        0.130419567F, 0.0957907513F, 0.00683821598F, -0.000230032107F,
        0.0540181622F, -0.0580642484F, -0.0827756673F, -0.0648814216F,
        0.0822054744F, 0.0334382169F, 0.0625444651F, -0.0975234658F,
        0.0405621827F, 0.0152552146F, 0.0737116411F, 0.0745511949F,
        0.0159456059F, 0.0755311325F, 0.0892847106F, -0.0261459649F,
        0.0281312261F, 0.0497052819F, -0.00423424691F, 0.0320751145F,
        0.00643599452F, -0.0279160347F, 0.0211066641F, 0.0678428635F,
        -0.00913581159F, 0.0378243066F, 0.0931838751F, -0.00458083F,
        -0.040133357F, -0.0215214323F, -0.00141102634F, 0.0885188654F,
        -0.0449001305F, -0.000662852195F, -0.0775850788F, -0.104209751F,
        0.0214325991F, 0.0224061962F, 0.0151637755F, -0.038537968F, -0.0145985F,
        0.00988802F, -0.0162116922F, 0.00439006044F, 0.024859244F, 0.0164721869F,
        -0.0749176592F, 0.0697940141F, -0.0187069587F, 0.00730235176F,
        -0.0214003678F, -0.0850273743F, 0.0172873028F, 0.102620177F,
        -0.0757629871F, -0.0527785793F, 0.0472022258F, -0.0684114695F,
        -0.150388435F, -0.00630886387F, 0.116026692F, -0.00827681366F,
        -0.0119493F, -0.0966312364F, -0.105444305F, -0.0199277215F,
        -0.0403951108F, -0.0977731347F, -0.131311446F, -0.0147082955F,
        -0.0951071903F, 0.0393750742F, -0.0545960888F, -0.0151579631F,
        -0.0101234531F, 0.0231440198F, -0.101871826F, -0.0330399759F,
        -0.0401268192F, -0.0252273399F, 0.00513348635F, 0.00920810178F,
        -0.110564403F, -0.116741933F, 0.00920606125F, 0.081073679F,
        -0.0285151228F, -0.0551379882F, -0.0867034346F, 0.0733990371F,
        0.00513213687F, 0.00781895593F, -0.0233029276F, 0.0635909885F,
        0.0470581353F, -0.0040333597F, -0.0322533324F, -0.0865659043F,
        0.0762818158F, -0.0345019288F, 0.113531366F, -0.0502923392F,
        -0.036609821F, 0.012019123F, -0.00635525445F, 0.0369224101F,
        0.0613928102F, 0.0559387505F, 0.00568251871F, 0.00682834163F,
        -0.055368185F, -0.04217951F, -0.000452392822F, -0.11892131F,
        0.00325397588F, -0.00356627442F, -0.0376678593F, 0.023595931F,
        -0.0990447104F, 0.0239716452F, -0.0665795207F, -0.0662652254F,
        -0.0155868148F, -0.0246310588F, -0.00203821599F, -0.0259044487F,
        0.00886641536F, 0.0545592308F, -0.0212347675F, -0.0673297867F,
        -0.0245354585F, -0.0459872894F, 0.03181912F, -0.0611007251F,
        -0.0677531138F, 0.101387843F, 0.0783117265F, -0.00127199409F,
        0.0576613322F, -0.0821848F, 0.0750230849F, 0.0174506642F, 0.0519410707F,
        -0.061760556F, -0.0460984483F, 0.0712433085F, 0.0232445542F,
        -0.0593478829F, -0.0188332181F, 0.0735504702F, -0.00515887F,
        0.0125571666F, 0.0455914102F, -0.0128069995F, -0.00507071614F,
        -0.0514475778F, 0.00477056811F, -0.047604844F, 0.0181347169F,
        0.000765353092F, -0.0330514759F, 0.0393999703F, 0.00074495509F,
        -0.0429893285F, 0.0493575893F, 0.0866176635F, -0.0143481651F,
        -0.0142373443F, -0.120945036F, -0.0644987F, -0.07341104F, 0.00200094935F,
        0.019889541F, 0.0619457178F, -0.0123353601F, -0.0516225286F,
        -0.0764588416F, 0.0501777828F, -0.0363563411F, -0.136281371F,
        0.0930707529F, -0.0522413F, -0.0323290415F, -0.0534668379F,
        -0.00980637316F, 0.0125400703F, -0.0121250963F, 0.0246780831F,
        -0.0310962368F, 0.0804815665F, -0.0216095597F, 0.097406812F,
        0.0185875446F, 0.0941131264F, 0.0144384429F, -0.043154832F,
        0.0296540949F, -0.0955937058F, 0.007354517F, -0.0321745463F,
        0.0210631918F, 0.0315522328F, -0.101169311F, -0.034938F, -0.0237797461F,
        -0.0241381675F, -0.0345384F, -0.0420625061F, -0.0605220571F,
        0.0353925526F, -0.0748757273F, -0.095033668F, 0.0234651025F,
        -0.0447299145F, -0.0469057932F, -0.0593627058F, 0.0232233703F,
        0.0340298191F, -0.0598736F, -0.0859380215F, -0.101709865F, 0.017614834F,
        0.0432999767F, 0.0144806709F, 0.0322743542F, 0.0396448746F,
        -0.0572946444F, -0.022135945F, 0.0203607511F, 0.0470301621F,
        0.0378172435F, 0.0818537697F, -0.0579884872F, 0.0659532771F,
        0.100601099F, 0.0494588464F, -0.0412181206F, 0.0151727628F,
        0.00183255342F, 0.00554136187F, 0.0805915669F, -0.0047248858F,
        -0.0343634635F, -0.0149969235F, 0.101164542F, 0.0146970581F,
        -0.0592538156F, -0.0485279746F, -0.038271334F, -0.0140969688F,
        -0.0298236459F, -0.0193755962F, -0.0590983927F, 0.0392517522F,
        0.0859500095F, 0.104867622F, -0.0149932988F, 0.0495357662F,
        -0.00134527823F, -0.0770962462F, 0.0895395F, 8.67720373E-5F,
        -0.00150513707F, -0.0572226457F, -0.0620939955F, 0.0534513071F,
        -0.0955706388F, -0.0661752522F, -0.0950414911F, 0.0495809726F,
        -0.0266211126F, -0.0563453287F, 0.0284062345F, 0.0522425734F,
        -0.088297613F, -0.0279463418F, -0.0328913108F, -0.0740393326F,
        -0.0241947863F, 0.0217534546F, 0.0363847464F, 0.0387153849F,
        0.101053394F, 0.0139317987F, -0.0642063171F, -0.0107243201F, 0.04543126F,
        0.0269009341F, 0.00320174661F, -0.0492629409F, -0.0603056848F,
        0.0360882357F, 0.0161164366F, -0.101345122F, 0.0368116684F,
        -0.0798895881F, -0.0062813675F, -0.0197928585F, 0.0664230138F,
        -0.0778286681F, 0.0389336795F, 0.0705026388F, 0.0834992751F,
        0.101783901F, 0.131779566F, -0.0355657302F, -0.0654878691F,
        0.0499529429F, -0.0505582802F, -0.0840977654F, 0.0927336216F,
        0.0415606238F, -0.0665315762F, -0.0176728F, 0.0135936607F, 0.0556935892F,
        -0.046087116F, -0.0198107436F, -0.0266207419F, -0.00885320362F,
        0.0182231013F, 0.108616702F, -0.0511112288F, -0.0814523771F,
        0.0875849426F, -0.131210878F, -0.0802045614F, 0.0305851903F,
        0.00231571798F, 0.0568827689F, -0.024925096F, 0.121269293F,
        0.0172017328F, 0.00357986521F, 0.0449400917F, -0.0362504087F,
        0.0681514665F, -0.105217598F, -0.0727959499F, 0.00732183829F,
        -0.029593505F, -0.126454651F, -0.0663127229F, 0.0694821402F,
        -0.00988899823F, 0.0353612378F, -0.0187432598F, 0.0360877775F,
        0.00865597F, -0.0184223391F, 0.00641358225F, 0.0428396612F,
        -0.0844386667F, 0.00209915382F, -0.0769714192F, -0.0679408312F,
        0.0180909075F, -0.117912821F, -0.0658355653F, -0.0217017587F,
        -0.0861875713F, -0.0506610572F, -0.0846257135F, -0.0101157334F,
        0.0194648039F, -0.102515124F, -0.0432578549F, 0.0405891873F,
        -0.073648639F, 0.00792618934F, -0.0880963877F, -0.089287661F,
        0.0334815606F, 0.0413607582F, 0.0448326617F, 0.0243735071F,
        0.0150355035F, -0.0715979412F, -0.0115317935F, 0.0414624214F,
        0.00351492385F, 0.0919030756F, 0.0298708137F, -0.0347298309F,
        0.114560254F, 0.0552971549F, -0.108882017F, 0.0494380929F,
        -0.0380251519F, 0.0550618581F, -0.108674407F, 0.0492566861F,
        0.0743096769F, -0.00741009926F, 0.059895575F, 0.129109755F,
        -0.0109158885F, 0.0860695615F, -0.0353225619F, -0.100796446F,
        -0.0208155792F, -0.0983023196F, -0.0691562F, 0.0817445442F, 0.019439945F,
        -0.147578344F, -0.0765935779F, -0.0228366703F, -0.0111753559F,
        -0.0690224543F, -0.0501793101F, 0.00958129F, -0.0958447754F,
        0.111968696F, 0.0737856403F, 0.0046439413F, -0.0554887429F,
        -0.0414234921F, -0.0958843902F, 0.00976546854F, -0.0923852324F,
        -0.10063713F, -0.105531022F, 0.0204971228F, 0.114334174F, -0.0859684795F,
        0.0751236752F, 0.0707344562F, -0.104975343F, 0.106302582F,
        -0.0121285152F, -0.10535913F, 0.0144666014F, -0.00763082551F,
        -0.110166647F, -0.0586783625F, 0.0351554789F, -0.00105509895F,
        -0.0467346236F, 0.0261090919F, -0.0368079096F, 0.106855556F,
        0.0447964147F, 0.0757990107F, -0.0391522311F, 0.0731216744F,
        0.0568962432F, -0.0558591F, -0.0338032395F, 0.104505405F, -0.0369327776F,
        0.0881487727F, 0.081774056F, -0.0159997214F, 0.0497041941F,
        -0.0509454161F, 0.0356268808F, 0.0605808273F, 0.0480686054F,
        0.0111683309F, -0.014818131F, 0.0493223369F, 0.0273911804F,
        -0.0360399783F, -0.031785585F, -0.0655927956F, -0.00308192545F,
        -0.0536579899F, 0.011812089F, -0.0321076736F, -0.0216215812F,
        0.0138921458F, -0.0326046459F, -0.0620226376F, -0.073946625F,
        -0.0103207622F, -0.0164858475F, 0.0375237055F, 0.0528757833F,
        -0.0686665624F, -0.0863267F, -0.0468283221F, -0.00395642407F,
        -0.0907539F, 0.0542874411F, -0.0826065913F, -0.0218895171F,
        0.0182377603F, 4.64732075E-5F, -0.0416292921F, -0.0509799384F,
        0.00327482028F, -0.0375057235F, -0.0619220175F, -0.0837366134F,
        -0.068940632F, -0.0657149181F, -0.0160748959F, -0.034400709F,
        0.0212548152F, 0.0131054074F, 0.00791751686F, -0.0847733319F,
        -0.120521411F, 0.030728247F, -0.00260516116F, -0.0747086108F,
        -0.00155826751F, -0.0103609078F, 0.00799712166F, -0.0174863581F,
        -0.0848102123F, -0.0236248802F, -0.0740272775F, 0.0107037034F,
        -0.10103634F, -0.024493495F, -0.0408771709F, 0.0127212834F,
        0.00328799104F, -0.0489885509F, 0.0516886152F, -0.0564692244F,
        0.0286457241F, -0.0235659182F, 0.0297770556F, 0.00943592843F,
        -0.069068253F, 0.0403430536F, -0.0450956523F, -0.0349496789F,
        -0.0273525678F, 0.0378401354F, -0.0374111496F, -0.0215890687F,
        0.0307724513F, -0.0253299866F, -0.108251929F, -0.138846859F,
        0.015829334F, -0.0304200705F, -0.00153058034F, -0.0158165414F,
        -0.0557957515F, 0.018274989F, -0.0454802066F, -0.0777673423F,
        -0.0227673F, -0.084825024F, -0.0871341527F, 0.0107562644F, -0.085227415F,
        -0.00222099805F, -0.0586836487F, 0.0650483668F, -0.0591867119F,
        0.0864535794F, -0.0491487347F, -0.0392719842F, 0.0710153505F,
        -0.0424417481F, -0.0312692784F, -0.0526558906F, 0.0586777329F,
        0.0405511707F, -0.0486940034F, -0.00336765475F, -0.0699444488F,
        0.0130113568F, -0.051027786F, -0.060903158F, 0.0510835424F,
        0.00480541633F, -0.0132647259F, -0.0923808813F, 0.0182662103F,
        -0.0975257233F, 0.00597096886F, -0.0698109344F, -0.0234898329F,
        0.0525700413F, -0.00564094866F, -0.0336081833F, 0.0593143515F,
        -0.0682241619F, -0.0568079874F, -0.0433049202F, -0.0376632623F,
        0.0516702607F, 0.0390699767F, -0.0258418713F, 0.0865018144F,
        0.0269179326F, -0.0714783818F, -0.00467280624F, 0.0144857951F,
        -0.0367499813F, 0.066473484F, 0.0619839802F, 0.0906683058F,
        -0.0516111702F, -0.00132767635F, -0.0151241468F, 0.0164252985F,
        -0.0569005981F, -0.0624645241F, -0.058256492F, 0.0346163772F,
        0.107057787F, -0.0742681399F, 0.134251907F, 0.0720415562F, 0.0432649292F,
        0.123099536F, 0.04176943F, -0.0213964339F, 0.0656282306F, 0.0222637318F,
        -0.0508587025F, -0.032789316F, -0.0430824123F, 0.0722737536F,
        0.0492994487F, 0.0496472605F, -0.00267496775F, 0.0154363476F,
        -0.0240069572F, -0.060747005F, -0.0418463461F, -0.0256422069F,
        -0.0424713343F, 0.0190387722F, -0.0435848683F, -0.0915354267F,
        -0.0993357301F, 0.0211787429F, -0.106927F, -0.0419899225F,
        -0.0804253072F, -0.0642360598F, -0.0732139871F, -0.0798227116F,
        0.0402115248F, 0.0103567764F, -0.0187807288F, 0.00997300167F,
        -0.0891164765F, 0.0524511449F, 0.033659976F, -0.0351435542F,
        -0.107691154F, -0.097487092F, -0.0556582548F, 0.0123104602F,
        -0.0697884783F, 0.0385755114F, 0.0080419F, -0.0204199906F,
        -0.0709742606F, -0.0385455601F, -0.0772101954F, -0.0305680782F,
        -0.127147943F, -0.0314581096F, -0.0590020865F, -0.0220127106F,
        -0.102877304F, -0.00545674376F, 0.0820905045F, 0.0591151528F,
        0.00366699789F, 0.0689865872F, -0.0430298187F, 0.0337244086F,
        -0.0686312765F, -0.0497356802F, -0.113090292F, 0.0942397192F,
        0.0129242763F, -0.0284601618F, -0.105052933F, -0.102011733F,
        -0.110056728F, 0.0123890806F, -0.0764740556F, -0.0487031564F,
        0.0350693129F, -0.0943426937F, 0.0136301797F, -0.0491325557F,
        -0.122810304F, -0.0449590571F, -0.088543F, 0.0240484159F, -0.0495334119F,
        -0.0656377897F, -0.0501017682F, -0.0431333706F, 0.0865463465F,
        -0.0523928516F, -0.055536449F, -0.0706946105F, -0.10375613F,
        0.0705469251F, 0.0117710009F, -0.0835830942F, -0.0255100466F,
        0.12511453F, 0.0546873957F, -0.0100378525F, 0.0588708594F,
        -0.0926021039F, -0.0625404343F, -0.0059175971F, -0.114036642F,
        0.0277832393F, -0.0608761907F, -0.0639743656F, -0.0746476F,
        0.0684380531F, -0.0470376089F, -0.0977170095F, -0.0264810342F,
        0.0291321613F, -0.0449715741F, 0.0555118F, -0.0390084125F,
        -0.0415387973F, -0.0406159647F, -0.0534594916F, 0.0168369934F,
        -0.0739161298F, -0.0286022257F, 0.0272444747F, 0.0535243116F,
        0.118044063F, 0.000406155537F, -0.0909289792F, -0.0423523188F,
        0.0891590416F, 0.100926511F, 0.047253903F, -0.0764819235F,
        -0.0407918319F, 0.122297347F, 0.127211779F, 0.0995320231F, -0.075498037F,
        -0.0287940595F, -0.11053171F, 0.122146375F, -0.0349994F, 0.0934796333F,
        0.0747787654F, 0.164052233F, 0.139372811F, 0.10875567F, 0.0596370474F,
        0.100035951F, 0.00491937296F, -0.0433112308F, -0.0350746848F,
        -0.0460847579F, 0.0851367116F, 0.0610305555F, 0.0457821488F,
        0.0301387198F, 0.0686529875F, 0.109563835F, 0.00595283927F,
        -0.104632743F, -0.108519457F, -0.00892370474F, -0.0201734975F,
        -0.00197041733F, -0.0508302562F, -0.112168044F, 0.0452487096F,
        -0.030589005F, -0.106080703F, 0.0388084762F, -0.0184256099F,
        -0.039913822F, -0.0518409312F, 0.00173094112F, 0.00845772F,
        0.0672902539F, 0.088973254F, -0.0254086573F, 0.0876522F, -0.0864037052F,
        0.0145161031F, 0.0924614742F, -0.0483718514F, 0.0267063472F,
        0.0379710831F, -0.0427910462F, -0.06746158F, 0.0134738227F,
        -0.0816353261F, -0.0227980837F, 0.0291719493F, 0.00791164953F,
        -0.0337092094F, 0.0221219826F, 0.0258044414F, 0.0083101308F,
        0.0173234846F, 0.0168661159F, -0.0797359422F, 0.0094292F, -0.0881522223F,
        -0.0498523787F, -0.0261500906F, -0.0686298534F, -0.0440683551F,
        0.072087191F, -0.0301809981F, -0.0386567153F, -0.0321999937F,
        -0.037783321F, 0.108962193F, -0.0038788591F, -0.034355823F,
        -0.0915725529F, -0.0579382069F, -0.00901482441F, 0.0564198308F,
        0.013005198F, 0.0820690542F, -0.0336786807F, 0.00800377782F,
        0.0197737757F, -0.00543301506F, 0.011752272F, 0.0782529637F,
        0.0557924323F, 0.0288573187F, 0.0800316632F, 0.077981025F,
        0.00933865551F, -0.0280746426F, -0.00331219682F, 0.0322003886F,
        0.0731593594F, 0.00983714219F, -0.057189744F, -0.0511425808F,
        -0.0436474234F, -0.0271098223F, -0.115044244F, -0.0970755592F,
        -0.0180280618F, -0.00770494714F, -0.101908036F, -0.0212096833F,
        -0.0364332907F, 0.019123517F, 0.076297F, -0.00677209953F, -0.0264345482F,
        -0.0161421094F, 0.0649001598F, -0.0765279755F, 0.0236254241F,
        -0.0648040771F, 0.0350067094F, 0.000690635177F, 0.0821630731F,
        0.0969100296F, -0.0780999139F, 0.0674833F, -0.0029167959F, 0.0892771855F,
        -0.0300826F, -0.063205339F, -0.0322663151F, 0.0563239902F, -0.010872636F,
        0.0449290536F, -0.0377481468F, -0.0363987F, 0.0143184941F,
        -0.0661180243F, 0.0894373804F, 0.0071825427F, -0.0370277911F,
        -0.00129869592F, -0.0575087704F, -0.0510318801F, 0.0695811063F,
        -0.0116368653F, -0.06277702F, -0.0549927801F, -0.0172009636F,
        0.0222772267F, 0.0368307382F, 0.0635949448F, 0.044421941F,
        -0.0280668028F, 0.0412260629F, -0.0427020378F, -0.0372018553F,
        0.0641445518F, -0.0179284178F, -0.0612553284F, 0.0384318456F,
        -0.0266103558F, 0.0708087F, -0.0929434299F, -0.0336434282F,
        0.0489527769F, 0.0854777172F, -0.0239495281F, -0.0197740477F,
        0.075972788F, -0.0267298464F, 0.0467293486F, -0.102928691F,
        0.0162442587F, -0.0288682096F, 0.0751557127F, 0.0691329762F,
        -0.0307742581F, -0.0722223669F, 0.0522586443F, -0.0241985135F,
        0.0195484851F, 0.103352681F, 0.0487399921F, -0.000663891144F,
        0.0838066414F, -0.033009477F, -0.129921392F, 0.024573179F,
        -0.0405564457F, -0.0199301504F, 0.0232859291F, -0.0172114298F,
        -0.0347629F, -0.040745981F, 0.0373499244F, 0.0851382762F,
        -0.00355652301F, -0.0360307246F, 0.0542080626F, 0.0455737263F,
        0.0321874283F, -0.0454736613F, -0.0500229374F, 0.0790615901F,
        -0.0276923887F, 0.0672170445F, -0.0730709881F, -0.0130153336F,
        -0.040319F, -0.0653985515F, 0.0214650258F, -0.0277260654F, 0.0170527715F,
        -0.00147250714F, 0.0570890494F, 0.0368401781F, -0.0290660989F,
        0.0694770962F, 0.0642609522F, -0.00467306934F, 0.0547659919F,
        -0.062435288F, 0.102987677F, 0.00660268F, 0.0408157334F, -0.0314998142F,
        0.0486407F, 0.0347503573F, 0.0118670855F, 0.00548623363F, 0.0382851698F,
        -0.0535607114F, 0.108363099F, 0.0793818682F, -0.0725151F, 0.130646765F,
        -0.000992252142F, -0.0539155938F, 0.0413036756F, 0.0228981134F,
        -0.0476274118F, 0.0899514481F, -0.0629304424F, -0.0156115545F,
        0.00809676666F, 0.0453625619F, -0.0387271047F, 0.00103398343F,
        0.048574198F, -0.0102663701F, -0.0860845521F, -0.104919374F,
        -0.0632699952F, -0.0042546452F, 0.00256427377F, 0.012724773F,
        -0.035277158F, 0.0562521F, -0.0682301745F, 0.0264355056F, 0.0852818415F,
        0.0418532F, 0.0689874142F, -0.000356245582F, 0.0946171731F,
        -0.0372915231F, -0.0370462053F, 0.0154848862F, 0.0472181663F,
        0.0378691927F, -0.0363183F, -0.0338154F, -0.0215784926F, 0.0438222624F,
        -0.0460807644F, 0.039960321F, -0.11542654F, -0.0312097073F,
        0.0428518355F, -0.0224312898F, -0.0671742F, -0.00486412365F,
        -0.090917483F, 0.0796126574F, -0.000933012227F, 0.0497455709F,
        -0.0598115586F, -0.0548747592F, 0.0366751F, 0.0213282946F,
        -0.0797710046F, -0.0182031523F, 0.0383430198F, -0.0331861526F,
        0.0706821F, -0.0273414161F, 0.00701484689F, 0.0198544338F, 0.0102069527F,
        -0.0916498899F, 0.0956833214F, -0.0742698F, -0.0475563407F, 0.0689744F,
        -0.0543484427F, -0.0505785309F, 0.0681506172F, -0.00788989849F,
        0.0650967285F, 0.100890212F, -0.00829308387F, -0.0480392836F,
        0.0345407799F, -0.0580007061F, 0.0844616368F, 0.0791228861F,
        -0.0510870293F, -0.0111329043F, 0.070154F, 0.025206564F, 0.023503352F,
        -0.0110170972F, -0.0122467289F, 0.0131232282F, -0.100339852F,
        -0.0542851239F, -0.023646811F, -0.0983801931F, 0.031144958F, 0.0779814F,
        0.00458168425F, -0.0230475031F, -0.071707651F, -0.00640899409F,
        -0.0766842365F, -0.0797489882F, 0.0582417473F, -0.106531702F,
        -0.0763046145F, -0.0589177087F, -0.000653755153F, -0.0746187717F,
        -0.0438337587F, 0.0697168782F, 0.0161383208F, -0.0434645079F,
        -0.0340196639F, -0.0326407142F, 0.0600689165F, -0.00791304279F,
        -0.0644047707F, -0.0561826788F, -0.0218442045F, -0.0253476277F,
        0.0220300611F, -0.0453878753F, -0.126877382F, 0.0276404805F,
        -0.0023937386F, 0.0638559163F, -0.0249229427F, -0.0489258617F,
        0.0314688794F, -0.00603360403F, -0.0218769759F, -0.00133542717F,
        0.0311572198F, 0.0205123089F, -0.065469712F, 0.0171511285F,
        -0.0217147656F, 0.083076179F, -0.0261555016F, 0.0800532922F, -0.0335035F,
        -0.0849495232F, 0.0424752831F, -0.10149096F, 0.0782564282F, 0.044109039F,
        -0.0324713662F, -0.063474834F, 0.0105448524F, -0.043316178F,
        -0.0369697548F, 0.00564576173F, 0.00509602344F, -0.0012834596F,
        0.0442638174F, -0.0199481584F, 0.0397394113F, -0.0780396F,
        -0.00194826152F, -0.0497277F, 0.0665694922F, 0.0528614223F,
        -0.0978685245F, 0.0248689502F, 0.00467905216F, -0.0651705712F,
        0.0065917871F, -0.00760787912F, 0.0525743067F, 0.0351034217F,
        -0.0645879209F, -0.0189761557F, 0.00464866962F, -0.0353007503F,
        -0.0308129F, -0.0864317864F, -0.0153397284F, 0.0318109281F,
        -0.0154452166F, -0.0400926135F, -0.0300598778F, -0.0187186431F,
        -0.0827093944F, -0.0690358F, -0.0594651438F, 0.0592608526F,
        0.0659469888F, 0.100095376F, -0.105626956F, -0.0412681364F, 0.113786951F,
        0.0617632903F, 0.0740788F, 0.0352491923F, 0.0921839923F, -0.0246831141F,
        -0.0618188605F, 0.0393081494F, 0.0500504076F, -0.016674066F,
        0.092014648F, -0.00640336052F, 0.0247123856F, 0.0143294241F, 0.00568557F,
        -0.041930832F, 0.00129871326F, -0.0765030086F, -0.0735707432F,
        -0.0103381351F, 0.0256674848F, 0.118729331F, 0.100525968F, 0.0785047486F,
        -0.0779620558F, 0.0279451981F, -0.0541702583F, 0.0794188306F,
        0.0312564075F, 0.00120894751F, 0.0304001272F, -0.00230594724F,
        -0.00274589495F, 0.0552758239F, 0.0315216184F, 0.0810189247F,
        0.0284769479F, -0.00639622612F, -0.00754696084F, -0.111468278F,
        0.0995581746F, 0.0354251266F, 0.00537705328F, 0.0735153109F,
        -0.0291682668F, 0.0148391295F, -0.00418911176F, -0.0839486718F,
        -0.0371465124F, 0.0297787152F, -0.0142592881F, 0.00726364879F,
        -0.0261446498F, -0.10791795F, 0.0433745645F, 0.00582940737F,
        -0.0949257463F, 0.0638509467F, -0.0424280465F, -0.0169204045F,
        -0.067212835F, -0.0237643346F, -0.0183750615F, -0.092612F, 0.0168643687F,
        -0.0324877203F, -0.0944319293F, -0.0197267309F, 0.09221863F,
        0.093764618F, 0.0404153615F, -0.00782021694F, -0.0864322633F,
        0.00568915717F, -0.0799319297F, 0.0496499725F, -0.0552153625F,
        -0.133391008F, 0.0442163609F, 0.014377919F, -0.0780285895F,
        -0.0974866897F, -0.0162326042F, 0.107368685F, -0.0500250794F,
        -0.0310033467F, 0.0175631139F, 0.0331339911F, 0.041926641F,
        0.000193579748F, 0.0113862948F, -0.0507842116F, -0.0424637794F,
        0.114413224F, -0.0740234777F, -0.070292294F, -0.0184674766F,
        -0.00622767908F, 0.00318016065F, -0.0197588466F, -0.0583901517F,
        0.0178914908F, -0.0443200655F, -0.0204762835F, 0.00706704939F,
        -0.0201854985F, 0.014127451F, 0.0915467218F, -0.0359427556F,
        0.0395546146F, -0.0928944647F, 0.0470330566F, -0.0265126061F, 0.0310433F,
        -0.123126641F, 0.0409871154F, -0.0708469227F, 0.0233577918F,
        0.00324897165F, -0.0672857836F, -0.0203771405F, -0.031529285F,
        -0.0510065071F, -0.0835117325F, -0.0258464459F, 0.0418357067F,
        -0.014944545F, 0.0534774698F, 0.075513266F, -0.110818237F, 0.0427930057F,
        0.0426530652F, 0.0446077362F, 0.0372932479F, 0.0688678473F,
        0.0592406653F, -0.00437603332F, -0.0884012431F, -0.117879212F,
        -0.0365521051F, 0.0122868614F, 0.0151519328F, -0.0173970815F,
        0.0296782143F, -0.0713276416F, 0.0157488529F, 0.0763867944F,
        0.0495180115F, -0.00181917823F, 0.0166464839F, 0.0365679935F,
        -0.0452583618F, -0.0104110176F, -0.112133704F, 0.0663385168F,
        0.0646066442F, 0.00947172474F, 0.00177176774F, 0.0010939053F,
        0.000259903492F, 0.0899429321F, 0.00914516672F, -0.00315481052F,
        0.0753847137F, -0.0359824039F, -0.0143294111F, 0.106158853F,
        0.101773642F, 0.0287490487F, 0.0467828698F, -0.125222072F,
        -0.0407641046F, 0.0886395797F, 0.0185404196F, -0.105409108F,
        0.189013898F, 0.143818274F, -0.0507189371F, 0.110579707F, 0.0448174849F,
        0.0865020752F, 0.00913384371F, -0.0106045865F, 0.0356452949F,
        0.0960754454F, -0.0156824384F, 0.0307138078F, -0.0601425171F,
        -0.027710719F, 0.031941507F, 0.0489345454F, -0.050949242F, 0.0126283802F,
        0.0880799294F, 0.0161745045F, -0.0208729263F, -0.0604130216F,
        0.133535147F, -0.0501147F, 0.0894873142F, 0.0625986159F, -0.06741108F,
        -0.0139650982F, 0.00623695692F, -0.00290877116F, -0.0750192404F,
        -0.0281356424F, 0.00542042544F, -0.08448641F, 0.025624305F,
        -0.064343147F, -0.00865758304F, 0.0741953701F, -0.0456953645F,
        0.0544354692F, -0.0156106595F, 0.0882542506F, 0.0479659922F,
        -0.0296758786F, 0.0237790085F, -0.0232846681F, -0.044760786F,
        -0.00789813418F, 0.0490627103F, 0.0388882048F, 0.0353218503F,
        0.0384469815F, -0.0710555613F, -0.0277989581F, 0.0433605127F,
        -0.0688411519F, 0.0587955415F, 0.0663048252F, 0.000815083273F,
        0.0530198924F, -0.0525415093F, -0.0787859857F, 0.0030617523F,
        -0.0434643924F, 0.0466992371F, -0.0533043109F, 0.0365642421F,
        0.00573840924F, -0.072677277F, 0.0026028133F, 0.014718744F,
        -0.0405477695F, 0.00393554568F, 0.0199911389F, 0.0286810268F,
        -0.0517012812F, -0.105270684F, -0.00817895588F, -0.0548024327F,
        -0.00929595344F, 0.072191067F, -0.108477406F, -0.0952559933F,
        -0.00486109732F, -0.016385112F, 0.0104261963F, 0.138524011F,
        -0.00387790031F, -0.0297573283F, 0.0736822635F, -0.0824423283F,
        -0.0452785641F, -0.0237951595F, -0.122178487F, -0.128064975F,
        -0.0865081549F, -0.0577599779F, -0.103729203F, 0.0799009F,
        -0.0421573631F, -0.0863637552F, -0.0879370049F, 0.0609531961F,
        -0.14165774F, -0.0523703881F, 0.0115633495F, -0.117101F, -0.0710067824F,
        0.00551719079F, -0.121691257F, 0.00934271328F, 0.00880611222F,
        -0.0224410519F, -0.0320471823F, 0.00539768487F, -0.0799115524F,
        -0.0155982943F, -0.137011766F, -0.117267631F, -0.0541634671F,
        -0.100575157F, 0.0769610181F, 0.0439339578F, -0.114836469F,
        -0.109124787F, 0.00654252572F, 0.0343940891F, -0.115229912F,
        -0.0144383823F, -0.0593891293F, -0.0677918717F, 0.0106742987F,
        -0.0968362093F, 0.0399108715F, 0.0784799606F, 0.0678227693F,
        0.075672321F, -0.034474466F, -0.122511171F, -0.0896109641F,
        0.0405060165F, 0.111597873F, 0.123621881F, 0.0269002263F, 0.12990126F,
        0.0887497813F, 0.105697006F, -0.0307422746F, 0.0722509548F,
        -0.00174434413F, 0.0136502394F, -0.000338249898F, 0.0376449339F,
        -0.0711838F, -0.050407812F, -0.0833939761F, 0.112100244F, 0.0892354F,
        0.0188118163F, 0.135255158F, 0.132727966F, 0.0312396679F, 0.0182341263F,
        0.109871909F, 0.0973975956F, 0.0113257244F, 0.0715324879F, 0.0692739263F,
        -0.0709389448F, 0.0148847513F, 0.0644443855F, -0.0646502748F,
        -0.0404719114F, -0.0878166631F, -0.0514957532F, 0.0745730847F,
        -0.0430521443F, 0.0994998068F, -0.0331839472F, 0.0434440449F,
        -0.0373480357F, 0.0576767176F, 0.0453305058F, 0.0834376737F,
        -0.0205538832F, -0.134128377F, 0.0391549766F, 0.0246571824F,
        0.0217593797F, 0.0254085325F, -0.0551152F, 0.0130005758F, 0.0382862F,
        0.083808139F, 0.111333549F, 0.030244166F, 0.124706157F, 0.0802392513F,
        -0.0817636847F, 0.00863170344F, 0.112621106F, -0.0246542078F,
        0.0957968831F, -0.0850836709F, -0.0666306913F, -0.0595807172F,
        -0.0015447659F, 0.000191192667F, 0.0947634F, 0.0641067F, 0.0859689862F,
        0.0599167868F, 0.0353309736F, -0.105891228F, -0.116713874F,
        0.0356473327F, 0.0504360907F, -0.0745373F, 0.0688385069F, -0.0465197191F,
        -0.0194757432F, -0.0129868481F, 0.00123939035F, -0.109615408F,
        0.0724929497F, -0.0908280462F, -0.0509964116F, -0.0508223735F,
        -0.044161059F, -0.0070726769F, -0.00308330683F, -0.0697524697F,
        0.061333511F, -0.108494416F, 0.114067614F, -0.0294540524F, 0.0328164473F,
        -0.044647608F, -0.10777124F, -0.0664247423F, -0.00267636124F,
        0.0469773524F, -0.0395849347F, -0.0105891619F, -0.0342025459F,
        -0.0227976F, -0.105652072F, -0.0740654171F, -0.0722943F, -0.146038622F,
        0.00644144882F, -0.119194016F, -0.0915693492F, -0.0242474675F,
        -0.0688872114F, -0.0739197209F, -0.0798752755F, 0.0402020402F,
        -0.0579180755F, -0.0872237161F, 0.00270180078F, -0.0787312835F,
        -0.0267241355F, -0.0872374251F, -0.00515210675F, 0.0322937407F,
        -0.0494412407F, -0.132082582F, -0.0533263348F, 0.0139333848F,
        -0.0759658F, -0.0195925646F, -0.10005217F, -0.0320641659F,
        -0.00180168415F, -0.0342593528F, -0.0512084439F, 0.019811498F,
        0.00571673689F, -0.0489164665F, 0.0676369071F, 0.00967194F,
        -0.032906387F, 0.0711326897F, -0.025350282F, -0.0550712235F,
        0.0289642867F, 0.00953207165F, -0.113611139F, -0.0552814081F,
        0.0375709906F, -0.0207812F, 0.0686158836F, -0.0668950379F,
        -0.0388294384F, 0.0351820402F, -0.0710682273F, -0.0541955382F,
        -0.0172992293F, 0.0677744895F, -0.0721250325F, -0.018802207F,
        -0.0968505442F, 0.073650375F, 0.0197542757F, 0.0346838497F,
        -0.0595283955F, -0.060069982F, 0.0408995338F, -0.0993974134F, 0.0354881F,
        0.0227379985F, -0.109459475F, 0.0286727343F, 0.0442196317F, 0.04587695F,
        -0.113365345F, -0.0517663F, -0.0602568537F, 0.00437734649F,
        -0.0500436202F, -0.119779795F, -0.0704261214F, -0.120050192F,
        -0.0631175637F, 0.0120020453F, -0.0108376741F, 0.0680129603F,
        0.117506891F, 0.0198994353F, 0.0504650809F, 0.0252836961F, 0.0154600563F,
        0.0249587987F, 0.0071255411F, 0.080863826F, -0.0510863736F,
        -0.0202218778F, 0.0651753098F, 0.0631844699F, 0.000877493876F,
        0.0166809727F, 0.047175061F, 0.0767779723F, 0.0967865363F,
        -0.0535149314F, 0.0681803524F, 0.091563642F, 0.0471447632F,
        -0.0126638822F, -0.00762264477F, 0.0650643408F, 0.00460258964F,
        0.0177719835F, -0.0233087428F, -0.0101462128F, 0.0876817405F,
        -0.104620412F, 0.0113311531F, -0.030629389F, 0.00321840541F,
        0.0360435098F, 0.0960121602F, 0.0339409448F, 0.0691677406F,
        -0.0168374069F, -0.0107454183F, -0.0690372437F, 0.045761738F,
        -0.159153476F, 0.0958328769F, -0.0354088247F, 0.0655033F, 0.0575224124F,
        0.029176563F, 0.0228163935F, 0.0811520442F, -0.00660124142F,
        0.0900387615F, 0.0171956606F, -0.065508008F, -0.0602855571F,
        0.00246925792F, -0.0573139191F, -0.114028946F, -0.00815771427F,
        -0.00191268965F, -0.0071759345F, 0.0390187688F, -0.047409F,
        0.0130802365F, -0.0418924801F, 0.0606548227F, 0.00239183381F,
        -0.0672895461F, -0.0231445376F, 0.0629196763F, 0.0757780597F,
        -0.0898544863F, 0.108918041F, 0.0526659302F, -0.110596314F,
        0.0784974545F, 0.044244919F, -0.0218287185F, -0.149861425F, 0.123271845F,
        -0.0764403F, -0.0192922018F, 0.0845585391F, 0.0445273146F, -0.049084045F,
        0.0246735457F, -0.0046607512F, -0.0263328925F, -0.0846237317F,
        -0.0298521835F, -0.0913854F, -0.0129523249F, -0.121752664F,
        0.0011193445F, -0.0406784676F, 0.0200269781F, 0.0895857289F,
        -0.0112329619F, 0.0685169622F, 0.0217974484F, 0.0420305878F,
        -0.0645371228F, 0.0253728554F, -0.0812467709F, -0.107494339F,
        0.0339261815F, -0.0560360439F, 0.0279466864F, -0.0884963423F,
        -0.0181153566F, -0.021631524F, 0.0235248134F, -0.0548164286F,
        -0.0258550271F, 0.0966016576F, -0.0463152193F, 0.0238768701F,
        -0.00136375078F, -0.0760962516F, -0.0916019902F, -0.0115695167F,
        -0.0637663901F, -0.078096129F, -0.0228790622F, -0.0954757631F,
        0.0153628308F, -0.00786974374F, -0.104367591F, 0.000307881302F,
        -0.0863227397F, 0.0589845926F, -0.0404860228F, -0.0632901862F,
        -0.134942651F, -0.0558142662F, -0.0384854712F, -0.116824076F,
        0.0165651757F, -0.0522469692F, -0.0470706597F, -0.0496768169F,
        0.0201784596F, -0.0104684262F, -0.0634929612F, 0.0689480081F,
        -0.0461129658F, 0.0295397937F, 0.0454198718F, 0.0918738171F,
        0.0796240717F, -0.0509309322F, -0.0329651721F, -0.0929677933F,
        0.0386217684F, 0.0361122712F, 0.0543065555F, 0.0821553692F,
        -0.0341960825F, -0.0457808748F, 0.0273067504F, -0.00314330892F,
        -0.0441704169F, 0.0842523277F, -0.0187202506F, 0.0466330312F,
        0.0760488138F, 0.000755641551F, -0.04811823F, -0.0327921472F,
        -0.00415390078F, -0.0596286431F, 0.0895665139F, -0.0358728208F,
        -0.0491478294F, 0.0212207884F, -0.125265971F, 0.0539095663F,
        -0.0382079855F, -0.0555169061F, 0.0423086584F, 0.0723341778F,
        0.0208473764F, 0.000726618338F, -0.0551303F, -0.0246949047F,
        -0.0569556579F, 0.00825592317F, -0.01757445F, -0.0578167178F,
        -0.0188130438F, -0.0112993158F, -0.0315890871F, -0.0100435279F,
        -0.0411948F, -0.0113538215F, -0.055136F, 0.106719479F, -0.0915823951F,
        0.0584235527F, -0.0375217795F, -0.00990875252F, -0.109769061F,
        -0.0133306179F, -0.042282071F, -0.0643534437F, 0.0131871309F,
        -0.0137260649F, -0.0189988799F, 0.0767823681F, -0.0963118374F,
        0.026299648F, -0.017239077F, -0.0538449809F, -0.0425288F, -0.0828271657F,
        -0.0877937302F, -0.0607424751F, -0.0855047703F, 0.0265441407F,
        -0.046604678F, 0.0205404125F, 0.0598839633F, 0.0258760899F,
        -0.0149313863F, -0.0135187097F, -0.0292134415F, -0.039907828F,
        -0.00509544043F, -0.0114570167F, -0.0690866113F, 0.0272484981F,
        -0.00715583842F, -0.0415778197F, 0.00511800963F, -0.00195259298F,
        -0.0132500697F, 0.0510888472F, 0.0395443812F, -0.0331070162F,
        0.040518973F, -0.0162531827F, 0.0727118105F, 0.0383752063F,
        0.0548444614F, 0.07115677F, -0.0474536531F, -0.0572524443F,
        0.00180844765F, -0.0351461545F, 0.0191323422F, 0.0173436645F,
        -0.00177991274F, -0.0110353054F, -0.0434144251F, -0.00334651396F,
        0.00279060844F, 0.0450775065F, -0.0120657226F, 0.0601462F, -0.099876374F,
        0.0202045776F, -0.0474067852F, 0.0431236364F, 0.00103577785F,
        0.0135417404F, 0.00784800574F, -0.00918671768F, -0.00476693502F,
        -0.124262549F, 0.0556990132F, -0.00720550353F, -0.0969920531F,
        0.0442032292F, 0.0244314503F, -0.0651342794F, -0.112739146F,
        -0.0469677821F, 0.0103467647F, -0.118285321F, 0.00398410251F,
        -0.0939543694F, 0.0522562526F, 0.0258795619F, -0.0918895528F,
        -0.0451532565F, -0.0477862731F, 0.0497204363F, 0.0801303461F,
        0.0556795448F, -0.098348F, 0.0124525074F, -0.0486557782F,
        -0.00347972917F, -0.00628325343F, -0.0472539961F, -0.0593008809F,
        0.0586474128F, -0.0893692523F, -0.00887905713F, -0.106851175F,
        -0.0389446504F, -0.0251119621F, -0.0305428505F, -0.0550723523F,
        -0.0234408602F, 0.0560866296F, -0.0293493439F, -0.0764272287F,
        -0.0179971531F, 0.0940013304F, 0.0349658392F, 0.0401939265F,
        0.00813909061F, -0.0940725356F, -0.0137245459F, 0.0077032051F,
        -0.084136039F, 0.0417957976F, 0.0177379455F, -0.0808025822F,
        -0.0374227837F, -0.0669884235F, -0.03118149F, 0.0775963515F,
        0.107149735F, 0.0693768188F, -0.0223082565F, 0.0769652873F, 0.108257815F,
        0.000643010833F, 0.0611581318F, 0.0993146375F, -0.00718523236F,
        0.0353509672F, -0.020335678F, -0.00804373343F, 0.0357902758F,
        -0.0182634015F, 0.0400161259F, -0.012802843F, -0.0736032054F,
        -0.0140856048F, -0.0955851749F, -0.0282187052F, 0.0763562322F,
        0.072169587F, -0.00715242792F, 0.0181234777F, -0.0346583277F,
        0.00338644837F, -0.00891941227F, 0.0843411461F, -0.0703988075F,
        -0.101146109F, -0.0254384894F, 0.0279137529F, -0.0168946069F,
        -0.0599453598F, -0.0540478043F, 0.0126760369F, 0.0220808554F,
        -0.0872901604F, 0.0101012308F, -0.00212966767F, 0.0124032879F,
        -0.0621455312F, -0.0221846737F, -0.0792139843F, -0.0612494648F,
        0.00511588529F, -0.0229567215F, 0.0326575153F, 0.0726190582F,
        0.0716216192F, 0.0318514444F, 0.14120622F, 0.0132665383F, -0.112092905F,
        0.0377164073F, 0.0602726191F, 0.0809863359F, -0.0178523697F,
        0.0435258225F, 0.0438078158F, -0.0189368986F, -0.0588956214F,
        -0.0682123825F, -0.0155834313F, 0.0637803748F, -0.0689008385F,
        -0.0493168756F, -0.0482180789F, 0.00889785F, -0.0952819958F,
        0.0560057573F, 0.0474881418F, 0.0050041303F, 0.0266518816F,
        0.0974795818F, 0.00981054734F, 0.0621888973F, -0.0711885393F,
        0.0883751065F, 0.0574593805F, 0.103173546F, -0.032860253F,
        -0.0936053544F, -0.0342554078F, -0.0235842541F, 0.00583791826F,
        0.0517048612F, -0.00223439536F, 0.0145108588F, -0.00785039086F,
        0.012970455F, 0.0362712145F, -0.0780659169F, -0.0203727335F,
        -0.0659891516F, -0.0185519643F, -0.0328137353F, -0.0455369242F,
        0.0247216038F, 0.0560897924F, -0.0349245295F, -0.125786588F,
        0.0655551627F, -0.0750126168F, -0.0897476375F, 0.0367595293F,
        0.0213893205F, 0.0204908531F, -0.0975257307F, -0.0549532175F,
        0.000237239146F, -0.0477790646F, -0.0753173605F, 0.0378144123F,
        -0.0846651867F, -0.0231813174F, 0.0859528333F, -0.057276275F,
        0.0103444261F, -0.107857235F, 0.0472412854F, 0.0643376261F,
        0.0154730864F, 0.0595760606F, -0.0320940502F, -0.00915644225F,
        0.0733331293F, -0.103075035F, -0.0483647622F, -0.0692397952F,
        -0.0052399775F, 0.0137416702F, 0.104660839F, -0.109074458F,
        -0.0181609411F, 0.0602104254F, 0.0770343393F, 0.017243091F,
        0.0490283482F, 0.109457143F, 0.034206178F, 0.0162728447F, 0.0517871082F,
        -0.07947997F, -0.00721708592F, 0.0710123F, -0.0516044125F, 0.106240287F,
        -0.0494152978F, -0.0355243459F, 0.130336881F, -0.01270294F,
        -0.138504252F, 0.00549321622F, 0.0667792112F, 0.0792190731F,
        -0.0460306816F, -0.00729058543F, 0.0808147788F, 0.0471146367F,
        0.0904974565F, 0.0188560151F, -0.078154631F, -0.0199396033F,
        -0.0590004325F, -0.0165039804F, -0.0323188119F, -0.0851791129F,
        -0.123715609F, 0.0198160131F, -0.0342859328F, 0.0765995681F,
        -0.0159330331F, -0.0698118806F, 0.0225176942F, -0.0725395307F,
        0.0601039454F, -0.0607518665F, -0.050290402F, -0.017432278F,
        0.0765862092F, -0.0286159031F, -0.102155969F, -0.0282412693F,
        0.0386757366F, 0.016268285F, 0.0327175371F, -0.0561052524F,
        0.0454009287F, 0.00172910537F, -0.0661449432F, -0.0556909963F,
        0.0398833081F, 0.0434661247F, 0.0566980056F, 0.00257453555F,
        0.0363717489F, -0.0529170558F, -0.0288956221F, -0.0373311266F,
        0.0513292439F, -0.00226821448F, -0.00300218118F, 0.014996998F,
        0.0658923611F, 0.0676830187F, -0.0586921535F, -0.0261825193F,
        0.0130857034F, 0.0619640946F, -0.0411015712F, -0.0150512187F,
        -0.0576189086F, 0.0127835646F, -0.00826395396F, 0.0014060355F,
        0.0340177342F, 0.0625638217F, 0.000839061395F, 0.0750915334F,
        0.103954822F, -0.0128014516F, -0.0251560565F, 0.0250953566F, 0.0725374F,
        -0.0459386967F, 0.0832463875F, -0.0420613624F, -0.0423171632F,
        -0.0788705498F, 0.0297415126F, -0.0545544736F, 0.0682420135F,
        0.0663500205F, -0.0508991368F, -0.00174852018F, -0.00388999446F,
        -0.0133018205F, 0.0270710196F, 0.0458333082F, 0.0121263489F,
        -0.0385883935F, -0.0673780292F, -0.0246354062F, 0.0434632711F,
        -0.0401662588F, -0.0365089F, 0.0579567626F, -0.11804124F, 0.0340252F,
        -0.0481933914F, -0.0803957F, 0.0496796183F, -0.000626167632F,
        0.0279337727F, -0.0328599736F, -0.0421088152F, 0.0555153303F,
        0.0198955536F, -0.0771521926F, -0.066281952F, -0.058066152F,
        -0.0561527573F, -0.00291543221F, 0.084116891F, 0.0594791472F,
        -0.0522613F, -0.05620756F, -0.0352856182F, 0.0392034389F, -0.0163570885F,
        -0.0681629404F, 0.012615433F, 0.0821497738F, 0.0636726394F,
        -0.0476031415F, -0.0717057362F, -0.110739425F, 0.0125228334F,
        -0.0267118122F, -0.0645171255F, 0.0367234871F, 0.0278485268F,
        0.0063308496F, 0.0584156886F, -0.0130732339F, -0.0794383883F, 0.0579732F,
        -0.084627606F, 0.0700516254F, 0.0259005986F, 0.0266864989F,
        -0.0153281018F, 0.0456818417F, 0.00304861041F, -0.0357159562F,
        -0.0279803127F, 0.0560649559F, -0.0387208611F, -0.0877302438F,
        0.0709646344F, -0.0126600675F, 0.0984261706F, 0.0627234057F,
        -0.0379803218F, 0.00386973447F, -0.0667692646F, 0.0750177801F,
        0.00568934297F, -0.092214644F, 0.0194307901F, 0.0305784233F,
        -0.0461767651F, 0.0243834462F, -0.0272588171F, -0.0337293781F,
        0.0590786561F, 0.0272081066F, -0.0289936159F, -0.0563129596F,
        0.0178944971F, 0.00854490697F, 0.0659955591F, 0.00651282864F,
        -0.015746776F, 0.0321862847F, 0.0297418665F, -0.0415919051F,
        -0.0339188576F, -0.0442217253F, 0.015373758F, -0.0341756754F,
        -0.0027518922F, -0.0481357276F, 0.0115317861F, 0.0707898811F,
        -0.0686884448F, 0.0830448344F, 0.0678754F, 0.0436339378F,
        -0.00640305365F, -0.0608121566F, -0.0422539972F, 0.0244033486F,
        0.0435701609F, 0.0297889151F, 0.0175012387F, 0.0456201136F,
        0.0621401817F, 0.0720073953F, -0.0333272442F, -0.030971555F,
        -0.0162047371F, -0.0244552288F, -0.0548710339F, 0.0935200453F,
        0.0271194298F, 0.0702365786F, 0.0662494451F, -0.00469342759F,
        0.0132083138F, 0.00169630384F, 0.119270258F, -0.0175805092F,
        0.0150899319F, 0.0701177F, -0.0016041192F, 0.0388452336F, 0.0181514081F,
        0.102962352F, -0.100802928F, 0.0762068629F, 0.0820492506F, 0.0688746348F,
        0.0717826337F, 0.0718229F, 0.0162421446F, 0.0423189476F, 0.0814001411F,
        0.0248077959F, -0.049790103F, 0.0715100393F, -0.0961146727F,
        -0.074703835F, 0.00306509226F, 0.0368028842F, -0.104358412F,
        -0.0418516807F, 0.0819977298F, -0.0199692417F, 0.0387590453F,
        0.00424912479F, 0.0670455098F, -0.0285651721F, 0.0973716304F,
        0.0486993119F, 0.0103660384F, 0.0548717F, 0.0342412256F, -0.00577642955F,
        -0.0852856785F, -0.047201883F, -0.107229605F, 0.0563469343F,
        0.0430024639F, 0.0869898647F, 0.0689713061F, -0.0353584625F, 0.0418806F,
        0.05946064F, -0.0638953596F, -0.0689541101F, -0.0684432611F,
        0.0386349112F, -0.0449670404F, 0.0961445943F, -0.0998336F,
        -0.0164467227F, -0.0674297214F, -0.0550821535F, 0.0719176903F,
        0.0548879206F, -0.0313518085F, 0.0298688114F, 0.0732737109F,
        -0.0560611151F, -0.0217181668F, 0.0443850644F, -0.000331086805F,
        0.0505624823F, 0.00940543693F, -0.0684486851F, 0.0418777801F,
        0.0067343493F, -0.0514669977F, 0.0725909173F, -0.0266292207F,
        -0.0140951332F, 0.0766321346F, -0.0876138F, -0.0817728862F,
        -0.0384937413F, 0.0114542302F, -0.0144637516F, 0.0117847705F,
        -0.00412682397F, -0.0739920214F, -0.033860717F, -0.082018517F,
        0.0346195959F, -0.0652457252F, -0.024420049F, 0.0753179118F,
        0.096294269F, 0.0600132346F, 0.00704596564F, -0.0564488433F,
        -0.0178171676F, 0.0457948409F, -0.0647562593F, 0.0381022952F,
        0.0944873393F, -0.0378644019F, -0.0392078385F, -0.00191174843F,
        0.0114806853F, 0.00912585575F, -0.0545765609F, 0.0329400972F,
        0.0564452559F, -0.0439631082F, -0.0386113338F, -0.0628157184F,
        0.0235630814F, 0.0265256707F, -0.0327413455F, -0.0246622656F,
        -0.00350494683F, -0.0660143048F, -0.0931804255F, -0.0943550467F,
        -0.0422802828F, -0.0283967908F, -0.0292396527F, 0.0604757592F,
        0.0859581083F, -0.0413942039F, 0.0621518493F, 0.0792334452F,
        0.0869626477F, 0.0687840432F, -0.0029988063F, -0.0460220575F,
        0.0574410409F, -0.0168338753F, 0.0442049168F, -0.108861186F, -0.0113784F,
        0.0832048878F, 0.0124421101F, -0.110301159F, 0.0962315F, 0.0917392671F,
        -0.0440252312F, -0.0337392353F, 0.00120589696F, 0.00256488356F,
        0.00440680422F, 0.0321897678F, -0.043670658F, 0.0164053272F,
        0.0479157194F, 0.0669488609F, 0.0658725351F, 0.0287449267F, 0.110068612F,
        0.0298362598F, -0.048493702F, 0.0177619047F, -0.0562583655F,
        -0.044885803F, -0.0308797918F, 0.0895722881F, -0.0103811268F,
        0.0377916433F, 0.010199382F, -0.0280267224F, -0.0876558349F,
        -0.0425624475F, 0.0471453369F, 0.0292195491F, -0.0758530796F,
        0.0686975867F, -0.0406253077F, 0.0325604044F, -0.0158338286F,
        0.0386484861F, -0.0691954419F, -0.0593415722F, -0.0539228618F,
        0.095124729F, 0.00241409987F, 0.042742148F, -0.0825960189F,
        0.0519549921F, -0.0819640085F, 0.0257356018F, -0.0912331566F,
        0.0530447364F, -0.0766827464F, 0.0788204074F, 0.0319559574F,
        -0.101658456F, -0.0916539803F, 0.0568404533F, -0.0209058877F,
        0.00574789802F, -0.0280227922F, -0.0510725901F, -0.106382467F,
        -0.0999979153F, -0.0433600172F, 0.0619304664F, -0.0171459597F,
        -0.103997812F, -0.0650977269F, 0.100935377F, -0.00888274889F,
        -0.0851236F, -0.0752557889F, -0.0266153943F, -0.0827433243F,
        0.0601407178F, 0.00959890336F, -0.0757915676F, -0.0205890927F,
        0.0812810585F, 0.0576584339F, 0.0577121526F, -0.037145026F,
        -0.043462757F, -0.0706815273F, 0.0478280559F, 0.0783860758F,
        -0.0523781739F, -0.00890736096F, -0.0150459502F, -0.0411175F,
        -0.0248149484F, -0.0219750423F, 0.00016958185F, -0.0187298842F,
        0.0764129236F, 0.0451139733F, 0.0181404836F, 0.0837616473F,
        -0.0468717404F, 0.0285438579F, -0.0645362362F, 0.0569838174F,
        -0.0257193409F, -0.0137872193F, 1.34717266E-6F, -0.0116219306F,
        0.0261102077F, 0.0660997853F, -0.0918744355F, 0.0744805709F,
        -0.0780913606F, 0.00924757496F, -0.0646924525F, 0.0590355881F,
        -0.0465812869F, -0.07070297F, 0.0329295918F, -0.0821280852F,
        -0.0372302979F, -0.0245915558F, 0.0922718F, 0.0634281933F,
        -0.00584629737F, -0.0381315239F, -0.00681829453F, -0.0678553879F,
        -0.00559354387F, 0.0867025554F, 0.0450416654F, 0.00321620051F,
        -0.0564017594F, -0.0589087531F, -0.0131416237F, 0.0511607118F,
        -0.0544548184F, -0.0382140838F, -0.0216335654F, -0.0406205F,
        -0.0171500258F, 0.0863367692F, -0.0861209705F, -0.110636458F,
        -0.103538588F, 0.0536112338F, 0.0607705F, 0.0924121141F, 0.054583665F,
        0.0385704041F, 0.0900371224F, -0.0835193098F, 0.0591011792F,
        0.0752899274F, 0.0341043472F, 0.105109066F, 0.0688256547F, -0.034127064F,
        -0.0098074954F, 0.0354934596F, 0.019328665F, 0.047915753F,
        -0.0393511355F, 0.122124285F, 0.000296941405F, 0.0256027933F,
        0.119101845F, -0.0294150058F, -0.00993859489F, 0.0515533164F,
        -0.0379434787F, 0.0423316918F, 0.035604313F, 0.0579593368F,
        -0.033148095F, -0.0592133589F, -0.00471574673F, -0.0186158717F,
        -0.0831744373F, 0.0487928167F, 0.0558183193F, 0.05359409F, -0.064815F,
        0.0112518789F, -0.0774102062F, -0.0118546383F, -0.0219444279F,
        0.121610083F, 0.0636387393F, 0.0912637562F, -0.0485936627F, 0.050374195F,
        0.0570228025F, 0.0500036664F, -0.0686582F, -0.073599577F, 0.12724261F,
        -0.0311253555F, 0.0955023393F, 0.0604353212F, 0.0115740299F, 0.02929065F,
        -0.0224362351F, 0.0229024906F, -0.0711220056F, -0.0100966934F,
        -0.0626956895F, -0.00100685772F, -0.0724211112F, -0.028372433F,
        -0.11045634F, 0.0719980374F, 0.0760714933F, -0.0162442531F, 0.0851157F,
        -0.0640475377F, 0.0065638693F, 0.0941503495F, 0.0528626107F,
        0.0846503228F, 0.00842142664F, -0.0633483902F, -0.0525923148F,
        -0.0170205515F, -0.00161940057F, 0.0494352952F, -0.0918241218F,
        0.0787751824F, -0.0489531681F, -0.037817724F, 0.0272789337F,
        -0.0226380732F, -0.0528009199F, 0.0279862024F, 0.0283472016F,
        -0.0592063367F, 0.0635988563F, -0.039404802F, -0.0432291478F,
        -0.0411375761F, -0.0460774116F, 0.0770257339F, 0.0100033805F,
        0.0295591503F, -0.01443558F, 0.0435832F, -0.0143919801F, -0.0801548883F,
        -0.0239635874F, -0.109208755F, -0.0553663597F, -0.0346347466F,
        0.0484625213F, -0.0657041892F, 0.0810895637F, -0.0658368543F,
        0.0208471492F, -0.0312235728F, -0.078533791F, 0.0106285755F,
        -0.00328854192F, -0.024266975F, 0.0186186098F, -0.017977383F,
        0.0232182499F, -0.0185049251F, -0.0214766786F, -0.0635411665F,
        0.0107232463F, -0.054309573F, -0.0310859252F, 0.033318609F,
        0.0732939616F, 0.0790553316F, 0.0147633096F, 0.0672430173F,
        1.30379049E-5F, 0.0712188706F, 0.0577972047F, 0.0660891235F,
        0.0283584148F, 0.0912730396F, -0.00830934756F, -0.0246697906F,
        -0.000345500273F, -0.0042355042F, 0.000579376589F, -5.61029083E-7F,
        -0.0291948803F, -0.0080047315F, 2.61639052E-5F, 3.06951079E-5F,
        -0.0150581244F, -0.0298093893F, 0.00978478137F, 0.0121179828F,
        0.0254488327F, -0.00847910531F, -0.0268112123F, -0.0262252819F,
        -0.00111916568F, -0.00614083279F, 0.0217568818F, 0.00141524291F,
        -0.0108217318F, -0.00044746793F, -0.00340205338F, -0.00848943274F,
        -0.0166869983F, -0.0305840522F, 0.0133570507F, 0.0269140825F,
        -0.0310826171F, -0.00721885217F, -0.0660646334F, -0.0524423495F,
        -0.054356657F, -0.0303240549F, 0.0344107114F, -0.0490319841F,
        -0.00866470765F, -0.0128275426F, -0.0153736072F, 0.0496304445F,
        0.0272651576F, -0.0270762779F, -0.0429538712F, -0.0342926234F,
        0.0419293195F, 0.0150496103F, -0.0600657053F, -0.0435960405F,
        2.10973267E-5F, -7.97494613E-6F, -0.0204808339F, -2.08047908E-7F,
        0.0138647528F, -3.64523403E-5F, -1.23763868E-6F, 4.48924879E-8F,
        -0.019618379F, -0.0253263917F, -0.0269927476F, -8.59916418E-6F,
        0.00382264866F, 3.23560607E-6F, 0.0324612446F, -0.058678478F,
        1.86034313E-7F, 0.00304946653F, 0.0133840246F, -0.00121059199F,
        0.0269021746F, 2.34482582E-6F, -0.005203743F, -0.0025280565F,
        -0.036288064F, -0.0462277979F, 0.0404839106F, 1.87588848E-5F,
        0.0198875163F, 3.46849847E-5F, 0.0317739956F, 0.00495991F,
        -0.00883091055F, 8.57197301E-5F, 0.00278109638F, -0.0256817695F,
        -0.0185267739F, -0.0153092993F, -0.0331264213F, 0.038288787F,
        0.000821255962F, -0.0126533294F, 0.0613947175F, -0.049889423F,
        0.0198507607F, 0.0100134797F, 0.030218292F, 0.0375511684F,
        1.99133456E-6F, -5.00518027E-8F, -0.00303903106F, 0.0102592511F,
        -0.00276357541F, 8.55606231E-6F, 6.19827042E-5F, 5.77990875E-7F,
        -0.0182069577F, 0.00898422766F, -0.0300197564F, 4.56029653E-7F,
        -0.0275373608F, 3.56016267E-6F, -0.0641122311F, -0.0275877267F,
        1.83220408E-8F, -0.00750065688F, -0.00353234122F, 0.00817612745F,
        -0.051413022F, -0.00108207797F, -0.00885813683F, -0.0103697889F,
        0.013858554F, -0.0146757169F, 0.0242867582F, 4.03288723E-5F,
        -0.0187024754F, -0.00193544221F, 0.0289098155F, 0.0441551805F,
        -0.0118100168F, -0.0166229047F, -0.0014773428F, -0.0156108523F,
        -0.0402404144F, 0.00615854841F, 0.00225038198F, 0.00464921538F,
        0.00388854137F, 0.0488736406F, -0.0178325232F, 0.00572995888F,
        -0.0506673828F, 0.0537555367F, -0.00158233556F, 0.000747923739F,
        -0.0011520416F, 0.00451874081F, -0.0310138054F, 0.0377159342F,
        -0.00780970929F, 0.00635570521F, 0.00980361272F, -0.0187082235F,
        -0.032593485F, 0.0290289465F, -0.000867728086F, 0.00584194297F,
        0.0105679939F, -0.0090663759F, -0.00317149167F, 0.000402498234F,
        -0.00137457973F, -0.00403216062F, -0.0311366059F, 0.000787973811F,
        -0.0104728024F, -0.00699344603F, 0.0543850251F, -0.0547546484F,
        -0.022154076F, -0.00288583455F, -0.00059773773F, 0.00649644295F,
        -0.0569605678F, 0.0375104F, -0.00114800595F, -0.0233782157F,
        0.0228117257F, -0.00360717368F, 0.003149339F, 0.0247850455F,
        -0.0378998816F, -0.0312677622F, -0.0804016292F, 0.0405695513F,
        -0.00414101593F, 0.0109713282F, -0.0189265795F, -0.0356607698F,
        -0.0386869647F, 0.0312812664F, -0.000997848F, -0.00269674114F,
        -0.000332812837F, -0.0172691513F, -0.0267587285F, 0.00664905086F,
        -0.0122446008F, 5.23123963E-5F, 0.0552643F, 0.000609343813F,
        -0.000858913059F, -0.0164136849F, 0.000261531764F, 1.54824884E-5F,
        -0.0143954949F, 0.0059641609F, -0.00343973888F, -0.0366828628F,
        3.01089585E-6F, -0.00837726F, -0.0206016656F, 0.0113641145F,
        -0.0167577043F, 9.53521812E-5F, -0.0157574248F, -0.00597175304F,
        -0.0626685172F, -0.0348285101F, -0.000779137132F, 0.00669694599F,
        0.00801505055F, 0.0543999262F, -0.0330411121F, -0.0447430089F,
        0.00793952309F, -0.0483735614F, -0.0586747341F, -0.0209467169F,
        -0.0148891527F, -0.0439121798F, -0.0663751736F, 0.0528377667F,
        -0.0242811292F, 0.00032332589F, -0.00126971025F, 0.0550446101F,
        -0.00175596413F, 0.0134950988F, -0.000120941411F, -0.00772179337F,
        -8.42026608E-8F, -0.00954160187F, -0.057794217F, 0.0180588178F,
        -0.0227243509F, 2.19154543E-7F, 0.0207316037F, 0.0103019793F,
        -0.0408646055F, 0.00719597237F, 0.00662947074F, 1.13120651E-8F,
        1.14542956E-6F, -0.0486865193F, -0.00764419232F, -0.0258404296F,
        -5.40186456E-8F, -0.00454600528F, 0.00687912432F, -0.00843580905F,
        -0.00846169796F, -1.28575024E-7F, 0.0203587916F, -0.0224994682F,
        0.0385854095F, 0.00446679909F, -0.00164397294F, -0.00666593341F,
        5.23864863E-8F, 0.00158365874F, -0.00523314299F, -0.0229392741F,
        0.00380194979F, 0.0120391035F, -0.00493120728F, 0.0508290641F,
        -0.0128463628F, -0.0132465502F, -0.0015638941F, -0.0327487551F,
        -0.0501974411F, 0.0550718307F, -0.0075543F, -0.0452159829F,
        -0.0550464094F, -0.0593499355F, 0.0935423672F, 0.0809947F,
        -0.0517479517F, 0.0443252102F, 0.0391504727F, 0.0323469937F,
        0.0159314442F, 0.0435923561F, -0.0907151923F, 0.0791727751F,
        -0.0873274058F, -0.0466099456F, 0.0510419123F, -0.0357560366F,
        -0.0592333786F, 0.0217900109F, -0.108714491F, 0.0856611356F,
        0.0459088534F, -0.037603803F, 0.10048309F, -0.0141416825F,
        -0.0109028034F, -0.0110235959F, -0.100102074F, -0.0362842381F,
        -0.0213707015F, -0.0581488051F, -0.0163332913F, -0.027168598F,
        -0.0401741229F, -0.0234617721F, -0.0704730526F, 0.0721676722F,
        0.0173588656F, -0.097733669F, 0.0271597914F, -0.109119907F,
        0.00988134742F, -0.0967686F, -0.109365612F, 0.0154462969F, 0.0624349862F,
        0.0624710545F, -0.0239290185F, -0.0230683666F, 0.0274258982F,
        0.0740270168F, 0.100274421F, -0.0683927387F, 0.0752103478F,
        0.0689207315F, -0.0686440393F, -0.0405590497F, 0.000566812116F,
        -0.0794885755F, -0.0752918571F, -0.0682878F, 0.00136132468F,
        0.0822929367F, 0.0493433289F, 0.045878496F, 0.0920447335F,
        -0.0124618374F, -0.0338167846F, -0.12743248F, -0.0627357513F,
        0.00222657761F, -0.0583579615F, 0.070320487F, 0.01891548F, 0.0652848929F,
        -0.00375847262F, -0.0738986433F, 0.0274426676F, 0.0618870147F,
        -0.0909840912F, -0.00907572731F, 0.0170310419F, -0.0338100046F,
        0.00954066403F, -0.071609F, -0.0138824116F, 0.0458060056F, 0.0446750857F,
        -0.0413531F, 0.0403883196F, -0.032530386F, 0.0774087831F, -0.0985555351F,
        0.0571816F, 0.0558559299F, -0.0793700144F, 0.0680728182F, -0.0743662566F,
        -0.0215405151F, 0.0953951627F, -0.0151654007F, -0.0244492255F,
        -0.0112648411F, 0.0963194817F, 0.0400536284F, -0.0254605431F,
        -0.0588451698F, 0.0243122131F, 0.0419527553F, -0.0600603856F,
        0.0157870166F, 0.0365500823F, -0.0277644694F, 0.0214815233F,
        0.0134855853F, -0.0112127466F, 0.0988330394F, -0.0398320518F,
        -0.0316848271F, -0.0188318659F, -0.0022514062F, 0.0814159364F,
        -0.000781692215F, 0.0099199228F, -0.000699766213F, -0.0616888F,
        -0.056714531F, 0.0726732314F, -0.068980217F, 0.0740659609F,
        0.0210514423F, -0.0294534266F, 0.00473029446F, -0.0797703564F,
        0.0124524059F, 0.0509610586F, -0.0449094214F, 0.00560693536F,
        0.0313250609F, 0.0310915671F, -0.0295458883F, 0.0317188092F,
        -0.0256318767F, 0.0562015846F, 0.0315484405F, -0.0295783468F,
        0.0352364033F, 0.0172420591F, -0.126080588F, -0.0829446763F,
        0.0137796439F, -0.0394329689F, -0.0314988643F, -0.0550771244F,
        -0.0437911F, 0.110620178F, -0.117417179F, -0.0300194342F, -0.0567727238F,
        0.00284378976F, 0.040858116F, 0.072748445F, 0.0316531F, 0.0175610539F,
        -0.0410849117F, -0.0556467623F, -0.0574016273F, -0.0111509701F,
        0.0555260628F, 0.0385552421F, -0.0831585079F, -0.100093357F,
        -0.00718924729F, 0.00403373875F, -0.0610127F, 0.0287718214F,
        -0.0792084262F, 0.0233930741F, -0.076596044F, -0.0633820072F,
        -0.0852625445F, -0.0389355682F, -0.0478491373F, -0.0613188893F,
        -0.0590876564F, 0.0367357247F, 0.0216303784F, -0.0512238853F,
        -0.112946801F, 0.0641372055F, 0.0437631272F, -0.0578689277F,
        -0.123908162F, -0.0276802722F, -0.113219485F, -0.0350426063F,
        0.00740742963F, 0.00823950302F, 0.0814840421F, 0.0406364724F,
        -0.013422804F, 0.0342450626F, 0.00173292088F, -0.0327229239F,
        0.0356189162F, -0.0912361741F, -0.0121617084F, 0.0397270843F,
        0.0992921144F, 0.020490637F, 0.0725825652F, -0.0336862765F,
        -0.0877884701F, 0.076172F, -0.0626282468F, 0.0306845047F, 0.0688682869F,
        0.0988938957F, 0.0100591658F, 0.00632230425F, 0.0673212633F, 0.0379766F,
        -0.0516885929F, 0.0718675479F, 0.0176778696F, -0.0123183914F, 0.0274282F,
        -0.0701920316F, 0.0553236F, 0.0399735942F, -0.0115851201F, 0.0419675522F,
        -0.0262357201F, 0.105595611F, -0.103392795F, 0.0528740175F,
        -0.0893261284F, -0.0589091443F, 0.00113493088F, 0.0525334105F,
        -0.044665426F, -0.109099798F, -0.00245270459F, -0.0537488051F,
        0.032492321F, 0.0761560053F, 0.0527884923F, -0.125136226F,
        -0.0549499653F, -0.0254456419F, 0.0535340309F, 0.0506257452F,
        -0.0811196268F, 0.0602810346F, -0.0325641148F, 0.0181418248F,
        -0.0737763941F, 0.086139366F, -0.0254856758F, 0.0346210115F,
        -0.0821782649F, 0.0553698502F, -0.0557702929F, -0.015539309F,
        0.0165371913F, 0.0266603567F, -0.0545702726F, -0.0525319092F,
        -0.0191090293F, 0.0120490361F, 0.00753033254F, -0.0856406912F,
        -0.0100974953F, 0.0508233681F, 0.0729130208F, -0.0630289689F,
        -0.0131869931F, -0.0700023919F, -0.0478544161F, 0.000986035098F,
        -0.0331057198F, 0.0269145481F, 0.026607994F, 0.0577351786F,
        -0.0341758169F, -0.00278751156F, -0.0811939612F, -0.0344320312F,
        -0.00217664125F, -0.0517529696F, -0.0604731068F, -0.0685085F,
        -0.0561844781F, 0.0449642502F, 0.0584503524F, 0.046569854F,
        -0.0793065205F, 0.0236230027F, 0.0865578502F, 0.0763642043F,
        0.0584133379F, 0.078070946F, -0.108686157F, -0.0657586604F,
        0.0315712541F, -0.061190512F, 0.0528427288F, 0.0288970955F, 0.029493276F,
        -0.00245901453F, 0.0395480208F, -0.0152803222F, 0.0402348265F,
        -0.0219135955F, -0.00613812497F, 0.0316781886F, -0.0131257335F,
        0.0724167153F, -0.0204001982F, -0.00862101093F, -0.0162785463F,
        0.0377226025F, -0.0203111749F, -0.0357766449F, 0.09022744F,
        0.0598962083F, 0.0612087511F, -0.0655630156F, -0.0977039561F,
        -0.0654708296F, -0.0102700833F, -0.0525344796F, -0.0637273416F,
        -0.0540390387F, 0.00700640026F, -0.0981509164F, -0.0435142033F,
        0.000174483415F, -0.0631063133F, -0.103163123F, -0.0120349322F,
        0.0702782646F, 0.0446693785F, -0.0211434029F, -0.0513512716F,
        0.0550615564F, -0.0644870624F, 0.0615087673F, -0.0350633934F,
        -0.02449378F, -0.0933691859F, -0.0915972441F, -0.0895049F,
        -0.0556158051F, -0.0594300218F, -0.0167738218F, 0.0415878035F,
        -0.0149120158F, -0.0294104386F, -0.0708389059F, -0.0545432791F,
        -0.0285672732F, -0.0004087165F, -0.0103097074F, 0.0347321369F,
        -0.0614845119F, 0.0663560927F, -0.0050265654F, -0.030536145F,
        -0.0592770725F, 0.0635103956F, 0.0586633161F, 0.069265537F,
        -0.0887821242F, -0.0378297716F, 0.00153762568F, -0.0447970815F,
        -0.0686409399F, -0.0620936F, -0.0547947809F, -0.0920106694F,
        -0.0542136282F, -0.0725627318F, 0.0367235132F, -0.0387544148F,
        -0.0149447825F, -0.0584862418F, 0.041346889F, -0.0777719F, 0.0668365359F,
        0.101218194F, -0.0351549089F, -0.00182744418F, 0.0747432709F,
        0.0702841878F, 0.0726170167F, 0.0595383607F, -0.0140045322F,
        -0.0270718113F, -0.0735816807F, 0.0685776696F, -0.0136852274F,
        0.00101302029F, -0.0805400163F, 0.0294587854F, 0.0755949F, 0.0690578818F,
        0.0662954077F, 0.0465177447F, 0.040942017F, 0.0455175452F,
        0.00479027862F, 0.0202540569F, 0.0138518903F, -0.0618252307F,
        0.0343341194F, 0.0292626061F, 0.0863116384F, 0.0360039F, 0.0564937592F,
        -0.00836022664F, -0.06059324F, -0.0128314169F, 0.0617649F, 0.0682447255F,
        0.0415826179F, -0.0884186F, -0.021829132F, -0.0531840958F, 0.0684751719F,
        -0.0111750299F, -0.0726010203F, -0.057704404F, -0.0194917321F,
        0.00719947787F, 0.029852489F, -0.0464259274F, 0.0219854079F,
        0.0629339218F, 0.0617786497F, 0.0039397832F, 0.115673333F, 0.0893354639F,
        -0.112344F, 0.0176402684F, 0.00499235606F, 0.0390816256F, 0.0556123704F,
        0.0329537466F, -0.00432564737F, 0.0153875025F, 0.0776579678F,
        0.0310596041F, -0.00852630567F, -0.0848936588F, -0.0162885506F,
        0.015436844F, 0.00954939146F, -0.0225563422F, -0.00725079933F,
        -0.0114883361F, 0.0139214769F, 0.0679445267F, -0.0143081378F,
        -0.02132117F, -0.0604456961F, -0.0893930867F, 0.0280922204F,
        -0.0184882488F, 0.0699400157F, -0.0338952765F, -0.0277716145F,
        -0.0488520935F, 0.0322021134F, -0.0518773347F, -0.0831405148F,
        -0.0191267505F, 0.0329268761F, -0.0160849374F, -0.0493052341F,
        0.0522266664F, 0.0605437793F, 0.0221339706F, 0.0614358895F,
        -0.0723078698F, -0.0612670332F, -0.0365742482F, -0.0101460032F,
        -0.0284409225F, -0.0205995291F, 0.000795625441F, 0.0405846536F,
        -0.0387942381F, 0.00978123117F, -0.00200091582F, -0.0626478344F,
        0.0470724441F, -0.0847070962F, -0.0346756F, -0.0408153683F,
        -0.0225775409F, -0.0969793573F, -0.0777105838F, 0.029540265F,
        -0.0296078306F, -0.0619519688F, 0.0540042743F, 0.0463970453F,
        0.0327296369F, -0.0132524185F, 0.0792781264F, 0.0595012642F,
        0.0210792497F, -0.0240513664F, -0.0420084335F, -0.0183748025F,
        0.0116212312F, 0.0551222116F, -0.0146743748F, -0.0581749342F,
        -0.0690394342F, 0.0205173697F, 0.00433864817F, 0.00684967218F,
        0.0952714756F, 0.000182444492F, -0.0500851087F, -0.00519488F,
        -0.0109120198F, -0.0355937518F, 0.0650715455F, -0.0413791686F,
        -0.00369524467F, 0.000382678205F, 0.0446049683F, 0.0522046052F,
        0.0634712055F, -0.0218627825F, -0.0181495622F, -0.00932568777F,
        0.00847107824F, -0.107750289F, 0.0589181669F, 0.0873533562F,
        0.0691172406F, 0.0545805953F, 0.02376852F, 0.0552501976F, 0.0413253456F,
        0.0631238148F, -0.0369670875F, 0.0505636968F, -0.00248937518F,
        -0.0471842028F, 0.0942978784F, -0.0189356431F, -0.0235019717F,
        -0.0620018914F, 0.0237277485F, -0.00278521911F, -0.0570466854F,
        -0.0388981625F, 0.083761178F, -0.0364750847F, -0.011305755F,
        0.0326201059F, 0.0206971467F, -0.0302800909F, -0.0365984067F,
        0.015880676F, 0.00238166F, -0.0363044105F, -0.103098132F, -0.0671824813F,
        0.0439706184F, -0.0823585168F, -0.0798349902F, 0.054666087F,
        0.0935209394F, 0.0725075305F, -0.0508592688F, -0.0139751919F,
        0.00404087547F, -0.0217029434F, -0.0898543224F, -0.00244961469F,
        -0.0317197889F, 0.0716895461F, -0.0765179321F, 0.0787256882F,
        -0.0433398671F, -0.0255659502F, -0.0622453168F, 0.0190471411F,
        -0.0729100779F, 0.0492055155F, -0.0184016973F, -0.0553183258F,
        0.0171482209F, 0.00876302738F, -0.0565918833F, 0.021859413F,
        -0.0241589043F, -0.0753311291F, -0.0508095175F, -0.0735116154F,
        0.0179860145F, -0.0165508725F, -0.00155305082F, -0.0528142F,
        -0.0443893038F, -0.0291636828F, 0.0226239767F, 0.0791136846F,
        0.0664806291F, 0.0418041162F, 0.0213647727F, -0.0118072033F, 0.0946645F,
        0.0665316582F, 0.0514054298F, 0.0557348207F, 0.0192199312F,
        0.0768844709F, -0.0518383458F, 0.0162225403F, -0.0131540271F,
        -0.0592903085F, -0.0693678409F, 0.0330569856F, 0.0296873339F,
        -0.0508513451F, -0.082376726F, 0.0013812473F, 0.100666329F,
        0.0285544973F, 0.0240547713F, -0.0109664183F, 0.00640258472F,
        -0.00948109105F, -0.0594879054F, 0.0138824331F, -0.0724738166F,
        0.0664707199F, -0.0488012135F, 0.0533462949F, 0.0769513398F,
        0.00230000517F, 0.000982371857F, -0.0807234198F, -0.0898116529F,
        0.00628814241F, 0.0863418058F, -0.0916058868F, -0.016246371F,
        -0.0253240783F, -0.0333966091F, -0.0614336431F, 0.0442604832F,
        0.078141652F, -0.0279459823F, 0.00730614224F, -0.0553345494F,
        -0.0685215145F, -0.0964118689F, 0.04620938F, 0.049037613F, 0.0504583418F,
        -0.0263066906F, -0.0795387924F, 0.047791522F, 0.11048118F,
        -0.0274223704F, 0.060599722F, -0.0780075416F, -0.0272335969F,
        -0.0206920542F, 0.0565429032F, 0.0257555898F, -0.053254921F,
        -0.0295024626F, -0.0377364345F, 0.0318385512F, -0.0204046126F,
        0.045870468F, -0.0543317F, 0.0239384323F, -0.0196500272F, 0.0510667823F,
        0.0965076163F, -0.0216389094F, -0.0448796935F, -0.0828402564F,
        0.0664558F, 0.0796201155F, 0.0343614221F, 0.00334550743F, -0.0384614393F,
        0.0273759346F, 0.0512033775F, 0.0131259207F, 0.0754522458F,
        0.0868712068F, -0.0159232281F, 0.0526113473F, 0.0878900215F,
        -0.0696552172F, 0.0519240536F, 0.0509258918F, 0.00449121371F,
        0.046697665F, 0.0199022982F, -0.0681114942F, -0.0914609954F,
        0.00181833352F, -0.0207303986F, -0.0714563876F, -0.00274884934F,
        -0.0360782593F, -0.0171572398F, 0.0107107963F, 0.0139933461F,
        -0.107600532F, 0.078654F, 0.057791397F, 0.037436232F, 0.0618429072F,
        0.0718016326F, -0.010478789F, 0.0142448889F, -0.0081455512F,
        -0.0683678389F, -0.0827827677F, 0.0185220093F, -0.0162039921F,
        0.119285442F, -0.0477663949F, -0.0621766932F, 0.0176720824F,
        0.0481811129F, -0.0118124923F, 0.0018674949F, -0.00566767342F,
        -0.0766965F, -0.105495274F, 0.019264156F, 0.0294562932F, -0.0594448745F,
        -0.0192924757F, -0.0219121259F, -0.0408117585F, -0.0286542624F,
        0.00150527281F, 0.0296406131F, 0.0320484452F, 0.0177114066F,
        -0.00355809066F, 0.00652829185F, -0.0245887525F, -0.00357752386F,
        -0.0761096179F, 0.0818630308F, 0.0390805937F, 0.0199346244F,
        -0.0357658714F, -0.0328954905F, 0.0750673413F, 0.0875004828F,
        -0.0690671951F, -0.0713706F, 0.0680980906F, 0.0785095F, 0.0214891266F,
        0.0608649217F, -0.0345416702F, 0.0698649213F, -0.0227733571F,
        0.0447164401F, -0.0608875901F, -0.0237663109F, -0.0489776731F,
        0.0638254285F, -0.0845099613F, 0.107948966F, 0.0322046466F,
        0.0198053289F, -0.00382184819F, -0.0431207046F, 0.0320355F,
        -0.0872274041F, -0.087987639F, 0.0731761307F, -0.0514517464F,
        -0.0832508504F, 0.0323480517F, -0.073531054F, 0.101192F, -0.0105706062F,
        -0.0159923788F, 0.105261587F, 0.0223859232F, -0.0462132171F,
        0.0989251658F, 0.0998554155F, -0.0161625817F, 0.0543700233F,
        0.0620569438F, -0.0563643F, -0.0649001151F, -0.0960354209F, 0.055551447F,
        0.0158365685F, 0.0929343179F, 0.0979117751F, 0.0862393528F, 0.101325236F,
        0.00547013804F, -0.0157521367F, 0.00285931374F, 0.0685550198F,
        0.0840531141F, -0.107762076F, -0.0164382085F, -0.0628516674F,
        -0.00145650725F, -0.105621032F, 0.0459188633F, -0.0458783954F,
        0.102297559F, -0.0411311761F, -0.0263425447F, 0.016707439F,
        0.0228988249F, -0.0689993873F, 0.0709028915F, -0.00475000218F,
        0.077355355F, 0.0794265866F, 0.0867620558F, 0.0344675146F,
        -0.0343504623F, -0.0118074641F, 0.0133467661F, -0.0523883328F,
        0.128624201F, -0.00396700809F, 0.0461683087F, 0.0492857918F,
        0.0241904128F, 0.0414498374F, 0.0602406375F, 0.0524815433F,
        0.0798196867F, -0.0264158212F, 0.0270404425F, -0.0737976953F,
        0.0351218544F, 0.00719216F, 0.0711527094F, -0.0115633421F,
        -0.0645452142F, 0.0213198569F, -0.00129139074F, 0.118124098F,
        -0.0376229584F, -0.0385807417F, 0.0734247416F, 0.0255288817F,
        -0.0749956742F, -0.00373147894F, 0.00479500741F, 0.0810227394F,
        -0.00216163299F, 0.0592267364F, -0.0389710888F, -0.0780081749F,
        -0.0570655428F, -0.00112422F, -0.0971869081F, -0.091971755F,
        -0.0568959527F, -0.0132132722F, 0.0341433808F, 0.0473113507F,
        0.0517517254F, -0.0239446517F, -0.0202718135F, -0.0214685444F,
        -0.0711218F, -0.0383762494F, -0.0869302303F, -0.0537512563F,
        -0.0106322924F, -0.0590319484F, 0.0644414648F, -0.0557408F,
        -0.0859558731F, 0.0635339245F, 0.0439240523F, -0.0775771439F,
        -0.0468355045F, 0.0182767678F, -0.00453291321F, -0.0421423651F,
        0.0379591435F, -0.0792615F, 0.0372447744F, -0.0100635868F,
        -0.0252817143F, -0.00917129591F, 0.031595014F, 0.0153462077F,
        -0.0238122549F, 0.0118049448F, -0.0641087219F, -0.090771541F,
        0.0551853217F, -0.105691306F, -0.0335539542F, 0.0358586349F,
        -0.0270070247F, -0.0871157125F, 0.0240442492F, 0.0681983307F,
        -0.0663999096F, 0.0389184356F, -0.0880336091F, -0.0520767681F,
        0.00536304852F, 0.0544037819F, 0.0143881813F, -0.0199490488F,
        -0.021520013F, -0.0829768851F, 0.0387907438F, -0.0348574631F,
        -0.0294103213F, -0.0403332524F, -0.0258305762F, 0.0995099694F,
        -0.00675841607F, -0.0911523178F, 0.00885709375F, 0.0296862591F,
        -0.0742891729F, -0.0384058543F, 0.0625634119F, 0.0615278333F,
        -0.0112184128F, 0.0537470542F, 0.0778530836F, 0.00601641182F,
        -0.00140362466F, 0.0114386631F, -0.0752499476F, 0.0732394308F,
        0.00577080715F, 0.0373385698F, -0.0501032695F, 0.0692987442F,
        -0.00735847838F, -0.0454274267F, 0.00832084566F, -0.0022098762F,
        -0.107291557F, -0.00618148083F, 0.0694033876F, 0.0172966607F,
        -0.0706620738F, 0.00120357925F, 0.0812799558F, -0.0224533491F,
        0.0849232F, -0.0344069451F, 0.0310421363F, 0.10997244F, -0.00584215391F,
        0.117582731F, -0.0506033041F, -0.0572724193F, -0.0894982889F, 0.0830188F,
        0.0108495308F, -0.0571921691F, 0.0731675103F, 0.0549862385F,
        -0.0225646887F, -0.0727395862F, -0.0486477092F, 0.022870278F,
        0.053969685F, 0.116962515F, 0.0176789351F, -0.0388925746F,
        -0.0538116023F, 0.0278190821F, 0.0271701701F, -0.0277606435F,
        -0.0537626F, 0.0815009326F, 0.0271400157F, 0.0278669391F, 0.0886114836F,
        -0.0480777584F, 0.0289260317F, -0.0113193681F, 0.0259586051F,
        0.0832372606F, -0.0457732752F, -0.0222531855F, -0.0330602936F,
        0.08031746F, 0.107747942F, 0.0408701263F, -0.0265317913F, 0.00668566488F,
        -0.00254237792F, -0.0413960256F, 0.102706566F, -0.00839257892F,
        -0.0701358244F, 0.00169585692F, -0.0825515687F, 0.0476536117F,
        -0.0314503834F, 0.0585231632F, 0.0249715801F, -0.0408258848F,
        0.00590455299F, 0.0645659342F, -0.0595705882F, -0.0196359F,
        -0.0010951492F, -0.117129929F, 0.0371712372F, 0.0535124391F,
        0.0484329872F, -0.0732653588F, -0.0137188453F, 0.0322751328F,
        0.0678989515F, -0.110757679F, -0.0188638382F, 0.0405938588F,
        0.00172934728F, -0.0751135871F, -0.0506783426F, -0.0902079344F,
        -0.0366576239F, -0.0262917485F, 0.0415774733F, 0.042919606F,
        0.053364303F, -0.028291665F, 0.0711037889F, -0.0119551122F,
        0.0111323316F, -0.00758610759F, 0.0874698907F, -0.0640255362F,
        -0.0857854038F, -0.0798043087F, 0.0180748F, -0.00638178037F,
        0.0177376922F, 0.0214289408F, 0.0397953428F, -0.0605628602F,
        0.0242391471F, 0.0474415869F, -0.027099004F, 0.0737714767F,
        -0.0803056136F, -0.0560478605F, 0.0222698189F, -0.0606879257F,
        0.0288147461F, 0.0844691694F, -0.00151496276F, -0.0348314978F,
        -0.0717839524F, -0.0461189225F, 0.0400511697F, 0.0394998677F,
        -0.0350452214F, 0.0845215544F, -0.00560589228F, 0.106867142F,
        -0.0611937F, -0.0527478792F, 0.0435486436F, -0.0152085572F,
        0.0921025127F, -0.0423788652F, -0.00505528552F, -0.0170723926F,
        0.114080697F, -0.107705474F, 0.041661296F, 0.0692294091F, -0.0306810364F,
        0.108384468F, 0.077183567F, 0.05087718F, 0.000155558766F, -0.0308054853F,
        0.098140873F, 0.0103708357F, -0.00343471416F, -0.0469745882F,
        -0.0406302437F, 0.0435800441F, -0.139695287F, -0.0991324186F,
        0.0582966916F, -0.0112967389F, 0.0696394071F, -0.0747591928F,
        0.0345635973F, 0.1001518F, -0.00780932093F, -0.0546877235F, 0.076316826F,
        0.0496803038F, 0.117618129F, 0.0995622277F, -0.0455838405F,
        0.0217679013F, -0.058318723F, 0.0726486146F, 0.0434549488F,
        -0.108864561F, 0.00617057F, 0.0241779275F, -0.0560517572F, 0.0192297213F,
        0.0450019389F, -0.0055104685F, 0.0995575264F, 0.0574925244F,
        0.0864899084F, -0.0773563F, 0.0238595325F, -0.00233405409F,
        0.0077158357F, -0.0590248629F, 0.0733996853F, 0.0272745658F,
        -0.0566612966F, -0.0255460069F, 0.0895680636F, -0.0313876048F,
        -0.0522770584F, -0.0133668371F, 0.0494303927F, 0.0128465844F,
        -0.0892223269F, 0.0289551876F, -0.0253910515F, 0.0104453387F,
        0.00580082135F, -0.0583979674F, 0.0383765474F, -0.0249688253F,
        -0.037686225F, 0.0321337767F, -0.04115301F, -0.0724095926F,
        0.0615179799F, 0.0644255877F, 0.0400302075F, -0.0295508225F,
        0.0226049833F, 0.0414173268F, 0.0793752894F, -0.0122728366F,
        0.0573819205F, -0.114913963F, -0.0290167108F, 0.0533395261F,
        -0.0380933955F, 0.0150797162F, 0.0542129129F, 0.0878687724F,
        0.00887248851F, 0.0423032269F, -0.0537390113F, 0.0843785629F,
        0.0693233758F, -0.00541619072F, 0.0193600841F, 0.0982923284F,
        -0.0682186112F, -0.0217527412F, 0.0122900428F, -0.0306941476F,
        -0.0244400185F, 0.0625991151F, 0.0506774485F, -0.016734099F,
        0.058912497F, 0.0286882706F, 0.0353945866F, -0.00845270418F,
        -0.0903825164F, 0.0722772703F, -0.0240986142F, 0.0261212792F,
        0.00494983327F, -0.03663259F, -0.0390530936F, 0.0892455056F,
        0.0215697158F, -0.0388721712F, 0.0388833843F, 0.0716465786F,
        -0.0431883633F, -0.0134493178F, 0.0286413766F, -0.0159809366F,
        0.00860121287F, 0.0608753338F, 0.0338854194F, -0.0499237217F,
        -0.0255080536F, -0.0319561772F, 0.0693930909F, 0.0641529337F,
        -0.0868461952F, -0.0732228309F, 0.00866800547F, -0.0530831628F,
        0.0241706576F, 0.0680746585F, 0.0148472162F, -0.0279833786F,
        -0.0786541253F, 0.0739113614F, -0.00350010744F, 0.0463032313F,
        -0.0501619354F, -0.0596152842F, -0.0299328975F, -0.0624432787F,
        -0.0498791225F, -0.101491585F, -0.00365256495F, -0.0121618826F,
        0.0460375622F, 0.0773380473F, 0.014526438F, 0.0784690306F,
        -0.000759051822F, 0.0134405242F, 0.0852470472F, -0.00947920606F,
        -0.111718111F, 0.052079495F, 0.0615227744F, -0.0636501089F,
        0.0680959672F, -0.0442414246F, 0.0710395277F, -0.0369481072F,
        0.0837653726F, 0.071631F, -0.0905144066F, 0.0284704641F, -0.0175343212F,
        -0.014534181F, 0.0478031896F, -0.0314334892F, -0.0507961512F,
        0.0718330741F, -0.0822828561F, -0.0339188837F, -0.0464974754F,
        -0.0931937769F, -0.0816407874F, -0.0842957273F, 0.027683394F,
        -0.0107633453F, -0.0872861147F, -0.0730406642F, -0.0604091026F,
        -0.0679525286F, -0.00424084952F, 0.0734078661F, 0.0232240614F,
        0.0161105208F, 0.04341745F, -0.0218712F, -0.0434597395F, -0.00418208167F,
        -0.0288994722F, -0.0322068483F, 0.0530085191F, -0.0357376486F,
        0.0589621179F, -0.051744733F, 0.0440868884F, -0.0564069748F,
        0.0733869299F, -0.0663572401F, -0.00778694265F, -0.11529661F,
        -0.0125890924F, 0.047916986F, 0.119655624F, -0.054635115F,
        -0.0035096854F, 0.083226487F, -0.0725747421F, -0.0880987123F,
        0.0282331686F, 0.039905075F, 0.0754672438F, -0.0775387809F,
        0.0519987531F, -0.146751463F, -0.00643517869F, -0.10456495F,
        -0.018032033F, -0.013438642F, 0.134527251F, 0.00434542913F,
        0.0355954692F, 0.0917044133F, 0.0409438163F, -0.0343037434F,
        0.134195805F, 0.111814462F, -0.00779164536F, 0.0433521755F,
        -0.0026296319F, -0.0628291145F, -0.0275718365F, -0.114841118F,
        0.00761545077F, -0.0585798733F, 0.0658176765F, 0.107162461F, 0.1058845F,
        -0.01716079F, 0.00560907181F, -0.00314960768F, -0.0216431953F,
        0.0746203512F, 0.0965811908F, 0.0737583637F, 0.0598383732F,
        -0.109038167F, -0.111004122F, -0.0246634409F, -0.03061416F,
        0.0925055519F, 0.0224295575F, 0.0739860535F, 0.0689889938F,
        -0.00698230695F, 0.077021651F, -0.0781182051F, 0.090922F, 0.116401568F,
        0.0726546496F, 0.0838914F, 0.0816519186F, 0.0337025523F, 0.0463622883F,
        -0.112405553F, 0.111459836F, 0.0116337063F, 0.00908215437F,
        0.0286890734F, -0.00447350135F, 0.131593764F, -0.0584458448F,
        0.0242338292F, 0.0456144623F, 0.0491885878F, -0.00107311876F,
        -0.0323742777F, -0.0593224801F, -0.0842397287F, 0.0903898403F,
        -0.0763564184F, -0.00434581144F, -0.0120696751F, 0.0495374F,
        0.0694320053F, 0.000570669421F, 0.02061937F, -0.0303351935F,
        -0.0537688434F, 0.0330861881F, -0.0138281183F, 0.127327755F,
        -0.0142792724F, 0.0634520203F, -0.0295498632F, -0.00235228171F,
        0.0571404956F, 0.0996612683F, -0.0888388082F, 0.0400650576F,
        0.00182161026F, 0.036974702F, 0.109293364F, 0.016280394F, 0.0275802519F,
        -0.00970922224F, -0.0546321198F, 0.0827017426F, -0.0785241947F,
        -0.0787794665F, -0.0576983392F, 0.00229400164F, -0.093731083F,
        -0.0781414658F, -0.0509180352F, -0.0495116971F, 0.0116581991F,
        -0.0448499583F, 0.00340146245F, 0.0509989448F, 0.00419737399F,
        0.071974054F, -0.0270242617F, -0.0352753103F, 0.0316237323F,
        0.0572923273F, -0.0154999848F, -0.0158588924F, 0.0151501028F,
        -0.0616778433F, 0.0735580325F, 0.0380219445F, -0.0770369619F,
        -0.0407833494F, -0.0022388224F, -0.010643648F, -0.0516732074F,
        0.0221523792F, 0.0320265889F, -0.0320660882F, -0.0521519817F,
        0.0499160923F, 0.0395187102F, 0.0291342046F, -0.0555494539F,
        0.0617128201F, 0.0145291276F, 0.00325052766F, 0.0595674068F,
        0.0521520376F, 0.0223651435F, 0.0673389882F, 0.0394398943F,
        -0.0841724724F, 0.0130609609F, 0.0118402336F, -0.0229334701F,
        -0.0186960846F, -0.0246841684F, 0.038940303F, 0.0796452388F,
        -0.0443334877F, -0.0223967768F, 0.0775679424F, 0.0565436929F,
        0.00986583345F, 0.0768849701F, 0.00187267549F, -0.00438469974F,
        0.0314829871F, -0.0373733528F, -0.0459967107F, 0.0286964104F,
        -0.02532655F, 0.000416468363F, -0.060006015F, 0.0383739658F,
        0.00176986447F, 0.035574954F, -0.0035289533F, -0.0464998074F,
        0.0372107551F, 0.022786025F, 0.0535642914F, -0.0648657F, -0.100121044F,
        0.0132442694F, 0.0357680097F, 0.045296587F, -0.00950213801F,
        0.00987168867F, -0.0837352723F, -0.0941763669F, 0.0271126274F,
        0.0130909802F, -0.0158612281F, 0.00286019407F, -0.0822604299F,
        -0.042332992F, -0.0494923964F, 0.0690683499F, -0.0816455334F,
        -0.0118929641F, 0.0422748551F, 0.00183015282F, -0.0558272041F,
        0.0217330176F, -0.0625338927F, 0.057848338F, 0.00539235678F,
        0.0498919711F, -0.010995796F, -0.0464417115F, -0.130747899F,
        0.0206535142F, -0.0338191F, 0.00496747484F, 0.0547036305F,
        -0.0726746395F, -0.0916940346F, 0.0559906363F, 0.0354929827F,
        -0.0614932328F, -0.0853980184F, -0.0312589444F, -0.0612488799F,
        0.0306995809F, -0.00752128661F, -0.075631313F, 0.0345646515F,
        0.00618881267F, 0.0413912758F, -0.0239445567F, 0.0293038618F,
        0.0432680212F, -0.0639744326F, 0.0177599397F, -0.060891293F,
        0.0314247645F, -0.0314868353F, 0.066846855F, 0.031865757F, -0.101786144F,
        -0.100647338F, -0.0797278136F, -0.0808069557F, -0.0679119676F,
        0.0867019221F, -0.0498453677F, 0.0585350692F, -0.0549098104F,
        -0.077989772F, 0.034034F, -0.0197603572F, -0.0426261537F, -0.038347736F,
        0.0734541118F, -0.0465391874F, 0.0498943068F, 0.0233163163F,
        0.0328935198F, -0.0850310698F, -0.0668066144F, -0.0377331339F,
        -0.0930961072F, 0.0604378544F, 0.0143443663F, -0.0868963525F,
        -0.0206540339F, 0.0592138916F, -0.0698715672F, -0.0289932042F,
        0.0348421037F, -0.0666607171F, 0.043090377F, 0.0837364718F,
        -0.0226722807F, -0.0813007355F, -0.0161585864F, 0.0356247202F,
        0.0580531284F, 0.00716171786F, -0.0609691702F, 0.0223787911F,
        -0.0398858115F, 0.0624535345F, -0.104200013F, 0.0924534723F, -0.0934053F,
        -0.0319064222F, 0.0221804343F, -0.00595312472F, 0.0564994067F,
        0.0133042401F, -0.0261177514F, -0.0217537489F, -0.0385319106F,
        -0.0383462831F, 0.053495843F, -0.0639098063F, 0.0312242322F,
        -0.0531453453F, 0.0164547395F, -0.0109249465F, -0.0468427353F,
        0.0742111802F, 0.0209737029F, -0.00426294F, -0.0294248F, 0.0878446922F,
        0.0720138475F, 0.0761081353F, -0.0291058738F, 0.0641206875F, 0.0854609F,
        0.0150427036F, 0.0774668F, -0.0481318086F, 0.068375513F, -0.0454672F,
        0.0418185331F, -0.0281239413F, -0.0965718776F, 0.0524788052F,
        -0.0227431823F, -0.0752781F, 0.0767076537F, -0.0594874062F,
        0.0512123965F, 0.0496317148F, -0.0713525414F, 0.0637338459F,
        0.0378680974F, 0.017072048F, -0.0664521083F, -0.0185693037F,
        -0.080632396F, 0.0231614634F, 0.0395095274F, 0.0706990138F,
        0.0265082307F, 0.0506575853F, 0.0901438221F, 0.0590180792F,
        -0.0375280343F, 0.0854464099F, -0.0175765939F, -0.0163690653F,
        0.0223974958F, -0.0774748698F, -0.0322011113F, -0.0504454784F,
        -0.0647245497F, -0.00525202742F, -0.088245675F, -0.037682835F,
        -0.0141040478F, 0.0185581762F, -0.0447373949F, -0.0314681865F,
        -0.0655600056F, 0.00987206306F, 0.0746853873F, -0.00775929727F,
        -0.0868605301F, 0.040568348F, 0.0258909464F, 0.0138634788F,
        -0.0337859653F, 0.0523707718F, 0.0505539365F, -0.058695659F,
        0.0427626818F, -0.0828314424F, -0.00460105063F, -0.0361662507F,
        0.0388592891F, -0.0132011306F, 0.108769491F, -0.0349803679F,
        0.106808394F, 0.0205471125F, 0.0168339107F, 0.0972421616F,
        -0.0654849336F, -0.0328294113F, 0.0398130864F, -0.0612058677F,
        -0.0161714461F, -0.0293318387F, -0.00927798264F, 0.0336682387F,
        0.0716563836F, 0.045391202F, 0.0609649F, 0.0579050444F, 0.0629447F,
        -0.035011258F, 0.053179618F, 0.0566405021F, -0.081290938F,
        -0.0935526863F, 0.0173325967F, -0.0290041082F, 0.0468885563F,
        -0.0761619881F, 0.0110960435F, 0.00476858858F, -0.0367796F,
        0.0420867316F, -0.0669670179F, 0.0360692181F, 0.0157852937F,
        0.0213710479F, -0.0545701236F, -0.0144353108F, 0.034805268F,
        -0.00260868133F, -0.0845918879F, -0.0527903289F, 0.058062721F,
        -0.073271893F, 0.0377987698F, -0.0854211524F, -0.000407344894F,
        0.0248508062F, 0.00929756556F, -0.107756458F, -0.0428562276F,
        0.0368104875F, 0.022340687F, 0.0197910406F, 0.0779771432F,
        -0.0162218027F, 0.0168741923F, 0.0953073949F, 0.0735004917F,
        -0.0212096367F, -0.0570412911F, -0.00584090361F, 0.0152465506F,
        0.0616892911F, -0.062201757F, -0.00368801691F, 0.0947722495F,
        0.0820208788F, 0.0139474189F, -0.020070333F, 0.124960758F,
        -0.0692521781F, -0.0111422203F, -0.0375598818F, 0.118627109F,
        -0.00708986539F, -0.0946833566F, 0.0321119577F, 0.0101542706F,
        -0.00666557F, -0.117795654F, -0.124949619F, 0.0257469732F, 0.0302432105F,
        -0.0865258127F, 0.0566118322F, -0.0465784781F, -0.063975513F,
        0.0125699677F, 0.0154070426F, -0.00185644277F, 0.0458896235F,
        -0.0175652131F, 0.0160858016F, -0.0440654F, -0.0315167531F, -0.0609199F,
        0.0524340943F, 0.0213516764F, 0.114263467F, -0.0292600207F, 0.123628639F,
        -0.0325342491F, 0.0882898271F, 0.0212895628F, 0.00485370075F,
        0.0831725448F, -0.0243135262F, 0.0223115478F, 0.0444073044F,
        0.0499526151F, 0.0805403069F, -0.0693438873F, 0.00222614361F,
        0.0814626962F, 0.106110968F, 0.124922238F, 0.0304757208F, 0.0933598951F,
        0.0222709775F, -0.0508900173F, -0.0838736892F, -0.0115985461F,
        -0.0136158857F, -0.0644999519F, -0.0575337335F, -0.0870140418F,
        -0.00888583157F, -0.104685314F, 0.118228257F, -0.0988972F, 0.104508705F,
        0.0326382965F, -0.0103334254F, -0.102093235F, 0.0793870315F,
        -0.0692286566F, 0.0270720553F, 0.0507861786F, 0.0175379384F,
        -0.0894947276F, 0.0565865338F, 0.0557979345F, 0.118687533F,
        0.0328671597F, -0.108191766F, -0.0223030709F, 0.0204878412F,
        -0.0528820194F, 0.102726571F, 0.00762774376F, 0.0435710736F,
        0.00538953859F, 0.0352279246F, 0.0215627439F, -0.069571577F,
        0.0520536415F, -0.0097560389F, 0.0260966923F, -0.0179221518F,
        -0.0700061545F, 0.0404093452F, -0.0617791601F, -0.0584063344F,
        0.088049069F, -0.0624299832F, 0.0507888682F, -0.0397603884F,
        -0.0572019927F, -0.0945168212F, -0.0282521676F, 0.0893159285F,
        -0.0975653902F, -0.0356415547F, -0.0719783F, -0.0501237176F,
        -0.0272183493F, -0.0741153285F, -0.146514773F, -0.0986545756F,
        0.0199802872F, -0.0433748104F, -0.0456056558F, -0.117554531F,
        0.00983436871F, -0.109294981F, -0.0433730297F, 0.0857082233F,
        -0.124066986F, -0.085685268F, 0.00762532884F, -0.0954777449F,
        -0.0825946555F, 0.0315915F, 0.0676975921F, 0.0856080651F, 0.0726925358F,
        0.0988097563F, 0.0753865689F, -0.0527177304F, 0.0786578357F,
        0.0548791699F, -0.0986093059F, 0.0794900507F, -0.0126980077F,
        0.0439726822F, -0.0137436651F, 0.0678355619F, 0.0187236164F,
        0.0227736663F, 0.0506823845F, 0.00187097059F, 0.115877584F,
        0.0690932795F, 0.0182254203F, 0.0206364673F, -0.0820601657F,
        0.0308786482F, -0.110864341F, 0.0203245077F, 0.0324923322F,
        -0.0430282056F, -0.0870348439F, -0.131691813F, -0.0171383861F,
        -0.00332574337F, 0.0733903125F, 0.092793338F, -0.00195056165F,
        -0.00774374884F, 0.00134886848F, -0.00027115093F, 0.0517953932F,
        -0.0518206023F, -0.127903968F, -0.0481782369F, -0.102958441F,
        0.0162070282F, -0.025935946F, 0.0185649935F, -0.0671899766F, -0.0862146F,
        0.0762172192F, -0.0566489175F, 0.0174718965F, 0.0797655433F,
        -0.00518703F, -0.0338653065F, 0.00691288849F, -0.125351638F,
        -0.0664990917F, -0.111272827F, -0.125450954F, 0.0662098601F,
        0.0305357594F, -0.0204132721F, 0.00122265075F, 0.069322072F,
        0.0597971305F, 0.0247156564F, 0.0986041501F, 0.00114721409F,
        -0.0239717811F, 0.06841968F, 0.00857047085F, -0.0450756066F,
        -0.0671208724F, -0.0176566076F, -0.0089286631F, 0.0271350443F,
        0.0692687258F, -0.0337425396F, -0.055441048F, -0.0280503388F,
        -0.0679682419F, -0.0727562234F, -0.00728438562F, -0.0948030427F,
        -0.109324612F, 0.0496603511F, -0.0721255392F, -0.0917299688F,
        -0.000235264655F, -0.0149768861F, -0.114145473F, 0.0528115705F,
        0.00176050258F, 0.0647566691F, 0.0174532086F, 0.0164494365F,
        -0.0532550216F, -0.0934978053F, 0.0820402429F, 0.0633707717F,
        -0.0442893244F, -0.0826974958F, 0.0278763734F, 0.007068F, -0.124693431F,
        -0.0104703363F, -0.12863709F, 0.072241649F, -0.0645608455F,
        0.0245653503F, -0.0363947563F, -0.00408634404F, 0.0142072F,
        -0.0726370364F, 0.0595432371F, 0.109501474F, 0.0577859432F,
        -0.0647019893F, -0.0587749593F, -0.036372032F, 0.0456419326F,
        0.0827879086F, -0.0453258082F, -0.0500054359F, -0.0355403237F,
        0.0113976933F, 0.00436362578F, -0.1019952F, -0.0702844039F,
        -0.133976221F, -0.108388081F, 0.0031367687F, -0.117053583F,
        -0.0343319476F, -0.0179408696F, -0.0727839768F, 0.0333932042F,
        -0.0127314785F, -0.0283450671F, 0.0118658543F, 0.00979645178F,
        3.52904608E-5F, 0.0454001762F, -0.0445726439F, 0.047833886F,
        0.0483102463F, 0.0937593505F, 0.0154879047F, 0.00421184814F,
        -0.0629877597F, -0.011210151F, -0.142647371F, -0.107510969F,
        0.0789501145F, -0.0726231933F, -0.0984306857F, -0.0570697747F,
        0.0220636129F, 0.0580267161F, 0.0944026634F, -0.0692942888F,
        0.0366541147F, -0.00764630735F, -0.118566684F, -0.112065397F,
        0.0600054897F, -0.132979438F, -0.0163881816F, 0.0304879062F,
        -0.0778865069F, -0.042530261F, -0.0967507288F, -0.0180501174F,
        0.0135557819F, -0.106890596F, 0.0201795325F, -0.0420516841F,
        -0.0112849167F, 0.0238115173F, -0.0440622531F, -0.0720309764F,
        0.0173060969F, 0.0607267059F, -0.0467614606F, -0.053711921F,
        0.00736195408F, -0.117871359F, 0.0626625F, -0.0312514715F, 0.0521864966F,
        -0.0620441064F, -0.0986336693F, 0.0630725622F, 0.0893430039F,
        0.00817470718F, -0.0319265462F, 0.00206393935F, 0.0734399259F,
        0.0708035901F, -0.0596791729F, 0.0570988245F, -0.0233043712F,
        -0.105088621F, 0.0377142429F, 0.039825771F, 0.0193307307F,
        -0.0700331256F, -0.0505369082F, 0.0598528795F, 0.0565598756F,
        0.0261479113F, 0.0636251569F, -0.0197388064F, 0.0733415484F,
        -0.0265533384F, 0.0709243715F, 0.0524019115F, 0.0282647256F,
        -0.075475432F, 0.100263186F, -0.0103483861F, -0.0543810651F,
        -0.0336402282F, -0.0319372118F, 0.0733088627F, 0.0889115408F,
        -0.0843151286F, 0.000964463456F, 0.106373191F, 0.0936652049F,
        0.0259021465F, -0.0265082866F, 0.0114433616F, 0.0266192909F,
        0.000890538F, -0.00628489535F, 0.0744417906F, -0.0210070852F,
        -0.0820574686F, 0.0692806691F, -0.0816658214F, -0.0685904399F,
        0.00437008869F, -0.11269854F, -0.0215726569F, -0.064829886F,
        -0.106166765F, -0.118723124F, -0.000889532384F, -0.0661681071F,
        0.00933624525F, 0.00558803789F, -0.0344095379F, 0.0689017326F,
        -0.016609285F, 0.107272439F, -0.0961568803F, 0.0432031117F,
        -0.0342455581F, -0.0522503294F, -0.108586363F, -0.037875589F,
        0.0190820117F, 0.0433266647F, 0.0045847334F, -0.08128F, 0.0104641039F,
        0.050216537F, -0.00872257631F, 0.0268896092F, 0.0660941079F,
        0.0331580155F, 0.0130980862F, 0.0112447767F, -0.0170946047F,
        0.00769018615F, -0.0156479254F, -0.0431922898F, -0.0308838934F,
        0.0743448958F, 0.0641771331F, 0.00977147F, 0.0258790851F, 0.0389368497F,
        -0.0165500343F, -0.0310821943F, -0.0307075791F, -0.0242984965F,
        -0.0694339201F, -0.0928629637F, 0.0440240316F, 0.0296963304F,
        0.033964023F, -0.0586467795F, -0.0148292976F, 0.0368209593F,
        0.088312313F, 0.0706950426F, -0.0174097531F, -0.0294823702F,
        0.0399353951F, -0.0695362836F, -0.0574539416F, -0.0658030957F,
        0.00974502F, -0.0160328839F, -0.0735604092F, -0.073694244F,
        -0.0148650352F, -0.110881977F, 0.0506662503F, -0.124803F, -0.036934115F,
        -0.0373465195F, -0.0931670666F, -0.091843538F, 0.0860424563F,
        -0.0431933217F, -0.0354848467F, 0.0378867052F, 0.0379684381F,
        -0.0386215709F, -0.0690682754F, 0.0408853032F, 0.062277291F,
        0.0449800268F, -0.0414627381F, -0.00421455037F, 0.0422801375F,
        -0.0993755832F, -0.0562351644F, 0.0555095077F, -0.0398516506F,
        0.0163682103F, -0.0221993793F, 0.0413348116F, 0.0675266385F,
        -0.0524834841F, 0.0503382F, -0.0624340698F, 0.0609698035F, 0.0547868386F,
        -0.0332785733F, -0.099805139F, -0.0282266047F, -0.0488376617F,
        -0.0235178526F, 0.0581446551F, -0.0275270697F, 0.0324559174F,
        0.0436673947F, -0.0123876734F, -0.0386098772F, 0.0242159776F,
        -0.0114989374F, -0.0177058633F, 0.0100340284F, 0.0431931354F,
        0.0123187983F, -0.00611602888F, -0.0157112628F, -0.0181817F,
        -0.0638527721F, -0.045029629F, 0.0354590714F, -0.0359656215F,
        0.0381272845F, 0.0302908327F, 0.0514349528F, -0.0522783324F,
        0.105556376F, -0.0577916875F, -0.011516883F, 0.0699636191F,
        -0.0795471221F, 0.0771687627F, -0.0830560774F, 0.0665005147F,
        0.0811254233F, 0.0776205063F, 0.0464070924F, -0.0572245568F,
        -0.0192393754F, 0.0245490316F, 0.0903444F, -0.0108322734F,
        -0.0615648068F, 0.0354961716F, -0.0870148614F, 0.0364183672F,
        0.0460211858F, -0.0914159194F, -0.0330245495F, -0.00310983253F,
        -0.0256659929F, -0.0593221746F, 0.0122354589F, -0.0417614654F,
        -0.0526120514F, -0.0580374859F, -0.0680957958F, -0.0761722848F,
        -0.0201655906F, 0.0658099055F, 0.0493575037F, -0.111892417F,
        -0.0436666124F, -0.0531792045F, -0.0142253898F, -0.00526403589F,
        -0.10368903F, -0.0563225411F, 0.0426953435F, -0.0979693085F,
        0.0466405228F, -0.0940793529F, -0.0198247842F, 0.0215946548F,
        -0.0899498314F, -0.00809717644F, -0.0107998578F, -0.0551353395F,
        -0.0608387F, -0.00381335593F, 0.0628340468F, -0.041098047F,
        0.0203997754F, 0.0252749622F, 0.0757756159F, -0.0911286771F,
        0.00599290431F, -0.0264049303F, -0.00205434207F, -0.0389480628F,
        -0.0661668852F, 0.0493003614F, -0.016622467F, 0.0477894917F,
        0.00202589389F, 0.0692752525F, 0.0899921581F, -0.0328457952F,
        0.0163205937F, 0.0284441095F, 0.0381996594F, 0.0642642379F,
        0.0670435652F, -0.0868077055F, 0.0293758418F, -0.0190888923F,
        -0.0754221827F, -0.0705657154F, -0.0565545484F, 0.0904560164F,
        0.0777793601F, -0.0437312871F, 0.0785960332F, -0.0587229319F,
        -0.0023971186F, 0.0382838883F, -0.0682181418F, -0.0791961104F,
        0.0849771F, 0.0079728011F, -0.0651892424F, 0.0591116436F, -0.0673008785F,
        0.00448386418F, 0.015195434F, -0.0417174138F, 0.0425935648F,
        -0.049366042F, 0.0284269899F, -0.0606117956F, 0.0177986808F,
        0.0907817632F, 0.0504594781F, 0.0275584627F, -0.0817662627F,
        0.00811977871F, 0.0227172114F, 0.0671450049F, 0.0952700526F,
        0.0526037104F, -0.0335287601F, 0.0309087597F, 0.0607782491F,
        -0.0222296901F, -0.0478036F, -0.0180857405F, 0.0180476345F, 0.0902284F,
        -0.0102881249F, 0.0510560721F, 0.0543826669F, -0.0689596608F,
        0.000659308513F, -0.0640816092F, 0.0122722425F, -0.0268923435F,
        0.0143956877F, -0.00216210401F, 0.00727307145F, 0.0441035442F,
        -0.0723907948F, -0.0942582786F, 0.0768804923F, 0.011198625F,
        -0.0782654956F, 0.0739533156F, -0.0411423482F, 0.0552922599F,
        -0.0667120889F, 0.0145375133F, 0.0393260717F, 0.0527824201F,
        -0.00844580308F, -0.0682851151F, 0.083432138F, 0.0390355363F,
        0.0156990066F, -0.0569931976F, 0.0260445941F, -0.0490107462F,
        0.0500253476F, 0.0681312829F, 0.0186143108F, -0.0433494262F,
        0.0110935755F, 0.0526372902F, -0.033335343F, -0.0448830761F,
        0.0449888073F, -0.0161899216F, 0.0744067654F, -0.0897626728F,
        -0.0417372659F, -0.0895756558F, 0.0606460087F, -0.0382836051F,
        0.0468180291F, 0.00123594515F, 0.0659607574F, -0.0851667821F,
        0.0434618779F, -0.0479113311F, -0.00662491424F, -0.0572867F, -0.0647573F,
        -0.0449281633F, 0.0343135074F, 0.0430959873F, -0.0538244061F,
        0.0398400798F, -0.0873878226F, -0.00891538151F, -0.0509149395F,
        -0.0156745389F, 0.0772119388F, 0.0017659989F, -0.0548398495F,
        -0.0324218236F, 0.0314204395F, -0.0435820706F, 0.000293052581F,
        -0.0268535335F, -0.0327640697F, 0.0193799641F, -0.00539337704F,
        -0.0939230472F, 0.0772849098F, 0.0901965424F, 0.0658368245F,
        -0.023789214F, -0.0489121415F, 0.0926971138F, 0.0386488549F,
        0.0303999688F, 0.0730860233F, -0.0753473043F, 0.0359067656F,
        0.00468872953F, -0.0778174251F, 0.068998456F, 0.0850448608F,
        0.0674609914F, 0.0718824491F, -0.00410128525F, -0.0649111569F,
        0.0131735466F, 0.0241061673F, 0.0664206F, -0.0232586339F, 0.00220224913F,
        -0.034442693F, 0.0572603643F, -0.0656644776F, -0.0235767346F,
        -0.0885162801F, -0.0717513785F, 0.0316045843F, -0.0134741459F,
        -0.00478579476F, 0.0762390643F, 0.0457458757F, -0.0612534285F,
        0.0672558546F, 0.0659124628F, 0.00813188311F, 0.0579013042F,
        0.0594629869F, 0.0179655124F, 0.0532068275F, -0.065237008F,
        -0.0548219532F, -0.00653246883F, -0.0319323465F, -0.0223234911F,
        0.0338072032F, 0.0831576884F, 0.0323957615F, -0.0329952575F,
        -0.0435769185F, -0.0366582163F, 0.0672678575F, -0.0199756511F,
        -0.0671720356F, 0.0559436232F, -0.0456777886F, 0.0390263535F,
        -0.0696978197F, -0.0586366914F, 0.054711096F, 0.0112672206F,
        0.0860412791F, -0.0516342111F, 0.0675198808F, -0.0497804508F,
        -0.00523648551F, -0.0453865752F, 0.0271265917F, -0.0044060573F,
        0.0765649155F, 0.00480595604F, 0.0353172086F, -0.0698161572F,
        -0.0108361039F, 0.0569303334F, -0.0313523673F, 0.0525068976F,
        -0.037620753F, -0.00199925946F, 0.00953933224F, -0.028260814F,
        -0.0760906339F, -0.0432721637F, 0.0776932761F, 0.089325428F,
        -0.0237240195F, -0.0670173541F, -0.0204443093F, -0.0442006029F,
        -0.0803851336F, -0.0131081101F, 0.0136850476F, -0.0511435047F,
        0.0940614492F, 0.00259568682F, 0.0145905688F, 0.001240768F,
        -0.0663687587F, -0.0340224691F, -0.0576625578F, 0.0319474377F,
        0.0639724284F, 0.00866285F, -0.0389582701F, 0.000557700347F, -0.0916907F,
        0.0536346138F, -0.0593876466F, -0.0442167111F, 0.0784250572F,
        0.0820456073F, -0.0435992181F, 0.00333231571F, -0.0241118018F,
        0.0492345355F, 0.0544038862F, 0.0783914402F, -0.0149584208F,
        0.0486649647F, -0.0851279199F, -0.000347188412F, 0.0337168649F,
        -0.0537728593F, -0.0630925074F, -0.0890948176F, -0.066093348F,
        0.0040755095F, -0.0828200504F, 0.0577053651F, -0.0369056724F,
        -0.073568657F, -0.0539473481F, 0.0432152823F, -0.0112541309F,
        0.0376588255F, 0.0358173251F, -0.0343721807F, -0.0812934712F,
        -0.0167145506F, -0.073032774F, 0.0305750668F, -0.0476683F, 0.0080224F,
        0.0312818848F, -0.0027367F, 0.0138172265F, -0.00211132807F,
        -0.0215191338F, -0.0132703967F, -0.0640305206F, 0.0365998335F,
        -0.0972425714F, -0.0669935495F, 0.0217045881F, 0.0398354977F,
        -0.00485778926F, 0.0608011372F, -0.018169716F, -0.110517323F,
        0.0242510531F, 0.0468364395F, -0.0646463484F, 0.0935398862F,
        -0.050863117F, -0.059625186F, 0.0468494557F, 0.0234653484F,
        -0.0443230346F, -0.0519077405F, -0.121852539F, -0.119169876F,
        0.0437110625F, -0.0520341471F, -0.0547628552F, -0.0544777699F,
        -0.0131091056F, -0.0355883464F, 0.0371914431F, 0.0698245689F,
        -0.0659697279F, -0.0473383777F, 0.024871124F, -0.0560381077F,
        -0.109144323F, -0.0522891507F, -0.0890768915F, -0.0820642859F,
        -0.0783912539F, 0.0844767392F, -0.0521997102F, 0.0343028717F,
        -0.0981935412F, -0.0191345382F, -0.0534769632F, -0.0972039476F,
        -0.0957472101F, -0.0723468512F, 0.0161940511F, -0.0261671599F,
        -0.0523574464F, -0.103826106F, -0.00147882348F, -0.0970911384F,
        -0.124234088F, 0.0873465F, 0.0571354888F, -0.0785816F, 0.00949480105F,
        -0.119292788F, 0.00421190355F, -0.0636225343F, -0.063617304F,
        0.0428888872F, -0.0973082F, -0.0520058759F, 0.00226954557F,
        -0.0284044947F, 0.060021542F, 0.0689473227F, -0.0869530141F,
        0.0898538083F, 0.0365404F, -0.092147626F, -0.059632618F, 0.0279608388F,
        -0.0479118638F, -0.10282442F, -0.048394F, -0.0711723864F, 0.0381605923F,
        0.000680562342F, -0.0572468936F, -0.0440692529F, -0.0342641734F,
        0.0464971401F, 0.0188817866F, -0.0186000261F, -0.032255318F,
        -0.0566618815F, 0.0709115F, 0.0568190888F, -0.0213499498F, 0.0286950916F,
        0.0144983567F, 0.028501926F, -0.0712722242F, -0.0327276215F,
        -0.0977663174F, 0.0347260572F, 0.0590194799F, 0.0683868453F,
        -0.0355479047F, 0.00825792924F, -0.06055215F, -0.0457904823F,
        0.00204642583F, 0.06945315F, 0.0718287751F, -0.0231122691F,
        -0.0279740691F, 0.0388821848F, -0.0794678926F, 0.0891605765F,
        -0.0360476561F, -0.0695328042F, 0.00330723124F, -0.00413146196F,
        0.0101151494F, 0.0947405621F, 0.0579652339F, 0.0542806461F, 0.160807863F,
        0.000774478482F, 0.0802850127F, -0.017695656F, -0.0432483889F,
        0.0207530595F, 0.0872826278F, 0.0619821884F, -0.0338707492F,
        0.0563987233F, 0.0806149095F, -0.0233218763F, 0.0709657893F,
        0.0524962172F, 0.0833802074F, -0.00115405722F, 0.0395536423F,
        -0.0538746789F, -0.0951734111F, 0.00601928122F, -0.00505326036F,
        0.043135684F, -0.0594558083F, -0.00206242F, -0.0727459416F,
        -0.0771056265F, -0.0428069048F, -0.0205117185F, -0.0174495392F,
        -0.0170956198F, -0.0384844579F, -0.0837065056F, -0.0398638584F,
        0.047447484F, -0.0764267072F, -0.0481835417F, -0.0725552142F,
        -0.131115898F, -0.0323300436F, -0.00394118624F, -0.0564350709F,
        -0.0871393383F, 0.0419708155F, -0.00650256872F, -0.0215112586F,
        -0.0773847252F, -0.0346118584F, -0.124613531F, -0.0565044582F,
        -0.0213387F, -0.000576882274F, -0.0678463F, -0.0848950297F,
        -0.0656546876F, 0.0430854112F, -0.0292466767F, -0.10814511F,
        -0.129207879F, 0.0372942686F, -0.00336830039F, -0.0118191475F,
        0.0406927243F, 0.00438929209F, -0.0286846142F, 0.0608121864F,
        -0.0249699261F, -0.0455847F, -0.0850940645F, 0.0250773653F, -0.07053902F,
        0.0342740789F, 0.0356263556F, -0.121440567F, 0.028439261F,
        -0.0640199333F, -0.00490441639F, -0.0141040022F, -0.0363996029F,
        -0.122409016F, -0.00428270129F, 0.0117155416F, -0.0019393F,
        -0.0961624607F, -0.0526648909F, -0.011563208F, -0.0845829248F,
        -0.0763857588F, -0.0768638849F, -0.111488141F, 0.00420040218F,
        0.0202276129F, 0.0121591743F, -0.0810122862F, 0.0551937521F,
        0.0993063673F, 0.0608533956F, -0.0947733819F, -0.0444965102F,
        0.0550653599F, 0.0419265702F, 0.0763676167F, 0.0420199893F,
        0.0106692407F, -0.0658444166F, -0.0707123652F, 0.0289252F, 0.0644968674F,
        0.0461836681F, -0.0309255198F, 0.00874184258F, 0.118455328F,
        0.0573416166F, -0.00261226902F, -0.0170037057F, -0.0908517092F,
        0.0297137443F, -0.0914935768F, 0.0701508597F, -0.0515318513F,
        -0.00321071642F, -0.107218176F, -0.100691661F, 0.117358364F,
        0.0486980975F, -0.0682932734F, 0.0983398F, -0.0193472933F,
        -0.0395222418F, -0.0649570301F, -0.104677856F, 0.0442755F,
        -0.00976445246F, 0.0300078914F, 0.1076243F, -0.119028747F, 0.014799078F,
        0.0135463309F, 0.121382385F, 0.023529008F, 0.145851731F, 0.120554477F,
        0.145127088F, 0.0808313936F, 0.101103686F, 0.0659384355F, 0.101047188F,
        0.0469322614F, 0.0315534025F, -0.00254705735F, 0.0530004725F,
        0.0421875603F, 0.00246599573F, 0.0185913704F, 0.123289756F,
        -0.0682494342F, 0.0682718307F, 0.104377821F, 0.0958527476F,
        0.0249141864F, 0.0822388232F, 0.118914686F, -0.0139010129F,
        -0.114126675F, -0.0379418135F, -0.0233837869F, 0.0219678506F,
        -0.0743283853F, 0.0797830671F, -0.131943762F, -0.0378728434F,
        -0.0431564264F, 0.0598584488F, -0.104574606F, 0.0628388226F,
        0.00569743756F, 0.0564730801F, 0.101829335F, -0.0482211821F,
        0.114205405F, -0.0926091447F, 0.0110581322F, 0.0488651544F,
        -0.110542394F, 0.0584807955F, 0.0255549289F, -0.00273086876F,
        -0.0317965262F, 0.00662318571F, -0.132147402F, 0.117363356F,
        0.163214967F, -0.0179070253F, 0.0928956941F, -0.0469798706F,
        0.000810578291F, 0.0801677257F, 0.0488601737F, -0.0604637489F,
        -0.0175592303F, -0.0027385042F, -0.0280864183F, 0.012179628F,
        0.0253075771F, -0.0031681098F, -0.0978711918F, -0.0653805211F,
        -0.0154161938F, 0.00367712392F, 0.0389071964F, -0.0197169296F,
        0.0463946F, -0.00959944539F, 0.0275355633F, -0.00935170054F,
        -0.00718170684F, 0.010208644F, 0.0592344031F, -0.0127896275F,
        -0.0553657748F, -0.048170004F, -0.103138939F, 0.00436028233F,
        1.08258901E-5F, 0.0907024294F, 0.0661722273F, 0.0206139963F,
        -0.00881061517F, 0.0527316406F, -0.0390855409F, -0.00268580951F,
        -0.0181092098F, 0.0283293147F, 0.0587862059F, -0.050091166F,
        -0.112058111F, -0.0335206725F, -0.000340978382F, -0.0164122656F,
        0.101130135F, -0.0462348275F, 0.0699652657F, -0.0930849165F,
        -0.0191460941F, -0.0617290623F, -0.0299178604F, -0.021203408F,
        -0.0488974303F, 0.0257216431F, 0.0120094316F, -0.0867071F,
        -0.0729849935F, -0.0290235281F, -0.11001502F, 0.0327217169F,
        -0.0572475381F, -0.0155052338F, -0.0595429577F, -0.00066780427F,
        0.0124258678F, 0.0594788156F, -0.0322810747F, -0.0707735345F,
        0.0430354699F, -0.0878018364F, 0.0065334239F, -0.04005621F,
        -0.0336157307F, 0.0342796892F, -0.0349435061F, -0.0471261255F,
        0.0154020693F, -0.0223374292F, 0.00902091432F, -0.0881859F,
        0.00369593618F, 0.0522733778F, -0.0450438336F, 0.0361989699F,
        0.0416258201F, 0.0168511607F, -0.0356969945F, 0.05250315F, -0.106876515F,
        -0.0512089469F, -0.0645298138F, -0.0344375111F, -0.0059365863F,
        -0.0447384939F, -0.0456318632F, 0.0145231038F, 0.0247936361F,
        -0.0757781714F, -0.0306094959F, 0.00849024765F, 0.0470053442F,
        -0.0128839277F, 0.00842129905F, 0.0530598126F, -0.0577888303F,
        0.0266469624F, -0.000775812659F, 0.0182320774F, -0.0448584966F,
        -0.0905119255F, 0.0519101135F, -0.117123917F, -0.0339090191F,
        -0.0807029381F, -0.0801122859F, -0.0237588696F, -0.0753149092F,
        -0.0173341632F, -0.134413734F, -0.042498637F, 0.0468881465F,
        0.119407639F, -0.0929359421F, -0.0106932828F, 0.113210887F,
        0.0464556962F, -0.032301411F, -0.0586860254F, 0.0696715489F,
        0.000105344996F, 0.0299892854F, 0.131901547F, -0.0609632358F,
        -0.0296327546F, -0.137524158F, 0.080331251F, 0.103595249F, 0.145077944F,
        0.0748772696F, 0.101066306F, 0.053993687F, -0.0164533518F, 0.0412473567F,
        0.0274334885F, 0.080249548F, 0.0046209665F, 0.065065F, 0.0528921522F,
        0.0267040282F, -0.001674528F, -0.130339533F, 0.0731057152F,
        -0.0691957474F, -0.0718187168F, 0.162371203F, 0.104398824F,
        0.0241896827F, 0.0248158164F, 0.0391019247F, 0.0384412296F,
        -0.0408869125F, 0.124637708F, 0.0578508191F, -0.0133569185F,
        -0.117917597F, 0.0629095361F, -0.0297869295F, 0.082225062F,
        0.0867962465F, 0.126553237F, 0.047114905F, 0.0128488019F, 0.142562553F,
        0.083648257F, 0.0105439816F, 0.0943982527F, 0.0719821677F, 0.080084078F,
        0.0485243946F, 0.00440358464F, 0.0054911687F, 0.0961990058F,
        -0.106160171F, 0.0898078606F, -0.000222977658F, -0.0248004664F,
        0.123244219F, -0.0161795206F, 0.0442046672F, -0.0701978803F,
        0.0163135547F, -0.00699360436F, -0.0629626811F, 0.0150250299F,
        -0.00260080933F, 0.0521571375F, -0.0346397199F, 0.116010465F,
        0.0184320919F, 0.00379975F, -0.00418422744F, -0.032535892F,
        -0.0805055276F, -0.0301566795F, 0.101857409F, -0.128853127F,
        -0.0810820907F, -0.00328671793F, 0.0126520842F, 0.106292248F,
        -0.00821830332F, 0.0378383361F, 0.0587466247F, -0.0297548454F,
        0.072158657F, 0.0399646945F, -0.0424490795F, -0.0257842485F,
        0.0847405046F, -0.0531057604F, 0.119665593F, -0.0994582549F,
        0.0479633659F, -0.00346319959F, 0.062538F, -0.0188152343F,
        -0.0437916033F, -0.00637417892F, -0.0551509559F, 0.0517749339F,
        0.0202685054F, 0.0262016207F, -0.0975737125F, 0.0146144107F,
        -0.00240941439F, 0.010780571F, 0.0831816718F, -0.0601754487F,
        0.0501856543F, -0.110720351F, 0.0530909F, -0.00619775523F, -0.044681944F,
        0.00907852128F, -0.0589794256F, 0.047575321F, -0.00556102348F,
        0.00409175921F, -0.0558878F, 0.0596682057F, -0.0496691316F,
        -0.042790316F, 0.0093896063F, -0.00712506194F, 0.0172776449F,
        -0.0564326309F, 0.0016525907F, 0.028076116F, 0.0125641916F,
        -0.0620878786F, -0.0511493757F, 0.0123385349F, -0.0396460444F,
        0.00931042247F, -0.0918711722F, 0.0332190208F, 0.0587095506F,
        -0.0739724636F, 0.0492822F, -0.02472708F, -0.0793612078F, 0.0120890187F,
        0.0168541465F, 0.0159612559F, -0.0750601441F, -0.0292006116F,
        -0.0219304077F, -0.00381340855F, -0.00675856788F, 0.0225859098F,
        0.047395505F, -0.0231540948F, -0.103403971F, 0.0286030602F,
        -0.0539979413F, -0.0447886027F, 0.0402949415F, -0.0779018551F,
        -0.0696191415F, -0.0261311196F, -0.048067309F, 0.0188695155F,
        -0.0840818956F, -0.0436297879F, -0.0539807864F, -0.0442583561F,
        0.077009894F, -0.0323465765F, -0.0882971436F, -0.00895237271F,
        0.0398968719F, 0.0103638023F, 0.0551781F, -0.00824622158F, 0.0549107678F,
        0.065527454F, 0.00975551084F, 0.00879672356F, -0.0292313863F,
        0.0257541295F, -0.0511555262F, -0.00128302234F, 0.0366436541F,
        -0.0704527795F, -0.0334758908F, 0.015046305F, 0.0662586093F,
        -0.0532414205F, 0.0332465395F, -0.108867124F, 0.00643111253F,
        -0.0645364F, -0.0351292863F, 0.0450443923F, -0.0617596209F,
        -0.0048709088F, -0.0852741897F, -0.00093275F, -0.0390261635F,
        0.0157852247F, -0.0198988318F, 0.00295796478F, -0.00521236751F,
        0.0709416121F, 0.0583733469F, 0.0383084044F, 0.0883795321F,
        0.0425304696F, -0.000181996715F, -0.00505391276F, 0.0101225749F,
        -0.0807901248F, 0.0243290272F, 0.082888F, 0.015832793F, 0.0152434083F,
        -0.0689233467F, 0.037714567F, 0.0520368256F, -0.0433413237F,
        0.125931323F, -0.0164176542F, 0.0243707839F, -0.0820725188F,
        0.0710645169F, -0.00774667598F, -0.0481188558F, -0.0352482609F,
        0.0394806154F, 0.0597286485F, 0.042782791F, 0.0651406497F, 0.0798755065F,
        -0.0335550047F, 0.0973510444F, -0.022869803F, -0.0283459015F, 0.0047986F,
        0.0915628821F, -0.105311461F, 0.097902745F, -0.0189206041F,
        0.0113475686F, -0.014712844F, -0.0286546983F, -0.00396419549F,
        0.0814871117F, -0.00533974404F, 0.0157016851F, 0.1041122F, 0.141651914F,
        0.0301458295F, -0.00797388516F, -0.0490801483F, -0.0378069319F,
        -0.0264984351F, -0.00910947286F, 0.018852178F, -0.00654349336F,
        -0.130747706F, -0.0829985291F, -0.0871669874F, -0.153543174F,
        -0.00500014564F, -0.0123683391F, 0.0353639387F, -0.018543642F,
        -0.011666772F, -0.0189595819F, -0.115107216F, -0.0243564714F,
        -0.0939827934F, 0.0508253202F, -0.0393615663F, -0.0125380447F,
        -0.0213493798F, 0.0326650664F, -0.0683183819F, -0.108877607F,
        0.0107088182F, -0.0342950411F, -0.0561715737F, 0.0337212868F,
        0.0287662596F, -0.0399639718F, -0.00993312616F, -0.0616645F,
        -0.0422712788F, -0.0995261F, -0.075866729F, 0.0607347526F,
        -0.0471743457F, 0.0463642851F, -0.029944405F, -0.0720332116F,
        0.0847452208F, -0.0453467853F, -0.0936832428F, 0.0775710791F,
        0.0501497649F, 0.0309008528F, 0.000648913323F, -0.00192957115F,
        0.0141757522F, 0.0637391508F, 0.0837951675F, -0.0193521902F,
        0.0258502029F, -0.083206512F, 0.0612909347F, 0.0918580815F,
        0.0851532891F, 0.0756802559F, 0.117923662F, 0.124499939F, 0.0607848093F,
        -0.08056546F, 0.0803157464F, -0.0239747409F, 0.0690542385F,
        0.0515325628F, 0.0603403226F, 0.0293772258F, 0.00665818946F,
        -0.00658584805F, 0.00261692307F, -0.076832816F, 0.0180673748F,
        0.0466549806F, 0.00966807082F, -0.0408362299F, -0.000412346737F,
        0.00127524463F, 0.05908316F, -9.70495821E-5F, -0.0384217575F,
        -0.019506989F, 0.0386597104F, -0.0102316765F, -0.0112606082F,
        -0.0170681551F, -0.0612580851F, 0.0661505535F, 0.143431053F,
        -0.0231332127F, 0.0316871F, 0.00445708493F, -0.0461881049F, 0.0047159F,
        -0.00788459F, -0.00249801693F, -0.0274233148F, 0.0474859923F,
        0.0638831332F, -0.111984178F, 0.04502194F, -0.0226504337F, 0.0348721556F,
        -0.046063602F, -0.0163892191F, 0.13904196F, 0.139959797F, 0.144002557F,
        -0.00542593235F, -0.0157927312F, 0.0760418475F, -0.0403621271F,
        0.0123951891F, -0.0067756176F, 0.04481351F, 0.0517114438F,
        -0.0893272534F, -0.02115063F, -0.053132F, 0.083392933F, 0.138690695F,
        -0.0496526137F, 0.0293645822F, 0.0719048902F, 0.0549882203F,
        -0.0418989696F, 0.0123832831F, 0.0528072454F, 0.109018475F,
        0.0846351683F, 0.120925471F, -0.0759168342F, -0.0178654138F,
        -0.0714027435F, 0.0447803959F, -0.0454446673F, 0.104887322F,
        0.0088040838F, 0.00139141374F, 0.0279536806F, -0.00486306613F,
        0.0481146276F, 0.0857462063F, 0.112221025F, -0.0298674274F,
        -0.012308402F, -0.00204547844F, 0.00806584489F, -0.0288324188F,
        0.00111921644F, 0.0580415577F, -0.0951545388F, -0.0842201412F,
        0.100074515F, 0.0632752255F, -0.00345482025F, -0.118956529F,
        0.116168454F, -0.0555554777F, 0.0799367055F, 0.0115445601F,
        -0.0600856878F, 0.0821671784F, 0.0845787525F, -0.0470372923F,
        0.0798530877F, -0.0591632761F, 0.0368814953F, -0.00542500429F,
        0.0154593773F, 0.000178220915F, 0.109044798F, -0.00731775723F,
        0.0357811525F, -0.00317205419F, -0.108333319F, -0.054327935F,
        -0.0416803099F, 0.0250407252F, -0.0534194708F, 0.0458771549F,
        -0.0326966196F, -0.0221383721F, 0.062489029F, 0.0802222118F,
        0.0194886681F, -0.0880742818F, -0.0500022173F, -0.0260339864F,
        0.0170699786F, -0.0469878688F, -0.0191948712F, 0.00702624489F,
        0.0695952773F, 0.00869565178F, 0.0188052598F, -0.102087796F,
        0.0534762666F, -0.0761486515F, -0.0318221487F, 0.041968435F,
        -0.0265170466F, 0.0583814234F, -0.080613561F, 0.0300571565F,
        0.0476692915F, -0.126238465F, 0.0547409579F, -0.06061735F, -0.069649592F,
        -0.0676039F, 0.053556934F, -0.00770296808F, -0.0469234F, 0.00594530115F,
        -0.0553951822F, -0.0741023645F, -0.143772095F, -0.0751070827F,
        0.00605149334F, -0.0943023562F, -0.0809530839F, -0.0972569585F,
        0.0162770189F, -0.0586409345F, -0.0913778171F, 0.0566643961F,
        -0.0888321549F, 0.0693626776F, 0.0272442847F, 0.0406759791F,
        0.0568798333F, 0.00322269672F, -0.0176961571F, -0.0853237584F,
        -0.0359708443F, -0.061499875F, 0.00438622292F, 0.0158720855F,
        0.0761197433F, 0.000618864433F, 0.0686360747F, 0.0303502567F,
        -0.078495726F, 0.0769082457F, 0.0511403531F, -0.0131023154F,
        0.101997055F, 0.00389930699F, -0.0236912314F, -0.060261488F,
        0.0491268598F, 0.0112398872F, -0.031495817F, -0.0732439756F,
        -0.034367606F, -0.147627279F, -0.00738109415F, -0.0368319713F,
        0.019667862F, 0.0156212877F, -0.0797509775F, 0.0237046F, 0.0680021718F,
        0.0886382759F, -0.0647681057F, 0.0485565439F, 0.0135753509F,
        -0.00822472665F, 0.0255528018F, 0.0499782227F, -0.0434926897F,
        -0.0278718323F, 0.01620779F, -0.044635918F, -0.0107036205F,
        -0.0272757709F, -0.0444215573F, -0.01683628F, -0.0155328624F,
        -0.0501875877F, 0.0424813256F, -0.028234899F, 0.0546187572F,
        -0.0445688814F, 0.0945586562F, -0.0167258102F, 0.028219372F,
        0.0713338703F, 0.0429522954F, 0.0734812915F, 0.0751327872F,
        -0.113477603F, -0.0195397679F, 0.00370645896F, -0.0555409677F,
        -0.00732441805F, -0.0314105712F, 0.0349504873F, 0.0642806F,
        0.0317546353F, -0.0449692234F, 0.0520983785F, 0.101161666F,
        0.0960662737F, 0.0303075816F, -0.00392093463F, -0.00951110292F,
        0.046630498F, 0.0389875099F, 0.000636093144F, -0.066701591F,
        0.0643418804F, 0.0793746486F, 0.0185216218F, -0.0243872F, 0.00337560079F,
        0.0157442186F, 0.0191633496F, 0.0133315809F, 0.0115445377F,
        -0.0787846893F, 0.0115035782F, 0.04445922F, 0.0558777191F,
        -0.0609362125F, -0.0155555345F, -0.00116269966F, -0.0327713117F,
        0.0509020723F, 0.00195132452F, 0.0901985243F, -0.00430405745F,
        -0.0454875343F, -0.106021352F, -0.0616632514F, -0.0098612057F,
        -0.0307787228F, -0.0646931306F, 0.0115421489F, -0.0405175947F,
        0.00963809F, 0.0511647128F, 0.0685075596F, -0.0925716832F,
        -0.0195794813F, -0.0169650242F, -0.0854169726F, -0.0175073892F,
        -0.0609943978F, -0.0430413559F, -0.094340235F, -0.0367390402F,
        -0.0277332813F, -0.0213365611F, -0.0722682551F, 0.0128800096F,
        0.0214451738F, -0.0111200958F, 0.0635556132F, 0.000399601384F,
        0.0105003221F, -0.0336880125F, -0.0381651111F, -0.133520126F,
        -0.0395402461F, 0.0446565337F, -0.0842070729F, -0.0460938811F,
        -0.0975062102F, 0.0449772887F, -0.0025505193F, -0.0874545202F,
        0.0179549586F, -0.0601571053F, -0.101575084F, 0.11865513F, 0.004044984F,
        -0.0317091718F, 0.111978374F, -0.014498285F, -0.0743365064F,
        -0.0113078896F, -0.015010736F, 0.0151098147F, 0.0475110114F,
        -0.00435366901F, -0.0454786196F, 0.006824526F, -0.000310193747F,
        0.0824646205F, -0.0554595068F, 0.0244285092F, -0.0327645913F, 0.0176143F,
        0.0931922942F, 0.0528608672F, 0.0013131873F, 0.0753641427F,
        -0.0815282166F, 0.0459423028F, 0.0422387458F, 0.067615144F,
        -0.00621125801F, 0.0355126746F, -0.0277339239F, -0.0272025075F,
        0.0219172351F, 0.0135697294F, -0.113278545F, 0.0932331234F,
        0.0860197321F, 0.0212956592F, -0.147968739F, 0.0180887487F,
        0.0314766429F, 0.144485742F, 0.0299402848F, 0.00390947284F, -0.10668958F,
        -0.0615521036F, -0.11346522F, -0.0150261074F, 0.0407127179F,
        0.0929788575F, 0.0576649457F, 0.0872279853F, 0.100935116F, 0.0739833191F,
        0.0563381091F, -0.0262616612F, 0.118830368F, 0.0666056424F,
        -0.0303240288F, -0.0259711277F, 0.00471809739F, 0.030063238F,
        -0.0357161649F, 0.0773386955F, -0.115423873F, 0.00771961035F,
        0.107248835F, -0.0408898667F, -0.0325374529F, -0.071394287F,
        0.0582711473F, 0.0844766125F, 0.0373630747F, 0.0234792F, 0.0275653321F,
        0.0319430307F, -0.0818634927F, 0.0481712222F, -0.00857401546F,
        -0.0118168416F, 0.0651280358F, 0.0434356518F, -0.0411039405F,
        0.0355140902F, 0.0900161937F, -0.0233351942F, 0.0040666135F,
        0.0305633489F, -0.0881398693F, 0.0457335897F, -0.0719526112F,
        0.0502608679F, 0.084846817F, -0.00274832337F, 0.0325854756F,
        -0.0938191637F, 0.0171524025F, 0.0325878263F, 0.0795745477F,
        0.0278584603F, -0.0312249437F, -0.0202297531F, 0.0205152575F,
        -0.111294337F, 0.0668950081F, -0.00379474368F, 0.00387085F,
        0.0238173977F, -0.00454669492F, -0.0489969552F, -0.0295404568F,
        0.04996695F, 0.0241344199F, 0.0193062555F, 0.00636995677F,
        -0.0457767472F, 0.0679444447F, -0.0783461705F, -0.0220302586F,
        -0.0382317752F, 0.0654502362F, -0.0699252933F, -0.0451466963F,
        -0.00249513192F, -0.0633024052F, 0.109403096F, -0.046622593F,
        -0.01901838F, -0.0613811389F, 0.0849568173F, 0.0357664637F,
        -0.0420445427F, -0.0520225316F, -0.0349539146F, -0.0151573028F,
        -0.0159190856F, 0.0223074928F, -0.100423858F, 0.038958773F,
        -0.0666146427F, -0.017183641F, -0.049242083F, -0.0202711392F,
        0.0144651076F, 0.0689971596F, 0.0148945209F, 0.0833594948F,
        -0.0558358058F, -0.0747946948F, 0.00181995577F, 0.0246103648F,
        0.0430356748F, -0.0843890756F, -0.0114746345F, 0.0835945308F,
        0.0348394178F, -0.10709469F, 0.0999988839F, 0.0738661364F,
        -0.0275201239F, 0.0663030744F, -0.0536964759F, -0.0653872564F,
        -0.029792266F, -0.0170079637F, 0.0147187319F, 0.00430470519F,
        -0.031572517F, 0.0751055479F, -0.031351272F, -0.0182866324F,
        0.0808837414F, 0.0420714431F, 0.00457243063F, -0.0016694169F,
        -0.0522725955F, -0.0920324102F, -0.00352074066F, -0.00709818816F,
        -0.00337111042F, -0.0940769613F, -0.0746024922F, 0.0536247492F,
        0.0860053F, -0.0209054053F, 0.0561649613F, 0.0398000106F,
        -0.00632043462F, -0.00838231482F, -0.0338422209F, 0.0821020305F,
        -0.0201104097F, 0.0351464339F, 0.0832924247F, -0.0053176051F,
        -0.0481458828F, -0.0113521824F, -0.0814686939F, 0.0564859435F,
        0.036875166F, -0.105640709F, 0.0595250204F, -0.00807612389F,
        -0.023918502F, 0.0641331375F, -0.118530117F, 0.0348146595F,
        0.0524127074F, -0.0562175252F, 0.0926720649F, -0.0445798896F, -0.075735F,
        -0.0877035409F, -0.0166135486F, -0.0240236502F, 0.0331165269F,
        0.0269846302F, 0.0115262298F, -0.034591414F, 0.0429513678F,
        -0.0362501293F, 0.0560318641F, -0.0373964123F, 0.0342604592F,
        0.0128239011F, 0.0144241899F, -0.0997787118F, 0.0389409028F,
        0.0146963215F, 0.0562173128F, 0.0383896828F, 0.00613919599F,
        -0.10321492F, 0.0669960901F, 0.0255779661F, -0.101813875F, 0.0450313352F,
        0.0121923927F, -0.00310122035F, -0.0514484532F, -0.112681657F,
        0.0128783993F, -0.0899651125F, 0.0443950966F, -0.0347729847F,
        0.0013777999F, -0.0295251664F, -0.0613443665F, -0.029613601F,
        -0.114183567F, 0.0174013227F, -0.085476473F, -0.024406584F,
        -0.0559982583F, -0.0687062368F, -0.0920226648F, 0.0369779058F,
        -0.0719234645F, -0.0535806268F, -0.0999545678F, -0.0959816128F,
        -0.0904494226F, 0.014935948F, 0.0429813787F, 0.0584383495F,
        -0.105662331F, -0.0520078465F, 0.00574880745F, -0.0031944497F,
        -0.0245961975F, 0.0012544468F, 0.0627930388F, -0.0542780571F,
        0.0557927564F, 0.0293121785F, 0.0796815529F, -0.00658415351F,
        0.0744493157F, 0.0239022356F, -0.0414486527F, 0.048495777F,
        -0.0379440114F, 0.0663286522F, 0.0345635638F, 0.059246853F,
        -0.0344480202F, 0.0364847928F, -0.0832671225F, -0.0455983542F,
        -0.014494746F, 0.0210387409F, -0.0323859751F, 0.0366812944F,
        -0.0466210321F, 0.0172381587F, -0.113875896F, -0.0953986719F,
        -0.0680939481F, -0.0439911485F, -0.00427423837F, 0.00971673522F,
        -0.0985109583F, 0.0882294402F, -0.0149126248F, -0.070058994F,
        -0.0614433661F, 0.0452125892F, -0.0434249081F, -0.103862897F,
        -0.00696867285F, 0.0797700733F, -0.0491260551F, -0.0659722462F,
        -0.0599233098F, -0.0265934877F, -0.0777730942F, -0.136463448F,
        0.0343697853F, 0.0538723096F, 0.00885294192F, 0.055323F, 0.0035408719F,
        0.0834032744F, 0.0611148439F, 0.0259865411F, -0.037250232F,
        0.0755929351F, 0.0599853285F, 0.0741449744F, -0.0526396222F,
        -0.0210280288F, -0.00383329624F, -0.0705229789F, 0.0335486F,
        -0.0620511249F, 0.00980002806F, 0.0204108506F, -0.0916989371F,
        0.0683076754F, -0.100698024F, -0.0127056092F, -0.00667331321F,
        0.0902370885F, 0.0326385908F, 0.0540517829F, -0.101538852F,
        0.0556892417F, -0.0281953719F, 0.00251454604F, 0.0391156562F,
        -0.000723948178F, -0.0384921879F, -0.0490650386F, -0.109044045F,
        0.0817566589F, -0.00674866885F, -0.0382770598F, -0.0288212691F,
        -0.0641545057F, -0.0653400943F, 0.0145538533F, -0.0993141532F,
        0.00451225834F, -0.0144650256F, -0.0300944336F, 0.0164887588F,
        -0.147775635F, 0.0102558369F, 0.0284771174F, -0.0408800207F,
        -0.0770997703F, -0.0196432509F, 0.0656529F, 0.0519180112F,
        0.00362003967F, -0.00315604568F, -0.0378369056F, -0.080913119F,
        0.0835215598F, 0.0246497579F, -0.0589771643F, 0.0317274332F,
        0.067990616F, -0.080255352F, -0.0259486325F, -0.0368822776F,
        -0.0625674427F, 0.0902305096F, 0.0671105161F, 0.0552780144F,
        0.155431435F, -0.00977691542F, -0.0499786101F, 0.0693226755F,
        -0.00059196807F, -0.0631144047F, 0.0775476843F, -0.0102891047F,
        -0.0590087622F, -0.100431129F, 0.0353338197F, -0.0302957706F,
        0.0284800474F, -0.0295284949F, -0.0332447067F, 0.0860065594F,
        0.0444605611F, 0.0727556497F, 0.0582506917F, 0.0627443865F,
        0.0907614306F, 0.103017546F, -0.0742482F, 0.0605442524F, 0.0180914812F,
        -0.0555554517F, -0.0127568785F, 0.0337415747F, 0.00972331874F,
        0.0509507582F, 0.0904134363F, 0.0222637076F, 0.040481545F, 0.0252637F,
        0.115986213F, 0.0821302608F, 0.0578453578F, 0.0268029831F, 0.0654023F,
        -0.00822584052F, 0.00273997406F, -0.0767899156F, -0.050230138F,
        0.0371891335F, 0.0160626117F, -0.0357578956F, 0.0355442092F,
        -0.0407004468F, 0.0998078361F, 0.00673020724F, -0.0553653054F,
        0.0535081141F, -0.0859345719F, 0.0810342878F, 0.0657038316F,
        0.0314118154F, 0.0225175023F, -0.0804076195F, -0.0622500591F,
        0.0157850888F, 0.0663545728F, 0.0498536043F, -0.0586264022F,
        -0.0777613372F, -0.0445937403F, 0.0717135891F, -0.0281778798F,
        0.0683359F, 0.0517187F, -0.0358807892F, 0.0338634774F, -0.0350193046F,
        0.0427438542F, -0.064535439F, 0.0484503F, -0.0352882743F, 0.00327456486F,
        0.0532962605F, 0.0861677602F, 0.00190159958F, 0.0464390479F,
        -0.0450049601F, -0.114234067F, 0.061816521F, -0.0289758071F,
        -0.0873450935F, 0.0206969436F, -0.0591617189F, -0.0143767903F,
        0.0501899235F, -0.0229512509F, 0.0405499116F, -0.0603787564F,
        -0.0273473486F, -0.0977261737F, 0.018365832F, -0.0117864134F,
        -0.0670248568F, -0.0986921117F, -0.056407921F, -0.0031230629F,
        -0.0850641578F, -0.062276531F, 0.00954337791F, -0.0329269469F,
        -0.106696077F, -0.0497620888F, -0.0598717034F, -0.117334843F,
        0.0451995507F, -0.13542752F, -0.019204611F, -0.0940346345F,
        -0.124672189F, -0.0597957112F, -0.102218263F, 0.0056886957F,
        -0.000622210791F, -0.0670890063F, -0.0749598444F, -0.103926964F,
        0.00607111072F, 0.0370377712F, 0.107359327F, 0.0100238146F, 0.130237713F,
        -0.0669059455F, -0.0638549551F, -0.0949590355F, -0.0462090559F,
        -0.0765166506F, -0.0966715664F, -0.0475572273F, 0.00900576729F,
        -0.121260263F, -0.037078917F, 0.0301233437F, -0.0520749427F,
        0.134737492F, 0.0880462229F, -0.0245474223F, 0.0543178469F,
        -0.000125231134F, -0.0371921696F, -0.0189632196F, 0.116160624F,
        -0.0918344185F, -0.0646566749F, 0.00991646573F, -0.00371133F,
        0.014528228F, 0.00738418614F, -0.000237104134F, 0.0801872835F,
        0.0655635595F, 0.0597996861F, -0.016553279F, 0.102422751F,
        -0.0183624458F, 0.0260509271F, -0.0428885333F, -0.0334471203F,
        0.0542274453F, -0.0232044216F, 0.00174385123F, 0.0123969195F,
        0.0277758949F, 0.014430942F, -0.113368228F, 0.062734887F, 0.0181566663F,
        0.0174541138F, 0.0105524762F, 0.180312201F, 0.0377325378F,
        0.000290817203F, 0.0358912386F, 0.102588072F, 0.0731524155F,
        -0.013638963F, -0.0204452742F, 0.117197573F, -0.145218417F,
        0.0771246105F, -0.0778507441F, 0.105472282F, -0.0130563397F,
        0.0716635212F, 0.00140248856F, 0.0275705568F, 0.108464412F,
        0.0369121246F, 0.102742247F, 0.0774699226F, 0.0162449758F, 0.0741372406F,
        0.0956049934F, 0.00621505035F, -0.0767447F, 0.0954812318F,
        0.00280947657F, 0.114996262F, -0.00130752428F, -0.0769316554F,
        0.0724262819F, 0.0471306145F, 0.0742481351F, 0.067075409F, 0.104186133F,
        -0.0349004269F, -0.0165305622F, 0.115908332F, -0.0196945854F,
        -0.0464216955F, -0.0106967939F, 0.0824723691F, -0.0781626403F,
        0.0457830876F, -0.0544810779F, 0.038761504F, 0.141697511F, 0.0978608504F,
        0.0543376394F, -0.00756380521F, 0.106954336F, 0.0770037472F,
        0.0872748718F, -0.0141810905F, 0.0223715231F, 0.0376692414F,
        -0.147091597F, 0.0507647321F, -0.00277342275F, -0.0709228739F,
        -0.0527245F, -0.0729131326F, -0.0054702973F, -0.0257102419F,
        0.0552169234F, 0.0106734075F, -0.000940294471F, 0.0464668944F,
        0.0100506088F, -0.0177332945F, -0.0840750113F, 0.0118496176F,
        -0.0564151816F, 0.0215168279F, -0.00403460301F, -0.0941367298F,
        -0.00146802154F, -0.0575731061F, -0.0649088845F, 0.0826606303F,
        -0.0432562716F, -0.0745886117F, -0.0065445751F, -0.0545417F,
        0.00959313288F, -0.0422982275F, -0.0864503235F, -0.0522208251F,
        -0.0156834181F, 0.0263988692F, -0.112072259F, -0.0453017391F,
        0.0459536649F, -0.0664921254F, -0.0277696121F, -0.0593811795F,
        -0.00622977782F, -0.0325386375F, -0.0940963253F, 0.0308962893F,
        0.0901671723F, -0.00130734418F, -0.0959258601F, 0.0181363784F,
        -0.0369464643F, -0.0286048781F, -0.0567620434F, 0.0103460504F,
        0.0200825408F, -0.00254152017F, 0.0217502918F, 0.0746188536F,
        -0.0333485603F, -0.083114773F, -0.00557607552F, -0.00333940703F,
        0.0933895707F, -0.0104222428F, -0.0697670802F, 0.0107944887F,
        0.0498066656F, -0.0277629513F, -0.00651991833F, 0.0742776319F,
        0.0582908057F, 0.0737518892F, 0.0735766888F, -0.0023258666F,
        0.0138587905F, -0.0385456085F, 0.07650996F, 0.0945094526F, 0.0433299802F,
        0.0292068385F, -0.0145217637F, -0.0451545194F, -0.0861438F,
        0.0306285601F, -0.0745832846F, -0.0775769353F, -0.0807541683F,
        0.012030662F, -0.0536195636F, -0.0133253727F, 0.0508717597F,
        -0.0141415121F, 0.0277582668F, 0.0237724036F, 0.0522715189F,
        -0.0541603304F, -0.0140286665F, -0.00402735174F, -0.0396382846F,
        -0.00469018752F, 0.0479483381F, -0.0518807583F, -0.0214580968F,
        -0.0883794054F, -0.068068251F, -7.30012543E-5F, 0.0114441225F,
        0.0226128232F, -0.0458233058F, -0.0721862F, 0.0592547767F, 0.0218462795F,
        0.0502100699F, -0.0107997768F, 0.00131403119F, 0.0014709502F,
        -0.0494958088F, -0.0526175946F, -0.0571972877F, -0.0181711353F,
        0.0102650234F, 0.00234134332F, 0.0657088608F, 0.0756149516F,
        0.00215010531F, 0.00538071664F, -0.0460774861F, -0.0688297525F,
        -0.0357065536F, -0.0335065946F, -0.101880744F, -0.104561813F,
        0.0060946052F, 0.00546995085F, 0.0361489467F, 0.00693919789F,
        -0.022095006F, 0.054032173F, -0.031463109F, -0.101427644F,
        -0.0863000602F, 0.0396173857F, 0.00383991469F, 0.0150362914F,
        -0.000370466267F, 0.0386666544F, -0.0947885588F, 0.00529548712F,
        -0.0931452587F, -0.0392065719F, -0.0132240737F, 0.0290377811F,
        0.0118592326F, 0.0438575223F, -0.0335992202F, 0.00645608641F,
        -0.0262050536F, 0.0622723401F, -0.0577399135F, -0.0433991067F,
        -0.0643797815F, 0.0132516371F, -0.0210916363F, 0.056271296F,
        0.0138028841F, 0.0206379499F, -0.0326229632F, 0.039912682F,
        -0.0279139765F, 0.0334647819F, -0.0133836083F, 0.0638536736F,
        0.0421666093F, 0.0882688463F, -0.0619728491F, -0.0359523483F,
        0.0113991871F, -0.0529134162F, -0.0362600572F, -0.0802514926F,
        0.0239308737F, -0.0678147301F, -0.0703553334F, -0.0781695F,
        0.0297291558F, -0.0855250359F, 0.0241389051F, -0.0317851305F,
        0.0708070695F, -0.0421145931F, -0.0807745084F, -0.000155371439F,
        -0.0872699395F, -0.0500778109F, -0.00817427F, 0.0528566092F,
        -0.0288528409F, -0.0796440393F, -0.0450785272F, 0.0137762753F,
        0.100563034F, -0.0359136648F, -0.0350927263F, 0.0584828258F,
        -0.0369726457F, 0.0382436626F, -0.00634494284F, 0.0681754276F,
        0.0132179465F, 0.0466075353F, -0.0526667386F, -0.0304912869F,
        -0.0695159808F, -0.0575178899F, 0.0804214627F, 0.00654337741F,
        0.0833485425F, -0.018497603F, 0.0241137315F, 0.0562659688F, 0.115155451F,
        0.00429301662F, -0.0299371015F, -0.0469609573F, -0.103930727F,
        -0.0628930777F, -0.0853804424F, 0.0368640609F, -0.0494109F,
        -0.0441464111F, -0.0669646F, -0.0580558591F, -0.0785214156F,
        0.0249829497F, -0.0022585988F, 0.0531716235F, 0.0223428812F,
        0.0553146079F, 0.0479077026F, -0.0249356739F, -0.036466796F,
        -0.0400785245F, -0.00855223276F, -0.0629470572F, -0.0124814883F,
        -0.0148813734F, 0.031378828F, -0.0166947879F, 0.0175260771F,
        0.0577618107F, -0.0603183918F, -0.07115338F, -0.0696132183F,
        -0.0942364782F, -0.0606402978F, -0.0827367455F, -0.0870014057F,
        -0.0307888351F, 0.0283560324F, 0.00197749306F, 0.0131929405F,
        -0.0190713927F, 0.0447134227F, 0.0221943911F, 0.0176526699F,
        -0.0505628176F, -0.0522758476F, 0.106031813F, -0.0615043715F,
        -0.0366829485F, -0.0206287093F, -0.0277830195F, -0.014546873F,
        -0.0357886702F, 0.00970846415F, -0.00358780916F, -0.0337287299F,
        -0.0533315912F, -0.0182535741F, -0.00411845185F, 0.00564581761F,
        0.0298297256F, -0.0739762112F, -0.0654255748F, -0.00645612F,
        -0.0067499713F, 0.0575452857F, -0.0176428426F, 0.0370480716F,
        -0.0281653106F, -0.0585622974F, 0.0665188F, -0.0254742745F,
        0.00187620462F, -0.0532385781F, 0.0370254964F, -0.033509396F,
        0.015700087F, -0.00273718033F, -0.0760750473F, 0.0135454629F,
        -0.0737965852F, 0.00912854169F, 0.0297770239F, -0.0261309091F,
        -0.095729351F, -0.032973F, -0.0368374772F, -0.0528529733F, 0.0331014246F,
        0.0612692386F, -0.103054613F, -0.0793292895F, 0.0597055629F,
        -0.0216219127F, 0.0858013183F, -0.00817728508F, -0.0906605721F,
        0.0471054278F, -0.0232252404F, -0.0786934197F, -0.0683548152F,
        0.037646167F, -0.0623954162F, -0.0520568937F, 0.0172181614F,
        0.00497931335F, -0.0862180293F, -0.0917095244F, 0.0387798324F,
        -0.0211128071F, 0.00106969255F, -0.00324596395F, 0.085167326F,
        -0.0265193917F, -0.0271328222F, -0.058142785F, -0.0731359646F,
        0.0553092547F, -0.109437115F, -0.132547364F, 0.0560222641F,
        0.0445959903F, 0.0287220143F, -0.071630992F, -0.0523400828F,
        -0.0521653667F, 0.0134934345F, -0.10145437F, 0.0332912542F, 0.137521088F,
        -0.0313794576F, -0.0452738069F, 0.0525046624F, -0.0399499387F,
        -0.0410794802F, -0.0726581067F, -0.00879432354F, 0.0375998132F,
        0.133326605F, 0.0524280667F, 0.0480206F, 0.0665770769F, 0.00197044201F,
        0.0551589876F, 0.0178330857F, -0.0281067193F, 0.0146520156F,
        -0.0483094975F, -0.0149106923F, -0.0314025916F, -0.07059405F,
        -0.0899901688F, -0.0685474351F, 0.00773528F, -0.0440657325F,
        -0.0912298635F, -0.0567780957F, -0.0397038646F, -0.0538589507F,
        -0.114367433F, 0.000956588483F, -0.0345399566F, -0.0738969371F,
        -0.0977913F, -0.0285438783F, -0.0764517039F, -0.0181308426F,
        0.0431688279F, -0.0733540356F, 0.0459032468F, -0.0141834458F,
        0.0485849306F, -0.0495344028F, -0.0477529913F, 0.00526883127F,
        0.0264899451F, -0.0330363549F, 0.0701727867F, 0.126821414F,
        0.0129114408F, -0.0711009949F, -0.0929428637F, 0.0479591191F,
        -0.0561326444F, 0.00505288783F, -0.0519860722F, 0.00287085236F,
        -0.0195657853F, -0.0179289058F, 0.0633035079F, -0.00570558896F,
        -0.0664319769F, 0.0162382834F, -0.0905820727F, -0.115305461F,
        -0.0859304667F, -0.0807015151F, -0.0998159498F, -0.101886578F,
        -0.0763831288F, -0.0100608375F, 0.017383555F, -0.0964048579F,
        -0.0956133083F, -0.0149155222F, -0.0494489856F, -0.0897527784F,
        -0.0541544259F, 0.0317603834F, -0.0148768155F, -0.0215778556F,
        0.0160663184F, -0.0496412106F, -0.0873509049F, -0.0805867687F,
        -0.0656967759F, -0.0247058887F, -0.0501376316F, -0.0602817163F,
        -0.0900429264F, -0.0070547373F, 0.0529910289F, -0.0773449913F,
        -0.0494273081F, -0.0895259902F, -0.100808896F, -0.0573216081F,
        -0.044304125F, -0.0969563723F, 0.0436117128F, -0.0334228165F,
        3.53202922E-5F, -0.0179938562F, -0.0164764188F, -0.0281952638F,
        -0.0157696046F, 0.0370074548F, 0.0318101607F, -0.0748895407F,
        -0.0477228463F, -0.014529543F, 0.0375728384F, -0.0711893961F,
        -0.0348292515F, 0.0544416942F, -0.0346678421F, 0.000681352045F,
        -0.0944262743F, -0.0393573605F, 0.0354203545F, 0.00671392865F,
        0.0718128085F, -0.0137139028F, 0.0369840376F, -0.0726906061F,
        0.0205651559F, -0.0448447913F, 0.0376171507F, -0.033130642F,
        -0.014844344F, 0.0156402867F, -0.061256472F, -0.0178164F, -0.0183198676F,
        -0.00362756359F, 0.0230930448F, 0.000902642612F, -0.0101206899F,
        -0.0179109201F, -0.0809148476F, -0.0913479254F, -0.0376947075F,
        0.0106101772F, 0.0370609276F, 0.0457167961F, 0.0394360721F,
        0.0840463415F, 0.0466947965F, -0.0279211551F, 0.0452643856F,
        0.124746814F, -0.0175301749F, 0.034073431F, 0.111472547F, -0.0385630168F,
        -0.0481528677F, 0.0582622364F, 0.0023527646F, 0.122824892F,
        -0.0419769585F, -0.0768343F, 0.0147500644F, -0.0788947046F,
        0.0240637399F, -0.013885566F, -0.0331480056F, 0.00649031857F,
        -0.0139788138F, -0.0429025888F, -0.0796211734F, -0.00358149013F,
        0.0290396735F, -0.0990821421F, -0.0645759404F, -0.073447831F,
        0.0318237841F, -0.045119565F, -0.0715145841F, -0.00466415379F,
        0.055420354F, -0.000806653872F, -0.0365753882F, -0.00994848926F,
        -0.0362076387F, 0.0378265604F, -0.0281849876F, -0.0746528581F,
        -0.0478946082F, -0.08522138F, -0.11340972F, -0.0146444682F, 0.021396257F,
        0.0794371739F, -0.0776658356F, -0.06596075F, 0.013051155F, -0.104364544F,
        0.0264817066F, 0.00427098107F, -0.0348331332F, 0.0338044688F,
        0.094052583F, -0.015520921F, -0.0641524941F, -0.00414150814F,
        0.0201938655F, 0.0995147452F, -0.0580522232F, -0.0937195197F,
        -0.0444360338F, -0.0975816622F, -0.0534581654F, -0.0719124898F,
        -0.013900822F, -0.10782773F, -0.07968878F, -0.00367013598F,
        -0.0173381548F, -0.0415998138F, -0.0613441505F, -0.0154055133F,
        -0.0479713492F, 0.00863652118F, 0.0296370797F, -0.00770294433F,
        0.011896749F, -0.000983957434F, -0.0834477916F, -0.0925598145F,
        -0.0391371474F, -0.00447433721F, 0.0524722971F, -0.0103591895F,
        -0.0655515715F, -0.0638207197F, 0.0479452349F, -0.0253478661F,
        -0.0702162534F, 0.0501386523F, 0.00720466534F, -0.039027676F,
        0.0242803544F, 0.0082313139F, -0.0530269742F, 0.00535321422F,
        0.00789708458F, -0.0469975285F, -0.0761945248F, -0.0457931645F,
        0.0129981143F, -0.00118880591F, 0.0283952355F, -0.0619189478F,
        -0.100036755F, 0.00306690601F, 0.037852671F, 0.0581247844F,
        0.0254179165F, -0.0885015801F, 0.0189500023F, 0.0136974445F,
        0.00251045148F, -0.00466926303F, -0.0292215422F, -0.083277747F,
        -0.00907364674F, 0.0579528399F, -0.0808089077F, 0.032580182F,
        -0.0806011111F, 0.0579760484F, -0.0755069703F, 0.0309755504F,
        -0.0623752438F, -0.0511309616F, -0.00355025451F, -0.0363790169F,
        0.0311376378F, 0.0566423796F, -0.0705993176F, -0.0539755672F,
        -0.0725766569F, 0.0288834795F, -0.048066102F, 0.00967883F, 0.0420910418F,
        -0.0677632168F, -0.0728871524F, -0.0146637931F, -0.0746338218F,
        0.0344274901F, 0.0235479362F, 0.0029707402F, -0.0845826F, -0.0335747153F,
        -0.0519061387F, -0.00977467F, 0.00753708184F, 0.0244398974F,
        0.00931322761F, -0.0462209173F, 0.0394826084F, -0.073558487F,
        -0.0273108929F, -0.01477639F, -0.0297494046F, -0.0268116277F,
        -0.069940336F, 0.0642483F, -0.0591229722F, -0.0764568821F, 0.0219491068F,
        0.0422037393F, -0.0569533557F, -0.0913798064F, -0.0040735011F,
        0.0389278494F, 0.0506713465F, -0.0858795941F, 0.0488743261F,
        -0.0360348225F, -0.0630373657F, 0.0372258797F, 0.0181189366F,
        -0.0569757074F, 0.0316644683F, 0.0141539546F, -0.0759884268F,
        -0.0253084842F, -0.0600172617F, 0.0428409576F, 0.0365596F,
        -0.0504835807F, -0.0602742F, -0.0621701591F, 0.0284504034F,
        0.00635579461F, -0.000500573951F, 0.0513522439F, -0.0362196527F,
        -0.0343230627F, -0.0166459F, -0.0390277058F, 0.0616748296F,
        -0.0381008312F, -0.034812469F, 0.0527126305F, -0.0590906814F,
        -0.0549503528F, -0.0180303324F, 0.0394517146F, 0.023255486F,
        0.0307972785F, -0.0290857013F, 0.0311816689F, -0.0463259183F,
        -0.0833366215F, 0.0154068787F, 0.0570606366F, -0.0372118726F,
        0.0325744413F, -0.0855059773F, -0.0273858365F, -0.0620105416F,
        -0.0209958907F, -0.0189306438F, -0.0324964933F, -0.0058508818F,
        0.057537809F, -0.00604803907F, -0.065550454F, 0.0114368163F,
        0.0462085977F, -0.04977322F, 0.0238733087F, 0.0541086197F,
        -0.0331689119F, -0.0815767869F, -0.0172729269F, -0.00653390354F,
        0.0134622911F, -0.0705073923F, 0.0428112261F, 0.0463668108F,
        0.0272200983F, 0.0532829463F, 0.0518074483F, 0.0597667843F,
        0.0398564152F, -0.0782428831F, -0.0620424822F, -0.0399689525F,
        0.0624970384F, 0.0296880454F, 0.00275914697F, -0.01053927F,
        -0.023182435F, 0.00341911544F, -0.0562748313F, -0.0892463624F,
        -0.0266048722F, -0.0679851845F, 0.0374494642F, -0.00386099238F,
        0.0176310223F, -0.0511246882F, 0.0165538732F, 0.0714434534F,
        -0.0398577452F, -0.0460835285F, 0.0162574984F, -0.0811354518F,
        0.0589893162F, -0.0323422477F, -0.0543548204F, 0.0340713486F,
        0.0221151523F, 0.032343518F, 0.0349852331F, 0.0550888106F, 0.0741595626F,
        0.0184009634F, 0.0384022631F, 0.0318962894F, -0.042090293F,
        -0.0268732924F, -0.0387578495F, 0.0543616675F, -0.0895744711F,
        0.0106323836F, -0.0135247344F, 0.0376634598F, 0.0268496554F, 0.0610731F,
        0.0137895318F, 0.0630912557F, -0.0410332195F, -0.0537626743F,
        0.0566206351F, -0.0174727049F, -0.0373062342F, -0.0596907325F,
        0.0670775101F, 0.00322891516F, -0.0342446454F, -0.0984709263F,
        0.0186875146F, -0.0317151546F, -0.0283042677F, 0.00953813922F,
        -0.0656085908F, -0.0560849719F, -0.0107107786F, -0.0347541608F,
        -0.0465472862F, -0.0388329104F, 0.0445272289F, -0.0429621488F,
        0.00376574136F, 0.00447695609F, -0.0509528928F, -0.0460811406F,
        0.0361015722F, -0.0393173806F, -0.0147686554F, 0.0225178935F,
        -0.0568613373F, -0.062816292F, 0.0207409374F, -0.0575986654F,
        -0.0756167173F, -0.0548879392F, 0.0309849195F, -0.0457932055F,
        -0.0710937157F, 0.0703951046F, -0.00549364835F, 0.0401970074F,
        0.0109383548F, -0.0510843135F, 0.0607464239F, -0.0770859122F,
        0.0379834026F, 0.0363060981F, -0.0367659442F, -0.0347479954F,
        -0.00938371569F, -0.0357923433F, -0.0339412019F, -0.00451522507F,
        -0.0544184893F, 0.0479284637F, 0.0178809371F, -0.0236999933F,
        -0.00739110634F, 0.0200825352F, -0.058075F, -0.02169667F, -0.0617581345F,
        0.00592243671F, 0.020323541F, 0.0179302897F, -0.0405743346F,
        -0.0924145356F, -0.0201613F, 0.051229205F, 0.0142758954F, 0.0444171801F,
        -0.0674559623F, 0.0756293759F, 0.0481531918F, -0.00338488584F,
        -0.0155388368F, -0.0346109532F, 0.0133025628F, 0.0396080837F,
        -0.0786923468F, 0.0325608179F, 0.0436842702F, -0.0458012484F,
        0.0397406258F, 0.0589470454F, -0.0454957858F, -0.0107354792F,
        -0.0681875572F, -0.05184545F, -0.0510357358F, -0.0450589098F,
        -0.072535187F, -0.0207011867F, -0.00644097803F, -0.00186792971F,
        0.0584005639F, 0.0145986425F, -0.078681536F, -0.105378136F,
        0.0386872254F, 0.0490906201F, -0.060144119F, -0.0813364F, -0.0287141819F,
        -0.0427151173F, -0.0557852797F, -0.0688715354F, 0.132310033F,
        -0.0634260252F, 0.0590467602F, 0.0889611095F, -0.0956891179F,
        -0.0111341141F, -0.0196099896F, 0.0469264F, -0.0515784211F,
        0.00186464784F, -0.0353385061F, -0.104773559F, -0.0108531304F,
        0.00981391314F, 0.040262565F, -0.0670156851F, 0.113826826F,
        -0.0890621617F, 0.00754331285F, 0.00365423574F, -0.112597913F,
        -0.00333756581F, 0.00225535897F, 0.0257181544F, -0.0719152838F,
        -0.0564458035F, 0.0587026812F, -0.0274066292F, 0.0423589423F,
        -0.0861624479F, -0.0166306105F, -0.000578068662F, 0.0651018769F,
        0.0276299883F, 0.0550083816F, -0.00866696052F, -0.0163286757F,
        -0.0314559191F, -0.0363940671F, -0.0634762123F, -0.0220323578F,
        -0.0614914F, -0.0286811907F, -0.0263927374F, 0.0205857102F,
        0.0133119579F, 0.0615332164F, -0.0341616161F, -0.0764726698F,
        -0.0464755036F, -0.0248605106F, 0.0069361697F, -0.0197496619F,
        -0.0315522626F, 0.0292899758F, 0.0372128338F, 0.0197752211F,
        0.045248121F, 0.071097225F, -0.0804372653F, 0.015168082F, 0.0417301506F,
        0.0391057692F, -0.0594599769F, 0.0194122884F, 0.028299015F,
        -0.0124066062F, -0.00293224119F, 0.100854456F, 0.0132028125F,
        -0.0236882735F, 0.0336218551F, -0.0571908876F, 0.0224279072F,
        -0.0562402755F, 0.0228684973F, 0.0116751045F, -0.0539408214F,
        -0.0605252571F, -0.0217633601F, 0.00350609585F, 0.059270177F,
        0.0515919961F, -0.119448297F, -0.0274414718F, 0.049594786F,
        0.00600907486F, 0.0436156318F, -0.0077324966F, -0.0264998171F,
        0.00796958432F, 0.00763270818F, 0.0916753337F, 0.00486752577F,
        -0.050151974F, -0.0182953347F, 0.0868888199F, -0.0260108635F,
        -0.0486794077F, 0.0966233611F, -0.00211620098F, 0.0415057242F,
        0.0189282633F, 0.0577617809F, -0.0700217411F, -0.0683078095F,
        0.0565816425F, -0.0206919946F, -0.0438039191F, -0.0547431409F,
        -0.0155196348F, -0.0836509392F, -0.0160027612F, -0.0717103928F,
        0.0603791326F, -0.000231143669F, 0.0263611265F, -0.109989323F,
        -0.031592723F, -0.0858893618F, -0.0440298356F, -0.0748239085F,
        0.0229963064F, -0.0788472295F, -0.104388423F, -0.0371141471F,
        0.0461487547F, -0.0614501722F, -0.033410836F, -0.0396475345F,
        0.0472212918F, -0.0402586609F, -0.0346984193F, -0.070028834F,
        -0.00764211314F, -0.0123594F, 0.0227174554F, -0.054755535F,
        -0.00996671245F, -0.0105773723F, 0.00477362331F, -0.0798630193F,
        -0.00843260065F, 0.000429317879F, -0.104369894F, -0.0639190599F,
        -0.045987241F, 0.0163310505F, 0.052269049F, 0.0321497321F,
        -0.0624657832F, 0.0263063237F, -0.0718886927F, 0.0777229518F,
        -0.0397029035F, -0.0364432409F, 0.0354792699F, 0.00852866378F,
        -0.0360165946F, 0.0419925228F, -0.0526521094F, -0.0446744971F,
        -0.0103087407F, -0.0895465836F, 0.0917001441F, -0.0170638766F,
        -0.0447582044F, -0.0577188581F, 0.00556260394F, 0.0175047033F,
        -0.00916878134F, -0.0976109058F, 0.0462635793F, 0.101262487F,
        -0.0579821803F, 0.00932696089F, -0.00635388307F, -0.0332192965F,
        0.0159435924F, 0.0261769108F, 0.0776885599F, -0.0845807567F,
        -0.0615074858F, -0.0703746378F, -0.0145967035F, 0.0123892529F,
        0.0418833345F, -0.0257476233F, 0.028947806F, -0.0192091279F, -0.07445F,
        -0.0794491321F, -0.0215618294F, 0.00346635981F, 0.0859658F,
        0.0413499475F, -0.0317242853F, 0.011886429F, -0.0027565714F, 0.08136F,
        -0.0362372F, -0.0477861911F, 0.0162158031F, -0.0308970809F,
        0.00493128598F, 0.0679285452F, -0.00531502301F, -0.0279208757F,
        -0.0488869622F, 0.040704336F, 0.049018044F, -0.0186199918F, -0.0636174F,
        -0.0564728267F, 0.0425091498F, 0.0748207793F, -0.018998649F,
        -0.00343257352F, 0.0127033144F, -0.0373199806F, -0.00895154662F,
        0.0271415524F, -0.0761751458F, 0.0273226816F, -0.0188147426F,
        -0.0335342474F, 0.0729487613F, 0.0609046966F, -0.0385133326F,
        0.0548292957F, -0.0255953446F, 0.0298722684F, -0.0043970393F,
        -0.0206832103F, 0.0327339F, -0.0316921175F, -0.0255082715F,
        -0.043110393F, -0.0151177682F, 0.0120294448F, 0.0809249729F,
        -0.0384583585F, -0.0262922049F, -0.0579515956F, 0.0444004312F,
        -0.0151600279F, 0.00802679F, -0.045400653F, -0.000160177093F,
        0.0397961624F, 0.011038959F, 0.0425692238F, 0.0193421207F, 0.0745082647F,
        -0.0101025468F, 0.0211097691F, 0.0346952826F, -0.0504983775F,
        -0.0465100184F, 0.0261495858F, 0.0626670569F, -0.0493238792F,
        0.0466210172F, -0.0211631209F, -0.0174422935F, -0.0251865648F,
        -0.0799666F, -0.0363018364F, 0.00626984192F, 0.0607950576F,
        -0.00540757552F, -0.00856394786F, 0.0502499864F, 0.0677967519F,
        0.0747713819F, 0.00053360645F, -0.0637620389F, -0.000608344446F,
        -0.0641846806F, -0.038981244F, -0.0688009113F, 0.0894864127F,
        0.0338691659F, -0.00975105353F, 0.0671475083F, 0.00189105747F,
        -0.0587219968F, 0.0251586474F, 0.0116178924F, -0.00419650506F,
        -0.0932922736F, 0.036221385F, 0.0554560795F, -0.0061353948F,
        -0.0190300364F, -0.010647594F, -0.10107968F, -0.0449195839F,
        0.0203479249F, -0.0558151752F, 0.0290476866F, 0.00411540922F,
        0.0364871621F, 0.0391602814F, -0.0115715573F, 0.0158599485F,
        -0.06169172F, -0.10073939F, 0.0727560222F, -0.0439363681F, 0.0115679121F,
        -0.0135051878F, -0.0192207098F, -0.0282293353F, 0.0689926893F,
        0.0642619357F, -0.0809664056F, -0.0569596924F, 0.0341965444F,
        -0.0261321105F, 0.000666446402F, -0.0342932157F, -0.0529594831F,
        0.0233112518F, 0.0744018927F, -0.0120714307F, -0.030334603F,
        -0.0525487959F, 0.0500245839F, 0.0612089373F, -0.0588811822F,
        -0.0213171151F, 0.0249017645F, 0.0119337924F, -0.0248183608F,
        -0.0469962545F, 0.00907122623F, 0.00729673635F, -0.0532580912F,
        -0.0845157951F, 0.0486360863F, 0.0407314487F, -0.100459993F,
        -0.0818829462F, 0.0372571647F, -0.0125819268F, -0.0138603495F,
        0.00582195F, -0.0579947643F, 0.00831582397F, -0.100939304F,
        0.0192546081F, 0.0636709481F, -0.0215744078F, -0.052782163F,
        0.0409762859F, -0.0649104416F, 0.0417033508F, 0.0019470806F,
        0.0315207914F, -0.0237318166F, 0.0133773908F, -0.0599110276F,
        -0.02257731F, -0.0568723492F, -0.0762281343F, -0.00451327348F,
        -0.0208300669F, 0.0435242169F, 0.0138092153F, 0.0221444927F,
        0.0277419817F, 0.00551498029F, -0.0571724959F, -0.0770579651F,
        0.0751827657F, 0.0309154019F, -0.033029072F, -0.0346110724F,
        -0.0205697622F, -0.072249487F, -0.078935653F, 0.0277454983F,
        0.0263189599F, -0.0856410787F, -0.00520342495F, 0.0162785407F,
        -0.0217471793F, -0.0457683355F, 0.0205959622F, -0.00109447236F,
        0.0480555259F, -0.058844611F, 0.10654974F, 0.0339446291F, -0.0820484385F,
        -0.0602014F, -0.00552417897F, -0.0957148224F, -0.0314501561F,
        0.058605317F, -0.000414837617F, -0.0604128726F, -0.030799767F,
        -0.0410197228F, 0.0320620202F, 0.0228302944F, 0.0309774522F,
        0.0173525717F, 0.0271304809F, -0.0299505834F, -0.0696574897F,
        -0.00572609482F, -0.0915681496F, -0.0943784565F, 0.0245500989F,
        -0.0612482727F, 0.0367499F, 0.0233869702F, -0.0757149309F, 0.0150710056F,
        0.0401928462F, -0.0565197356F, -0.0508342832F, 0.0116692223F,
        -0.0939175487F, -0.0557442047F, -0.0831493735F, -0.0589842349F,
        -0.075767979F, -0.0122350557F, -0.0978973508F, -0.0412227139F,
        -0.067999F, 0.0601319894F, -0.084656F, 0.0183332805F, -0.114249781F,
        -0.114606395F, -0.0491340905F, 0.0731168166F, -0.0219950844F,
        0.0740699917F, 0.0662427321F, -0.0373688824F, 0.032054238F,
        0.0147545775F, -0.0578407049F, -0.0196902F, 0.0351347886F, -0.0981917F,
        0.0366415493F, -0.0275739711F, -0.105234094F, -0.0454740971F,
        0.0298362449F, 0.0780346692F, -0.00268937228F, -0.065814428F,
        -0.101113595F, 0.0121408617F, 0.00395402173F, -0.00368341524F,
        -0.0846787F, -0.0914584473F, 0.0146291098F, 0.00768220704F,
        -0.0720927343F, -0.00101902545F, 0.0666486323F, -0.0198480263F,
        -0.0130615626F, 0.0193068404F, -0.0262491107F, 0.0625104904F,
        0.0580244437F, 0.0396562368F, 0.0502824523F, -0.0244429875F,
        0.0338222645F, 0.0677709579F, -0.0220389757F, -0.0336978771F,
        0.0622335449F, -0.0678861067F, -0.0233719423F, 0.074689F, -0.0473573394F,
        0.0113189491F, 0.0355521F, 0.00728155F, -0.00494857039F, 0.0586377271F,
        0.00585580105F, -0.0234479569F, 0.0417336635F, 0.0632614046F, 0.0688424F,
        -0.0198322013F, 0.0467317477F, -0.00309223728F, 0.0504466109F,
        0.026565792F, 0.058041282F, -0.0700176507F, -0.0567820333F,
        0.00184944097F, -0.00552723091F, -0.0695284307F, 0.0558621548F,
        0.00496023381F, -0.00106397248F, 0.0236171298F, -0.00674544182F,
        -0.0711893F, -0.0395720452F, -0.0703783F, 0.0442370474F, 0.0652146935F,
        -0.0540503226F, -0.0170865189F, 0.0727039054F, 0.0728921518F,
        0.0325288959F, -0.056224972F, -0.0279299505F, -0.027439421F,
        0.0878958106F, 0.0923569649F, 0.0480302423F, 0.0506210923F,
        -0.0296822637F, 0.0554280058F, -0.0281735901F, -0.0046961722F,
        -0.00337266573F, -0.0792806521F, 0.00060880254F, -0.0137506239F,
        0.0835215226F, 0.0749478787F, 0.0347959846F, -0.0790153F, -0.075171642F,
        0.0193164013F, -0.0304116476F, 0.0246753525F, 0.0387338623F, 0.0199969F,
        -0.10082826F, -0.061597608F, 0.0312599F, -0.055382736F, -0.00401026057F,
        0.0077274763F, -0.0623520948F, -0.0314999372F, -0.00284567638F,
        -0.0244312771F, -0.0182268377F, -0.0219679791F, -0.0540571325F,
        0.0186232831F, -0.0873613283F, 0.03829908F, 0.0634387806F, -0.036010582F,
        0.078940995F, -0.0311268028F, -0.0673046783F, -0.0240765493F,
        0.052479703F, 0.0632435605F, -0.0855035782F, -0.0331963934F,
        0.0575849637F, -0.0197732989F, 0.0678018183F, -0.0432198606F,
        -0.0544185787F, 0.040419843F, -0.00864564069F, -0.045562461F,
        0.0452451147F, -0.0944830701F, -0.0309761F, -0.0327849686F, -0.10506843F,
        -0.0749736056F, 0.00694164168F, 0.0164946448F, -0.0248985719F,
        0.0451080501F, -0.0445239097F, 0.00944454409F, -0.0199401416F,
        0.0234395899F, -0.100718483F, 0.0442997217F, -0.0838965252F,
        -0.0819257125F, -0.0461614206F, -0.0447636F, 0.0491255932F,
        -0.0425087139F, -0.00343153044F, -0.0329457968F, 0.0318918414F,
        -0.0536575466F, -0.0503184535F, -0.074361749F, -0.0346823446F,
        0.0422975123F, -0.106540479F, 0.0466045253F, 0.116001822F, 0.0389326029F,
        -0.0479555652F, -0.0521523617F, 0.0889145881F, 0.0687413439F,
        0.014435241F, -0.0512994379F, -0.0526979715F, 0.0294188745F,
        0.0492138825F, 0.0293825045F, -0.0443503819F, 0.0272888634F,
        0.0657390729F, 0.091156505F, -0.0220661666F, 0.0307982955F,
        0.00829220377F, -0.0933181122F, 0.0140947392F, -0.0769779F,
        -0.0486537442F, 0.0450042F, 0.0171539858F, -0.0193499979F,
        -0.0340289138F, 0.0104512703F, -0.0210545436F, -0.0954335704F,
        0.0642367527F, -0.0594623648F, -0.0392460041F, -0.0414360613F,
        -0.0624448135F, 0.0161812585F, 0.00411513494F, 0.00894773565F,
        0.0191766974F, 0.0457257777F, 0.0745168105F, -0.043155279F,
        0.000335830555F, -0.0208008103F, 0.0650080293F, -0.124283962F,
        0.0298126284F, -0.0688879341F, -0.00900564808F, 0.0091554625F,
        -0.068375F, -0.0263758749F, 0.0800310448F, -0.0557064116F, 0.0750167593F,
        -0.0881659538F, 0.110564411F, -0.0223104618F, -0.0420744717F,
        -0.0700496435F, -0.0107565671F, -0.028843103F, -0.0711778402F,
        -0.0294192247F, 0.0714548528F, 0.0871393F, -0.0548463278F,
        -0.00446907291F, 0.0473913588F, -0.0798547491F, 0.0735190883F,
        -0.0532784648F, -0.0381299332F, -0.0782258213F, -0.064897649F,
        -0.0190814771F, 0.0713627189F, 0.016962694F, 0.0805411339F, 0.117640913F,
        0.00508288853F, -0.0011532841F, -0.0749569312F, -0.0849378929F,
        0.063817881F, 0.0563982725F, -0.0757851079F, 0.0157766249F,
        0.0411623046F, -0.0842756853F, 0.00588367553F, 0.0435382389F,
        -0.00132740173F, -0.056723956F, 0.0347399265F, 0.0859561786F,
        -0.0501905717F, -0.0385773703F, 0.0235765334F, -0.0701307207F,
        -0.0448971465F, -0.0203209966F, 0.0211402345F, -0.0104884896F,
        -0.0300876591F, 0.0824158415F, 0.094039306F, -0.0780638829F,
        0.0108597381F, 0.000621533487F, 0.0574017204F, 0.0936654508F,
        0.0171082933F, -0.04817985F, -0.0469570979F, -0.0869872943F,
        0.0662968904F, 0.0403881557F, 0.0402078442F, -0.0665453747F,
        -0.00912029855F, -0.085107021F, -0.0180938691F, -0.109800816F,
        -0.0495621935F, 0.00152835855F, -0.0723200142F, -0.0135734249F,
        -0.0833492354F, 0.0239783339F, 0.0530589633F, -0.0130907847F,
        0.00674794707F, -0.0743683428F, -0.0723421797F, 0.0226393864F,
        0.0269823577F, 0.0293199606F, 0.0251866616F, -0.0200066846F,
        -0.0663046092F, -0.0767375603F, -0.0393442437F, 0.02339142F,
        -0.0575487241F, 0.0815734491F, 0.0640699491F, 0.00915897544F, 0.0982172F,
        -0.0167463683F, -0.0584590174F, 0.0511919446F, 0.0210283957F,
        0.110678345F, -0.0324502774F, 0.0356164724F, -0.0547771417F,
        -0.123065464F, -0.0202711299F, 0.0219003521F, 0.0418446809F,
        0.087392956F, 0.0277937762F, -0.0187494718F, 0.0869162157F,
        -0.0942203626F, -0.0848587751F, -0.107461698F, 0.0702411F, 0.0814411789F,
        -0.0232251026F, 0.0292004589F, 0.0830525085F, -0.0641121492F,
        -0.015581158F, 0.0788815767F, -0.0833730772F, 0.0669222549F, -0.0503635F,
        0.0262714233F, -0.013252967F, 0.0314557292F, -0.061565984F,
        -0.0170349199F, 0.0358167663F, 0.0373323783F, 0.0180947408F,
        0.00940187275F, -0.00799346808F, 0.0629420877F, 0.0292935725F,
        0.078097485F, -0.0375894159F, -0.0238800347F, 0.0847373456F,
        -0.0340263657F, -0.0536960699F, -0.0586063378F, 0.0502675399F,
        0.0288445931F, 0.0927938148F, 0.00123874331F, -0.0463350788F,
        0.0256726686F, 0.0216821358F, 0.0416408628F, -0.0424453057F,
        -0.00755028287F, 0.00831909571F, 0.0153691107F, 0.0385850035F,
        0.0654224083F, 0.0350103788F, 0.021836495F, 0.0422935486F, 0.0419218577F,
        0.00872743502F, 0.0743367225F, 0.0406860299F, -0.0122967875F,
        0.02757065F, -0.0395124592F, 0.0348285139F, 0.0501595251F, 0.0199909471F,
        0.0729833469F, 0.042226769F, -0.018344149F, 0.101701818F, 0.0491731949F,
        0.0142606338F, -0.0128797302F, 0.0329612754F, -0.046706479F,
        0.0447169468F, 0.0266885925F, 0.0551274568F, 0.0320103504F,
        -0.0152776958F, 0.0779379383F, -0.00799535308F, 0.0100504328F,
        -0.0617220737F, 0.0359172076F, 0.0791092F, 0.0151834283F,
        -0.00580697367F, -0.0795971379F, 0.0323787406F, 0.00260132691F,
        -0.0261833537F, -0.054068625F, -0.0454685576F, 0.00822252221F,
        -0.150218368F, -0.0566222072F, -0.0345927253F, 0.0534386523F,
        -0.0278125051F, -0.0528772548F, 0.0717143938F, -0.0708527267F,
        0.0157116596F, -0.083577089F, 0.0969123542F, -0.00603981595F,
        0.0772657394F, -0.0637153089F, -0.049294427F, 0.0124009224F,
        0.0228140615F, -0.0437189676F, -0.052445434F, 0.103244931F,
        -0.0431424454F, 0.009479017F, 0.0611113496F, 0.061788965F, 0.0913346112F,
        0.0484894589F, 0.0476254225F, 0.0287195053F, -0.0428011566F,
        -0.0702963769F, 0.0478070639F, -0.0834255591F, 0.0374412127F, 0.0792242F,
        0.0289774F, -0.0662939921F, 0.0332859233F, -0.000798086519F,
        0.117847554F, 0.0473094769F, -0.0552730709F, -0.0566395484F,
        0.0998700187F, -0.00914282911F, 0.104756378F, -0.0714539513F,
        -0.00595633406F, 0.102773048F, -0.0612007752F, -0.0193136875F,
        0.0645587295F, 0.0420649052F, -0.064714089F, 0.0638827533F,
        0.00907782651F, 0.0104452083F, 0.0848672688F, 0.0310529862F,
        0.097489275F, 0.00752058299F, 0.0484087132F, -0.000337840465F,
        0.00092976552F, 0.028417943F, 0.0134833567F, -0.0586089976F,
        -0.0711001158F, -0.00772320712F, -0.0448773913F, 0.0150538972F,
        0.0617967509F, 0.0299736671F, -0.0556907691F, 0.00541639468F,
        0.0559915155F, 0.0378526635F, -0.0245950986F, -0.00283932476F,
        -0.0264145F, -0.0789648518F, 0.0456732288F, -0.000319855229F,
        -0.116716385F, -0.0138695762F, 0.0108700143F, 0.0336364843F,
        -0.0577669591F, 0.0212900173F, -0.0134098232F, -0.0649388805F,
        0.0283568986F, 0.0503236F, 0.0284284502F, 0.0142079918F, 0.0564697199F,
        -0.0661698133F, 0.00613856642F, 0.0463954508F, -0.063381739F,
        -0.0945416391F, 0.0146249169F, -0.0980481282F, 0.00741576822F,
        0.108715594F, 0.0171990935F, -0.0108212046F, -0.0211828873F,
        0.00487707648F, -0.094448708F, -0.0413708352F, 0.0564328954F,
        -0.0615497455F, 0.0483258553F, -0.102447622F, 0.00731848553F,
        -0.0266096536F, -0.0550052971F, -0.0607535467F, -0.113501139F,
        -0.0346547589F, -0.0978541225F, -0.122959115F, 0.0284051429F,
        -0.0887229294F, -0.0703118667F, 0.00435057376F, -0.122608192F,
        0.0117969392F, -0.111579992F, -0.0873815492F, 0.0575766228F,
        0.011720852F, -0.0780138671F, -0.0200560801F, -0.0355192088F,
        -0.0144090867F, 0.00979221053F, 0.00517239608F, -0.0831467137F,
        -0.0274387617F, -0.113800764F, -0.0132799484F, -0.154816061F,
        0.0221489314F, -0.166597143F, -0.10160467F, 0.106211312F, 0.0152385263F,
        -0.0616249815F, 0.0341530629F, 0.0163169038F, -0.0840889F,
        -0.00650928589F, 0.065761216F, -0.0342439897F, 0.00426676F,
        0.0877187774F, -0.018063236F, -0.131514639F, -0.121439531F,
        -0.134071767F, -0.00832918845F, 0.0524021499F, 0.0994155407F,
        0.0135067841F, 0.151435524F, 0.0978629291F, -0.0284899157F,
        0.0219936483F, 0.141338602F, 0.0752604231F, 0.0845198259F, 0.0596589446F,
        -0.0180366784F, -0.0494272597F, -0.0166063327F, -0.0248795711F,
        0.0919393077F, 0.0188111216F, 0.0793726F, 0.0868288428F, 0.0623611584F,
        0.00127015705F, 0.0691535398F, 0.0254751779F, 0.107883669F,
        -0.0164454095F, 0.122841574F, 0.102704816F, 0.0831635594F, -0.137974486F,
        0.015493148F, -0.107001759F, 0.0423794538F, 0.00812260248F, 0.147265255F,
        0.0324095264F, 0.101441987F, 0.101731978F, 0.0578949451F, 0.0101377973F,
        0.0154796029F, 0.0572882704F, 0.0997669175F, 0.000518317451F,
        -0.0162817053F, -0.0758775696F, 0.0446480736F, -0.0364175253F,
        0.0295585338F, -0.125699788F, 0.0314500779F, 0.144358531F,
        -0.0015138851F, 0.137421936F, -0.017066149F, 0.0381578505F,
        -0.0162383355F, -0.00891397521F, 0.0388734676F, 0.0565495305F,
        0.0482996218F, -0.0826666206F, 0.112977736F, -0.0406328775F,
        0.000103027865F, -0.0107203461F, 0.0324940532F, -0.0188947376F,
        -0.0892375931F, 0.0530118532F, -0.0112657072F, -0.0156180309F,
        0.0125775365F, 0.0228637736F, 0.129544079F, 0.0946465284F, 0.0105090411F,
        -0.0267736576F, -0.00387034053F, -0.0823402703F, 0.0828013867F,
        -0.132650018F, 0.0154802874F, 0.116327584F, 0.0897031277F, 0.0647995174F,
        -0.0452793539F, 0.0124254124F, 0.0385349914F, 0.0379909463F,
        -0.0775584206F, -0.0445020311F, 0.0512412898F, -0.0674560592F,
        0.0691222772F, -0.0550214164F, 0.0323111601F, -0.0326214172F,
        -0.0351628624F, 0.050133761F, 0.0170475077F, 0.050186649F,
        -0.0555992834F, -0.00409999583F, 0.0589474849F, 0.0139649669F,
        -0.0724666342F, -0.0155434618F, -0.0568310916F, 0.00821951125F,
        -0.00707406364F, -0.0207808837F, 0.04310821F, -0.0158719253F,
        0.0274593662F, -0.0492354259F, 0.0863256678F, 0.0437270738F,
        -0.0569659248F, -0.0657002553F, 0.0385086387F, -0.040317174F, -0.091498F,
        0.0184484813F, -0.0689210594F, 0.0131116165F, -0.0484705754F,
        -0.0407282F, -0.0639280528F, 0.0189344902F, -0.0525537953F,
        -0.0746001452F, -0.0855098516F, -0.107145309F, -0.00505325291F,
        -0.0303438753F, -0.0889456868F, 0.0686249658F, -0.0618435666F,
        -0.0823131874F, 0.087599352F, -0.0115098329F, 0.0906252712F,
        0.044275213F, 0.0605607629F, 0.0256882049F, -0.06600409F, -0.0296888128F,
        0.0280276928F, -0.0911244676F, 0.0109995436F, 0.0150350211F,
        0.0619068779F, 0.00856195483F, -0.101806544F, -0.00937979296F,
        0.0252532586F, 0.0139362691F, 0.0640825927F, 0.0345713422F,
        0.00812911429F, 0.0365481861F, -0.00400193082F, -0.0527267084F,
        -0.104521841F, 0.0199852735F, 0.0292594973F, -0.0671835542F,
        0.00555431051F, 0.000562213245F, 0.0300619025F, -0.0757668167F,
        0.0737146139F, 0.0587732978F, 0.0483648852F, 0.0274617951F,
        0.0340020284F, -0.00325322757F, -0.0141692189F, -0.0293960311F,
        0.020683188F, -0.015790347F, 0.0692636073F, 0.0439565293F, 0.0764750242F,
        0.0695279911F, -0.0458816141F, 0.0029204383F, 0.0343075357F,
        0.0901373774F, -0.0301637426F, 0.0514556542F, 0.054538887F,
        0.0363393649F, -0.00385567499F, -0.0678292289F, 0.00272969645F,
        -0.0710035563F, 0.0871866271F, 0.00564746559F, 0.0917455927F,
        0.0481294803F, -0.0535003915F, 0.00426884601F, -0.0493485704F,
        0.0838631317F, 0.0529533774F, 0.00814270135F, -0.0751484111F,
        0.0277750026F, 0.0267787892F, -0.0248539038F, -0.0509530082F,
        -0.103270546F, -0.0156382099F, 0.031882707F, -0.0328775123F,
        -0.0742471442F, 0.0591582F, 0.0327108316F, -0.0482166819F,
        -0.0352386311F, -0.00507594F, -0.0252155103F, -0.0448509045F,
        -0.00388908852F, 0.0105229449F, -0.107932746F, 0.0152701754F,
        0.0265869554F, -0.0037417186F, -0.0550288F, 0.0662061274F,
        0.00650567748F, -0.0601625F, 0.0288775656F, 0.0213126484F,
        0.00734563079F, -0.065723978F, 0.0264868159F, -0.0866373628F,
        -0.0221792944F, -0.0429278F, -0.0734311044F, -0.0580435917F,
        -0.0657566488F, 0.0155463545F, 0.0868328F, 0.0135031138F, 0.05256138F,
        -0.0996535718F, 0.0770693123F, -0.0511648655F, 0.0445444509F,
        0.0397146419F, -0.0452287309F, 0.0440619886F, 0.0461756252F,
        -0.0614475049F, 0.0434766635F, -0.115145937F, 0.0103661381F,
        0.0237741601F, 0.0644894764F, -0.0372862145F, -0.0818429813F,
        -0.047727827F, 0.0734907F, -0.0430385657F, -0.0228479449F,
        0.00594811467F, -0.0178903807F, 0.0307131391F, -0.0736173838F,
        -0.0926453695F, 0.0327528976F, -0.00270343153F, -0.027807422F,
        0.0477603488F, 0.0530128181F, 0.0626397431F, -0.0410768203F,
        -0.094953917F, 0.0437242091F, 0.0275089815F, -0.101274312F,
        0.0761415288F, 0.0648156106F, 0.00174316857F, 0.0772165433F,
        -0.0175012369F, 0.00463111885F, 0.0235206243F, -0.100559272F,
        -0.0679181218F, -0.0531793F, 0.0503189825F, -0.0229572244F,
        -0.0408177562F, -0.0529016219F, 0.0278287511F, 0.0602433532F,
        -0.0447263978F, 0.0461919829F, 0.0767917782F, 2.50623561E-5F,
        0.0589433499F, 0.055418279F, 0.00737291249F, 0.0268705301F, -0.00841276F,
        0.0305653F, 0.0239667F, -0.0785188F, 0.00875528529F, -0.033814203F,
        -0.0798711702F, 0.053747531F, -0.0687058866F, 0.0284449086F,
        0.0159691498F, -0.106685564F, -0.0924687F, 0.0464278236F,
        -0.00308263279F, 0.0484085083F, 0.0772166252F, 0.0471209846F,
        -0.00908773486F, -0.000567965151F, -0.0811931789F, -0.041606728F,
        -0.0434492119F, 0.000172796383F, -0.060849864F, 0.00182553509F,
        -0.0210027825F, 0.0633766F, -0.0255150106F, 0.00299882377F,
        -0.0621744134F, 0.0407940894F, 0.0066315583F, 0.0320373848F,
        -0.0492966101F, -0.0284689143F, -0.00681021297F, -0.0105204443F,
        -0.108444139F, 0.0235782582F, 0.11727161F, 0.0392498225F, -0.0581750497F,
        -0.00474931113F, -0.104356714F, -0.0859819353F, -0.0110169081F,
        -0.0254934207F, -0.0138944173F, 0.0358063F, 0.0708747581F,
        -0.0715219453F, -0.105173945F, -0.0898569822F, -0.0943260044F,
        -0.0160246585F, 0.0213848F, -0.0462648682F, 0.0124613969F,
        -0.0812131688F, 0.0260726176F, -0.0658092424F, -0.0554927476F,
        0.0460325629F, -0.0296779554F, -0.0590333492F, -0.0808994547F,
        0.0164662749F, -0.102994628F, -0.0265620407F, -0.0651404485F,
        -0.00876419526F, -0.0686428F, -0.0495204255F, 0.0111722583F,
        -0.0385991596F, -0.00208926201F, -0.0547213256F, 0.0641549453F,
        -0.0580041558F, -0.0308334362F, 0.0665817335F, -0.089301534F,
        -0.0240914896F, -0.0325311385F, -0.00690350309F, 0.0612411499F,
        0.0376523286F, 0.0785835683F, 0.0429197066F, -0.0537222177F,
        0.00334263314F, -0.0803662762F, -0.120118253F, -0.0110198176F,
        -0.0212561078F, -0.0446916483F, 0.0114312852F, 0.00812729821F,
        -0.0247188956F, -0.0199292973F, 0.0379793756F, -0.00461459067F,
        0.00956855528F, 0.0161009077F, -0.0200911574F, 0.0362466462F,
        0.0675403103F, 0.0507136621F, -0.0286393072F, 0.0186002403F,
        0.0950991511F, -0.0954700708F, -0.0719796419F, 0.0316912793F,
        -0.0894721F, 0.0505762435F, -0.0623585768F, -0.0536987409F,
        -0.0152171347F, -0.0521103777F, 0.0615308024F, 0.0399084799F,
        0.0199200418F, -0.0785112157F, 0.0255956631F, 0.013581072F,
        0.0743351281F, -0.0218477566F, 0.0256523062F, 0.0582901277F,
        0.00436853198F, -0.0786729F, -0.0433456562F, 0.0654147938F,
        0.0685538724F, 0.0124771679F, -0.00288620288F, -0.0150595084F,
        0.0209232364F, 0.0214517564F, -0.0739982203F, 0.0619904548F,
        -0.0403020605F, -0.0772444382F, 0.00944101159F, 0.0105801048F,
        0.0015533868F, 0.00285026059F, 0.0534566306F, -0.0345096439F,
        0.0713846833F, -0.0304317605F, -0.0121180573F, 0.0457602814F,
        0.0405978635F, -0.0665703565F, -0.0532916747F, 0.0156758111F,
        -0.0253207795F, 0.0254681855F, 0.0393564254F, 0.00418914342F,
        -0.000188743172F, 0.0228616446F, -0.0630572066F, 0.0308350753F,
        0.0576905124F, 0.0851017907F, -0.0645979419F, 0.0488493964F,
        0.0885846391F, 0.00852625445F, 0.0417174809F, -0.0542280935F,
        0.0724028349F, 0.0299113411F, 0.0740935802F, 0.015422537F,
        -0.0301317312F, 0.0203443542F, 0.0699099675F, 0.00890658423F,
        0.0101820659F, 0.0397784337F, -0.0424958579F, -0.0166822523F,
        -0.103231169F, -0.0229139868F, 0.0124162557F, -0.0728739351F,
        0.00162378489F, -0.00661416585F, 0.0146146202F, 0.0506549478F,
        0.0109274462F, 0.0302715804F, 0.0215047374F, -0.0859658569F,
        -0.00266520935F, -0.0782053545F, 0.0372292139F, -0.0778085664F,
        0.0186688658F, 0.0458044633F, -0.0543073416F, 0.0167907607F,
        0.057386253F, -0.0576097108F, 0.00897814333F, -0.066778F, 0.0461239927F,
        -0.0291545093F, 0.0244298819F, 0.0261865258F, -0.0189605579F,
        0.0107900314F, -0.0252031665F, -0.0408731699F, -0.0995051637F,
        -0.0456588F, -0.0875678807F, -0.0608536489F, -0.0223597791F,
        -0.0409436934F, -0.02481113F, 0.0617228076F, -0.0297449976F,
        -0.0137122301F, -0.0463148616F, 0.0308095496F, 0.0776888728F,
        -0.0440743305F, -0.0713542104F, -0.013188594F, -0.0430675559F,
        -0.0642259791F, 0.0588406697F, 0.0228046793F, -0.0585295334F,
        -0.0882127658F, -0.108858727F, -0.0505409837F, 0.0410892926F,
        0.0799380094F, 0.00833256077F, 0.0380116776F, 0.00194985175F,
        -0.0221365225F, -0.115469143F, -0.0349023864F, 0.0212011896F,
        -0.0418655351F, 0.0318631195F, 0.125969782F, 0.0184651539F,
        -0.0826302543F, 0.00472450024F, 0.0549625866F, -0.0338635035F,
        0.0842840448F, 0.0373470373F, 0.00363555783F, 0.0374748111F,
        -0.0450826287F, -0.0715882F, 0.0422988497F, -0.101465896F, 0.0197800603F,
        0.0342986956F, 0.0558118336F, 0.0630321428F, -0.0789166242F,
        -0.0878979191F, 0.0615613088F, -0.0176725462F, -0.0917288288F,
        0.00223527336F, 0.0608867742F, 0.00918768533F, 0.0362789445F,
        -0.0844683F, -0.0596598834F, 0.0347831286F, 0.0359828584F,
        -0.0663484335F, -0.00208507362F, 0.0896185F, 0.0361452F, 0.0640409291F,
        0.0312197451F, 0.0578428693F, 0.0861049518F, -0.0424129F, -0.0148635749F,
        -0.119975016F, 0.0380343981F, -0.127881303F, 0.00716805179F,
        0.026899565F, 0.094331421F, -0.0119876359F, -0.00997639913F,
        0.138187408F, 0.0633811653F, -0.0486644059F, -0.0319019295F,
        -0.0393019542F, 0.0664355F, -0.0676395446F, 0.0447321683F, -0.053906776F,
        -0.0800846517F, 0.0342385098F, 0.0792551339F, -0.0298963245F,
        0.0511112548F, 0.0355418622F, 0.030316392F, 0.0271724556F, 0.0322109647F,
        -0.091286853F, -0.0369378F, -0.00734432414F, 0.0442469604F,
        0.0871230066F, 0.0916217268F, -0.0823344067F, 0.0167476311F,
        -0.0631452277F, -0.00862337F, -0.00185507175F, -0.0614806488F,
        0.043181017F, -0.0180998649F, 0.076322712F, -0.0757273063F,
        -0.0283379201F, 0.0252772886F, 0.00146946823F, 0.101115912F,
        0.0445883796F, 0.0828239769F, -0.0649082065F, 0.0685117319F,
        0.0301413815F, 0.00368686812F, -0.0267192721F, 0.0125478059F,
        0.104443058F, 0.0739186853F, 0.0702913478F, 0.0309595522F, -0.027635077F,
        0.0694492087F, 0.0921459049F, 0.0909422338F, -0.0203112159F,
        -0.069010295F, -0.136435628F, -0.0507677495F, -0.0374383926F,
        -0.0359628871F, -0.051426582F, -0.00477849599F, 0.0381798F,
        0.0241757035F, 0.0116925519F, -0.0656641F, 0.0944584087F, -0.00778486F,
        -0.00983670074F, -0.0965673625F, -0.0822143257F, -0.028305022F,
        0.0398798548F, 0.00258503575F, 0.025451947F, 0.0528880246F,
        0.00990363769F, -0.0607486628F, -0.0320127755F, -0.0377360471F,
        0.0715958402F, 0.0890628844F, 0.017960161F, -0.0828116164F,
        -0.0342189409F, -0.0560335293F, 0.0448965F, 0.0331484228F,
        -0.0646948367F, 0.042928379F, -0.090744108F, -0.0274490882F,
        -0.00122861878F, -0.00760856271F, 0.00932057295F, -0.0648821667F,
        0.060155F, -0.0436486267F, 0.110357963F, -0.0764765814F, 0.0322334804F,
        -1.61936186E-5F, -0.061967466F, -0.0200105105F, -0.0323342681F,
        0.00733348867F, -0.0600634627F, 0.0623665489F, -0.0516534187F,
        0.0228049066F, 0.0182512738F, 0.0543041788F, 0.0364850089F,
        0.00285735773F, 0.0176198184F, 0.0338405482F, -0.0625780672F,
        -0.00916116312F, -0.0124903712F, 0.0397220701F, -0.00522135105F,
        0.0458239317F, 0.051534459F, 0.0486312583F, -0.0834877193F,
        -0.0463783517F, -0.0426890329F, 0.0369379446F, 0.0789772719F,
        -0.0780170634F, -0.0014498278F, 0.0358890928F, 0.0313625932F,
        0.0512548685F, 0.01256047F, -0.0431605615F, -0.0293601137F,
        -0.0199730247F, -0.0103369271F, 0.0705555752F, 0.0648806244F,
        0.00485497294F, 0.0813509598F, -0.0571181513F, 0.0616774261F,
        0.100802369F, -0.0337198228F, -0.0225981977F, 0.0583709888F,
        -0.0628206804F, 0.0224520341F, -0.0262940936F, -0.0634265766F,
        -0.00220714905F, -0.0534442738F, -0.0519226566F, -0.112654611F,
        -0.0078089321F, -0.103838347F, 0.00446870644F, 0.071823813F,
        -0.00277544581F, 0.0101242568F, -0.0981128886F, 0.00830255F,
        0.000711900764F, 0.0627262816F, -0.0843130425F, 0.0144490134F,
        -0.0872871652F, 0.00697965221F, 0.0516570099F, -0.0492609777F,
        -0.048568096F, -0.0260820985F, 0.0283513051F, 0.0557807349F,
        -0.0445108674F, 0.07928022F, 0.0329778045F, -0.0477249064F,
        -0.020295281F, -0.0326071717F, 0.0143782031F, 0.0377151668F,
        0.0497813113F, -0.0475945137F, -0.0112055223F, -0.0574307777F,
        -0.0110327397F, -0.0308338329F, 0.0326860547F, -0.0495303497F,
        -0.0196854342F, -0.0858154744F, -0.00369868684F, -0.0304196011F,
        -0.0547953881F, 0.0691125318F, 0.0143596698F, -0.0369739532F,
        0.02608734F, -0.0722497255F, 0.0472625382F, 0.0517333224F, 0.0204942524F,
        0.0662287399F, -0.0341442898F, -0.0580608621F, 0.0669979155F,
        -0.0588402599F, -0.00277907308F, 0.0216707885F, -0.00274444791F,
        0.0412164703F, -0.0445707962F, -0.0207321495F, -0.0891772807F,
        -0.00887852255F, -0.106184125F, 0.0258034617F, -0.0854593515F,
        0.0464931168F, -0.0208200812F, 0.055331029F, -0.0122962939F,
        -0.0153033836F, -0.0948852673F, 0.0496807769F, 0.0444006957F,
        0.0192540102F, 0.0097858F, -0.109912232F, -0.0995951667F, -0.0944766626F,
        0.0676927716F, 0.0806084871F, 0.117030673F, -0.0507793538F,
        0.0953471214F, 0.0501146168F, 0.0276922379F, 0.0252480358F,
        0.0239082724F, 0.0278448388F, -0.042155046F, -0.0195035394F,
        -0.0209124722F, -0.0818983689F, 0.000798002235F, -0.0400770381F,
        0.0685073882F, 0.0398814529F, 0.0295699891F, 0.0532708131F,
        0.0110777505F, 0.0598938949F, 0.0619969554F, -0.00616986165F,
        0.085463196F, 0.059251152F, 0.0133762592F, 0.0726503059F, -0.0478478037F,
        -0.0719945952F, 0.045609571F, -0.0294246022F, 0.0596416667F, 0.0719559F,
        -0.0626949295F, -0.00383000728F, -0.0767121166F, 0.0912329927F,
        -0.0872900039F, -0.0698463F, 0.0539686345F, -0.0088991411F,
        0.0044893045F, -0.0342113264F, 0.110722199F, 0.0337670892F,
        -0.0169993676F, -0.0332180448F, 0.0281678587F, 0.0504786409F,
        0.0830573812F, 0.0899700895F, 0.0830109045F, -0.00437751226F,
        -0.00142522284F, 0.0782005F, -0.0142750433F, 0.0765356869F,
        0.0428514369F, 0.0568872876F, 0.0210378822F, -0.0560307428F,
        0.0428285711F, -0.0134876138F, 0.0216625892F, 0.0595368184F,
        -0.0442939475F, -0.036447417F, 0.0175341833F, -0.00998878945F,
        0.00475277612F, 0.0226874221F, 0.0352762677F, 0.0615388379F,
        0.0330275223F, -0.0429143272F, 0.0106416F, -0.0986905F, 0.010902199F,
        0.00225863676F, 0.081124194F, 0.0109542357F, -0.0275799707F,
        0.0113264415F, -0.0193445254F, -0.0510047339F, 0.0191461705F,
        0.0202871356F, 0.00854291208F, 0.0648732781F, 0.0373895653F,
        -0.0748422071F, -0.0158105567F, -0.0892608166F, 0.0563763715F,
        -0.0542110801F, -0.0121854106F, 0.0476449542F, -0.0673653707F,
        -0.0359698273F, 0.0279671047F, 0.0223493986F, -0.0161004178F,
        -0.0245343056F, -0.0328873694F, -0.0179768149F, -0.0173395164F,
        -0.055658672F, -0.100161158F, -0.0343073569F, 0.0644625053F,
        0.0194579624F, -0.0651716739F, -0.0397330225F, -0.0519680083F,
        -0.0384754315F, -0.0491785556F, 0.0273347814F, 0.00891872F,
        -0.0478719547F, -0.0361587144F, -0.0317925103F, 0.0546044335F,
        -0.086121805F, 0.0412445739F, -0.0357048139F, -0.0207054429F,
        -0.0441592783F, 0.00487500336F, -0.0457897633F, -0.0224363375F,
        0.0447519645F, 0.0278463587F, 0.0457839668F, -0.00518423831F,
        0.0573051199F, -0.0378994867F, 0.00517307455F, 0.0308109298F,
        0.0653071105F, -0.071645692F, -0.0160294976F, 0.0440274812F,
        0.0311114881F, 0.0841075331F, -0.0283767749F, 0.0695528537F,
        -0.0906810537F, -0.0639886335F, 0.0613800809F, -0.0426566F,
        -0.0561038516F, -0.0161214937F, -0.0827874914F, 0.0628224835F,
        -0.009770751F, -0.00349336723F, 0.0498378314F, 0.0827793628F,
        -0.0387691893F, 0.0275795888F, 0.0203273892F, 0.0117557449F,
        0.0378479771F, -0.0768847F, 0.044104889F, 0.0259621255F, 0.0478720069F,
        -0.0631955564F, -0.082586F, -0.0148881711F, -0.007902137F, 0.0812247321F,
        -0.0219999794F, -0.00080243242F, -0.000751807F, 0.0822279751F,
        0.031827338F, 0.0346274041F, -0.00654095178F, -0.0548325926F,
        -0.0203157011F, 0.0692117363F, -0.10000775F, 0.0384185F, 0.0803183913F,
        -0.0724361613F, 0.0592743903F, -0.0490898788F, -0.0261715651F,
        -0.0329966433F, -0.0162186436F, 0.0841458365F, 0.0795348883F,
        -0.08557906F, 0.0564835593F, -0.123262167F, 0.0200871807F, 0.0630023703F,
        -0.0886738598F, 0.0180913098F, -0.00798202213F, -0.0653711259F,
        0.0243519843F, 0.0315930098F, 0.0108381743F, 0.0508138873F,
        -0.0565555692F, -0.0362784639F, -0.00956907775F, -0.0409651659F,
        -0.0307574F, -0.120128483F, 0.0561357029F, -0.0444351435F, -0.0958495F,
        0.0702793747F, 0.0620403737F, -0.0535077825F, 0.0605166666F,
        0.0808649361F, 0.000691619F, 0.0392675735F, 0.0518428199F, 0.0774120092F,
        0.00594781665F, -0.0689060315F, 0.0706795752F, -0.114967778F,
        -0.0362857059F, -0.0917236134F, -0.0342917182F, -0.0187928F,
        0.0228207037F, 0.0522542708F, -0.0370213464F, 0.0649956465F,
        0.0608061068F, -0.0736334771F, 0.0604464971F, 0.0308778156F,
        0.0499501489F, -0.0452017561F, 0.0537101105F, -0.00673132F,
        0.0327885784F, -0.0371513255F, 0.051863078F, -0.00567648653F,
        -0.0394255072F, -0.0560371168F, -0.00175276096F, -0.0191975012F,
        0.0642461777F, -0.0682564229F, 0.0589644201F, 0.00622296659F,
        0.101692364F, 0.049609784F, -0.042104885F, -0.0408622026F, 0.0710103363F,
        0.0448712222F, -0.00159989763F, 0.00323301693F, -0.0474104024F,
        0.0139039224F, -0.018544605F, -0.0281419065F, -0.058161363F,
        -0.0371525399F, -0.0595240481F, -0.0731193051F, 0.049405396F,
        -0.0273961816F, -0.0390141234F, -0.0547004193F, -0.0320573412F,
        0.0305533186F, -0.0417383648F, 0.0123779858F, -0.058312498F,
        -0.0620863251F, 0.00279125804F, -0.0160049647F, -0.0138088409F,
        -0.0266444609F, 0.0553505905F, 0.0822536424F, -0.0827932507F,
        -0.0455239415F, 0.0389637649F, 0.0672400817F, 0.0683788285F,
        -0.0628620312F, -0.0599255934F, 0.0219755378F, 0.0176271051F,
        -0.0258201845F, 0.0134057133F, 0.0337422267F, 0.0112954332F,
        -0.0435111895F, 0.0307313669F, 0.0926620662F, -0.0980579853F,
        -0.00138982711F, -0.00357303489F, -0.089877516F, 0.0221890397F,
        0.0590206794F, 0.0428327955F, -0.0572330318F, 0.113043167F,
        -0.0628031939F, 0.0386231542F, -0.0532004051F, 0.0456656851F,
        -0.0150549235F, 0.0516743064F, -0.0455792919F, 0.0452361591F,
        -0.033016257F, -0.0121631362F, 0.0513075106F, -0.0208635274F,
        0.0448726341F, 0.055302456F, 0.0276234597F, 0.0508719683F, 0.0686656609F,
        -0.0412188247F, -0.0624551736F, 0.00156670879F, -0.0405311882F,
        0.026936138F, 0.00251968345F, -0.00311592361F, 0.00440836744F,
        -0.0592916F, 0.00533706322F, 0.062151704F, -0.0600257441F,
        -0.0642551333F, 0.0245249961F, 0.038651146F, -0.00353299943F,
        -0.0590474159F, -0.0224128831F, -0.00117716496F, -0.0237280894F,
        -0.0257178321F, 0.0413817689F, -0.0723029301F, -0.0158712827F,
        0.00618341938F, -0.0547958426F, 0.0493543707F, -0.0999478251F,
        -0.0585543141F, 0.00142880075F, 0.0173447188F, -0.0333033912F,
        -0.0260833818F, -0.0106650544F, 0.0168482289F, -0.054530967F,
        -0.0354186632F, -0.0821773484F, -0.0094158845F, 0.0469384678F,
        0.0924167931F, -0.0997976F, 0.0214704331F, 0.00116315356F,
        -0.0405431874F, -0.0426475964F, -0.0814500749F, 0.0406953245F,
        -0.0590081587F, 0.0208884459F, 0.0480958037F, 0.00256894203F,
        0.0365590826F, -0.0701301098F, -0.0542129241F, -0.0650378764F,
        -0.0495532416F, -0.0751941949F, 0.0610501058F, -0.0276171826F,
        0.017169321F, 0.0533441715F, -0.0353420302F, 0.00866449252F,
        0.0128303971F, 0.0206909664F, 0.0476591F, -0.0244518928F, 0.0986459181F,
        -0.0516941547F, 0.032763347F, 0.0284070577F, -0.0275589284F,
        -0.0807441175F, -0.018350238F, -0.0115741072F, 0.040857181F,
        0.0355485305F, -0.00337942038F, 0.0890359282F, -0.0343399F,
        -0.0831472874F, 0.0818404406F, -0.0634999126F, -0.00667700078F,
        0.0223468635F, -0.00127607875F, -0.0066956277F, -0.0189585276F,
        -0.0786806941F, 0.020383982F, 0.0356416367F, 0.0243266765F,
        -0.0724781677F, 0.0862667784F, -0.0489509776F, -0.00135763304F,
        0.119766563F, 0.051724337F, 0.0585296974F, 0.0170498081F, 0.0152748134F,
        -0.0462355465F, 0.108841017F, -0.000980500598F, 0.0956373066F,
        0.0861793682F, -0.000168411148F, 0.0285051744F, 0.0816339627F,
        0.0385458656F, 0.0701641738F, 0.00315357046F, 0.101797804F, 0.149492249F,
        -0.059787184F, 0.0408344F, 0.0647110268F, -0.0484257154F, -0.0795639F,
        -0.0473770425F, -0.0550047383F, -0.0803289339F, 0.0657543391F,
        -0.0496864393F, 0.112449817F, -0.0445130616F, 0.0905668586F,
        -0.00763526466F, 0.0572825521F, 0.0471184328F, 0.0400620438F,
        0.0319812819F, -0.0221625455F, -0.0692385361F, 0.0331137776F,
        -0.0268459432F, 0.0374707207F, -0.0966941044F, -0.011357734F,
        -0.113901637F, -0.0410651118F, 0.00474864896F, 0.0542936884F,
        -0.044722762F, -0.0770186633F, 0.114360996F, 0.00690722186F,
        0.0282171983F, -0.10452228F, 0.019454509F, -0.0457500294F,
        0.00923900586F, 0.0302834883F, -0.0260640122F, 0.0931824595F,
        0.0117622437F, -0.0317685865F, -0.0723455399F, 0.0797740743F,
        -0.00147865736F, -0.0613949075F, 0.0714428723F, -0.0854966864F,
        0.0331156701F, -0.0771061778F, -0.089668408F, -0.0759764314F,
        -0.0970804915F, 0.0503947362F, 0.0502462387F, 0.022397751F,
        -0.00934144389F, -0.020313086F, -0.0522925F, -0.0370908864F,
        -0.101166263F, -0.0855458677F, 0.00540896691F, 0.0591400936F,
        -0.0987898633F, -0.0753029287F, -0.0394979976F, -0.0360531025F,
        -0.0611112F, 0.0275754798F, -0.0550010055F, -0.018016167F, 0.0213448666F,
        -0.0873358473F, -0.0900701508F, -0.0711645409F, -0.0355743915F,
        -0.0966854692F, 0.0496818461F, -0.0217820071F, -0.0557629056F,
        -0.0954628289F, -0.0531439595F, -0.0767469704F, -0.0622727349F,
        0.0283987708F, -0.0521876439F, 0.0686601698F, -0.0404488072F,
        -0.0884361938F, 0.0200176649F, -0.0738073587F, -0.00236197561F,
        -0.0558990352F, 0.0521222427F, 0.0217832718F, 0.00139176182F,
        -0.0375330485F, -0.0750201792F, 0.0188644975F, -0.0148693593F,
        -0.0717844814F, -0.0776355416F, 0.0161755197F, 0.0501011834F,
        -0.00838247F, 0.000988037325F, -0.00405610213F, -0.0901839435F,
        -0.0770827383F, 0.0416449346F, 0.010780938F, -0.0918435454F,
        0.00787598267F, -0.119956911F, 0.0574850366F, 0.0287895557F, -0.0512477F,
        -0.0962713212F, 0.0214757733F, -0.0454220176F, -0.0776739269F,
        0.00311045372F, 0.077415891F, 0.128738731F, 0.137398437F, -0.125590846F,
        0.0445039049F, -0.0694424659F, 0.0703129321F, 0.137244925F, 0.0321386F,
        0.0912955627F, 0.120533921F, 0.023995515F, 0.0903507F, 0.0492168739F,
        0.152700573F, 0.145967662F, 0.00360551546F, 0.118965387F, 0.0673064888F,
        -0.111082487F, 0.023648696F, -0.105648607F, 0.159511581F, -0.0314492807F,
        0.0273851454F, 0.128097415F, 0.0339548849F, -0.0465922F, 0.022205634F,
        0.0886965394F, 0.0338521898F, 0.0289129578F, -0.0967535153F,
        0.0696913898F, -0.0185912885F, -0.077660352F, 0.0916155F, -0.111011654F,
        0.0560306F, 0.0628154129F, 0.0249854606F, 0.0454156585F, 0.0313578285F,
        0.0374945775F, -0.0610306524F, 0.0685973763F, 0.0536262356F,
        -0.0266939811F, 0.0962367281F, -0.00990604609F, 0.0925225168F,
        -0.124934167F, 0.0549657233F, -0.099048309F, -0.0387298875F,
        0.0641454905F, 0.0183109734F, 0.0872034505F, -0.0326866582F,
        0.121516027F, -0.0231030472F, -0.0304094441F, 0.00135846017F,
        0.0141898831F, -0.00714933F, -0.0793342292F, 0.0262784641F,
        0.0176598653F, 0.123144805F, -0.0802298784F, -0.107359096F,
        0.0588244535F, -0.0282013118F, -0.064961426F, 0.00732116F,
        -0.0431358963F, 0.0421057828F, -0.0892519429F, -0.0943954512F,
        0.0317012295F, -0.0631191134F, -0.0689527318F, 0.0421639942F,
        -0.0744158179F, -0.0224712715F, -0.0746973157F, -0.00248506945F,
        0.078248091F, -0.0455613844F, 0.0297271907F, 0.05921207F, -0.0468489788F,
        0.0335225388F, -0.0484543256F, -0.107019335F, -0.0582684614F,
        -0.0690186322F, 0.0516638234F, -0.0606066771F, -0.0757750124F,
        -0.0326207764F, 0.0372698344F, -0.0437993966F, -0.0155480094F,
        0.0349127501F, -0.0604585968F, 0.0534109026F, -0.0100666322F,
        0.0416147225F, -0.0793072879F, 0.0337671563F, -0.0183808599F,
        -0.0357623957F, -0.0609046817F, -0.0435011759F, 0.0258192215F,
        -0.0589239337F, -0.0471996963F, -0.0428084321F, -0.072411187F,
        -0.0998195559F, -0.0855968446F, -0.0655831844F, -0.0414043888F,
        -0.000439984957F, 0.0203653555F, -0.0808429793F, -0.114982896F,
        -0.0547647364F, -0.00694499351F, -0.000879759144F, -0.106790282F,
        0.0434917249F, -0.0860275328F, -0.0381882079F, -0.0562506802F,
        0.0165596716F, 0.0340194665F, -0.000247448916F, -0.018982837F,
        0.0070861266F, -0.0760339126F, 0.00373930228F, -0.0275022108F,
        0.053066086F, -0.0516270176F, 0.017472F, 0.0300955884F, 0.0294102617F,
        -0.0410229862F, 0.0557174F, -0.00712389313F, -0.0823810548F,
        -0.0461112894F, -0.00932654925F, -0.0665881634F, -0.067059584F,
        -0.0773416609F, 0.0342819691F, -0.0870008692F, 0.0593184456F,
        0.0547934957F, -0.0279793181F, 0.0414156653F, 0.0682781786F,
        -0.0462170169F, 0.0363935977F, -0.0217281636F, 0.0313647129F,
        -0.0448789634F, 0.0182957631F, -0.0370729603F, -0.0642848089F,
        0.0247422624F, -0.0851873532F, 0.0397181623F, 0.066431053F,
        0.0117227631F, -0.0631651506F, 0.0727482F, -0.0618140735F,
        0.00436205138F, 0.0543419607F, 0.00433780719F, 0.0328425393F,
        -0.0488660894F, -0.0102397688F, 0.0363084823F, -0.0118316831F,
        -0.0820095688F, 0.0594274327F, 0.0676601082F, -0.000841810135F,
        0.0258505624F, 0.0275240336F, -0.0662872568F, -0.0394310206F,
        -0.0654933751F, -0.00425547641F, -0.00368604879F, -0.0632632375F,
        -0.0663516149F, 0.0559130497F, 0.0451636538F, 0.0335316882F,
        0.0236999467F, 0.0700755566F, -0.0810519084F, 0.0555553436F,
        0.0326271467F, 0.0419379957F, 0.0253764912F, 0.00675009098F, -0.0637252F,
        -0.0241453126F, -0.026878858F, 0.048195716F, -0.092403993F,
        -0.0842644423F, 0.0295956377F, 0.066639632F, -0.0526850484F,
        -0.017040994F, 0.0538858287F, 0.0298371818F, -0.0516245626F,
        0.0203415975F, 0.0452462249F, -0.022335181F, -0.0102299182F,
        -0.0655813515F, -0.0790519342F, 0.0488155037F, -0.00609370368F,
        -0.0675112531F, -0.0386047401F, 0.0286081526F, -0.000880866F,
        -0.0240891371F, -0.0150101585F, -0.0839913413F, 0.0552064441F,
        -0.0667573884F, 0.0258106533F, -0.0446236879F, 0.0377930552F,
        0.0465259328F, 0.00766513683F, 0.0512065291F, 0.0167495739F,
        0.0095107751F, -0.00597442314F, -0.0406212658F, -0.00239592674F,
        -0.00691411411F, -0.0361304693F, -0.023757698F, 0.0767420158F,
        0.0484843254F, -0.0239064768F, -0.023870904F, -0.0692912936F,
        -0.0260962937F, -0.025553897F, -0.0703646913F, 0.0322443396F,
        -0.0911296532F, 0.0295277685F, 0.0322443917F, -0.0650933832F,
        -0.0970862657F, -0.0141333928F, 0.0335349105F, -0.0609366521F,
        -0.0668969303F, 0.0647903383F, 0.0263056774F, 0.0281425789F,
        0.0670395643F, 0.0608265698F, 0.0121298982F, -0.0212251265F,
        -0.0563629717F, 0.075702779F, 0.00194153015F, 0.0154034542F,
        -0.0614420287F, 0.0117805684F, -0.00459029F, 0.00824799F, 0.0682112798F,
        -0.067675665F, 0.0285941716F, -0.0763689056F, -0.0880783F,
        0.00298478128F, -0.0470607728F, -0.0507926159F, 0.0319423564F,
        0.0673558787F, -0.0582382642F, 0.0349004306F, -0.102449119F,
        -0.0786901712F, 0.0155133745F, 0.0535825714F, 0.0299163423F,
        -0.0491499081F, 0.0478301086F, -0.0277730562F, -0.0280703343F,
        0.00825194735F, 0.0666630715F, -0.0241658948F, 0.0285991598F,
        -0.06849619F, -0.0091437716F, 0.054106351F, -0.0101933284F,
        0.0626859367F, -0.038448859F, -0.0150249684F, -0.046635367F,
        -0.0557703115F, 0.074926205F, -0.0185335949F, -0.0766072199F,
        -0.057467971F, 0.0103424629F, 0.00661331695F, 0.00240679854F,
        -0.0406588651F, -0.0858751088F, 0.047720667F, -0.0197502784F,
        -0.0313827097F, 0.0660279766F, -0.0332563072F, -0.0627052486F,
        0.0322478302F, 0.0589470118F, 0.0454702713F, -0.0361556597F,
        -0.00724583492F, -0.0372053944F, -0.0464874282F, 0.0563976616F,
        -0.0285313074F, 0.0358198248F, 0.0207154937F, 0.0202169809F,
        -0.0611177199F, -0.00967087131F, 0.044143565F, -0.081887F, 0.0608022511F,
        -0.064180553F, -0.00849148817F, 0.0669224858F, 0.0305616241F,
        -0.0897387564F, -0.0365541056F, -0.0785172805F, -0.0868148655F,
        -0.0613475628F, -0.0116120679F, 0.0618592F, -0.0420532152F,
        -0.0230083726F, -0.0667230114F, 0.0395972915F, 0.00314914505F,
        0.0801176727F, 0.0259582326F, 0.0289016422F, -0.0875094F, 0.0456827469F,
        0.0512717366F, -0.0798264369F, 0.00422728388F, 0.0607384294F,
        0.0527804382F, 0.00722758F, 0.0350410491F, -0.0601405203F,
        -0.0775293484F, -0.0373143256F, 0.0681603178F, -0.0344820544F,
        0.0648863F, 0.00266202632F, 0.0218427051F, 0.0447418317F, 0.0101600569F,
        -0.0494407F, -0.0674310401F, -0.0657931492F, -0.0145648858F,
        -0.0230636541F, 0.0492691435F, -0.00170461647F, -0.0378718078F,
        -0.0798081309F, -0.0234676395F, 0.0340244062F, -0.0125997243F,
        -0.0046956148F, -0.064574F, 0.0123184174F, -0.0217819847F, 0.0624927618F,
        0.0146757672F, -0.0127916131F, 0.0437029935F, -0.0193787031F,
        -0.0101168733F, -0.0759425685F, 0.0120821651F, -0.0322144143F,
        -0.0601741709F, 0.0571374632F, 0.0185532775F, 0.0444320589F,
        0.0422225483F, 0.00113347301F, -0.0642687F, -0.0632376149F,
        0.0238524415F, 0.0443460271F, 0.0589358509F, -0.00895826705F,
        -0.0795096606F, -0.0139815239F, -0.115546174F, -0.0674271584F,
        -0.000450011052F, -0.0690426305F, 0.00261823903F, -0.0194780584F,
        0.0125721013F, -0.106728896F, 0.04884772F, -0.0403473377F,
        -0.0175516065F, 0.00442232843F, -0.0607357919F, -0.0429612882F,
        0.0120535269F, 0.0224402938F, 0.023101313F, 0.114745297F, 0.102193519F,
        0.0919298157F, 0.0422470532F, -0.0116229765F, -0.0414738096F,
        -0.0261351354F, -0.0874620229F, 0.0278226621F, 0.0291948114F,
        -0.0191360414F, 0.0957891494F, 0.0940904319F, -0.0458752885F,
        0.028787205F, 0.0298569351F, -0.0435710289F, 0.139880374F, -0.0425797F,
        0.110064529F, -0.0418196358F, -0.0103410026F, -0.00295527326F,
        0.0347823389F, -0.0173681937F, -0.0130172335F, 0.0875807479F,
        -0.0013384053F, -0.00985780731F, 0.00637750048F, -0.0162118822F,
        0.0233289413F, 0.0284430347F, -0.0956122726F, 0.064759396F,
        -0.0802526399F, 0.0563677587F, 0.0397621132F, -0.0528761968F,
        0.0520932265F, -0.0763678551F, -0.0596189648F, -0.0444711F,
        -0.0165477637F, -0.102048069F, 0.084993504F, -0.033200331F,
        0.0641395599F, 0.0615490079F, -0.123101681F, 0.00356819108F,
        -0.0119985687F, -0.0144137023F, -0.0272275675F, 0.0227017365F,
        -0.0183820892F, -0.0566552542F, 0.0863009691F, -0.0349899754F,
        -0.0170239806F, 0.00774874818F, -0.0932522789F, -0.109344035F,
        0.0721624F, -0.0465031788F, -0.0402327254F, -0.000163969176F,
        -0.0340840742F, 0.0318500362F, -0.0336674713F, -0.0902397409F,
        0.125192627F, 0.0301451962F, 0.0101594385F, 0.0644100234F,
        -0.0650125816F, -0.0829933211F, -0.0564525612F, -0.0566746332F,
        -0.0958027765F, -0.0589956827F, -0.0561840534F, -0.00492587965F,
        -0.0884196237F, -0.029572783F, -0.00264749164F, -0.0690925866F,
        0.0152858328F, 0.00848058611F, -0.0270102713F, 0.00389643828F,
        -0.0391992778F, 0.0583097339F, 0.0230863132F, -0.059275534F,
        0.0635252073F, 0.00859433413F, -0.0221126638F, 0.0264049638F,
        -0.0129323155F, -0.0615288541F, -0.00247842306F, -0.051877182F,
        0.0200045519F, 0.00317414012F, -0.00439379225F, 0.0491272882F,
        -0.0294678286F, 0.101225026F, -0.016869003F, -0.0321831591F,
        0.0193873551F, -0.0311379805F, 0.100220576F, -0.0431678742F,
        0.0707449615F, 0.0290734824F, -0.0480757058F, -0.0564367659F,
        0.00893666F, -0.0554247759F, 0.0396352746F, -0.0565552302F,
        -0.0732128546F, 0.00315254088F, 0.0245878305F, -0.0869354084F,
        0.0334661715F, -0.0818942711F, -0.0866574198F, 0.00845661107F,
        -0.0931373835F, 0.0539562665F, -0.00315260096F, -0.10798049F,
        0.0458421074F, 0.0455528498F, -0.0986813381F, -0.0852055326F,
        -0.046639096F, 0.00500796968F, -0.0521271601F, -0.0920950398F,
        -0.0123301605F, -0.0870643482F, 0.0260977149F, -0.0377372205F,
        -0.0513993688F, -0.061987102F, -0.013365279F, -0.0171717312F,
        0.00185514824F, -0.0440257F, -0.0823522136F, 0.0449984297F,
        0.0548623614F, 0.13972792F, -0.0333911143F, -0.0193778723F,
        0.0448039174F, 0.00124249386F, -0.00337797217F, 0.00188658782F,
        0.0974044576F, 0.0593589172F, 0.0231879782F, -0.0437258594F,
        0.059774816F, -0.0888796225F, -0.0951847956F, -0.067729F, 0.106271327F,
        -0.0108531304F, 0.0231219865F, 0.0551489107F, -0.0742968917F,
        -0.048914589F, 0.026504593F, -0.0562611073F, 0.0574499294F,
        -0.0486239269F, -0.0254583657F, 0.00956384279F, -0.104247309F,
        0.0494083054F, -0.0402054191F, -0.00268592476F, -0.00621009385F,
        -0.102966942F, -0.0998923555F, 0.00484530255F, 0.0211226102F,
        -0.0706835315F, 0.0260794852F, -0.0762051269F, 0.0686143562F,
        -0.0350209512F, 0.0941393748F, 0.0277947F, -0.0034593367F, 0.0472778939F,
        -0.134736836F, 0.0987506F, -0.0829261243F, 0.0709326044F, -0.109070554F,
        0.0790172815F, 0.0454518348F, 0.0283571351F, 0.0161351971F, 0.121926986F,
        0.0851751417F, -0.035487473F, 0.070693925F, 0.00588156097F,
        -0.0333686583F, -0.101211049F, 0.041413106F, -0.0353609025F,
        -0.108228974F, -0.130170181F, -0.00689996965F, 0.0415181F,
        -0.0920323357F, -0.0719823912F, -0.0566978641F, -0.020455543F,
        -0.0803231224F, -0.0321710929F, 0.00321398745F, -0.0702707171F,
        0.0534747913F, -0.109449454F, 0.0215521287F, -0.0967304185F,
        -0.061679475F, 0.0339319222F, -0.0664118603F, 0.00359646184F,
        -0.0189067796F, 0.0134073272F, -0.032697998F, -0.095025979F,
        0.035654936F, 0.00394699909F, -0.0410338F, 0.0197091755F, 0.0611614399F,
        -0.0840326846F, -0.0204548445F, 0.0435435884F, 0.0339442715F,
        0.000127315376F, 0.00394911179F, 0.0153404269F, -0.0534248166F,
        -0.0175873283F, 0.0862703323F, -0.0151599655F, -0.0207779743F,
        -0.00997709762F, -0.00397112966F, -0.0564186275F, -0.0528823F,
        0.00295948889F, 0.102428198F, -0.0161114559F, 0.028315641F,
        0.0091593042F, 0.0605397448F, -0.0629458F, -0.0302295573F, 0.0572779886F,
        0.000416621449F, 0.0112370132F, -0.00374614075F, -0.00263719377F,
        -0.0471761487F, -0.0393554904F, -0.096258074F, 0.00234044972F,
        0.119621575F, -0.00949248F, -0.0336356238F, -0.028738033F,
        0.00378768472F, 0.0631225705F, 0.0427419171F, -0.0775933F, 0.0480933413F,
        -0.0517917685F, 0.0635915324F, -0.0224672388F, 0.0204976015F,
        0.0222295895F, -0.0988738239F, -0.0832682103F, -0.0156120509F,
        0.0515189394F, -0.0411222689F, -0.0593964234F, -0.0631485656F,
        0.053329695F, 0.0315657705F, 0.0314504877F, -0.0827151239F,
        -0.0640501752F, -0.0818719119F, 0.0443745293F, 0.0373712517F,
        0.0150873782F, 0.05813298F, 0.0780874F, -0.0588168129F, -0.0734380782F,
        -0.049385868F, -0.00451765908F, -0.0383657739F, 0.0858925581F,
        -0.0493087731F, 0.0252746809F, 0.04372973F, 0.0290458072F, 0.05513338F,
        0.0317467451F, -0.00778370164F, -0.00728544034F, -0.0671584681F,
        0.0522697344F, -0.0267983917F, -0.0042417408F, 0.0122735063F,
        -0.110754691F, -0.0949892178F, -0.0267109666F, -0.0364538655F,
        0.0262754578F, -0.0385332257F, -0.0294950027F, -0.0769876689F,
        0.00132239598F, 0.00104916666F, 0.0651084855F, -0.0756815523F,
        -0.000865681155F, -0.00133905327F, -0.0212921128F, 0.0581990294F,
        -0.0250991788F, 0.00760946888F, -0.0298507344F, 0.057931412F,
        -0.0710189F, -0.0595935658F, 0.0234331898F, -0.0677185729F,
        -0.0110428678F, -0.0241326652F, -0.0214916598F, -0.053306248F,
        0.0295708477F, 0.0491571277F, -0.0437466912F, -0.0713049F,
        -0.0301496293F, -0.0304562934F, 0.0619608313F, 0.108936854F,
        -0.0208055433F, 0.0533377044F, -0.0168221239F, 0.00444492698F,
        0.119035535F, 0.0790883377F, 0.0146566322F, 0.0570052825F, 0.0669617206F,
        0.0367086828F, 0.0802663267F, -0.0740659535F, 0.0475213714F,
        -0.0229402706F, -0.0829262F, 0.0715378076F, 0.0181163121F, -0.00410576F,
        0.00430188095F, 0.0521157086F, -0.0751316F, 0.0280452166F,
        -0.0171426367F, 0.0203792099F, -0.0257593356F, 0.0105640274F,
        0.0365975127F, -0.052978918F, 0.0441502556F, 0.0263900328F,
        -0.0354185142F, -0.0915824249F, -0.00505442498F, 0.0436364524F,
        0.015206635F, -0.00508286431F, 0.042675782F, -0.0749681816F,
        -0.0519199744F, -0.0474409461F, 0.0694451779F, 0.0228447169F,
        -0.0255708974F, -0.0690265521F, 0.00513629243F, 0.058722958F,
        0.0498222299F, -0.0688264146F, 0.0105867302F, -0.108257242F,
        -0.0979424939F, 0.00413775211F, -0.0808397F, -0.0291177314F,
        -0.040107429F, 0.0631119758F, 0.0516907685F, -0.0270908829F,
        -0.0535294451F, -0.00449288776F, 0.0628476962F, 0.0583730973F,
        -0.0350747555F, 0.0268850606F, -0.00877903402F, -0.0352874734F,
        -0.0146622043F, 0.0234386977F, 0.057900466F, -0.0369945F, 0.0393834412F,
        0.0730170682F, -0.105041139F, 0.0164652411F, 0.0579647571F,
        -0.0393303037F, 0.00182298897F, -0.00866813678F, -0.027929049F,
        -0.0900085F, 0.0474144F, -0.0748704225F, 0.0477982201F, 0.0394807272F,
        0.00846846495F, -0.0840359F, -0.0581257567F, -0.0451742299F,
        -0.0177503377F, -0.0369390845F, -0.0160348509F, -0.0952679068F,
        -0.0932204202F, -0.0054209996F, -0.081389606F, 0.0639247298F,
        0.0661014467F, -0.00737231178F, -0.00900984742F, -0.0719916448F,
        -0.0510992F, 0.062593624F, 0.0170663204F, -0.0509450957F, 0.0348062888F,
        -0.0513907187F, -0.0296458378F, 0.0115502747F, -0.0463880859F,
        0.0454696231F, -0.0675198F, -0.108532079F, -0.0590344854F,
        -0.0839652047F, 0.0281581115F, -0.00790391397F, -0.10659036F,
        -0.0258508F, -0.0505924858F, -0.0354047716F, -0.0773731843F,
        -0.0364955515F, 0.0494958162F, 0.037615221F, -0.0684887394F,
        0.0360090584F, -0.0707616955F, 0.026562769F, -0.0195638556F,
        0.0168776922F, 0.0379578508F, -0.0736899599F, -0.0173774138F,
        -0.0529942922F, 0.0503257066F, 0.0289247967F, 0.039998237F, 0.04763956F,
        -0.0339724161F, 0.0444587171F, 0.0455928035F, 0.103712603F,
        -0.00136626908F, -0.0160541721F, 0.0551077239F, 0.0962691754F,
        -0.0466441363F, 0.090399377F, 0.0743682534F, 0.0430707745F,
        0.0610471778F, 0.047594212F, 0.00336559163F, 0.0624048933F,
        0.0841048583F, -0.0823972821F, -0.0282632243F, -0.0722533837F,
        -0.00752288196F, -0.0635416F, 0.0488272235F, -0.0138514973F,
        -0.0732216835F, 0.00574085582F, -0.0141295316F, 0.0606904365F,
        -0.0376997106F, -0.0695599169F, -0.0272672065F, -0.000342658866F,
        -0.100038476F, -0.0537261069F, 0.0117577445F, -0.05437278F, -0.0936398F,
        -0.099652864F, -0.0660905242F, 0.0400209539F, -0.0145810852F,
        -0.0772306472F, -0.103235774F, -0.0761288181F, -0.0108218361F,
        -0.0201531239F, -0.00323122437F, -0.0911742449F, -0.0459007695F,
        -0.0953221396F, -0.094316341F, 0.00164179609F, -0.0654186085F,
        0.0666071475F, 0.0396347679F, 0.0840300322F, -0.0141338799F,
        0.0332574919F, -0.0828786343F, -0.0179854333F, 0.00644840114F,
        -0.107989296F, 0.00519404747F, 0.126529232F, -0.0465407595F,
        0.0826367587F, 0.0539430194F, -0.0411407091F, 0.0432780869F,
        -0.0425180756F, -0.0832322091F, 0.120229229F, -0.0140961409F,
        0.111505978F, 0.0273363553F, -0.103786074F, -0.137072846F, 0.0494639948F,
        -0.0152818756F, 0.0128341122F, -0.0381637327F, -0.0536313355F,
        -0.0463424139F, -0.101147182F, -0.0152608845F, -0.0258286446F,
        -0.0693766773F, -0.0118529676F, 0.0398540907F, 0.00433829613F,
        0.0237827431F, -0.0278053246F, -0.038417995F, -0.0650599673F,
        0.00228354032F, 0.0598158836F, -0.0220846813F, -0.00200651842F,
        -0.0449285023F, -0.0453415848F, 0.0686641484F, 0.0324259922F,
        -0.108833902F, 0.111678571F, -0.0217540152F, 0.0353048332F,
        -0.0946760699F, -0.0775287077F, -0.00466271909F, -0.0415236317F,
        -0.0164300837F, -0.0660346895F, -0.0695276782F, -0.136750787F,
        -0.0929022953F, 0.00261907582F, -0.0508885793F, 0.0251954496F,
        0.0471154302F, -0.0556519292F, -0.00737188477F, -0.0935691521F,
        0.0366413146F, 0.00358350808F, 0.000356092292F, -0.0356758721F,
        -0.0100521948F, -0.0789256096F, -0.0834909454F, -0.0115147131F,
        -0.0316322446F, 0.0126961637F, -0.00505761476F, 0.0740963F,
        0.0662205443F, -0.0486283824F, 0.0766206756F, -0.030220706F,
        -0.0978038087F, 0.0279726703F, -0.0212704707F, -0.067466341F,
        0.070810914F, 0.104150683F, -0.00663391547F, 0.119122617F,
        0.00629558647F, -0.0479407795F, 0.0618080348F, 0.022496257F,
        0.0446179248F, 0.0939832777F, -0.0118284449F, -0.0634664074F,
        -0.0670025274F, -0.00397406705F, 0.0373731218F, -0.00990754738F,
        0.028469326F, -0.0456924923F, -0.0644247457F, -0.0377658F, 0.0112426421F,
        0.00295660575F, -0.0878032893F, 0.0292542446F, 0.0126506267F,
        -0.113220498F, -0.039174173F, -0.057101354F, 0.0153763145F,
        0.0715446845F, 0.0758115798F, 0.0371628404F, 0.0995509F, 0.0452859253F,
        -0.0812911838F, 0.118512772F, -0.0725514F, -0.0713345259F,
        -0.0102440342F, 0.089454934F, 0.0575452708F, -0.000497742149F,
        -0.0605439134F, 0.0507283658F, 0.0684252232F, -0.134676874F,
        0.0416980609F, -0.0833459571F, 0.0472832844F, -0.0575568266F,
        0.0110897115F, 0.018858267F, -0.00438845344F, 0.00335270632F,
        0.0207666699F, 0.08288607F, 0.066502519F, -0.0373224132F, -0.0593342595F,
        -0.0662729889F, 0.0989945307F, -0.0617404915F, 0.000803134288F,
        0.114633098F, 0.175539687F, 0.132048607F, 0.0974151641F, -0.0413124114F,
        0.138464749F, 0.108796448F, 0.0353151597F, 0.0990155339F, -0.0209303442F,
        -0.0304715335F, 0.126894325F, 0.00913280435F, 0.100585029F,
        0.00477297278F, -0.0646564737F, 0.095888719F, -0.0472367331F,
        0.129966348F, -0.0455609486F, -0.0323277786F, 0.0243084319F,
        0.0245281123F, -0.105393067F, -0.0216288865F, 0.0118763344F,
        -0.114273123F, 0.0311780088F, -0.126427278F, -0.0548897646F,
        -0.0187348649F, 0.0946807861F, -0.0764122382F, -0.0293714646F,
        0.0391077064F, 0.0446267202F, -0.0787303373F, -0.042936828F,
        0.0257789027F, -0.00156614662F, 0.0758734122F, -0.0116982572F,
        -0.0615699664F, 0.089338623F, -0.037351355F, 0.0953885466F,
        -0.0264667477F, -0.0975906625F, 0.126670331F, -0.127713725F,
        0.101238407F, -0.043821F, 0.107776083F, -0.00178538938F, -0.0967939F,
        -0.0185957253F, -0.0569372587F, -0.0148506351F, -0.106493399F,
        0.0366585068F, 0.00994129945F, 0.0123479636F, 0.0068212687F,
        0.0510301664F, -0.139505506F, 0.0909104273F, -0.00876877643F,
        0.0394453257F, -0.114818193F, 0.0294054747F, 0.0317074358F,
        0.0355091691F, -0.0654696822F, 0.129086F, -0.0642081872F, -0.0183903519F,
        -0.00125070533F, 0.0649249107F, 0.0360560976F, -3.15647776E-5F,
        -0.0102260755F, 0.0664090365F, 0.0290139578F, 0.0313516334F,
        -0.00709647872F, 0.0414906219F, -0.040629115F, -0.0606947094F,
        -0.0191416033F, 0.0668200254F, -0.0522687919F, -0.0384840593F,
        -0.0905144885F, -0.041222088F, 0.0212814379F, 0.0929899514F,
        -0.0956341103F, 0.122387506F, 0.0642877072F, -0.0631257F, 0.0138976211F,
        -0.0310059618F, 0.0207748897F, 0.0113754887F, 0.0868025124F,
        0.123681225F, 0.0277956817F, -0.0912663341F, -0.0789080933F,
        0.106170788F, 0.0860716F, 0.0447946489F, 0.0354527F, 0.156564415F,
        -0.0213943031F, 0.000304544636F, -0.0481141619F, 0.0613255911F,
        0.0851669461F, -0.00293569267F, 0.0856357664F, -0.0250122473F,
        -0.0752898678F, 0.0430470333F, -0.0219450574F, 0.0907261446F,
        -0.126183361F, 0.00605643447F, 0.031130204F, -0.0512362868F,
        0.0301306061F, -0.107845545F, 0.115742207F, 0.116404638F, -0.0635658652F,
        -0.108370759F, 0.0312451683F, 0.0016114919F, 0.0456206724F, 0.133492529F,
        -0.027916953F, 0.0195719898F, 0.0964710191F, -0.0514815673F,
        0.0243121255F, 0.0276797507F, -0.0121604372F, 0.0101853786F,
        0.0493334606F, -0.060112644F, -0.0607090965F, -0.127411678F,
        -0.00693341764F, -0.0707988665F, -0.0691309199F, 0.0919568613F,
        -0.0420037918F, -0.0892204195F, 0.0829445943F, 0.0458532497F,
        0.0449529141F, 0.0370665416F, -0.0573141351F, 0.051401373F,
        0.0570525974F, 0.0551911592F, 0.0405189842F, -0.0264926627F,
        -0.0572782196F, 0.0230629481F, -0.084031716F, 0.134307027F,
        0.0689914599F, 0.0108631728F, 0.100340322F, -0.0905839354F,
        0.0269694887F, -0.0110099856F, -0.0341318101F, 0.00910230074F,
        -0.0420129485F, -0.0278587434F, 0.0769762173F, 0.091271989F,
        0.0522414148F, -0.0409115441F, 0.0370015465F, 0.0721495748F,
        -0.0662909374F, 0.0471241064F, 0.0137942694F, 0.0567930453F,
        0.0807519928F, -0.106457546F, 0.015999198F, 0.0836486071F,
        -0.0314990096F, 0.0846642703F, -0.0431395061F, 0.121834494F,
        0.0518020168F, 0.0406431183F, 0.054067973F, 0.00789106F, -0.0322166979F,
        0.0756864F, -0.0567052402F, -0.0101454426F, -0.0509874523F,
        -0.0649431348F, -0.0990458F, -0.00524178753F, -0.000176115573F,
        0.0486237854F, -0.117674075F, 0.128816038F, 0.0140114911F, 0.0299306847F,
        0.0574555732F, -0.00909972098F, -0.015265245F, 0.0423742495F,
        0.038503848F, -0.103126958F, -0.0248555299F, 0.00624987716F,
        0.0202617031F, -0.000437381736F, -0.00551711163F, 0.0774387717F,
        0.0521021634F, 0.0796752647F, -0.0135758221F, -0.0793209076F,
        -0.00384601951F, 0.0216011517F, 0.0557735488F, -0.0110073742F,
        -0.0380994603F, 0.0153583968F, -0.0583534576F, -0.056301333F,
        -0.0796125233F, 0.0633557F, -0.020484047F, -0.0365721509F, -0.116734929F,
        0.0371762589F, -0.0474613421F, -0.109369837F, 0.0339808427F,
        -0.0827690214F, -0.09618783F, -0.0651311353F, -0.104065694F,
        -0.0859354436F, 0.0521075279F, -0.0167132765F, -0.0646702275F,
        0.0374992713F, -0.0702442452F, -0.048998069F, -0.0737226903F,
        0.054220058F, 0.0312983096F, 0.0129526239F, -0.0119428197F,
        -0.0638841093F, 0.057400804F, 0.0120936912F, -0.0270528737F,
        0.0210012347F, 0.0371985659F, 0.0340715386F, -0.0596236736F,
        -0.0586807802F, -0.0388657674F, -0.0838660225F, -0.00278411107F,
        -0.0425046645F, -0.0315543748F, 0.052248884F, -0.0354784541F,
        0.0881846696F, 0.0898711532F, 0.0440484136F, -0.0598814152F,
        -0.0321759544F, 0.0429770947F, 0.110637829F, -0.0443497524F,
        0.0553986914F, 0.0576671772F, -0.0546312183F, -0.0775145218F,
        -0.0482940413F, 0.0734765306F, 0.0776756778F, -0.0309688393F,
        -0.0851701945F, 0.0787160546F, -0.0570107922F, 0.020008456F,
        0.0510796346F, -0.00908315647F, 0.0712626278F, -0.0643444F,
        -0.00774462707F, -0.108603835F, 0.0532192215F, -0.0328850746F,
        0.0528371483F, -0.0307614692F, 0.114863709F, -0.0565876029F,
        -0.0814726353F, 0.0750813335F, -0.058336325F, 0.0347914882F,
        0.0866479427F, -0.1022892F, 0.0466373153F, 0.0585167669F, -0.0326460451F,
        0.00305291335F, 0.0219959952F, -0.0260802284F, -0.0729809925F,
        0.097133331F, 0.00116821239F, 0.0706948638F, -0.0394265167F,
        0.0601339489F, 0.0536375567F, -0.0250928253F, -0.053922046F,
        -0.0330746584F, -0.0550848469F, -0.0240978207F, -0.0463104211F,
        0.0552870743F, -0.0402026735F, -0.0636481F, 0.0210585967F, 0.062521413F,
        -0.0866741687F, 0.0119640976F, 0.0695079F, -0.0823011845F, 0.106356367F,
        -0.0736748204F, -0.0333399847F, 0.0596083924F, -0.000336684287F,
        -0.0600302778F, 0.00190695352F, 0.0759018809F, -0.0754905939F,
        -0.0764507651F, 0.00281124422F, 0.0825494602F, 0.00787342526F,
        -0.0875664577F, 0.0384619869F, 0.00189828093F, -0.01067873F,
        -0.00128381257F, -0.0878417641F, -0.0163164753F, -0.00680333422F,
        -0.101917F, 0.0319113843F, 0.0623810813F, 0.0496786758F, -0.0280933697F,
        -0.0569621101F, 0.0655219257F, 0.00893565081F, -0.0571989678F,
        0.100851409F, -0.00379571691F, -0.0114470012F, 0.0498822F,
        0.000562905159F, -0.0630240366F, 0.0120029123F, -0.0900464132F,
        0.0602229089F, 0.0794341192F, -0.0921463147F, -0.132788017F,
        -0.0544548146F, -0.0825879127F, -0.0778648183F, 0.0091938423F,
        -0.00645416F, -0.0117686084F, -0.0112377275F, -0.0261253938F,
        -0.0280117765F, -0.0372375F, -0.0310682636F, 0.0365064F, -0.0892439857F,
        0.0608308315F, 0.0181575641F, 0.0145149725F, -0.041223418F,
        -0.0383134894F, -0.0154603682F, -0.0547271445F, -0.0633067861F,
        -0.0577523187F, -0.0656358674F, -0.0822108F, -0.0272523388F,
        0.0380483121F, -0.032205835F, -0.0239336528F, -0.0797548667F,
        -0.0593852364F, 0.0129836742F, 0.0292260814F, -0.00933399424F,
        -0.0751500055F, 0.0733644739F, 0.0215767659F, -0.00071425864F,
        0.0717814043F, -0.00905862078F, -0.0654030815F, -0.0721181333F,
        0.03208768F, 0.00886360463F, -0.0551622771F, -0.0147586707F,
        -0.0153530091F, 0.0120604197F, -0.0510043502F, 0.0292146F,
        -0.0201917458F, -0.0739123896F, -0.100311354F, 0.0677929819F,
        0.0293807704F, 0.0523412339F, 0.0369282924F, 0.0701157078F,
        -0.0274366643F, -0.0143769123F, 0.0590229556F, -0.0266091637F,
        0.0446437709F, 0.048721157F, -0.0446393825F, -0.0655408725F, -0.0782051F,
        -0.0369587205F, 0.0433956422F, -0.0383791402F, 0.0542268753F,
        0.0159768742F, -0.0201293025F, 0.0487622693F, -0.0667780712F,
        -0.000382588914F, -0.0566338822F, -0.0130352108F, -0.00319410861F,
        0.021435665F, -0.0064679971F, -0.122641176F, -0.0190503988F,
        0.0930534378F, 0.00740660727F, 0.0450511202F, -0.0637388602F,
        0.0541810244F, -0.0654738247F, 0.00398364756F, 0.105172351F,
        -0.0231339112F, 0.0492944047F, 0.0103364363F, 0.0257083699F,
        0.0649691895F, -7.69002363E-5F, -0.114105865F, 0.0659640059F,
        -0.0520778149F, 0.0528161637F, 0.0413869023F, -0.0324506052F,
        0.0200999789F, -0.00310350279F, -0.0752476603F, -0.0506682172F,
        -0.123548456F, 0.0491865911F, 0.0133422706F, -0.00409917207F,
        0.0663156211F, 0.0862491354F, -0.0427217148F, -0.106794566F,
        -0.030667942F, -0.0788422599F, -0.0368345417F, -0.0572881401F,
        0.0310473833F, -0.0244190618F, -0.0647818223F, 0.0328329206F,
        -0.10006883F, -0.0241107009F, 0.0330167115F, 0.0103982138F,
        0.0158841442F, 0.0895136595F, 0.00849368609F, -0.0455198511F,
        0.0833583549F, 0.0368907601F, -0.0432338528F, 0.0621956959F,
        -0.0406608395F, 0.0175248384F, 0.0828217417F, 0.0484571531F,
        0.0175747853F, 0.00301334774F, -0.0866569132F, 0.0573091172F,
        0.0541851372F, -0.0582241528F, 0.0417437628F, 0.0171555355F,
        0.0428428054F, 0.0442269929F, 0.0809756741F, 0.110373393F, 0.0827385634F,
        0.0175603982F, -0.0286054816F, -0.00824709795F, 0.00994183775F,
        -0.0887678638F, -0.0209476706F, 0.0443944857F, 0.0304168668F,
        0.0019269156F, -0.0262942109F, 0.0751098394F, -0.0180391502F,
        0.0409205407F, 0.0802352F, 0.0339241326F, -0.0362315513F, -0.0669174269F,
        -0.0366590023F, 0.011757479F, -0.0579948537F, 0.0126552656F,
        0.0248959791F, 0.0420640074F, -0.0498228334F, -0.00699983863F,
        0.0417134836F, 0.0777494386F, -0.0951585099F, -0.00331654679F,
        0.03017837F, 0.0912020057F, 0.0274784435F, 0.0453979187F, -0.0396021456F,
        -0.0361170657F, -0.0164105482F, 0.0344716311F, -0.0519404039F,
        0.0589796901F, -0.0334722027F, -0.106305189F, 0.035617806F,
        -0.0472929403F, -0.103623986F, -0.0144026186F, -0.0971292F,
        0.0726020336F, 0.00073952449F, -0.0328388326F, -0.060594894F,
        -0.0802756846F, 0.0431384929F, -0.0805503353F, -0.016228199F,
        0.0210477095F, 0.0582615435F, 0.0745944604F, 0.0315796174F,
        0.0682261586F, 0.0401227698F, -0.0353415385F, -0.0524783395F,
        0.00770310685F, 0.0543164238F, -0.00741306273F, -0.0915904567F,
        -0.0429209396F, -0.0508800149F, -0.0824958831F, -0.0700513348F,
        0.018875001F, -0.0145242885F, -0.0655182526F, 0.0839792565F,
        -0.035798002F, -0.0153201381F, 0.0661656111F, 0.0537355766F,
        0.0989835784F, -0.00987444911F, -0.0339789614F, -0.0709711611F,
        -0.00284341536F, -0.0724703F, 0.0845125169F, 0.0657497942F,
        -0.00743815256F, -0.0759733468F, 0.0286035892F, 0.0202930458F,
        -0.0386300385F, -0.0953784958F, 0.0246397611F, -0.0080615934F,
        -0.0352090299F, -0.045106668F, -0.110032968F, -0.052960258F,
        -0.00482935784F, -0.0501617528F, -0.00244762585F, 0.0430776216F,
        0.0369098745F, -0.0109777292F, -0.0326271541F, -0.0771695F,
        -0.0256749392F, 0.017336566F, 0.0144739896F, -0.00874302536F,
        0.0504766554F, -0.0234733559F, -0.0210306142F, -0.0217472855F,
        -0.0965611711F, -0.0173930191F, -0.0945294F, 0.0619976111F,
        -0.0488348305F, 0.0315468386F, -0.0103282202F, -0.0231629461F,
        0.00133512425F, -0.0131191928F, 0.0604163855F, -0.077132985F,
        -0.051375106F, 0.0695913658F, 0.0209856853F, 0.0738465935F,
        0.0696016699F, -0.0467863344F, 0.0717003196F, 0.0240526367F,
        0.0237488337F, -0.0372874849F, -0.0398403741F, -0.00227633771F,
        -0.0168519616F, -0.0980019F, -0.0100709591F, -0.0206384193F,
        -0.0375691094F, -0.0490168072F, -0.11523439F, 0.0701563656F,
        0.0536949486F, -0.0802441314F, 0.105090559F, -0.0451225303F,
        -0.0159067176F, 0.0296838619F, 0.0155862747F, -0.0595164932F,
        0.0659967363F, 0.0707719401F, -0.0619873516F, 0.00990377739F,
        0.0528119653F, -0.0650225282F, 0.0817148462F, 0.00208133552F,
        0.0477507822F, -0.0808840618F, 0.0337834954F, 0.0570733473F,
        0.0405559763F, -0.00399001269F, 0.0197926033F, 0.110154025F,
        -0.0329710059F, -0.0559232458F, -0.0408612303F, -0.107583605F,
        -0.0412859F, 0.0681369305F, 0.0399857648F, -0.00166173663F,
        -0.0569719225F, -0.0894550607F, -0.00671311235F, -0.0323033594F,
        0.0105703082F, -0.0467474945F, -0.0923697F, -0.0307877883F,
        -0.00761224655F, 0.0882040635F, -0.00302647729F, -0.00392623432F,
        0.0526408441F, 0.128290638F, 0.0578085966F, 0.127904609F, 0.0244977828F,
        -0.0719140843F, 0.0636218265F, 0.0113648968F, -0.105907567F,
        -0.0213570558F, -0.0199690126F, -0.000149475483F, 0.0823133588F,
        0.0303733218F, 0.0222633313F, -0.0794768557F, 0.0917589F, -0.0540364757F,
        -0.0222489275F, -0.098867178F, 0.010688873F, 0.0186638292F,
        0.0219662897F, 0.0785662308F, -0.0552596711F, 0.00142475322F,
        -0.056343928F, -0.0428852923F, 0.0284588616F, -0.0429276787F,
        -0.0147225838F, -0.0307417493F, 0.000103542057F, 0.043927148F,
        -0.0293526091F, -0.0164016709F, 0.0685441419F, -0.058084432F,
        0.00181105849F, 0.0683675408F, -0.0441852883F, -0.0493753664F,
        0.0653538555F, 0.0734245926F, 0.00581519911F, 0.0855370238F,
        0.0532845967F, -0.0105947377F, 0.0686245561F, -0.0677774549F,
        0.0213485751F, -0.0438200347F, 0.0430544466F, -0.0273013376F,
        0.0514090061F, 0.0472179502F, -0.018023314F, 0.0171965081F,
        -0.0541220456F, -0.104090832F, -0.0472418256F, -0.0558645204F,
        0.0508826F, -0.0220285263F, 0.0494206175F, 0.0422276407F, -0.0348739401F,
        0.0964417085F, 0.0986229926F, -0.115644664F, -0.00196160353F,
        0.0267945081F, -0.0600399785F, 0.0882379785F, -0.0544358157F,
        -0.0067484933F, 0.0535828918F, 0.0515267029F, 0.00421645073F,
        0.0588432029F, 0.00337208505F, 0.0827952847F, -0.0655511394F,
        0.0879524872F, -0.0295315757F, -0.063599214F, -0.0738260597F,
        0.02335383F, -0.0778456405F, 0.0537133F, -0.0223330446F, 0.0646993369F,
        -0.0699557811F, -0.0460477397F, -0.104925655F, 0.00872521661F,
        -0.0607716776F, 0.03451607F, 0.00253223209F, 0.00886072777F,
        0.0824525207F, -0.0314283706F, -0.0182814281F, -0.0697997212F,
        -0.0744914711F, 0.0401495509F, 0.0567621738F, 0.041417513F, 0.05326657F,
        -0.0171986595F, -0.0732449517F, -0.0337861776F, 0.0439906865F,
        0.00451003062F, 0.0369412564F, 0.120353617F, -0.0430127047F,
        -0.0581334643F, 0.0325928256F, -0.0280630626F, 0.0477249622F,
        0.0950732529F, -0.0234586503F, -0.0593545511F, 0.0520441495F,
        -0.013158232F, 0.0289827F, -0.07822451F, 0.0598641373F, -0.0326340757F,
        -0.0997187123F, -0.0447491407F, 0.11935927F, -0.0532703064F,
        0.043266844F, 0.0595253259F, 0.06453228F, 0.0397308208F, 0.104394495F,
        0.020602053F, 0.0764135793F, 0.0531310625F, 0.0463131443F, -0.114238195F,
        0.0686123595F, 0.0350415371F, -0.111098267F, -0.00688890601F,
        -0.0156394243F, 0.0220076647F, 0.124743015F, -0.0677595064F,
        -0.0889433473F, -0.034878429F, 0.0984036475F, 0.0866859108F,
        0.00516700558F, 0.0214818791F, 0.0407451577F, 0.00100246514F,
        -0.0336069763F, 0.0390353575F, -0.117695585F, -0.022237137F,
        -0.00864261389F, 0.0192529336F, -0.0323874578F, -0.037730895F,
        -0.0376525745F, -0.104709931F, 0.00547846F, -0.0444434024F,
        -0.0650277734F, 0.0320156403F, 0.00165984675F, 0.0180670042F, 0.0697339F,
        -0.0307379048F, -0.0207043402F, 0.044003956F, 0.0285512749F,
        -0.0716209635F, 0.0676021203F, -0.00317973737F, 0.0231663827F,
        -0.00933162495F, 0.0257335231F, 0.0554295219F, -0.0523246937F,
        0.0780069903F, 0.074601166F, -0.0188952871F, 0.00348698068F,
        -0.0489473268F, -0.0484029F, -0.0775035F, 0.0898107514F, -0.114878289F,
        0.00663089473F, -0.00970342103F, -0.00884769F, 0.00215565343F,
        -0.0325167254F, 0.0632718131F, -0.0410460681F, 0.0416314341F,
        0.0282994807F, 0.00381462369F, -0.0189977195F, -0.0727768689F,
        0.0337890387F, 0.0916822329F, -0.0141286962F, 0.00166829186F,
        0.0564338528F, -0.0390472449F, -0.0916706F, -0.0372185744F,
        0.0492472351F, 0.0776016563F, -0.0496199F, 0.070439145F, 0.00752306683F,
        -0.0282508451F, 0.0652943179F, -0.0172063F, -0.101570763F, 0.0615773723F,
        -0.0339781195F, -0.0644557327F, 0.0367789119F, -0.0419585F,
        0.00901060831F, -0.0904835835F, 0.0209273119F, 0.111032769F,
        -0.0650644079F, -0.000881462474F, -0.00612764619F, -0.073060818F,
        0.0650076345F, -0.0226097256F, -0.133933499F, 0.0513408706F,
        -0.0104049575F, -0.0632625669F, 0.0147216581F, -0.0906677544F,
        -0.0413734131F, -0.045362018F, 0.0976428464F, 0.0293270964F,
        0.0482041836F, -0.0146145197F, 0.0720856786F, -0.0969152F, 0.0759557F,
        -0.053306371F, -0.0230665468F, -0.0625454262F, 0.00834266189F,
        0.0224856921F, 0.0582612902F, 0.0443900451F, -0.0570354946F,
        0.0405423567F, 0.0350071527F, -0.108778603F, 0.0152553208F, 0.0601785F,
        0.00553212315F, -0.0158846509F, 0.0291471183F, -0.0947777107F,
        -0.0257180072F, 0.0961440876F, 0.0113477986F, 0.0884297192F,
        0.151693493F, 0.0149083417F, 0.120165251F, -0.0564471483F, 0.0249777287F,
        0.0747329593F, 0.0768107846F, 0.0133842742F, 0.106174685F,
        -0.0615931302F, -0.0441152342F, -0.0804915577F, -0.100840345F,
        -0.0342489704F, -0.0956653357F, -0.0960882083F, 0.000665611238F,
        -0.0492508F, 0.0602715686F, -0.0114384675F, -0.0980029106F,
        0.0507580973F, -0.0875687823F, -0.00814774167F, 0.00197352516F,
        -0.0312301032F, -0.0204367563F, -0.0715942085F, -0.0135320146F,
        -0.0739101842F, -0.0696634278F, 0.0128920898F, -0.0743222907F,
        0.0498342924F, -0.0320203751F, 0.0314761847F, 0.0511161834F,
        0.0680022389F, -0.0103203896F, -0.0455775969F, -0.00641249726F,
        -0.106960326F, 0.0764415115F, -0.0519346F, -0.0586199537F,
        -0.0439678729F, -0.0185479745F, 0.00980796386F, -0.083631523F,
        -0.0078628622F, 0.0244693216F, -0.0403302F, -0.112136826F, 0.0964195132F,
        0.0173879229F, -0.0953858271F, 0.0938699543F, -0.0525400452F,
        -0.080143854F, 0.032079313F, -0.043710351F, -0.0790934637F,
        -0.100956738F, 0.0693613663F, -0.0087693762F, 0.000314416597F,
        0.0839962885F, -0.0510854796F, 0.0140039511F, -0.0935762301F,
        0.0225076377F, -0.043858692F, 0.0406206585F, 0.0198551845F,
        0.000493257947F, -0.118514374F, -0.00964296423F, -0.00722023798F,
        -0.0412719138F, 0.0256660394F, -0.0357202031F, -0.0105827171F,
        0.032438077F, -0.058654502F, -0.12419796F, 0.0574123859F, -0.0193128865F,
        -0.00665831426F, 0.0661287382F, 0.0600173026F, -0.107396923F,
        0.0240101591F, 0.0612285F, 0.0450768061F, 0.00804149266F, 0.0281291083F,
        0.0327638686F, 0.00104423112F, 0.0746937469F, -0.122067451F,
        0.0430963412F, -0.0607927442F, 0.0399115197F, -0.0229478478F,
        -0.00791756064F, 0.0501849F, -0.067890808F, 0.0293917377F, 0.0192699954F,
        0.104020782F, -0.00800866075F, 0.108167484F, 0.00402142433F,
        0.0192586239F, 0.0456964262F, 0.0391301736F, 0.0267262291F,
        -0.0247756988F, 0.0834578201F, -0.0058060349F, 0.0460360609F,
        0.0877307206F, 0.0510667227F, -0.0509583242F, -0.0716383085F,
        -0.0824234858F, -0.0360667147F, -0.00974897854F, -0.0345202237F,
        -0.0442119129F, 0.00658373721F, -0.00963934604F, -0.0318308845F,
        0.0439941436F, 0.0460810401F, 0.112275571F, -0.0611633062F, -0.0908638F,
        -0.131812841F, 0.106048718F, 0.0654782131F, 0.158417329F, 0.0789094791F,
        0.118485406F, 0.133193642F, 0.0785188451F, -0.0641106814F, 0.11786522F,
        0.0952048376F, 0.0269275848F, 0.131179214F, 0.0658576F, -0.00788715482F,
        0.117023095F, -0.10259743F, 0.0450939611F, -0.0731854886F, 0.0239546113F,
        0.143414244F, 0.0520281941F, 0.0386080109F, -0.0669148415F, 0.115217432F,
        0.0181859657F, 0.0406763181F, -0.00865271222F, -0.0122204581F,
        0.0100190872F, -0.129921839F, 0.0811438039F, -0.0814116597F,
        -0.0149175888F, -0.0220995508F, 0.0649854094F, 0.00644750753F,
        -0.0778847635F, 0.00445931032F, 0.0368540622F, -0.0298262574F,
        0.0576851182F, 0.149537504F, 0.11534334F, 0.0124934474F, -0.00901307352F,
        -0.0848161578F, 0.0661691129F, 0.0190100912F, 0.0531686656F,
        -0.125568554F, -0.0951112807F, 0.0887449235F, -0.0211507026F,
        0.0830559433F, -0.035395056F, 0.0749704912F, 0.137071133F, 0.0265672747F,
        -0.122826047F, 0.0335806981F, -0.026195379F, -0.0565264225F,
        0.131374717F, -0.101864941F, 0.0416993685F, 0.0231296141F,
        -0.0180822965F, -0.0707864091F, 0.0714754462F, -0.0166657288F,
        0.0143983727F, 0.0388709F, -0.0547486581F, 0.0370432884F,
        -0.00419721426F, 0.00203886745F, 0.0805293322F, -0.0264287349F,
        0.0178891774F, -0.0534486696F, -0.00862774F, 0.00293419324F,
        -0.0660764128F, -0.0942830592F, 0.00193311914F, -0.0588973053F,
        0.0585777238F, -0.0529380552F, 0.0944957808F, 0.00141498051F,
        0.0132277012F, -0.0996808782F, 0.0444365069F, 0.00263019209F,
        -0.0171151925F, -0.0681897253F, -0.0776369274F, 0.0777019933F,
        0.00634901645F, -0.00890060607F, 0.040875636F, 0.092898339F,
        0.0506286509F, 0.0244950633F, -0.104292668F, -0.033193551F,
        -0.0773970932F, -0.00167619134F, 0.0847810879F, -0.0946997702F,
        -0.0448765233F, -0.103058226F, -0.0144777047F, 0.0782521889F,
        0.0674122572F, -0.00921656378F, 0.095085375F, 0.11178793F,
        0.000357607147F, -0.0585595965F, 0.143534809F, 0.00167108898F,
        0.0746068358F, 0.0679428801F, -0.0346142389F, 0.0542251579F,
        -0.0043257419F, 0.0123977019F, 0.0902794525F, 0.00877905F,
        0.00592001528F, 0.0532262474F, -0.0235368237F, 0.0173673127F,
        0.0633444339F, -0.0179401152F, 0.0408147089F, 0.00699557457F,
        -0.0360687859F, 0.0232431628F, 0.0372486264F, 0.00858984888F,
        0.0876528844F, 0.00491385F, 0.0435359739F, -0.050037317F, -0.0136168245F,
        -0.0183188356F, 0.0113416538F, 0.124567881F, -0.0257331766F, 0.0191672F,
        -0.0796013325F, -0.0027125082F, 0.00873625278F, -0.0437847935F,
        -0.0156360343F, 0.152810976F, -0.0726466626F, 0.0697990507F,
        0.0736070871F, -0.0620680228F, 0.0337402672F, 0.0499168709F,
        0.0449053235F, 0.0149329612F, -0.0458206236F, 0.0386364758F,
        0.00471363217F, -0.0434258766F, 0.0165379345F, -0.105591118F,
        0.0899955928F, 0.0950778797F, -0.0785157084F, -0.107020363F,
        0.0290481113F, -0.0742052719F, -0.0915808678F, 0.00393028371F,
        0.00619508699F, 0.0106441863F, -0.063154377F, 0.0821037889F,
        0.0282716174F, -0.0620007329F, -0.010560195F, -0.0363616236F,
        -0.0398769677F, 0.0350351F, -0.0733798668F, -0.0397571251F,
        -0.0554073639F, -0.0383922309F, -0.0267497562F, -0.089601174F,
        0.0378626883F, 0.0136622144F, 0.0967855155F, 0.0138615016F,
        0.0693089217F, -0.0487999432F, 0.0384115055F, -0.0478495583F,
        0.00939470809F, 0.0279369075F, 0.0395048968F, -0.0239728801F,
        0.0103240823F, -0.0335972682F, -0.0313984975F, -0.0589039F,
        0.0951216146F, -0.0575988814F, -0.0947332084F, 0.0663290396F,
        -0.00186471967F, 0.00144075765F, -0.0378390588F, -0.0887185335F,
        -0.0937865376F, -0.0275667608F, -0.036806751F, 0.018636249F,
        -0.105591506F, 0.00125577627F, -0.00149006722F, -0.0240651127F,
        0.0532340892F, 0.00668752333F, -0.00130015437F, -0.0372080095F,
        -0.0997509882F, -0.0707563385F, -0.050641261F, -0.0156338F,
        -0.0199267231F, 0.0561743416F, -0.0335134268F, 0.02155439F,
        -0.0776076689F, -0.109817892F, 0.0507830568F, -0.0323181264F,
        0.0377909206F, 0.00807766244F, 0.0228157286F, -0.00311082671F,
        -0.0689778328F, 0.00328022568F, -0.0512264706F, -0.0159422886F,
        -0.0737819299F, -0.105145499F, 0.0427899882F, -0.0166632291F,
        -0.10496705F, -0.0218541268F, 0.0449634977F, -0.0457314216F,
        -0.037198551F, 0.0119332178F, -0.0547134914F, -0.0253232699F,
        -0.0781703219F, -0.0227740873F, -0.12807855F, -0.067120932F,
        -0.0847522095F, 0.00213338737F, -0.0058665853F, 0.0486795641F,
        -0.0215275139F, -0.00516674668F, -0.0329331718F, -0.0923779905F,
        -0.0509164706F, -0.0972827598F, -0.00591416471F, -0.0453767031F,
        -0.0748656616F, 0.111836292F, 0.0348673873F, 0.0802558735F,
        0.0255020577F, 0.0148560172F, -0.0254197381F, -0.052057717F,
        0.0802297741F, -0.00178548787F, 0.0170153975F, 0.0944564864F,
        0.167895436F, 0.003413097F, 0.13009198F, 0.0883699134F, 0.17823559F,
        0.04678661F, 0.0596349761F, 0.038051635F, -0.058061339F, -0.0144121256F,
        0.025145933F, -0.0390443131F, 0.098140046F, -0.0190372374F, 0.046767626F,
        0.0878330097F, 0.00376592F, 0.108149223F, -0.0401368365F, 0.132915735F,
        0.0958414599F, -0.0452046841F, -0.0972408F, 0.031866964F, 0.016012121F,
        -0.0111787831F, 0.0688559F, -0.0674170777F, 0.0402376391F, 0.0756308436F,
        -0.113156587F, 0.0831095353F, 0.0286538582F, 0.0284123085F,
        -0.038803719F, 0.0357548296F, 0.0415283963F, 0.106699459F, 0.0372424349F,
        0.0549213067F, -0.0446106531F, 0.00199133554F, 0.0298900399F,
        -0.0382459722F, -0.0300581399F, -0.00803199131F, -0.0268926F,
        0.0147853745F, -0.0823659375F, 0.0480758287F, -0.0353796743F,
        0.0309021063F, 0.022830382F, -0.129145578F, -0.108529314F,
        -0.0807602853F, 0.00897917897F, -0.0194334108F, 0.0920351148F,
        -0.112972066F, -0.0698838308F, -0.0380855165F, -0.0960237831F,
        -0.12250635F, 0.0560857691F, -0.000813230057F, 0.0116020041F,
        -0.00730204815F, -0.0572023354F, -0.136587173F, -0.0595579408F,
        -0.05838532F, -0.121139199F, -0.0683154538F, -0.0829065442F,
        0.0152284522F, -0.00653640181F, -0.0138957901F, 0.00696136663F,
        -0.0524681658F, -0.0163678564F, -0.0833473504F, -0.00663771573F,
        -0.012724882F, 0.0395027F, -0.0178421717F, 0.00970585831F,
        -0.0593426488F, -0.0836320296F, -0.0392145701F, 0.0136297941F,
        -0.0593801774F, 0.0336308F, 0.0427895598F, 0.0583241619F, -0.0544712245F,
        -0.066637218F, 0.0169783942F, 0.0509826317F, 0.0597029664F,
        -0.0716971084F, -0.0822853744F, -0.00181217736F, -0.0617728569F,
        -0.0800329223F, -0.056275811F, -0.101732582F, -0.0911657214F,
        -0.045521535F, 0.00959430449F, 0.00866554119F, -0.0902031511F,
        -0.0541192442F, -0.00788420811F, -0.0763156042F, -0.00232901424F,
        -0.0351873599F, -0.0187543947F, -0.0116583165F, -0.0714082569F,
        0.00145075831F, 0.0545611419F, -0.0292383749F, -0.0250680316F,
        -0.0854400098F, 0.00296540582F, -0.0202321F, 0.021266019F,
        -0.0867160112F, 0.0165337175F, -0.00152965146F, -0.0964671299F,
        -0.0602397695F, -0.0330487862F, 0.0626904145F, -0.07595139F,
        0.0441366918F, -0.027861746F, -0.0224401448F, -0.159015328F,
        0.0649662241F, 0.0298831929F, 0.0284011904F, -0.15021643F, 0.0539240539F,
        0.000241791553F, 0.0282065347F, -0.0105674258F, -0.0399732F,
        0.0253472738F, -0.0663355812F, 0.0556256063F, 0.0814449713F,
        -0.00406283466F, 0.0495237187F, -0.0697247088F, 0.05099326F,
        0.0938131586F, 0.0269644409F, -0.0581539311F, 0.0842170417F,
        0.0160830393F, -0.0343585312F, 0.0334522538F, -0.0488402136F,
        0.0602104254F, 0.0747353658F, -0.0591391549F, 0.0383414477F,
        -0.00962258782F, -0.0862250701F, 0.050853651F, 0.0483658537F,
        -0.005800399F, 0.0363977663F, 0.0303522218F, -0.0171935447F,
        -0.0134208221F, -0.0408032946F, -0.075972639F, -0.129664F,
        -0.0233608466F, -0.0368956514F, 0.0890024155F, 0.0369767062F,
        0.0564690642F, 0.0434138626F, -0.0763851851F, -0.0204185862F,
        0.0333194844F, -0.0505462326F, 0.0295317937F, 0.0377079844F, 0.02531307F,
        0.0683049262F, 0.0291869678F, -0.0849400684F, 0.0130103705F,
        -0.0132342307F, 0.00229759864F, -0.0602438897F, 0.00687411847F,
        -0.124622583F, 0.0155296056F, 0.0410558097F, -0.0349531956F,
        -0.00153955887F, 0.0354168154F, 0.00903733261F, 0.074661307F,
        -0.0435138084F, -0.115451358F, -0.0743172094F, 0.0482467748F,
        -0.101710699F, 0.0234734751F, 0.0489740968F, -0.0779745802F,
        -0.00203075306F, -0.0608415939F, -0.00342187751F, 0.103679039F,
        0.000662753941F, 0.0457299463F, -0.0566401184F, 0.0168366078F,
        -0.0216585305F, 0.0658757836F, -0.061310377F, -0.0669110715F,
        -0.00117575098F, 0.0156919323F, 0.0524018481F, 0.00943419524F,
        -0.004756012F, 0.0936689F, 0.0860656351F, 0.02049434F, -0.0346439704F,
        0.0306050349F, -0.0618089177F, -0.0810334459F, -0.0739423782F,
        -0.0965352803F, -0.0592545085F, -0.0251607448F, -0.0481517054F,
        0.0664880872F, -0.0606226884F, 0.0275056921F, -0.0163838863F,
        -0.00087738462F, -0.0857318342F, 0.0298158452F, 0.0606948063F,
        -0.0113699837F, 0.0102763893F, 0.0758907199F, 0.0330780111F,
        -0.0100449687F, -0.00637577381F, -0.0456400812F, -0.067713812F,
        0.0767514333F, 0.00863297191F, -0.133155942F, -0.0493656099F,
        -0.0878278241F, 0.0236909632F, 0.0404405966F, -0.0122584011F,
        -0.0767514706F, -0.00291752396F, -0.00252875732F, 0.0125507F,
        0.0404395871F, 0.0420514494F, -0.0236613564F, -0.0221516788F,
        -0.118143201F, -0.0315704122F, -0.0824446231F, -0.0792708173F,
        -0.148489118F, -0.094002232F, -0.0263965949F, 0.0691716596F,
        0.036578618F, 0.134237811F, 0.037470445F, 0.027848F, -0.0510871187F,
        0.0739705339F, 0.0438430458F, 0.118569955F, 0.0954604521F,
        0.00312851951F, 0.0648707226F, -0.0280208029F, -0.0873357F,
        -0.013670533F, 0.0243780408F, 0.0684171692F, 0.109833114F, 0.034180712F,
        0.128389761F, 0.0988221839F, 0.0369247F, 0.0714435279F, -0.012864396F,
        -0.00110493333F, -0.0394487642F, -0.084120594F, 0.0273318365F,
        0.0409075469F, 0.0568409152F, -0.0479415879F, -0.111242339F,
        -0.0522369742F, -0.0117509095F, 0.0529215F, 0.0802865401F, 0.0241870303F,
        -0.0560914725F, -0.0148723647F, 0.00692314608F, 0.116639987F,
        0.032302618F, 0.0977295861F, -0.0569901317F, 0.0101817269F,
        -0.0112822512F, 0.104221709F, 7.98571E-5F, 0.0465511642F, 0.145196825F,
        0.0125443125F, 0.0814937279F, -0.0212238133F, 0.0169086307F, 0.0680978F,
        0.099065192F, 0.0133088659F, -0.0550957173F, -0.0683388561F,
        -0.00706935255F, 0.0577571392F, 0.0153067699F, -0.014849795F,
        -0.0369725265F, -0.0268914532F, 0.0969832316F, -0.038089674F,
        0.0192458238F, -0.0437527038F, 0.0918320641F, -0.0211112853F,
        0.0287660789F, -0.0884033218F, -0.0429153666F, -0.0158553291F,
        -0.0709606335F, -0.0365546644F, 0.0208127052F, 0.0325061828F,
        -0.0241410844F, 0.0890762806F, -0.0291344263F, 0.0661221519F,
        0.0366855264F, -0.0324604847F, 0.026052203F, -0.0873045623F,
        0.0374981165F, 0.104891814F, -0.0467044F, -0.0358899273F, 0.0657028F,
        0.0463748425F, -0.0177380685F, 0.0375867598F, -0.0906126872F,
        0.0316452384F, 0.0204191189F, -0.120574713F, 0.0335721932F,
        0.00978385936F, 0.0379994325F, -0.0864461884F, 0.0800328255F, 0.0848727F,
        -0.0668905526F, -0.0366558842F, 0.017550502F, -0.0807188451F,
        0.0488844253F, -0.00623499136F, 0.0334251F, 0.0107644089F, -0.12027479F,
        0.0954849944F, 0.102902062F, -0.0663249046F, -0.035024941F,
        -0.0336221941F, 0.0638066158F, 0.0363043807F, 0.00653361762F,
        0.0217286125F, -0.0218299571F, -0.0413164757F, -0.00826810673F,
        -0.018771939F, 0.0114511456F, 0.0348932818F, 0.0843574256F, 0.104153946F,
        0.109825335F, -0.0674152F, 0.0460018516F, 0.0393615253F, 0.0358724333F,
        -0.080615066F, 0.0625658259F, 0.0656936467F, 0.0231962F, 0.0421749391F,
        0.0611211434F, -0.00245913723F, -0.0209863707F, 0.0506538488F,
        -0.0354563333F, 0.0590186939F, 0.117488474F, 0.0708068833F,
        -0.00528522348F, 0.0638088509F, 0.0357415527F, -0.00546864374F,
        0.0103047F, -0.0118930051F, 0.00748387678F, -0.0144639984F, 0.015490965F,
        0.0174765103F, 0.0380808599F, 0.0237088595F, -0.0431442745F,
        -0.0296951197F, -0.0907987803F, 0.0387135707F, 0.0251850244F,
        -0.0403760411F, -0.0832174495F, 0.0310236178F, 0.0232187286F,
        -0.0549339056F, 0.0612411797F, -0.0799408183F, 0.020750748F,
        0.000242587907F, -0.0792590156F, -0.00199310621F, -0.123348653F,
        -0.0729683116F, 0.0464962348F, -0.0203202683F, -0.0437665321F,
        -0.0289614964F, -0.0168907624F, 0.0588744171F, -0.0672304705F,
        -0.0787123069F, -0.0529462285F, -0.0995595679F, 0.0731941834F,
        0.0108266799F, 0.0287558623F, 0.0691312626F, -0.0137287714F,
        -0.0592011213F, 0.0772548094F, 0.0448583588F, 0.0380877F, 0.0609848499F,
        0.0190978907F, -0.0166309308F, -0.0399427414F, 0.0233061574F,
        0.0794074684F, -0.0367990062F, -0.0946613252F, -0.02069683F,
        0.00102017471F, -0.0280574262F, -0.0237693023F, 0.0267766379F,
        -0.00256212661F, 0.0590307936F, -0.0726452917F, -0.0553443357F,
        0.0521571785F, 0.0480170138F, -0.0334009081F, 0.0645754263F,
        -0.0877411515F, 0.013139667F, -0.0510618798F, -0.031657F, -0.017451277F,
        -0.00681645749F, -0.0659831911F, -0.0136676477F, -0.00323491171F,
        0.0381364599F, 0.0534959845F, 0.0430990942F, -0.0720408782F,
        -0.0237525851F, 0.013915428F, -0.0958234072F, -0.022119958F,
        -0.0778835639F, 0.0134825082F, 0.0477023795F, 0.0156126479F,
        -0.0334597938F, -0.0303292312F, -0.0656938329F, -0.109784946F,
        0.00677460618F, -0.0465996899F, -0.102532886F, 0.0131490063F,
        0.0161756352F, -0.00567850191F, 0.0294082202F, -0.0196373463F,
        0.0266198702F, -0.0526699647F, -0.00110359991F, 0.0850199908F,
        -0.0225870181F, -0.00397787197F, 0.078221865F, 0.0819216147F,
        0.0301957689F, 0.0998092443F, 0.0262591708F, 0.0711562F, -0.0704338625F,
        -0.0362790041F, 0.0422656536F, -0.0726771727F, 0.0617216788F,
        0.0802246109F, -0.0580420606F, 0.0200215522F, -0.0132143712F,
        -0.0777782053F, -0.0657561719F, -0.0105310706F, 0.0640558749F,
        -0.0281610154F, 0.000378166209F, 0.071095027F, -0.0209698379F,
        0.0183849931F, 0.0437618271F, 0.00279126153F, 0.058687523F,
        -0.0915073529F, -0.00306104822F, -0.014573982F, 0.0492351316F,
        0.103283785F, -0.0316970944F, 0.0995701477F, -0.032532759F,
        0.0238523055F, 0.0794601962F, -0.0527347848F, -0.0379490629F,
        0.0186297987F, 0.0455662943F, -0.0274534859F, 0.082406342F,
        -0.00506217405F, -0.0420691222F, -0.0292416289F, 0.0255955104F,
        -0.0707087666F, 0.000390471047F, 0.122249916F, -0.0164576247F,
        0.0496800654F, -0.0330825634F, 0.021628378F, 0.0115764588F,
        -0.0217679013F, 0.0050106491F, -0.106268302F, -0.0195314307F,
        -0.0014345533F, -0.0900670364F, -0.0765926167F, -0.0655190796F,
        -0.0537545644F, 0.0660929382F, -0.0262192748F, -0.0931867138F,
        0.0602023117F, 0.00447393255F, 0.0524236932F, 0.0157769248F,
        0.0917990357F, 0.0337046646F, 0.00272710319F, 0.101481833F,
        -0.0280877519F, 0.0201010313F, -0.0270340256F, -0.0781493038F,
        -0.0152183231F, 0.00664546387F, 0.0148524269F, -0.0784127191F,
        0.018095145F, 0.0908005238F, 0.0362350047F, 0.025465576F, 0.013123353F,
        -0.0263259914F, -0.0729577467F, 0.0685527176F, -0.0516930223F,
        -0.0927697197F, -0.00104097975F, 0.0134196915F, 0.0450251698F,
        -0.0918631F, 0.0908975378F, 0.0279758628F, -0.0861705542F,
        -0.0351464115F, -0.0603402182F, -0.0148103768F, -0.0404600799F,
        0.0147643657F, -0.0900149345F, 0.0244394727F, -0.0679749772F,
        0.0313183777F, 0.0693051F, 0.0292281918F, 0.0564276427F, 0.0468055382F,
        -0.070464544F, 0.0603369027F, -0.0503207445F, 0.0868407562F,
        0.036440786F, -0.0606905073F, -0.0870687142F, 0.0148190958F,
        0.0419556685F, 0.0251049977F, 0.0327939317F, -0.0857606F,
        -0.00336688734F, 0.0636109188F, -0.104589894F, -0.0579591393F,
        -0.0737040862F, 0.0361196399F, -0.0573164523F, -0.0966438055F,
        -0.0642396286F, -0.0461042486F, 0.0238053463F, 0.0565313101F,
        -0.0868139938F, 0.0244939122F, -0.122296326F, 0.0938449204F,
        0.0939820558F, -0.0144289443F, 0.0164886452F, 0.0933241174F,
        -0.000906910747F, 0.0217736494F, -0.0689630583F, 0.0498657264F,
        0.0715980381F, -0.0308576748F, -0.0613931604F, -0.00159900531F,
        0.0388708338F, -0.0112151103F, 0.02697495F, 0.0855870321F,
        -0.00237497082F, 0.0454492569F, 0.0951994807F, -0.00644456F,
        0.0663621053F, -0.0154631399F, 0.0878530443F, 0.0193694197F,
        -0.0299473498F, 0.00387979089F, -0.0773190707F, -0.102259062F,
        0.0254441369F, -0.0728851855F, 0.0102766892F, -0.0397217F,
        0.00493426668F, -0.0755503178F, 0.0685983598F, -0.101403482F,
        0.0313755535F, 0.0227990057F, -0.0067341947F, 0.013524875F,
        0.0335124321F, 0.0265670456F, -0.0213331152F, -0.0292372908F,
        0.0368606038F, 0.07892932F, -0.122588933F, 0.00577220786F, 0.0665475503F,
        0.0573179498F, -0.0400474519F, -0.0572147369F, 0.0143612484F,
        -0.0935586095F, 0.051438F, -0.0643930361F, 0.0393969566F, -0.0128100272F,
        0.0639884472F, -0.0368786454F, -0.0661621317F, -0.00402290747F,
        0.0237143096F, 0.049709674F, 0.0418026708F, -0.0451161675F,
        -0.0113485046F, -0.0426197164F, 0.109541751F, 0.0712382719F,
        0.00835318491F, -0.0208143163F, -0.0352266729F, 0.054950159F,
        0.0309531093F, -0.0272912271F, -0.0177579485F, 0.0273427255F,
        -0.0646965653F, -0.0458782837F, -0.0141364057F, -0.00641709799F,
        -0.0403813757F, -0.0288707316F, 0.0219790358F, 0.0609779768F, 0.028889F,
        -0.0495771766F, 0.0677121505F, -0.00397416204F, -0.000364070904F,
        -0.0451105051F, -0.0563310198F, -0.0287558455F, 0.01305323F,
        0.00673735561F, 0.0879109F, -0.0417136699F, -0.0407674238F,
        -0.00239565084F, 0.0326538682F, -0.0571882166F, 0.0648281872F,
        -0.0764884874F, -0.00800695829F, 0.0940985829F, -0.0594241358F,
        -0.0833594054F, 0.0233256221F, -0.0747703612F, -0.0623193122F,
        0.0522799827F, -0.13628912F, -0.0822873041F, 0.0513569899F,
        -0.0216103066F, -0.00734218862F, -0.0209378209F, 0.0532385111F,
        -0.0685631335F, 0.0477391668F, -0.000797268411F, 0.0630830824F,
        0.086963132F, -0.128979042F, -0.00681885332F, -0.116828799F,
        -0.0463377461F, 0.00559446262F, 0.134738654F, -0.0752749F, 0.0238112416F,
        0.10025347F, -0.000402320089F, 0.0942873955F, -0.0552028716F,
        0.0602172539F, 0.0210831854F, 0.033367727F, -0.07359346F, 0.0235060249F,
        -0.0341427103F, 0.091468364F, 0.0500746928F, -0.0887847468F,
        -0.00180709164F, -0.014392551F, -0.00255493657F, 0.0858375207F,
        0.0871398523F, 0.0571566671F, -0.0637330115F, 0.0236421414F,
        0.0231532361F, -0.0217800066F, -0.0094756F, 0.0665186569F,
        0.00287337624F, -0.0350620858F, -0.0245634578F, -0.104464673F,
        0.0143605256F, -0.0571919121F, -0.0574424677F, -0.0245979764F,
        -0.0111041022F, 0.0357637629F, -0.0205354F, -0.0196716189F,
        0.0778393745F, 0.0807521418F, -0.0775411353F, 0.0252983738F,
        -0.0158629082F, 0.0700561702F, 0.0303475391F, -0.095970571F,
        -0.110029571F, 0.11698062F, -0.0230207741F, 0.0285127629F, -0.03566017F,
        0.0636881068F, 0.00777586177F, -0.0552256592F, -0.0768193156F,
        -0.100754783F, -0.0529100411F, -0.111007899F, -0.0145913446F,
        -0.0703569427F, 0.00745202508F, -0.0112720653F, -0.0192245729F,
        0.0273051672F, 0.0311426632F, -0.0324250571F, 0.0351847969F,
        -0.0297122505F, 0.0411880501F, 0.0568432473F, -0.0591854975F,
        0.074111931F, 0.0857041553F, 0.0348125435F, -0.0070318887F,
        -0.0988060758F, 0.0025928251F, 0.00234504417F, 0.0918987319F,
        -0.0194920897F, 0.0752392858F, 0.108757034F, 0.0580520406F,
        0.0705838129F, 0.0850608945F, 0.057305865F, -0.0885344222F,
        -0.107969537F, -0.0204976518F, -0.117239885F, -0.00558521925F,
        -0.0347546302F, 0.00915117748F, 0.0126684168F, 0.151234984F,
        -0.086693421F, 0.00654095644F, 0.0697224438F, -0.0192833338F,
        -0.0339515842F, -0.0412837304F, 0.0937178F, -0.0184331164F,
        -0.0180465207F, 0.0212394148F, -0.0273931734F, -0.0557687022F,
        -0.00269481936F, 0.05140898F, 0.0559658147F, 0.00635545654F,
        0.0253928918F, 0.0434655584F, 0.138348103F, 0.0644282252F,
        -0.0889870897F, 0.126723409F, 0.0213979576F, 0.0296304468F,
        -0.000602452958F, 0.0722115859F, -0.107596196F, 0.0626496375F,
        0.0517907478F, -0.0141141294F, 0.0264048576F, -0.0355108231F,
        0.0548677295F, -0.0452345163F, 0.062495295F, -0.0932061747F,
        0.0657738522F, 0.0598778203F, 0.0697559044F, 0.0431231558F,
        -0.0239642784F, 0.084516421F, -0.0605187789F, -0.102514833F,
        -0.111422107F, -0.0227088332F, 0.0736939833F, 0.109665051F,
        0.0278607178F, 0.0313289F, 0.0784957334F, 0.0894518495F, -0.0634310469F,
        0.16437842F, 0.112748206F, 0.000774210203F, 0.0852269F, 0.0315738767F,
        0.00830792636F, 0.0457472093F, -0.0127825486F, 0.0947189704F,
        -0.0125832278F, -0.0861791074F, 0.0663350895F, 0.00573853822F,
        -0.0318305306F, 0.0156628732F, 0.110617861F, 0.0492012538F,
        0.0333822966F, -0.043996051F, 0.00839231443F, 0.0343544744F,
        0.00847705454F, 0.103330135F, -0.00691286614F, -0.0670152754F,
        -0.0404434316F, 0.00802738219F, -0.0735455379F, -0.0498164222F,
        -0.0385291614F, -0.10154219F, 0.0881431F, -0.113163486F, 0.0780373141F,
        -0.0107738758F, -0.00489623565F, 0.0153210461F, 0.0299129F,
        0.0739996135F, 0.00510022836F, 0.0733655542F, -0.0199138671F,
        0.0301468652F, -0.117481522F, 0.0937884375F, -0.0164230578F,
        0.067044355F, 0.0907182842F, -0.0365650356F, 0.0290992297F,
        -0.0638724715F, -0.0252083149F, -0.0599556528F, 0.0264310818F,
        0.0473697111F, 0.00164835225F, 0.0753175691F, -0.0171685759F,
        -0.0409729555F, 0.0140148867F, 0.0420331731F, -0.0200751889F,
        0.095938094F, -0.018999679F, -0.0450591892F, -0.0801901668F,
        0.0220115166F, -0.0518047325F, 0.0710369349F, 0.0880670324F,
        -0.000722809113F, 0.00188091851F, 0.08447171F, -0.0339423195F,
        0.0181808285F, 0.0165609214F, 0.0316275507F, -0.0946348906F,
        0.0857375413F, -0.0101780742F, -0.0459651053F, 0.0651471689F,
        0.0108190672F, 0.0274071079F, 0.0521916151F, 0.0195430517F,
        0.0477663726F, -0.020570863F, -0.0486665815F, 0.0516455658F,
        0.010229948F, -0.105071463F, 0.0642680749F, 0.000536360429F,
        -0.00465032971F, 0.0742521584F, -0.0425923802F, -0.0700307712F,
        0.0017347025F, -0.0545490384F, -0.0144789033F, 0.043309588F,
        -0.0321942121F, 0.0177203976F, 0.0795185789F, 0.0413469933F,
        0.0341477878F, -0.0966034606F, -0.0173321739F, 0.0659443662F,
        0.0394583531F, 0.0308748074F, -0.0419599935F, 0.0080761807F,
        -0.0643034577F, 0.0276074167F, 0.070711486F, 0.0530485287F,
        0.0831272751F, -0.0484779403F, 0.0607824102F, -0.0576043501F,
        0.00227568718F, -0.0905160159F, 0.0335724913F, 0.0278042704F,
        0.0429090336F, -0.018133916F, -0.055208914F, -0.111767128F, 0.08642409F,
        0.0857129693F, -0.0315676667F, 0.0299037434F, 0.00824339F,
        -0.0335273556F, -0.0614485443F, -0.0571218F, -0.129554048F,
        -0.0560223535F, -0.010163513F, -0.0860394388F, -0.0171261616F,
        -0.0293268524F, -0.0623254627F, -0.0719051883F, 0.0717305541F,
        -0.0140576474F, -0.0167376101F, -0.0486666933F, -0.0748582F,
        -0.0917033255F, -0.0150153199F, -0.0149176195F, 0.0163152274F,
        -0.0456505455F, 0.0226619635F, -0.0767100304F, -0.0138021279F,
        -0.0606257729F, -0.0314052477F, -0.0860853F, 0.0823619887F,
        0.00775918085F, -0.0450989753F, -0.0877264142F, -0.0175270457F,
        -0.0408389606F, 0.0574143194F, -0.0280171894F, -0.0806698725F,
        -0.0959172547F, -0.0787922442F, 0.0372872874F, -0.0757118613F,
        0.031701114F, -0.0210520327F, -0.022756191F, -0.0120547358F,
        0.0589977726F, 0.0687508881F, -0.0151663367F, 0.01103976F, 0.0105123082F,
        0.0567859486F, 0.0891766325F, 0.0983678624F, 0.0502025F, 0.148556888F,
        0.0340231359F, -0.00921377726F, 0.0123808524F, 0.065865986F,
        -0.0455780812F, 0.0735929832F, -0.00268720184F, 0.00907334872F,
        0.00658780755F, -0.01917913F, 0.0480353758F, -0.0368002467F,
        -0.0368282534F, -0.0108045088F, -0.00108065759F, 0.0953229442F,
        0.113032132F, 0.0484294407F, -0.0270708054F, -0.01819144F, 0.0508426279F,
        0.0641156584F, -0.0518075936F, 0.0685254633F, 0.00858932268F,
        -0.0309799388F, -0.0100335022F, 0.0390197448F, 0.0695344F, 0.0411601253F,
        -0.00433098571F, 0.00267887744F, 0.0239952207F, 0.0192272719F,
        0.0519727059F, 0.0138499103F, -0.0602706745F, -0.000228676858F,
        0.0933198258F, 0.0476444885F, -0.0332150795F, -0.0530031659F,
        0.0366373546F, -0.00639682868F, -0.0670524761F, -0.0533636957F,
        -0.0225944165F, 0.0614512637F, 0.0681976378F, 0.0680211857F,
        0.0921178535F, 0.0286510959F, -0.00216469099F, -0.0949134231F,
        -0.0543650165F, 0.061993327F, 0.0269665401F, 0.00564423669F,
        0.00866491161F, 0.0728620291F, -0.0601195581F, 0.0375434384F,
        -0.0342906117F, -0.0362199619F, 0.0656082928F, -0.0150691224F,
        0.0705352873F, -0.0406692214F, -0.0605248399F, -0.0290954914F,
        0.0303658023F, 0.0969126299F, 0.00362630864F, -0.0718645751F,
        -0.0298088398F, 0.011414581F, -0.0125015285F, -0.0411258861F,
        -0.0652581751F, -0.0327209644F, -0.0654131845F, -0.0330790766F,
        -0.00491610169F, -0.00416660309F, 0.0943092F, -0.0202982835F,
        0.0841143578F, 0.0437407903F, -0.0550403111F, 0.106153749F,
        -0.0664784461F, 0.0338912793F, 0.0200265199F, -0.00180495938F,
        0.0126958601F, -0.0183475707F, 0.0100799622F, -0.0504977033F,
        0.0176325273F, 0.0654336959F, 0.0538869761F, 0.0283939727F,
        -0.00981338322F, -0.0552449562F, -0.134099483F, 0.0682072788F,
        -0.0511149056F, 0.0346855037F, -0.113289669F, -0.071181491F,
        -0.0210577864F, -0.0694595426F, -0.0887033492F, 0.00719196489F,
        -0.0558373295F, 0.0643563122F, -0.027569145F, -0.0163343195F,
        -0.0363535285F, -0.0474063307F, -0.0601273216F, -0.0673662722F,
        -0.0478191599F, 0.0618101731F, -0.0795877F, 0.00394637324F,
        0.0123988353F, 0.000340858125F, -0.00240887515F, -0.0220574625F,
        -0.038462352F, 0.0561337F };

      static const float bias2[64]{ -0.025125999F, 0.00317621953F,
        -0.0116604157F, -0.0290403906F, -0.0350205302F, -0.00805905368F,
        -0.00366964354F, 0.00646275049F, -0.0152029889F, -0.000442647492F,
        -0.0102606583F, -0.00602593552F, -0.0202424247F, 0.00238912716F,
        -0.0166922826F, -0.0144558195F, -0.0253804438F, -0.0200136546F,
        -0.00760238757F, 0.00256216177F, -0.0232033767F, -0.021970829F,
        -0.0231849942F, -0.00939343404F, -0.00358240725F, -0.0123662688F,
        -0.0262937546F, -0.0202292074F, -0.0245236736F, -0.0330378935F,
        0.0196880642F, 0.00430325465F, -0.0175201986F, 0.0034963889F,
        -0.00675991923F, -0.0227035023F, -0.0216866788F, -0.010334624F,
        -0.021288231F, -0.00363576412F, -0.00610022712F, -0.019946415F,
        0.00825731643F, -0.00639536139F, -0.0242498796F, -0.0218537394F,
        -0.0136672035F, -0.0267854109F, 0.000441530254F, -0.0209457092F,
        0.013834619F, -0.0126837986F, 0.00783823431F, -0.00641921F,
        -0.0144933984F, -0.0107786702F, -0.0235877503F, -0.0344515182F,
        -0.017795587F, -0.00279777707F, -0.0122497203F, -0.0230712779F,
        -0.0264026187F, 0.00548381F };

      b_convolution(&X[0], &Z[0], &weights2[0], &bias2[0]);
      b_elementwiseOperationInPlace(Z);
    }

    void conv2dDirectOptimizedColMajor(const float X[784], float Z[25088])
    {
      static const float weights2[4608]{ 0.0907927305F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.122094981F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.14644216F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.155505404F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0421757847F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.179585621F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.098126784F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0484399498F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0675351322F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.16890949F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, -0.0790292844F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.199595481F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0405933745F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.126343042F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0970619693F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.14600426F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.00347579969F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.160203725F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0713205561F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0533522852F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.043708615F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00922709703F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.105536781F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0796640292F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.129449338F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.137791649F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0949545056F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0209922101F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0323983952F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0293344352F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0774374902F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0449065641F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.165450752F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0480547F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0863554925F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0567582138F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.165707201F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0894653797F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0132893231F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.108402304F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.128205165F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.103154108F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0338454619F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.111836463F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.00596278626F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.166800708F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0284275375F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0245942324F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0817875639F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0248561669F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.12409962F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.011576266F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.127824709F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.165574178F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0108957179F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0940106958F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.146790668F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.123744316F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0283041224F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.178351015F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0561821312F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.161794856F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0161129776F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0594613552F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0522498041F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0372393914F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0281768888F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.140504062F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.018064091F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0942634195F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0528933816F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0864214823F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0299612097F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.063412793F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.112822503F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0834078416F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.114839211F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0428951681F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.163074091F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.132989332F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.181444466F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00959168561F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0864463896F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.152292982F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.13331604F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0289249234F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.10024561F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0923238471F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0795244F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.143881977F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0340244584F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.188625529F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.123828411F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.197128221F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0379289687F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0528359488F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0940287262F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.116716325F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0481909327F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0370839946F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.15354082F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0260404218F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0963853225F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00402418105F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0508170202F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.110944055F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.118297875F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0422899053F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0428671837F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0685254261F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0872265622F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.175205752F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0358582027F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.172178254F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.00783485454F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.126958087F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.169509098F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0529795848F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.122580238F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0169596039F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0915606543F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.143617839F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.00219688448F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.116733238F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.137575418F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.112638585F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0990527123F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0717303753F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0564298742F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.183112353F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0497475527F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.172612637F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.116126917F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.158623755F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0422593281F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0365378149F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.137222826F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.144039199F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.164627329F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0770671517F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0311871469F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0584828779F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0610535853F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.160562664F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.137378335F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.141217992F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0601683594F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.158993915F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.196794078F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0830968395F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0291584693F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0688942522F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0914511F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.193645209F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.029268736F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.16883342F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.128171697F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0474927463F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.111759536F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, -0.144399345F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0580670275F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.213730425F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.131931901F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0974787474F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0602931865F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.118075415F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.131392762F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.112248793F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.165059149F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0277241413F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0213656686F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0696966499F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00517730694F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.114260845F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.134521142F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.119770996F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.127543971F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0531841367F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.0996071622F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00160287821F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.015603031F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.10950467F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.126425281F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0915798F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0339593664F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.21402283F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0984486F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.152437255F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0541881F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.213632748F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0864915624F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0481298529F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.000475625537F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.109466277F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0225960091F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00844986271F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.10103339F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.122043557F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.00289827259F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.125693262F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0593784451F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.107746273F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.211112022F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.184265807F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.169928268F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.125483036F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0403678454F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.218207285F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0851878F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.00293051288F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0570618026F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0109101702F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0786904618F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.152432546F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0386219546F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.118591361F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.131945103F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.179935381F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0346606411F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0921787173F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.067309387F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0930809379F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.109022684F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.115223527F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.184804305F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0369052887F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.033740785F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.16987367F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.085277386F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.00566210411F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0107797394F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.201347455F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0369167253F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, -0.157727063F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.151506126F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, -0.115143865F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.177548572F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, -0.0691716596F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0805916F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0144191822F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0412621163F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.179849908F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.207837045F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0569440462F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.166665375F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.156908706F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.16823335F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.040317975F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.199407175F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0271324385F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.179764852F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0299497452F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.115886956F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0653740466F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0925610512F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0634244829F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.119272791F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.00416922942F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.194610581F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.123850331F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, -0.0865792111F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.131301329F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0497690514F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0245675519F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0999551639F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0649626553F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.163311362F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0534286126F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.135816023F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0875263214F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0199791528F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0698123947F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.15446265F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.197561428F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        -0.0589390211F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0473972932F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0918983147F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.200596973F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.122050822F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.200720802F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.11621163F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, -0.161536887F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.119952239F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, -0.123827353F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.0661649704F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, -0.0166100096F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, -0.1161303F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.220524833F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
        0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F };

      static const float bias2[32]{ -0.00707217446F, -0.0054557994F,
        -0.0101987468F, 0.00332028139F, 0.000709732936F, -0.0043967953F,
        0.000247988792F, -0.0156390332F, -0.00194077601F, -0.0132692782F,
        -0.00782666262F, 0.00654294668F, -0.0112436032F, -0.0163678881F,
        -0.0103984987F, -0.00698037213F, -0.0123826042F, -0.00938023813F,
        -0.00876201F, -0.0023000841F, -0.0112935342F, -0.00327621493F,
        -0.00401205895F, -0.0149075352F, 0.0185798556F, -0.0197621267F,
        -0.00996255782F, -0.0129517764F, -0.00934279524F, -0.00900064129F,
        0.00238894252F, -0.0144028608F };

      convolution(&X[0], &Z[0], &weights2[0], &bias2[0]);
      elementwiseOperationInPlace(Z);
    }
  }
}

// End of code generation (conv2dDirectOptimizedColMajor.cpp)
