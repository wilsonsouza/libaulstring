/*
*  std string convert classes
*
*  Created by wilson.souza
*  Default language used c++11
*
*  Copyright (c) 2016, 2017, 2018 WR DevInfo
*
*  Created jun 12 2016
*  Last updated jul 25 2018
*  Last updated agu 04 2018
*  Changed file name std_string_convert.hpp to std_convert_string.hpp
*  Now only supported wide string (UNICODE)
*  Version 0.2-beta
*/
#pragma once
#include <sstream>
#include <ostream>
#include <istream>
#include <cstdarg>
#include <memory>
#include <std_convert_string.hpp>
//-----------------------------------------------------------------------------------------------//
namespace std
{
   namespace aul
   {
      template <typename type_t = enable_if<is_same<type_t, wchar_t>::value, type_t>::type>
      class string : public basic_string<type_t>
      {
      public:
         using pointer = shared_ptr<string>;

      public:
         //-----------------------------------------------------------------------------------------------//
         string() : basic_string<type_t>{}
         {
         }
         //-----------------------------------------------------------------------------------------------//
         explicit string(const type_t & ch_t) : basic_string<type_t>{}
         {
            push_back(ch_t);
         }
         //-----------------------------------------------------------------------------------------------//
         explicit string(const basic_string<type_t> & value) : basic_string<type_t>{ value }
         {
         }
         //-----------------------------------------------------------------------------------------------//
         explicit string(const type_t * value) : basic_string<type_t>{ value }
         {
         }
         //-----------------------------------------------------------------------------------------------//
         explicit string(const basic_string<char> & value) : basic_string<type_t>{}
         {
            basic_string<type_t>::assign(convert::to_wide<char>(value));
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & resize(const size_t size)
         {
            basic_string<type_t>::resize(size);
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & upper()
         {
            auto temp = string{ *this };
            //clear current buffer
            clear();
            //convert 
            std::transform(temp.begin(), temp.end(), std::back_inserter(*this), [](const type_t & c)
            {
               return towupper(c);
            });
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & lower()
         {
            auto temp = string{ *this };
            //clear current buffer
            clear();
            //convert
            std::transform(temp.begin(), temp.end(), std::back_inserter(*this), [](const type_t & c)
            {
               return towlower(c);
            });
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator type_t *()
         {
            return const_cast<type_t *>(this->data());
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator const type_t *()
         {
            return this->data();
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator const char *()
         {
            return convert::to_multiple_byte<wchar_t>(*this).data();
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator basic_string<type_t>()
         {
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator basic_string<char>()
         {
            return convert::to_multiple_byte<wchar_t>(*this);
         }
         //-----------------------------------------------------------------------------------------------//
         __inline operator string()
         {
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         template <class class_t> class_t trim(class_t first, class_t last)
         {
            auto locate_t = std::locale{};
            //
            for (; first != last; ++first)
            {
               if (!std::use_facet<std::ctype<type_t>>(locate_t).is(std::ctype_base::space, *first))
               {
                  break;
               }
            }
            return first;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & ltrim()
         {
            basic_string<type_t>::assign(trim(begin(*this), end(*this)), end(*this));
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & rtrim()
         {
            basic_string<type_t>::assign(this->begin(), trim(this->rbegin(), this->rend()).base());
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & all_trim()
         {
            return ltrim().rtrim();
         }
         //-----------------------------------------------------------------------------------------------//
         template <typename value_out> value_out to_value()
         {
            auto temp = basic_stringstream<type_t>{ *this };
            value_out value;
            temp >> value;
            return value;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline string & format(const type_t * fmt, ...)
         {
            va_list args;
            va_start(args, fmt);
            /**/
            this->resize(string{ fmt }.size() << 6);
            _vsnwprintf_s(*this, this->size(), _TRUNCATE, fmt, args);
            va_end(args);
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         __inline pointer to_pointer()
         {
            return make_shared<string<type_t>>(*this);
         }
         //-----------------------------------------------------------------------------------------------//
      };
   }
}
