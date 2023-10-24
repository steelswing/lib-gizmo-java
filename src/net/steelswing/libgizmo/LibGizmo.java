/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

import java.nio.FloatBuffer;

/**
 * File: LibGizmo.java
 * Created on 15 авг. 2023 г., 06:49:48
 *
 * @author LWJGL2
 */
public class LibGizmo {

    static {
        NativeLoader.init();
    }

    private long pointer;

    public LibGizmo(long pointer) {
        this.pointer = pointer;
    }

    public static LibGizmo create(GizmoType type) {
        return nCreate(type.ordinal());
    }

    public static native LibGizmo nCreate(int type);

    public static native void nSetEditMatrix(long gizmo, FloatBuffer pMatrix);

    public static native void nSetOffsetEditMatrix(long gizmo, FloatBuffer pMatrix);

    public static native void nSetCameraMatrix(long gizmo, FloatBuffer Model, FloatBuffer Proj);

    public static native void nSetScreenDimension(long gizmo, int screenWidth, int screenHeight);

    public static native void nSetDisplayScale(long gizmo, float aScale);

    // return true if gizmo transform capture mouse
    public static native boolean nOnMouseDown(long gizmo, int x, int y);

    public static native void nOnMouseMove(long gizmo, int x, int y);

    public static native void nOnMouseUp(long gizmo, int x, int y);

    // snaping
    public static native void nUseSnap(long gizmo, boolean bUseSnap);

    public static native boolean nIsUsingSnap(long gizmo);

    public static native void nSetSnap(long gizmo, float snapx, float snapy, float snapz);

    public static native void nSetSnap(long gizmo, float snap);


    public static native void nSetLocation(long gizmo, int aLocation);

    public static native int nGetLocation(long gizmo);

    public static native void nSetAxisMask(long gizmo, int mask);

    // rendering
    public static native void nDraw(long gizmo);

    public void setLocation(Location aLocation) {
        nSetLocation(pointer, aLocation.ordinal());
    }

    public Location getLocation() {
        return Location.values()[nGetLocation(pointer)];
    }

    public void setEditMatrix(FloatBuffer pMatrix) {
        nSetEditMatrix(pointer, pMatrix);
    }

    public void setOffsetEditMatrix(FloatBuffer pMatrix) {
        nSetOffsetEditMatrix(pointer, pMatrix);
    }

    public void setCameraMatrix(FloatBuffer Model, FloatBuffer Proj) {
        nSetCameraMatrix(pointer, Model, Proj);
    }

    public void setScreenDimension(int screenWidth, int screenHeight) {
        nSetScreenDimension(pointer, screenWidth, screenHeight);
    }

    public void setDisplayScale(float aScale) {
        nSetDisplayScale(pointer, aScale);
    }

    // return true if gizmo transform capture mouse
    public boolean onMouseDown(int x, int y) {
        return nOnMouseDown(pointer, x, y);
    }

    public void onMouseMove(int x, int y) {
        nOnMouseMove(pointer, x, y);
    }

    public void onMouseUp(int x, int y) {
        nOnMouseUp(pointer, x, y);
    }

    // snaping
    public void useSnap(boolean bUseSnap) {
        nUseSnap(pointer, bUseSnap);
    }

    public boolean isUsingSnap() {
        return nIsUsingSnap(pointer);
    }

    public void setSnap(float snapx, float snapy, float snapz) {
        nSetSnap(pointer, snapx, snapy, snapz);
    }

    public void setSnap(float snap) {
        nSetSnap(pointer, snap);
    }

    public void setAxisMask(int mask) {
        nSetAxisMask(pointer, mask);
    }

    // rendering
    public void draw() {
        nDraw(pointer);
    }

    public long getPointer() {
        return pointer;
    }



    public static native void create_test_window(Runnable runnable);
}
