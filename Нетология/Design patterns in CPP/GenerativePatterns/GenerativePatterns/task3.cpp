#include "sql_query_builder.h"
#include <cassert>

int main()
{
    AdvancedSqlSelectQueryBuilder query_builder;
    query_builder.AddColumn("name").AddColumn("phone");
    query_builder.AddFrom("students");

    // Добавляем условие id > 42
    query_builder.AddWhere("id","42");
    query_builder.GreaterAndLess(">");

    assert(query_builder.BuildQuery() == "SELECT name, phone FROM students WHERE id>42;");
}