﻿// xll_poly.cpp - Various polynomials
#include "../GR5260/fms_poly.h"
#include "../xll12/xll/xll.h"

using namespace xll;

AddIn xai_fms_poly_Bell(
    Function(XLL_DOUBLE, L"?xll_fms_poly_Bell", L"POLY.BELL")
    .Arg(XLL_FP, L"kappa", L"is an array of cumulants.")
    .FunctionHelp(L"Compute Bell polynomials.")
    .Category(L"GR5260")
    .Documentation(
LR"xyzzyx(
Bell polynomials satisfy the recurrence relations <math>B<subscript>0</subscript> = 1</math> and
<math>B<subscript>n+1</subscript>(&#954;<subscript>1</subscript>,...,&#954;<subscript>n+1</subscript>)
= ...</math>
)xyzzyx"
    )
);
double WINAPI xll_fms_poly_Bell(const _FP12* pkappa)
{
#pragma XLLEXPORT
    double result = std::numeric_limits<double>::quiet_NaN();

    try {
        result = fms::poly::Bell(size(*pkappa), pkappa->array);
    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());
    }

    return result;
}

AddIn xai_fms_poly_Hermite(
    Function(XLL_DOUBLE, L"?xll_fms_poly_Hermite", L"POLY.HERMITE")
    .Arg(XLL_WORD, L"n", L"is an array of cumulants.")
    .Arg(XLL_DOUBLE, L"x", L"is the value at which to compute the polynomial.")
    .FunctionHelp(L"Compute Hermite polynomials.")
    .Category(L"GR5260")
    .Documentation(
        LR"xyzzyx(
Hermite polynomials satisfy the recurrence relations H<subscript>0</subscript>(x) = 1, 
H<subscript>1</subscript>(x) = x, and 
H<subscript>n + 1</subscript>(x) 
  = x H<subscript>n</subscript>(x) - n H<subscript>n - 1</subscript>(x).
)xyzzyx"
)
); 
double WINAPI xll_fms_poly_Hermite(WORD n, double x)
{
#pragma XLLEXPORT
    double result = std::numeric_limits<double>::quiet_NaN();

    try {
        result = fms::poly::Hermite(n, x);
    }
    catch (const std::exception& ex) {
        XLL_ERROR(ex.what());
    }

    return result;
}

//??? Implement an add-in called NJR.CDF that calls fms::prob::njr_cdf