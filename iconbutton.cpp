#include "iconbutton.h"
//Constructor1
iconButton::iconButton(QString text, QWidget *parent):QPushButton(text, parent)
{
    this->setFixedSize(60,60);

    //===============================
    //Icon Loader
    //-------------------------------
    //_Initialize Icon Loader
    this->iconLoader = new QLabel(this);


    //===============================
    //Icon Text
    //-------------------------------
    //_Initialize Text
    this->setText("");
    iconText = new QLabel(text, this);
    iconText->setStyleSheet("QLabel{background:transparent;}"
                            "QLabel{font-family: "+this->fontName+", Helvetica, sans-serif;}"
                            "QLabel{color: rgb("+this->fontColor+");}");

    //_Shadow Effect
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    iconText->setGraphicsEffect(shadowEffect);
    shadowEffect->setBlurRadius(2);
    shadowEffect->setOffset(1,1);
    //Set Text Location
    //_setFontSize
    font.setPointSize(this->fontSize);
    //_setFont
    this->iconText->setFont(font);
    //_Calculate font width
    in_calculateIconTextPosition();
    //_set iconText position
    iconText->setGeometry(iconTextPX,iconTextPY, this->width(), this->height());

}
//Constructor2
iconButton::iconButton(QPixmap defaultIconMap, QString text, QWidget *parent):QPushButton(QIcon(), text, parent)
{
    this->setFixedSize(60,60);

    //===============================
    //Icon Loader
    //-------------------------------
    //_Initialize Icon Loader
    this->iconLoader = new QLabel(this);


    //===============================
    //Icon Pixmap
    //-------------------------------
    //_Scaled Pixmap
    if(_autoResizeIcon)
    {
        //_Scale Map
        this->defaultPix = defaultIconMap.scaled(this->width(), this->height()
                                                 , Qt::KeepAspectRatio
                                                 , Qt::SmoothTransformation);
    }
    else
    {
        //_keep the original map size
        this->defaultPix = defaultIconMap;
    }
    //_set Icon map
    this->iconLoader->setPixmap(this->defaultPix);



    //===============================
    //Icon Text
    //-------------------------------
    //_Initialize Text
    this->setText("");
    iconText = new QLabel(text, this);
    iconText->setStyleSheet("QLabel{background:transparent;}"
                            "QLabel{font-family: "+this->fontName+", Helvetica, sans-serif;}"
                            "QLabel{color: rgb("+this->fontColor+");}");

    //_Shadow Effect
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    iconText->setGraphicsEffect(shadowEffect);
    shadowEffect->setBlurRadius(2);
    shadowEffect->setOffset(1,1);
    //Set Text Location
    //_setFontSize
    font.setPointSize(this->fontSize);
    //_setFont
    this->iconText->setFont(font);
    //_Calculate font width
    in_calculateIconTextPosition();
    //_set iconText position
    iconText->setGeometry(iconTextPX,iconTextPY, this->width(), this->height());
}

//Constructor3
iconButton::iconButton(QWidget *parent):QPushButton(parent)
{
    this->setFixedSize(60,60);

    //===============================
    //Icon Loader
    //-------------------------------
    //_Initialize Icon Loader
    this->iconLoader = new QLabel(this);


    //===============================
    //Icon Text
    //-------------------------------
    //_Initialize Text
    this->setText("");
    iconText = new QLabel("", this);
    iconText->setStyleSheet("QLabel{background:transparent;}"
                            "QLabel{font-family: "+this->fontName+", Helvetica, sans-serif;}"
                            "QLabel{color: rgb("+this->fontColor+");}");

    //_Shadow Effect
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect();
    iconText->setGraphicsEffect(shadowEffect);
    shadowEffect->setBlurRadius(2);
    shadowEffect->setOffset(1,1);
    //Set Text Location
    //_setFontSize
    font.setPointSize(this->fontSize);
    //_setFont
    this->iconText->setFont(font);
    //_Calculate font width
    in_calculateIconTextPosition();
    //_set iconText position
    iconText->setGeometry(iconTextPX,iconTextPY, this->width(), this->height());
}

