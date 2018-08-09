# libaulstring
Create by wilson.souza (c) 2016, 2017, 2018
Version 0.2-beta
This library was create with full support of c++14.
Has full inherintace of STL template string and wstring class.

classes: namespace std::convert
	to_multiple_byte<typename wchar_t> - return basic_string<char>
	receive basic_string<wchar_t> and out basic_string<char>
	example:
		void main()
		{
			auto buffer = std::aul::string<wchar_t>{ L"wilson.souza" };
			std::cout << std::convert::to_multiple_byte<wchar_t>(buffer) << std::endl;
		}

	to_wide<typename char> - return basic_string<wchar_t>
	receive basic_string<char> and out basic_string<wchar_t>
	example:
		void main()
		{
			auto buffer = std::basic_string<char>{ "wilson.souza" };
			std::cout << std::convert::to_wide<char>(buffer) << std::endl;
		}

	string class std::aul::string only supported by wstring or basic_string<wchar_t> template class. 
	methods list:
		type_t is of kind wchar_t and default type
		string() default
		create an new empty string buffer
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{};
			//
			buffer = L"empty string buffer not more!";
		}

		string(const type_t & ch_t) 
		create an new string buffer with one byte
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{L'A'};
		}

		string(const basic_string<type_t> & value)
		create an new string buffer with an copy of basic_string<type_t> object
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ std::basic_string<wchar_t>{L"wilson.souza"} };
		}

		string(const type_t * value)
		create an new string buffer with wide string parameter
		sample:
		void main()
		{
			auto buffer = string<wchart_t>{ L"wilson.souza" };
		}

		string & resize(const size_t size)
		resize buffer to an new size
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//now resize the current to new size with 0xf bytes
			buffer = buffer.resize( buffer.size() + 0xf ) + L"developer C++";
		}

		string & upper()
		convert the current string buffer of lower case to upper case
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" }.upper();
		}

		string & lower()
		convert the current string buffer of upper case to lower case
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"WILSON.SOUZA" }.lower();
		}

		operator type_t *()
		operator of conversion
		sample:
		void print_string(wchar_t * buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		operator const type_t *()
		operator of conversion
		sample:
		void print_string(const wchar_t * buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		operator basic_string<type_t>()
		operator of conversion
		sample:
		void print_string(std::basic_string<wchar_t> buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		operator const basic_string<type_t>()
		operator of conversion
		sample:
		void print_string(const std::basic_string<wchar_t> buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		operator string()
		operator of conversion
		sample:
		void print_string(std::aul::string buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		operator const string()
		operator of conversion
		sample:
		void print_string(const std::aul::string buffer)
		{
			std::cout << value << std::endl;
		}
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"wilson.souza" };
			//invoke operator of type wchar_t on the class std::aul::string and convert to wchar_t *
			print_string(buffer);
		}

		template <class iterator> iterator trim(iterator first, iterator last)
		used by others methods

		string & ltrim()
		remove all blank space of left 
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"           wilson.souza"}.ltrim();
		}

		string & rtrim()
		remove all blank space of right 
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"           wilson.souza"}.rtrim();
		}
		string & all_trim()
		remove all blank space of left and right 
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"           wilson.souza"}.all_trim();
		}

		template <typename value_out> value_out to_value()
		convert any string buffer to integral value or float point
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>{ L"100" }.to_value();
		}

		static string & format(string & bufer, const type_t * fmt,...)
		format current string buffer like sprintf
		sample:
		void main()
		{
			auto buffer = std::aul::string<wchart_t>::format( std::aul::string<wchar_t>{}, 
			                                                  L"wilson%csouza %s", 
															  L".", 
															  L"C/C++ developer");
		}

