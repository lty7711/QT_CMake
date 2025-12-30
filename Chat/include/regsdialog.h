#ifndef REGSDIALOG_H
#define REGSDIALOG_H

#include <QDialog>
#include <QMap>

#include "global.h"

namespace Ui {
class RegsDialog;
}

class RegsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegsDialog(QWidget *parent = nullptr);
    ~RegsDialog();

private slots:
    void OnEmailTextChangedSlot();
    void RegsFinishedSlot(ReqId id, QString res, ErrorCodes err);

private:
    void RegsHttpHandlers();    // 用于初始化回调函数

    Ui::RegsDialog *ui;
    QMap<ReqId, std::function<void(const QJsonObject&)>> __handlerMap;      // 回调处理函数

signals:
    void CancelRegsSignal();  // 取消注册信号
    
};

#endif // REGSDIALOG_H
