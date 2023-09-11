/*
Ну вы же понимаете, что код здесь только мой?
Well, you do understand that the code here is only mine?
 */

/* 
 * File:   GizmoJNIEnv.cpp
 * Author: LWJGL2
 * 
 * Created on 12 сентября 2023 г., 04:08
 */

#include "GizmoJNIEnv.h"

GizmoJNIEnv::GizmoJNIEnv() {
}

GizmoJNIEnv::GizmoJNIEnv(const GizmoJNIEnv& orig) {
}

GizmoJNIEnv::~GizmoJNIEnv() {
}


// final tvector3 orig, float r, float g, float b, final tvector3 vtx, final tvector3 vty

void GizmoJNIEnv::call(JNIEnv *env) {
    if (!validated) {
        std::cout << "GizmoJNIEnv call error -> not validated\n";
        return;
    }

    jclass clazz = env->FindClass("net/steelswing/libgizmo/LibGizmoRenderer");
    jmethodID method = (env)->GetMethodID(clazz, "DrawCircle", "(Lnet/steelswing/libgizmo/tvector3;FFFLnet/steelswing/libgizmo/tvector3;Lnet/steelswing/libgizmo/tvector3;)V");
    if (method != nullptr) {
        env->CallStaticVoidMethod(clazz, method, newVector3(env, 0, 0, 0), 1, 0, 0, newVector3(env, 1, 1, 1), newVector3(env, 0, 2, 0));
    }
}

jobject GizmoJNIEnv::newVector3(JNIEnv *env, float x, float y, float z) {
    jclass javaGlobalClass = reinterpret_cast<jclass> (env->FindClass("net/steelswing/libgizmo/tvector3"));
    jmethodID javaConstructor = env->GetMethodID(javaGlobalClass, "<init>", "(FFF)V");

    if (javaConstructor == NULL) {
        std::cout << "GizmoJNIEnv newVector3 Find method Failed.\n";
        return nullptr;
    }

    jobject obj = env->NewObject(javaGlobalClass, javaConstructor, x, y, z);
    return obj;
}

jobject GizmoJNIEnv::newVector4(JNIEnv *env, float x, float y, float z, float w) {
    jclass javaGlobalClass = reinterpret_cast<jclass> (env->FindClass("net/steelswing/libgizmo/tvector4"));
    jmethodID javaConstructor = env->GetMethodID(javaGlobalClass, "<init>", "(FFFF)V");

    if (javaConstructor == NULL) {
        std::cout << "GizmoJNIEnv newVector4 Find method Failed.\n";
        return nullptr;
    }

    jobject obj = env->NewObject(javaGlobalClass, javaConstructor, x, y, z, w);
    return obj;
}

jobject GizmoJNIEnv::newVector3(JNIEnv *env, const tvector3 &orig) {
    return newVector3(env, orig.x, orig.y, orig.z);
}

jobject GizmoJNIEnv::newVector4(JNIEnv *env, const tvector4 &orig) {
    return newVector4(env, orig.x, orig.y, orig.z, orig.w);
}