#ifndef ITEM_H
#define ITEM_H

#include <QObject>
#include <QRegularExpression>

class Item : public QObject {
  Q_OBJECT
public:
  explicit Item(QObject *parent = nullptr);
  bool check(QString data);

signals:
};

#endif // ITEM_H
