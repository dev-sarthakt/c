const double pi =3.14159;

//degtorad
double degtorad(double deg){
    return deg*(pi/180);
}

//radtodeg
double radtodeg(double rad){
    return rad*(180/pi);
}

//power
double power(double base, int pow){
    double temp = 1;
    for (int i = 0; i < pow; i++)
    {
        temp = temp*base;
    }
    return temp;
}

//resultant (note : will need math.h for sqrt())
double resultant(double x, double y){
    return sqrt((power(x,2)+power(y,2)));
}

//factorial
double fac(int number){
    double temp = 1;
    while (number > 0)
    {
        temp = temp * number;
        number--;
    }
    return temp;
}

//sin
double sin(double angle){
    return (angle-(power(angle, 3)/fac(3))+(power(angle, 5)/fac(5))-(power(angle, 7)/fac(7))+(power(angle, 9)/fac(9)));
}

//tan
double arctan(double p, double b){
    double ratio = p/b;
    return ratio-(power(ratio,3)/3)+(power(ratio,5)/5)-(power(ratio,7)/7)+(power(ratio,9)/9);
}

//polar_coordinate
struct Polar{
    double resultant;
    double angle;
};

struct Polar pol(double x, double y){
    struct Polar temp;
    temp.resultant = resultant(x,y);
    temp.angle = arctan(y, x);
    return temp;
}
