#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Aug 24 13:23:47 2019

@author: mar
"""

import numpy as np
import matplotlib.pyplot as plt
import cv2
imagen = cv2.imread("platzi.jpg");
#plt.imshow(imagen, cmap = 'gray', interpolation = 'bicubic');
plt.imshow(imagen);
#plt.xticks([]), plt.yticks([])  # to hide tick values on X and Y axis
plt.show()
