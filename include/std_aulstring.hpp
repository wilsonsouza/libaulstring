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
*  9-30-2018 fix validation to template enable_if
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
      template <typename type_t, 
         typename enable_if<is_same<typename type_t, wchar_t>::value, typename type_t>::type = 0>
      class string : public basic_string<type_t>
      {
      public:
         using pointer = shared_ptr<string>;

      public:
         //-----------------------------------------------------------------------------------------------//
         string() : basic_string< type_t >{}
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
         string & resize(const size_t size)
         {
            basic_string<type_t>::resize(size);
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         string & upper()
         {
            auto temp = string{ *this };
            //clear current buffer
            basic_string<type_t>::clear();
            //convert 
            std::transform(temp.begin(), temp.end(), std::back_inserter(*this), [](const type_t & c)
            {
               return towupper(c);
            });
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         string & lower()
         {
            auto temp = string{ *this };
            //clear current buffer
            basic_string<type_t>::clear();
            //convert
            std::transform(temp.begin(), temp.end(), std::back_inserter(*this), [](const type_t & c)
            {
               return towlower(c);
            });
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         operator type_t *()
         {
            return const_cast<type_t *>(this->data());
         }
         //-----------------------------------------------------------------------------------------------//
         operator const type_t *()
         {
            return this->data();
         }
         //-----------------------------------------------------------------------------------------------//
         operator const char *()
         {
            return convert::to_multiple_byte<wchar_t>(*this).data();
         }
         //-----------------------------------------------------------------------------------------------//
         operator basic_string<type_t>()
         {
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         operator basic_string<char>()
         {
            return convert::to_multiple_byte<wchar_t>(*this);
         }
         //-----------------------------------------------------------------------------------------------//
         operator string()
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
         string & ltrim()
         {
            basic_string<type_t>::assign(trim(begin(*this), end(*this)), end(*this));
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         string & rtrim()
         {
            basic_string<type_t>::assign(this->begin(), trim(this->rbegin(), this->rend()).base());
            return *this;
         }
         //-----------------------------------------------------------------------------------------------//
         string & all_trim()
         {
            return ltrim().rtrim();
         }
         //-----------------------------------------------------------------------------------------------//
         template <typename value_out> 
         typename enable_if<is_arithmetic<typename value_out>::value || 
            is_floating_point<typename value_out>::value, typename value_out>::type to_value()
         {
            auto temp = basic_stringstream<type_t>{ *this };
            value_out value;
            temp >> value;
            return value;
         }
         //-----------------------------------------------------------------------------------------------//
         string & format(const type_t * fmt, ...)
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
         pointer to_pointer()
         {
            return pointer{ new string<type_t>{*this} };
         }
         //-----------------------------------------------------------------------------------------------//
         template<typename param_t> pointer & copy_alloc(typename param_t && value)
         {
            assign(forward<param_t>(value));
            return to_pointer();
         }
      };
   }
   /* use this */
   using unicodestring = std::aul::string<wchar_t>;
}
