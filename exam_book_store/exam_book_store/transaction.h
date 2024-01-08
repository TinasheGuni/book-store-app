#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "customer.h"

class Transaction {
public:
  Transaction(QString c, QDate d, QList<Item> i);

private:
  QString customer;
  QDate date;
  QList<Item> items;
};

#endif // TRANSACTION_H
