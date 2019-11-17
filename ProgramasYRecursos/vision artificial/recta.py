# -*- coding: utf-8 -*-
"""
Created on Fri Aug 30 12:25:51 2019

@author: L430
"""
#/Cada línea que encuentra es representada por dos valores, rho ρ y theta Θ,
#que representan la distancia de la perpendicular de la recta al punto de origen
# y el ángulo de rotación de la perpendicular, respectivamente.
#Los parámetros cv2.HoughLines(edges, 1.2, PI/180, 200), establecen, primero la imagen
# binaria con los bordes encontrados, luego en valor rho y theta en radianes, el último parámetro
# establece el máximo umbral aceptable, esta función devuelve un conjunto de
# líneas expresadas por los valores, rho y theta, por ello los procesamos para obtener 
#las coordenadas x, y iniciales y finales que usaremos para dibujar la línea.

import cv2
import numpy as np

img = cv2.imread('parking.png')
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
edges = cv2.Canny(gray, 50, 150, apertureSize = 3)

lines = cv2.HoughLines(edges, 1, np.pi/180, 200)

for line in lines:
    rho, theta = line[0]
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a*rho
    y0 = b*rho
    x1 = int(x0 + 1000*(-b))
    y1 = int(y0 + 1000*(a))
    x2 = int(x0 - 1000*(-b))
    y2 = int(y0 - 1000*(a))

    cv2.line(img, (x1,y1), (x2,y2), (0, 0, 255), 1, cv2.LINE_AA)

cv2.imshow('Bordes de Imagen', edges)
cv2.imshow('Detector de Lineas', img)
cv2.waitKey()