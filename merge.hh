#pragma once
#ifndef MERGE_HH
#define MERGE_HH

#include <cstddef> //size_t
#include <utility> //swap
#include <vector>  //vector
#include <limits>  //numeric_limits

template < class T >
void merge( T* a, size_t left, size_t right, size_t center )
{
  if ( left + 1 == right )
  {
    if ( a[ left ] > a[ right ] )
      std::swap( a[ left ], a[ right ] );
    return;
  }

  const size_t LEFT_PART_SIZE  = center - left   + 1;
  const size_t RIGHT_PART_SIZE = right  - center;

  std::vector< T > left_part ( LEFT_PART_SIZE   + 1 );
  std::vector< T > right_part( RIGHT_PART_SIZE  + 1 );

  std::memcpy( left_part.data(),  a + left,
    LEFT_PART_SIZE * sizeof( T ) );

  std::memcpy( right_part.data(), a + center + 1,
    RIGHT_PART_SIZE * sizeof( T ) );

  left_part[ LEFT_PART_SIZE ] = right_part[ RIGHT_PART_SIZE ] =
    std::numeric_limits< T >::max();

  for ( size_t i = left, l = 0, r = 0; i <= right; ++i )
    a[ i ] = left_part[ l ] < right_part[ r ] ?
    left_part[ l++ ] : right_part[ r++ ];
}

#endif
