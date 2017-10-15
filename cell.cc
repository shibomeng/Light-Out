#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() {}

bool Cell::getState() const { return isOn; }


Info Cell::getInfo() const {
    Info i{r, c, isOn};
    return i;
}

void Cell::setOn() {
    isOn = true;
}

void Cell::toggle() {
    if (isOn) {
        isOn = false;
    } else {
        isOn = true;
    }
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &) {
    toggle();
    this->notifyObservers(SubscriptionType::All);
}

SubscriptionType Cell::subType() const {
    return SubscriptionType::SwitchOnly;
}

