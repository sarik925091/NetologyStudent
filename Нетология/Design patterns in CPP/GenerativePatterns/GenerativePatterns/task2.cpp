#include "sql_query_builder.h"
#include <cassert>
#include <map>

int main()
{
    SqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");

    std::map<std::string, std::string> cond1 = { {"id", "42"} };
    std::map<std::string, std::string> cond2 = { {"name", "John"} };
    query_builder.AddWhere(cond1).AddWhere(cond2);

    assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id=42 AND name=John;");
}