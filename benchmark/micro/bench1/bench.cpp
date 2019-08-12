#include <benchmark/benchmark.h>
#include <vector>

#define type int

static void bm_create_vector(benchmark::State& s){
  for(auto _ : s){
    std::vector<type> v;
    benchmark::DoNotOptimize(v.data());
  }
}


static void bm_vector_reserve(benchmark::State& s){
  for(auto _ : s){
    std::vector<type> v;
    v.reserve(s.range(0));
    benchmark::DoNotOptimize(v.data());
  }
}

static void bm_vector_resize(benchmark::State& s){
  for(auto _ : s){
    std::vector<type> v;
    benchmark::DoNotOptimize(v.data());
    v.resize(s.range(0),1024);
    benchmark::ClobberMemory();
  }
}

static void bm_vector_push_back(benchmark::State& s){
  for(auto _ : s){
    std::vector<type> v;
    benchmark::DoNotOptimize(v.data());
    for(int i=0; i<s.range(0); ++i){
      v.push_back(i);
      benchmark::ClobberMemory();
    }
  }
}


static void bm_vector_reserve_push_back(benchmark::State& s){
  for(auto _ : s){
    std::vector<type> v;
    v.reserve(s.range(0));
    benchmark::DoNotOptimize(v.data());
    for(int i=0; i<s.range(0); ++i){
      v.push_back(i);
      benchmark::ClobberMemory();
    }
  }
}


#define N 18
BENCHMARK(bm_create_vector);
BENCHMARK(bm_vector_reserve)->Range(2,8<<N);
BENCHMARK(bm_vector_resize)->Range(2,8<<N);
BENCHMARK(bm_vector_push_back)->Range(2,8<<N);
BENCHMARK(bm_vector_reserve_push_back)->Range(2,8<<N);



BENCHMARK_MAIN();
