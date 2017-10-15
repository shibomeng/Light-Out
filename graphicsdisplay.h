#ifndef graphicsdisplay_h
#define graphicsdisplay_h
#include "observer.h"
#include "subject.h"
#include "info.h"
#include "window.h"
#include <iostream>


class GraphicsDisplay: public Observer {
    Xwindow *w;
    const int n;
    
public:
    GraphicsDisplay(Xwindow *w, int n);
    SubscriptionType subType() const override;
    void notify(Subject &whoNotified) override;
};

#endif
