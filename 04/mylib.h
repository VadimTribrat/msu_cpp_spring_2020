#include <iostream>
#include <string>
#include <sstream>

enum class Error
{
	noError,
	CorruptedArchive
};

class Serializer
{
	std::stringstream& out;
	static constexpr char separator = ' ';
	Error process(bool val);
	Error process(int val);
	template <class T, class... ArgT>
	Error process(T&& t, ArgT&&... args);
	public:
	Serializer(std::stringstream& out);
	template<class... ArgsT>
	Error operator()(ArgsT&&... args);
	template<class T>
	Error save(T & object);
};

class Deserializer
{
	std::stringstream & in;
	static constexpr char separator = ' ';
	public:
	Deserializer(std::stringstream &);
	Error process(bool &);
	Error process(int &);
	template <class T, class... ArgT>
	Error process(T&& t, ArgT&&...);
	template <class T>
	Error load(T & t);
	template <class... ArgT>
	Error operator ()(ArgT&&... args);	
};

Serializer::Serializer(std::stringstream& out_t):out{out_t}
{
	std::cout << "Serializer object is done\n";
}

Error Serializer::process(bool val)
{
	if (val)
		out << "true" << separator;
	else
		out << "false" << separator;
	return Error::noError;
}

Error Serializer::process(int val)
{
	out << val << separator;
	return Error::noError;
}

template <class T, class... ArgT>
Error Serializer::process(T && t, ArgT&&... args)
{
	if (process(std::forward<T>(t)) == Error::noError)
		return process(std::forward<ArgT>(args)...);
	return Error::noError;
}

template <class... ArgT>
Error Serializer::operator ()(ArgT&&... args)
{
	return process(std::forward<ArgT>(args)...);
}
	
template <class T>
Error Serializer::save(T & obj)
{
	std::cout << "ok\n";
	return obj.serialize(*this);
}

Deserializer::Deserializer(std::stringstream & in_t): in{in_t}
{}

Error Deserializer::process(bool & val)
{
	std::string str;
	in >> str;
	if (str == "true")
		val = true;
	else
		if (str == "false")
			val = false;
		else
			return Error::CorruptedArchive;
	return Error::noError;
}

Error Deserializer::process(int & val)
{
	std::string str;
	in >> str;
	val = atoi(str.c_str());
	return Error::noError;
}

template <class T, class... ArgT>
Error Deserializer::process(T&& t, ArgT&&... args)
{
	if (process(std::forward<T>(t)) == Error::noError)
		process(std::forward<ArgT>(args)...);
	return Error::CorruptedArchive;
}

template <class... ArgT>
Error Deserializer::operator ()(ArgT&&... args)
{
	if (process(std::forward<ArgT>(args)...) == Error::noError)
		return Error::noError;
	return Error::CorruptedArchive;
}

template <class T>
Error Deserializer::load(T & t)
{
	return t.serialize(*this);
}



