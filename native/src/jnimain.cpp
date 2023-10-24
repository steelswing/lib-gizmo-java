/*
Ну вы же понимаете, что код здесь только мой?
Well, you do understand that the code here is only mine?
 */

#include "jnimain.h"

GizmoJNIEnv* gizmoEnv;

jmethodID setupENV(GizmoJNIEnv* gizmoEnvIn) {
    gizmoEnv = gizmoEnvIn;
}
GizmoJNIEnv* getGizmoEnv() {
    return gizmoEnv;
}