#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QPushButton>
#include <QtCore>
#include <QtGui>
#include <QIcon>
#include <QPixmap>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QFont>
#include <QFontMetrics>
#include <cmath>

#define MODE_DEFAUT 0
#define MODE_PRESSED 1
#define MODE_HOVER 2

#define TYPE_PUSHBUTTON 0
#define TYPE_ICONBUTTON 1

class iconButton : public QPushButton
{
    Q_OBJECT
public:
    iconButton(QString text="", QWidget *parent=nullptr);
    iconButton(QIcon icon=QIcon(), QString text="", QWidget *parent = nullptr);
    iconButton(QWidget *parent = nullptr);

    //Properties
    QString fontName = "Calibri";
    QFont font= QFont("Calibri");
    QString fontColor = "255,255,255";
    int fontSize = 12;
    int iconTextPX = 0;
    int iconTextPY = 0;

    QPixmap defaultOriginalPix = QPixmap();
    QPixmap pressedOriginalPix = QPixmap();
    QPixmap hoverOriginalPix = QPixmap();

    QPixmap defaultPix = QPixmap();
    QPixmap pressedPix = QPixmap();
    QPixmap hoverPix = QPixmap();

    QIcon defaultIcon;
    QIcon pressedIcon;
    QIcon hoverIcon;

    QString exePath = QDir::currentPath();
    QString defaultIconPath = exePath+"/NONE";
    QString pressedIconPath = exePath+"/NONE";
    QString hoverIconPath = exePath+"/NONE";

    //_Options
    bool _releaseWithHover = true;
    bool _shadow = true;
    bool _iconTextMoveWithButton = true;
    bool _iconButtonType = TYPE_PUSHBUTTON;
    bool _autoResizeIcon = true;
    //_Option Methods
    void enableReleaseWithHover(bool option);
    void enableShaodw(bool option);
    void enableTextMoveWithButton(bool option);
    void enableIconButtonType(bool option);
    void enableAutoResizeIcon(bool option);

    //UI
    QLabel *iconLoader = nullptr;
    QLabel *iconText= nullptr;
    QGraphicsDropShadowEffect *shadowEffect = nullptr;

    //Methods
    void setGeometry(int x, int y, int w, int h);
    void setGeometry(const QRect &rect);

    void setDefaultIcon(QPixmap defaultMap);
    void setPressedIcon(QPixmap pressedMap);
    void setHoverIcon(QPixmap hoverMap);
    void setIcons(QPixmap defaultMap, QPixmap pressedMap, QPixmap hoverMap);

    void setDefaultIcon(QString defaultMapName);
    void setPressedIcon(QString pressedMapName);
    void setHoverIcon(QString hoverMapNam);
    void setIcons(QString defaultMapName, QString pressedMapName, QString hoverMapName);

    void storeIconPath(QString str, int mode = MODE_DEFAUT);

    void setFontSize(int value);
    void setFont(QString fontName);

    void setShadowBlurRadius(int value);
    void setShadowOffset(int x, int y);
    void setShadowOffsetX(int x);
    void setShadowOffsetY(int y);



private:
    void in_updateIconAndText();

protected:
    void mousePressEvent(QMouseEvent *e)override;
    void mouseReleaseEvent(QMouseEvent *e)override;
    void enterEvent(QEvent *e)override;
    void leaveEvent(QEvent *e)override;
};

#endif // ICONBUTTON_H