void iconButton::enableReleaseWithHover(bool option)
{
    this->_releaseWithHover = option;
}

void iconButton::enableShaodw(bool option)
{
    this->_shadow = option;
    if(this->_shadow)
        shadowEffect->setEnabled(true);
    else
        shadowEffect->setEnabled(false);
}

void iconButton::enableTextMoveWithButton(bool option)
{
    this->_iconTextMoveWithButton = option;
}

//TYPE_PUSHBUTTON; TPYE_ICONBUTTON
void iconButton::enableIconButtonType(bool option)
{
    this->_iconButtonType = option;
    in_updateIconAndText();
}

void iconButton::enableAutoResizeIcon(bool option)
{
    this->_autoResizeIcon = option;
    in_updateIconAndText();
}

void iconButton::setGeometry(int x, int y, int w, int h)
{
    this->setFixedSize(w, h);
    QPushButton::setGeometry(x, y, w, h);
    in_updateIconAndText();
}

void iconButton::setGeometry(const QRect &rect)
{
    this->setFixedSize(rect.width(), rect.height());
    QPushButton::setGeometry(rect);
    in_updateIconAndText();
}


//===================================================
//QPixmap Version ::setIcons
//These methods cannot save the path
//Please use storeIconPath() to save paths
//===================================================
void iconButton::setDefaultIcon(QPixmap defaultMap)
{
    //_store the original map
    this->defaultOriginalPix = defaultMap;
    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->defaultPix = defaultMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->defaultPix = defaultMap;
    }
    this->iconLoader->setPixmap(this->defaultPix);
}

void iconButton::setPressedIcon(QPixmap pressedMap)
{
    //_store the original map
    this->pressedOriginalPix = pressedMap;
    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->pressedPix = pressedMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->pressedPix = pressedMap;
    }
}

void iconButton::setHoverIcon(QPixmap hoverMap)
{
    //_store the original map
    this->hoverOriginalPix = hoverMap;
    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->hoverPix = hoverMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->hoverPix = hoverMap;
    }
}

void iconButton::setIcons(QPixmap defaultMap, QPixmap pressedMap, QPixmap hoverMap)
{

    //_store the original map
    this->defaultOriginalPix = defaultMap;
    this->pressedOriginalPix = pressedMap;
    this->hoverOriginalPix = hoverMap;

    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->defaultPix = defaultMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);

        //_Scaled Pixmap
        this->pressedPix = pressedMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);
        //_Scaled Pixmap
        this->hoverPix = hoverMap.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);

    }
    else
    {
        //_No scale
        this->defaultPix = defaultMap;

        //_No scale
        this->pressedPix = pressedMap;

        //_No scale
        this->hoverPix = hoverMap;
    }

    //
    this->iconLoader->setPixmap(this->defaultPix);
}

//===================================================
//QString Version ::setIcons
//These methods can save the path at the same time
//===================================================
void iconButton::setDefaultIcon(QString defaultMapName)
{
    this->defaultIconPath = exePath + "/" + defaultMapName;
    //_store the original map
    this->defaultOriginalPix = QPixmap(this->defaultIconPath);

    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->defaultPix = this->defaultOriginalPix.scaled(this->width(), this->height()
                                                   , Qt::KeepAspectRatio
                                                   , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->defaultPix = this->defaultOriginalPix;
    }
    this->iconLoader->setPixmap(this->defaultPix);
}

void iconButton::setPressedIcon(QString pressedMapName)
{
    this->pressedIconPath = exePath + "/" + pressedMapName;
    //_store the original map
    this->pressedOriginalPix = QPixmap(this->pressedIconPath);

    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->pressedPix = this->pressedOriginalPix.scaled(this->width(), this->height()
                                                           , Qt::KeepAspectRatio
                                                           , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->pressedPix = this->pressedOriginalPix;
    }
}

