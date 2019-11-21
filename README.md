# Generating Random Numbers in Parallel within C++

<!-- badges: start -->
[![Travis build status](https://travis-ci.com/r-pkg-examples/rcpp-rng-parallel.svg?branch=master)](https://travis-ci.com/r-pkg-examples/rcpp-rng-parallel)
<!-- badges: end -->

The `RcppRNGParallel` _R_ package explores using Random Number Generation (RNG)
streams in parallel with `static thread_local` C++11 feature. The overarching
goal is a reproducible RNG stream with a shared RNG class.

### Usage

To install the package, you must first have a compiler on your system that is
compatible with R. For help on obtaining a compiler consult either
[macOS](http://thecoatlessprofessor.com/programming/r-compiler-tools-for-rcpp-on-os-x/)
or
[Windows](http://thecoatlessprofessor.com/programming/rcpp/install-rtools-for-rcpp/)
guides.

With a compiler in hand, one can then install the package from GitHub by:

```r
# install.packages("devtools")
devtools::install_github("r-pkg-examples/rcpp-rng-parallel")
library("RcppRNGParallel")
```

### Implementation Details

Todo ....

## Author

James Joseph Balamuta

## License

GPL (\>= 2)
