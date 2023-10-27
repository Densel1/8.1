#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include "SqlSelectQueryBuilder.h"


void Send(const Query& q)
{
    std::string out = "SELECT ";
    for (const auto& a : q.colomn)
    {
        out += a;
        out += ", ";
    }
    out += "\b\b";
    out += " FROM " + q.table + " WHERE ";
    for (const auto& b : q.mp)
    {
        out += b.first + " = " + b.second;
        out += " AND ";
    }
    out += "\b\b\b\b\b";
    out += ";      ";

    std::cout <<out<< std::endl;

}

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColomn("name").AddColomn("phone");
    query_builder.AddFrom("students");
    query_builder.AddWhere("id", "42").AddWhere("name", "John");

    Send(query_builder.BildSql());

    return 0;

}