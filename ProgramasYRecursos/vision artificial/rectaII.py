# -*- coding: utf-8 -*-
"""
Created on Tue Sep  3 01:56:09 2019

@author: L430
"""
#Otra implementación es el método probabilístico de la transformada de Hough, en este caso
# la función recibe dos parámetros extras, minLineLength que establece la longitud mínima de
#la línea y maxLineGap que indica el intervalo máximo de líneas para tratarlas como una sola.
# =============================================================================
# A diferencia del la función anterior, esta nos devuelve las coordenadas de la línea
# directamente.
# =============================================================================

import cv2
import numpy as np

img = cv2.imread('sudoku.png')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 50, 150, apertureSize = 3)

lines = cv2.HoughLinesP(edges, 1, np.pi/180, 100, minLineLength=100, maxLineGap=10)

for line in lines:
    x1, y1, x2, y2 = line[0]
    cv2.line(img, (x1,y1), (x2,y2), (0,255,0), 1, cv2.LINE_AA)

cv2.imshow('Bordes de Iamgen', edges)
cv2.imshow('Detector de Lineas', img)
cv2.waitKey()