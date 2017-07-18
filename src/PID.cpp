#include "PID.h"
#include <time.h>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() 
{
    i_error = 0;
    lastcte = 0;
}

PID::~PID() {}

void PID::Init(double _Kp, double _Ki, double _Kd) {
    Kp = _Kp;
    Ki = _Ki;
    Kd = _Kd;
    i_error = 0;
    lasttime = clock();
    lastcte = 0;
}

void PID::UpdateError(double cte) {
    p_error = cte;
    i_error += cte;
    d_error = (cte-lastcte)*1000.0/(clock()-lasttime);
    lastcte = cte;
    lasttime = clock();
}

double PID::TotalError() {
    return -(Kp*p_error+Kd*d_error+Ki*i_error);
}

