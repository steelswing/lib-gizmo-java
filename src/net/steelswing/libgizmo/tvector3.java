/*
 * Ну вы же понимаете, что код здесь только мой?
 * Well, you do understand that the code here is only mine?
 */

package net.steelswing.libgizmo;

/**
 * File: tvector3.java
 * Created on 12 сент. 2023 г., 01:48:34
 *
 * @author LWJGL2
 */
public class tvector3 {

    public float x, y, z;

    public tvector3(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public tvector3(float xyz) {
        this(xyz, xyz, xyz);
    }

    public tvector3() {
        this(0);
    }

    public tvector3 add(tvector3 other) {
        return tvector3(x + other.x, y + other.y, z + other.z);
    }

    public tvector3 sub(tvector3 other) {
        return tvector3(x - other.x, y - other.y, z - other.z);
    }

    public tvector3 mul(tvector3 other) {
        return tvector3(x * other.x, y * other.y, z * other.z);
    }

    public tvector3 div(tvector3 other) {
        return tvector3(x / other.x, y / other.y, z / other.z);
    }

    public tvector3 add(float otherx, float othery, float otherz) {
        return tvector3(x + otherx, y + othery, z + otherz);
    }

    public tvector3 sub(float otherx, float othery, float otherz) {
        return tvector3(x - otherx, y - othery, z - otherz);
    }

    public tvector3 mul(float otherx, float othery, float otherz) {
        return tvector3(x * otherx, y * othery, z * otherz);
    }

    public tvector3 div(float otherx, float othery, float otherz) {
        return tvector3(x / otherx, y / othery, z / otherz);
    }

    public tvector3 add(float otherxyz) {
        return tvector3(x + otherxyz, y + otherxyz, z + otherxyz);
    }

    public tvector3 sub(float otherxyz) {
        return tvector3(x - otherxyz, y - otherxyz, z - otherxyz);
    }

    public tvector3 mul(float otherxyz) {
        return tvector3(x * otherxyz, y * otherxyz, z * otherxyz);
    }

    public tvector3 div(float otherxyz) {
        return tvector3(x / otherxyz, y / otherxyz, z / otherxyz);
    }

    public tvector3 tvector3(float x, float y, float z) {
        this.x = x;
        this.y = y;
        this.z = z;
        return this;
    }


//    public   tvector3 tvector3(float x, float y, float z) {
//        return new tvector3(x, y, z);
//    }


    public static tvector3 add(tvector3 a, tvector3 b) {
        return new tvector3(a.x + b.x, a.y + b.y, a.z + b.z);
    }

    public static tvector3 add(float a, tvector3 b) {
        return new tvector3(a + b.x, a + b.y, a + b.z);
    }

    public static tvector3 add(tvector3 a, float b) {
        return new tvector3(a.x + b, a.y + b, a.z + b);
    }

    public static tvector3 sub(tvector3 a, tvector3 b) {
        return new tvector3(a.x - b.x, a.y - b.y, a.z - b.z);
    }

    public static tvector3 sub(float a, tvector3 b) {
        return new tvector3(a - b.x, a - b.y, a - b.z);
    }

    public static tvector3 sub(tvector3 a, float b) {
        return new tvector3(a.x - b, a.y - b, a.z - b);
    }

    public static tvector3 mul(tvector3 a, tvector3 b) {
        return new tvector3(a.x * b.x, a.y * b.y, a.z * b.z);
    }

    public static tvector3 mul(float a, tvector3 b) {
        return new tvector3(a * b.x, a * b.y, a * b.z);
    }

    public static tvector3 mul(tvector3 a, float b) {
        return new tvector3(a.x * b, a.y * b, a.z * b);
    }

    public static tvector3 div(tvector3 a, tvector3 b) {
        return new tvector3(a.x / b.x, a.y / b.y, a.z / b.z);
    }

    public static tvector3 div(float a, tvector3 b) {
        return new tvector3(a / b.x, a / b.y, a / b.z);
    }

    public static tvector3 div(tvector3 a, float b) {
        return new tvector3(a.x / b, a.y / b, a.z / b);
    }

    public float Dot(tvector3 v) {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }

    @Override
    public String toString() {
        return "tvector3{" + "x=" + x + ", y=" + y + ", z=" + z + '}';
    }
}
