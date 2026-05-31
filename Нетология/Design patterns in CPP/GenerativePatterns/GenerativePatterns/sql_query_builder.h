#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <sstream> 
#include <string> 

struct SqlSelectQuery
{
	std::vector<std::string> column;
	std::string from;
	std::vector<std::string> where;
    std::vector<std::string> greaterLess;

};

class SqlSelectQueryBuilder
{
	SqlSelectQuery obj;
public:
	SqlSelectQueryBuilder& AddColumn(const std::string& column)
	{
		obj.column.push_back(column);
		return *this;
	}
	
	SqlSelectQueryBuilder& AddFrom(const std::string& from)
	{
		obj.from = from;
		return *this;
	}

    SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>& kv)
    {
        for (const auto& el : kv)
        {
            obj.where.push_back(el.first);
            obj.where.push_back(el.second);
        }
        return *this;
    }

    SqlSelectQueryBuilder& AddWhere(const std::string& column, const std::string& value)
    {
        obj.where.push_back(column);
        obj.where.push_back(value);
        return *this;
    }

    void set_greaterLesss(const std::string& greaterLess)
    {
        obj.greaterLess.push_back(greaterLess);
    }

    std::string BuildQuery() const
    {
        std::ostringstream query;

        query << "SELECT ";
        if (obj.column.empty())
        {
            query << "*";
        }
        else
        {
            for (size_t i = 0; i < obj.column.size(); ++i)
            {
                if (i > 0) query << ", ";
                query << obj.column[i];
            }
        }

        query << " FROM " << obj.from;

        if (!obj.where.empty())
        {
            query << " WHERE ";
            if (!obj.greaterLess.empty())
            {
                for (size_t i = 0; i < obj.where.size(); i += 2)
                {
                    if (i > 0) query << " AND ";
                    query << obj.where[i] << obj.greaterLess[i] << obj.where[i + 1];
                }
            }
            else
            {
                for (size_t i = 0; i < obj.where.size(); i += 2)
                {
                    if (i > 0) query << " AND ";
                    query << obj.where[i] << "=" << obj.where[i + 1];
                }
            }
        }
    

        query << ";";
        return query.str();
    }
};

class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder
{
public:
    AdvancedSqlSelectQueryBuilder& GreaterAndLess(const std::string& greaterLess)
    {
        set_greaterLesss(greaterLess);
        return *this;
    }
};
