#pragma once
#ifndef PARALLEL_MERGE_SORT_HH
#define PARALLEL_MERGE_SORT_HH

#include <cstddef>       //size_t
#include <thread>        //thread
#include "merge_sort.hh" //merge_sort

template < class T >
void parallel_merge_sort( T* a, size_t left, size_t right,
  size_t threads_count )
{
  if ( threads_count / 2 )
  {
    if ( left < right )
    {
      const size_t CENTER = ( left + right ) / 2;
      std::thread left_part{ &parallel_merge_sort< T >, a, left, CENTER,
        threads_count / 2 };
      parallel_merge_sort( a, CENTER + 1, right, threads_count / 2 );
      left_part.join();
      merge( a, left, right, CENTER );
    }
  }
  else
  {
    merge_sort( a, left, right );
  }
}

#endif
