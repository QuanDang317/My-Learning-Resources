import cv2 as cv
import numpy as np

ori_image = cv.imread("Berlin.jpg")
height, width, _ = ori_image.shape

# image = ori_image[::2, ::2, :]  # Resize

# image = ori_image[:, ::-1, :]  # Flip horizontally

# image = ori_image[::-1, :, :]  # Flip vertically

# Rotate clockwise
image = np.zeros((width, height, 3), dtype=np.uint8)
image[:, :, 0] = ori_image[:, :, 0].T
image[:, :, 1] = ori_image[:, :, 1].T
image[:, :, 2] = ori_image[:, :, 2].T


cv.imshow("Result", image)
cv.waitKey(0)
