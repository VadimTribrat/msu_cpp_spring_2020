#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <exception>

template <class T>
std::string printChar(T && t)
{
	std::string str;
	str.push_back(t);
	return str;
}

template <class... ArgT>
std::string format(std::string str, ArgT&&... args)
{
	std::vector<std::string> params = {std::to_string(std::forward<ArgT>(args))...};
	size_t len = str.length();
	std::string result_str;
	for(int i = 0; i<len; i++)
	{
		while (str[i] != '{')
		{
			result_str.push_back(str[i]);
			i++;
			if (i >= len)
				break;
		}
		if (i >= len)
			break;
		std::string str_temp;
		while (str [i] != '}')
		{
			i++;
			if (i<len)
				str_temp.push_back(str[i]);
			else
				throw std::runtime_error("Unbalanced number of brackets\n");
			i++;
		}
		for(auto sym : str_temp)
			if ((sym<'0') || (sym >'9'))
				throw std::runtime_error("Not a number\n");
		if (atoi(str_temp.c_str()) < params.size())
		{
			result_str = result_str + params[atoi(str_temp.c_str())];
		}
		else
			throw std::runtime_error("Not enough arguments\n");
	}
	return result_str;
}
