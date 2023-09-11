/*
Ну вы же понимаете, что код здесь только мой?
Well, you do understand that the code here is only mine?
 */

/* 
 * File:   GizmoJNIEnv.h
 * Author: LWJGL2
 *
 * Created on 12 сентября 2023 г., 04:08
 */

#ifndef GIZMOJNIENV_H
#define GIZMOJNIENV_H
#include <jni.h>
#include <iostream>

#include "libgizmo/stdafx.h"

class GizmoJNIEnv {
public:
    GizmoJNIEnv();
    GizmoJNIEnv(const GizmoJNIEnv& orig);
    virtual ~GizmoJNIEnv();

    void call(JNIEnv *env);
    jobject newVector3(JNIEnv *env, float x, float y, float z);
    jobject newVector4(JNIEnv *env, float x, float y, float z, float w);

    jobject newVector3(JNIEnv *env, const tvector3 &orig);
    jobject newVector4(JNIEnv *env, const tvector4 &orig);



private:
    bool validated = false;
};

#endif /* GIZMOJNIENV_H */

