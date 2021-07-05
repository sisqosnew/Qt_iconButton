# Qt_iconButton
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
The difference is:
(A)Icon movement
PushButton: The icon will move when users presses the button.
iconButton: The icon will not move. The button doesn't represent the pressed behavior.

(B)Icon types
Both types have 3 kinds of icons:
1. default icon (pixmap type)
2. pressed icon (pixmap type)
3. hover icon   (pixmap type)

