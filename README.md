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


//=====================================================     
The difference is:  
(A)Icon movement
PushButton: The icon will move when users presses the button.
iconButton: The icon will not move when users presses the button. The button doesn't represent the pressed behavior.

(B)Icon types
Both types have 3 kinds of icons:
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







