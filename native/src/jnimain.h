/*
Ну вы же понимаете, что код здесь только мой?
Well, you do understand that the code here is only mine?
 */

/* 
 * File:   jnimain.h
 * Author: LWJGL2
 *
 * Created on 12 сентября 2023 г., 03:25
 */

#ifndef JNIMAIN_H
#define JNIMAIN_H

#include <string>
#include "GizmoJNIEnv.h"
#include "net_steelswing_libgizmo_LibGizmo.h"
#include <iostream>

jmethodID setupENV(GizmoJNIEnv* gizmoEnv);

GizmoJNIEnv* getGizmoEnv();

#endif /* JNIMAIN_H */

