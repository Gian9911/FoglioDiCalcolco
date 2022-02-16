#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
#include <QMainWindow>
#include <QListWidgetItem>
class Observer {
 public:
  virtual ~Observer(){};
  virtual void update(QString item) = 0;
};

class Subject {
 public:
  virtual ~Subject(){};
  virtual void subscribe(Observer* observer) = 0;
  virtual void unsubscribe(Observer* observer) = 0;
  virtual void notify(QString item) = 0;
};
#endif // OBSERVER_H
