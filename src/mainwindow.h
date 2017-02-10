#pragma once

#include <QObject>
#include <QQmlEngine>

#include <memory>

class MainWindow : public QObject{
  Q_OBJECT

  public:
    MainWindow(std::shared_ptr<QQmlEngine> engine);

  signals:
    void openMuc();

};
