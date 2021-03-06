#include <DApplication>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    DApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("dtk-application");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a dtk template application.");

    a.loadTranslator();
    a.setApplicationDisplayName(QCoreApplication::translate("Main", "DTK Application"));
    a.setWindowIcon(QIcon(":/images/iso定制工具-24px.svg"));

    // 保存程序的窗口主题设置
    DApplicationSettings as;
    Q_UNUSED(as)

    MainWindow w;
    w.resize(807,604);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
