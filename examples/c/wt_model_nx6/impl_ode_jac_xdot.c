/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

#ifdef CODEGEN_PREFIX
  #define NAMESPACE_CONCAT(NS, ID) _NAMESPACE_CONCAT(NS, ID)
  #define _NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else /* CODEGEN_PREFIX */
  #define CASADI_PREFIX(ID) impl_ode_jac_xdot_ ## ID
#endif /* CODEGEN_PREFIX */

#include <math.h>

#ifndef real_t
#define real_t double
#endif /* real_t */

#define to_double(x) (double) x
#define to_int(x) (int) x
#define CASADI_CAST(x,y) (x) y
/* Pre-c99 compatibility */
#if __STDC_VERSION__ < 199901L
real_t CASADI_PREFIX(fmin)(real_t x, real_t y) { return x<y ? x : y;}
#define fmin(x,y) CASADI_PREFIX(fmin)(x,y)
real_t CASADI_PREFIX(fmax)(real_t x, real_t y) { return x>y ? x : y;}
#define fmax(x,y) CASADI_PREFIX(fmax)(x,y)
#endif

#define PRINTF printf
#ifndef CASADI_SYMBOL_EXPORT
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#if defined(STATIC_LINKED)
#define CASADI_SYMBOL_EXPORT
#else /* defined(STATIC_LINKED) */
#define CASADI_SYMBOL_EXPORT __declspec(dllexport)
#endif /* defined(STATIC_LINKED) */
#elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#define CASADI_SYMBOL_EXPORT __attribute__ ((visibility ("default")))
#else /* defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) */
#define CASADI_SYMBOL_EXPORT
#endif /* defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__) */
#endif /* CASADI_SYMBOL_EXPORT */
real_t CASADI_PREFIX(sq)(real_t x) { return x*x;}
#define sq(x) CASADI_PREFIX(sq)(x)

real_t CASADI_PREFIX(sign)(real_t x) { return x<0 ? -1 : x>0 ? 1 : x;}
#define sign(x) CASADI_PREFIX(sign)(x)

void CASADI_PREFIX(fill)(real_t* x, int n, real_t alpha) {
  int i;
  if (x) {
    for (i=0; i<n; ++i) *x++ = alpha;
  }
}
#define fill(x, n, alpha) CASADI_PREFIX(fill)(x, n, alpha)

void CASADI_PREFIX(trans)(const real_t* x, const int* sp_x, real_t* y, const int* sp_y, int* tmp) {
  int ncol_x = sp_x[1];
  int nnz_x = sp_x[2 + ncol_x];
  const int* row_x = sp_x + 2 + ncol_x+1;
  int ncol_y = sp_y[1];
  const int* colind_y = sp_y+2;
  int k;
  for (k=0; k<ncol_y; ++k) tmp[k] = colind_y[k];
  for (k=0; k<nnz_x; ++k) {
    y[tmp[row_x[k]]++] = x[k];
  }
}
#define trans(x, sp_x, y, sp_y, tmp) CASADI_PREFIX(trans)(x, sp_x, y, sp_y, tmp)

void CASADI_PREFIX(copy)(const real_t* x, int n, real_t* y) {
  int i;
  if (y) {
    if (x) {
      for (i=0; i<n; ++i) *y++ = *x++;
    } else {
      for (i=0; i<n; ++i) *y++ = 0.;
    }
  }
}
#define copy(x, n, y) CASADI_PREFIX(copy)(x, n, y)

static const int CASADI_PREFIX(s0)[15] = {6, 6, 0, 1, 2, 3, 4, 5, 6, 0, 1, 2, 3, 4, 5};
#define s0 CASADI_PREFIX(s0)
static const int CASADI_PREFIX(s1)[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
#define s1 CASADI_PREFIX(s1)
static const int CASADI_PREFIX(s2)[6] = {2, 1, 0, 2, 0, 1};
#define s2 CASADI_PREFIX(s2)
static const int CASADI_PREFIX(s3)[5] = {1, 1, 0, 1, 0};
#define s3 CASADI_PREFIX(s3)
/* casadi_impl_ode_jac_xdot */
CASADI_SYMBOL_EXPORT int casadi_impl_ode_jac_xdot(const real_t** arg, real_t** res, int* iw, real_t* w, int mem) {
  real_t *rr, *ss;
  real_t *w0=w+0, *w1=w+6;
  /* #0: @0 = zeros(6x6,6nz) */
  fill(w0, 6, 0.);
  /* #1: @1 = ones(6x1) */
  fill(w1, 6, 1.);
  /* #2: (@0[:6] = @1) */
  for (rr=w0+0, ss=w1; rr!=w0+6; rr+=1) *rr = *ss++;
  /* #3: @1 = @0' */
  trans(w0, s0, w1, s0, iw);
  /* #4: output[0][0] = @1 */
  copy(w1, 6, res[0]);
  return 0;
}

CASADI_SYMBOL_EXPORT void casadi_impl_ode_jac_xdot_incref(void) {
}

CASADI_SYMBOL_EXPORT void casadi_impl_ode_jac_xdot_decref(void) {
}

CASADI_SYMBOL_EXPORT int casadi_impl_ode_jac_xdot_n_in(void) { return 4;}

CASADI_SYMBOL_EXPORT int casadi_impl_ode_jac_xdot_n_out(void) { return 1;}

CASADI_SYMBOL_EXPORT const char* casadi_impl_ode_jac_xdot_name_in(int i){
  switch (i) {
    case 0: return "i0";
    case 1: return "i1";
    case 2: return "i2";
    case 3: return "i3";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const char* casadi_impl_ode_jac_xdot_name_out(int i){
  switch (i) {
    case 0: return "o0";
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const int* casadi_impl_ode_jac_xdot_sparsity_in(int i) {
  switch (i) {
    case 0: return s1;
    case 1: return s1;
    case 2: return s2;
    case 3: return s3;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT const int* casadi_impl_ode_jac_xdot_sparsity_out(int i) {
  switch (i) {
    case 0: return s0;
    default: return 0;
  }
}

CASADI_SYMBOL_EXPORT int casadi_impl_ode_jac_xdot_work(int *sz_arg, int* sz_res, int *sz_iw, int *sz_w) {
  if (sz_arg) *sz_arg = 6;
  if (sz_res) *sz_res = 2;
  if (sz_iw) *sz_iw = 7;
  if (sz_w) *sz_w = 12;
  return 0;
}


#ifdef __cplusplus
} /* extern "C" */
#endif
