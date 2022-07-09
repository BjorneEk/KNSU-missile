
////////////////////////////////////////////////////////////////////////////
///                                                                      ///
///        @author Gustaf Franzén :: https://github.com/BjorneEk;        ///
///        @author Emil Wallbom   :: https://github.com/XXXXXXXX;        ///
///              https://github.com/BjorneEk/KNSU-missile                ///
///                                                                      ///
////////////////////////////////////////////////////////////////////////////

#include <Servo.h>

#define TODEGREES(x) (x * 57.2957795147)


class TVSystem {

  private:
    int _x_pin, _y_pin;
    Servo x_axis, y_axis;

  public:
    TVSystem(int x_pin, int y_pin);

    void init();
    void set_x(int angle);
    void set_y(int angle);
    void set_x_rad(float angle);
    void set_y_rad(float angle);
    void detatch();
    int read_x();
    int read_y();
    int x_pin();
    int y_pin();
    bool is_ready();
};


class Rocket {

  private:
    double x_ang, y_ang;
    double Dx_ang, Dy_ang;
    double altitude;
    double Dalt;
    unsigned long long T;
    unsigned long long ET_apogee;
    unsigned long long ET_burn;
    TVSystem motor;

  public:

    Rocket(
      int x_pin,
      int y_pin,
      unsigned long long etapogee,
      unsigned long long etburn,
      double base_altitude,
      double base_x_angle,
      double base_y_angle)
      : motor(x_pin, y_pin) {
      Dx_ang = 0; Dy_ang = 0; T = 0; Dalt = 0;
      x_ang = base_x_angle; y_ang = base_y_angle;
      altitude = base_altitude;
      ET_apogee = etapogee; ET_burn = etburn;
    }
    void init();
    void update(unsigned long long ct, double alt, double x_ang, double y_ang);
    void set_gimbal(int x_angle, int y_angle);
    void set_gimbal_rad(float x_angle, float y_angle);
};
