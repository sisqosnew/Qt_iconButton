# Qt_iconButton Overview
iconButton combines   
icon(QLabel as iconLoader)  
text(QLabel as iconText)  
iconButton(QPushButton as iconButton)

Text is above the icon. It has PushButton and IconButton modes

![Untitled](https://user-images.githubusercontent.com/49277601/124438876-50d1b980-ddab-11eb-9d29-0328d0f45583.png)

The iconButton inherits from QPushButton.
iconButton has 2 Types:  
1. PushButton
2. iconButton 

//=====================================================   
[Usage]   
Append the header and .cpp files to your Qt Project.

[Exampe]
https://www.youtube.com/watch?v=-NmYvTfXs-o

//=====================================================     
The difference is:      
(A)Icon movement    
PushButton: The icon will move when users presses the button.   
iconButton: The icon will not move when users presses the button. The button doesn't represent the pressed behavior.    
    
(B)Icon types
Both types work with 3 kinds of icons: (In .png format)
1. default icon (pixmap type)
2. pressed icon (pixmap type)
3. hover icon   (pixmap type) 
  
![icon_google_60x60](https://user-images.githubusercontent.com/49277601/124498635-40433280-ddef-11eb-8847-f9aa7c1db0bc.png)
![icon_google_Pressed_60x60](https://user-images.githubusercontent.com/49277601/124499113-0de60500-ddf0-11eb-8b75-39e75a1cf74f.png)
![icon_google_hover_60x60](https://user-images.githubusercontent.com/49277601/124499116-10485f00-ddf0-11eb-84c4-15d246a678d0.png)


(C)Text
Text is above the icon. It allows uesrs to offset its location.

//=====================================================     
[Help]    
//Properties    
QString fontName = "Calibri";   
QFont font= QFont("Calibri");//Default font   
QString fontColor = "255,255,255";//Default font color    
int fontSize = 12;//Default font color      
int iconTextPX = 0;//Default position X of text   
int iconTextPY = 0;//Default position Y of text   

//_Option Methods      
void enableReleaseWithHover(true);//Switch the defaultIcon to hoverIcon   
void enableShaodw(true);//Eable Shadow of text    
void enableTextMoveWithButton(true);//Eable the text moves with button    
void enableIconButtonType(false);//By default, the type is pushButton   
void enableAutoResizeIcon(true);//Eable the icon follows the size of the button   

//UI    
QLabel *iconLoader; //The Icon widget   
QLabel *iconText;//The Icon Text widget   

//Methods   
void setGeometry(int x, int y, int w, int h); //set the button geometry   
void setGeometry(const QRect &rect);//Set the button geometry by a rect   

void setDefaultIcon(QPixmap defaultMap);//Set the Default Icon    
void setPressedIcon(QPixmap pressedMap);//Set the Pressed Icon    
void setHoverIcon(QPixmap hoverMap);//Set the Hover Icon    

//Set the default, pressed, hover icons   
void setIcons(QPixmap defaultMap, QPixmap pressedMap, QPixmap hoverMap);    

//The default path is where the .exe exists   
//You need copy files in the same folder    
//These functions accept the format >> fileName.extension (pix.png)   
//Note Qt reads .png for QPixmap    
//These functions will store their paths automatically    
void setDefaultIcon(QString defaultMapName);    
void setPressedIcon(QString pressedMapName);    
void setHoverIcon(QString hoverMapNam);   
void setIcons(QString defaultMapName, QString pressedMapName, QString hoverMapName);    

//If you need to work with paths    
//0->MODE_DEFAUT; 1->MODE_PRESSED; 2->MODE_HOVER    
void storeIconPath(QString str, int mode = MODE_DEFAUT);    

void setFontSize(int value);//Set the font size   
void setFont(QString fontName);//Set the font   

void setIconText(QString text);//Set the text of the button   
void setIconTextOffset(int offX, int offY);//Offset the text of the button    

void setShadowBlurRadius(int value);//Set the blur Radius of the shadow   
void setShadowOffset(int x, int y);//Set the offset of the shadow   
void setShadowOffsetX(int x);//Set the offsetX of the shadow    
void setShadowOffsetY(int y);//Set the offsetY of the shadow    






