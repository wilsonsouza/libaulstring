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
#include <std_string_convert.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   class ansi_string : public basic_string<char>
   {
   public:
      using pointer = shared_ptr<ansi_string>;
      using pointer_const = pointer const;
      using basic_string_ansi = basic_string<value_type>;
      using basic_string_ansi_pointer = shared_ptr<basic_string<value_type>>;
      using basic_string_wide = basic_string<wchar_t>;
      using basic_string_wide_pointer = shared_ptr<basic_string_wide>;
   public:
      ansi_string( ) = default;
      ansi_string( const_pointer buffer ) : basic_string<value_type>( buffer )
      {
      }
      ansi_string( basic_string<value_type> const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      ansi_string( ansi_string const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      ansi_string( shared_ptr<ansi_string> const & buffer ) :
         basic_string<value_type>( buffer->data( ) )
      {
      }
      ansi_string( shared_ptr<basic_string<value_type>> const & buffer ) :
         basic_string<value_type>( buffer->data( ) )
      {
      }
      ansi_string( _bstr_t const & buffer ) : basic_string<value_type>( buffer )
      {
      }
      ansi_string( basic_string<wchar_t> const & buffer ) :
         basic_string<value_type>( string_convert::widestring_to_ansistring( buffer ) )
      {
      }
      ansi_string( basic_string_wide_pointer const & buffer ) :
         basic_string<value_type>( string_convert::widestring_to_ansistring( buffer->data( ) ) )
      {
      }
      ansi_string( const wchar_t * buffer ) :
         basic_string<value_type>( string_convert::widestring_to_ansistring( buffer ) )
      {
      }
      ansi_string( basic_string<value_type>::const_iterator & itb,
                   basic_string<value_type>::const_iterator const & ite ) :
         basic_string<value_type>( itb, ite )
      {
      }
      /**/
      ansi_string::pointer clone( );
      ansi_string::pointer resize_clone( size_t const offset );
      /**/
      ansi_string &  copy( ansi_string const & buffer );
      ansi_string &  copy( ansi_string::pointer const & buffer );
      ansi_string &  copy( basic_string<value_type> const & buffer );
      ansi_string &  copy( basic_string_ansi_pointer const & buffer );
      /**/
      ansi_string &  uppercase( );
      ansi_string &  lowercase( );
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
      __inline operator ansi_string( )
      {
         return *this;
      }
      /**/
      ansi_string &  resize_string( size_t const length );
      ansi_string &  resize_string( ansi_string const & buffer );
      /**/
      shared_ptr<vector<ansi_string>>  to_vector( );
      /**/
      ansi_string &  ltrim( );
      ansi_string &  rtrim( );
      ansi_string &  alltrim( );
      /**/
      ansi_string::basic_string_wide_pointer to_unicode( ) const;
      /**/
      const unsigned  to_uint( );
      const int  to_int( );
      const long  to_long( );
      const unsigned long  to_ulong( );
      const double  to_double( );
      const float  to_float( );
      /**/
      ansi_string & reference( );
      ansi_string const * address( ) const;
      /**/
      __inline static ansi_string & __cdecl format( ansi_string & buffer,
                                                    ansi_string::const_pointer fmt,
                                                    ... )
      {
         va_list args;
         va_start( args, fmt );
         /**/
         vsnprintf_s( buffer, buffer.length( ), _TRUNCATE, fmt, args );
         va_end( args );
         return buffer;
      }
      /**/
      __inline static pointer alloc( std::size_t const offset = 0 )
      {
         auto out = ansi_string( ).clone( );
         /**/
         if( offset > 0 )
         {
            out->resize_string( offset );
         }
         return out;
      }
      /**/
      __inline static pointer copy_alloc( ansi_string const & buffer )
      {
         return ansi_string( buffer ).clone( );
      }
   };
   //-----------------------------------------------------------------------------------------------//
   __inline static shared_ptr<std::ansi_string> __cdecl format( size_t const offset,
                                                                ansi_string::const_pointer fmt,
                                                                ... )
   {
      va_list args;
      va_start( args, fmt );
      auto buffer = ansi_string( ).resize_string( offset );
      /**/
      vsnprintf_s( buffer, buffer.length( ), _TRUNCATE, fmt, args );
      va_end( args );
      return buffer.clone( );
   }
   //-----------------------------------------------------------------------------------------------//
   using T = string_convert::ansistring_to_widestring;
}
//-----------------------------------------------------------------------------------------------//
