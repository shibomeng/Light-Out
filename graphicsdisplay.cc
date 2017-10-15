#include "graphicsdisplay.h"
using namespace std;


GraphicsDisplay::GraphicsDisplay(Xwindow *w, int n) : w{w}, n{n} {}

void GraphicsDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    if (i.state) {
        w->fillRectangle(i.col * n, i.row * n, n , n, Xwindow::White);
    } else {
        w->fillRectangle(i.col * n, i.row * n, n , n, Xwindow::Black);
    }
}
SubscriptionType GraphicsDisplay::subType() const {
    return SubscriptionType::All;
}

