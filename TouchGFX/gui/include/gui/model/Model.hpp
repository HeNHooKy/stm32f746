#ifndef MODEL_HPP
#define MODEL_HPP

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    void SendLeftTemp(int value);

protected:
    ModelListener* modelListener;

    int leftTempAddress = 101;
};

#endif // MODEL_HPP