void iconButton::setHoverIcon(QString hoverMapName)
{
    this->hoverIconPath = exePath + "/" + hoverMapName;
    //_store the original map
    this->hoverOriginalPix = QPixmap(this->hoverIconPath);

    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->hoverPix = this->hoverOriginalPix.scaled(this->width(), this->height()
                                             , Qt::KeepAspectRatio
                                             , Qt::SmoothTransformation);
    }
    else
    {
        //_No scale
        this->hoverPix = this->hoverOriginalPix;
    }
}

void iconButton::setIcons(QString defaultMapName, QString pressedMapName, QString hoverMapName)
{
    //_get path
    this->defaultIconPath = exePath + "/" + defaultMapName;
    this->pressedIconPath  = exePath + "/" + pressedMapName;
    this->hoverIconPath   = exePath + "/" + hoverMapName;

    //_store the original map
    this->defaultOriginalPix = QPixmap(this->defaultIconPath);
    this->pressedOriginalPix = QPixmap(this->pressedIconPath);
    this->hoverOriginalPix = QPixmap(this->hoverIconPath);

    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->defaultPix = this->defaultOriginalPix.scaled(this->width(), this->height()
                                                           , Qt::KeepAspectRatio
                                                           , Qt::SmoothTransformation);

        //_Scaled Pixmap
        this->pressedPix = this->pressedOriginalPix.scaled(this->width(), this->height()
                                                           , Qt::KeepAspectRatio
                                                           , Qt::SmoothTransformation);
        //_Scaled Pixmap
        this->hoverPix = this->hoverOriginalPix.scaled(this->width(), this->height()
                                                       , Qt::KeepAspectRatio
                                                       , Qt::SmoothTransformation);

    }
    else
    {
        //_No scale
        this->defaultPix = this->defaultOriginalPix;

        //_No scale
        this->pressedPix = this->pressedOriginalPix;

        //_No scale
        this->hoverPix = this->hoverOriginalPix;
    }

    //
    this->iconLoader->setPixmap(this->defaultPix);
}

void iconButton::storeIconPath(QString path, int mode)
{
    if(mode == MODE_DEFAUT)
    {
        //_for debug
        this->defaultIconPath = path;
    }
    else if(mode == MODE_PRESSED)
    {
        //_for debug
        this->pressedIconPath = path;
    }
    else if(mode == MODE_HOVER)
    {
        //_for debug
        this->pressedIconPath = path;
    }
}

void iconButton::setFontSize(int value)
{
    font.setPointSize(value);
    this->iconText->setFont(font);
    in_updateIconAndText();
}

void iconButton::setIconText(QString text)
{
    this->iconText->setText(text);
    in_updateIconAndText();
}

void iconButton::setIconTextOffset(int offX, int offY)
{
    this->iconText->setGeometry(iconTextPX+offX, iconTextPY+offY, this->width(), this->height());
}

void iconButton::setShadowBlurRadius(int value)
{
    shadowEffect->setBlurRadius(value);
}

void iconButton::setShadowOffset(int x, int y)
{
    shadowEffect->setOffset(x, y);
}

void iconButton::setShadowOffsetX(int x)
{
    shadowEffect->setXOffset(x);
}

void iconButton::setShadowOffsetY(int y)
{
    shadowEffect->setYOffset(y);
}

void iconButton::setIcon(QPixmap defaultMap)
{
    //This has been overrided
    //The function is the same as setDefaultIcon();
    qDebug() << "Override setIcon";
    setDefaultIcon(defaultMap);
}


