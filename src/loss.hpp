class Loss {
public:
    virtual double function(double, double) = 0;
    virtual double derivative(double, double) = 0;
};
