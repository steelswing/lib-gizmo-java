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

#ifdef DEFAULT_RENDERER
#ifdef MAC_OS
#import <OpenGL/OpenGL.h>
#else
#include <GL/gl.h>
#endif
#endif

void CGizmoTransformRender::DrawCircle(JNIEnv *env, const tvector3 &orig, float r, float g, float b, const tvector3 &vtx, const tvector3 &vty) {
    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    jmethodID method = (env)->GetStaticMethodID(clazz, "DrawCircle", "(Lnet/steelswing/libgizmo/tvector3;FFFLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, getGizmoEnv()->newVector3(env, orig), r, g, b, getGizmoEnv()->newVector3(env, vtx), getGizmoEnv()->newVector3(env, vty));
    }

#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glColor4f(r, g, b, 1);

    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 50; i++) {
        tvector3 vt;
        vt = vtx * cos((2 * ZPI / 50) * i);
        vt += vty * sin((2 * ZPI / 50) * i);
        vt += orig;
        glVertex3f(vt.x, vt.y, vt.z);
    }
    glEnd();
#endif

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
#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glColor4f(r, g, b, 1);

    glBegin(GL_LINE_STRIP);
    for (int i = 0; i < 30; i++) {
        tvector3 vt;
        vt = vtx * cos((ZPI / 30) * i);
        vt += vty * sin((ZPI / 30) * i);
        vt += orig;
        if (camPlan.DotNormal(vt))
            glVertex3f(vt.x, vt.y, vt.z);
    }
    glEnd();
#endif
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
#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glColor4fv(&col.x);
    glBegin(GL_LINES);
    glVertex3fv(&orig.x);
    glVertex3f(orig.x + axis.x, orig.y + axis.y, orig.z + axis.z);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 30; i++) {
        tvector3 pt;
        pt = vtx * cos(((2 * ZPI) / 30.0f) * i) * fct;
        pt += vty * sin(((2 * ZPI) / 30.0f) * i) * fct;
        pt += axis*fct2;
        pt += orig;
        glVertex3fv(&pt.x);
        pt = vtx * cos(((2 * ZPI) / 30.0f)*(i + 1)) * fct;
        pt += vty * sin(((2 * ZPI) / 30.0f)*(i + 1)) * fct;
        pt += axis*fct2;
        pt += orig;
        glVertex3fv(&pt.x);
        glVertex3f(orig.x + axis.x, orig.y + axis.y, orig.z + axis.z);

    }
    glEnd();
#endif
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
#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    int i = 0;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_CULL_FACE);


    glColor4f(1, 1, 0, 0.5f);
    glBegin(GL_TRIANGLE_FAN);
    glVertex3fv(&orig.x);
    for (i = 0; i <= 50; i++) {
        tvector3 vt;
        vt = vtx * cos(((ng) / 50) * i);
        vt += vty * sin(((ng) / 50) * i);
        vt += orig;
        glVertex3f(vt.x, vt.y, vt.z);
    }
    glEnd();

    glDisable(GL_BLEND);


    glColor4f(1, 1, 0.2f, 1);
    tvector3 vt;
    glBegin(GL_LINE_LOOP);

    glVertex3fv(&orig.x);
    for (i = 0; i <= 50; i++) {
        tvector3 vt;
        vt = vtx * cos(((ng) / 50) * i);
        vt += vty * sin(((ng) / 50) * i);
        vt += orig;
        glVertex3f(vt.x, vt.y, vt.z);
    }

    glEnd();
#endif
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

#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_CULL_FACE);

    tvector3 pts[4];
    pts[0] = orig;
    pts[1] = orig + (axisU * size);
    pts[2] = orig + (axisU + axisV) * size;
    pts[3] = orig + (axisV * size);

    if (!bSelected)
        glColor4f(1, 1, 0, 0.5f);
    else
        glColor4f(1, 1, 1, 0.6f);

    glBegin(GL_QUADS);
    glVertex3fv(&pts[0].x);
    glVertex3fv(&pts[1].x);
    glVertex3fv(&pts[2].x);
    glVertex3fv(&pts[3].x);
    glEnd();

    if (!bSelected)
        glColor4f(1, 1, 0.2f, 1);
    else
        glColor4f(1, 1, 1, 0.6f);

    glBegin(GL_LINE_STRIP);
    glVertex3fv(&pts[0].x);
    glVertex3fv(&pts[1].x);
    glVertex3fv(&pts[2].x);
    glVertex3fv(&pts[3].x);
    glEnd();

    glDisable(GL_BLEND);
#endif
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
#ifdef DEFAULT_RENDERER
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glDisable(GL_CULL_FACE);

    tvector3 pts[3];
    pts[0] = orig;

    pts[1] = (axisU);
    pts[2] = (axisV);

    pts[1] *= size;
    pts[2] *= size;
    pts[1] += orig;
    pts[2] += orig;

    if (!bSelected)
        glColor4f(1, 1, 0, 0.5f);
    else
        glColor4f(1, 1, 1, 0.6f);

    glBegin(GL_TRIANGLES);
    glVertex3fv(&pts[0].x);
    glVertex3fv(&pts[1].x);
    glVertex3fv(&pts[2].x);
    glVertex3fv(&pts[3].x);
    glEnd();

    if (!bSelected)
        glColor4f(1, 1, 0.2f, 1);
    else
        glColor4f(1, 1, 1, 0.6f);

    glBegin(GL_LINE_STRIP);
    glVertex3fv(&pts[0].x);
    glVertex3fv(&pts[1].x);
    glVertex3fv(&pts[2].x);
    glEnd();

    glDisable(GL_BLEND);
#endif
}
