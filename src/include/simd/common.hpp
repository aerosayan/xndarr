//-//////////////////////////////////////////////////////////////////////////-//
// @file common.hpp
// @info Common SIMD vectorization definitions and operations
// @author Sayan Bhattacharjee
// @date 14-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
#pragma once
#ifndef __XNDARR_SIMD_COMMON_HPP__
#define __XNDARR_SIMD_COMMON_HPP__


//-//////////////////////////////////////////////////////////////////////////-//
// AVX2 vectorization
//-//////////////////////////////////////////////////////////////////////////-//
#if defined(__AVX2__)
  // Indicates if AVX2 is available
  #define XNSIMD_AVX2_AVAILABLE 1

  // Alignment required for SIMD operations
  #ifndef XNSIMD_ALIGNMENT
    #define XNSIMD_ALIGNMENT 32
  #endif // XNSIMD_ALIGNMENT

#endif // __AVX2__


//-//////////////////////////////////////////////////////////////////////////-//
// SSE2 vectorization
//-//////////////////////////////////////////////////////////////////////////-//
#if defined(__SSE2__)
  // Indicates if SSE2 is available
  #define XNSIMD_SSE2_AVAILABLE 1

  // Alignment required for SIMD operations
  #ifndef XNSIMD_ALIGNMENT
    #define XNSIMD_ALIGNMENT 16
  #endif // XNSIMD_ALIGNMENT

#endif // __SSE2__

#endif // __XNDARR_SIMD_COMMON_HPP__
