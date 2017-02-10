#pragma once

#include <QObject>
#include <QQmlEngine>

#include <memory>
#include <QtQuick/QQuickWindow>

class MainWindow : public QObject {
  Q_OBJECT

  public:
    MainWindow(QQmlEngine& engine);
    bool eventFilter(QObject *watched, QEvent *event) override;

  signals:
    void closed();
    void openMuc();

  private:
    std::unique_ptr<QObject> window;

};
