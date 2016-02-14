#pragma once
#ifndef HELPER_FUNCTIONS_HH
#define HELPER_FUNCTIONS_HH

#include <iostream> //cout, endl
#include <fstream>  //ifstream, ofstream
#include <iomanip>  //setw
#include <string>   //string
#include <cstddef>  //size_t
#include <chrono>   //duration_cast

template < class T >
void print_time( const T& duration )
{
  using namespace std::chrono;

  std::cout
    << "HOS" << std::setw( 10 )
    << duration_cast< hours >( duration ).count()   % 24 << std::endl

    << "MIN" << std::setw( 10 )
    << duration_cast< minutes >( duration ).count() % 60 << std::endl

    << "SEC" << std::setw( 10 )
    << duration_cast< seconds >( duration ).count() % 60 << std::endl

    << "MIL" << std::setw( 10 )
    << duration_cast< milliseconds >( duration ).count() % 1000 << std::endl

    << "MIC" << std::setw( 10 )
    << duration_cast< microseconds >( duration ).count() % 1000 << std::endl

    << "NAN" << std::setw( 10 )
    << duration_cast< nanoseconds >( duration ).count()  % 1000 << std::endl;
}

template < class T >
void print_result( const T& duration,
  const std::string& algorithm, size_t threads, size_t size )
{
  std::cout                     << algorithm << std::endl
    << "THR" << std::setw( 10 ) << threads   << std::endl
    << "SIZ" << std::setw( 10 ) << size      << std::endl;

  print_time( duration );
  std::cout << std::endl;
}

template < class T >
void fill( const char* inputfile, T& v )
{
  std::ifstream in( inputfile );
  typename T::value_type value;

  while ( in >> value )
    v.push_back( value );
}

template < class T >
void print( const char* outputfile, const T& v )
{
  std::ofstream out( outputfile );

  for ( auto value : v )
    out << value << ' ';
  out << std::endl;
}

#endif
