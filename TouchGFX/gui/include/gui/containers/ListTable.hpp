#ifndef LISTTABLE_HPP
#define LISTTABLE_HPP

#include <gui_generated/containers/ListTableBase.hpp>

class ListTable : public ListTableBase
{
public:
    ListTable();
    virtual ~ListTable() {}

    virtual void initialize();
protected:
};

#endif // LISTTABLE_HPP
