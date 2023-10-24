///////////////////////////////////////////////////////////////////////////////////////////////////
// LibGizmo
// File Name : 
// Creation : 10/01/2012
// Author : Cedric Guillemet
// Description : LibGizmo
//
///Copyright (C) 2012 Cedric Guillemet
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
//of the Software, and to permit persons to whom the Software is furnished to do
///so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
///FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 


#include "stdafx.h"
#include "GizmoTransformRender.h"
#include "../jnimain.h"

void CGizmoTransformRender::DrawCircle(JNIEnv *env, const tvector3 &orig, float r, float g, float b, const tvector3 &vtx, const tvector3 &vty) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawCircle", "(Lnet/steelswing/libgizmo/tvector3;FFFLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), r, g, b, getGizmoEnv()->newVector3(env, vtx), getGizmoEnv()->newVector3(env, vty));
    }
}

void CGizmoTransformRender::DrawCircleHalf(JNIEnv *env, const tvector3 &orig, float r, float g, float b, const tvector3 &vtx, const tvector3 &vty, tplane &camPlan) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    if (clazz == nullptr) {
        std::cout << "Class not found!" << std::endl;
        return;
    }
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawCircleHalf", "(Lnet/steelswing/libgizmo/tvector3;FFFLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tplane;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), r, g, b, getGizmoEnv()->newVector3(env, vtx), getGizmoEnv()->newVector3(env, vty), getGizmoEnv()->newVector4(env, camPlan));
    }
}

void CGizmoTransformRender::DrawAxis(JNIEnv *env, const tvector3 &orig, const tvector3 &axis, const tvector3 &vtx, const tvector3 &vty, float fct, float fct2, const tvector4 &col) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    if (clazz == nullptr) {
        std::cout << "Class not found!" << std::endl;
        return;
    }
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawAxis", "(Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;FFLnet/steelswing/libgizmo/tvector4;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), getGizmoEnv()->newVector3(env, axis), getGizmoEnv()->newVector3(env, vtx), getGizmoEnv()->newVector3(env, vty), fct, fct2, getGizmoEnv()->newVector4(env, col));
    }
}

void CGizmoTransformRender::DrawCamem(JNIEnv *env, const tvector3& orig, const tvector3& vtx, const tvector3& vty, float ng) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    if (clazz == nullptr) {
        std::cout << "Class not found!" << std::endl;
        return;
    }
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawCamem", "(Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;F)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), getGizmoEnv()->newVector3(env, vtx), getGizmoEnv()->newVector3(env, vty), ng);
    }
}

void CGizmoTransformRender::DrawQuad(JNIEnv *env, const tvector3& orig, float size, bool bSelected, const tvector3& axisU, const tvector3 &axisV) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    if (clazz == nullptr) {
        std::cout << "Class not found!" << std::endl;
        return;
    }
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawQuad", "(Lnet/steelswing/libgizmo/tvector3;FZLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), size, bSelected, getGizmoEnv()->newVector3(env, axisU), getGizmoEnv()->newVector3(env, axisV));
    }

}

void CGizmoTransformRender::DrawTri(JNIEnv *env, const tvector3& orig, float size, bool bSelected, const tvector3& axisU, const tvector3& axisV) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    if (clazz == nullptr) {
        std::cout << "Class not found!" << std::endl;
        return;
    }
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawTri", "(Lnet/steelswing/libgizmo/tvector3;FZLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), size, bSelected, getGizmoEnv()->newVector3(env, axisU), getGizmoEnv()->newVector3(env, axisV));
    }
}
