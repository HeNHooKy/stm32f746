#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    virtual void DisplayTimeLeft(int minute) {}
    virtual void DisplayTimeRight(int minute) {}
    virtual void DisplayTempLeft(int value) {}
    virtual void DisplayTempRight(int value) {}
    virtual void DisplayStatusLeft(int status) {}
    virtual void DisplayStatusRight(int status) {}
    //вывод времени
    virtual void DisplayCurrentTime(int day, int hour, int minute) {}
    virtual void DisplayServiceMaintenance(bool flag) {}

    virtual void ShowMessage(int num) {}

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
