#pragma once
#include <vector>
#include <string>
#include <map>

struct Query {
	std::vector<std::string> colomn;
	std::vector<std::string> from;
	std::map<std::string, std::string> mp;
};

class SqlSelectQueryBuilder
{
public:
	SqlSelectQueryBuilder()
	{

	};

	/*
	in this method, we select the columns that we will output 
	based on the result of the SQL query. Let's say we have 10 columns
	in the table for information about students
	(full name, average grade, place of residence, course, etc.),
	but now it is important for us to display only the full name and phone number.*/

	SqlSelectQueryBuilder& AddColomn(std::string st)
	{
		query.colomn.push_back(st);
		return *this;
	}
	//this is the function we need to specify the tables we are accessing.
	SqlSelectQueryBuilder& AddFrom(std::string st)
	{
		query.from.push_back(st);
		return *this;
	}
	/*
	this is already generating a condition. And what kind of students do we need? In the example, this is a student with the name John and the ID 42.
	query_builder.AddWhere(“id”, “42”).AddWhere(“name”, “John”);
	Taking into account that the id is most likely unique, then we will have one person. We can only leave:
	query_builder.AddWhere(“name”, “John”);
	Then a list of all students with the name John will be displayed.*/
	SqlSelectQueryBuilder& AddWhere(std::pair<std::string, std::string> vp)
	{
		query.mp.emplace(vp);
		return *this;
	}

	// should return final query for SQL database
	Query BildSql()
	{
		return query;
	}

private:
	Query query;
};

