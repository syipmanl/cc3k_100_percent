#ifndef __SUBJECT_H__
#define __SUBJECT_H__

#include <vector>
#include "subscriptions.h"
#include "observer.h"

using std::vector;


class Subject {
	vector<Observer *> observers;

public:
	void attach(Observer *o);
	void notifyObservers(SubscriptionType t);
	virtual Info getInfo() const =0;
	virtual ~Subject();
};

#endif






