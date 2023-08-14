/*
Ну вы же понимаете, что код здесь только мой?
Well, you do understand that the code here is only mine?
 */



#include <windows.h>  // Header File For Windows
#include <stdio.h>   // Header File For Standard Input/Output
#include <gl\gl.h>   // Header File For The OpenGL32 Library
#include <gl\glu.h>   // Header File For The GLu32 Library
#include <math.h>
#include <iostream>
#include "libgizmo/IGizmo.h"

#include "net_steelswing_libgizmo_LibGizmo.h"

int WINAPI start_debug_window();

//
//public static enum Type {
//   GIZMO_MOVE,
//   GIZMO_SCALE,
//   GIZMO_ROTATE
//}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    create_test_window
 * Signature: (Ljava/lang/Runnable;)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_create_1test_1window(JNIEnv *env, jclass cls, jobject runnable) {
#ifdef TEST_MAIN_CPP
    start_debug_window();
#endif
}

JNIEXPORT jobject JNICALL Java_net_steelswing_libgizmo_LibGizmo_nCreate(JNIEnv *env, jclass clazz, jint type) {
    jclass javaGlobalClass = reinterpret_cast<jclass> (env->NewGlobalRef(clazz));
    jmethodID javaConstructor = env->GetMethodID(javaGlobalClass, "<init>", "(J)V");

    if (javaConstructor == NULL) {
        std::cout << "Java_net_steelswing_libgizmo_LibGizmo_create Find method Failed.\n";
        return nullptr;
    }

    IGizmo* gizmo = nullptr;

    if (type == 1) {
        gizmo = CreateScaleGizmo();
    }
    if (type == 2) {
        gizmo = CreateRotateGizmo();
    }
    if (gizmo == nullptr || type == 0) {
        gizmo = CreateMoveGizmo();
    }

    jobject obj = env->NewObject(javaGlobalClass, javaConstructor, gizmo);
    return obj;
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetEditMatrix
 * Signature: (Ljava/nio/FloatBuffer;)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetEditMatrix(JNIEnv * env, jclass cls, jlong pointer, jobject pMatrix) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetEditMatrix\n";
        return;
    }
    float *pMatrixBuf = (float *) env->GetDirectBufferAddress(pMatrix);
    gizmo->SetEditMatrix(pMatrixBuf);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetCameraMatrix
 * Signature: (Ljava/nio/FloatBuffer;Ljava/nio/FloatBuffer;)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetCameraMatrix(JNIEnv * env, jclass cls, jlong pointer, jobject model, jobject proj) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetCameraMatrix\n";
        return;
    }
    float *modelBuf = (float *) env->GetDirectBufferAddress(model);
    float *projBuf = (float *) env->GetDirectBufferAddress(proj);
    gizmo->SetCameraMatrix(modelBuf, projBuf);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetScreenDimension
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetScreenDimension(JNIEnv * env, jclass cls, jlong pointer, jint screenWidth, jint screenHeight) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetScreenDimension\n";
        return;
    }
    gizmo->SetScreenDimension(screenWidth, screenHeight);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetDisplayScale
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetDisplayScale(JNIEnv * env, jclass cls, jlong pointer, jfloat aScale) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetDisplayScale\n";
        return;
    }
    gizmo->SetDisplayScale(aScale);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nOnMouseDown
 * Signature: (II)Z
 */
JNIEXPORT jboolean JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseDown(JNIEnv * env, jclass cls, jlong pointer, jint x, jint y) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nOnMouseDown\n";
        return;
    }
    return gizmo->OnMouseDown(x, y);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nOnMouseMove
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseMove(JNIEnv * env, jclass cls, jlong pointer, jint x, jint y) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nOnMouseMove\n";
        return;
    }
    gizmo->OnMouseMove(x, y);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nOnMouseUp
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseUp(JNIEnv * env, jclass cls, jlong pointer, jint x, jint y) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nOnMouseUp\n";
        return;
    }
    gizmo->OnMouseUp(x, y);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nUseSnap
 * Signature: (Z)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nUseSnap(JNIEnv *env, jclass cls, jlong pointer, jboolean useSnap) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nUseSnap\n";
        return;
    }
    gizmo->UseSnap(useSnap);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nIsUsingSnap
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_net_steelswing_libgizmo_LibGizmo_nIsUsingSnap(JNIEnv *env, jclass cls, jlong pointer) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nIsUsingSnap\n";
        return;
    }
    return gizmo->IsUsingSnap();
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetSnap
 * Signature: (FFF)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__FFF(JNIEnv *env, jclass cls, jlong pointer, jfloat snapx, jfloat snapy, jfloat snapz) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__FFF\n";
        return;
    }
    gizmo->SetSnap(snapx, snapy, snapz);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetSnap
 * Signature: (F)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__F(JNIEnv *env, jclass cls, jlong pointer, jfloat snap) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__F\n";
        return;
    }
    gizmo->SetSnap(snap);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetLocation
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetLocation(JNIEnv *env, jclass cls, jlong pointer, jint newLocation) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetLocation\n";
        return;
    }

    gizmo->SetLocation(newLocation);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nGetLocation
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_net_steelswing_libgizmo_LibGizmo_nGetLocation(JNIEnv *env, jclass cls, jlong pointer) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nGetLocation\n";
        return;
    }

    return gizmo->GetLocation();
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nSetAxisMask
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetAxisMask(JNIEnv *env, jclass cls, jlong pointer, jint mask) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nSetAxisMask\n";
        return;
    }
    gizmo->SetAxisMask(mask);
}

/*
 * Class:     net_steelswing_libgizmo_LibGizmo
 * Method:    nDraw
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nDraw(JNIEnv *env, jclass cls, jlong pointer) {
    IGizmo* gizmo = reinterpret_cast<IGizmo*> (pointer);
    if (gizmo == nullptr) {
        std::cout << "Nullptr Java_net_steelswing_libgizmo_LibGizmo_nDraw\n";
        return;
    }
    gizmo->Draw();
}