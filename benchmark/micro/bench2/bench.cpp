#include <benchmark/benchmark.h>
#include <vector>
#include <immintrin.h>

using namespace std;

static void bm_vector_setup(benchmark::State& s)
{
  for(auto _ : s){
    std::vector<float> v1(s.range(0), s.range(0)),
       v2(s.range(0), s.range(0)+512),
       v3(s.range(0), 0);

    benchmark::DoNotOptimize(v1.data());
    benchmark::DoNotOptimize(v2.data());
    benchmark::DoNotOptimize(v3.data());
    benchmark::ClobberMemory();
  }
}

static void bm_vector_add(benchmark::State& s)
{
  for( auto _ : s){
    std::vector<float> v1(s.range(0), s.range(0)),
       v2(s.range(0), s.range(0)+512),
       v3(s.range(0), 0);

    benchmark::DoNotOptimize(v1.data());
    benchmark::DoNotOptimize(v2.data());
    benchmark::DoNotOptimize(v3.data());
    benchmark::ClobberMemory();

    int i=0;
    for(; i<s.range(0); ++i){
      v3[i] = v1[i] + v2[i];
      benchmark::ClobberMemory();
    }

  }
}

static void bm_simd_vector_add(benchmark::State& s)
{
  for( auto _ : s){
    std::vector<float> v1(s.range(0), s.range(0)),
       v2(s.range(0), s.range(0)+512),
       v3(s.range(0), 0);

    benchmark::DoNotOptimize(v1.data());
    benchmark::DoNotOptimize(v2.data());
    benchmark::DoNotOptimize(v3.data());
    benchmark::ClobberMemory();

    int i=0;

// Enable AVX2 if available
#if defined (__AVX2__)
    for(; i<(s.range(0) & ~0x7); i += 8){
      _mm256_storeu_ps(&v3[i],
          _mm256_add_ps(
            _mm256_loadu_ps(&v1[i]),
            _mm256_loadu_ps(&v2[i])
          )
      );
      benchmark::ClobberMemory();
    }
#endif

// Enable SSE2 if available
#if defined(__SSE2__)
    for(; i<(s.range(0) & ~0x3); i += 4){
      _mm_storeu_ps(&v3[i],
        _mm_add_ps(
          _mm_loadu_ps(&v1[i]),
          _mm_loadu_ps(&v2[i])
        )
      );
      benchmark::ClobberMemory();
    }
#endif

    // Serial loop
    for(; i<s.range(0); ++i){
      v3[i] = v1[i] + v2[i];
      benchmark::ClobberMemory();
    }

  }
}



#define RANGE RangeMultiplier(2)->Range(2, 8<< 10)

BENCHMARK(bm_vector_setup)->RANGE;
BENCHMARK(bm_vector_add)->RANGE;
BENCHMARK(bm_simd_vector_add)->RANGE;
BENCHMARK_MAIN();
