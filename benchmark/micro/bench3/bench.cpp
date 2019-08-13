#include <benchmark/benchmark.h>
#include <vector>
#include <immintrin.h>
using namespace std;

static void bm_vector_fill(benchmark::State& s)
{
  for(auto _ : s){
    float r = s.range(0);
    int n = s.range(0) + 313;
    vector<float> v(n,0);
    benchmark::DoNotOptimize(v.data());
    fill(v.begin(),v.end(),r);
    benchmark::ClobberMemory();
  }
}

static void bm_simd_vector_fill(benchmark::State& s)
{

  for(auto _ : s){
    float r = s.range(0);
    int n = s.range(0) + 313;
    vector<float> v(n,0);
    benchmark::DoNotOptimize(v.data());

    int i=0;

#if defined(__AVX2__)
    __m256 data256 = _mm256_set1_ps(r);
    for(; i< (n & ~0x7) ; i += 8) {
      _mm256_store_ps(&v[i],data256);
      benchmark::ClobberMemory();
    }
#endif

#if defined(__SSE2__)
    __m128 data128 = _mm_set1_ps(r);
    for(; i<(n & ~0x3); i += 4){
      _mm_store_ps(&v[i],data128);
      benchmark::ClobberMemory();
    }
#endif

    fill(v.begin()+i, v.end(), r);
    benchmark::ClobberMemory();
  }
}

#define RANGE RangeMultiplier(2)->Range(8<<8,8<<16);
BENCHMARK(bm_vector_fill)->RANGE;
BENCHMARK(bm_simd_vector_fill)->RANGE;
BENCHMARK_MAIN();
