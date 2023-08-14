/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

/**
 * File: RotateAxis.java
 * Created on 15 авг. 2023 г., 06:56:22
 *
 * @author LWJGL2
 */
public enum RotateAxis {
    AXIS_X(1), AXIS_Y(2), AXIS_Z(4), AXIS_TRACKBALL(8), AXIS_SCREEN(16), AXIS_ALL(31);
    protected final int nativeIndex;

    private RotateAxis(int nativeIndex) {
        this.nativeIndex = nativeIndex;
    }

    public static RotateAxis get(int nativeIndex) {
        for (RotateAxis value : RotateAxis.values()) {
            if (value.nativeIndex == nativeIndex) {
                return value;
            }
        }
        return null;
    }
    
}
