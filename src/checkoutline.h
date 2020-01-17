#ifndef CHECKOUTLINE_H
#define CHECKOUTLINE_H

class CheckoutlineSimulation {
public:
    void runSimulation();
    void printReport();

private:
    int nServed;
    int totalWait;
    int totalLength;

};


#endif // CHECKOUTLINE_H


