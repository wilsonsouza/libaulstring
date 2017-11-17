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
#include <string>
#include <memory>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace string_convert
   {
      class widestring_to_ansistring : public basic_string<char>
      {
      public:
         using pointer = shared_ptr<widestring_to_ansistring>;
         using pointer_const = pointer const;
         using type_entry = wchar_t;
         using basic_string_ansi_pointer = shared_ptr<basic_string<value_type>>;
      public:
         widestring_to_ansistring( ) = default;
         explicit widestring_to_ansistring( basic_string<type_entry> const & wstr );
         __inline widestring_to_ansistring::basic_string_ansi_pointer __stdcall clone( )
         {
            return make_shared<basic_string<value_type>>( *this );
         }
      };
      //-----------------------------------------------------------------------------------------------//
      class byte_to_widestring : public basic_string<wchar_t>
      {
      public:
         using pointer = shared_ptr<byte_to_widestring>;
         using pointer_const = pointer const;
         using type_entry = unsigned char;
         using basic_string_wide_pointer = shared_ptr<basic_string<byte_to_widestring::value_type>>;
      public:
         byte_to_widestring( ) = default;
         explicit byte_to_widestring( basic_string<type_entry> const & uchar );
         __inline byte_to_widestring::basic_string_wide_pointer __stdcall clone( )
         {
            return make_shared < basic_string<value_type>>( *this );
         }
      };
      //-----------------------------------------------------------------------------------------------//
      class widestring_to_byte : public basic_string<unsigned char>
      {
      public:
         using pointer = shared_ptr<widestring_to_byte>;
         using pointer_const = pointer const;
         using type_entry = wchar_t;
         using basic_string_uchar_pointer = shared_ptr<basic_string<value_type>>;
      public:
         widestring_to_byte( ) = default;
         explicit widestring_to_byte( basic_string<type_entry> const & wchar );
         __inline widestring_to_byte::basic_string_uchar_pointer __stdcall clone( )
         {
            return make_shared<basic_string<value_type>>( *this );
         }
      };
      //-----------------------------------------------------------------------------------------------//
      class ansistring_to_widestring : public basic_string<wchar_t>
      {
      public:
         using pointer = shared_ptr<ansistring_to_widestring>;
         using pointer_const = pointer const;
         using type_entry = char;
         using basic_string_wide_pointer = shared_ptr<basic_string<value_type>>;
      public:
         ansistring_to_widestring( ) = default;
         explicit ansistring_to_widestring( basic_string<type_entry> const & ch );
         __inline ansistring_to_widestring::basic_string_wide_pointer __stdcall clone( )
         {
            return make_shared<basic_string<value_type>>( *this );
         }
      };
   }
};

