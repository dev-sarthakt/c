double degtorad(double deg){
    double pi = 3.14159;
    return deg*(pi/180);
}

double power(double base, int pow){
    double temp = 1;
    for (int i = 0; i < pow; i++)
    {
        temp = temp*base;
    }
    return temp;
}

double fac(int number){
    double temp = 1;
    while (number > 0)
    {
        temp = temp * number;
        number--;
    }
    return temp;
}

double sin(double angle){
    return (angle-(power(angle, 3)/fac(3))+(power(angle, 5)/fac(5))-(power(angle, 7)/fac(7))+(power(angle, 9)/fac(9)));
}
