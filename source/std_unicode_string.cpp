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
#include <std_unicode_string.hpp>
#include <std_string_convert.hpp>
#include <algorithm>
#include <sstream>
//-----------------------------------------------------------------------------------------------//
using namespace std;
//-----------------------------------------------------------------------------------------------//
shared_ptr<unicode_string>  unicode_string::clone( )
{
   return make_shared<unicode_string>( *this );
}
//-----------------------------------------------------------------------------------------------//
shared_ptr<unicode_string>  unicode_string::resize_clone( size_t const offset )
{
   return resize_string( offset ).clone( );
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::copy( unicode_string const & buffer )
{
   assign( buffer.begin( ), buffer.end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::copy( shared_ptr<unicode_string> const & buffer )
{
   assign( buffer->begin( ), buffer->end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::copy( basic_string<value_type> const & buffer )
{
   assign( buffer.begin( ), buffer.end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::copy( shared_ptr<basic_string<value_type>> const & buffer )
{
   assign( buffer->begin( ), buffer->end( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::uppercase( )
{
   auto old_buffer = unicode_string( *this );
   /**/
   transform( old_buffer.begin( ), old_buffer.end( ), begin( ), [ & ] ( value_type const & c )
   {
      return value_type( ::towupper( c ) );
   } );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::lowercase( )
{
   auto old_buffer = unicode_string( *this );
   /**/
   transform( old_buffer.begin( ), old_buffer.end( ), begin( ), [ & ] ( value_type const & c )
   {
      return value_type( ::towlower( c ) );
   } );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::resize_string( size_t const length )
{
   resize( length );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::resize_string( unicode_string const & buffer )
{
   resize( buffer.length( ) );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
shared_ptr<vector<unicode_string>>  unicode_string::to_vector( )
{
   auto out = vector<unicode_string>{};
   auto stream = wstringstream( *this );
   auto buffer = unicode_string( );
   /**/
   while( getline( stream, buffer ) )
   {
      out.push_back( buffer );
   }
   return make_shared<vector<unicode_string>>( out );
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::ltrim( )
{
   auto buffer = unicode_string( *this );
   /**/
   for( auto c = buffer.begin( ); c != buffer.end( ); c++ )
   {
      if( !::isspace( *c ) )
      {
         assign( c, buffer.end( ) );
         return *this;
      }
   }
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::rtrim( )
{
   auto buffer = unicode_string( *this );
   /**/
   for( auto c = buffer.end( ) - 1; c != buffer.begin( ); c-- )
   {
      if( !::isspace( *c ) )
      {
         assign( buffer.begin( ), c + 1 );
         return *this;
      }
   }
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string &  unicode_string::alltrim( )
{
   ltrim( );
   rtrim( );
   return *this;
}
//-----------------------------------------------------------------------------------------------//
shared_ptr<basic_string<char>>  unicode_string::to_ansi( ) const
{
   return string_convert::widestring_to_ansistring( *this ).clone( );
}
//-----------------------------------------------------------------------------------------------//
const unsigned  unicode_string::to_uint( )
{
   return unsigned( _wtoi( *this ) );
}
//-----------------------------------------------------------------------------------------------//
const int  unicode_string::to_int( )
{
   return _wtoi( *this );
}
//-----------------------------------------------------------------------------------------------//
const long  unicode_string::to_long( )
{
   return _wtol( *this );
}
//-----------------------------------------------------------------------------------------------//
const unsigned long  unicode_string::to_ulong( )
{
   return unsigned long( _wtoll( *this ) );
}
//-----------------------------------------------------------------------------------------------//
const double  unicode_string::to_double( )
{
   return _wtof( *this );
}
//-----------------------------------------------------------------------------------------------//
const float  unicode_string::to_float( )
{
   return float( _wtof( *this ) );
}
//-----------------------------------------------------------------------------------------------//
unicode_string & unicode_string::reference( )
{
   return *this;
}
//-----------------------------------------------------------------------------------------------//
unicode_string const * unicode_string::address( ) const
{
   return this;
}
//-----------------------------------------------------------------------------------------------//

