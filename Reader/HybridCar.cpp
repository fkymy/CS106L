//
// class Car
// {
// public:
//     virtual ~Car();
//     virtual void applyBrakes() { doApplyBrakes(); }
//     virtual void accelerate() { doAccelerate(); }
//
// protected:
//     void doApplyBrakes();
//     void doAccelerate();
// };
//
// class HybridCar: public Car
// {
// public:
//     virtual void applyBrakes() { doApplyBrakes(); chargeBattery(); }
//     virtual void accelerate() { doAccelerate(); dischargeBattery(); }
//
// private:
//     void chargeBattery();
//     void dischargeBattery();
// };


class Car
{
public:
    virtual ~Car();
    virtual void applyBrakes();
    virtual void accelerate();
};

class HybridCar: public Car
{
public:
    virtual void applyBrakes() {
        Car::applyBrakes();
        chargeBattery();
    }
    virtual void accelerate() {
        Car::accelerate();
        dischargeBattery();
    }

private:
    void chargeBattery();
    void dischargeBattery();
};
