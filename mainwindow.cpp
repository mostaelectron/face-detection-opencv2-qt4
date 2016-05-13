#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace std;
using namespace cv;

/** Global variables */

String face_cascade_name = "haarcascade/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "haarcascade/haarcascade_eye.xml";
String nose_cascade_name = "haarcascade/haarcascade_mcs_nose.xml";

VideoCapture capture_cam;
Mat src_img, des_img, gray_img , gray_img_;
QTimer *timer;
String window_name = "Capture - Face detection";

CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
CascadeClassifier nose_cascade;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    capture_cam.open(-1);

    //if fail whene openning cam
    if(! capture_cam.isOpened())
        exit(0);
    //if fail whene loading face cascade xml file
    if( !face_cascade.load( face_cascade_name ) )
        exit(0);
    //if fail whene loading eyes cascade xml file
    if( !eyes_cascade.load( eyes_cascade_name ) )
        exit(0);
    //if fail whene loading nose cascade xml file
    if( !nose_cascade.load( nose_cascade_name ) )
        exit(0);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(ProcessFrameAndUpdateGui()));
    timer->start(20);
}

void MainWindow::ProcessFrameAndUpdateGui()
{
    capture_cam.read(src_img);
    if(src_img.empty())
        return;
    cv::resize(src_img, src_img, cvSize( ui->org_img->width() , ui->org_img->height()) );
    des_img = detectAndDraw(src_img);

    //show results
    //orginal image
    ui->org_img->setPixmap(QPixmap::fromImage(Mat2qimage(src_img, QImage::Format_RGB888)));
    //gray image
    cvtColor( src_img, gray_img, CV_BGR2GRAY );
    ui->gray_img->setPixmap(QPixmap::fromImage(Mat2qimage(gray_img, QImage::Format_Indexed8)));
    //equalized image
    equalizeHist( gray_img, gray_img_ );
    ui->gray_img_->setPixmap(QPixmap::fromImage(Mat2qimage(gray_img_, QImage::Format_Indexed8)));
    //final image
    ui->des_img->setPixmap(QPixmap::fromImage(Mat2qimage(des_img, QImage::Format_RGB888)));
}
////////////////////////////////////////////////////////////////////////////////////////

QImage MainWindow::Mat2qimage(Mat& mat, QImage::Format format )
{
    //if not gray image
    if(format!=QImage::Format_Indexed8)
        cvtColor(mat, mat, CV_BGR2RGB); // if color image  , convert from BRG to RGB
    return QImage((uchar*)mat.data , mat.cols, mat.rows, mat.step ,  format);
}


//detect faces and draw theme
Mat MainWindow::detectAndDraw(const Mat& frame)
{
    vector<Rect> faces;
    Mat des_img , frame_gray ;

    des_img = frame.clone();
    //convert to gray scal
    cvtColor( des_img, frame_gray, CV_BGR2GRAY );
    //equalize to incease edges
    equalizeHist( frame_gray, frame_gray );
    //-- Detect faces
    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
    for( int i = 0; i < faces.size(); i++ )
    {
        //Point p1( faces[i].x , faces[i].y );
        //Point p2( p1.x  + faces[i].width , p1.y + faces[i].height);
        rectangle(des_img, faces[i] , Scalar( 0, 0, 255 ), 2);

        //Detect eyes and noses inside face image (faceROI)
        Mat faceROI = frame_gray( faces[i] );
        //face x and y offset in frame_gray
        int x_offset = faces[i].x;
        int y_offset = faces[i].y;

        //-- In each face, detect eyes
        vector<Rect> eyes;
        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE );
        if(eyes.size()==2)
        {
            //draw our tow eyes
            for( int j = 0; j < 2; j++ )
            {
                Point center( x_offset + eyes[j].x + eyes[j].width*0.5, y_offset + eyes[j].y + eyes[j].height*0.5 );
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                circle( des_img, center, radius, Scalar( 255, 0, 0 ), 2 );
            }
        }

        //-- In each face, detect nose
        vector<Rect> noses;
        nose_cascade.detectMultiScale( faceROI, noses, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(10, 10) );
        if(noses.size()==1)
        {
                Rect noseRect = noses[0];
                Point p1( x_offset + noseRect.x , y_offset  + noseRect.y );
                Point p2( p1.x  + noseRect.width , p1.y + noseRect.height);
                rectangle(des_img, p1, p2 , Scalar( 0, 255, 0 ), 2);
        }
    }
    //-- return image
    return des_img;
}

MainWindow::~MainWindow()
{
    delete ui;
}
