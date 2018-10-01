/*
*  std string convert classes
*
*  Created by wilson.souza
*  Default language used c++14
*
*  Copyright (c) 2016, 2017, 2018 WR DevInfo
*
*  Created jun 12 2016
*  Last updated jul 25 2018
*  8-7-2018 modified to template class
*  9-30-2018 fix validation to template enable_if
*  Version 0.1-beta
*/
#pragma once
#include <string>
#include <algorithm>
#include <uchar.h>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace convert
   {
      template <typename from, typename enable_if<is_same<from, wchar_t>::value, from>::type = 0>
      struct to_multiple_byte : public basic_string<char>
      {
         to_multiple_byte() = delete;
         //-----------------------------------------------------------------------------------------------//
         explicit to_multiple_byte(const basic_string<from> & value)
         {
            transform(value.begin(), value.end(), back_inserter(*this), [&](from const & ch)
            {
               int i = 0;
               value_type c;
               //
               wctomb_s(&i, &c, 1, ch);
               return c;
            });
         }
         //-----------------------------------------------------------------------------------------------//
         operator basic_string<value_type>()
         {
            return basic_string<value_type>(*this);
         }
      };
      //-----------------------------------------------------------------------------------------------//
      template <typename from, typename enable_if<is_same<from, char>::value, from>::type = 0>
      struct to_wide : public basic_string<wchar_t>
      {
         to_wide() = delete;
         //-----------------------------------------------------------------------------------------------//
         explicit to_wide(const basic_string<from> & value)
         {
            transform(value.begin(), value.end(), back_inserter(*this), [&](from const & ch)
            {
               value_type c;
               mbtowc(&c, &ch, 1);
               return c;
            });
         }
         //-----------------------------------------------------------------------------------------------//
         operator basic_string<value_type>()
         {
            return basic_string<value_type>(*this);
         }
      };
   }
}