void iconButton::in_updateIconAndText()
{
    //Update Icon size
    //_Auto Resize the icon as the icon size
    if(this->_autoResizeIcon)
    {
        //_Scaled Pixmap
        this->defaultPix = this->defaultOriginalPix.scaled(this->width(), this->height()
                                                           , Qt::KeepAspectRatio
                                                           , Qt::SmoothTransformation);

        //_Scaled Pixmap
        this->pressedPix = this->pressedOriginalPix.scaled(this->width(), this->height()
                                                           , Qt::KeepAspectRatio
                                                           , Qt::SmoothTransformation);
        //_Scaled Pixmap
        this->hoverPix = this->hoverOriginalPix.scaled(this->width(), this->height()
                                                       , Qt::KeepAspectRatio
                                                       , Qt::SmoothTransformation);

    }
    else
    {
        //_No scale
        this->defaultPix = this->defaultOriginalPix;

        //_No scale
        this->pressedPix = this->pressedOriginalPix;

        //_No scale
        this->hoverPix = this->hoverOriginalPix;
    }

    //
    this->iconLoader->setPixmap(this->defaultPix);


    //Set Text Location
    in_calculateIconTextPosition();
    iconText->setGeometry(iconTextPX,iconTextPY, this->width(), this->height());
}

void iconButton::in_calculateIconTextPosition()
{
    QFontMetrics fm(this->font);
    int textWidth=fm.width(iconText->text());
    int textHeight=fm.height();
    iconTextPX = (this->width()/2) - (textWidth/2);
    iconTextPY = (this->height()/2) - (textHeight/2);
    qDebug() << "[textWidth] " << textWidth;
    qDebug() << "[textHeight] " << textHeight;
    qDebug() << "[px] " << iconTextPX;
    qDebug() << "[py] " << iconTextPY;
    qDebug() << "[width] " << this->width();
    qDebug() << "[height] " << this->height();
}


//=================================
void iconButton::mousePressEvent(QMouseEvent *e)
{
    qDebug() << "iconButton::mousePressEvent";
    if(e->buttons() == Qt::LeftButton){
        qDebug() << "Pressed";
        iconLoader->setPixmap(this->pressedPix);
    }

    //_TYPE_PUSHBUTTON=======================================================================
    if(_iconButtonType == TYPE_PUSHBUTTON)
    {
        if(this->_iconTextMoveWithButton)
        {
            //_back to the origianl location
            //__move iconLoader
            if(_autoResizeIcon)
            {
                iconLoader->setGeometry(2,2, this->defaultPix.width(), this->defaultPix.height());
            }
            else
            {
                iconLoader->setGeometry(2,2, this->defaultOriginalPix.width(), this->defaultOriginalPix.height());
            }
            //__move icontext
            iconText->setGeometry(iconTextPX+2,iconTextPY+2, this->width(), this->height());
        }

        QPushButton::mousePressEvent(e);
    }
    //=======================================================================================
}

void iconButton::mouseReleaseEvent(QMouseEvent *e)
{
    qDebug() << "iconButton::mouseReleaseEvent";
    qDebug() << "Released";
    if(this->_releaseWithHover)
        iconLoader->setPixmap(this->hoverPix);
    else
        iconLoader->setPixmap(this->defaultPix);

    //_TYPE_PUSHBUTTON=======================================================================
    if(_iconButtonType == TYPE_PUSHBUTTON)
    {
        if(this->_iconTextMoveWithButton)
        {
            //__move iconLoader
            if(_autoResizeIcon)
            {
                iconLoader->setGeometry(0,0, this->defaultPix.width(), this->defaultPix.height());
            }
            else
            {
                iconLoader->setGeometry(0,0, this->defaultOriginalPix.width(), this->defaultOriginalPix.height());
            }
            //__move icontext
            iconText->setGeometry(iconTextPX,iconTextPY, this->width(), this->height());
        }

        QPushButton::mouseReleaseEvent(e);
    }
}

void iconButton::enterEvent(QEvent *e)
{
    qDebug() << "iconButton::enterEvent";
    iconLoader->setPixmap(this->hoverPix);
}

void iconButton::leaveEvent(QEvent *e)
{
    Q_UNUSED(e);
    qDebug() << "iconButton::leaveEvent";
    iconLoader->setPixmap(this->defaultPix);
}
