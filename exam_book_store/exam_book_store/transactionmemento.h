#ifndef TRANSACTIONMEMENTO_H
#define TRANSACTIONMEMENTO_H

#include <QString>

class TransactionMemento {
public:
  TransactionMemento(const QString &state);
  QString getState();
  void setState(QString state);

private:
  QString state;
};

#endif // TRANSACTIONMEMENTO_H
