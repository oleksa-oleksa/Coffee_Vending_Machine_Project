#ifndef STATE_H
#define STATE_H

class State
{
public:
    State();
    ~State();

private:
    enum{
      OK,
      IS_EVENT,
      ALARM,
      UNDEFINED
    };
};

#endif // STATE_H
