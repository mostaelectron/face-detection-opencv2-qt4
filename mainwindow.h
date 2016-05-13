#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <QTimer>

using namespace std;
using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage Mat2qimage(Mat& mat, QImage::Format format );
    Mat detectAndDraw(const Mat& frame);

public slots:
    void ProcessFrameAndUpdateGui();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
