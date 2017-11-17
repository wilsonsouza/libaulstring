/*
*  std string convert classes
*
*  Created by wilson.souza
*  Default language used c++11
*
*  Copyright (c) 2016, 2017 WR DevInfo
*
*  Created jun 12 2016
*  Last updated
*  Version 0.1-beta
*/
#include <std_string_convert.hpp>
using namespace std::string_convert;
//-----------------------------------------------------------------------------------------------//
widestring_to_ansistring::widestring_to_ansistring( basic_string<type_entry> const & wstr ) :
   basic_string<value_type>( )
{
   for( auto && s : wstr )
   {
      int i;
      char c;
      //
      wctomb_s( &i, &c, 1, s );
      push_back( c );
   }
}
//-----------------------------------------------------------------------------------------------//
byte_to_widestring::byte_to_widestring( basic_string<type_entry> const & uchar ) :
   basic_string<value_type>( )
{
   for( auto && s : uchar )
   {
      wchar_t c = 0;
      /**/
      mbtowc( &c, ( char * ) &s, 1 );
      push_back( c );
   }
}
//-----------------------------------------------------------------------------------------------//
widestring_to_byte::widestring_to_byte( basic_string<type_entry> const & wchar ) :
   basic_string<value_type>( )
{
   for( auto && s : wchar )
   {
      int i = 0;
      char c;
      //
      wctomb_s( &i, &c, 1, s );
      push_back( c );
   }
}
//-----------------------------------------------------------------------------------------------//
ansistring_to_widestring::ansistring_to_widestring( basic_string<type_entry> const & ch ) :
   basic_string<value_type>( )
{
   for( auto && s : ch )
   {
      wchar_t c;
      /**/
      mbtowc( &c, &s, 1 );
      push_back( c );
   }
}
//-----------------------------------------------------------------------------------------------//
