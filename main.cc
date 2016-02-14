#include <iostream>               //cerr, endl
#include <vector>                 //vector
#include <chrono>                 //high_resolution_clock
#include <cstdlib>                //EXIT_SUCCESS, exit
#include <cstddef>                //size_t
#include "parallel_merge_sort.hh" //parallel_merge_sort
#include "helper_functions.hh"    //print_result
#include "format.hh"              //format

int main( int argc, char** argv )
{
  if ( argc < 4 ) //-V112
  {
    const auto msg = format(
      "%1%: error: too few program arguments\n"
      "Syntax:\n"
      "\t%1% <INPUT_FILE_NAME> <OUTPUT_FILE_NAME> <THREADS_COUNT>", argv[ 0 ] );

    std::cerr << msg << std::endl;

    return EXIT_FAILURE;
  }

  const char* const  INPUT_FILE_NAME = argv[ 1 ];
  const char* const OUTPUT_FILE_NAME = argv[ 2 ];
  const size_t THREADS_COUNT = std::stoull( argv[ 3 ] );

  std::vector< size_t > v;
  fill( INPUT_FILE_NAME, v );

  auto start = std::chrono::high_resolution_clock::now();
  parallel_merge_sort( v.data(), 0, v.size() - 1, THREADS_COUNT );
  auto stop  = std::chrono::high_resolution_clock::now();

  print( OUTPUT_FILE_NAME, v );
  print_result( stop - start, "PARALLEL MERGE SORT", THREADS_COUNT, v.size() );

	return EXIT_SUCCESS;
}
