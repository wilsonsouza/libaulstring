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
#include <std_ansi_string.hpp>
#include <std_string_convert.hpp>
#include <algorithm>
#include <sstream>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
ansi_string::pointer ansi_string::clone( )
{
   return make_shared<ansi_string>( *this );
}
//-----------------------------------------------------------------------------------------------//
ansi_string::pointer ansi_string::resize_clone( size_t const offset )
{
   return resize_string( offset ).clone( );
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::copy( ansi_string const & buffer )
{
   assign( buffer.begin( ), buffer.end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::copy( ansi_string::pointer const & buffer )
{
   assign( buffer->begin( ), buffer->end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::copy( basic_string<value_type> const & buffer )
{
   assign( buffer.begin( ), buffer.end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::copy( ansi_string::basic_string_ansi_pointer const & buffer )
{
   assign( buffer->begin( ), buffer->end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::uppercase( )
{
   auto old_buffer = ansi_string( *this );
   /**/
   transform( old_buffer.begin( ), old_buffer.end( ), back_inserter( *this ), [ & ] ( value_type const & c )
   {
      return value_type( ::towupper( c ) );
   } );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::lowercase( )
{
   auto old_buffer = ansi_string( *this );
   /**/
   transform( old_buffer.begin( ), old_buffer.end( ), back_inserter( *this ), [ & ] ( value_type const & c )
   {
      return value_type( ::towlower( c ) );
   } );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::resize_string( size_t const length )
{
   resize( length );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::resize_string( ansi_string const & buffer )
{
   resize( buffer.length( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
shared_ptr<vector<ansi_string>>  ansi_string::to_vector( )
{
   auto out = vector<ansi_string>{ };
   auto stream = stringstream( *this );
   auto buffer = ansi_string( );
   /**/
   while( getline( stream, buffer ) )
   {
      out.push_back( buffer );
   }
   return make_shared<vector<ansi_string>>( out );
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::ltrim( )
{
   auto buffer = ansi_string( *this );
   /**/
   for( auto c = buffer.begin( ); c != buffer.end( ); c++ )
   {
      if( *c != 0x20 )
      {
         assign( c, buffer.end( ) );
         return *this;
      }
   }
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::rtrim( )
{
   auto buffer = ansi_string( *this );
   /**/
   for( auto c = buffer.end( ) - 1; c != buffer.begin( ); c-- )
   {
      if( *c != 0x20 )
      {
         assign( buffer.begin( ), c );
         return *this;
      }
   }
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string &  ansi_string::alltrim( )
{
   ltrim( );
   rtrim( );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string::basic_string_wide_pointer ansi_string::to_unicode( ) const
{
   return string_convert::ansistring_to_widestring( *this ).clone( );
}
//-----------------------------------------------------------------------------------------------//
const unsigned  ansi_string::to_uint( )
{
   return unsigned( atoi( *this ) );
}
//-----------------------------------------------------------------------------------------------//
const int  ansi_string::to_int( )
{
   return atoi( *this );
}
//-----------------------------------------------------------------------------------------------//
const long  ansi_string::to_long( )
{
   return atol( *this );
}
//-----------------------------------------------------------------------------------------------//
const unsigned long  ansi_string::to_ulong( )
{
   return unsigned long( atoll( *this ) );
}
//-----------------------------------------------------------------------------------------------//
const double  ansi_string::to_double( )
{
   return atof( *this );
}
//-----------------------------------------------------------------------------------------------//
const float  ansi_string::to_float( )
{
   return float( atof( *this ) );
}
//-----------------------------------------------------------------------------------------------//
ansi_string & ansi_string::reference( )
{
   return *this;
}
//-----------------------------------------------------------------------------------------------//
ansi_string const * ansi_string::address( ) const
{
   return this;
}
//-----------------------------------------------------------------------------------------------//
