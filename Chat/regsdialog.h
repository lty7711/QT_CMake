#ifndef REGSDIALOG_H
#define REGSDIALOG_H

#include <QDialog>

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
    void OnEmailTextChanged();

private:
    Ui::RegsDialog *ui;

    
    
};

#endif // REGSDIALOG_H
