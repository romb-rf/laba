#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <recursionVar1.h>
#include <datamanager.h>
#include <iteration.h>
#include <intvalidator.h>
#include <doptask.h>
#include <treenode.h>
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    IntValidator validator;
    engine.rootContext()->setContextProperty("validator", &validator);
    Test myTestObject;
    engine.rootContext()->setContextProperty("recVar", &myTestObject);
    DataManager dataManager;
    engine.rootContext()->setContextProperty("dataM", &dataManager);
    Iteration iteration;
    engine.rootContext()->setContextProperty("iter", &iteration);
    DopTask dop;
    engine.rootContext()->setContextProperty("dop", &dop);
    qmlRegisterUncreatableType<TreeNode>("MyApp", 1, 0, "TreeNode", "TreeNode cannot be created directly");
    qmlRegisterType<Test>("MyApp", 1, 0, "Test");
    engine.loadFromModule("untitled", "Main");

    return app.exec();
}
