#ifndef SERVICES_HPP
#define SERVICES_HPP

#include <gui_generated/containers/servicesBase.hpp>

class services : public servicesBase
{
public:
    services();
    virtual ~services() {}

    virtual void initialize();
protected:
};

#endif // SERVICES_HPP
