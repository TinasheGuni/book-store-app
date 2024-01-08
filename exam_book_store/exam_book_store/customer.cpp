#include "customer.h"

Customer::Customer(const QString &name, QList<Customer *> *list,
                   QObject *parent)
    : QObject(parent), name(name), list(list) {}

Customer::~Customer() { delete *list; }

void Customer::listFromXml(QString s) {
  QDomDocument doc;
  if (!doc.setContent(&xmlString)) {
    QDomElement root = doc.rootElement();
    if (root.tagName() == "customer") {
      QDomNode node = root.firstChild();
      while (!node.isNull()) {
        QDomElement element = node.element();
        if (!element.isNull()) {
          if (element.tagName() == "customer type") {
            QString type{element.attribute("customer", "")};
            QString name{element.attribute("name", "")};
            QString other{element.attribute("regNumber", "")};

            QDomNode n = node.firstChild();

            while (!n.isNull()) {
              // get the tag values for this customer

              QDomElement childNodeElement = n.toElement();

              QString name = childNodeElement.tagName();
              if (name == "customer" || name == "name" || name == "regNumber") {
                QString text = childNodeElement.text();
                qDebug() << name << text;
              }

              n = n.nextTag();
            }
          }
        }
        node = node.nextSibling();
      }
    }
  }
}

QString Customer::getName() const { return name; }

void Customer::setName(const QString &newName) {
  if (name == newName)
    return;
  name = newName;
  emit nameChanged();
}
}
