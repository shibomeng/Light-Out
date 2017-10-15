#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
    if (SubscriptionType::All == t) {
        observers.back()->notify(*this);
        observers.front()->notify(*this);
    } else {
        for (auto ob : observers) {
            ob->notify(*this);
        }
    }
}

Subject::~Subject() {}

