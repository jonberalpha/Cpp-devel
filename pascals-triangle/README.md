# Specification
Pascal's triangle is an arithmetic and geometric figure where each line resembles
the sum of the coefficients of the upper line. The first few lines look like this:

         1
       1   1
     1   2   1
   1   3   3   1

The numbers of the next line can either be calculated by the sum of the upper two 
neighbors, or by using the binomial exponent calculation.

# Quick Guide
In the build directory there is the 'pascal-demo' which is the pascal-program itself.
It can be executed e.g. like './pascal-demo 4' which displays 4 lines of pascals triangle

In the same directory there is also the 'pascal-test' executable which when executed 
runs the following Catch2-tests:
* Given: A negative number
* Given: Neither negative nor positive number
* Given: A large positive number
* Given: Some example line numbers between 1 and 10
