// std_aulstrig_teste.cpp : Defines the entry point for the console application.
//
#include <std_aulstring.hpp>
#include <std_convert_string.hpp>
#include <iostream>
#include <vector>
//
namespace teste
{
   template <typename kind_t = wchar_t>
   void to_multiple_byte(const std::aul::string<kind_t> & value)
   {
      std::cout << std::convert::to_multiple_byte<kind_t>(value) << std::endl;
   }
   template <typename kind_t = char>
   void to_wide(const std::basic_string<kind_t> & value)
   {
      std::wcout << std::convert::to_wide<kind_t>(value) << std::endl;
   }
   void do_trim()
   {
      auto value = std::aul::string<wchar_t>{}.resize(0x64);
      //
      std::fill(value.begin(), value.end(), 0x20);
      value.insert(0x10, L"wilson.souza");
      //
      std::wcout << "real offset " << value.size() << std::endl;
      std::wcout << "left trim " << value.ltrim();
      std::wcout << " offset " << value.size() << std::endl;
      std::wcout << "right trim " << value.rtrim();
      std::wcout << " offset " << value.size() << std::endl;
      //
      value.resize(0x64);
      std::fill(value.begin() + 0xc, value.end(), 0x20);
      //
      std::wcout << "resizable offset " << value.size() << std::endl;
      std::wcout << "alltrim " << value.all_trim();
      std::wcout << " offset " << value.size() << std::endl;
   }
   void do_value()
   {
      auto value = std::aul::string<wchar_t>{ "2018.08" };
      //
      std::wcout << "string value " << value << std::endl;
      std::wcout << "long value " << value.to_value<long>() << std::endl;
      std::wcout << "double value " << value.to_value<double>() << std::endl;
      std::wcout << "float value " << value.to_value<float>() << std::endl;
   }
   void do_formatted()
   {
      auto value = std::aul::string<wchar_t>{}.format( L"Lib %s V %f", L"AULString", 1.0f);
      std::wcout << value << std::endl;
   }
}
int main()
{
   //teste std::convert
   //convert_from_wide_to_multiple_byte
   teste::to_multiple_byte<wchar_t>(std::aul::string<wchar_t>{ "wide_to_multiple:wilson.souza" });
   //convert_from_multiple_byte_to_wide
   teste::to_wide<char>(std::basic_string<char>{"multiple_to_wide:wilson.souza"});
   //trim functions
   teste::do_trim();
   //value convert
   teste::do_value();
   //formatted value
   teste::do_formatted();
   return 0;
}

