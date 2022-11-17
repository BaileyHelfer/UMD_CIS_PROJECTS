import cv2
## Open CV
#img = cv2.imread('lena.jpg')
#img = cv2.imread('lena.png')
img = cv2.imread('lena.png', 1) 
hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)  # 1: color  0:gray  -1: color+alpha
print(img)
cv2.imshow('image', img)
cv2.imshow('new',hsv)
cv2.waitKey(5000)   # delay 5 seconds

cv2.imwrite('lena.tiff', img)