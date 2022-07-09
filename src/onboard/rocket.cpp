
////////////////////////////////////////////////////////////////////////////
///                                                                      ///
///        @author Gustaf Franzén :: https://github.com/BjorneEk;        ///
///        @author Emil Wallbom   :: https://github.com/XXXXXXXX;        ///
///              https://github.com/BjorneEk/KNSU-missile                ///
///                                                                      ///
////////////////////////////////////////////////////////////////////////////

#include "rocket.h"

TVSystem::TVSystem(int x_pin, int y_pin)
{ _x_pin = x_pin; _y_pin = y_pin; }

void TVSystem::init()
{ x_axis.attach(_x_pin); y_axis.attach(_y_pin); }

void TVSystem::set_x(int angle)
{ x_axis.write(angle); }

void TVSystem::set_y(int angle)
{ y_axis.write(angle); }

void TVSystem::set_x_rad(float angle)
{ x_axis.write(TODEGREES(angle)); }

void TVSystem::set_y_rad(float angle)
{ y_axis.write(TODEGREES(angle)); }

int TVSystem::read_x()
{ return x_axis.read(); }

int TVSystem::read_y()
{ return y_axis.read(); }

bool TVSystem::is_ready()
{
  return x_axis.attached(_x_pin) && y_axis.attached(_y_pin);
}

void TVSystem::detatch()
{ x_axis.detatch(); y_axis.detatch(); }

int TVSystem::x_pin()
{return _x_pin; }

int TVSystem::y_pin()
{return _y_pin; }


void Rocket::init()
{ motor.init() }

void Rocket::update(unsigned long long ct,     double alt,
                    double             _x_ang, double _y_ang)
{
  int dt = ct - T;
  T = ct;
  Dx_ang = (double)((_x_ang - x_ang) / (double)(dt));
  Dy_ang = (double)((_y_ang - y_ang) / (double)(dt));
  x_ang = _x_ang;
  y_ang = _y_ang;
  Dalt = (double)((alt - altitude) /(double)(dt));
  altitude = alt;
}

void Rocket::set_gimbal(int x_angle, int y_angle)
{ motor.set_x(x_angle); motor.set_y(y_angle); }

void Rocket::set_gimbal_rad(float x_angle, float y_angle)
{ motor.set_x_rad(x_angle); motor.set_y_rad(y_angle); }
