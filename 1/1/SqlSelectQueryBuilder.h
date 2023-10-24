#pragma once
#include <vector>
#include <string>
#include <map>

struct Query {
	std::vector<std::string> colomn;
	std::map<std::string, std::string> mp;
};

class SqlSelectQueryBuilder
{
public:
	SqlSelectQueryBuilder()
	{

	};

	SqlSelectQueryBuilder& AddColomn(std::string st)
	{
		query.colomn.push_back(st);
	}

private:
	Query query;
};

