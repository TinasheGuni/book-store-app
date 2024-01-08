#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QDomDocument>
#include <QList>
#include <QObject>

class Customer : public QObject {
  Q_OBJECT
  Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged FINAL)
public:
  Customer(const QString &name, QList<Customer *> *list,
           QObject *parent = nullptr);

  ~Customer();

  void listFromXml(QString s);

  QString getName() const;
  void setName(const QString &newName);

signals:
  void nameChanged();

private:
  QString name;
  QList<Customer *> *list;
};

#endif // CUSTOMER_H
