#ifndef ACTUATORTYPE_H
#define ACTUATORTYPE_H


class ActuatorType
{
public:
    ActuatorType();
    ~ActuatorType();

private:
    enum{
      DC_MOTOR,
      LCD,
      MILKMAKER,
      WATERHEATER,
      LED,
      BREWGROUP
    };
};

#endif // ACTUATORTYPE_H
