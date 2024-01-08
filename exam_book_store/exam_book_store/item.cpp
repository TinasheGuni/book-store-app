#include "item.h"

Item::Item(QObject *parent) : QObject{parent} {}

bool Item::check() { QRegularExpression re("[Bk|Mg][0-3]d{2}"); }
