#include <Rcpp.h>
#include <xoshiro.h>
#include <dqrng_distribution.h>
#ifdef _OPENMP
#include <omp.h>
#endif

template<typename T, typename RNGengine = dqrng::xoshiro256plus>
T numeric_unif(const T& min, const T& max) {
  // Generator created per thread that persists
  static thread_local RNGengine eng;

  // Create a new distribution each sample (not-expensive)
  dqrng::uniform_distribution U_dist(min, max);

  // Sample from distribution
  return U_dist(eng);
}

//' Max CPU cores
//'
//' Determine the number of cores available
//'
//' @return
//' Integer containing the maximum number of CPU cores.
//'
//' If 0, then parallelization is not supported and a silent failure occurs
//'
//' @export
//' @examples
//'
//' # Retrieve the number of total cores on the machine.
//' max_cores()
// [[Rcpp::export]]
int max_cores() {
  int n_cores = 0;
#ifdef _OPENMP
  n_cores = omp_get_max_threads();
#endif

  return n_cores;
}

//' Static Thread Local Parallelized Uniform RNG sampler
//'
//' Samples from the Uniform distribution in parallel through using
//' core specific RNG engines that are kept active throughout the calculation.
//'
//' @param n    Number of values to generate.
//' @param min  Bottom value to generate values from in a continuous uniform.
//' @param max  Top range to generate values from in a continuous uniform.
//'
//' @return
//' A `numeric` vector containing the output.
//'
//' @export
//' @examples
//' # Retrieves 100 observations from a random uniform distribution.
//' x = draw_numeric_unif(100)
// [[Rcpp::export]]
std::vector<double> draw_numeric_unif(unsigned int n,
                                      double min = 0.0, double max = 1.0) {

  int n_cores = max_cores();
  std::vector<double> sample_values(n);

#pragma omp parallel for num_threads(n_cores)
  for(unsigned int i = 0; i < n; ++i) {
    sample_values[i] = numeric_unif(min, max);
  }

  return sample_values;
}
