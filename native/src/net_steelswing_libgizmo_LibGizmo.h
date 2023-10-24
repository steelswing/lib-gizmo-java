/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class net_steelswing_libgizmo_LibGizmo */

#ifndef _Included_net_steelswing_libgizmo_LibGizmo
#define _Included_net_steelswing_libgizmo_LibGizmo

#ifdef __cplusplus
extern "C" {
#endif

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nCreate
     * Signature: (I)Lnet/steelswing/libgizmo/LibGizmo;
     */
    JNIEXPORT jobject JNICALL Java_net_steelswing_libgizmo_LibGizmo_nCreate
    (JNIEnv *, jclass, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetEditMatrix
     * Signature: (JLjava/nio/FloatBuffer;)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetEditMatrix
    (JNIEnv *, jclass, jlong, jobject);

    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetOffsetEditMatrix
    (JNIEnv *, jclass, jlong, jobject);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetCameraMatrix
     * Signature: (JLjava/nio/FloatBuffer;Ljava/nio/FloatBuffer;)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetCameraMatrix
    (JNIEnv *, jclass, jlong, jobject, jobject);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetScreenDimension
     * Signature: (JII)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetScreenDimension
    (JNIEnv *, jclass, jlong, jint, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetDisplayScale
     * Signature: (JF)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetDisplayScale
    (JNIEnv *, jclass, jlong, jfloat);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nOnMouseDown
     * Signature: (JII)Z
     */
    JNIEXPORT jboolean JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseDown
    (JNIEnv *, jclass, jlong, jint, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nOnMouseMove
     * Signature: (JII)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseMove
    (JNIEnv *, jclass, jlong, jint, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nOnMouseUp
     * Signature: (JII)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nOnMouseUp
    (JNIEnv *, jclass, jlong, jint, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nUseSnap
     * Signature: (JZ)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nUseSnap
    (JNIEnv *, jclass, jlong, jboolean);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nIsUsingSnap
     * Signature: (J)Z
     */
    JNIEXPORT jboolean JNICALL Java_net_steelswing_libgizmo_LibGizmo_nIsUsingSnap
    (JNIEnv *, jclass, jlong);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetSnap
     * Signature: (JFFF)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__JFFF
    (JNIEnv *, jclass, jlong, jfloat, jfloat, jfloat);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetSnap
     * Signature: (JF)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetSnap__JF
    (JNIEnv *, jclass, jlong, jfloat);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetLocation
     * Signature: (JI)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetLocation
    (JNIEnv *, jclass, jlong, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nGetLocation
     * Signature: (J)I
     */
    JNIEXPORT jint JNICALL Java_net_steelswing_libgizmo_LibGizmo_nGetLocation
    (JNIEnv *, jclass, jlong);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetAxisMask
     * Signature: (JI)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetAxisMask
    (JNIEnv *, jclass, jlong, jint);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nDraw
     * Signature: (J)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nDraw
    (JNIEnv *, jclass, jlong);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    create_test_window
     * Signature: (Ljava/lang/Runnable;)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_create_1test_1window
    (JNIEnv *, jclass, jobject);

    /*
     * Class:     net_steelswing_libgizmo_LibGizmo
     * Method:    nSetRenderer
     * Signature: (JLjava/lang/Object;)V
     */
    JNIEXPORT void JNICALL Java_net_steelswing_libgizmo_LibGizmo_nSetRenderer
    (JNIEnv *, jclass, jlong, jobject);


#ifdef __cplusplus
}
#endif
#endif
