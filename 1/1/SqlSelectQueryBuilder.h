#pragma once
#include <vector>
#include <string>
#include <map>

struct Query {
	std::vector<std::string> colomn;
	std::string table;
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
		return *this;
	}
	//this is the function we need to specify the tables we are accessing.
	SqlSelectQueryBuilder& AddFrom(std::string st)
	{
		query.table = st;
		return *this;
	}

	SqlSelectQueryBuilder& AddWhere(std::string a, std::string b)
	{
		query.mp.emplace(std::pair<std::string, std::string>(a,b));
		return *this;
	}

	// should return final query for SQL database
	Query BildSql()
	{
		if (query.colomn.empty()) query.colomn.push_back("*");
		return query;
	}

private:
	Query query;
};

