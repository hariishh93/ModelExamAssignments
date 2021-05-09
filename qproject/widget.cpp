#include "widget.h"
#include "QTextEdit"
#include "QColorDialog"
#include "QLabel"
#include "QDebug"
#include "QPushButton"
#include "QFont"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //Heading
    QFont labelFont("Times",18,QFont::Bold);
        QLabel *mLabel=new QLabel("This is My Sentence",this);
        mLabel->setFont(labelFont);
        mLabel->move(100,25);
        QPalette label;
        label.setColor(QPalette::Window,Qt::green);
        label.setColor(QPalette::WindowText,Qt::darkBlue);
        mLabel->setAutoFillBackground(true);
        mLabel->setPalette(label);


        //Text edit
        QTextEdit *text=new QTextEdit(this);
        text->move(120,90);
        text->setMinimumSize(300,100);
        connect(text,&QTextEdit::textChanged,[=](){
        qDebug()<<"Text Changed"; });


        //CutButton
        QPushButton *cut=new QPushButton("Cut",this);
        cut->setMinimumSize(50,30);
        cut->move(75,300);
        connect(cut,&QPushButton::clicked,[=](){
        text->cut(); });


        //copyButton
        QPushButton *copy=new QPushButton("Copy",this);
        copy->setMinimumSize(50,30);
        copy->move(215,300);
        connect(copy,&QPushButton::clicked,[=](){
        text->copy(); });


        //PasteButton
        QPushButton *paste=new QPushButton("Paste",this);
        paste->setMinimumSize(50,30);
        paste->move(355,300);
        connect(paste,&QPushButton::clicked,[=](){
        text->paste(); });


        //UndoButton
        QPushButton *undo=new QPushButton("Undo",this);
        undo->setMinimumSize(50,30);
        undo->move(75,350);
        connect(undo,&QPushButton::clicked,[=](){
        text->undo(); });


        //RedoButton
        QPushButton *redo=new QPushButton("Redo",this);
        redo->setMinimumSize(50,30);
        redo->move(355,350);
        connect(redo,&QPushButton::clicked,[=](){
        text->redo(); });


        //HTML Button
        QPushButton *html=new QPushButton("HTML",this);
        html->setMinimumSize(50,30);
        html->move(215,350);
        connect(html,&QPushButton::clicked,[=](){
        text->setHtml("<h1>Title</h1><p>Three districts:</br> <ul><li>X</li><li>Y</li><li>Z</li></ul></p>");  });

    }


Widget::~Widget()
{
}

