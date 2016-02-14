#pragma once
#ifndef MERGE_SORT_HH
#define MERGE_SORT_HH

#include <cstddef>  //size_t
#include "merge.hh" //merge

template < class T >
void merge_sort( T* a, size_t left, size_t right )
{
  if ( left < right )
  {
    const size_t CENTER = ( left + right ) / 2;
    merge_sort( a, left, CENTER );
    merge_sort( a, CENTER + 1, right );
    merge( a, left, right, CENTER );
  }
}

#endif
