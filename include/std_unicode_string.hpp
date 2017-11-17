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
#pragma once
#include <memory>
#include <vector>
#include <comutil.h>
#include <varargs.h>
#include <cwchar>
#include <std_string_convert.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class unicode_string : public basic_string<wchar_t>
   {
   public:
      using pointer = shared_ptr<unicode_string>;
      using pointer_const = pointer const;
      using basic_string_ansi = basic_string<char>;
      using basic_string_ansi_pointer = shared_ptr<basic_string_ansi>;
      using basic_string_wide = basic_string<value_type>;
      using basic_string_wide_pointer = shared_ptr<basic_string_wide>;
   public:
      unicode_string( ) = default;
      unicode_string( value_type & buffer ) :basic_string<value_type>( )
      {
         push_back( buffer );
      }
      unicode_string( const_pointer buffer ) : basic_string<value_type>( buffer )
      {
      }
      unicode_string( basic_string<value_type> const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      unicode_string( unicode_string const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      unicode_string( shared_ptr<unicode_string> const & buffer ) :
         basic_string<value_type>( buffer->data( ) )
      {
      }
      unicode_string( shared_ptr<basic_string<value_type>> const & buffer ) :
         basic_string<value_type>( buffer->data( ) )
      {
      }
      unicode_string( _bstr_t const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      unicode_string( basic_string<char> const & buffer ) :
         basic_string<value_type>( string_convert::ansistring_to_widestring( buffer ) )
      {
      }
      unicode_string( basic_string_ansi_pointer const & buffer ) :
         basic_string<value_type>( string_convert::ansistring_to_widestring( buffer->data( ) ) )
      {
      }
      unicode_string( const char * buffer ) :
         basic_string<value_type>( string_convert::ansistring_to_widestring( buffer ) )
      {
      }
      unicode_string( basic_string<value_type>::const_iterator & itb,
                      basic_string<value_type>::const_iterator & ite ) :
         basic_string<value_type>( itb, ite )
      {
      }
      unicode_string( basic_string<unsigned char> const & uchar ) :
         basic_string<value_type>( string_convert::byte_to_widestring( uchar ) )
      {
      }
      /**/
      unicode_string::pointer clone( );
      unicode_string::pointer resize_clone( size_t const offset );
      /**/
      unicode_string &  copy( unicode_string const & buffer );
      unicode_string &  copy( unicode_string::pointer const & buffer );
      unicode_string &  copy( basic_string<value_type> const & buffer );
      unicode_string &  copy( unicode_string::basic_string_wide_pointer const & buffer );
      /**/
      unicode_string &  uppercase( );
      unicode_string &  lowercase( );
      /**/
      __inline operator value_type *( )
      {
         return const_cast< value_type * >( data( ) );
      }
      /**/
      __inline operator const_pointer ( )
      {
         return data( );
      }
      /**/
      __inline operator basic_string<value_type>( )
      {
         return *this;
      }
      /**/
      __inline operator unicode_string( )
      {
         return *this;
      }
      /**/
      unicode_string &  resize_string( size_t const length );
      unicode_string &  resize_string( unicode_string const & buffer );
      /**/
      shared_ptr<vector<unicode_string>>  to_vector( );
      /**/
      unicode_string &  ltrim( );
      unicode_string &  rtrim( );
      unicode_string &  alltrim( );
      /**/
      unicode_string::basic_string_ansi_pointer to_ansi( ) const;
      /**/
      const unsigned  to_uint( );
      const int  to_int( );
      const long  to_long( );
      const unsigned long  to_ulong( );
      const double  to_double( );
      const float  to_float( );
      /**/
      unicode_string & reference( );
      unicode_string const * address( ) const;
      /**/
      __inline static unicode_string & format( unicode_string & buffer,
                                               unicode_string::const_pointer fmt,
                                               ... )
      {
         va_list args;
         va_start( args, fmt );
         /**/
         _vsnwprintf_s( buffer, buffer.length( ), _TRUNCATE, fmt, args );
         va_end( args );
         return buffer;
      }
      /**/
      __inline static pointer alloc( std::size_t const offset = 0 )
      {
         auto out = unicode_string( ).clone( );
         /**/
         if( offset > 0 )
         {
            out->resize_string( offset );
         }
         return out;
      }
      /**/
      __inline static pointer copy_alloc( unicode_string const & buffer )
      {
         return unicode_string( buffer ).clone( );
      }
   };
   //-----------------------------------------------------------------------------------------------//
   __inline static shared_ptr<unicode_string> format( size_t const offset,
                                                      unicode_string::const_pointer fmt,
                                                      ... )
   {
      va_list args;
      va_start( args, fmt );
      auto buffer = unicode_string( ).resize_string( offset );
      /**/
      _vsnwprintf_s( buffer, buffer.length( ), _TRUNCATE, fmt, args );
      va_end( args );
      return buffer.clone( );
   }
}
//-----------------------------------------------------------------------------------------------//
