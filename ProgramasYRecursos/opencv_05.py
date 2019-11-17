#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Sep 19 23:05:48 2019

@author: mar
"""
import numpy as np
import cv2 
image = cv2.imread('hoja.png') # Load your image in here
# Your code to threshold
image = cv2.adaptiveThreshold(image, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY_INV, 45, 0)    

# Perform morphology
se = np.ones((7,7), dtype='uint8')
image_close = cv2.morphologyEx(image, cv2.MORPH_CLOSE, se)

# Your code now applied to the closed image
cnt = cv2.findContours(image_close, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_NONE)[0]
mask = np.zeros(image.shape[:2], np.uint8)
cv2.drawContours(mask, cnt, -1, 255, -1)